#ifndef PLOTHELPER_H
#define PLOTHELPER_H

#include "ConfigureSamples.h"
#include "ConfigureVars.h"
#include "Gadgets.h"

//Template for drawing different hists
//template <typename T>
void DrawRatioPlot( TH1D* data, TH1D* MC, TString Xaxis, TString Yaxis="Data/Prediction"){
	TH1D* ratioP = (TH1D*) data->Clone("DataVsErrorHist");
	ratioP->Divide(MC);

	//ratioP carrys ratio point & %error of the data
	for(int index=1; index<ratioP->GetNbinsX()+1;index++){
		ratioP->SetBinError(index, data->GetBinError(index)/data->GetBinContent(index));
	}
	
	
	ratioP->Draw("E1");
	ratioP->GetXaxis()->SetTitle(Xaxis);
	ratioP->GetYaxis()->SetTitle(Yaxis);

	//PerErr carrys the percent errors of MC;
	TH1D* PerErr = (TH1D*) MC->Clone("MCPercentError");

	for(int index=1; index<PerErr->GetNbinsX()+1;index++){
		PerErr->SetBinError(index, PerErr->GetBinError(index)/PerErr->GetBinContent(index));
		PerErr->SetBinContent(index, 1);
	}

	SetRatioStyle(ratioP);//defined in Gadgets.h

	SetHashStyle(PerErr);//defined in Gadgets.h
	PerErr->Draw("E2 same");

}

	//Draw a TH1D
TH1D* drawTH1D(Samples &sample, Vars &var)
{
	//spell out contents that we need from two classes
	TString variable = var.GetVarName();
	std::vector<double> binnings = var.GetBinning();

	TTree* ttree = sample.GetSampleTree();
	TString cuts = "("+sample.GetDefinition()+")*("+sample.GetWeight()+")";

	int linecolor = sample.GetCol();
	int fillstyle = sample.GetFillStyle();
	//default is (nbins, bmin, bmax);
	TH1D* h = new TH1D(RandomName(), "", binnings[0], binnings[1], binnings[2]);
	ttree->Draw(variable+">>"+h->GetName(), cuts);
	//std::cout<<"Drawing :"<<variable<<" cuts:"<<cuts<<std::endl;
	//std::cout<<"TH1 has events: "<<h->Integral()<<std::endl;

//	if(linecolor == 0 || fillstyle == 0) std::cout<<"Warning: "<<sample.GetSampleName()<<" histogram color/style is not set."<<std::endl;
	h->SetLineColor(kBlack);
	h->SetFillColor(linecolor);
	h->SetFillStyle(fillstyle);
	h->Scale(sample.GetScale());
	return h;
}

//Draw covariance matrix
//Each block has nbins x nbins grids
//Each grid is (cv_i-var_i)*(cv_j - var_j)

TH2D* BuildCovarianceMatrix(const TH1D* hCV, const std::vector<TH1D*>& variations){
    int nvars = variations.size();
    int nbins = hCV->GetNbinsX();
	int totalbins = nbins*nvars;

    TH2D* hCov = new TH2D("hCov", "Matrix", totalbins, 0.5, totalbins+0.5, totalbins, 0.5, totalbins+0.5);
	TH1D* h_concat = new TH1D("h_concat", "Concatenated Histogram", totalbins, 0.5, totalbins + 0.5);


	for (int index = 0; index < nvars; ++ index){
		for (int jndex= 1; jndex< nbins + 1; ++jndex) {//Get the CV

			h_concat->SetBinContent(index*nbins + jndex, variations[index]->GetBinContent(jndex));

		}
	}

    // Calculate covariance

	for (int tndex= 1; tndex < totalbins + 1; ++tndex) {//Get the CV
		double cv_i = hCV->GetBinContent( (tndex-1)%nbins + 1); //want 1,2,3; 1,2,3; 
		double var_i = h_concat->GetBinContent( tndex);

		for (int undex= 1; undex < totalbins + 1; ++undex) {//Get the 2nd CV
			double cv_j = hCV->GetBinContent( (undex - 1)%nbins + 1);
			double var_j = h_concat->GetBinContent( undex);

			double diff_i = var_i - cv_i;
			double diff_j = var_j - cv_j;

			double cov = diff_i * diff_j;

			hCov->SetBinContent(tndex, undex, cov);
			std::cout<<"("<<tndex<<","<<undex<<")="<<cov<<std::endl;
			std::cout<<"       "<<"cv_i:"<<cv_i<<" cv_j:"<<cv_j<<" var_i:"<<var_i<<" var_j:"<<var_j<<std::endl;
		}
	}

    return hCov;
}

void ExportPNG_StackDataTwoSignal_wLabel(
		std::vector< TH1D*> sig_hists,
		THStack* hist, 
		TH1D* hist2, 
		TH1D* errorHist, 
		TLegend *leg, 
		TString name,  
		TString Xaxis, 
		TString Yaxis= "Events", 
		bool logY = false){
	//Add estimator
	gStyle->SetPaintTextFormat("4.1f%%");//draw numbers with percentage


	TCanvas* c = new TCanvas("c","c",800,600);
	TPad *padT = new TPad("padT","padT",0 , 0.8		,1 ,   1); //Pad for legend, invaid margin 0.05 below
	TPad *padH = new TPad("padH","padH",0 , 0.3		,1 ,   0.8);//Pad for Histograms, 
	TPad *padR = new TPad("padR","padH",0 , 0.05	,1 ,   0.3);//Pad for Ratio, 
	TPad *padB = new TPad("padB","padB",0 , 0		,1 ,   0.05);//Pad for text, xlow, ylow,xup,yup

// ---- Pad for Legends
	padT->SetMargin(0,0,0,0);//Setmargins for left,right,bottom,top

	padT->Draw();
	padT->cd();
	leg->Draw();


// ---- Pad for Histograms
	c->cd();
	padH->SetTopMargin(0.02);//leave some space for the yaxis label
	padH->SetBottomMargin(0);
//	padH->SetFillColor(kBlue-4); //this labels the area
	padH->Draw();
	padH->cd();
	if(logY) padH->SetLogy();


	//Adjust maximum based on two histograms
	double max = hist->GetMaximum();
	hist->Draw("hist");//MC
	for( auto hi : sig_hists){
		hi->Draw("hist same");
		if(hi->GetMaximum() > max) max = hi->GetMaximum();
	}
	hist2->Draw("E1P same");//Data
	errorHist->Draw("same E2");//MCError

	if(hist2->GetMaximum() > max) max = hist2->GetMaximum();
	hist->SetMinimum(0.9);
	hist->SetMaximum(max*1.2);
	hist->GetYaxis()->SetTitle(Yaxis);
	hist->GetYaxis()->SetLabelSize(0.04);//% of the TPad height
	hist->GetYaxis()->SetTitleSize(0.06);//% of the TPad height
	hist->GetYaxis()->SetTitleOffset(0.6);//Sets the bottom of the text distance to the axis, when the value is between 0-1

// ---- Pad for ratios
	c->cd();
	padR->SetTopMargin(0);
	padR->SetBottomMargin(0.25);//distance from the bottom of the plot to pad edges
	padR->Draw();
	padR->cd();
	//Data has point, error bar
	//MC has shaded errors
	DrawRatioPlot( hist2, errorHist, Xaxis, "Data/Backgrounds");


//Draw the rest of the pads, on top of others;

// ---- Pad for text
	c->cd();
//	padB->SetFillColor(kCyan-4); //this is useful
	padB->Draw();
	padB->cd();
	TLatex* estimators = GetEstimators( hist2, errorHist);
	estimators->Draw();

	c->SaveAs("./output/"+name+".pdf");
	c->SaveAs("./output/"+name+".png");
	delete c;
}



void draw_variations(TH1D* CV, const std::vector<TH1D*>& variations,
		TLegend *leg, 
		TString SafeName,  
		TString XaxisTitle, 
		TString YaxisTitle= "Events", 
		bool logY = false)
{
    if (!CV) {
        std::cerr << "Error: CV histogram is null.\n";
        return;
    }

    //--- Canvas setup (2 pads side by side)
    TCanvas* c = new TCanvas("c", "Variations", 1000, 600);
    c->Divide(2,1,0,0);  // no gaps between pads

    TPad* pad1 = (TPad*)c->cd(1);
	pad1->SetPad(0.0, 0.0, 0.75, 1.0);
    pad1->SetMargin(0.12, 0.02, 0.12, 0.08);
    if (logY) pad1->SetLogy();

	TPad *pad2 = (TPad*)c->cd(2);
    pad2->SetPad(0.75, 0.0, 1.0, 1.0);
    pad2->SetMargin(0.05, 0.05, 0.1, 0.1);

    //--- Draw histograms on left pad
    pad1->cd();
    gStyle->SetOptStat(0);

    CV->SetLineColor(kBlack);
    CV->SetLineWidth(2);
    CV->SetTitle("");
    CV->GetXaxis()->SetTitle(XaxisTitle);
    CV->GetYaxis()->SetTitle(YaxisTitle);
    CV->Draw("HIST");

	double max = CV->GetMaximum();

    //--- Draw variations with different colors
    int colorIndex = 2; // start from red
    for (size_t i = 0; i < variations.size(); ++i) {
        if (!variations[i]) continue;
        variations[i]->SetLineColor(colorIndex);
        variations[i]->SetLineWidth(2);
        variations[i]->SetLineStyle(1);
        variations[i]->Draw("HISTSAME");

		colorIndex++;
        if (colorIndex == 5) colorIndex = 6; // skip yellow for clarity

		if(variations[i]->GetMaximum() > max) max = variations[i]->GetMaximum();
    }

	CV->SetMaximum(max*1.2);

    //--- Draw legend on right pad
    pad2->cd();
    leg->Draw();

    //--- Save output
    c->cd();
//    c->SaveAs("output/"+SafeName + ".pdf");
    c->SaveAs("output/"+SafeName + ".png");

    delete c;
}


void draw_FractionalDifference(TH1D* CV, const std::vector<TH1D*>& variations,
		TLegend *leg, 
		TString SafeName,  
		TString XaxisTitle, 
		TString YaxisTitle= "Events")
{
    if (!CV) {
        std::cerr << "Error: CV histogram is null.\n";
        return;
    }

    //--- Canvas setup (2 pads side by side)
    TCanvas* c = new TCanvas("c", "Fracitonal Uncertainty", 1000, 600);
    c->Divide(2,1,0,0);  // no gaps between pads

    TPad* pad1 = (TPad*)c->cd(1);
	pad1->SetPad(0.0, 0.0, 0.75, 1.0);
    pad1->SetMargin(0.12, 0.02, 0.12, 0.08);

	TPad *pad2 = (TPad*)c->cd(2);
    pad2->SetPad(0.75, 0.0, 1.0, 1.0);
    pad2->SetMargin(0.05, 0.05, 0.1, 0.1);

    //--- Draw histograms on left pad
    pad1->cd();
    gStyle->SetOptStat(0);

    //--- Draw variations with different colors
    int colorIndex = 2; // start from red
	int markerIndexOffset = 22;
	TH1D* hfirst = nullptr;
	double max = 0;
	double factor = 1.5;

	for (size_t i = 0; i < variations.size(); ++i) {
		if (!variations[i]) continue;
		TH1D* hdiff = (TH1D*)variations[i]->Clone();
		hdiff->Add(CV, -1.0);
		hdiff->Divide(CV);

		if (!hfirst) hfirst = hdiff; // store the first one drawn

		// compute max
		if (hdiff->GetMaximum() > max) max = hdiff->GetMaximum();
		if (hdiff->GetMinimum() < -max) max = -hdiff->GetMinimum();

		hdiff->SetLineColorAlpha(colorIndex, 0.7);
		hdiff->SetMarkerStyle(colorIndex + markerIndexOffset);
		hdiff->SetMarkerColorAlpha( colorIndex++, 0.7);
		hdiff->Draw(i == 0 ? "P" : "P SAME");
	}

	std::cout << "Set range: " << -max*factor << " and " << max*factor << std::endl;
	if (hfirst){
		hfirst->GetXaxis()->SetTitle(XaxisTitle);
		hfirst->GetYaxis()->SetTitle(YaxisTitle);
		hfirst->GetYaxis()->SetRangeUser(-max*factor, max*factor);

		// draw reference line
		int LineColor = 17;
		TLine* line;
		line = new TLine(hfirst->GetXaxis()->GetXmin(),0.0,hfirst->GetXaxis()->GetXmax(),0.0 );
		line->SetLineColor(LineColor);
		line->Draw("same");


	}

    pad2->cd();

	leg->GetListOfPrimitives()->RemoveAt(0);//don't need the CV one
    leg->Draw();

    //--- Save output
    c->cd();
//    c->SaveAs("output/"+SafeName + ".pdf");
    c->SaveAs("output/"+SafeName + ".png");

    delete c;
}

void	draw_CovMatrix(const TH1D* CV, 
			const std::vector<TH1D*>& varhists,
			TString SafeName,
			std::vector<TString> axis_texts, 
			TString title){

		TH2D* hCov = BuildCovarianceMatrix( CV, varhists );

		int Nbins = hCov->GetNbinsX();
		int Nvars = varhists.size();
		
		if(axis_texts.size() != varhists.size()){
			std::cout<<"WARNING: Histogram size is different from texts size"<<std::endl;
			std::cout<<axis_texts.size() << " vs. "<<varhists.size()<<std::endl;
		}

		int file_index = 0;
		hCov->GetXaxis()->SetBinLabel(1,"");
		hCov->GetYaxis()->SetBinLabel(1,"");
		hCov->GetYaxis()->LabelsOption("v");
		hCov->SetTitle( title );
		for (int index = 1; index < Nbins+1; ++index) {
			//Print contents
			double var = hCov->GetBinContent(index, index);
			double frac_unc = sqrt(var) / hCov->GetBinContent(index);
			std::cout << "Bin " << index << ": Variance = " << var
				<< ", Fractional = " << frac_unc * 100 << " %" << std::endl;


			//Update labels
			if(( index -1) % CV->GetNbinsX() == 0){
//				hCov->GetXaxis()->SetBinLabel(index, axis_texts[file_index] );
//				hCov->GetYaxis()->SetBinLabel(index, axis_texts[file_index++] );
				hCov->GetXaxis()->ChangeLabel(index, 0, 0.05, -1, -1, -1, axis_texts[file_index] ); //Rotation of 0 degrees
				hCov->GetYaxis()->ChangeLabel(index, 90, 0.05, -1, -1, -1, axis_texts[file_index++] ); //Rotation of 90 degrees NOT WORKING :(
				//void 	ChangeLabel (Int_t labNum=0, Double_t labAngle=-1., Double_t labSize=-1., Int_t labAlign=-1, Int_t labColor=-1, Int_t labFont=-1, const TString &labText="")

			}
		}

		// Hide numeric axis ticks
//		hCov->GetXaxis()->SetLabelSize(0.05);
//		hCov->GetYaxis()->SetLabelSize(0.05);


		TCanvas* c1 = new TCanvas("c1", title, 1400, 900);
		hCov->SetStats(0);
//		hCov->Draw("COLZ TEXT");
		gStyle->SetPaintTextFormat("1.2e");//scientific format 1.23e+03
		hCov->Draw("COLZ TEXT");


		//--- Save output
		c1->cd();
		//    c->SaveAs("output/"+SafeName + ".pdf");
		c1->SaveAs("output/"+SafeName + ".png");

}

//void draw_2DHist(Samples &CV, std::vector<Samples> &SysChanges,  Vars &var, TString tag){
//
//	TString variable = var.GetVarName();
//	std::vector<double> binnings = var.GetBinning();
//
//	TTree* ttree = sample.GetSampleTree();
//	TString cuts = "("+sample.GetDefinition()+")*("+sample.GetWeight()+")";
//
//}

#endif

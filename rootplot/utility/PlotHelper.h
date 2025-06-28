#ifndef PLOTHELPER_H
#define PLOTHELPER_H

#include "ConfigureSamples.h"
#include "ConfigureVars.h"
#include "Gadgets.h"

//Template for drawing different hists
template <typename T>
void ExportPNG(T hist, TString name, TString Xaxis, TString Yaxis= "Events"){
	TCanvas* c = new TCanvas("c","c",800,600);
	hist->Draw("colz text");
	hist->SetTitle(name);
	hist->GetXaxis()->SetTitle(Xaxis);
	hist->GetYaxis()->SetTitle(Yaxis);
	hist->SetStats(false);
	c->SaveAs("./output/"+name+".png");
	delete c;
}

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
	hist->SetMinimum(0.1);
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

void ExportPNG_StackData_wLabel(
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
	hist->Draw("hist");//MC
	hist2->Draw("E1P same");//Data
	errorHist->Draw("same E2");//MCError

	//Adjust maximum based on two histograms
	double max = hist->GetMaximum();
	if(hist2->GetMaximum() > max) max = hist2->GetMaximum();
	hist->SetMinimum(0.001);
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
	DrawRatioPlot( hist2, errorHist, Xaxis, "Data/Prediction");


//Draw the rest of the pads, on top of others;

// ---- Pad for text
	c->cd();
//	padB->SetFillColor(kCyan-4); //this is useful
	padB->Draw();
	padB->cd();
	TLatex* estimators = GetEstimators( hist2, errorHist);
	estimators->Draw();

	c->SaveAs("./output/"+name+".png");
	delete c;
}






//Template for drawing different hists
template <typename T>
void ExportPNGwLegend(T hist, TString name, TLegend *leg, TString Xaxis, TString Yaxis= "Events"){
	TCanvas* c = new TCanvas("c","c",800,600);
	TPad *padH = new TPad("padH","padH",0,   0,  1,   1);
	TPad *padT = new TPad("padT","padT",0, 0.85, 1,   1);

	padH->Draw();
	padH->cd();
	padH->SetTopMargin(0.2);
	hist->Draw("hist");
	hist->GetXaxis()->SetTitle(Xaxis);
	hist->GetYaxis()->SetTitle(Yaxis);

	c->cd();
	padT->Draw();
	padT->cd();
	leg->Draw();
	c->SaveAs("./output/"+name+".png");
	delete c;
}

void SetHist(TH1D* hist, int line, int fill, int style){
	hist->SetLineColor(kBlack);
	if(fill>0) hist->SetFillColor(fill);
	if(style>0) hist->SetFillStyle(style);
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

#endif

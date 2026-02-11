#ifndef PLOTHELPER_H
#define PLOTHELPER_H

#include "ConfigureSamples.h"
#include "ConfigureVars.h"
#include "Gadgets.h"

#include <ROOT/RDataFrame.hxx>

//hist stylist
void SetErrorStyle( TH1D* errorHist){
    errorHist->SetMarkerSize(0);
    errorHist->SetFillStyle(3454);
    errorHist->SetLineWidth(2);
    //        errorHist->SetLineColor(kBlack);
    errorHist->SetFillColor(kBlack);
}

void MakeBeautiHistFilled(Samples& sample, TH1D* hist){
    hist->SetLineColor(kBlack);
    hist->SetFillColor(sample.GetCol());
    hist->SetFillStyle(sample.GetFillStyle());

}

void MakeBeautiHistCV( TH1D* hist ){
    hist->SetLineColor(kBlack);
    hist->SetLineWidth(2);
}

void MakeBeautiHistVariations(TH1D* hist, int col){
    hist->SetLineColor(col);
    //    hist->SetLineColorAlpha(col, 0.3);
    hist->SetLineStyle(1);
    hist->SetLineWidth(1);
}


//legend Stylist
TLegend* LoadLegend(){

    TLegend *leg = new TLegend(0.05,0.01,0.95,0.95);
    leg->SetFillStyle(0);
    leg->SetLineWidth(0);
    leg->SetNColumns(3);

    return leg;
}


TLegend* LoadSideLegend(){

    TLegend *leg = new TLegend(0.05,0.01,0.95,0.95);
    leg->SetTextAlign(12);
    leg->SetFillStyle(0);
    leg->SetLineWidth(0);
    leg->SetNColumns(1);

    return leg;
}



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

    //default is (nbins, bmin, bmax);
    TH1D* h = new TH1D(RandomName(), "", binnings[0], binnings[1], binnings[2]);
    if(!ttree){
        std::cout<<"Did not find TTree "<< sample.GetBranchName()<<" from "<<sample.GetFilePath()<<std::endl;
        return h;
    }
    ttree->Draw(variable+">>"+h->GetName(), cuts);
    //    std::cout<<"Drawing :"<<variable<<" cuts:"<<cuts<<std::endl;
    //    std::cout<<"TH1 has events: "<<h->Integral()<<std::endl;

    //    if(linecolor == 0 || fillstyle == 0) std::cout<<"Warning: "<<sample.GetSampleName()<<" histogram color/style is not set."<<std::endl;
    MakeBeautiHistFilled( sample, h);

    return h;
}

//Draw a TH1D
TH1D* drawTH1D_w_Weight(Samples &sample, Vars &var, TString &wgt, int col )
{
    //spell out contents that we need from two classes
    TString variable = var.GetVarName();
    std::vector<double> binnings = var.GetBinning();

    TTree* ttree = sample.GetSampleTree();
    TString cuts = "("+sample.GetDefinition()+")*("+wgt+")";//We assign the weight;

    //default is (nbins, bmin, bmax);
    TH1D* h = new TH1D(RandomName(), "", binnings[0], binnings[1], binnings[2]);
    ttree->Draw(variable+">>"+h->GetName(), cuts);
    //    std::cout<<"Drawing :"<<variable<<" cuts:"<<cuts<<std::endl;
    //    std::cout<<"TH1 has events: "<<h->Integral()<<std::endl;

    //    if(linecolor == 0 || fillstyle == 0) std::cout<<"Warning: "<<sample.GetSampleName()<<" histogram color/style is not set."<<std::endl;
    MakeBeautiHistFilled( sample, h);
    //    h->SetLineColor(col);
    ////    h->SetFillColor(linecolor);
    //    h->SetFillStyle(0);
    //    h->Scale(sample.GetScale());
    return h;
}



//Draw covariance matrix
//Each block has nbins x nbins grids
//Each grid is (cv_i-var_i)*(cv_j - var_j)

TH2D* BuildCovarianceMatrix(const TH1D* hCV, const std::vector<TH1D*>& variations){
    int nvars = variations.size();
    int nbins = hCV->GetNbinsX();
    int totalbins = nbins*nvars;

	//don't know why, the following line will sometime make the code quiet quietly
    TH2D* hCov = new TH2D("hCov"+RandomName(), "Matrix", totalbins, 0.5, totalbins+0.5, totalbins, 0.5, totalbins+0.5);
//    hCov->SetDirectory(nullptr);
    TH1D* h_concat = new TH1D("h_concat", "Concatenated Histogram", totalbins, 0.5, totalbins + 0.5);
    h_concat->SetDirectory(nullptr);


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
			if(undex % 1000==0 && tndex % 1000==0) std::cout<<"\r Check progress "<<undex<<" / "<<totalbins<<" of "<<tndex<<std::flush;
            double cv_j = hCV->GetBinContent( (undex - 1)%nbins + 1);
            double var_j = h_concat->GetBinContent( undex);

            double diff_i = var_i - cv_i;
            double diff_j = var_j - cv_j;

            double cov = diff_i * diff_j;

            hCov->SetBinContent(tndex, undex, cov);
            //            std::cout<<"("<<tndex<<","<<undex<<")="<<cov<<std::endl;
            //            std::cout<<"       "<<"cv_i:"<<cv_i<<" cv_j:"<<cv_j<<" var_i:"<<var_i<<" var_j:"<<var_j<<std::endl;
        }
		if(tndex % 1000==0) std::cout<<">> Next Bin"<<std::endl;
    }

    return hCov;
}

void ExportPNG_Overlays(
        TH1D* hist, 
        TH1D* hist2, 
        TLegend *leg, 
        TString name,  
        TString Xaxis, 
        TString Yaxis= "Events", 
        bool logY = false){
    //Add estimator
    gStyle->SetPaintTextFormat("4.1f%%");//draw numbers with percentage


    TCanvas* c = new TCanvas("c","c",800,600);
    TPad *padT = new TPad("padT","padT",0 , 0.8        ,1 ,   1); //Pad for legend, invaid margin 0.05 below
    TPad *padH = new TPad("padH","padH",0 , 0.3        ,1 ,   0.8);//Pad for Histograms, 
    TPad *padR = new TPad("padR","padH",0 , 0.05    ,1 ,   0.3);//Pad for Ratio, 
    TPad *padB = new TPad("padB","padB",0 , 0        ,1 ,   0.05);//Pad for text, xlow, ylow,xup,yup

    // ---- Pad for Legends
    padT->SetMargin(0,0,0,0);//Setmargins for left,right,bottom,top

    padT->Draw();
    padT->cd();
    leg->Draw();


    // ---- Pad for Histograms
    c->cd();
    padH->SetTopMargin(0.02);//leave some space for the yaxis label
    padH->SetBottomMargin(0);
    //    padH->SetFillColor(kBlue-4); //this labels the area
    padH->Draw();
    padH->cd();
    if(logY) padH->SetLogy();


    //Adjust maximum based on two histograms
    double max = std::max( hist->GetMaximum(), hist2->GetMaximum() );
    hist->SetStats(false);
    hist->Draw("hist E");//MC
    hist2->Draw("hist E same");//MC

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
    DrawRatioPlot( hist2,hist, Xaxis, "Ratio");


    //Draw the rest of the pads, on top of others;

    // ---- Pad for text
    c->cd();
    //    padB->SetFillColor(kCyan-4); //this is useful
    padB->Draw();
    padB->cd();
    TLatex* estimators = GetEstimators( hist, hist2);
    estimators->Draw();

    c->SaveAs("./output/"+name+".pdf");
    c->SaveAs("./output/"+name+".png");
    delete c;
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

    //Draw Canvas for plots
    TCanvas* c = new TCanvas("c","c",800,600);
    TPad *padT = new TPad("padT","padT",0 , 0.8        ,1 ,   1); //Pad for legend, invaid margin 0.05 below
    TPad *padH = new TPad("padH","padH",0 , 0.3        ,1 ,   0.8);//Pad for Histograms, 
    TPad *padR = new TPad("padR","padH",0 , 0.05    ,1 ,   0.3);//Pad for Ratio, 
    TPad *padB = new TPad("padB","padB",0 , 0        ,1 ,   0.05);//Pad for text, xlow, ylow,xup,yup

    // ---- Pad for Legends
    padT->SetMargin(0,0,0,0);//Setmargins for left,right,bottom,top

    padT->Draw();
    padT->cd();
    leg->Draw();


    // ---- Pad for Histograms
    c->cd();
    padH->SetTopMargin(0.02);//leave some space for the yaxis label
    padH->SetBottomMargin(0);
    //    padH->SetFillColor(kBlue-4); //this labels the area
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

    // ---- Pad for text at the bottom
    //Add estimator
    //    gStyle->SetPaintTextFormat("4.1f%%");//draw numbers with percentage
    c->cd();
    //    padB->SetFillColor(kCyan-4); //this is useful
    padB->Draw();
    padB->cd();
    TLatex* estimators = GetEstimators( hist2, errorHist);
    estimators->Draw();

    if(errorHist->Integral() >0){
        c->SaveAs("./output/"+name+".pdf");
        c->SaveAs("./output/"+name+".png");
    } else{
        std::cout<<" No valid events, skip drawing"<<std::endl;
    }
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
    CV->Draw("HIST E");

    double max = CV->GetMaximum();

    //--- Draw variations with different colors
    int colorIndex = 0; // start from red
    for (size_t i = 0; i < variations.size(); ++i) {
        if (!variations[i]) continue;


        variations[i]->SetLineWidth(2);
        variations[i]->SetLineStyle(1);
        if(variations.size()==  static_cast<size_t> (leg->GetNRows()) + 1){//Only change color when legend is for each variations.
            variations[i]->SetLineColor(sampleColor(colorIndex++));
            variations[i]->Draw("HISTSAME E");
        }
        variations[i]->Draw("HISTSAME");


        if(variations[i]->GetMaximum() > max) max = variations[i]->GetMaximum();
    }

    CV->Draw("HISTSAME");//Draw again and put it on top.
    CV->SetMaximum(max*1.2);

    //--- Draw legend on right pad
    pad2->cd();
    leg->Draw();

    //--- Save output
    c->cd();
    c->SaveAs("output/"+SafeName + ".pdf");
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
    int colorIndex = 0; // start from first one
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

        Color_t  t_c = sampleColor(colorIndex++);//this_color
        hdiff->SetLineColorAlpha(t_c, 0.7);
        hdiff->SetMarkerColorAlpha( t_c, 0.7);
        hdiff->SetMarkerStyle(colorIndex + markerIndexOffset);
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
    c->SaveAs("output/"+SafeName + ".pdf");
    c->SaveAs("output/"+SafeName + ".png");

    delete c;
}

void    draw_CovMatrix(const TH1D* CV, 
        const std::vector<TH1D*>& varhists,
        TString SafeName,
        std::vector<TString> axis_texts, 
        TString title,
        bool do_correlation= false){

    TH2D* hCov = BuildCovarianceMatrix( CV, varhists );

    if(do_correlation){
        TH2D *corr = (TH2D*) hCov->Clone("corr");
        for (int i = 1; i <= hCov->GetNbinsX(); ++i) {
            double sigma_i = std::sqrt(hCov->GetBinContent(i, i));
            for (int j = 1; j <= hCov->GetNbinsY(); ++j) {
                double sigma_j = std::sqrt(hCov->GetBinContent(j, j));
                double cij = hCov->GetBinContent(i, j);

                double rho = 0;
                if (sigma_i > 0 && sigma_j > 0)
                    rho = cij / (sigma_i * sigma_j);

                corr->SetBinContent(i, j, rho);
            }
        }
        hCov = corr;
    }

    int Nbins = hCov->GetNbinsX();
    int NbinEachCat =  CV->GetNbinsX();
    int Nvars = varhists.size();

    if(axis_texts.size() != varhists.size()){
        std::cout<<"WARNING: Histogram size is different from texts size"<<std::endl;
        std::cout<<axis_texts.size() << " vs. "<<varhists.size()<<std::endl;
    }

    int file_index = 0;
    hCov->GetXaxis()->SetBinLabel(1,"");
    hCov->GetYaxis()->SetTitle("Bin Number");
    //        hCov->GetYaxis()->LabelsOption("v");
    hCov->SetTitle( title );
    for (int index = 1; index < Nbins+1; ++index) {
        //Print contents
        double var = hCov->GetBinContent(index, index);
        double frac_unc = sqrt(var) / hCov->GetBinContent(index);
        //            std::cout << "Bin " << index << ": Variance = " << var
        //                << ", Fractional = " << frac_unc * 100 << " %" << std::endl;


        //Update labels
        if(( index -1) % NbinEachCat == 0){
            //                hCov->GetXaxis()->SetBinLabel(index, axis_texts[file_index] );
            //                hCov->GetYaxis()->SetBinLabel(index, axis_texts[file_index++] );
            hCov->GetXaxis()->ChangeLabel(index, 0, 0.02, -1, -1, -1, axis_texts[file_index++] ); //Rotation of 0 degrees
            //                hCov->GetYaxis()->ChangeLabel(index, 90, 0.05, -1, -1, -1, axis_texts[file_index++] ); //Rotation of 90 degrees NOT WORKING :(
            //void     ChangeLabel (Int_t labNum=0, Double_t labAngle=-1., Double_t labSize=-1., Int_t labAlign=-1, Int_t labColor=-1, Int_t labFont=-1, const TString &labText="")

        }
    }

    // Hide numeric axis ticks
    //        hCov->GetXaxis()->SetLabelSize(0.05);
    //        hCov->GetYaxis()->SetLabelSize(0.05);


    TCanvas* c1 = new TCanvas("c1", title, 1400, 900);
    hCov->SetStats(0);

    gStyle->SetPaintTextFormat("1.1e");//scientific format 1.23e+03
    hCov->SetMarkerSize(0.6);  // fraction of pad height
    hCov->GetXaxis()->SetTickLength(0);  // removes tick marks
    hCov->GetYaxis()->SetTickLength(0);  // removes tick marks
    hCov->Draw("COLZ TEXT");

    //Draw red box to highlight the diagonal & Extract the values for calculating total uncertaities
    std::vector< double > VarOfBins(NbinEachCat, 0);
    for (int i = 1; i <= Nbins; ++i) {
        //high light them with red boxes
        double x1 = hCov->GetXaxis()->GetBinLowEdge(i);
        double x2 = hCov->GetXaxis()->GetBinUpEdge(i);
        double y1 = hCov->GetYaxis()->GetBinLowEdge(i);
        double y2 = hCov->GetYaxis()->GetBinUpEdge(i);
        TBox* b = new TBox(x1, y1, x2, y2);
        b->SetLineColor(kRed);
        b->SetFillStyle(0);  // transparent fill
        b->SetLineWidth(2);
        b->Draw("same");

        if(( i) % NbinEachCat == 0){
            // vertical line
            TLine* vline = new TLine(i+0.5, 0+0.5, i+0.5,Nbins+0.5);
            vline->SetLineColor(kBlack);
            vline->SetLineWidth(1);
            vline->Draw("same");

            // horizontal line
            TLine* hline = new TLine(0+0.5, i+0.5, Nbins+0.5, i+0.5);
            hline->SetLineColor(kBlack);
            hline->SetLineWidth(1);
            hline->Draw("same");


        }

        //calculate uncertainties
        VarOfBins[( i -1) % NbinEachCat] +=hCov->GetBinContent( i, i);
        //            std::cout<<"CHECK "<<hCov->GetBinContent( i, i)<<" goes to bin "<<( i -1) % NbinEachCat<<std::endl;
    }

    if(!do_correlation){
        std::cout<<"\nTotal uncertainties (not yet exclude stat. unc.): ";
        for (double val : VarOfBins) {
            std::cout << std::sqrt(val) << ", ";
        }

        std::cout<<"\nTotal fractional uncertainties (not exclude stat. unc.): ";
        for (size_t i = 0; i < VarOfBins.size(); ++i) {
            std::cout << std::sqrt(VarOfBins[i]) /CV->GetBinContent(i+1) << ", ";
        }

        //            std::cout<<"\nTotal fractional uncertainties (exclude stat. unc.): ";
        //            for (size_t i = 0; i < VarOfBins.size(); ++i) {
        //                std::cout << std::sqrt(VarOfBins[i] - CV->GetBinContent(i+1))/CV->GetBinContent(i+1) << ", ";
        //            }
        std::cout<<"\n"<<std::endl;
    }



    //--- Save output for small bins
    if(CV->GetNbinsX() < 5){
        c1->cd();
        c1->SaveAs("output/"+SafeName + ".pdf");
        c1->SaveAs("output/"+SafeName + ".png");
    }

}


//Super fast RDataFrame for multisim drawing
//Get the data in place; Use the data (scaling); Config. styles; Draw in a Canvas
struct HistPack {
    ROOT::RDF::RResultPtr<TH1D> cv;
    std::vector<ROOT::RDF::RResultPtr<TH1D>> univ;
};


HistPack makeHists_RDF(
        Samples& sample,
        Vars& var,
        const TString& cvWeight,
        const TString& univWeightExpr, // e.g. "sysWeight"
        int Nuniv
        )
{
    std::vector<double> bins = var.GetBinning();

    ROOT::RDataFrame df(*sample.GetSampleTree());

    auto df_base = df.Filter(sample.GetDefinition().Data());
    std::cout<<"Filter with "<<sample.GetDefinition().Data()<<std::endl;

    ROOT::RDF::TH1DModel model(
            Form("h_%s_%s_CV",
                sample.GetSampleName().Data(),
                var.GetVarName().Data()), //name
            "",//title
            (int)bins[0], bins[1], bins[2] //nbins, xlow, xup
            );


    HistPack out;

    // Give the new branch a simple name, to avoid "Unknown column" error, i.e. RDF does not know compute expressions
    TString newBranchName = "Dummy";

    auto df_var = df_base.Define(newBranchName.Data(),
            var.GetVarName().Data()); // var.GetVarName() can be a complicated expression

    // CV histogram
    auto df_cv = df_var
        .Define("w_cv", cvWeight.Data())
        .Filter("TMath::Finite(w_cv) && w_cv > 0");
    out.cv = df_cv.Histo1D(
            model,
            newBranchName.Data(),
            "w_cv"
            );

    if(false){//call out Weight doctor
        auto df_w = df_cv;
        auto n_total = *df_w.Count();

        auto n_nan = *df_w.Filter("!TMath::Finite(w_cv)").Count();
        auto n_zero = *df_w.Filter("w_cv == 0").Count();
        auto n_neg  = *df_w.Filter("w_cv < 0").Count();
        auto n_huge = *df_w.Filter("abs(w_cv) > 100").Count(); // tune threshold

        std::cout << "CV weight diagnostics:\n"
            << "  total events     = " << n_total << "\n"
            << "  NaN / Inf        = " << n_nan << "\n"
            << "  zero             = " << n_zero << "\n"
            << "  negative         = " << n_neg << "\n"
            << "  huge (>100)      = " << n_huge << "\n";
    }

    // Systematic universes
    for (int k = 0; k < Nuniv; ++k) {
        TString wname = Form("w_u%d", k);
        TString currentW = MakeSafeWgtName(Form("%s[%d]/1000", univWeightExpr.Data(), k));
        out.univ.push_back(
                df_var
                .Define(wname.Data(), currentW.Data())
                .Histo1D(
                    ROOT::RDF::TH1DModel(
                        Form("h_%s_%s_u%d",
                            sample.GetSampleName().Data(),
                            newBranchName.Data(), k),
                        "",
                        (int)bins[0], bins[1], bins[2]
                        ),
                    newBranchName.Data(),
                    wname.Data()
                    )
                );
    }

    //    // ---- CV histogram
    //    out.cv = df_base
    //        .Define("w", MakeSafeWgtName(cvWeight).Data())
    //        .Histo1D(model, var.GetVarName().Data(), "w");
    //
    //    // ---- Systematic universes
    //    for (int k = 0; k < Nuniv; ++k) {
    //        TString currentW =  MakeSafeWgtName(Form("%s[%d]/1000", univWeightExpr.Data(), k));
    //        out.univ.push_back(
    //                df_base
    //                .Define("w", currentW.Data())
    //                .Histo1D(
    //                    ROOT::RDF::TH1DModel(
    //                        Form("h_%s_%s_u%d",
    //                            sample.GetSampleName().Data(),
    //                            var.GetVarName().Data(), k),
    //                        "",
    //                        (int)bins[0], bins[1], bins[2]
    //                        ),
    //                    var.GetVarName().Data(),
    //                    "w"
    //                    )
    //                );
    //        if(k<2)std::cout <<__LINE__<< "univ integral: " << out.univ.back()->Integral() << std::endl;
    //    }

    return out;
}

void draw_variations_v2( 
        TH1D* hist_cv,
        std::vector<TH1D*> hist_univ,
        TLegend *leg, 
        TString SafeName,  
        TString XaxisTitle, 
        TString YaxisTitle= "Events", 
        bool logY = false){

	std::cout<<"Summary of var:"<<SafeName<<std::endl;
    TCanvas* c = new TCanvas("c","c",800,600);
    TPad *padT = new TPad("padT","padT",0.1 , 0.8        ,0.9 ,   1); //Pad for legend, invaid margin 0.05 below; xlow, ylow,xup,yup 
    TPad *padH = new TPad("padH","padH",0 , 0.05        ,1 ,   0.8);//Pad for Histograms, 
    // ---- Pad for Legends
    padT->SetMargin(0,0,0,0);//Set margins for left,right,bottom,top
    //    padT->SetFillColor(kAzure);

    padT->Draw();
    padT->cd();
    leg->Draw();

    // ---- Pad for Histograms
    c->cd();
    padH->SetTopMargin(0.02);//leave some space for the yaxis label
    padH->SetBottomMargin(0.1);
    //    padH->SetFillColor(kOrange);
    padH->Draw();
    padH->cd();
    gStyle->SetOptStat(0);
    if(logY) padH->SetLogy();

    //Set Maximum of the y-axis
    double max = hist_cv->GetMaximum(); 
    hist_cv->SetMaximum(3*max);
    hist_cv->SetTitle("");
    hist_cv->GetXaxis()->SetTitle(XaxisTitle);
    hist_cv->GetYaxis()->SetTitle(YaxisTitle);

    hist_cv->Draw("hist");

    for (auto& u : hist_univ) {
        u->Draw("hist same");
    }
    hist_cv->Draw("hist same");

    //--- Save output
    c->cd();
    c->SaveAs("output/"+SafeName + ".pdf");
    c->SaveAs("output/"+SafeName + ".png");

    delete c;
}




//void draw_2DHist(Samples &CV, std::vector<Samples> &SysChanges,  Vars &var, TString tag){
//
//    TString variable = var.GetVarName();
//    std::vector<double> binnings = var.GetBinning();
//
//    TTree* ttree = sample.GetSampleTree();
//    TString cuts = "("+sample.GetDefinition()+")*("+sample.GetWeight()+")";
//
//}

#endif

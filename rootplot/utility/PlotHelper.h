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

void ExportPNG_StackData(THStack* hist, TH1D* errorHist, TLegend *leg, TString name,  TString Xaxis, TString Yaxis= "Events", bool logY = false){
	TCanvas* c = new TCanvas("c","c",800,600);
	TPad *padD = new TPad("padD","padD",0,   0,  1,   1);
	TPad *padT = new TPad("padT","padT",0, 0.85, 1,   1);

	padD->Draw();
	padD->cd();
	padD->SetTopMargin(0.2);
	if(logY) padD->SetLogy();
	hist->Draw("hist");
//	hist2->Draw("E1P same");
	errorHist->Draw("same E2");


	TLatex *labels_official;
	labels_official = new TLatex(0.65,0.82, "MicroBooNE Simulation, In-Progress");
	labels_official->SetNDC();
	labels_official->SetTextColor(kBlack);
	labels_official->SetTextSize(0.02);
	labels_official->Draw();

	//Adjust maximum based on two histograms
	double max = hist->GetMaximum();
//	if(hist2->GetMaximum() > max) max = hist2->GetMaximum();
	hist->SetMinimum(0.0001);
	hist->SetMaximum(errorHist->GetMaximum()*1.2);

	hist->GetXaxis()->SetTitle(Xaxis);
	hist->GetYaxis()->SetTitle(Yaxis);
	hist->GetYaxis()->SetTitleOffset(1.5);


	c->cd();
	padT->Draw();
	padT->cd();
	leg->Draw();
	c->SaveAs("./output/"+name+".png");
	delete c;
}

void ExportPNG_StackData_wLabel(THStack* hist, TH1D* hist2, TH1D* errorHist, TLegend *leg, TString name,  TString Xaxis, TString Yaxis= "Events", bool logY = false){
	//Add estimator
	gStyle->SetPaintTextFormat("4.1f%%");//draw numbers with percentage

	TLatex *estimators;//Data/MC ratio, KS Test, Chi^2/(nDoF), Chi^2 p-value;
	double histdata_num = hist2->Integral();
	double histMC_num = errorHist->Integral();
	TString text_ratio; text_ratio.Form("Data/MC=%.2f   ",histdata_num/histMC_num); 
	TString text_ks; text_ks.Form("KS: %.2f   ", errorHist->KolmogorovTest(hist2)); 
	TString text_chi2; text_chi2.Form("#chi^{2}/n#it{DOF}=%.2f/%d p=%.2g   ", errorHist->Chi2Test(hist2,"UW CHI2"), 
																			errorHist->GetNbinsX()-1, 
																			errorHist->Chi2Test(hist2,"UW P"));

//soruce code at https://root.cern.ch/doc/master/TH1_8cxx_source.html#l01995
	std::cout<<"Chi2Test Check "<< errorHist->Chi2Test(hist2,"WU CHI2")<<std::endl;

	TString combined = text_ratio + text_ks + text_chi2;


	TCanvas* c = new TCanvas("c","c",800,600);
	TPad *padB = new TPad("padB","padB",0.02,  0.02,   0.98,   0.05);
	TPad *padD = new TPad("padD","padD",0.02,  0.05,  0.98,   0.8);
	TPad *padT = new TPad("padT","padT",0.02, 0.8 - 0.05,  0.98,   0.95); // invaid margin 0.05 below
	estimators = new TLatex(0.05, 0.3, combined);

	padD->SetTopMargin(-2);
//	padD->SetFillColor(kBlue-4); //this is useful
	padD->Draw();
	padD->cd();
	if(logY) padD->SetLogy();
	hist->Draw("hist");
	hist2->Draw("E1P same");
	errorHist->Draw("same E2");


	//Adjust maximum based on two histograms
	double max = hist->GetMaximum();
	if(hist2->GetMaximum() > max) max = hist2->GetMaximum();
	hist->SetMinimum(0.00001);
	hist->SetMaximum(max*1.2);

	hist->GetXaxis()->SetTitle(Xaxis);
	hist->GetYaxis()->SetTitle(Yaxis);
	hist->GetYaxis()->SetTitleOffset(1.5);

	//Draw the rest of the pads;
	c->cd(0);
//	padB->SetFillColor(kCyan-4); //this is useful
	padB->Draw();
	padB->cd();
	estimators->SetTextColor(kRed-7);
	estimators->SetTextSize(0.8);
	estimators->Draw();


	c->cd();
	padT->SetBottomMargin(0);
//	padT->SetFillColor(kRed-4); //This is useful
	padT->Draw();
	padT->cd();
	leg->Draw();
	c->SaveAs("./output/"+name+".png");
	delete c;
}



//Template for drawing different hists
template <typename T>
void ExportPNGwLegend(T hist, TString name, TLegend *leg, TString Xaxis, TString Yaxis= "Events"){
	TCanvas* c = new TCanvas("c","c",800,600);
	TPad *padD = new TPad("padD","padD",0,   0,  1,   1);
	TPad *padT = new TPad("padT","padT",0, 0.85, 1,   1);

	padD->Draw();
	padD->cd();
	padD->SetTopMargin(0.2);
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

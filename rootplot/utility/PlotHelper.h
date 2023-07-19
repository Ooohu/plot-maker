#ifndef PLOTHELPER_H
#define PLOTHELPER_H

#include "ConfigureSamples.h"
#include "ConfigureVars.h"
#include "Gadgets.h"

//Template for drawing different hists
template <typename T>
void ExportPNG(T hist, TString name, TString Xaxis, TString Yaxis= "Events"){
	TCanvas* c = new TCanvas("c","c",800,600);
	hist->Draw("colz");
	hist->GetXaxis()->SetTitle(Xaxis);
	hist->GetYaxis()->SetTitle(Yaxis);
	c->SaveAs("./output/"+name+".png");
	delete c;
}

void ExportPNG_StackData(THStack* hist, TH1D* hist2, TH1D* errorHist, TLegend *leg, TString name,  TString Xaxis, TString Yaxis= "Events", bool logY = false){
	TCanvas* c = new TCanvas("c","c",800,600);
	TPad *padD = new TPad("padD","padD",0,   0,  1,   1);
	TPad *padT = new TPad("padT","padT",0, 0.85, 1,   1);

	padD->Draw();
	padD->cd();
	padD->SetTopMargin(0.2);
	if(logY) padD->SetLogy();
	hist->Draw("hist");
	hist2->Draw("E1P same");
	errorHist->Draw("same E2");


	//Adjust maximum based on two histograms
	double max = hist->GetMaximum();
	if(hist2->GetMaximum() > max) max = hist2->GetMaximum();
	hist->SetMinimum(0.001);
	hist->SetMaximum(max*1.2);

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

	if(linecolor == 0 || fillstyle == 0) std::cout<<"Warning: "<<sample.GetSampleName()<<" histogram color/style is not set."<<std::endl;
	h->SetLineColor(kBlack);
	h->SetFillColor(linecolor);
	h->SetFillStyle(fillstyle);
	h->Scale(sample.GetScale());
	return h;
}

#endif

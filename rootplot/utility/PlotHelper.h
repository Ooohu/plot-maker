#ifndef PLOTHELPER_H
#define PLOTHELPER_H

#include "ConfigureSamples.h"
#include "ConfigureVars.h"
#include "Gadgets.h"

	//Draw a TH1D
TH1D* drawTH1D(Samples sample, Vars var)
{
	//spell out contents that we need from two classes
	TString variable = var.GetVarName();
	std::vector<double> binnings = var.GetBinning();

	TTree* ttree = sample.GetSampleTree();
	TString cuts = sample.GetDefinition();
	int linecolor = sample.GetCol();
	int fillstyle = sample.GetFillStyle();
	//default is (nbins, bmin, bmax);
	TH1D* h = new TH1D(RandomName(), "", binnings[0], binnings[1], binnings[2]);
	ttree->Draw(variable+">>"+h->GetName(), cuts);

	h->SetLineColor(linecolor);
	h->SetFillColor(linecolor);
	h->SetFillStyle(fillstyle);
	return h;
}

//void FillStack(THStack* stack, Samples sample, Vars var, double final_pot)
//{
//	TH1D* h = drawTH1D(sample, var);
//	h->Scale(sample.GetPOT()/final_pot);
//	stack->Add(h);
//}

#endif

#include "utility/PlotHelper.h"

void TTree2StackOverlays(){
	//Configure class Samples: name, input file, tree name, cut
	Samples signal("sample_sig","./input/glee_ntuple.root", "singlephotonana/vertex_tree","reco_asso_showers>-1");
	signal.SetPlotStyle(kRed-5, 3245);
	signal.SetPOT(1.0e20);

	Samples bkg("sample_bkg","./input/glee_ntuple.root", "singlephotonana/vertex_tree","reco_vertex_y>0");
	bkg.SetPlotStyle(kBlue-5, 3245);
	bkg.SetMCPOT();


	TString Precut = "reco_asso_tracks == 1 && reco_asso_showers == 0";

	//Configure class Vars: varaibles, axis name, binnings 
	Vars var1("Reco. Vertex X", "reco_vertex_x", {10,0,500});
	

	//Create THStack
	THStack *hs = new THStack(RandomName(), "");

	//Add legends
	TLegend *leg = new TLegend(0.05,0.01,0.95,0.95);
	leg->SetFillStyle(0);
	leg->SetLineWidth(0);
	leg->SetNColumns(3);
	
	//Fill THStack & Legend
	std::vector< Samples > vecSamples = {signal, bkg};
	TH1D* errorHist = 0;

	for(auto &sample : vecSamples){
		sample.AddDefinition(Precut);

		TH1D* hist = drawTH1D(sample, var1);
		hist->Scale(data.GetPOT()/sample.GetPOT());

		TString leg_title = sample.GetSampleName() + Form(" %.1lf",hist->Integral());
		leg->AddEntry(hist, leg_title ,"fl");

		hs->Add(hist);

		if(errorHist){
			errorHist->Add(hist);
		} else{
			errorHist = (TH1D*) hist->Clone();
		}
	}
	
	signal.AddDefinition(Precut);
	TH1D* hdata = drawTH1D(signal, var1);
	hdata->SetMarkerSize(2);//data
	hdata->SetMarkerStyle(20);//data
	TString leg_title = data.GetSampleName() + Form(" %.0lf",hdata->Integral());
	leg->AddEntry( hdata, leg_title, "fl");


	//errorHist style
	errorHist->SetMarkerSize(0);
	errorHist->SetFillStyle(3454);
	errorHist->SetLineWidth(2);
	errorHist->SetLineColor(kBlack);
	errorHist->SetFillColor(kBlack);
	leg->AddEntry(errorHist, "Stat. Error", "fl");

	ExportPNG_StackData(hs, hdata, errorHist, leg, "testwLOL", var1.GetAxisLabel());
	}

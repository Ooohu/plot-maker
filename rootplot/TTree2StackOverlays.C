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

	//Fill THStack & Legend
	std::vector< Samples > vecSamples = {signal, bkg};
	for(auto &sample : vecSamples){
		sample.AddDefinition(Precut);

		TH1D* hist = drawTH1D(sample, var1);
		hist->Scale(sample.GetPOT()/signal.GetPOT());
		leg->AddEntry(hist,sample.GetSampleName(),"fl");

		hs->Add(hist);
	}
	
	//Create TH1 and configure it
//	TH1D *hsignal = signal.drawTH1D(var1.GetVarName(), var1.GetBinning());
//	hsignal->Scale(2e20/ signal.GetPOT());
//	hs->Add(hsignal);
//
//	TH1D *hbkg = bkg.drawTH1D(var1.GetVarName(), var1.GetBinning());
//	hbkg->Scale(2e20/ signal.GetPOT());
//	hs->Add(hbkg);


//	leg->AddEntry(hsignal,signal.GetSampleName(),"fl");
//	leg->AddEntry(hbkg,bkg.GetSampleName(), "fl");

	//Draw THStack
//	ExportPNG(hs, "test", var1.GetAxisLabel());
	ExportPNGwLegend(hs, "testwL", leg, var1.GetAxisLabel());
	}

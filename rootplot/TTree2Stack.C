#include "utility/ConfigureSample.h"


void TTree2Stack(){
	Samples signal("test","./input/glee_ntuple.root", "singlephotonana/vertex_tree","1");
	signal.setPlotStyle(kRed-5, 3245);

	TTree *tree1 = GetTree("./input/glee_ntuple.root","singlephotonana/vertex_tree");
	TTree *tree2 = GetTree("./input/glee_ntuple.root","singlephotonana/vertex_tree");

	TString var = "reco_vertex_x";
	TString Precut = "reco_asso_tracks == 1 && reco_asso_showers == 0";

	std::vector< double > binning = {10, 0, 500};

	//Check Number of entries of the TTree
	cout << "Number of entries: " << tree1->GetEntries() << endl;

	THStack *hs = new THStack(RandomName(), "Stacked 1D histograms");

	//Create TH1 and configure it
	

	TString TH1_name1 = RandomName();
	TH1D *h1 = new TH1D(TH1_name1, "h1", binning[0], binning[1], binning[2]);
	tree1->Draw(var+">>"+ TH1_name1, Precut);
	SetHist(h1, kBlack, kRed-5, 3245);
	hs->Add(h1);

	TH1D *h2 = new TH1D(TH1_name1, "h1", binning[0], binning[1], binning[2]);
	tree2->Draw(var+">>"+ TH1_name1, Precut+"&& reco_vertex_z > 400");
	SetHist(h2, kBlack, kBlue-5, 3245);
	hs->Add(h2);

	TH1D *hsignal = signal.drawTH1D(var, binning);


	//Add legends
	TLegend *leg = new TLegend(0.05,0.01,0.95,0.95);
	leg->SetFillStyle(0);
	leg->SetLineWidth(0);
	leg->AddEntry(h1,"h1","fl");
	leg->AddEntry(h2,"h2","fl");
//	leg->SetBorderSize(0);
	

	//Draw THStack
	ExportPNG(hs, "test", var);
	ExportPNGwLegend(hs, "testwL", leg, var);
	}

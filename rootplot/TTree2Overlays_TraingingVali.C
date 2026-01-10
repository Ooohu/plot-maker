#include "utility/PlotHelper.h"
#include "VarsList_BDT.C"
#include "LoadSamples_TrainingVali.h"
#include "LoadStyles.h"

#include "utility/CutScanner.h"

#include <iostream>
#include <fstream>
#include <sstream>

void TTree2Overlays_TraingingVali(){
	//Configure class Samples: name, input file, tree name, cut
	//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

	std::vector< TString > tag={"ma084"};
	//	std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};
	std::stringstream text_buffer;

	bool show_training = true;

	// PREPARE SAMPLES -----------------------------------------------------------------
	TString axiontag = tag[0];//"ma003";

	Samples axion084		= LoadAxions084	(axiontag);
	Samples axion084T		= LoadAxions084T(axiontag);

	Samples axion084s		= LoadAxions084s	(axiontag);
	Samples axion084sT		= LoadAxions084sT(axiontag);

	Samples OneAllpi0		= LoadAllFHCOnepi0 (axiontag);
	Samples OneAllpi0T		= LoadAllFHCOnepi0T (axiontag);
//	Samples OneAllpi0t			= LoadAllFHCOnepi0t (axiontag);//true training events
//	Samples OneAllpi0tT		= LoadAllFHCOnepi0tT (axiontag);


	double PlotPOT = 2E21;// data.GetPOT();

	// PRECUT --------------------------------------------------------------------------------
	TString Label = "NuMIFHCRuns_cleanPi0Train"+axiontag+"_2s0t_twoMassPoints";
	TString Precut = "(reco_asso_tracks == 0 && reco_asso_showers == 2)";
//	Precut +="&& reco_vertex_dist_to_SCB > 2";
//
//	Precut +="&&( reco_shower_energy_max[i_shr[0]]/1000.0 > 0.03)";//LeadingShrEnergy
//	Precut +="&&((reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)>0.8)"; //CosBeta LeadingShr
//	Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003CosmicClassifier_mva > 0.2";//It does so well in cosmic elimination??

	// Configure class Var: varaibles, axis name, binnings  ----------------------------------
	std::vector< Vars> allVar = SetMultipleVars();


	// Start making histograms --------------------------------------------------------------------
	//-->  Setup Pair comparison
	std::vector< std::pair <Samples, Samples > > pairs = {
		{axion084, axion084T},
		{axion084s, axion084sT},
		{OneAllpi0, OneAllpi0T},
//		{OneAllpi0t, OneAllpi0tT}
//		{Onepi0, Onepi0T},
//		{NueCC, NueCCT},
//		{ext, extT},
//		{ext2a, ext2aT},
//		{extAll, extAllT}
	};

	for( size_t index = 0; index < pairs.size(); ++index){
		for(Vars & temp_var : allVar){
			TLegend *leg = LoadLegend(); //Add legends
			TString leg_title ;


			//Prepare signals, overlay them;
			Samples S1 = pairs[index].first;
			Samples S2 = pairs[index].second;

			S1.AddDefinition(Precut);
			TH1D* hS1 = drawTH1D(S1, temp_var);
			hS1->SetFillColorAlpha( S1.GetCol(), 0.5); 
			hS1->SetLineWidth(3);
			hS1->SetLineColor(S1.GetCol());
			hS1->Scale(PlotPOT/S1.GetPOT());
			leg_title = S1.GetSampleName() + Form(" %.1lf",hS1->Integral());
			leg->AddEntry( hS1, leg_title, "fl");

			S2.AddDefinition(Precut);
			TH1D* hS2 = drawTH1D(S2, temp_var);
			hS2->SetFillColorAlpha( S2.GetCol(), 0.5); 
			hS2->SetLineWidth(3);
			hS2->SetLineColor(S2.GetCol());
			hS2->Scale(PlotPOT/S2.GetPOT());
			leg_title = S2.GetSampleName() + Form(" %.1lf",hS2->Integral());
			leg->AddEntry( hS2, leg_title, "fl");

			ExportPNG_Overlays(hS1, hS2, leg, MakeSafeName(Label+temp_var.GetAxisLabel()+S1.GetSampleName()+S2.GetSampleName()) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());


		}
	}//Next variable

}

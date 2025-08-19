#include "utility/PlotHelper.h"
#include "TTree2StackOverlays_axion_common.C"
//#include "LoadSamples_newCatRun1_TrainingSample.h"
//#include "LoadSamples_newCatRun1.h"
#include "LoadSamples_FHCRuns_Run1.h"
#include "LoadStyles.h"

#include "utility/CutScanner.h"

#include <iostream>
#include <fstream>
#include <sstream>

void TTree2StackOverlays_run1axion_AllMass_twoPoints(){
	//Configure class Samples: name, input file, tree name, cut
	//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

	std::vector< TString > tag={"ma003"};
	//	std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};
	std::stringstream text_buffer;

	bool show_training = true;

	// PREPARE SAMPLES -----------------------------------------------------------------
	TString axiontag = tag[0];//"ma003";

	Samples axion003		= LoadAxions003	(axiontag);
	Samples axion0146		= LoadAxions0146	(axiontag);
	Samples axion084		= LoadAxions084	(axiontag);

	Samples axion003T		= LoadAxions003T(axiontag);
//	Samples BkgCHECK		= LoadRun2aAll (axiontag);//This would be a duplicated;

//	Samples ALL = LoadRun1All(axiontag);//Pass
	Samples Onepi0		= LoadRun1Onepi0 (axiontag);
	Samples NueCC		= LoadRun1NueCC (axiontag);
	Samples NumuCC		= LoadRun1NumuCC (axiontag);
	Samples InCryoOther 	= LoadRun1InCryoOther (axiontag);
	Samples dirt		= LoadRun1Dirt		(axiontag);
	Samples data		= LoadRun1FHCData		(axiontag);
	Samples ext			= LoadRun1EXT		(axiontag);


	double PlotPOT = data.GetPOT();

	// PRECUT --------------------------------------------------------------------------------
	TString Label = "AxionRun1FHC"+axiontag+"_2s0t_twoMassPoints";
	TString Precut = "(reco_asso_tracks == 0 && reco_asso_showers == 2)";
	Precut +="&&( NuMIFHCRuns_ma003PionClassifier_mva < 0.6)";
//	Precut +="&&( reco_vertex_dist_to_SCB > 2)";
//	Precut +="&&( reco_shower_energy_max[i_shr[0]]/1000.0 > 0.03)";//LeadingShrEnergy
//	Precut +="&&((reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)>0.8)"; //CosBeta LeadingShr
//	Precut +="&&(((reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1])*0.462372+(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1])*0.0488541+(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1])*0.885339)/(sqrt(pow(reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1],2) + pow(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1],2)+pow(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1],2)))>0.4)";//MesonCBeta
//	Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003CosmicClassifier_mva > 0.2";//It does so well in cosmic elimination??

//	Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003CosmicClassifier_mva < 0.25";//Non-signal regon
//	Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003PionClassifier_mva < 0.3";//signal regon
//	Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003NueCCClassifier_mva < 0.5";//Non-signal regon
	//Optimized for NueCC
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003PionClassifier_mva < 0.5";//Non-signal regon
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003NueCCClassifier_mva < 0.3";//Non-signal regon
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003CosmicClassifier_mva > 0.7";//Non-signal regon

	//Optimized for Pi0
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003PionClassifier_mva < 0.3";//Non-signal regon
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003NueCCClassifier_mva < 0.5";//Non-signal regon
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003CosmicClassifier_mva > 0.9";//Non-signal regon

	//Optimized for axions003
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003PionClassifier_mva > 0.98";//signal regon
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003NueCCClassifier_mva > 0.97";//signal regon
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003CosmicClassifier_mva > 0.94";//signal regon
	//		Precut +="&& NuMIFHCRun1AxionV2_newCat_ma003AxionLikeClassifier_mva > 0.5";//Non-signal regon
	//		Strategy: box cuts then PyHF in inv. mass

	bool ScanCut = false;

	// Configure class Var: varaibles, axis name, binnings  ----------------------------------
	std::vector< Vars> allVar = SetMultipleVars();

	if(ScanCut){//Scan variables for optimized cuts
//					BDTCutScan( axion003, {Onepi0, NueCC, NumuCC, InCryoOther, dirt, ext}, allVar);
//					BDTCutScanTwoDirections( Onepi0, {NueCC, NumuCC, InCryoOther, dirt, ext}, allVar);
					BDTCutScanTwoDirections( NueCC, {Onepi0, NumuCC, InCryoOther, dirt, ext}, allVar);
		return;
	}


	// Start making histograms --------------------------------------------------------------------
	//--> Draw Stacked Histograms
	for(Vars & temp_var : allVar){
		TLegend *leg = LoadLegend(); //Add legends
		TString leg_title ;

		//Prepare signals, overlay them;
		axion003.AddDefinition(Precut);
		TH1D* haxion003 = drawTH1D(axion003, temp_var);
		haxion003->SetFillColorAlpha( axion003.GetCol(), 0.9); 
		haxion003->SetLineWidth(3);
		haxion003->SetLineColor(axion003.GetCol());
		leg_title = axion003.GetSampleName() + Form(" %.1lf",haxion003->Integral());
		leg->AddEntry( haxion003, leg_title, "fl");

		axion003T.AddDefinition(Precut);
		TH1D* haxion003T = drawTH1D(axion003T, temp_var);
		haxion003T->SetFillColorAlpha( axion003T.GetCol(), 0.9); 
		haxion003T->SetLineWidth(3);
		haxion003T->SetLineColor(axion003T.GetCol());
		leg_title = axion003T.GetSampleName() + Form(" %.1lf",haxion003->Integral());
	

		axion0146.AddDefinition(Precut);
		TH1D* haxion0146 = drawTH1D(axion0146, temp_var);
		haxion0146->SetFillColorAlpha( axion0146.GetCol(), 0.9); 
		haxion0146->SetLineWidth(3);
		haxion0146->SetLineColor(axion0146.GetCol());
		leg_title = axion0146.GetSampleName() + Form(" %.1lf",haxion0146->Integral());
		leg->AddEntry( haxion0146, leg_title, "fl");
	


		axion084.AddDefinition(Precut);
		TH1D* haxion084 = drawTH1D(axion084, temp_var);
		haxion084->SetFillColorAlpha( axion084.GetCol(), 0.9); 
		haxion084->SetLineWidth(3);
		haxion084->SetLineColor(axion084.GetCol());
		leg_title = axion084.GetSampleName() + Form(" %.1lf",haxion084->Integral());
		leg->AddEntry( haxion084, leg_title, "fl");



		//Now backgrounds are stacked
		THStack *hs = new THStack(RandomName(), "");// Create Stack
		TH1D* errorHist = 0;// Create a empty hist for storing all bkgs
//		std::vector<Samples> vecSamples = {  ext, Onepi0, NueCC, NumuCC, InCryoOther, dirt};
		std::vector<Samples> vecSamples = { Onepi0, NueCC, NumuCC, InCryoOther, dirt, ext};
		//	std::vector<Samples> vecSamples = {axion};
		for(auto &sample : vecSamples){
			sample.AddDefinition(Precut);

			TH1D* hist = drawTH1D(sample, temp_var);
			//		std::cout<<"Total evts: "<<hist->Integral()<<std::endl;
			hist->Scale(PlotPOT/sample.GetPOT());

			leg_title = sample.GetSampleName() + Form(" %.1lf",hist->Integral());
			leg->AddEntry(hist, leg_title ,"fl");
			std::cout<<"\nSummary: "<< leg_title<<std::endl;
			std::cout<<PrintHist(hist);

			hs->Add(hist);

			if(errorHist){
				errorHist->Add(hist);
			} else{
				errorHist = (TH1D*) hist->Clone();
				text_buffer<<"\nSummary: "<< leg_title<<"\n"<<PrintHist(hist);
			}
		}

		//--> Draw histogram: data overlay
		data.AddDefinition(Precut);
		TH1D* hdata = drawTH1D(data, temp_var);
		hdata->Scale(PlotPOT/data.GetPOT());
		hdata->SetMarkerSize(1);//data
		hdata->SetMarkerStyle(20);//data

		leg_title = data.GetSampleName() + Form(" %.0lf",hdata->Integral());
		leg->AddEntry( hdata, leg_title, "fl");

		text_buffer<<"\nSummary: "<< leg_title<<"\n"<< PrintHist(hdata);


		//errorHist style
		SetErrorStyle(errorHist);

//		TString mc_leg_title = Form("Stat. Error | Total Pred.: %.1lf",errorHist->Integral());
		TString mc_leg_title = Form("Stat. Error | Bkg Sum: %.1lf",errorHist->Integral());
		leg->AddEntry(errorHist, mc_leg_title, "fl");
		text_buffer<<"\nSummary total MC:"<<"\n"<< PrintHist(errorHist);

		if(show_training){
			ExportPNG_StackDataTwoSignal_wLabel({haxion003, haxion003T, haxion0146, haxion084}, hs, hdata, errorHist, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());
		}else{
			ExportPNG_StackDataTwoSignal_wLabel({haxion003, haxion0146, haxion084}, hs, hdata, errorHist, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());
		}

	}//Next variable

	std::ofstream outFile("output.txt");
	std::string output_text = text_buffer.str();
	outFile<<output_text;
	outFile.close();

}

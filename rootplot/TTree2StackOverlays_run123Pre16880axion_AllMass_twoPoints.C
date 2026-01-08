#include "utility/PlotHelper.h"
#include "TTree2StackOverlays_axion_common.C"
#include "LoadSamples_Signal.h"
#include "LoadSamples_newCatRun3Pre16880.h"
#include "LoadStyles.h"

#include "utility/CutScanner.h"

#include <iostream>
#include <fstream>
#include <sstream>

void TTree2StackOverlays_run123Pre16880axion_AllMass_twoPoints(){
	//Configure class Samples: name, input file, tree name, cut
	//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

	//scalings_run1 = { "nu":1./2.35e21, "dirt":1.0*0.75/1.55e21, "beamoff": 0.98*(6230439.0/9186361.390000)}
	//scalings_run3 = { "nu":1./(1.993661e21), "dirt":1.0*0.35/1.020e21, "beamoff": 0.98*(10714868.0/34147459.925000)}

	std::vector< TString > tag={"ma0146"};
	//	std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};
	std::stringstream text_buffer;

	// PREPARE SAMPLES -----------------------------------------------------------------
	TString axiontag = tag[0];//"ma003";

	Samples axion003		= LoadAxions003	(axiontag);
	Samples axion084		= LoadAxions084	(axiontag);

//	Samples BkgCHECK		= LoadRun3All (axiontag);//This would be a duplicated;

	Samples Onepi0		= LoadRun3Onepi0 (axiontag);
	Samples NueCC		= LoadRun3NueCC (axiontag);
	Samples OtherCC 	= LoadRun3OtherCC (axiontag);
	Samples OtherNC 	= LoadRun3OtherNC (axiontag);
	Samples dirt		= LoadRun3Dirt		(axiontag);
	Samples data		= LoadRun3Pre16880RHCData		(axiontag);
	Samples ext			= LoadRun3Pre16880EXT		(axiontag);


	double PlotPOT = data.GetPOT();

	// PRECUT --------------------------------------------------------------------------------
	TString Label = "AxionRun3"+axiontag+"_2s0t_twoMassPoints";
	TString Precut = "(reco_asso_tracks == 0 && reco_asso_showers == 2)";
	Precut +="&& reco_vertex_dist_to_SCB > 2";
	//Optimized for NueCC
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003CosmicClassifier_mva > 0.1";//Non-signal regon
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003PionClassifier_mva < 0.8";//Non-signal regon
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003NueCCClassifier_mva > 0.1";//Non-signal regon

	//Optimized for Pi0
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003PionClassifier_mva < 0.5";//Non-signal regon
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003NueCCClassifier_mva > 0.7";//Non-signal regon
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003CosmicClassifier_mva > 0.7";//Non-signal regon

	//Optimized for axions
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003PionClassifier_mva > 0.97";//signal regon
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003NueCCClassifier_mva > 0.9";//signal regon
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003CosmicClassifier_mva > 0.9";//signal regon
	//		Precut +="&& NuMIRHCRun3Pre16880AxionV3ma003AxionLikeClassifier_mva > 0.5";//Non-signal regon
	//		Strategy: box cuts then PyHF in inv. mass

	bool ScanCut = true;

	// Configure class Var: varaibles, axis name, binnings  ----------------------------------
	std::vector< Vars> allVar = SetMultipleVars();

	if(ScanCut){//Scan variables for optimized cuts
					BDTCutScan( axion003, {Onepi0, NueCC, OtherNC, dirt, ext}, allVar);
		//			BDTCutScanTwoDirections( OtherCC, {Onepi0, Twopi0, OtherNC, dirt, ext}, allVar);
//		BDTCutScanTwoDirections( Onepi0, { OtherCC, OtherNC, dirt, ext}, allVar);
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
		haxion003->SetFillColorAlpha( axion003.GetCol(), 0.75); 
		haxion003->SetFillStyle(3436);
		haxion003->SetLineColor(axion003.GetCol());
		leg_title = axion003.GetSampleName() + Form(" %.1lf",haxion003->Integral());
		leg->AddEntry( haxion003, leg_title, "fl");


		axion084.AddDefinition(Precut);
		TH1D* haxion084 = drawTH1D(axion084, temp_var);
		haxion084->SetFillColorAlpha( axion084.GetCol(), 0.75); 
		haxion084->SetFillStyle(3663);
		haxion084->SetLineColor(axion084.GetCol());
		leg_title = axion003.GetSampleName() + Form(" %.1lf",haxion003->Integral());
		leg_title = axion084.GetSampleName() + Form(" %.1lf",haxion084->Integral());
		leg->AddEntry( haxion084, leg_title, "fl");



		//Now backgrounds are stacked
		THStack *hs = new THStack(RandomName(), "");// Create Stack
		TH1D* errorHist = 0;// Create a empty hist for storing all bkgs
		std::vector<Samples> vecSamples = { Onepi0, NueCC, OtherCC, OtherNC, dirt, ext};
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

		ExportPNG_StackDataTwoSignal_wLabel({haxion003, haxion084}, hs, hdata, errorHist, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());
	}//Next variable

	std::ofstream outFile("output.txt");
	std::string output_text = text_buffer.str();
	outFile<<output_text;
	outFile.close();

}

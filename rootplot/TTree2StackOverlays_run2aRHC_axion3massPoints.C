#include "utility/PlotHelper.h"
#include "LoadStyles.h"

#include "utility/CutScanner.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "VarsList.C"
#include "LoadSamples_Signals.h"
//#include "LoadSamples_JumboMC.h"
#include "LoadSamples_RHCRuns_Run2.h"

#include "CommonCut.C"

void TTree2StackOverlays_run2aRHC_axion3massPoints(){
	//Configure class Samples: name, input file, tree name, cut
	//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

	std::vector< TString > tag={"ma0146"};
	//	std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};

	// PREPARE SAMPLES -----------------------------------------------------------------
	TString axiontag = tag[0];//"ma003";
	TString JSONfileName="JSON_output/"+axiontag+".json";
	TString Label = "NuMIaxionsRun2aRHC"+axiontag+"_2s0t_twoMassPoints";

//	Samples axion003		= LoadAxions003	(axiontag);
	Samples axion0146		= LoadAxions0146	(axiontag);
	Samples axion084		= LoadAxions084	(axiontag);

	Samples ext			= LoadJumboEXT		(axiontag);

	Samples Onepi0		= LoadRun2RHCOnepi0 (axiontag);
	Samples NueCC		= LoadRun2RHCNueCC (axiontag);
	Samples NumuCC		= LoadRun2RHCNumuCC (axiontag);
	Samples InCryoOther = LoadRun2RHCInCryoOther (axiontag);

	Samples dirt		= LoadRun2RHCDirt		(axiontag);

	Samples data		= LoadRun2aRHCData		(axiontag);


	double PlotPOT = ILikeThisPOT( data );

	// PRECUT --------------------------------------------------------------------------------

	TString Precut = GetCut();

	bool ScanCut = false;

	// Configure class Var: varaibles, axis name, binnings  ----------------------------------
	std::vector< Vars> allVar = SetMultipleVars();

	if(ScanCut){//Scan variables for optimized cuts
		BDTCutScanTwoDirections( NueCC, {Onepi0, NumuCC, InCryoOther, dirt, ext}, allVar);
		return;
	}


	// Start making histograms --------------------------------------------------------------------
	//--> Draw Stacked Histograms
	JSONStore store;

	for(Vars & temp_var : allVar){
		TLegend *leg = LoadLegend(); //Add legends
		TString leg_title ;

		//Prepare signals, overlay them;
//		axion003.AddDefinition(Precut);
//		TH1D* haxion003 = drawTH1D(axion003, temp_var);
//		haxion003->SetFillColorAlpha( axion003.GetCol(), 0.9); 
//		haxion003->SetLineWidth(3);
//		haxion003->SetLineColor(axion003.GetCol());
//		leg_title = axion003.GetSampleName() + Form(" %.1lf",haxion003->Integral());
//		leg->AddEntry( haxion003, leg_title, "fl");

//		axion003T.AddDefinition(Precut);
//		TH1D* haxion003T = drawTH1D(axion003T, temp_var);
//		haxion003T->SetFillColorAlpha( axion003T.GetCol(), 0.9); 
//		haxion003T->SetLineWidth(3);
//		haxion003T->SetLineColor(axion003T.GetCol());
//		leg_title = axion003T.GetSampleName() + Form(" %.1lf",haxion003->Integral());
	

		axion0146.AddDefinition(Precut);
		TH1D* haxion0146 = drawTH1D(axion0146, temp_var);
		haxion0146->SetFillColorAlpha( axion0146.GetCol(), 0.9); 
		haxion0146->SetLineWidth(3);
		haxion0146->SetLineColor(axion0146.GetCol());
		leg_title = axion0146.GetSampleName() + Form(" %.1lf",haxion0146->Integral());
		leg->AddEntry( haxion0146, leg_title, "fl");

		store[Label.Data()][temp_var.GetAxisLabel().Data()][axion0146.GetSampleName().Data()] = 
		{HistToCV(  haxion0146), HistToErr( haxion0146)};

		axion084.AddDefinition(Precut);
		TH1D* haxion084 = drawTH1D(axion084, temp_var);
		haxion084->SetFillColorAlpha( axion084.GetCol(), 0.9); 
		haxion084->SetLineWidth(3);
		haxion084->SetLineColor(axion084.GetCol());
		leg_title = axion084.GetSampleName() + Form(" %.1lf",haxion084->Integral());
		leg->AddEntry( haxion084, leg_title, "fl");


		store[Label.Data()][temp_var.GetAxisLabel().Data()][axion084.GetSampleName().Data()] = 
		{HistToCV(  haxion084), HistToErr( haxion084)};

		//Now backgrounds are stacked
		THStack *hs = new THStack(RandomName(), "");// Create Stack
		TH1D* errorHist = nullptr;// Create a empty hist for storing all bkgs
		TH1D* MCOnly = nullptr;
//		std::vector<Samples> vecSamples = {  ext, Onepi0, NueCC, NumuCC, InCryoOther, dirt};
		std::vector<Samples> vecSamples = { Onepi0, NueCC, NumuCC, InCryoOther, dirt, ext};

		for (size_t i = 0; i < vecSamples.size(); ++i) {

			auto& sample = vecSamples[i];
			sample.AddDefinition(Precut);

			TH1D* hist = drawTH1D(sample, temp_var);
			//		std::cout<<"Total evts: "<<hist->Integral()<<std::endl;
			hist->Scale(PlotPOT/sample.GetPOT());

			leg_title = sample.GetSampleName() + Form(" %.1lf",hist->Integral());
			leg->AddEntry(hist, leg_title ,"fl");

			std::cout<<"\nSummary: "<< leg_title<<std::endl;
			std::cout<<PrintHist(hist);

			hs->Add(hist);

			// BEFORE last sample: snapshot MC-only
			if (i + 1 == vecSamples.size() && !MCOnly) {
				MCOnly = (TH1D*)errorHist->Clone("MCOnly");
				MCOnly->SetDirectory(nullptr);
				std::cout << "MCOnly snapshot created\n";
				PrintHist(MCOnly);
			}
			// Build summed histogram
			if (errorHist) {
				errorHist->Add(hist);
			} else {
				errorHist = (TH1D*)hist->Clone("errorHist");
				errorHist->SetDirectory(nullptr);
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

		// Data sample
		store[Label.Data()][temp_var.GetAxisLabel().Data()][data.GetSampleName().Data()] =
		{ HistToCV(hdata), HistToErr(hdata) };


		std::cout<< leg_title<< "\n"<<PrintHist(hdata)<<std::endl;


		//errorHist style
		SetErrorStyle(errorHist);

		TString mc_leg_title = Form("Stat. Error | Bkg Sum: %.1lf",errorHist->Integral());
		leg->AddEntry(errorHist, mc_leg_title, "fl");

		//Print MCOnly & MC+ext as background 

		// MC only
		store[Label.Data()][temp_var.GetAxisLabel().Data()]["MCOnly"] =
		{ HistToCV(MCOnly), HistToErr(MCOnly) };

		// Total backgrounds
		store[Label.Data()][temp_var.GetAxisLabel().Data()]["Total Backgrounds"] =
		{ HistToCV(errorHist), HistToErr(errorHist) };


		WriteJSON( JSONfileName.Data(), store);

		ExportPNG_StackDataTwoSignal_wLabel({haxion0146, haxion084}, hs, hdata, errorHist, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) + "_CutTag"+ Precut.CountChar('&') , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());

	}//Next variable

//	std::ofstream outFile("output.txt");
//	std::string output_text = text_buffer.str();
//	outFile<<output_text;
//	outFile.close();

}

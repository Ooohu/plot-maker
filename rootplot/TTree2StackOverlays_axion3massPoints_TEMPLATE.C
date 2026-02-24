#include "utility/PlotHelper.h"

#include "utility/CutScanner.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "LoadSamples_Signals.h"

//#include "LoadSamples_Full.h"

#include "LoadSamples_Raw.h" //raw samples no 2s0t cut
#include "VarsList.C"

#include "CommonCut.C"

void TTree2StackOverlays_axion3massPoints_TEMPLATE(){//TEMPLATE key: Run1FHC
	//Configure class Samples: name, input file, tree name, cut
	//Samples directory /pnfs/uboone/persistent/users/klin/MCC9/ntuples

	std::vector< TString > tag={"ma0146"};
	//	std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};

	bool show_training = false;

	// PREPARE SAMPLES -----------------------------------------------------------------
	TString axiontag = tag[0];//"ma003";
	TString JSONfileName="JSON_output/"+axiontag+"_TEMPLATE.json";
	TString Label = "NuMIaxions_3mp2s0t_TEMPLATE"+axiontag+"_";

	Samples axion0093		= LoadAxions0093	(axiontag);
	Samples axion0146		= LoadAxions0146	(axiontag);
	Samples axion084		= LoadAxions084	(axiontag);

	Samples Onepi0		= LoadTEMPLATEOnepi0 (axiontag);
	Samples NueCC		= LoadTEMPLATENueCC (axiontag);
	Samples NumuCC		= LoadTEMPLATENumuCC (axiontag);
	Samples InCryoOther = LoadTEMPLATEInCryoOther (axiontag);

	Samples dirt		= LoadTEMPLATEDirt		(axiontag);

	Samples ext			= LoadETAG		(axiontag);

	Samples data		= LoaddTAGData		(axiontag);
	std::vector<Samples> vecSamples = { Onepi0, NueCC, NumuCC, InCryoOther, dirt, ext};


	// POT of Chice-----
	double PlotPOT = ILikeThisPOT( data );

	// PRECUT --------------------------------------------------------------------------------
	TString Precut = GetCut();

	// Configure class Var: varaibles, axis name, binnings  ----------------------------------
	std::vector< Vars> allVar = SetMultipleVars();


	// Start making histograms --------------------------------------------------------------------
	//--> Draw Stacked Histograms
	JSONStore store;

	for(Vars & temp_var : allVar){
		TLegend *leg = LoadLegend(); //Add legends
		TString leg_title ;

		//Prepare signals, overlay them;
		axion0093.AddDefinition(Precut);
		TH1D* haxion0093 = drawTH1D(axion0093, temp_var);
		haxion0093->Scale(axion0093.GetScale()*PlotPOT/data.GetPOT());
		haxion0093->SetFillColorAlpha( axion0093.GetCol(), 0.9); 
		haxion0093->SetLineWidth(3);
		haxion0093->SetLineColor(axion0093.GetCol());
		leg_title = axion0093.GetSampleName() + Form(" %.1lf",haxion0093->Integral());
		leg->AddEntry( haxion0093, leg_title, "fl");
	

		axion0146.AddDefinition(Precut);
		TH1D* haxion0146 = drawTH1D(axion0146, temp_var);
		haxion0146->Scale(axion0146.GetScale()*PlotPOT/data.GetPOT());
		haxion0146->SetFillColorAlpha( axion0146.GetCol(), 0.9); 
		haxion0146->SetLineWidth(3);
		haxion0146->SetLineColor(axion0146.GetCol());
		leg_title = axion0146.GetSampleName() + Form(" %.1lf",haxion0146->Integral());
		leg->AddEntry( haxion0146, leg_title, "fl");

		store[Label.Data()][temp_var.GetAxisLabel().Data()][axion0146.GetSampleName().Data()] = 
		{HistToCV(  haxion0146), HistToErr( haxion0146)};

		axion084.AddDefinition(Precut);
		TH1D* haxion084 = drawTH1D(axion084, temp_var);
		haxion084->Scale(axion084.GetScale()*PlotPOT/data.GetPOT());
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
		TH1D* FVMCOnly = nullptr;

		for (size_t i = 0; i < vecSamples.size(); ++i) {

			auto& sample = vecSamples[i];
			sample.AddDefinition(Precut);

			TH1D* hist = drawTH1D(sample, temp_var);
			//		std::cout<<"Total evts: "<<hist->Integral()<<std::endl;
			hist->Scale(sample.GetScale()*PlotPOT/sample.GetPOT());

			leg_title = sample.GetSampleName() + Form(" %.1lf",hist->Integral());
			leg->AddEntry(hist, leg_title ,"fl");

			std::cout<<"\nSummary: "<< leg_title<<std::endl;
			std::cout<<PrintHist(hist);

			hs->Add(hist);

			// BEFORE last two samples: snapshot FVMC-only
			if (i + 2 == vecSamples.size() && !MCOnly) {
				FVMCOnly = (TH1D*)errorHist->Clone("FVMCOnly");
				FVMCOnly->SetDirectory(nullptr);
				std::cout << "FVMCOnly snapshot created\n";
				PrintHist(FVMCOnly);
			}

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
		hdata->Scale(data.GetScale()*PlotPOT/data.GetPOT());
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
		if( temp_var.GetUseSys() ){//loads with systematic uncertainties
			std::cout<<"Draw systematic errors "<<std::endl;
			//Gonnd hard code the uncertainties here..
//			std::vector<double> fr = {0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1,0.1};
			std::vector<double> fr = temp_var.GetFracSys();

			AddFractionalSystematics( errorHist, fr, FVMCOnly);

			mc_leg_title = Form("Stat. & Sys. Uncertainties | Bkg Sum: %.1lf",errorHist->Integral());

		}
		leg->AddEntry(errorHist, mc_leg_title, "fl");

		//Print MCOnly & MC+ext as background 

		// MC only
		store[Label.Data()][temp_var.GetAxisLabel().Data()]["MCOnly"] =
		{ HistToCV(MCOnly), HistToErr(MCOnly) };

		// Total backgrounds
		store[Label.Data()][temp_var.GetAxisLabel().Data()]["Total Backgrounds"] =
		{ HistToCV(errorHist), HistToErr(errorHist) };


		WriteJSON( JSONfileName.Data(), store);

		ExportPNG_StackDataTwoSignal_wLabel({haxion0093, haxion0146, haxion084}, hs, hdata, errorHist, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) + "__"+ MakeSuffix(Precut) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());
		//ExportPNG_StackDataTwoSignal_wLabel({haxion0093, haxion0146, haxion084}, hs, hdata, errorHist, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) + "_CutTag"+ Precut.CountChar('&') , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());

	}//Next variable

}

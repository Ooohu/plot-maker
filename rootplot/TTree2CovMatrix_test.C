#include "utility/PlotHelper.h"
#include "TTree2StackOverlays_axion_common.C"
//#include "LoadSamples_newCatRun1_TrainingSample.h"
//#include "LoadSamples_newCatRun1.h"
#include "LoadSample_local.h"
#include "LoadStyles.h"

#include <iostream>
#include <fstream>
#include <sstream>

void TTree2CovMatrix_test(){
	//Configure class Samples: name, input file, tree name, cut
	//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

	std::vector< TString > tag={"ma003"};
	//	std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};
	std::stringstream text_buffer;
	
	Samples sampleCV = LoadCV("");
	Samples sampleVar1 = LoadVar1("");
	Samples sampleVar2 = LoadVar2("");

	// PREPARE SAMPLES -----------------------------------------------------------------
	double PlotPOT = 1E20;

	// PRECUT --------------------------------------------------------------------------------
	TString Label = "Testing";
	TString Precut = "(reco_asso_tracks == 0 && reco_asso_showers == 2)";
//	Precut +="&&( NuMIFHCRuns_ma003PionClassifier_mva > 0.5)";
//	Precut +="&&( reco_vertex_dist_to_SCB > 2)";

	// Configure class Var: varaibles, axis name, binnings  ----------------------------------
	std::vector< Vars> allVar = SetMultipleVars();

	// Start making histograms --------------------------------------------------------------------
	// It is systematics, so we need two sets of plots
	// 1. 1D histogram with lines of each universes.
	// 2. Comparison of the fractional difference curve.
	// 3. 2D histogram: Covariance matrix and correlation matrix

	//--> Draw Stacked Histograms
	std::vector< TString > sample_labels = {};
	for(Vars & temp_var : allVar){
		TLegend *leg = LoadSideLegend(); //Add legends
		TString leg_title ;

		//Prepare signals, overlay them;
		sampleCV.AddDefinition(Precut);
		TH1D* hsampleCV = drawTH1D(sampleCV, temp_var);
		hsampleCV->Scale(PlotPOT/sampleCV.GetPOT());
//		hsampleCV->SetFillColorAlpha( sampleCV.GetCol(), 0.9); 
//		hsampleCV->SetLineWidth(3);
//		hsampleCV->SetLineColor(sampleCV.GetCol());
		leg_title = sampleCV.GetSampleName();//+ Form(" %.1lf",hsampleCV->Integral());

		leg->AddEntry( hsampleCV, leg_title, "l");

			std::cout<<"\nSummary: "<< leg_title<<std::endl;
			std::cout<<PrintHist(hsampleCV);


		//Now backgrounds are stacked
		std::vector<Samples> vecSamples = { sampleVar1, sampleVar2};
		//	std::vector<Samples> vecSamples = {axion};
		std::vector< TH1D* > allhists={};
		THStack *hs = new THStack(RandomName(), "");// Create Stack
		for(auto &sample : vecSamples){
			sample.AddDefinition(Precut);

			TH1D* hist = drawTH1D(sample, temp_var);
			//		std::cout<<"Total evts: "<<hist->Integral()<<std::endl;
			hist->Scale(PlotPOT/sample.GetPOT());

			leg_title = sample.GetSampleName();// + Form(" %.1lf",hist->Integral());
			sample_labels.push_back(leg_title);
			leg->AddEntry(hist, leg_title ,"fl");
			std::cout<<"\nSummary: "<< leg_title<<std::endl;
			std::cout<<PrintHist(hist);

			allhists.push_back(hist);
			hs->Add(hist);




		}

//			ExportPNG_StackDataTwoSignal_wLabel({hsampleCV}, hs, hsampleCV, hsampleCV, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());
		draw_variations( hsampleCV, allhists, leg, MakeSafeName(Label+ "_Variations_" +temp_var.GetAxisLabel() ), temp_var.GetAxisLabel(), "Event Rate At Arbitrary POT", temp_var.GetIsLog());

		draw_FractionalDifference( hsampleCV, allhists, leg, MakeSafeName(Label+ "_FracDiff_" +temp_var.GetAxisLabel() ), temp_var.GetAxisLabel(), "%Diff respected to CV");

		draw_CovMatrix( hsampleCV, allhists,  MakeSafeName(Label+"_CovMatrix_"+temp_var.GetAxisLabel()), sample_labels, "Covariance Matrix");

//		draw_2DHist(sampleCV, vecSamples, temp_var, Label );

	}//Next variable

	std::ofstream outFile("output.txt");
	std::string output_text = text_buffer.str();
	outFile<<output_text;
	outFile.close();

}

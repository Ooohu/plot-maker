#include "utility/PlotHelper.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "LoadSamples_sys.h"
#include "LoadStyles.h"
//#include "VarsList_BDT.C"
#include "VarsList_R3.C"

#include "CommonCut.C"


void TTree2CovMatrix_sysR3bPre16880(){
	//Configure class Samples: name, input file, tree name, cut
	//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

	TString Label = "R3sys";

	std::vector< TString > tag={"ma0146"};
	//	std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};
//	std::stringstream text_buffer;
	
	Samples sampleCV						= LoadR3b_CVRHC						(tag[0]);
	Samples sampleLYDown					= LoadR3b_DetVarLYDown					(tag[0]);
	Samples sampleAlternativeSCMap			= LoadR3b_DetVarAlternativeSCMap			(tag[0]);
	Samples sampleAlternativeRecombination	= LoadR3b_DetVarAlternativeRecombination (tag[0]);
	Samples sampleLYRayleigh				= LoadR3b_DetVarLYRayleigh				(tag[0]);
	Samples sampleWireModX					= LoadR3b_DetVarWireModX					(tag[0]);
//	Samples sampleWireModThetaXZ			= LoadR3b_DetVarWireModThetaXZ			(tag[0]);
	Samples sampleWireModThetaYZ			= LoadR3b_DetVarWireModThetaYZ			(tag[0]);
	Samples sampleWireModYZ				    = LoadR3b_DetVarWireModYZ				(tag[0]);
	std::vector<Samples> vecSamples = { sampleLYDown, sampleAlternativeSCMap, sampleAlternativeRecombination, sampleLYRayleigh, sampleWireModX, sampleWireModThetaYZ, sampleWireModYZ };
//	std::vector<Samples> vecSamples = { sampleLYDown, sampleAlternativeSCMap, sampleAlternativeRecombination, sampleLYRayleigh, sampleWireModX, sampleWireModThetaXZ, sampleWireModThetaYZ, sampleWireModYZ };




	// PREPARE SAMPLES -----------------------------------------------------------------
//	double PlotPOT = 2.37E20;//R1
	double PlotPOT = 2E21;

	// PRECUT --------------------------------------------------------------------------------
//	TString Precut = "(reco_asso_tracks == 0 && reco_asso_showers == 2)";
//	Precut +="&&( reco_vertex_dist_to_SCB > 2)";
	TString Precut = GetCut();

	// Configure class Var: varaibles, axis name, binnings  ----------------------------------
	std::vector< Vars> allVar = SetMultipleVars();

	// Start making histograms --------------------------------------------------------------------
	// It is systematics, so we need two sets of plots
	// 1. 1D histogram with lines of each universes.
	// 2. Comparison of the fractional difference curve.
	// 3. 2D histogram: Covariance matrix and correlation matrix

	//--> Draw Stacked Histograms
	for(Vars & temp_var : allVar){
		std::vector< TString > sample_labels = {};
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
		std::vector< TH1D* > allhists={};
		THStack *hs = new THStack(RandomName(), "");// Create Stack

		int colorIndex = 0; // We need color in the legend
		int markerIndexOffset = 22;
		for(auto &sample : vecSamples){
			sample.AddDefinition(Precut);

			TH1D* hist = drawTH1D(sample, temp_var);
			Color_t  t_c = sampleColor(colorIndex++);//this_color
			hist->SetLineColorAlpha(t_c, 0.7);
			hist->SetMarkerColorAlpha( t_c, 0.7);
			hist->SetMarkerStyle(colorIndex + markerIndexOffset);
			//		std::cout<<"Total evts: "<<hist->Integral()<<std::endl;
			hist->Scale(PlotPOT/sample.GetPOT());

			leg_title = sample.GetSampleName();// + Form(" %.1lf",hist->Integral());
			sample_labels.push_back(leg_title);
			leg->AddEntry(hist, leg_title ,"flp");
			std::cout<<"\nSummary: "<< leg_title<<std::endl;
			std::cout<<PrintHist(hist);

			allhists.push_back(hist);
			hs->Add(hist);


		}

		//Adjust legend text size
		leg->SetTextSize(0.05);

//			ExportPNG_StackDataTwoSignal_wLabel({hsampleCV}, hs, hsampleCV, hsampleCV, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());
		draw_variations( hsampleCV, allhists, leg, MakeSafeName(Label+ "_Variations_" +temp_var.GetAxisLabel() ), temp_var.GetAxisLabel(), "Event Rate at 2E21 POT", temp_var.GetIsLog());

		draw_FractionalDifference( hsampleCV, allhists, leg, MakeSafeName(Label+ "_FracDiff_" +temp_var.GetAxisLabel() ), temp_var.GetAxisLabel(), "%Diff respected to CV");

		draw_CovMatrix( hsampleCV, allhists,  MakeSafeName(Label+"_CovMatrix_"+temp_var.GetAxisLabel()), sample_labels, "Covariance Matrix");

//		draw_2DHist(sampleCV, vecSamples, temp_var, Label );

	}//Next variable

//	std::ofstream outFile("output_sysR1.txt");
//	std::string output_text = text_buffer.str();
//	outFile<<output_text;
//	outFile.close();

}

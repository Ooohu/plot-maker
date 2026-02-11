#include "utility/PlotHelper.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "LoadSamples_sys.h"
#include "VarsList.C"

#include "CommonCut.C"

#include <TH1D.h>


void TTree2Multisim_sysR1_v2(){
    //Configure class Samples: name, input file, tree name, cut
    //DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

    TString Label = "R1FHCsys_Multisim";
    std::vector< TString > tag={"ma0146"};
    //    std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};
//    std::stringstream text_buffer;

    Samples sampleCV    = LoadR1_CVFHC    (tag[0]);



    // PREPARE SAMPLES -----------------------------------------------------------------
//    double PlotPOT = 2.37E20;//R1
    double PlotPOT = 2E21;

    // PRECUT --------------------------------------------------------------------------------
    TString Precut = GetCut();

    // Configure class Var: varaibles, axis name, binnings  ----------------------------------
    std::vector< Vars> allVar = SetMultipleVars();

    int NumUNIGenie = 6;//600
    int NumUNIReInt = 2;//1000
    int NumUNIFlux = 0;//600 -- missing flux variations;

//SO THIS IS GONNA BE DIFFERNT, only one file is needed, 
// CV holds weight_cv*weight_spline*ppfx_cv_UBPPFXCV OR weightSplineTimesTune
// Varaitions holds weight_cv*weight_spline*ppfx_ms_UBPPFX[i]

    //--> Draw Stacked Histograms
	ROOT::EnableImplicitMT();  // multithreading
    for(Vars & temp_var : allVar){


		if(NumUNIGenie>0){//GenieVariatinos
			auto hists = makeHists_RDF(
					sampleCV, temp_var, 
					"weightSplineTimesTune", 
					"weightSplineTimesTune*weightsGenie",
					NumUNIGenie);//CV weight & universe weights (added [k] iteration later on

			// --- Precompute scale factor ---
			double scale = sampleCV.GetScale() * PlotPOT / sampleCV.GetPOT();

			// --- Style and scale CV ---
			TH1D* cv = hists.cv.GetPtr();
			MakeBeautiHistCV(cv);
			cv->Scale(scale);
			std::cout << sampleCV.GetSampleName() << " CV integral: " << cv->Integral() << std::endl;

			// --- Style and scale universes ---
			int lightColor = TColor::GetColorTransparent(kAzure+7, 0.6);
			std::vector<TH1D*> universes;
			for (auto& u : hists.univ) {
				TH1D* hu = u.GetPtr();
				MakeBeautiHistVariations(hu, lightColor);
				hu->Scale(scale);
				universes.push_back(hu);//Fill vector<TH1D*>
			}

			// --- Legend ---
			TLegend* leg = LoadLegend();
			leg->SetTextSize(0.15);
			leg->AddEntry(cv, sampleCV.GetSampleName(), "fl");
			leg->AddEntry(hists.univ[0].GetPtr(), "#splitline{Variations:}{Genie XSec.}", "fl");

			// --- Draw everything ---
			draw_variations_v2(
					cv, universes, leg,
					MakeSafeName(Label + "_GenieVariations_" + temp_var.GetAxisLabel()) + "_CutTag" + Precut.CountChar('&'),
					temp_var.GetAxisLabel(),
					Form("MC Backgrounds in %gPOT", PlotPOT),
					temp_var.GetIsLog()
					);

			TH2D* hCov = BuildCovarianceMatrix( cv, universes);

			PrintHist(cv);
			PrintSysErrFromCov( cv, hCov);

		}


		if(NumUNIReInt>0){//ReIntVariatinos
			auto hists = makeHists_RDF(
					sampleCV, temp_var, 
					"weightSplineTimesTune", 
					"weightSplineTimesTune*weightsReint",
					NumUNIReInt);//CV weight & universe weights (added [k] iteration later on

			// --- Precompute scale factor ---
			double scale = sampleCV.GetScale() * PlotPOT / sampleCV.GetPOT();

			// --- Style and scale CV ---
			TH1D* cv = hists.cv.GetPtr();
			MakeBeautiHistCV(cv);
			cv->Scale(scale);
			std::cout << sampleCV.GetSampleName() << " CV integral: " << cv->Integral() << std::endl;

			// --- Style and scale universes ---
			int lightColor = TColor::GetColorTransparent(kTeal-6, 0.6);
			std::vector<TH1D*> universes;
			for (auto& u : hists.univ) {
				TH1D* hu = u.GetPtr();
				MakeBeautiHistVariations(hu, lightColor);
				hu->Scale(scale);
				universes.push_back(hu);//Fill vector<TH1D*>
			}


			// --- Legend ---
			TLegend* leg = LoadLegend();
			leg->SetTextSize(0.15);
			leg->AddEntry(cv, sampleCV.GetSampleName(), "fl");
			leg->AddEntry(hists.univ[0].GetPtr(), "#splitline{Variations:}{ReInt XSec.}", "fl");

			// --- Draw everything ---
			draw_variations_v2(
					cv, universes, leg,
					MakeSafeName(Label + "_ReIntVariations_" + temp_var.GetAxisLabel()) + "_CutTag" + Precut.CountChar('&'),
					temp_var.GetAxisLabel(),
					Form("MC Backgrounds in %gPOT", PlotPOT),
					temp_var.GetIsLog()
					);

			TH2D* hCov = BuildCovarianceMatrix( cv, universes);

			PrintHist(cv);
			PrintSysErrFromCov( cv, hCov);
		}


    }//Next variable
}

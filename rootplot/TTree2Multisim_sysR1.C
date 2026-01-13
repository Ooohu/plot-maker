#include "utility/PlotHelper.h"

#include <iostream>
#include <fstream>
#include <sstream>

#include "LoadSamples_sysR1.h"
#include "LoadStyles.h"
#include "VarsList_BDT.C"


void TTree2Multisim_sysR1(){
    //Configure class Samples: name, input file, tree name, cut
    //DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

    std::vector< TString > tag={"ma084"};
    //    std::vector< TString > tag={ "ma003", "ma0093", "ma011", "ma0146", "ma03", "ma04", "ma052", "ma068", "ma084"};
//    std::stringstream text_buffer;

    Samples sampleCV    = LoadR1CV    (tag[0]);



    // PREPARE SAMPLES -----------------------------------------------------------------
    double PlotPOT = 2.37E20;//R1
//    double PlotPOT = 2E21;

    // PRECUT --------------------------------------------------------------------------------
    TString Label = "R1sys_Mult_testing";
    TString Precut = "(reco_asso_tracks == 0 && reco_asso_showers == 2)";
//    Precut +="&&( NuMIFHCRuns_ma003PionClassifier_mva > 0.5)";
    Precut +="&&( reco_vertex_dist_to_SCB > 2)";
//    Precut +="&&( (reco_shower_energy_max[0]+reco_shower_energy_max[1])/(sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1]))))<6.8)";

    // Configure class Var: varaibles, axis name, binnings  ----------------------------------
    std::vector< Vars> allVar = SetMultipleVars();

//SO THIS IS GONNA BE DIFFERNT, only one file is needed, 
// CV holds weight_cv*weight_spline*ppfx_cv_UBPPFXCV OR weightSplineTimesTune
// Varaitions holds weight_cv*weight_spline*ppfx_ms_UBPPFX[i]

    //--> Draw Stacked Histograms
    for(Vars & temp_var : allVar){
        std::vector< TString > sample_labels = {};
        TLegend *leg = LoadSideLegend(); //Add legends
        TString leg_title ;

        //Prepare signals, overlay them;
        sampleCV.AddDefinition(Precut);
        TH1D* hsampleCV = drawTH1D(sampleCV, temp_var);
        hsampleCV->Scale(PlotPOT/sampleCV.GetPOT());
//        hsampleCV->SetFillColorAlpha( sampleCV.GetCol(), 0.9); 
//        hsampleCV->SetLineWidth(3);
//        hsampleCV->SetLineColor(sampleCV.GetCol());
        leg_title = sampleCV.GetSampleName();//+ Form(" %.1lf",hsampleCV->Integral());
        
        leg->AddEntry( hsampleCV, leg_title, "l");

        std::cout<<"\nSummary: "<< leg_title<<std::endl;
        std::cout<<PrintHist(hsampleCV);


        //Now backgrounds are stacked
//        std::vector<Samples> vecSamples = { sampleLYDown, sampleAlternativeSCMap, sampleAlternativeRecombination, sampleLYRayleigh, sampleWireModX, sampleWireModThetaXZ, sampleWireModThetaYZ, sampleWireModYZ };
        std::vector< TH1D* > hists_GENIE={};

        int NumUNI = 600;//600; //Multisim of 600 GENIE Interactions

        for(int NthU = 0; NthU < NumUNI; ++NthU){//one weight gives one hist;

            TString Weight = MakeSafeWgtName( Form("weightSplineTimesTune*weightsGenie[%d]/1000", NthU) );//draw different universes
            //TString Weight = Form("weightsGenie[%d]/1000", NthU);//draw different universes

			int grayBlue = TColor::GetColorTransparent(kAzure+7, 0.3);
            TH1D* hist = drawTH1D_w_Weight(sampleCV, temp_var, Weight, grayBlue);
            //std::cout<<"Total evts: "<<hist->Integral()<<std::endl;
            hist->Scale(PlotPOT/sampleCV.GetPOT());

            if(NthU < 1){
                leg_title = "#splitline{Variations:}{Genie XSec.}";// + Form(" %.1lf",hist->Integral());
                sample_labels.push_back(leg_title);
                leg->AddEntry(hist, leg_title ,"fl");
            }

            hists_GENIE.push_back(hist);

			if (NthU % 10 == 0) {  // update every 10 loops to reduce flicker
				std::cout << "\rProcessing GENIE universe " << NthU+1 << " / "<<NumUNI << std::flush;
			}
        }
		std::cout<<std::endl;

		//for Re-interactions
        std::vector< TH1D* > hists_ReInt={};
		
        NumUNI = 1000;//1000; //Multisim of 1000 Re-interactions

        for(int NthU = 0; NthU < NumUNI; ++NthU){//one weight gives one hist;

            TString Weight = MakeSafeWgtName( Form("weightSplineTimesTune*weightsReint[%d]/1000", NthU) );//draw different universes
			int lightRed = TColor::GetColorTransparent(kRed-7, 0.3);
            TH1D* hist = drawTH1D_w_Weight(sampleCV, temp_var, Weight, lightRed);
            //std::cout<<"Total evts: "<<hist->Integral()<<std::endl;
            hist->Scale(PlotPOT/sampleCV.GetPOT());

            if(NthU < 1){
                leg_title = "#splitline{Variations:}{G4 Re-interactions}";// + Form(" %.1lf",hist->Integral());
                sample_labels.push_back(leg_title);
                leg->AddEntry(hist, leg_title ,"fl");
            }

            hists_ReInt.push_back(hist);
			if (NthU % 10 == 0) {  // update every 10 loops to reduce flicker
				std::cout << "\rProcessing Re-interaction universe " << NthU+1 << " / "<<NumUNI << std::flush;
			}
        }
		std::cout<<std::endl;


        //Adjust legend text size
        leg->SetTextSize(0.09);

		std::vector<TH1D*> allhists;

		allhists.insert(allhists.end(), hists_GENIE.begin(), hists_GENIE.end());
		allhists.insert(allhists.end(), hists_ReInt.begin(), hists_ReInt.end());

		PrintMultiSimVariation(hsampleCV, hists_GENIE, "GENIE Vars");
		PrintMultiSimVariation(hsampleCV, hists_ReInt, "ReInt Vars");

        draw_variations( hsampleCV, allhists, leg, MakeSafeName(Label+ "_Variations_" +temp_var.GetAxisLabel() ), temp_var.GetAxisLabel(), "Event Rate at 2E21 POT", temp_var.GetIsLog());

//        draw_FractionalDifference( hsampleCV, allhists, leg, MakeSafeName(Label+ "_FracDiff_" +temp_var.GetAxisLabel() ), temp_var.GetAxisLabel(), "%Diff respected to CV");



    }//Next variable

//    std::ofstream outFile("output_sysR1.txt");
//    std::string output_text = text_buffer.str();
//    outFile<<output_text;
//    outFile.close();

}

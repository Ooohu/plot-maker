#ifndef CUTSCANNER_H
#define CUTSCANNER_H

#include "ConfigureSamples.h"
#include "ConfigureVars.h"

void BDTSingleCutScan( Samples sig, std::vector< Samples > bkgs, std::vector< Vars > &vars){

	if(vars.size()> 3){
		std::cout<<" # of vars "<<vars.size()<<std::endl;
		std::cout<<" Not three BDT Settings. Quit. "<<std::endl;
		return;
	}
	float best_significance = -1;
	float best_cutA, best_cutB, best_cutC;
	double Resol = 0.01;
	double startCut = 0;

	TString SigDefOrg = sig.GetDefinition();
	std::vector< TString > BkgDefOrgs;
	for( auto tmp_sample : bkgs){
		BkgDefOrgs.push_back(tmp_sample.GetDefinition());
	}

	TH1D* hist_origin = drawTH1D(sig, vars[0]);
	double s_total = hist_origin->Integral();

	// Background
	double b_total = 0;
	for (size_t index = 0; index < BkgDefOrgs.size(); index ++){
		TH1D* bkgHist = drawTH1D( bkgs[index], vars[0]);
		b_total += bkgHist->Integral();
	}

	for (float cutA = startCut; cutA < 1 - Resol/10; cutA += Resol) {

		// Define the selection cut as a string
		TString cut = Form("(%s < %f)"
				, vars[0].GetVarName().Data(), cutA);

		// Quickly get number of entries passing the cut
		//Get signal#

		sig.SetDefinition( "(" + SigDefOrg + "&&" + cut + ")");
		TH1D* hist = drawTH1D(sig, vars[0]);
		double s_pass = hist->Integral();

		// Background
		double b_pass = 0;
		for (size_t index = 0; index < BkgDefOrgs.size(); index ++){
			bkgs[index].SetDefinition( "(" +BkgDefOrgs[index] +"&&" + cut + ")"); 
			TH1D* bkgHist = drawTH1D( bkgs[index], vars[0]);
			b_pass += bkgHist->Integral();
		}


		// Compute significance
		float significance = 0;
		if (b_pass > 0) {
			significance = s_pass / sqrt(b_pass);
			//significance = s_pass/(s_pass+b_pass)*s_pass / sqrt(b_pass);

			//Punzi Figure of Merit (FOM) 
//			significance=(s_pass/s_total)/(3/2+sqrt(b_pass));
		}


		std::cout<<"Cut ("<<cutA<<") #sig eff:"<< s_pass/s_total<<" , #bkg  "<<b_pass<< " eff"<<b_pass/b_total<<" measurement: "<<significance;
		if (significance > best_significance) {
			best_significance = significance;
			best_cutA = cutA;
			std::cout<<"<- ٩(^ᗜ^ )و ´ Best! ";
		}
		std::cout<<std::endl;
	}

	std::cout << "Best cuts found:" << std::endl;
	std::cout << vars[0].GetVarName().Data()<<" > " << best_cutA << std::endl;
	std::cout << "Max measurement = " << best_significance << std::endl;

}



void BDTCutScan( Samples sig, std::vector< Samples > bkgs, std::vector< Vars > &vars){

	if(vars.size()!= 3){
		std::cout<<" # of vars "<<vars.size()<<std::endl;
		std::cout<<" Not three BDT Settings. Quit. "<<std::endl;
		return;
	}
	float best_significance = -1;
	float best_cutA, best_cutB, best_cutC;
	double Resol = 0.01;
	double startCut = 0.94;

	TString SigDefOrg = sig.GetDefinition();
	std::vector< TString > BkgDefOrgs;
	for( auto tmp_sample : bkgs){
		BkgDefOrgs.push_back(tmp_sample.GetDefinition());
	}

	for (float cutA = startCut; cutA < 1 - Resol/10; cutA += Resol) {
		for (float cutB = startCut; cutB < 1 - Resol/10; cutB += Resol) {
			for (float cutC = startCut; cutC < 1 - Resol/10; cutC += Resol) {

				// Define the selection cut as a string
				TString cut = Form("(%s > %f && %s > %f && %s > %f)"
				, vars[0].GetVarName().Data(), cutA
				, vars[1].GetVarName().Data(), cutB
				, vars[2].GetVarName().Data(), cutC);

				// Quickly get number of entries passing the cut
				//Get signal#
				
				sig.SetDefinition( "(" + SigDefOrg + "&&" + cut + ")");
				TH1D* hist = drawTH1D(sig, vars[0]);
				double s_pass = hist->Integral();

                // Background
                double b_pass = 0;
                for (size_t index = 0; index < BkgDefOrgs.size(); index ++){
					bkgs[index].SetDefinition( "(" +BkgDefOrgs[index] +"&&" + cut + ")"); 
					TH1D* bkgHist = drawTH1D( bkgs[index], vars[0]);
					b_pass += bkgHist->Integral();
                }


				// Compute significance
				float significance = 0;
				if (b_pass > 0) {
					significance = s_pass / sqrt(b_pass);
					//significance = s_pass/(s_pass+b_pass)*s_pass / sqrt(b_pass);
				}


				std::cout<<"Cut ("<<cutA<<","<<cutB<<","<<cutC<<") #sig:"<< s_pass<<" , sig: "<<significance;
				if (significance > best_significance) {
					best_significance = significance;
					best_cutA = cutA;
					best_cutB = cutB;
					best_cutC = cutC;
					std::cout<<"<- ٩(^ᗜ^ )و ´ Best! ";
				}
				std::cout<<std::endl;
			}
		}
	}

	std::cout << "Best cuts found:" << std::endl;
	std::cout << vars[0].GetVarName().Data()<<" > " << best_cutA << std::endl;
	std::cout << vars[1].GetVarName().Data()<<" > " << best_cutB << std::endl;
	std::cout << vars[2].GetVarName().Data()<<" > " << best_cutC << std::endl;
	std::cout << "Max significance S/sqrt(B) = " << best_significance << std::endl;

}

void BDTCutScanTwoDirections( Samples sig, std::vector< Samples > bkgs, std::vector< Vars > &vars){

	if(vars.size()!= 3){
		std::cout<<" # of vars "<<vars.size()<<std::endl;
		std::cout<<" Not three BDT Settings. Quit. "<<std::endl;
		return;
	}
	float best_significance = -1;
	float best_cutA, best_cutB, best_cutC;
	int best_dirA, best_dirB, best_dirC;
	double Resol = 0.1;
	double startCut = 0;

	TString SigDefOrg = sig.GetDefinition();
	std::vector< TString > BkgDefOrgs;
	for( auto tmp_sample : bkgs){
		BkgDefOrgs.push_back(tmp_sample.GetDefinition());
	}

	for (float cutA = startCut; cutA < 1 - Resol/10; cutA += Resol) {
		for (float cutB = startCut; cutB < 1 - Resol/10; cutB += Resol) {
			for (float cutC = startCut; cutC < 1 - Resol/10; cutC += Resol) {
			for (int dirA = 0; dirA <= 1; dirA++) {   // 0: <, 1: >
			for (int dirB = 0; dirB <= 1; dirB++) {
			for (int dirC = 0; dirC <= 1; dirC++) {

				// Define the selection cut as a string
				TString cut = Form("(%s %s %f && %s %s %f && %s %s %f)"
				, vars[0].GetVarName().Data(), (dirA)? ">":"<",cutA
				, vars[1].GetVarName().Data(), (dirB)? ">":"<",cutB
				, vars[2].GetVarName().Data(), (dirC)? ">":"<",cutC);

				// Quickly get number of entries passing the cut
				//Get signal#
				
				sig.SetDefinition( "(" + SigDefOrg + "&&" + cut + ")");
				TH1D* hist = drawTH1D(sig, vars[0]);
				double s_pass = hist->Integral();

                // Background
                double b_pass = 0;
                for (size_t index = 0; index < BkgDefOrgs.size(); index ++){
					bkgs[index].SetDefinition( "(" +BkgDefOrgs[index] +"&&" + cut + ")"); 
					TH1D* bkgHist = drawTH1D( bkgs[index], vars[0]);
					b_pass += bkgHist->Integral();
                }


				// Compute significance
				float significance = 0;
				if (b_pass > 0) {
					significance = s_pass / sqrt(b_pass);
					//significance = s_pass/(s_pass+b_pass)*s_pass / sqrt(b_pass);
				}


				std::cout<<"Cut ("<<cutA<<","<<cutB<<","<<cutC<<")";
				std::cout<<" Dir ("<<dirA<<","<<dirB<<","<<dirC<<")";
				std::cout<<" #sig:"<< s_pass<<" , sig: "<<significance;
				if (significance > best_significance) {
					best_significance = significance;
					best_cutA = cutA;
					best_cutB = cutB;
					best_cutC = cutC;
					best_dirA = dirA;
					best_dirB = dirB;
					best_dirC = dirC;
					std::cout<<"<- ٩(^ᗜ^ )و ´ Best! ";
				}
				std::cout<<std::endl;
			}
		}
	}
	}
	}
	}

	std::cout << "Best cuts found:" << std::endl;
	std::cout << vars[0].GetVarName().Data()<<(best_dirA? ">":"<")<< best_cutA << std::endl;
	std::cout << vars[1].GetVarName().Data()<<(best_dirB? ">":"<")<< best_cutB << std::endl;
	std::cout << vars[2].GetVarName().Data()<<(best_dirC? ">":"<")<< best_cutC << std::endl;
	std::cout << "Max significance S/sqrt(B) = " << best_significance << std::endl;

}


#endif

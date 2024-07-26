#include "utility/PlotHelper.h"
#include "TTree2StackOverlays_axion_common.C"
#include "LoadSamples.h"

#include <iostream>
#include <fstream>
#include <sstream>

void TTree2StackOverlays_run1axion_ma003(){
	//Configure class Samples: name, input file, tree name, cut
	//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples
	
	//scalings_run1 = { "nu":1./2.35e21, "dirt":1.0*0.75/1.55e21, "beamoff": 0.98*(6230439.0/9186361.390000)}
	//scalings_run3 = { "nu":1./(1.993661e21), "dirt":1.0*0.35/1.020e21, "beamoff": 0.98*(10714868.0/34147459.925000)}

// PREPARE SAMPLES -----------------------------------------------------------------
	TString axiontag = "ma003";

	Samples axion		= LoadAxions	(axiontag);
	Samples nc1pi0		= LoadNC1pi0	(axiontag);
	Samples nc0pi0		= LoadNC0pi0	(axiontag);
	Samples ccnue		= LoadCCnue		(axiontag);
	Samples ccnumu1pi	= LoadCCnumu1pi	(axiontag);
	Samples ccnumu0pi	= LoadCCnumu0pi	(axiontag);
	Samples other		= LoadOthers	(axiontag);
	Samples dirt		= LoadDirt		(axiontag);
	Samples data		= LoadData		(axiontag);
	Samples ext			= LoadEXT		(axiontag);

	double PlotPOT = data.GetPOT();

// PRECUT --------------------------------------------------------------------------------
	TString Label = "AxionV2"+axiontag+"_2s0t";
	TString Precut = "(reco_asso_tracks == 0 && reco_asso_showers == 2)";
	Precut += "&&(reco_vertex_x > 5 && reco_vertex_x < 251 && reco_vertex_y > -110 && reco_vertex_y < 110 && reco_vertex_z > 20 && reco_vertex_z< 986)";//FV Cut


// Configure class Var: varaibles, axis name, binnings  ----------------------------------
	std::vector< Vars> allVar = SetMultipleVars();

	
	std::stringstream text_buffer;
// Start making histograms --------------------------------------------------------------------
//--> Draw Stacked Histograms
	for(Vars & temp_var : allVar){
		//Create THStack
		THStack *hs = new THStack(RandomName(), "");
		//Add legends
		TLegend *leg = new TLegend(0.05,0.01,0.95,0.95);
		leg->SetFillStyle(0);
		leg->SetLineWidth(0);
		leg->SetNColumns(3);

		std::vector<Samples> vecSamples = {axion, nc1pi0, nc0pi0, ccnue, ccnumu1pi, ccnumu0pi, other, dirt, ext};
		//	std::vector<Samples> vecSamples = {axion};
		TH1D* errorHist = 0;

		for(auto &sample : vecSamples){
			sample.AddDefinition(Precut);

			TH1D* hist = drawTH1D(sample, temp_var);
			//		std::cout<<"Total evts: "<<hist->Integral()<<std::endl;
			hist->Scale(PlotPOT/sample.GetPOT());

			TString leg_title = sample.GetSampleName() + Form(" %.1lf",hist->Integral());
			leg->AddEntry(hist, leg_title ,"fl");
			std::cout<<"\nSummary: "<< leg_title<<std::endl;
			std::cout<<PrintHist(hist);
			

			hs->Add(hist);

			if(errorHist){
				errorHist->Add(hist);
			} else{
				errorHist = (TH1D*) hist->Clone();
				text_buffer<<"\nSummary: "<< leg_title<<std::endl;
				text_buffer << PrintHist(hist);
			}
		}

		//--> Draw histogram: data overlay
		data.AddDefinition(Precut);
		TH1D* hdata = drawTH1D(data, temp_var);
		hdata->Scale(PlotPOT/data.GetPOT());
		hdata->SetMarkerSize(1);//data
		hdata->SetMarkerStyle(20);//data
		TString leg_title = data.GetSampleName() + Form(" %.0lf",hdata->Integral());
		leg->AddEntry( hdata, leg_title, "fl");

		text_buffer<<"\nSummary: "<< leg_title<<std::endl;
		text_buffer<< PrintHist(hdata);


		//errorHist style
		errorHist->SetMarkerSize(0);
		errorHist->SetFillStyle(3454);
		errorHist->SetLineWidth(2);
		errorHist->SetLineColor(kBlack);
		errorHist->SetFillColor(kBlack);
		TString mc_leg_title = Form("Stat. Error | Total Pred.: %.1lf",errorHist->Integral());
		leg->AddEntry(errorHist, mc_leg_title, "fl");
		text_buffer<<"\nSummary total MC:"<<std::endl;
		text_buffer<< PrintHist(errorHist);

		std::ofstream outFile("output.txt");
		std::string output_text = text_buffer.str();

		outFile<<output_text;
		outFile.close();

		ExportPNG_StackData_wLabel(hs, hdata, errorHist, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());
	}

}

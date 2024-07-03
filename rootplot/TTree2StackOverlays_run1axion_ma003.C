#include "utility/PlotHelper.h"
#include "TTree2StackOverlays_axion_common.C"

void TTree2StackOverlays_run1axion_ma003(){
	//Configure class Samples: name, input file, tree name, cut
	//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples
	
	//scalings_run1 = { "nu":1./2.35e21, "dirt":1.0*0.75/1.55e21, "beamoff": 0.98*(6230439.0/9186361.390000)}
	//scalings_run3 = { "nu":1./(1.993661e21), "dirt":1.0*0.35/1.020e21, "beamoff": 0.98*(10714868.0/34147459.925000)}

	TString tag = "ma003";
	Samples axion("Axion"+tag,"/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_"+tag+"_v1_zlt40m.root","singlephotonana/vertex_tree","Entry$%2==0");
	axion.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_Axion"+tag+"_app.root","Axion"+tag+"_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	axion.SetScale(100*2.0/58560);
	axion.SetPlotStyle(kYellow-3, 1001);
	axion.SetPOT(2e21);

//Break it down
//	Samples AllMC("MCInCryo", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","1");
//	AllMC.SetPlotStyle(kRed-3,1001);
//	AllMC.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
//	AllMC.SetPOT(2.35e21);

	//(MCFlux_NuPosX > (0.0-1.55) && MCFlux_NuPosX < (256.35-1.55) && MCFlux_NuPosY > (-116.5+0.97) && MCFlux_NuPosY < (116.5+0.97) && MCFlux_NuPosZ > 0.0+0.1 && MCFlux_NuPosZ < 1036.8+0.1) && reco_vertex_size==1
	Samples nc1pi0("NC1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==1 &&Entry$%2==0");
	nc1pi0.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NCPi0_app.root","NCPi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	nc1pi0.SetPlotStyle(kRed-3,1001);
	nc1pi0.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	nc1pi0.SetPOT(2.35e21);
	nc1pi0.SetScale(2);//Have used half for training;

	Samples nc0pi0("NC0#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==0");
	nc0pi0.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NC0Pi0_app.root","NC0Pi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	nc0pi0.SetPlotStyle(kBlue-3,1001);
	nc0pi0.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	nc0pi0.SetPOT(2.35e21);

	Samples ccnue("CC#nu_{e}/#bar{#nu_{e}}Intrinsic", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&fabs(mctruth_nu_pdg)==12");
	ccnue.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NueOverlays_app.root","NueOverlays_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	ccnue.SetPlotStyle(kGreen-8,1001);
	ccnue.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnue.SetPOT(2.35e21);


	Samples ccnumu1pi("CC#nu_{#mu}1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==1");
	ccnumu1pi.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_CC1Pi0_app.root","CC1Pi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	ccnumu1pi.SetPlotStyle(kRed-6,1001);
	ccnumu1pi.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnumu1pi.SetPOT(2.35e21);


	Samples ccnumu0pi("CC#nu_{#mu}0#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==0");
	ccnumu0pi.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_CC0Pi0_app.root","CC0Pi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	ccnumu0pi.SetPlotStyle(kBlue-6,1001);
	ccnumu0pi.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnumu0pi.SetPOT(2.35e21);



	TString othercuts = "!(mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==1)"; //nc1pi0
	othercuts+= "&&!(mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==0)";//nc0pi
	othercuts+= "&&!(mctruth_cc_or_nc==0&&fabs(mctruth_nu_pdg)==12)";//ccnuenuebar
	othercuts+= "&&!(mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==1)";//ccnumu1pi
	othercuts+= "&&!(mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==0)";//ccnumu0pi

	Samples other("InCryoOthers", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree",othercuts);
	other.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NuMIOtherExtra_app.root","NuMIOtherExtra_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	other.SetPlotStyle(kGreen-2,1001);
	other.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	other.SetPOT(2.35e21);




	Samples dirt("Dirt (OutsideCryo)  x.7","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1dirt_luis_goodweight.root","vertex_tree","1");
	dirt.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_Dirt_app.root","Dirt_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	dirt.SetPlotStyle(kOrange-7, 1001);
	dirt.SetWeight("ppfx_cv_good*spline_tune_good");
	dirt.SetPOT(1.55e21);
	dirt.SetScale(0.7);

	//Intent to have no data
	Samples data("Data NuMI Run1 FHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1data_luis_full.root","singlephotonana/vertex_tree","(run_number<6748)||(run_number==6748 && subrun_number<22)");
	data.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NuMIDataCANTTAKECUTS_app.root","NuMIDataCANTTAKECUTS_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	data.SetPOT(2.37e20);
//	data.SetPOT(2.1e21);
	double PlotPOT = data.GetPOT();

	Samples ext("Run1 EXT x.98","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1EXT_luis_filtered.root","singlephotonana/vertex_tree","1");
	ext.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NuMIextRun1_app.root","NuMIextRun1_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(1.846e19*513630.025/426046.0);
	ext.SetScale(0.98);


	TString Label = "AxionV2"+tag+"_2s0t";
	TString Precut = "(reco_asso_tracks == 0 && reco_asso_showers == 2)";
	Precut += "&&(reco_vertex_x > 5 && reco_vertex_x < 251 && reco_vertex_y > -110 && reco_vertex_y < 110 && reco_vertex_z > 20 && reco_vertex_z< 986)";//FV Cut

	//Configure class Var: varaibles, axis name, binnings 
	std::vector< Vars> allVar = SetMultipleVars();


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
		PrintHist(hist);

		hs->Add(hist);

		if(errorHist){
			errorHist->Add(hist);
		} else{
			errorHist = (TH1D*) hist->Clone();
		}
	}

	//Add data overlay
	data.AddDefinition(Precut);
	TH1D* hdata = drawTH1D(data, temp_var);
	hdata->Scale(PlotPOT/data.GetPOT());
	hdata->SetMarkerSize(1);//data
	hdata->SetMarkerStyle(20);//data
	TString leg_title = data.GetSampleName() + Form(" %.0lf",hdata->Integral());
	leg->AddEntry( hdata, leg_title, "fl");

	std::cout<<"\nSummary: "<< leg_title<<std::endl;
	PrintHist(hdata);


	//errorHist style
	errorHist->SetMarkerSize(0);
	errorHist->SetFillStyle(3454);
	errorHist->SetLineWidth(2);
	errorHist->SetLineColor(kBlack);
	errorHist->SetFillColor(kBlack);
	TString mc_leg_title = Form("Stat. Error | Total Pred.: %.1lf",errorHist->Integral());
	leg->AddEntry(errorHist, mc_leg_title, "fl");
	std::cout<<"\nSummary total MC:"<<std::endl;
	PrintHist(errorHist);

	ExportPNG_StackData_wLabel(hs, hdata, errorHist, leg, MakeSafeName(Label+temp_var.GetAxisLabel() ) , temp_var.GetAxisLabel(), Form("Events in %gPOT", PlotPOT), temp_var.GetIsLog());
	}

}

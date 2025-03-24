#include "./utility/ConfigureSamples.h"
//
//Configure class Samples: name, input file, tree name, cut
//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

//scalings_run1 = { "nu":1./2.35e21, "dirt":1.0*0.75/1.55e21, "beamoff": 0.98*(6230439.0/9186361.390000)}
//scalings_run3 = { "nu":1./(1.993661e21), "dirt":1.0*0.35/1.020e21, "beamoff": 0.98*(10714868.0/34147459.925000)}

Samples LoadAxions( TString tag ){
	Samples axion("Axion"+tag,"/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_"+tag+"_v1_zlt40m.root","singlephotonana/vertex_tree","Entry$%2==0");
//OLD Freind of BDT with 12 variables
//	axion.AddFriend("../../../2022Nov_ub_gLEE_Ntuples/hellstroms_hive/hive/build_axion_general/NuMIFHCRun1Axion"+tag+"/NuMIFHCRun1Axion"+tag+"NCPionClassifiee_Axion"+tag+"_app.root","Axion"+tag+"_NuMIFHCRun1Axion"+tag+"NCPionClassifiee");
//NEW Freind of BDT with 3 variables
	axion.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_Axion"+tag+"_app.root","Axion"+tag+"_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	axion.SetScale(3*2.0/58560);
	axion.SetPlotStyle(kYellow-3, 1001);
	axion.SetPOT(2e21);
	
	return axion;
};


Samples LoadNC1pi0( TString tag ){
	Samples tmpSample("NC1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==1 &&Entry$%2==0");
	tmpSample.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NCPi0_app.root","NCPi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2);//Have used half for training;

	return tmpSample;
};


Samples LoadNC0pi0( TString tag ){
	Samples tmpSample("NC0#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==0");
	tmpSample.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NC0Pi0_app.root","NC0Pi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	tmpSample.SetPlotStyle(kBlue-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);

	return tmpSample;
};


Samples LoadCCnue( TString tag ){

	Samples ccnue("CC#nu_{e}/#bar{#nu_{e}}Intrinsic", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&fabs(mctruth_nu_pdg)==12");
	ccnue.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NueOverlays_app.root","NueOverlays_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	ccnue.SetPlotStyle(kGreen-8,1001);
	ccnue.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnue.SetPOT(2.35e21);

	return ccnue;
};


Samples LoadCCnumu1pi( TString tag ){
	Samples ccnumu1pi("CC#nu_{#mu}1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==1");
	ccnumu1pi.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_CC1Pi0_app.root","CC1Pi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	ccnumu1pi.SetPlotStyle(kRed-6,1001);
	ccnumu1pi.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnumu1pi.SetPOT(2.35e21);

	return ccnumu1pi;
};


Samples LoadCCnumu0pi( TString tag ){

	Samples ccnumu0pi("CC#nu_{#mu}0#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==0");
	ccnumu0pi.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_CC0Pi0_app.root","CC0Pi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	ccnumu0pi.SetPlotStyle(kBlue-6,1001);
	ccnumu0pi.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnumu0pi.SetPOT(2.35e21);


	return ccnumu0pi;
};


Samples LoadOthers( TString tag ){

	TString othercuts = "!(mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==1)"; //tmpSample
	othercuts+= "&&!(mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==0)";//nc0pi
	othercuts+= "&&!(mctruth_cc_or_nc==0&&fabs(mctruth_nu_pdg)==12)";//ccnuenuebar
	othercuts+= "&&!(mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==1)";//ccnumu1pi
	othercuts+= "&&!(mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==0)";//ccnumu0pi

	Samples other("InCryoOthers", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree",othercuts);
	other.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NuMIOtherExtra_app.root","NuMIOtherExtra_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	other.SetPlotStyle(kGreen-2,1001);
	other.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	other.SetPOT(2.35e21);

	return other;
};


Samples LoadDirt( TString tag ){

	Samples dirt("Dirt (OutsideCryo)  x.7","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1dirt_luis_goodweight.root","vertex_tree","1");
	dirt.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_Dirt_app.root","Dirt_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	dirt.SetPlotStyle(kOrange-7, 1001);
	dirt.SetWeight("ppfx_cv_good*spline_tune_good");
	dirt.SetPOT(1.55e21);
	dirt.SetScale(0.7);

	return dirt;
};

// New Categories
Samples LoadRun1NCpi0( TString tag ){
	Samples tmpSample("NC#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0>0 &&Entry$%2==0");
	tmpSample.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NCPi0_app.root","NCPi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2);//Have used half for training;

	return tmpSample;
};

Samples LoadRun1NC0pi0Other( TString tag ){
	Samples tmpSample("NC0#pi^{0}Other", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==0");
	tmpSample.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NCPi0_app.root","NCPi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	tmpSample.SetPlotStyle(kBlue-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);

	return tmpSample;
};

Samples LoadRun1CCpi0( TString tag ){
	Samples tmpSample("CC#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&mctruth_num_exiting_pi0>0");
	tmpSample.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NCPi0_app.root","NCPi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	tmpSample.SetPlotStyle(kRed-6,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);

	return tmpSample;
};

Samples LoadRun1CC0pi0Other( TString tag ){
	Samples tmpSample("CC0#pi^{0}Other", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&mctruth_num_exiting_pi0==0");
	tmpSample.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NCPi0_app.root","NCPi0_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);

	return tmpSample;
};




//Data set
Samples LoadData( TString tag ){

	Samples data("Data NuMI Run1 FHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1data_luis_full.root","singlephotonana/vertex_tree","(run_number<6748)||(run_number==6748 && subrun_number<22)");
	data.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NuMIDataCANTTAKECUTS_app.root","NuMIDataCANTTAKECUTS_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	data.SetPOT(2.37e20);

	return data;
};

//Data set
Samples LoadEXT( TString tag ){

	Samples ext("Run1 EXT x.98","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run1EXT_luis_filtered.root","singlephotonana/vertex_tree","1");
	ext.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRun1AxionV2"+tag+"/NuMIFHCRun1AxionV2"+tag+"NCPionClassifier_NuMIextRun1_app.root","NuMIextRun1_NuMIFHCRun1AxionV2"+tag+"NCPionClassifier");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(1.846e19*513630.025/426046.0);//2.2e19 POT
	ext.SetScale(0.98);

	return ext;
}




//Run3 Pre16880 ---------------------------------------------------
Samples LoadRun3Pre16880Axions( TString tag ){
	Samples axion("Axion"+tag,"/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_"+tag+"_v1_zlt40m.root","singlephotonana/vertex_tree","Entry$%2==0");
	axion.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_Axion"+tag+"_app.root","Axion"+tag+"_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");
	axion.SetScale(3*2.0/58560);
	axion.SetPlotStyle(kYellow-3, 1001);
	axion.SetPOT(2e21);
	
	return axion;
};


Samples LoadRun3Pre16880NC1pi0( TString tag ){
	Samples tmpSample("NC1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==1 &&Entry$%2==0&&run_number<16880");
	tmpSample.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_NCPi0_app.root","NCPi0_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");
	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.53689e21);
	tmpSample.SetScale(2);//Have used half for training;

	return tmpSample;
};


Samples LoadRun3Pre16880NC0pi0( TString tag ){
	Samples tmpSample("NC0#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==0&&run_number<16880");
	tmpSample.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_NC0Pi0_app.root","NC0Pi0_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");
	tmpSample.SetPlotStyle(kBlue-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.53689e21);

	return tmpSample;
};


Samples LoadRun3Pre16880CCnue( TString tag ){

	Samples ccnue("CC#nu_{e}/#bar{#nu_{e}}Intrinsic", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&fabs(mctruth_nu_pdg)==12&&run_number<16880");
	ccnue.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_NueOverlays_app.root","NueOverlays_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");
	ccnue.SetPlotStyle(kGreen-8,1001);
	ccnue.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnue.SetPOT(1.53689e21);

	return ccnue;
};


Samples LoadRun3Pre16880CCnumu1pi( TString tag ){
	Samples ccnumu1pi("CC#nu_{#mu}1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==1&&run_number<16880");
	ccnumu1pi.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_CC1Pi0_app.root","CC1Pi0_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");
	ccnumu1pi.SetPlotStyle(kRed-6,1001);
	ccnumu1pi.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnumu1pi.SetPOT(1.53689e21);

	return ccnumu1pi;
};


Samples LoadRun3Pre16880CCnumu0pi( TString tag ){

	Samples ccnumu0pi("CC#nu_{#mu}0#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==0&&run_number<16880");
	ccnumu0pi.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_CC0Pi0_app.root","CC0Pi0_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");
	ccnumu0pi.SetPlotStyle(kBlue-6,1001);
	ccnumu0pi.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	ccnumu0pi.SetPOT(1.53689e21);


	return ccnumu0pi;
};


Samples LoadRun3Pre16880Others( TString tag ){

	TString othercuts = "run_number<16880&&!(mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==1)"; //tmpSample
	othercuts+= "&&!(mctruth_cc_or_nc==1&&mctruth_num_exiting_pi0==0)";//nc0pi
	othercuts+= "&&!(mctruth_cc_or_nc==0&&fabs(mctruth_nu_pdg)==12)";//ccnuenuebar
	othercuts+= "&&!(mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==1)";//ccnumu1pi
	othercuts+= "&&!(mctruth_cc_or_nc==0&&mctruth_nu_pdg==14&&mctruth_num_exiting_pi0==0)";//ccnumu0pi

	Samples other("InCryoOthers", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight.root","vertex_tree",othercuts);
	other.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_NuMIOtherExtra_app.root","NuMIOtherExtra_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");
	other.SetPlotStyle(kGreen-2,1001);
	other.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	other.SetPOT(1.53689e21);

	return other;
};


Samples LoadRun3Pre16880Dirt( TString tag ){

	Samples dirt("Dirt (OutsideCryo)  x.52","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3dirt_luis_goodweight.root","vertex_tree","run_number<16880");
	dirt.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_Dirt_app.root","Dirt_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");
	dirt.SetPlotStyle(kOrange-7, 1001);
	dirt.SetWeight("ppfx_cv_good*spline_tune_good");
	dirt.SetPOT(6.01415e20);
	dirt.SetScale(0.52);

	return dirt;
};

//Data set
Samples LoadRun3Pre16880Data( TString tag ){

	Samples data("NuMI Data R3b RHC < 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3data_luis_full.root","singlephotonana/vertex_tree","run_number<16880");
	data.SetPOT(4.108e20);

	data.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_NuMIDataCANTTAKECUTS_app.root","NuMIDataCANTTAKECUTS_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");

	return data;
};

//Data set
Samples LoadRun3Pre16880EXT( TString tag ){

	Samples ext("Run3b EXT < 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3EXT_luis.root",              "singlephotonana/vertex_tree","run_number<16880");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(4.22e20*19381337.925/8742594.0);//from POT tool, 9.35e20
	ext.SetScale(0.98);
	ext.AddFriend("../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRHCRun3Pre16880AxionV2"+tag+"/NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier_NuMIextRun3bPre16880_app.root","NuMIextRun3bPre16880_NuMIRHCRun3Pre16880AxionV2"+tag+"NCPionClassifier");

	return ext;
}

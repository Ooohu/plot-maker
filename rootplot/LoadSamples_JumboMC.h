#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT_j="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir_j="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/";
//static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRuns_cleanPi0Train/";
//static const TString TrainDir_j="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRuns_MultiBDTs/";
static const TString TrainDir_j="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIAllMC_2s0t_Jan2026/";

Samples LoadAllFHC( TString mTag ){
	Samples tmpSample("FHC Runs All Bkg", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_FHC_2s0t.root","vertex_tree",COMMONCUT_j);


	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetPOT(8.91e21);
	tmpSample.SetScale(2.996768);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllFHCBkg");
//	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good")); // vulnerable to inf weight of spline_tune_good
// Different runs' MC have different weight branches.

	return tmpSample;
};



Samples LoadAllFHCOnepi0( TString mTag ){
	Samples tmpSample("FHC Runs 1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_FHC_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT_j);


	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetPOT(8.91e21);
	tmpSample.SetScale(2.996768);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllFHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good

	return tmpSample;
};

Samples LoadAllFHCNueCC( TString mTag ){
	Samples tmpSample("FHC CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT_j);


	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetPOT(8.91e21);
	tmpSample.SetScale(2.996768);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllFHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};

Samples LoadAllFHCNumuCC( TString mTag ){
	Samples tmpSample("FHC CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT_j);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetPOT(8.91e21);
	tmpSample.SetScale(2.996768);

	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllFHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};


Samples LoadAllFHCOtherCC( TString mTag ){
	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& "+COMMONCUT_j);

	tmpSample.SetPlotStyle(kGreen-2,1001);
	tmpSample.SetPOT(8.91e21);
	tmpSample.SetScale(2.996768);

	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllFHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};



Samples LoadAllFHCInCryoOther( TString mTag ){
	Samples tmpSample("FHC InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT_j);

	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetPOT(8.91e21);
	tmpSample.SetScale(2.996768);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllFHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};



// RHC
Samples LoadAllRHCOnepi0( TString mTag ){
	Samples tmpSample("RHC Runs 1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_RHC_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT_j);


	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetPOT(9.67e21);
	tmpSample.SetScale(2.9393367);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllRHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};

Samples LoadAllRHCNueCC( TString mTag ){
	Samples tmpSample("RHC CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT_j);


	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetPOT(9.67e21);
	tmpSample.SetScale(2.9393367);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllRHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};

Samples LoadAllRHCNumuCC( TString mTag ){
	Samples tmpSample("RHC CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT_j);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetPOT(9.67e21);
	tmpSample.SetScale(2.9393367);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllRHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};


Samples LoadAllRHCOtherCC( TString mTag ){
	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& "+COMMONCUT_j);

	tmpSample.SetPlotStyle(kGreen-2,1001);
	tmpSample.SetPOT(9.67e21);
	tmpSample.SetScale(2.9393367);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllRHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};



Samples LoadAllRHCInCryoOther( TString mTag ){
	Samples tmpSample("RHC InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT_j);

	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetPOT(9.67e21);
	tmpSample.SetScale(2.9393367);

	//Add Friends ~ Start
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuAllRHCBkg");
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good


	return tmpSample;
};





// EXT
//
Samples LoadJumboEXT( TString mTag ){

	Samples ext("All EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboEXT_2s0t.root","vertex_tree",COMMONCUT_j);
	ext.SetPlotStyle(kGreen-6, 3333);
//	ext.SetPOT(2.76e20*9.25e6/6.62e6);
	ext.SetPOT(6.8e21);
	ext.SetScale(0.98*2.9657086);

	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"AllExt");


	return ext;
}





Samples LoadJumboDataR1toR3( TString mTag ){

	Samples data("Data NuMI R1-R3","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboData_R1R2aR2bR3Pre16880_2s0t.root","vertex_tree","1");
	data.SetPOT(1.13e21);

	//Add Friends ~ Start
	data.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier",	"NuMIDataR1ToR3Pre16880");

	return data;
};



//Individual MCs
Samples Loadrun1dirt( TString mTag ){
	Samples tmpSample("run1dirt",FDir_j+"gleeNtuples_numi_run1dirt_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run1dirt");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run1dirt");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.73409e+21);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun2MCFHC( TString mTag ){
	Samples tmpSample("run2MCFHC",FDir_j+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run2MCFHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.47898e+21);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun2MCRHC( TString mTag ){
	Samples tmpSample("run2MCRHC",FDir_j+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run2MCRHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(5.63511e+21);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun2adirt_FHC( TString mTag ){
	Samples tmpSample("run2adirt_FHC",FDir_j+"gleeNtuples_numi_run2adirt_FHC_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run2adirt_FHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run2adirt_FHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(8.64708e+19);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun2bdirt_RHC( TString mTag ){
	Samples tmpSample("run2bdirt_RHC",FDir_j+"gleeNtuples_numi_run2bdirt_RHC_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run2bdirt_RHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run2bdirt_RHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(9.17354e+19);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4aMC( TString mTag ){
	Samples tmpSample("run4aMC",FDir_j+"gleeNtuples_numi_run4aMCOverlay_reweighted_final_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4aMC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4aMC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(4.98713e+20);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4adirt_FHC( TString mTag ){
	Samples tmpSample("run4adirt_FHC",FDir_j+"gleeNtuples_numi_run4adirt_FHC_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4adirt_FHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4adirt_FHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(8.47892e+20);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4adirt_RHC( TString mTag ){
	Samples tmpSample("run4adirt_RHC",FDir_j+"gleeNtuples_numi_run4adirt_RHC_final_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4adirt_RHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4adirt_RHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.92094e+19);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4bMC( TString mTag ){
	Samples tmpSample("run4bMC",FDir_j+"gleeNtuples_numi_run4bMCOverlay_reweighted_final_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4bMC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4bMC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.54536e+21);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4bdirt_RHC( TString mTag ){
	Samples tmpSample("run4bdirt_RHC",FDir_j+"gleeNtuples_numi_run4bdirt_RHC_wMCTruth_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4bdirt_RHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4bdirt_RHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.63754e+20);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4cMC( TString mTag ){
	Samples tmpSample("run4cMC",FDir_j+"gleeNtuples_numi_run4cMCOverlay_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4cMC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4cMC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(8.43891e+20);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4cdirt_FHC( TString mTag ){
	Samples tmpSample("run4cdirt_FHC",FDir_j+"gleeNtuples_numi_run4cdirt_FHC_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4cdirt_FHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4cdirt_FHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.55181e+20);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4dMC( TString mTag ){
	Samples tmpSample("run4dMC",FDir_j+"gleeNtuples_numi_run4dMCOverlay_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4dMC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4dMC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.33292e+21);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun4ddirt_FHC( TString mTag ){
	Samples tmpSample("run4ddirt_FHC",FDir_j+"gleeNtuples_numi_run4ddirt_FHC_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run4ddirt_FHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run4ddirt_FHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.43699e+20);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun5MC( TString mTag ){
	Samples tmpSample("run5MC",FDir_j+"gleeNtuples_numi_run5MCOverlay_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run5MC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run5MC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.90108e+21);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};


Samples Loadrun5dirt_FHC( TString mTag ){
	Samples tmpSample("run5dirt_FHC",FDir_j+"gleeNtuples_numi_run5dirt_FHC_0lifetimeRemoval_2s0t.root","vertex_tree",COMMONCUT_j);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  mTag+"PionAccurateClassifier", "run5dirt_FHC");
	tmpSample.AddFriendViaTag_v2(TrainDir_j,  "Pi0CosmicClassifier", "run5dirt_FHC");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(3.56471e+20);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune"));

	return tmpSample;
};



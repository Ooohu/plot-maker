#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/";
static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIAllMC_2s0t_Jan2026/";

Samples LoadRun2FHCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight



	return tmpSample;
};


Samples LoadRun2FHCNueCC( TString mTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight


	return tmpSample;
};

Samples LoadRun2FHCNumuCC( TString mTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight


	return tmpSample;
};




Samples LoadRun2FHCOtherCC( TString mTag ){//NOT USED

	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-2,1001);
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight


	return tmpSample;
};


Samples LoadRun2FHCInCryoOther( TString mTag ){
	Samples tmpSample("InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight


	return tmpSample;
};


Samples LoadRun2FHCDirt( TString mTag ){

	Samples tmpSample("Dirt (OutsideCryo)  x.61","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2adirt_FHC_2s0t.root","vertex_tree","1");

	tmpSample.SetPlotStyle(kOrange-7, 1001);
	tmpSample.SetPOT(8.6e19);
	tmpSample.SetScale(0.61);
	
	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"run2adirt_FHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run2adirt_FHC");



	return tmpSample;
};


//Data set
Samples LoadRun2aFHCData( TString mTag ){

	Samples data("Data NuMI Run2a FHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2adata_2s0t.root","vertex_tree","(run_number>8772)&&(run_number<9931)");
	data.SetPOT(1.46e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR2a");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR2a");

	return data;
};

Samples LoadJumboEXT( TString mTag ){

	Samples ext("All EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboEXT_2s0t.root","vertex_tree",COMMONCUT);
	ext.SetPlotStyle(kGreen-6, 3333);
//	ext.SetPOT(2.76e20*9.25e6/6.62e6);
	ext.SetPOT(6.8e21);
	ext.SetScale(0.98*2.9657086);

	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"AllExt");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"AllExt");


	return ext;
}

Samples LoadRun2aEXT( TString mTag ){

	Samples ext("Run2a EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2aEXT_2s0t.root","vertex_tree","subrun_number%3==0");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(2.99e20*1.76e7/7.13e6);
	ext.SetScale(0.98*3.1602317);//Have used 2/3 for training;


	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR2a");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR2a");

	return ext;
}

Samples LoadRun2aFHCEXT( TString mTag ){

	Samples ext("Run2a FHC EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2aEXT_2s0t.root","vertex_tree","run_number > 8772 && run_number<9931");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(3.11e20);
	ext.SetScale(0.98);//Have used 2/3 for training;


//	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR2a");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR2a");

	return ext;
}


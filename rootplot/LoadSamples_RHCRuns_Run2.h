#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/";
static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIAllMC_2s0t_Jan2026/";

Samples LoadRun2RHCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight



	return tmpSample;
};


Samples LoadRun2RHCNueCC( TString mTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight


	return tmpSample;
};

Samples LoadRun2RHCNumuCC( TString mTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight


	return tmpSample;
};




Samples LoadRun2RHCOtherCC( TString mTag ){//NOT USED

	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-2,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
//Now weights available for Run2 at the moment :(
//	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight


	return tmpSample;
};


Samples LoadRun2RHCInCryoOther( TString mTag ){
	Samples tmpSample("InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
//	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root", "eventweight_tree");//gonna need additional weights	
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight


	return tmpSample;
};


Samples LoadRun2RHCDirt( TString mTag ){

	Samples tmpSample("Dirt (OutsideCryo)  x.54","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2bdirt_RHC_2s0t.root","vertex_tree","1");

	tmpSample.SetPlotStyle(kOrange-7, 1001);
	tmpSample.SetPOT(9.17e19);
	tmpSample.SetScale(0.54);
	
	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"run2bdirt_RHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run2bdirt_RHC");



	return tmpSample;
};


//Data set
Samples LoadRun2bRHCData( TString mTag ){

	Samples data("Data NuMI Run2b RHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2bdata_2s0t.root","vertex_tree", "1");
	data.SetPOT(1.29e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR2b");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR2b");

	return data;
};

Samples LoadRun2aRHCData( TString mTag ){

	Samples data("Data NuMI Run2a RHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2adata_2s0t.root","vertex_tree", "run_number>10245");
	data.SetPOT(1.36e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR2a");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR2a");

	return data;
};

//Data set
Samples LoadRun1RHCData( TString mTag ){

	Samples data("Data NuMI Run1 RHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1data_luis_full_2s0t.root","vertex_tree","!((run_number<6748)||(run_number==6748 && subrun_number<22))");
	data.SetPOT(6.19E+19);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR1");
	data.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIDataR1");

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

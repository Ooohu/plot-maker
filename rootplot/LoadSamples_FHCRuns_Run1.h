#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/";
//static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRuns_2s0t_Jan2026/";
static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIAllMC_2s0t_Jan2026/";

Samples LoadRun1FHCAll( TString mTag ){
	Samples tmpSample("AllMC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree",COMMONCUT);


	tmpSample.SetPlotStyle(kBlue+4,1001);
	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good")); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2.9431896);

	//Add Friends
//	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier",			"run1MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run1MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run1MCFHC");

	return tmpSample;
};




//New Categories!
Samples LoadRun1FHCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);


	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good")); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2.9431896);

	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run1MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run1MCFHC");


	return tmpSample;
};


Samples LoadRun1FHCNueCC( TString mTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good")); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2.9431896);

	
	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run1MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run1MCFHC");


	return tmpSample;
};

Samples LoadRun1FHCNumuCC( TString mTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good")); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2.9431896);
	
	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run1MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run1MCFHC");


	return tmpSample;
};




Samples LoadRun1FHCOtherCC( TString mTag ){//empty

	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-2,1001);
	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good")); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2.9431896);
	
	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run1MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run1MCFHC");


	return tmpSample;
};


Samples LoadRun1FHCInCryoOther( TString mTag ){
	Samples tmpSample("InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good")); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2.9431896);

	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run1MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run1MCFHC");


	return tmpSample;
};


Samples LoadRun1FHCDirt( TString mTag ){

	Samples tmpSample("Dirt (OutsideCryo)  x.72","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1dirt_luis_goodweight_2s0t.root","vertex_tree","1");

	tmpSample.SetPlotStyle(kOrange-7, 1001);
	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good"));
	tmpSample.SetPOT(1.55e21);
	tmpSample.SetScale(0.72);
	
	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run1dirt");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run1dirt");



	return tmpSample;
};


//Data set
Samples LoadRun1FHCData( TString mTag ){

	Samples data("Data NuMI Run1 FHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1data_luis_full_2s0t.root","vertex_tree","(run_number<6748)||(run_number==6748 && subrun_number<22)");
	data.SetPOT(2.37e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR1");
	data.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIDataR1");

	return data;
};

//Data set
Samples LoadRun1EXT( TString mTag ){

	Samples ext("Run1 EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1EXT_full_2s0t.root","vertex_tree",COMMONCUT);
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(2.76e20*9.25e6/6.62e6);
	ext.SetScale(0.98*2.8049536);

	//Add Friends
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR1");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR1");


	return ext;
}

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

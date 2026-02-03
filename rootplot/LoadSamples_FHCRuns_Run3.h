#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/";
static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIAllMC_2s0t_Jan2026/";



Samples LoadRun3RHCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used 1/3 for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuMIRun3Bkg");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "NuMIRun3Bkg");

	return tmpSample;
};


Samples LoadRun3RHCNueCC( TString mTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used half for training;

	
	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuMIRun3Bkg");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "NuMIRun3Bkg");


	return tmpSample;
};

Samples LoadRun3RHCNumuCC( TString mTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used half for training;

	
	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuMIRun3Bkg");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "NuMIRun3Bkg");



	return tmpSample;
};




Samples LoadRun3RHCOtherCC( TString mTag ){//empty

	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-2,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used half for training;

	
	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuMIRun3Bkg");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "NuMIRun3Bkg");


	return tmpSample;
};


Samples LoadRun3RHCInCryoOther( TString mTag ){
	Samples tmpSample("InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuMIRun3Bkg");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "NuMIRun3Bkg");



	return tmpSample;
};


Samples LoadRun3RHCDirt( TString mTag ){

	Samples tmpSample("Dirt (OutsideCryo)  x.52","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3dirt_luis_goodweight_2s0t.root","vertex_tree","run_number<16880");
	
	tmpSample.SetPlotStyle(kOrange-7, 1001);
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good");
	tmpSample.SetPOT(6.01415e20);
	tmpSample.SetScale(0.52);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "Dirt");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "Dirt");


	return tmpSample;
};


//Data set
Samples LoadRun3Pre16880RHCData( TString mTag ){

	Samples data("NuMI Data R3b RHC < 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3data_luis_full_2s0t.root","vertex_tree","run_number<16880");
	data.SetPOT(4.108e20);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuMIDataR3b");
	data.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "NuMIDataR3b");

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

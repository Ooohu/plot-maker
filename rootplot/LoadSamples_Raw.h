#include "./utility/ConfigureSamples.h"

//---------------------------
//-------- Common tag  ------
//---------------------------

//static gives internal linkage
static const TString COMMONCUT="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/";
static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIAllMC_Jan2026/";


//EXT could be consistent across all runs
Samples LoadJumboEXT( TString mTag ){

	Samples ext("All EXT",FDir+"JumboEXT.root","vertex_tree",COMMONCUT);
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(6.8e21);
	ext.SetScale(0.98*2.9657086);

	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"AllExt");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"AllExt");


	return ext;
}




//---------------------------
//-------- Run 1 FHC  ------
//---------------------------
//{
Samples LoadRun1FHCAll( TString mTag ){
	Samples tmpSample("AllMC", FDir+"gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight.root","vertex_tree",COMMONCUT);


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


Samples LoadRun1FHCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", FDir+"gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);


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

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", FDir+"gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

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

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", FDir+"gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetWeight(MakeSafeWgtName("ppfx_cv_good*spline_tune_good")); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.35e21);
	tmpSample.SetScale(2.9431896);

	//Add Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run1MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"run1MCFHC");


	return tmpSample;
};



Samples LoadRun1FHCInCryoOther( TString mTag ){
	Samples tmpSample("InCryoOther", FDir+"gleeNtuples_numi_run1MCOverlay_reweight_luis_goodweight.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);

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

	Samples tmpSample("Dirt (OutsideCryo)  x.72",FDir+"gleeNtuples_numi_run1dirt_luis_goodweight.root","vertex_tree","1");

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

	Samples data("Data NuMI Run1 FHC",FDir+"gleeNtuples_numi_run1data_luis_full.root","singlephotonana/vertex_tree","(run_number<6748)||(run_number==6748 && subrun_number<22)");
	data.SetPOT(2.37e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR1");
	data.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIDataR1");

	return data;
};

//EXTs
Samples LoadRun1EXT( TString mTag ){

	Samples ext("Run1 EXT",FDir+"gleeNtuples_numi_run1EXT_full.root","singlephotonana/vertex_tree",COMMONCUT);
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(2.76e20*9.25e6/6.62e6);
	ext.SetScale(0.98*2.8049536);

	//Add Friends
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR1");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR1");


	return ext;
}
//}



//---------------------------
//-------- Run 2a FHC  ------
//---------------------------
//{
Samples Loadrun2MCFHCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", FDir + "gleeNtuples_numi_run2MCOverlay_NewFlux_FHC.root","singlephotonana/vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetPOT(2.47898e+21);
	tmpSample.SetScale(3);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_FHC.root", "singlephotonana/eventweight_tree");
	//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));



	return tmpSample;
};


Samples Loadrun2MCFHCNueCC( TString mTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_FHC.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetPOT(2.47898e+21);
	tmpSample.SetScale(3);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_FHC.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
	//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


	return tmpSample;
};

Samples Loadrun2MCFHCNumuCC( TString mTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_FHC.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetPOT(2.47898e+21);
	tmpSample.SetScale(3);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_FHC.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
	//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


	return tmpSample;
};




Samples Loadrun2MCFHCInCryoOther( TString mTag ){
	Samples tmpSample("InCryoOther", FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_FHC.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetPOT(2.47898e+21);
	tmpSample.SetScale(3);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCFHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_FHC.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
	//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


	return tmpSample;
};

Samples Loadrun2MCFHCDirt( TString mTag ){

	Samples tmpSample("Dirt (OutsideCryo)  x.61",FDir+"gleeNtuples_numi_run2adirt_FHC.root","singlephotonana/vertex_tree","1");

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

	Samples data("Data NuMI Run2a FHC",FDir+"gleeNtuples_numi_run2adata.root","singlephotonana/vertex_tree","(run_number>8772)&&(run_number<9931)");
	data.SetPOT(1.46e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR2a");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR2a");

	return data;
};


Samples LoadRun2aEXT( TString mTag ){

	Samples ext("Run2a EXT",FDir+"gleeNtuples_numi_run2aEXT.root","singlephotonana/vertex_tree","subrun_number%3==0");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(2.99e20*1.76e7/7.13e6);
	ext.SetScale(0.98*3.1602317);//Have used 2/3 for training;


	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR2a");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR2a");

	return ext;
}

Samples LoadRun2aFHCEXT( TString mTag ){

	Samples ext("Run2a FHC EXT",FDir+"gleeNtuples_numi_run2aEXT.root","singlephotonana/vertex_tree","run_number > 8772 && run_number<9931");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(3.11e20);
	ext.SetScale(0.98);//Have used 2/3 for training;


	//	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR2a");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR2a");

	return ext;
}
//}




//---------------------------
//-------- Run 2b RHC  ------
//---------------------------
//{
Samples LoadRun2RHCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_RHC.root","singlephotonana/vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_RHC.root", "singlephotonana/eventweight_tree");//gonna need additional weights	
	//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv")); // vulnerable to inf/nan weight



	return tmpSample;
};


Samples LoadRun2RHCNueCC( TString mTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_RHC.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_RHC.root", "singlephotonana/eventweight_tree");//gonna need additional weights	
	//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv")); // vulnerable to inf/nan weight


	return tmpSample;
};

Samples LoadRun2RHCNumuCC( TString mTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_RHC.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_RHC.root", "singlephotonana/eventweight_tree");//gonna need additional weights	
	//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv")); // vulnerable to inf/nan weight


	return tmpSample;
};





Samples LoadRun2RHCInCryoOther( TString mTag ){
	Samples tmpSample("InCryoOther", FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_RHC.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run2MCRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run2MCRHC");
	//	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run2MCOverlay_NewFlux_RHC.root", "singlephotonana/eventweight_tree");//gonna need additional weights	
	//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv")); // vulnerable to inf/nan weight


	return tmpSample;
};


Samples LoadRun2RHCDirt( TString mTag ){

	Samples tmpSample("Dirt (OutsideCryo)  x.54",FDir+"gleeNtuples_numi_run2bdirt_RHC.root","singlephotonana/vertex_tree","1");

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

	Samples data("Data NuMI Run2b RHC",FDir+"gleeNtuples_numi_run2bdata.root","singlephotonana/vertex_tree", "1");
	data.SetPOT(1.29e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR2b");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR2b");

	return data;
};

Samples LoadRun2aRHCData( TString mTag ){

	Samples data("Data NuMI Run2a RHC",FDir+"gleeNtuples_numi_run2adata.root","singlephotonana/vertex_tree", "run_number>10245");
	data.SetPOT(1.36e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR2a");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR2a");

	return data;
};


Samples LoadRun2bEXT( TString mTag ){

	Samples ext("Run2b EXT",FDir+"gleeNtuples_numi_run2bEXT.root","singlephotonana/vertex_tree","1");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(1.08e20);
	ext.SetScale(0.98);


	//	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR2b");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR2b");

	return ext;
}


//}


//---------------------------
//--- Run 3 Pre16880 RHC  ---
//---------------------------
//{
Samples LoadRun3RHCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", FDir+"gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight.root","vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

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

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", FDir+"gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

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

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", FDir+"gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

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




Samples LoadRun3RHCInCryoOther( TString mTag ){
	Samples tmpSample("InCryoOther", FDir+"gleeNtuples_numi_run3MCOverlay_reweight_luis_goodweight.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
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

	Samples tmpSample("Dirt (OutsideCryo)  x.52",FDir+"gleeNtuples_numi_run3dirt_luis_goodweight.root","vertex_tree","run_number<16880");

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

	Samples data("NuMI Data R3b RHC < 16880 run",FDir+"gleeNtuples_numi_run3data_luis_full.root","singlephotonana/vertex_tree","run_number<16880");
	data.SetPOT(4.108e20);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuMIDataR3b");
	data.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "NuMIDataR3b");

	return data;
};

Samples LoadRun3Pre16880EXT( TString AmassBDTTag ){

	Samples ext("Run3b EXT < 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3EXT_luis.root","singlephotonana/vertex_tree","run_number<16880");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(9.34e20);
	ext.SetScale(0.98);
//	ext.SetScale(0.98*2.9566);

	//Add Friends ~ Start


	return ext;
}


Samples LoadRun3Post16880EXT( TString AmassBDTTag ){

	Samples ext("Run3b EXT > 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/gleeNtuples_numi_run3EXT_luis.root","singlephotonana/vertex_tree","run_number>16880");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(7.21e20);
	ext.SetScale(0.98);

	//Add Friends ~ Start


	return ext;
}

//}

//---------------------------
//------- Run 4 b RHC  ------
//---------------------------
//{
Samples Loadrun4bMCOnepi0( TString mTag ){
	Samples tmpSample("1#pi^{0}", FDir + "gleeNtuples_numi_run4bMCOverlay_reweighted_final.root","singlephotonana/vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetPOT(1.54536e+21);
	tmpSample.SetScale(3);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4bMC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4bMC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4bMCOverlay_reweighted_final.root", "singlephotonana/eventweight_tree");
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));



	return tmpSample;
};


Samples Loadrun4bMCNueCC( TString mTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", FDir+"gleeNtuples_numi_run4bMCOverlay_reweighted_final.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetPOT(1.54536e+21);
	tmpSample.SetScale(3);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4bMC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4bMC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4bMCOverlay_reweighted_final.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


	return tmpSample;
};

Samples Loadrun4bMCNumuCC( TString mTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", FDir+"gleeNtuples_numi_run4bMCOverlay_reweighted_final.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetPOT(1.54536e+21);
	tmpSample.SetScale(3);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4bMC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4bMC");
	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4bMCOverlay_reweighted_final.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


	return tmpSample;
};



Samples Loadrun4bMCInCryoOther( TString mTag ){
    Samples tmpSample("InCryoOther", FDir+"gleeNtuples_numi_run4bMCOverlay_reweighted_final.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
    tmpSample.SetPlotStyle(kMagenta+3,1001);
    tmpSample.SetPOT(1.54536e+21);
    tmpSample.SetScale(3);

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4bMC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4bMC");
    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4bMCOverlay_reweighted_final.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


    return tmpSample;
};



Samples Loadrun4bMCDirt( TString mTag ){
	Samples tmpSample("Dirt  (OutsideCryo) x.52", FDir + "gleeNtuples_numi_run4bdirt_RHC_wMCTruth.root","singlephotonana/vertex_tree","1");

	tmpSample.SetPlotStyle(kOrange-7,1001);
	tmpSample.SetPOT(2.63754e+20);
	tmpSample.SetScale(0.52);//Have used half for training;

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4bdirt_RHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4bdirt_RHC");
//	tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4bdirt_RHC_wMCTruth.root", "singlephotonana/eventweight_tree");
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


	return tmpSample;
};

Samples LoadRun4bRHCData( TString mTag ){

	Samples data("Data NuMI Run4b RHC",FDir+"gleeNtuples_numi_run4bdata.root","singlephotonana/vertex_tree", "1");
	data.SetPOT(2.78e20);
	data.SetScale(0);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR4b");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR4b");

	return data;
};


Samples LoadRun4bEXT( TString mTag ){

	Samples ext("Run4b EXT",FDir+"gleeNtuples_numi_run4bEXT_final.root","singlephotonana/vertex_tree","1");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(5.85e20);
	ext.SetScale(0.98);


	//	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR4b");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR4b");

	return ext;
}
//}


//---------------------------
//------- Run 4 c FHC  ------
//---------------------------
//{

Samples Loadrun4cMCOnepi0( TString mTag ){
    Samples tmpSample("1#pi^{0}", FDir + "gleeNtuples_numi_run4cMCOverlay.root","singlephotonana/vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

    tmpSample.SetPlotStyle(kRed-3,1001);
    tmpSample.SetPOT(8.43891e+20);
    tmpSample.SetScale(3);//Have used half for training;

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4cMC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4cMC");
    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4cMCOverlay.root", "singlephotonana/eventweight_tree");
    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));



    return tmpSample;
};


Samples Loadrun4cMCNueCC( TString mTag ){

    Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", FDir+"gleeNtuples_numi_run4cMCOverlay.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

    tmpSample.SetPlotStyle(kGreen-8,1001);
    tmpSample.SetPOT(8.43891e+20);
    tmpSample.SetScale(3);//Have used half for training;

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4cMC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4cMC");
    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4cMCOverlay.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


    return tmpSample;
};

Samples Loadrun4cMCNumuCC( TString mTag ){

    Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", FDir+"gleeNtuples_numi_run4cMCOverlay.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

    tmpSample.SetPlotStyle(kBlue-6,1001);
    tmpSample.SetPOT(8.43891e+20);
    tmpSample.SetScale(3);//Have used half for training;

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4cMC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4cMC");
    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4cMCOverlay.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


    return tmpSample;
};


Samples Loadrun4cMCInCryoOther( TString mTag ){
    Samples tmpSample("InCryoOther", FDir+"gleeNtuples_numi_run4cMCOverlay.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
    tmpSample.SetPlotStyle(kMagenta+3,1001);
    tmpSample.SetPOT(8.43891e+20);
    tmpSample.SetScale(3);

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4cMC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4cMC");
    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4cMCOverlay.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


    return tmpSample;
};



Samples Loadrun4cMCDirt( TString mTag ){
	Samples tmpSample("Dirt  (OutsideCryo) x.52", FDir + "gleeNtuples_numi_run4cdirt_FHC.root","singlephotonana/vertex_tree","1");

    tmpSample.SetPlotStyle(kOrange-7,1001);
    tmpSample.SetPOT(1.55181e+20);
	tmpSample.SetScale(0.52);

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run4cdirt_FHC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run4cdirt_FHC");
    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run4cdirt_FHC.root", "singlephotonana/eventweight_tree");
//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv")); //Not available



    return tmpSample;
};





Samples LoadRun4cFHCData( TString mTag ){

	Samples data("Data NuMI Run4c FHC",FDir+"gleeNtuples_numi_run4cdata.root","singlephotonana/vertex_tree", "run_number>21396");
	data.SetPOT(1.68e20);
	data.SetScale(0);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR4c");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR4c");

	return data;
};



Samples LoadRun4cEXT( TString mTag ){

	Samples ext("Run4c EXT",FDir+"gleeNtuples_numi_run4cEXT_final.root","singlephotonana/vertex_tree","1");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(4.62e20);
	ext.SetScale(0.98);


	//	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR4c");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR4c");

	return ext;
}
//}


//---------------------------
//-------- Run 5 FHC  -------
//---------------------------
//{

Samples Loadrun5MCOnepi0( TString mTag ){
    Samples tmpSample("1#pi^{0}", FDir + "gleeNtuples_numi_run5MCOverlay.root","singlephotonana/vertex_tree","mctruth_num_exiting_pi0==1 &&"+COMMONCUT);

    tmpSample.SetPlotStyle(kRed-3,1001);
    tmpSample.SetPOT(1.90108e+21);
    tmpSample.SetScale(3);//Have used half for training;

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run5MC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run5MC");
//    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run5MCOverlay.root", "singlephotonana/eventweight_tree");
//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));



    return tmpSample;
};


Samples Loadrun5MCNueCC( TString mTag ){

    Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", FDir+"gleeNtuples_numi_run5MCOverlay.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && "+COMMONCUT);

    tmpSample.SetPlotStyle(kGreen-8,1001);
    tmpSample.SetPOT(1.90108e+21);
    tmpSample.SetScale(3);//Have used half for training;

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run5MC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run5MC");
//    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run5MCOverlay.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


    return tmpSample;
};

Samples Loadrun5MCNumuCC( TString mTag ){

    Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", FDir+"gleeNtuples_numi_run5MCOverlay.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && "+COMMONCUT);

    tmpSample.SetPlotStyle(kBlue-6,1001);
    tmpSample.SetPOT(1.90108e+21);
    tmpSample.SetScale(3);//Have used half for training;

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run5MC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run5MC");
//    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run5MCOverlay.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


    return tmpSample;
};


Samples Loadrun5MCInCryoOther( TString mTag ){
    Samples tmpSample("InCryoOther", FDir+"gleeNtuples_numi_run5MCOverlay.root","singlephotonana/vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && "+COMMONCUT);
    tmpSample.SetPlotStyle(kMagenta+3,1001);
    tmpSample.SetPOT(1.90108e+21);
    tmpSample.SetScale(3);

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run5MC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run5MC");
//    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run5MCOverlay.root", "singlephotonana/eventweight_tree");//gonna need additional weights    
//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));


    return tmpSample;
};




Samples Loadrun5MCDirt( TString mTag ){
	Samples tmpSample("Dirt  (OutsideCryo) x.62", FDir + "gleeNtuples_numi_run5dirt_FHC_0lifetimeRemoval.root","singlephotonana/vertex_tree","1");

    tmpSample.SetPlotStyle(kOrange-7,1001);
    tmpSample.SetPOT(3.56471e+20);
	tmpSample.SetScale(0.62);

    //dirtory, classifier, sample
    //<directory>/<classifier>_<sample>_app.root
    tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "run5dirt_FHC");
    tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "run5dirt_FHC");
//    tmpSample.AddFriend(FDir+"gleeNtuples_numi_run5dirt_FHC_0lifetimeRemoval.root", "singlephotonana/eventweight_tree");
//    tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune*ppfx_cv"));



    return tmpSample;
};


Samples LoadRun5FHCData( TString mTag ){

	Samples data("Data NuMI Run5 FHC",FDir+"gleeNtuples_numi_run5data_final.root","singlephotonana/vertex_tree", "1");
	data.SetPOT(2.35e20);
	data.SetScale(0);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR5");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR5");

	return data;
};



Samples LoadRun5EXT( TString mTag ){

	Samples ext("Run5 EXT",FDir+"gleeNtuples_numi_run5EXT_0lifetimeRemoval.root","singlephotonana/vertex_tree","1");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(9e20);
	ext.SetScale(0.98);


	//	//Add Friends ~ Start
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR5");
	ext.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier",	"NuMIExtR5");

	return ext;
}


//}

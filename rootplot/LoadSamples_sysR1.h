#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/systemaics/";
static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRuns_Sys/";


Samples LoadR1CV( TString mTag ){
	Samples tmpSample("R1CVFHC",FDir+"klin_NuMI_sys_R1_CVFHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1CVFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1CVFHC");
	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_CVFHC.root", "singlephotonana/eventweight_tree");//gonna need additional weights	

	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.31865e+21);
//	tmpSample.SetWeight("genie_CV_tune_weight*genie_spline_weight"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); // vulnerable to inf/nan weight
//	tmpSample.SetWeight("weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good

	return tmpSample;
};




Samples LoadR1_DetVarCV( TString mTag ){
	Samples tmpSample("R1_CV",FDir+"klin_NuMI_sys_R1_DetVarCV.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_CV");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_CV");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.51159e+20);
	
	return tmpSample;
};



Samples LoadR1_DetVarAlternativeSCMap( TString mTag ){
	Samples tmpSample("R1_AltSCMap",FDir+"klin_NuMI_sys_R1_DetVarAlternativeSCMap.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_AlternativeSCMap");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_AlternativeSCMap");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.43864e+20);
	
	return tmpSample;
};


Samples LoadR1_DetVarAlternativeRecombination( TString mTag ){
	Samples tmpSample("R1_AltRecomb",FDir+"klin_NuMI_sys_R1_DetVarAlternativeRecombination.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_AlternativeRecombination");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_AlternativeRecombination");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.51357e+20);
	
	return tmpSample;
};



Samples LoadR1_DetVarLYDown( TString mTag ){
	Samples tmpSample("R1_LYDown",FDir+"klin_NuMI_sys_R1_DetVarLYDown.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_LYDown");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_LYDown");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.5028e+20);
	
	return tmpSample;
};


Samples LoadR1_DetVarLYRayleigh( TString mTag ){
	Samples tmpSample("R1_LYRayleigh",FDir+"klin_NuMI_sys_R1_DetVarLYRayleigh.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_LYRayleigh");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_LYRayleigh");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.4733e+20);
	
	return tmpSample;
};


Samples LoadR1_DetVarWireModX( TString mTag ){
	Samples tmpSample("R1_WireModX",FDir+"klin_NuMI_sys_R1_DetVarWireModX.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_WireModX");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_WireModX");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.61331e+20);
	
	return tmpSample;
};


Samples LoadR1_DetVarWireModThetaXZ( TString mTag ){
	Samples tmpSample("R1_WMThetaXZ",FDir+"klin_NuMI_sys_R1_DetVarWireModThetaXZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_WireModThetaXZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_WireModThetaXZ");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.57063e+20);
	
	return tmpSample;
};


Samples LoadR1_DetVarWireModThetaYZ( TString mTag ){
	Samples tmpSample("R1_WMThetaYZ",FDir+"klin_NuMI_sys_R1_DetVarWireModThetaYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_WireModThetaYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_WireModThetaYZ");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.61997e+20);
	
	return tmpSample;
};


Samples LoadR1_DetVarWireModYZ( TString mTag ){
	Samples tmpSample("R1_WMYZ",FDir+"klin_NuMI_sys_R1_DetVarWireModYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "R1_WireModYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_WireModYZ");


	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.448e+20);
	
	return tmpSample;
};


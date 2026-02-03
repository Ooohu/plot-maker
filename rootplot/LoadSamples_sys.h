#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT="1";//"subrun_number%3==0";//I didn't train on these files, so no subrun cuts
static const TString FDir="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/systemaics/";
static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIAllMC_2s0t_Jan2026/";



Samples LoadR1_CVFHC( TString mTag ){
	Samples tmpSample("R1_CVFHC",FDir+"klin_NuMI_sys_R1_CVFHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_CVFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_CVFHC");
	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_CVFHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.31865e+21);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_CVRHC( TString mTag ){
	Samples tmpSample("R1_CVRHC",FDir+"klin_NuMI_sys_R1_CVRHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_CVRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_CVRHC");
	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_CVRHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.05297e+21);
	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarAlternativeRecombination( TString mTag ){
	Samples tmpSample("R1_AlternativeRecombination",FDir+"klin_NuMI_sys_R1_DetVarAlternativeRecombination.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_AlternativeRecombination");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_AlternativeRecombination");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarAlternativeRecombination.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.51357e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarAlternativeSCMap( TString mTag ){
	Samples tmpSample("R1_AlternativeSCMap",FDir+"klin_NuMI_sys_R1_DetVarAlternativeSCMap.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_AlternativeSCMap");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_AlternativeSCMap");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarAlternativeSCMap.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.43864e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarCV( TString mTag ){
	Samples tmpSample("R1_CV",FDir+"klin_NuMI_sys_R1_DetVarCV.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_CV");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_CV");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarCV.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.51159e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarLYDown( TString mTag ){
	Samples tmpSample("R1_LYDown",FDir+"klin_NuMI_sys_R1_DetVarLYDown.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_LYDown");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_LYDown");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarLYDown.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.5028e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarLYRayleigh( TString mTag ){
	Samples tmpSample("R1_LYRayleigh",FDir+"klin_NuMI_sys_R1_DetVarLYRayleigh.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_LYRayleigh");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_LYRayleigh");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarLYRayleigh.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.4733e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarWireModThetaXZ( TString mTag ){
	Samples tmpSample("R1_WireModThetaXZ",FDir+"klin_NuMI_sys_R1_DetVarWireModThetaXZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_WireModThetaXZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_WireModThetaXZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarWireModThetaXZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.57063e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarWireModThetaYZ( TString mTag ){
	Samples tmpSample("R1_WireModThetaYZ",FDir+"klin_NuMI_sys_R1_DetVarWireModThetaYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_WireModThetaYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_WireModThetaYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarWireModThetaYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.61997e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarWireModX( TString mTag ){
	Samples tmpSample("R1_WireModX",FDir+"klin_NuMI_sys_R1_DetVarWireModX.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_WireModX");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_WireModX");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarWireModX.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.61331e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR1_DetVarWireModYZ( TString mTag ){
	Samples tmpSample("R1_WireModYZ",FDir+"klin_NuMI_sys_R1_DetVarWireModYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R1_WireModYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R1_WireModYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R1_DetVarWireModYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(7.448e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_CVFHC( TString mTag ){
	Samples tmpSample("R2a_CVFHC",FDir+"klin_NuMI_sys_R2a_CVFHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_CVFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_CVFHC");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_CVFHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.46568e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarAlternativeRecombination( TString mTag ){
	Samples tmpSample("R2a_AlternativeRecombination",FDir+"klin_NuMI_sys_R2a_DetVarAlternativeRecombination.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_AlternativeRecombination");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_AlternativeRecombination");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarAlternativeRecombination.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.07925e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarAlternativeSCMap( TString mTag ){
	Samples tmpSample("R2a_AlternativeSCMap",FDir+"klin_NuMI_sys_R2a_DetVarAlternativeSCMap.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_AlternativeSCMap");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_AlternativeSCMap");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarAlternativeSCMap.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.086e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarAttenuation( TString mTag ){
	Samples tmpSample("R2a_Attenuation",FDir+"klin_NuMI_sys_R2a_DetVarAttenuation.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_Attenuation");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_Attenuation");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarAttenuation.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.09671e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarCV( TString mTag ){
	Samples tmpSample("R2a_CV",FDir+"klin_NuMI_sys_R2a_DetVarCV.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_CV");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_CV");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarCV.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.0633e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarLYDown( TString mTag ){
	Samples tmpSample("R2a_LYDown",FDir+"klin_NuMI_sys_R2a_DetVarLYDown.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_LYDown");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_LYDown");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarLYDown.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.10012e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarLYRayleigh( TString mTag ){
	Samples tmpSample("R2a_LYRayleigh",FDir+"klin_NuMI_sys_R2a_DetVarLYRayleigh.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_LYRayleigh");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_LYRayleigh");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarLYRayleigh.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.09111e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarWireModThetaXZ( TString mTag ){
	Samples tmpSample("R2a_WireModThetaXZ",FDir+"klin_NuMI_sys_R2a_DetVarWireModThetaXZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_WireModThetaXZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_WireModThetaXZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarWireModThetaXZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.07302e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarWireModThetaYZ( TString mTag ){
	Samples tmpSample("R2a_WireModThetaYZ",FDir+"klin_NuMI_sys_R2a_DetVarWireModThetaYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_WireModThetaYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_WireModThetaYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarWireModThetaYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.09287e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarWireModX( TString mTag ){
	Samples tmpSample("R2a_WireModX",FDir+"klin_NuMI_sys_R2a_DetVarWireModX.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_WireModX");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_WireModX");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarWireModX.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.08573e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2a_DetVarWireModYZ( TString mTag ){
	Samples tmpSample("R2a_WireModYZ",FDir+"klin_NuMI_sys_R2a_DetVarWireModYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2a_WireModYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2a_WireModYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2a_DetVarWireModYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.0437e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_CVRHC( TString mTag ){
	Samples tmpSample("R2b_CVRHC",FDir+"klin_NuMI_sys_R2b_CVRHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_CVRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_CVRHC");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_CVRHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(5.55244e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_DetVarAlternativeRecombination( TString mTag ){
	Samples tmpSample("R2b_AlternativeRecombination",FDir+"klin_NuMI_sys_R2b_DetVarAlternativeRecombination.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_AlternativeRecombination");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_AlternativeRecombination");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_DetVarAlternativeRecombination.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(8.73123e+22);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_DetVarAlternativeSCMap( TString mTag ){
	Samples tmpSample("R2b_AlternativeSCMap",FDir+"klin_NuMI_sys_R2b_DetVarAlternativeSCMap.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_AlternativeSCMap");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_AlternativeSCMap");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_DetVarAlternativeSCMap.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(9.87989e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_DetVarLYDown( TString mTag ){
	Samples tmpSample("R2b_LYDown",FDir+"klin_NuMI_sys_R2b_DetVarLYDown.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_LYDown");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_LYDown");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_DetVarLYDown.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.0563e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_DetVarLYRayleigh( TString mTag ){
	Samples tmpSample("R2b_LYRayleigh",FDir+"klin_NuMI_sys_R2b_DetVarLYRayleigh.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_LYRayleigh");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_LYRayleigh");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_DetVarLYRayleigh.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.0503e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_DetVarWireModThetaXZ( TString mTag ){
	Samples tmpSample("R2b_WireModThetaXZ",FDir+"klin_NuMI_sys_R2b_DetVarWireModThetaXZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_WireModThetaXZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_WireModThetaXZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_DetVarWireModThetaXZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.07254e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_DetVarWireModThetaYZ( TString mTag ){
	Samples tmpSample("R2b_WireModThetaYZ",FDir+"klin_NuMI_sys_R2b_DetVarWireModThetaYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_WireModThetaYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_WireModThetaYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_DetVarWireModThetaYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.04396e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_DetVarWireModX( TString mTag ){
	Samples tmpSample("R2b_WireModX",FDir+"klin_NuMI_sys_R2b_DetVarWireModX.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_WireModX");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_WireModX");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_DetVarWireModX.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.0714e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR2b_DetVarWireModYZ( TString mTag ){
	Samples tmpSample("R2b_WireModYZ",FDir+"klin_NuMI_sys_R2b_DetVarWireModYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R2b_WireModYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R2b_WireModYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R2b_DetVarWireModYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.04725e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_CV( TString mTag ){
	Samples tmpSample("R3b_CV",FDir+"klin_NuMI_sys_R3b_CV.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_CV");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_CV");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_CV.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.45755e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_CVRHC( TString mTag ){
	Samples tmpSample("R3b_CVRHC",FDir+"klin_NuMI_sys_R3b_CVRHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_CVRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_CVRHC");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_CVRHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.98646e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_DetVarAlternativeRecombination( TString mTag ){
	Samples tmpSample("R3b_AlternativeRecombination",FDir+"klin_NuMI_sys_R3b_DetVarAlternativeRecombination.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_AlternativeRecombination");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_AlternativeRecombination");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_DetVarAlternativeRecombination.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.29442e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_DetVarAlternativeSCMap( TString mTag ){
	Samples tmpSample("R3b_AlternativeSCMap",FDir+"klin_NuMI_sys_R3b_DetVarAlternativeSCMap.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_AlternativeSCMap");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_AlternativeSCMap");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_DetVarAlternativeSCMap.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.37818e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_DetVarAttenuation( TString mTag ){
	Samples tmpSample("R3b_Attenuation",FDir+"klin_NuMI_sys_R3b_DetVarAttenuation.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_Attenuation");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_Attenuation");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_DetVarAttenuation.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.45403e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_DetVarLYDown( TString mTag ){
	Samples tmpSample("R3b_LYDown",FDir+"klin_NuMI_sys_R3b_DetVarLYDown.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_LYDown");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_LYDown");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_DetVarLYDown.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.45643e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_DetVarLYRayleigh( TString mTag ){
	Samples tmpSample("R3b_LYRayleigh",FDir+"klin_NuMI_sys_R3b_DetVarLYRayleigh.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_LYRayleigh");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_LYRayleigh");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_DetVarLYRayleigh.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.26938e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_DetVarWireModThetaYZ( TString mTag ){
	Samples tmpSample("R3b_WireModThetaYZ",FDir+"klin_NuMI_sys_R3b_DetVarWireModThetaYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_WireModThetaYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_WireModThetaYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_DetVarWireModThetaYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.45321e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_DetVarWireModX( TString mTag ){
	Samples tmpSample("R3b_WireModX",FDir+"klin_NuMI_sys_R3b_DetVarWireModX.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_WireModX");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_WireModX");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_DetVarWireModX.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.45781e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR3b_DetVarWireModYZ( TString mTag ){
	Samples tmpSample("R3b_WireModYZ",FDir+"klin_NuMI_sys_R3b_DetVarWireModYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R3b_WireModYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R3b_WireModYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R3b_DetVarWireModYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.42872e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_CV( TString mTag ){
	Samples tmpSample("R4_CV",FDir+"klin_NuMI_sys_R4_CV.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_CV");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_CV");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_CV.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.61946e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarAlternativeRecombination( TString mTag ){
	Samples tmpSample("R4_AlternativeRecombination",FDir+"klin_NuMI_sys_R4_DetVarAlternativeRecombination.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_AlternativeRecombination");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_AlternativeRecombination");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarAlternativeRecombination.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.64591e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarAlternativeSCMap( TString mTag ){
	Samples tmpSample("R4_AlternativeSCMap",FDir+"klin_NuMI_sys_R4_DetVarAlternativeSCMap.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_AlternativeSCMap");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_AlternativeSCMap");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarAlternativeSCMap.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.6191e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarAttenuation( TString mTag ){
	Samples tmpSample("R4_Attenuation",FDir+"klin_NuMI_sys_R4_DetVarAttenuation.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_Attenuation");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_Attenuation");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarAttenuation.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.64101e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarLYDown( TString mTag ){
	Samples tmpSample("R4_LYDown",FDir+"klin_NuMI_sys_R4_DetVarLYDown.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_LYDown");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_LYDown");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarLYDown.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.64658e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarLYRayleigh( TString mTag ){
	Samples tmpSample("R4_LYRayleigh",FDir+"klin_NuMI_sys_R4_DetVarLYRayleigh.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_LYRayleigh");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_LYRayleigh");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarLYRayleigh.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.63863e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarWireModThetaXZ( TString mTag ){
	Samples tmpSample("R4_WireModThetaXZ",FDir+"klin_NuMI_sys_R4_DetVarWireModThetaXZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_WireModThetaXZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_WireModThetaXZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarWireModThetaXZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.54594e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarWireModThetaYZ( TString mTag ){
	Samples tmpSample("R4_WireModThetaYZ",FDir+"klin_NuMI_sys_R4_DetVarWireModThetaYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_WireModThetaYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_WireModThetaYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarWireModThetaYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.5514e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarWireModX( TString mTag ){
	Samples tmpSample("R4_WireModX",FDir+"klin_NuMI_sys_R4_DetVarWireModX.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_WireModX");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_WireModX");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarWireModX.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.64641e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4_DetVarWireModYZ( TString mTag ){
	Samples tmpSample("R4_WireModYZ",FDir+"klin_NuMI_sys_R4_DetVarWireModYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4_WireModYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4_WireModYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4_DetVarWireModYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(2.56967e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4a_CVRHC( TString mTag ){
	Samples tmpSample("R4a_CVRHC",FDir+"klin_NuMI_sys_R4a_CVRHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4a_CVRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4a_CVRHC");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4a_CVRHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(4.89738e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4b_CVRHC( TString mTag ){
	Samples tmpSample("R4b_CVRHC",FDir+"klin_NuMI_sys_R4b_CVRHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4b_CVRHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4b_CVRHC");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4b_CVRHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.50337e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4c_CVFHC( TString mTag ){
	Samples tmpSample("R4c_CVFHC",FDir+"klin_NuMI_sys_R4c_CVFHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4c_CVFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4c_CVFHC");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4c_CVFHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(8.07896e+20);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR4d_CVFHC( TString mTag ){
	Samples tmpSample("R4d_CVFHC",FDir+"klin_NuMI_sys_R4d_CVFHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R4d_CVFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R4d_CVFHC");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R4d_CVFHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.30579e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_CV( TString mTag ){
	Samples tmpSample("R5_CV",FDir+"klin_NuMI_sys_R5_CV.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_CV");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_CV");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_CV.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.45622e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_CVFHC( TString mTag ){
	Samples tmpSample("R5_CVFHC",FDir+"klin_NuMI_sys_R5_CVFHC.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_CVFHC");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_CVFHC");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_CVFHC.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.80043e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarAlternativeRecombination( TString mTag ){
	Samples tmpSample("R5_AlternativeRecombination",FDir+"klin_NuMI_sys_R5_DetVarAlternativeRecombination.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_AlternativeRecombination");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_AlternativeRecombination");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarAlternativeRecombination.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(4.27428e+22);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarAlternativeSCMap( TString mTag ){
	Samples tmpSample("R5_AlternativeSCMap",FDir+"klin_NuMI_sys_R5_DetVarAlternativeSCMap.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_AlternativeSCMap");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_AlternativeSCMap");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarAlternativeSCMap.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(4.28275e+22);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarAttenuation( TString mTag ){
	Samples tmpSample("R5_Attenuation",FDir+"klin_NuMI_sys_R5_DetVarAttenuation.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_Attenuation");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_Attenuation");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarAttenuation.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.4548e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarLYDown( TString mTag ){
	Samples tmpSample("R5_LYDown",FDir+"klin_NuMI_sys_R5_DetVarLYDown.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_LYDown");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_LYDown");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarLYDown.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.44829e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarLYRayleigh( TString mTag ){
	Samples tmpSample("R5_LYRayleigh",FDir+"klin_NuMI_sys_R5_DetVarLYRayleigh.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_LYRayleigh");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_LYRayleigh");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarLYRayleigh.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.46162e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarWireModThetaXZ( TString mTag ){
	Samples tmpSample("R5_WireModThetaXZ",FDir+"klin_NuMI_sys_R5_DetVarWireModThetaXZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_WireModThetaXZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_WireModThetaXZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarWireModThetaXZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.41448e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarWireModThetaYZ( TString mTag ){
	Samples tmpSample("R5_WireModThetaYZ",FDir+"klin_NuMI_sys_R5_DetVarWireModThetaYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_WireModThetaYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_WireModThetaYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarWireModThetaYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.4308e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarWireModX( TString mTag ){
	Samples tmpSample("R5_WireModX",FDir+"klin_NuMI_sys_R5_DetVarWireModX.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_WireModX");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_WireModX");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarWireModX.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.44577e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};


Samples LoadR5_DetVarWireModYZ( TString mTag ){
	Samples tmpSample("R5_WireModYZ",FDir+"klin_NuMI_sys_R5_DetVarWireModYZ.root","singlephotonana/vertex_tree",COMMONCUT);

	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "R5_WireModYZ");
	tmpSample.AddFriendViaTag_v2(TrainDir,  "Pi0CosmicClassifier", "R5_WireModYZ");
//	tmpSample.AddFriend(FDir+"klin_NuMI_sys_R5_DetVarWireModYZ.root", "eventweight_tree");//gonna need additional weights if not for DetVar


//	tmpSample.SetScale(3);
	tmpSample.SetPOT(1.40967e+21);
//	tmpSample.SetWeight(MakeSafeWgtName("weightSplineTimesTune")); //DetVar samples don't need this

	return tmpSample;
};




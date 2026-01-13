#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT_s="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir_s="/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/";
static const TString TrainDir_s="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRuns_Sys/";

//Forget about light mass axion for now
//Samples LoadAxions003( TString mTag ){
//	Samples axion("0.03 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma003_v1_zlt40m.root","singlephotonana/vertex_tree",COMMONCUT_s);
//
//	TString BDTFileTag = "Axionma003";
//	TString ClassifierTag = "PionClassifier";
//	TString frdTFile = BDTTrainingDir+mTag+"/"+BDTTrainingTag+mTag+ClassifierTag + "_"+BDTFileTag+"_app.root";
//	TString frdT = BDTFileTag + "_"+ BDTTrainingTag + mTag + ClassifierTag;
//
//	if(!gSystem->AccessPathName(frdTFile)){
//		axion.AddFriend(frdTFile, frdT);
//	} else{
//		std::cout<<frdTFile<<" does not exist"<<std::endl;
//	}
//
//	ClassifierTag = "NueCCClassifier";
//	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, mTag);
//
//
//	ClassifierTag = "CosmicClassifier";
//	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, mTag);
//
////	ClassifierTag = "AxionLikeClassifier";
////	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, mTag);
//
////	axion.SetScale(3*2.0/58560);//for regular ma03 sample
//	axion.SetScale(5000.0/490000*5);
//	axion.SetPlotStyle(kOrange, 0);
//	axion.SetPOT(2e21);
//	
//	return axion;
//};
//
//Samples LoadAxions003T( TString mTag ){
//	Samples axion("0.03 GeV Axion (Training)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma003_v1_zlt40m.root","singlephotonana/vertex_tree","subrun_number%3>0");
//
//	TString BDTFileTag = "Axionma003";
//	TString ClassifierTag = "PionClassifier";
//	TString frdTFile = BDTTrainingDir+mTag+"/"+BDTTrainingTag+mTag+ClassifierTag + "_"+BDTFileTag+"_app.root";
//	TString frdT = BDTFileTag + "_"+ BDTTrainingTag + mTag + ClassifierTag;
//
//	if(!gSystem->AccessPathName(frdTFile)){
//		axion.AddFriend(frdTFile, frdT);
//	} else{
//		std::cout<<frdTFile<<" does not exist"<<std::endl;
//	}
//
//	ClassifierTag = "NueCCClassifier";
//	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, mTag);
//
//
//	ClassifierTag = "CosmicClassifier";
//	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, mTag);
//
////	ClassifierTag = "AxionLikeClassifier";
////	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, mTag);
//
////	axion.SetScale(3*2.0/58560);//for regular ma03 sample
//	axion.SetScale(5000.0/490000*5*(1/ 1.9887640));
//	axion.SetPlotStyle(kOrange+10, 0);
//	axion.SetPOT(2e21);
//	
//	return axion;
//};



Samples LoadAxions0146( TString mTag ){
	Samples axion("0.146 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma0146_v1_zlt40m.root","singlephotonana/vertex_tree",COMMONCUT_s);

	axion.SetScale(5000.0/357000*5);
	axion.SetPlotStyle(kTeal, 0);
	axion.SetPOT(2e21);
	
	//Add Friends
	axion.AddFriendViaTag_v2(TrainDir_s,  mTag+"PionClassifier",			"Axionma0146");
	axion.AddFriendViaTag_v2(TrainDir_s,  mTag+"PionAccurateClassifier",	"Axionma0146");


	return axion;
};

Samples LoadAxions084( TString mTag ){
	Samples axion("0.84 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma084_v1_zlt40m.root","singlephotonana/vertex_tree",COMMONCUT_s);

	axion.SetScale(5000.0/468000*5);
	axion.SetPlotStyle(kMagenta, 0);
	axion.SetPOT(2e21);

	//Add Friends
	axion.AddFriendViaTag_v2(TrainDir_s,  mTag+"PionClassifier",			"Axionma084");
	axion.AddFriendViaTag_v2(TrainDir_s,  mTag+"PionAccurateClassifier",	"Axionma084");


	return axion;
};


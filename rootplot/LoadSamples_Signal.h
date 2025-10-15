#include "./utility/ConfigureSamples.h"
#include "global_tag.h"
//
//Configure class Samples: name, input file, tree name, cut
//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

//Global AmassBDTTag for BDT variables

Samples LoadAxions003( TString AmassBDTTag ){
	Samples axion("0.03 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma003_v1_zlt40m.root","singlephotonana/vertex_tree","subrun_number%3==0");

	TString BDTFileTag = "Axionma003";
	TString ClassifierTag = "PionClassifier";
	TString frdTFile = BDTTrainingDir+AmassBDTTag+"/"+BDTTrainingTag+AmassBDTTag+ClassifierTag + "_"+BDTFileTag+"_app.root";
	TString frdT = BDTFileTag + "_"+ BDTTrainingTag + AmassBDTTag + ClassifierTag;

	if(!gSystem->AccessPathName(frdTFile)){
		axion.AddFriend(frdTFile, frdT);
	} else{
		std::cout<<frdTFile<<" does not exist"<<std::endl;
	}

	ClassifierTag = "NueCCClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	axion.SetScale(3*2.0/58560);//for regular ma03 sample
	axion.SetScale(5000.0/490000*5);
	axion.SetPlotStyle(kOrange, 0);
	axion.SetPOT(2e21);
	
	return axion;
};

Samples LoadAxions003T( TString AmassBDTTag ){
	Samples axion("0.03 GeV Axion (Training)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma003_v1_zlt40m.root","singlephotonana/vertex_tree","subrun_number%3>0");

	TString BDTFileTag = "Axionma003";
	TString ClassifierTag = "PionClassifier";
	TString frdTFile = BDTTrainingDir+AmassBDTTag+"/"+BDTTrainingTag+AmassBDTTag+ClassifierTag + "_"+BDTFileTag+"_app.root";
	TString frdT = BDTFileTag + "_"+ BDTTrainingTag + AmassBDTTag + ClassifierTag;

	if(!gSystem->AccessPathName(frdTFile)){
		axion.AddFriend(frdTFile, frdT);
	} else{
		std::cout<<frdTFile<<" does not exist"<<std::endl;
	}

	ClassifierTag = "NueCCClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	axion.SetScale(3*2.0/58560);//for regular ma03 sample
	axion.SetScale(5000.0/490000*5*(1/ 1.9887640));
	axion.SetPlotStyle(kOrange+10, 0);
	axion.SetPOT(2e21);
	
	return axion;
};



Samples LoadAxions0146( TString AmassBDTTag ){
	Samples axion("0.146 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma0146_v1_zlt40m.root","singlephotonana/vertex_tree","subrun_number%3==0");

	TString BDTFileTag = "Axionma0146";
	TString ClassifierTag = "PionClassifier";
	TString frdTFile = BDTTrainingDir+AmassBDTTag+"/"+BDTTrainingTag+AmassBDTTag+ClassifierTag + "_"+BDTFileTag+"_app.root";
	TString frdT = BDTFileTag + "_"+ BDTTrainingTag + AmassBDTTag + ClassifierTag;

	if(!gSystem->AccessPathName(frdTFile)){
		axion.AddFriend(frdTFile, frdT);
	} else{
		std::cout<<frdTFile<<" does not exist"<<std::endl;
	}

	ClassifierTag = "NueCCClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "CosmicClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	axion.SetScale(3*2.0/58560);//for regular ma03 sample
	axion.SetScale(5000.0/357000*5);
	axion.SetPlotStyle(kTeal, 0);
	axion.SetPOT(2e21);
	
	return axion;
};

Samples LoadAxions084( TString AmassBDTTag ){
	Samples axion("0.84 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma084_v1_zlt40m.root","singlephotonana/vertex_tree","subrun_number%3==0");

	TString BDTFileTag = "Axionma084";
	TString ClassifierTag = "PionClassifier";
	TString frdTFile = BDTTrainingDir+AmassBDTTag+"/"+BDTTrainingTag+AmassBDTTag+ClassifierTag + "_"+BDTFileTag+"_app.root";
	TString frdT = BDTFileTag + "_"+ BDTTrainingTag + AmassBDTTag + ClassifierTag;

	if(!gSystem->AccessPathName(frdTFile)){
		axion.AddFriend(frdTFile, frdT);
	} else{
		std::cout<<frdTFile<<" does not exist"<<std::endl;
	}

	ClassifierTag = "NueCCClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	axion.SetScale(3*2.0/58560);//for regular ma03 sample
	axion.SetScale(5000.0/468000*5);
	axion.SetPlotStyle(kMagenta, 0);
	axion.SetPOT(2e21);
	
	return axion;
};


#include "./utility/ConfigureSamples.h"
//
//Configure class Samples: name, input file, tree name, cut
//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

//scalings_run1 = { "nu":1./2.35e21, "dirt":1.0*0.75/1.55e21, "beamoff": 0.98*(6230439.0/9186361.390000)}
//scalings_run3 = { "nu":1./(1.993661e21), "dirt":1.0*0.35/1.020e21, "beamoff": 0.98*(10714868.0/34147459.925000)}

//Global AmassBDTTag for BDT variables
TString BDTTrainingTag = "NuMIRHCRun3Pre16880AxionV3";
TString BDTTrainingDir = "../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/" + BDTTrainingTag ;

Samples LoadAxions( TString AmassBDTTag ){
	Samples axion("Axion"+AmassBDTTag,"/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_"+AmassBDTTag+"_v1_zlt40m.root","singlephotonana/vertex_tree","Entry$%3==0");

	TString BDTFileTag = "Axion"+AmassBDTTag;
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

	ClassifierTag = "AxionLikeClassifier";
	axion.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	axion.SetScale(3*2.0/58560);//for regular ma03 sample
	axion.SetScale(5000.0*2/391750);
	axion.SetPlotStyle(kYellow-3, 1001);
	axion.SetPOT(2e21);
	
	return axion;
};

//New Categories!
Samples LoadRun3Onepi0( TString AmassBDTTag ){
	Samples tmpSample("1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&Entry$%3==0");

	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.53689e21);
	tmpSample.SetScale(3);//Have used half for training;

	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "AxionLikeClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);
	//Add Friends ~ Finish


	return tmpSample;
};




Samples LoadRun3Twopi0( TString AmassBDTTag ){
	Samples tmpSample("2#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==2");
	
	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "AxionLikeClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);
	//Add Friends ~ Finish


	tmpSample.SetPlotStyle(kBlue-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.53689e21);

	return tmpSample;
};


Samples LoadRun3OtherCC( TString AmassBDTTag ){

	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","mctruth_cc_or_nc==0&&!(mctruth_num_exiting_pi0>0 && mctruth_num_exiting_pi0<3) && Entry$%3==0");

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.53689e21);
	tmpSample.SetScale(3);//Have used half for training;

	
	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "AxionLikeClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	return tmpSample;
};


Samples LoadRun3OtherNC( TString AmassBDTTag ){
	Samples tmpSample("Other NC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","mctruth_cc_or_nc==1&& !(mctruth_num_exiting_pi0>0 && mctruth_num_exiting_pi0<3)");
	
	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "AxionLikeClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	tmpSample.SetPlotStyle(kRed-6,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.53689e21);

	return tmpSample;
};


Samples LoadRun3Dirt( TString AmassBDTTag ){

	Samples tmpSample("Dirt (OutsideCryo)  x.52","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3dirt_luis_goodweight_2s0t.root","vertex_tree","run_number<16880");
	
	//Add Friends ~ Start
	TString BDTFileTag = "Dirt";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "AxionLikeClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	tmpSample.SetPlotStyle(kOrange-7, 1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good");
	tmpSample.SetPOT(6.01415e20);
	tmpSample.SetScale(0.52);

	return tmpSample;
};


//Data set
Samples LoadRun3Pre16880RHCData( TString AmassBDTTag ){

	Samples data("NuMI Data R3b RHC < 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3data_luis_full_2s0t.root","vertex_tree","run_number<16880");
	data.SetPOT(4.108e20);

	//Add Friends ~ Start
	TString BDTFileTag = "NuMIDataR3";
	TString ClassifierTag = "PionClassifier";

	data.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	data.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	data.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "AxionLikeClassifier";
	data.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish

	return data;
};

//Data set
Samples LoadRun3Pre16880EXT( TString AmassBDTTag ){

	Samples ext("Run3b EXT < 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3EXT_luis_2s0t.root","vertex_tree","run_number<16880 && Entry$%3==0");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(4.22e20*19381337.925/8742594.0);//from POT tool, 9.35e20
	ext.SetScale(0.98);
	ext.SetScale(3);//Have used 2/3 for training;

	//Add Friends ~ Start
	TString BDTFileTag = "NuMIextRun3bPre16880";
	TString ClassifierTag = "PionClassifier";

	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "CosmicClassifier";
	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "AxionLikeClassifier";
	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	return ext;
}

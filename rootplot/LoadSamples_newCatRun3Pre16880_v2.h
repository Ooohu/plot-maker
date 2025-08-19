#include "./utility/ConfigureSamples.h"
//Compare to LoadSamples_newCatRun3Pre16880.h
//Updates the scaling & colors of samples
//
//Configure class Samples: name, input file, tree name, cut
//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

//scalings_run1 = { "nu":1./2.35e21, "dirt":1.0*0.75/1.55e21, "beamoff": 0.98*(6230439.0/9186361.390000)}
//scalings_run3 = { "nu":1./(1.993661e21), "dirt":1.0*0.35/1.020e21, "beamoff": 0.98*(10714868.0/34147459.925000)}

//Global AmassBDTTag for BDT variables
TString BDTTrainingTag = "NuMIRHCRun3Pre16880AxionV3";
TString BDTTrainingDir = "../../BDTTool/hellstroms_hive/hive/build_axion_general_v2/" + BDTTrainingTag ;

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
	axion.SetScale(5000.0/49000);
	axion.SetPlotStyle(kOrange, 0);
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
	axion.SetScale(5000.0/35700);
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
	axion.SetScale(5000.0/46800);
	axion.SetPlotStyle(kMagenta, 0);
	axion.SetPOT(2e21);
	
	return axion;
};



//New Categories!
Samples LoadRun3All( TString AmassBDTTag ){ // FOR CHECKING
	Samples tmpSample("All MC Backgrounds:", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","subrun_number%3==0");

	tmpSample.SetPlotStyle(kRed-2,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used half for training;

	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);
	//Add Friends ~ Finish


	return tmpSample;
};


Samples LoadRun3Onepi0( TString AmassBDTTag ){
	Samples tmpSample("1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&subrun_number%3==0");

	tmpSample.SetPlotStyle(kRed-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used half for training;

	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);
	//Add Friends ~ Finish


	return tmpSample;
};


Samples LoadRun3NueCC( TString AmassBDTTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && subrun_number%3==0");

	tmpSample.SetPlotStyle(kGreen-8,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used half for training;

	
	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	return tmpSample;
};

Samples LoadRun3NumuCC( TString AmassBDTTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && subrun_number%3==0");

	tmpSample.SetPlotStyle(kBlue-6,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used half for training;

	
	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	return tmpSample;
};




Samples LoadRun3OtherCC( TString AmassBDTTag ){//empty

	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& subrun_number%3==0");

	tmpSample.SetPlotStyle(kGreen-2,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);//Have used half for training;

	
	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	return tmpSample;
};


Samples LoadRun3InCryoOther( TString AmassBDTTag ){
	Samples tmpSample("InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3MCoverlay_reweight_luis_goodweight_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && subrun_number%3==0");
	//Add Friends ~ Start
	TString BDTFileTag = "NuBkg";
	TString ClassifierTag = "PionClassifier";

	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);


	ClassifierTag = "CosmicClassifier";
	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	tmpSample.SetPlotStyle(kMagenta+3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);
	tmpSample.SetScale(2.9193416);

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

//	ClassifierTag = "AxionLikeClassifier";
//	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

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

//	ClassifierTag = "AxionLikeClassifier";
//	data.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish

	return data;
};

//Data set
Samples LoadRun3Pre16880EXT( TString AmassBDTTag ){

	Samples ext("Run3b EXT < 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3EXT_luis_2s0t.root","vertex_tree","run_number<16880 && subrun_number%3==0");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(4.22e20*19381337.925/8742594.0);//from POT tool, 9.35e20
	ext.SetScale(0.98);
	ext.SetScale(2.9566613);//Have used 2/3 for training;

	//Add Friends ~ Start
	TString BDTFileTag = "NuMIextRun3bPre16880";
	TString ClassifierTag = "PionClassifier";

	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "CosmicClassifier";
	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	return ext;
}

Samples LoadRun2aEXT( TString AmassBDTTag ){

	Samples ext("Run2a EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2aEXT_2s0t.root","vertex_tree","subrun_number%3==0");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(2.99e20*1.76e7/7.13e6);//from POT tool, 9.35e20
	ext.SetScale(0.98);
	ext.SetScale(3.1602317);//Have used 2/3 for training;

	//Add Friends ~ Start
	TString BDTFileTag = "NuMIextRun2a";
	TString ClassifierTag = "PionClassifier";

	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "NueCCClassifier";
	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	ClassifierTag = "CosmicClassifier";
	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

//	ClassifierTag = "AxionLikeClassifier";
//	ext.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);

	//Add Friends ~ Finish


	return ext;
}


//DONT NEED THE FOLLOWING
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

//	ClassifierTag = "AxionLikeClassifier";
//	tmpSample.AddFriendViaTag( BDTFileTag, ClassifierTag, BDTTrainingDir, BDTTrainingTag, AmassBDTTag);
	//Add Friends ~ Finish


	tmpSample.SetPlotStyle(kBlue-3,1001);
	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(1.99e21);

	return tmpSample;
};




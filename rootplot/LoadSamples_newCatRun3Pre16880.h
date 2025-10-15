#include "./utility/ConfigureSamples.h"
#include "global_tag.h"
//Compare to LoadSamples_newCatRun3Pre16880.h
//Updates the scaling & colors of samples
//
//Configure class Samples: name, input file, tree name, cut
//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

//scalings_run1 = { "nu":1./2.35e21, "dirt":1.0*0.75/1.55e21, "beamoff": 0.98*(6230439.0/9186361.390000)}
//scalings_run3 = { "nu":1./(1.993661e21), "dirt":1.0*0.35/1.020e21, "beamoff": 0.98*(10714868.0/34147459.925000)}

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


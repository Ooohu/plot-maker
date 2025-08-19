#include "./utility/ConfigureSamples.h"
//

//Global AmassBDTTag for BDT variables
TString BDTTrainingTag = "NuMIFHCRun2a";
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
Samples LoadRun2aAll( TString AmassBDTTag ){ // FOR CHECKING
	Samples tmpSample("All MC Backgrounds:", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","subrun_number%3==0");

	tmpSample.SetPlotStyle(kRed-2,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;

	//Add reweighting friend
	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","eventweight_tree");

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


Samples LoadRun2aOnepi0( TString AmassBDTTag ){
	Samples tmpSample("1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&subrun_number%3==0");

	tmpSample.SetPlotStyle(kRed-3,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;


	//Add reweighting friend
	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","eventweight_tree");

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


Samples LoadRun2aNueCC( TString AmassBDTTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && subrun_number%3==0");

	tmpSample.SetPlotStyle(kGreen-8,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;

	//Add reweighting friend
	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","eventweight_tree");

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

Samples LoadRun2aNumuCC( TString AmassBDTTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && subrun_number%3==0");

	tmpSample.SetPlotStyle(kBlue-6,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;

	//Add reweighting friend
	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","eventweight_tree");
	
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




Samples LoadRun2aOtherCC( TString AmassBDTTag ){//NOT USED

	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& subrun_number%3==0");

	tmpSample.SetPlotStyle(kGreen-2,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);//Have used half for training;

	//Add reweighting friend
	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","eventweight_tree");
	
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


Samples LoadRun2aInCryoOther( TString AmassBDTTag ){
	Samples tmpSample("InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && subrun_number%3==0");
	tmpSample.SetPlotStyle(kMagenta+3,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(2.48E+21);
	tmpSample.SetScale(3.0718182);

	//Add reweighting friend
	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_FHC_2s0t.root","eventweight_tree");

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


Samples LoadRun2aDirt( TString AmassBDTTag ){

	Samples tmpSample("Dirt (OutsideCryo) x? ","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2adirt_FHC_2s0t.root","vertex_tree","1");

	tmpSample.SetPlotStyle(kOrange-7, 1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune");
	tmpSample.SetPOT(8.6e19);
//	tmpSample.SetScale(0.61);

	//Add reweighting friend
//	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2adirt_FHC_2s0t.root","eventweight_tree");


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



	return tmpSample;
};


//Data set
Samples LoadRun2aFHCData( TString AmassBDTTag ){

	Samples data("NuMI Data R2a FHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2adata_2s0t.root","vertex_tree","run_number>8782 && run_number<10140");
	data.SetPOT(1.46e20);

	//Add Friends ~ Start
	TString BDTFileTag = "NuMIDataR2aFHC";
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
Samples LoadRun2aEXT( TString AmassBDTTag ){

	Samples ext("Run2a EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2aEXT_2s0t.root","vertex_tree","subrun_number%3==0");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(2.99e20*1.76e7/7.13e6);
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


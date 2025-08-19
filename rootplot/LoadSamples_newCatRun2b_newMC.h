#include "./utility/ConfigureSamples.h"
//
//Configure class Samples: name, input file, tree name, cut
//DIR /pnfs/uboone/persistent/users/klin/MCC9/ntuples

//scalings_run1 = { "nu":1./5.63E+21, "dirt":1.0*0.75/1.55e21, "beamoff": 0.98*(6230439.0/9186361.390000)}
//scalings_run3 = { "nu":1./(1.993661e21), "dirt":1.0*0.35/1.020e21, "beamoff": 0.98*(10714868.0/34147459.925000)}

//Global AmassBDTTag for BDT variables
TString BDTTrainingTag = "NuMIFHCRun2b";
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
Samples LoadRun2bAll( TString AmassBDTTag ){ // FOR CHECKING
	Samples tmpSample("All MC Backgrounds:", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","subrun_number%3==0");

	tmpSample.SetPlotStyle(kRed-2,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;


	//Add reweighting friend
//	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","eventweight_tree");

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


Samples LoadRun2bOnepi0( TString AmassBDTTag ){
	Samples tmpSample("1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&subrun_number%3==0");

	tmpSample.SetPlotStyle(kRed-3,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;


	//Add reweighting friend
//	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","eventweight_tree");

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


Samples LoadRun2bNueCC( TString AmassBDTTag ){

	Samples tmpSample("CC#nu_{e}/#bar{#nu_{e}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==12 && subrun_number%3==0");

	tmpSample.SetPlotStyle(kGreen-8,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//Add reweighting friend
//	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","eventweight_tree");

	
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

Samples LoadRun2bNumuCC( TString AmassBDTTag ){

	Samples tmpSample("CC#nu_{#mu}/#bar{#nu_{#mu}}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1)&&mctruth_cc_or_nc==0&& fabs(mctruth_nu_pdg)==14 && subrun_number%3==0");

	tmpSample.SetPlotStyle(kBlue-6,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//Add reweighting friend
//	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","eventweight_tree");
	
	
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




Samples LoadRun2bOtherCC( TString AmassBDTTag ){//empty

	Samples tmpSample("Other CC", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==0&&!(fabs(mctruth_nu_pdg)==12) &&!(fabs(mctruth_nu_pdg)==14)&& subrun_number%3==0");

	tmpSample.SetPlotStyle(kGreen-2,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);//Have used half for training;

	//Add reweighting friend
//	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","eventweight_tree");
	
	
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


Samples LoadRun2bInCryoOther( TString AmassBDTTag ){
	Samples tmpSample("InCryoOther", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","vertex_tree","!(mctruth_num_exiting_pi0==1 ) && mctruth_cc_or_nc==1 && subrun_number%3==0");
	tmpSample.SetPlotStyle(kMagenta+3,1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(5.63E+21);
	tmpSample.SetScale(2.9823352);

	//Add reweighting friend
//	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","eventweight_tree");
	
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


Samples LoadRun2bDirt( TString AmassBDTTag ){

	Samples tmpSample("Dirt (OutsideCryo) x? ","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2bdirt_RHC_2s0t.root","vertex_tree","1");
	
	tmpSample.SetPlotStyle(kOrange-7, 1001);
//	tmpSample.SetWeight("ppfx_cv*weightSplineTimesTune");
	tmpSample.SetPOT(9.17e19);
//	tmpSample.SetScale(0.47);

	//Add reweighting friend
//	tmpSample.AddFriend( "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2MCOverlay_LightYieldFix_RHC_2s0t.root","eventweight_tree");
	

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
Samples LoadRun2bRHCData( TString AmassBDTTag ){

	Samples data("NuMI Data R2b RHC","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2bdata_2s0t.root","vertex_tree","1");
	data.SetPOT(1.29e20);

	//Add Friends ~ Start
	TString BDTFileTag = "NuMIDataR2bRHC";
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
Samples LoadRun2bEXT( TString AmassBDTTag ){

	Samples ext("Run2b EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run2bEXT_2s0t.root","vertex_tree","subrun_number%3==0");
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(1.08E20*1.10e7/2.26e6);//from POT tool, 9.35e20
	ext.SetScale(0.98);
	ext.SetScale(2.682);//Have used 2/3 for training;

	//Add Friends ~ Start
	TString BDTFileTag = "NuMIextRun2b";
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


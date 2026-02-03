#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir="/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/";
//static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRuns_2s0t_Jan2026/";
static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIAllMC_2s0t_Jan2026/";



//Data set
Samples LoadRun1FHCData( TString mTag ){

	Samples data("Data NuMI Run1 FHC", FDir+"gleeNtuples_numi_run1data_luis_full_2s0t.root","vertex_tree","(run_number<6748)||(run_number==6748 && subrun_number<22)");
	data.SetPOT(2.37e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier",			"NuMIDataR1");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR1");

	return data;
};

Samples LoadRun2aFHCData( TString mTag ){

	Samples data("Data NuMI Run2a FHC",FDir+"gleeNtuples_numi_run2adata_2s0t.root","vertex_tree","(run_number<9931)");
	data.SetPOT(1.46e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR2a");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR2a");

	return data;
};

Samples LoadRun2bRHCData( TString mTag ){

	Samples data("Data NuMI Run2b RHC",FDir+"gleeNtuples_numi_run2bdata_2s0t.root","vertex_tree","1");
	y
	data.SetPOT(1.26e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR2b");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR2b");

	return data;
};

Samples LoadRun3Pre16880RHCData( TString AmassBDTTag ){

	Samples data("NuMI Data R3b RHC < 16880 run","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run3data_luis_full_2s0t.root","vertex_tree","run_number<16880");
	data.SetPOT(4.108e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR3b");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR3b");

	return data;
};


Samples LoadRun4aRHCData( TString mTag ){

	Samples data("Data NuMI Run4a RHC",FDir+"gleeNtuples_numi_run4adata_2s0t.root","vertex_tree","");
	data.SetPOT(8.08e18);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR4a");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR4a");

	return data;
};


Samples LoadRun4bRHCData( TString mTag ){

	Samples data("Data NuMI Run4b RHC",FDir+"gleeNtuples_numi_run4bdata_2s0t.root","vertex_tree","");
	data.SetPOT(2.78e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR4b");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR4b");

	return data;
};


Samples LoadRun4cRHCData( TString mTag ){

	Samples data("Data NuMI Run4c RHC",FDir+"gleeNtuples_numi_run4cdata_2s0t.root","vertex_tree","run_number<21396");
	data.SetPOT(1.68e19);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR4c");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR4c");

	return data;
};



Samples LoadRun4cFHCData( TString mTag ){

	Samples data("Data NuMI Run4c FHC",FDir+"gleeNtuples_numi_run4cdata_2s0t.root","vertex_tree","run_number>21396");
	data.SetPOT(1.26e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR4c");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR4c");

	return data;
};


Samples LoadRun4dFHCData( TString mTag ){

	Samples data("Data NuMI Run4d FHC",FDir+"gleeNtuples_numi_run4ddata_2s0t.root","vertex_tree","");
	data.SetPOT(8.28e19);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR4d");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR4d");

	return data;
};



Samples LoadRun5FHCData( TString mTag ){

	Samples data("Data NuMI Run5 FHC",FDir+"gleeNtuples_numi_run5data_final_2s0t.root","vertex_tree","");
	data.SetPOT(2.35e20);

	//Add Friends
	data.AddFriendViaTag_v2(TrainDir, "Pi0CosmicClassifier",			"NuMIDataR5");
	data.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIDataR5");

	return data;
};







//Data set
Samples LoadRun1EXT( TString mTag ){

	Samples ext("Run1 EXT","/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/gleeNtuples_numi_run1EXT_full_2s0t.root","vertex_tree",COMMONCUT);
	ext.SetPlotStyle(kGreen-6, 3333);
	ext.SetPOT(2.76e20*9.25e6/6.62e6);
	ext.SetScale(0.98*2.8049536);

	//Add Friends
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier",			"NuMIExtR1");
	ext.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier",	"NuMIExtR1");


	return ext;
}


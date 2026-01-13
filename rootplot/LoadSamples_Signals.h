#include "./utility/ConfigureSamples.h"

//static gives internal linkage
static const TString COMMONCUT_s="subrun_number%3==0";//Take 1/3 of files for plotting, 2/3 for training
static const TString FDir_s="/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/";
static const TString TrainDir_s="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRuns_2s0t_Jan2026/";
//static const TString TrainDir_s="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIRuns_Sys/";

//Forget about light mass axion for now


Samples LoadAxions011(TString mTag){
    Samples axion("0.11 GeV Axion (RND)",
                  "/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma011_v1_zlt40m.root",
                  "singlephotonana/vertex_tree", COMMONCUT_s);

    axion.SetScale(5000.0/357000*5);
    axion.SetPlotStyle(kOrange, 0);
    axion.SetPOT(2e21);

//    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionClassifier", "Axionma011");
    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionAccurateClassifier", "Axionma011");

    return axion;
};

Samples LoadAxions0146(TString mTag){
    Samples axion("0.146 GeV Axion (RND)",
                  "/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma0146_v1_zlt40m.root",
                  "singlephotonana/vertex_tree", COMMONCUT_s);

    axion.SetScale(5000.0/357000*5);
    axion.SetPlotStyle(kTeal, 0);
    axion.SetPOT(2e21);

//    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionClassifier", "Axionma0146");
    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionAccurateClassifier", "Axionma0146");

    return axion;
};

Samples LoadAxions03(TString mTag){
    Samples axion("0.3 GeV Axion (RND)",
                  "/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma03_v1_zlt40m.root",
                  "singlephotonana/vertex_tree", COMMONCUT_s);

    axion.SetScale(5000.0/357000*5);
    axion.SetPlotStyle(kOrange, 0);
    axion.SetPOT(2e21);

//    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionClassifier", "Axionma03");
    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionAccurateClassifier", "Axionma03");

    return axion;
};

Samples LoadAxions04(TString mTag){
    Samples axion("0.4 GeV Axion (RND)",
                  "/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma04_v1_zlt40m.root",
                  "singlephotonana/vertex_tree", COMMONCUT_s);

    axion.SetScale(5000.0/357000*5);
    axion.SetPlotStyle(kOrange, 0);
    axion.SetPOT(2e21);

//    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionClassifier", "Axionma04");
    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionAccurateClassifier", "Axionma04");

    return axion;
};

Samples LoadAxions052(TString mTag){
    Samples axion("0.52 GeV Axion (RND)",
                  "/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma052_v1_zlt40m.root",
                  "singlephotonana/vertex_tree", COMMONCUT_s);

    axion.SetScale(5000.0/357000*5);
    axion.SetPlotStyle(kOrange, 0);
    axion.SetPOT(2e21);

//    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionClassifier", "Axionma052");
    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionAccurateClassifier", "Axionma052");

    return axion;
};

Samples LoadAxions068(TString mTag){
    Samples axion("0.68 GeV Axion (RND)",
                  "/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma068_v1_zlt40m.root",
                  "singlephotonana/vertex_tree", COMMONCUT_s);

    axion.SetScale(5000.0/357000*5);
    axion.SetPlotStyle(kOrange, 0);
    axion.SetPOT(2e21);

//    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionClassifier", "Axionma068");
    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionAccurateClassifier", "Axionma068");

    return axion;
};

Samples LoadAxions084(TString mTag){
    Samples axion("0.84 GeV Axion (RND)",
                  "/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma084_v1_zlt40m.root",
                  "singlephotonana/vertex_tree", COMMONCUT_s);

    axion.SetScale(5000.0/357000*5);
    axion.SetPlotStyle(kMagenta, 0);
    axion.SetPOT(2e21);

//    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionClassifier", "Axionma084");
    axion.AddFriendViaTag_v2(TrainDir_s, mTag+"PionAccurateClassifier", "Axionma084");

    return axion;
};

//Samples LoadAxions0146( TString mTag ){
//	Samples axion("0.146 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma0146_v1_zlt40m.root","singlephotonana/vertex_tree",COMMONCUT_s);
//
//	axion.SetScale(5000.0/357000*5);
//	axion.SetPlotStyle(kTeal, 0);
//	axion.SetPOT(2e21);
//	
//	//Add Friends
//	axion.AddFriendViaTag_v2(TrainDir_s,  mTag+"PionClassifier",			"Axionma0146");
//	axion.AddFriendViaTag_v2(TrainDir_s,  mTag+"PionAccurateClassifier",	"Axionma0146");
//
//
//	return axion;
//};
//
//Samples LoadAxions084( TString mTag ){
//	Samples axion("0.84 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma084_v1_zlt40m.root","singlephotonana/vertex_tree",COMMONCUT_s);
//
//	axion.SetScale(5000.0/468000*5);
//	axion.SetPlotStyle(kMagenta, 0);
//	axion.SetPOT(2e21);
//
//	//Add Friends
//	axion.AddFriendViaTag_v2(TrainDir_s,  mTag+"PionClassifier",			"Axionma084");
//	axion.AddFriendViaTag_v2(TrainDir_s,  mTag+"PionAccurateClassifier",	"Axionma084");
//
//
//	return axion;
//};


#include "./utility/ConfigureSamples.h"


static const TString TrainDir="/exp/uboone/app/users/klin/2024Jun_ub_AxionAnalysis/BDTTool/hellstroms_hive/hive/build_axion_general_v2/NuMIFHCRuns_cleanPi0Train/";


Samples LoadAxions084( TString mTag ){
	Samples axion("0.84 GeV Axion (RND)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma084_v1_zlt40m.root","singlephotonana/vertex_tree","subrun_number%3==0");


	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	axion.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "AxionTestma084");
	axion.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "AxionTestma084");

	axion.SetScale(3/6.0);
	axion.SetPlotStyle(kMagenta, 0);
	axion.SetPOT(2e21);
	
	return axion;
};


Samples LoadAxions084T( TString mTag ){
	Samples axion("0.84 GeV Axion (Train)","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/axions_numiRun1_mesonmixing_ma084_v1_zlt40m.root","singlephotonana/vertex_tree","subrun_number%3>0");


	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	axion.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "Axionma084");
	axion.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "Axionma084");

	axion.SetScale(3.0/2.0/6.0);
	axion.SetPlotStyle(kOrange+10, 0);
	axion.SetPOT(2e21);
	
	return axion;
};


Samples LoadAxions084s( TString mTag ){
	Samples axion("0.84 GeV Axion (RND) Selected","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/addedAxionVars/axions_numiRun1_mesonmixing_ma084_v1_zlt40m_AddVars.root","vertex_tree","subrun_number%3==0&&sqrt(pow((reco_shower_dirz[i_shr[0]]-axion_true_leadingShr_dirz),2)+pow((reco_shower_energy_max[i_shr[0]]-axion_true_leadingShr_E)/(axion_true_leadingShr_E),2)+pow((reco_shower_dirz[i_shr[1]]-axion_true_subleadingShr_dirz),2)+pow((reco_shower_energy_max[i_shr[1]]-axion_true_subleadingShr_E)/(axion_true_subleadingShr_E),2)) < 0.8&&sim_shower_overlay_fraction[i_shr[0]] < 0.3&&sim_shower_overlay_fraction[i_shr[1]] < 0.3&&sim_shower_pdg[i_shr[0]] == 22&&sim_shower_pdg[i_shr[1]] == 22");


	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	axion.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "AxionTestma084");
	axion.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "AxionTestma084");

	axion.SetScale(3/6.0);
	axion.SetPlotStyle(kMagenta, 0);
	axion.SetPOT(2e21);
	
	return axion;
};


Samples LoadAxions084sT( TString mTag ){
	Samples axion("0.84 GeV Axion (Train) Selected","/pnfs/uboone/persistent/users/klin/MCC9/axions_localgpvm_storage/singlemasspoint/addedAxionVars/axions_numiRun1_mesonmixing_ma084_v1_zlt40m_AddVars.root","vertex_tree","subrun_number%3>0&&sqrt(pow((reco_shower_dirz[i_shr[0]]-axion_true_leadingShr_dirz),2)+pow((reco_shower_energy_max[i_shr[0]]-axion_true_leadingShr_E)/(axion_true_leadingShr_E),2)+pow((reco_shower_dirz[i_shr[1]]-axion_true_subleadingShr_dirz),2)+pow((reco_shower_energy_max[i_shr[1]]-axion_true_subleadingShr_E)/(axion_true_subleadingShr_E),2)) < 0.8&&sim_shower_overlay_fraction[i_shr[0]] < 0.3&&sim_shower_overlay_fraction[i_shr[1]] < 0.3&&sim_shower_pdg[i_shr[0]] == 22&&sim_shower_pdg[i_shr[1]] == 22 ");


	//dirtory, classifier, sample
	//<directory>/<classifier>_<sample>_app.root
	axion.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "Axionma084");
	axion.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "Axionma084");

	axion.SetScale(3.0/2.0/6.0);
	axion.SetPlotStyle(kOrange+10, 0);
	axion.SetPOT(2e21);
	
	return axion;
};



Samples LoadAllFHCOnepi0( TString mTag ){
	Samples tmpSample("FHC Runs 1#pi^{0}", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_FHC_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&subrun_number%3==0");


	tmpSample.SetPlotStyle(kRed-3,1001);
//	Not every events have corect weights; so we omit them for now;
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(8.91e21);
	tmpSample.SetScale(2.996768);

	//Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "NuAllFHCBkg");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuAllFHCBkg");
	return tmpSample;
};


Samples LoadAllFHCOnepi0T( TString mTag ){
	Samples tmpSample("FHC Runs 1#pi^{0} Train", "/pnfs/uboone/persistent/users/klin/MCC9/ntuples/liteTtrees_2s0t/JumboMC_FHC_2s0t.root","vertex_tree","mctruth_num_exiting_pi0==1 &&subrun_number%3>0");


	tmpSample.SetPlotStyle(kViolet+8,1001);
//	Not every events have corect weights; so we omit them for now;
//	tmpSample.SetWeight("ppfx_cv_good*spline_tune_good"); // vulnerable to inf weight of spline_tune_good
	tmpSample.SetPOT(8.91e21);
	tmpSample.SetScale(2.996768/2.0);

	//Friends
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionClassifier", "NuAllFHCBkg");
	tmpSample.AddFriendViaTag_v2(TrainDir,  mTag+"PionAccurateClassifier", "NuAllFHCBkg");
	return tmpSample;
};



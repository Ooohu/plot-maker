#ifndef CommonCut_C
#define CommonCut_C
#include "./utility/ConfigureSamples.h"


TString GetCut(){
	TString Precut = "reco_vertex_size==1";
	Precut +="&&(reco_asso_tracks == 0 && reco_asso_showers == 2)";//CutTag2
//	Precut +="&&( reco_vertex_dist_to_SCB > 2)";//CutTag4
//	Precut +="&&( Sum$(reco_flash_total_pe_in_beamgate) > 50)";//CutTag4
//	Precut +="&&( reco_flash_time[0] > 5)";//CutTag4

//	Precut +="&&( Pi0CosmicClassifier > 0.5 )";//CutTag6
//	Precut +="&&( Pi0CosmicClassifier > 0.3 )";//CutTag6

//	Precut +="&&( Pi0CosmicClassifier < 0.3 )";


	return Precut;
}

double ILikeThisPOT( Samples& mc){

//	double pot = mc.GetPOT();
	double pot = 1e21;
	return pot;
}

#endif

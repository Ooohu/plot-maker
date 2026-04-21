#ifndef CommonCut_C
#define CommonCut_C
#include "./utility/ConfigureSamples.h"


TString GetCut(){
	TString Precut = "reco_vertex_size==1";
	Precut +="&&(reco_asso_tracks == 0 && reco_asso_showers == 2)";//2s0t
	Precut +="&&( reco_vertex_dist_to_SCB > 2)";//SCB
//	Precut +="&&( ((reco_shower_energy_max[0] + reco_shower_energy_max[1]) / sqrt(2.0*reco_shower_energy_max[0]*reco_shower_energy_max[1]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1]))))<5)";//E/m < 5, high quality diphoton shower cut;
//	Precut +="&&( Sum$(reco_flash_total_pe_in_beamgate) > 50)";//CutTag4
//	Precut +="&&( reco_flash_time[0] > 5)";//CutTag4

//	Precut +="&&( Pi0CosmicClassifier > 0.7 )";//NCPI0-like events
//	Precut +="&&( Pi0CosmicClassifier > 0.3 )";//NCPI0-like events

//	Precut +="&&( Pi0CosmicClassifier < 0.1 )";
//	Precut +="&&( Pi0CosmicClassifier < 0.3 )";
//	Precut +="&&( Pi0CosmicClassifier < 0.4 )";


//--- Cuts for Dirt selections ---
//	Precut +="&&(reco_asso_tracks == 1 && reco_asso_showers == 0)";//0s1t
//    Precut +="&&(reco_track_dirx*(128.175-reco_vertex_x)+reco_track_diry*(0-reco_vertex_y)+reco_track_dirz*(518.4-reco_vertex_z))>380";//Track tRV > 380

	return Precut;
}

double ILikeThisPOT( Samples& mc){

	double pot = mc.GetPOT();
//	double pot = 1e21;
//	double pot = 2e21;  // expect this as the full POT
	return pot;
}

#endif

#include "utility/PlotHelper.h"

std::vector< Vars> SetMultipleVars(){

	//BDTs
	Vars varbdt("NCPi0 Classifier BDT Score","mva",	{10,0,1.1});
	Vars varbdts("NCPi0 Classifier BDT Score (2 bins)","mva",	{2,0,1.1});
	Vars varbdtL("NCPi0 Classifier BDT Score LOGY","mva",	{8,0,1.1}, true);//LOGY - true

	//General
	Vars var0("Reco Vertex X OneBin", "reco_vertex_x", {1,-20,270});
	Vars var00("Reco Vertex X OneBin LOGY", "reco_vertex_x", {1,-20,270}, true);//LOGY - true
	Vars var1("Reco Vertex X", "reco_vertex_x", {10,-20,270}, true);//LOGY - true

	//Pion Special (NM mother)
	Vars varNMP("Reco. Meson Momentum [GeV]","(reco_shower_energy_max[0]+reco_shower_energy_max[1])/1000",{15,0,1.5});
	Vars varNMPL("Reco. Meson Momentum [GeV] LOGY","(reco_shower_energy_max[0]+reco_shower_energy_max[1])/1000",{15,0,1.5}, true);//LOGY - true

	Vars varNMBeta("Reco. Meson Cos(Beta)","((reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1])*0.462372+(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1])*0.0488541+(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1])*0.885339)/(reco_shower_energy_max[0]+reco_shower_energy_max[1])",{10,-1,1});

	Vars varMass("Reco Invariant Mass [GeV]", "sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {20,0,0.6});
	Vars varMassC("Corrected Reco Invariant Mass [GeV]", "1.21*sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {20,0,0.6});
	Vars varMassCl("Corrected Reco Invariant Mass (Large) [GeV]", "1.21*sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {10,0.4,1.4});
	Vars varMassL("Reco Invariant Mass [GeV] LOGY", "sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {20,0,0.6},true);
	

	//Pion Special (two showers)
	Vars varCosOpnAng("Cosine of Reco Diphoton Openning Angle", "reco_shower_dirx[0]*reco_shower_dirx[1]+reco_shower_diry[0]*reco_shower_diry[1]+reco_shower_dirz[0]*reco_shower_dirz[1]", {8,-1,1});//LOGY - true
	Vars varCosOpnAngL("Cosine of Reco Diphoton Openning Angle LOGY", "reco_shower_dirx[0]*reco_shower_dirx[1]+reco_shower_diry[0]*reco_shower_diry[1]+reco_shower_dirz[0]*reco_shower_dirz[1]", {8,-1,1}, true);//LOGY - true

	Vars varAI("Assymmetry Index", "(reco_shower_energy_max[i_shr[0]] - reco_shower_energy_max[i_shr[1]] )/(reco_shower_energy_max[0]+reco_shower_energy_max[1])", {20,0,1});

	
	//Individual Showers
	Vars varShrCosBeta1("Reco. Leading Shower Cos(Beta)","(reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)", {10,-1,1});
	Vars varShrCosBeta1L("Reco. Leading Shower Cos(Beta) LOGY","(reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)", {10,-1,1}, true);
	Vars varShrBeta1("Reco. Leading Shower Beta [Degree]","180/3.14159*TMath::ACos((reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339))", {18,0,180});
	Vars varShrBeta1L("Reco. Leading Shower Beta [Degree] LOGY","180/3.14159*TMath::ACos((reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339))", {18,0,180}, true);


	Vars varShrCosBeta2("Reco. SubLeading Shower Cos(Beta)","(reco_shower_dirx[i_shr[1]]*0.462372)+(reco_shower_diry[i_shr[1]]*0.0488541)+(reco_shower_dirz[i_shr[1]]*0.885339)", {5,-1,1});
	Vars varShrBeta2("Reco. SubLeading Shower Beta [Degree]","180/3.14159*TMath::ACos((reco_shower_dirx[i_shr[1]]*0.462372)+(reco_shower_diry[i_shr[1]]*0.0488541)+(reco_shower_dirz[i_shr[1]]*0.885339))", {30,0,180});

	Vars varShrE1("Reconstructed Leading Shower Energy [GeV]","reco_shower_energy_max[i_shr[0]]/1000.0", {12,0,0.6});
	Vars varShrE1L("Reconstructed Leading Shower Energy [GeV] LOGY","reco_shower_energy_max[i_shr[0]]/1000.0", {12,0,0.6}, true);

	Vars varShrE2("Reconstructed SubLeading Shower Energy [GeV]","reco_shower_energy_max[i_shr[1]]/1000.0", {20,0,0.8});

	Vars varShrKalmandEdx21("Reconstructed Leading Shower dEdx Plane 2 (Kalman) [MeV/cm]","reco_shower_kalman_dEdx_plane2_median[i_shr[0]]", {20,0,8});
	Vars varShrKalmandEdx22("Reconstructed SubLeading Shower dEdx Plane 2 (Kalman) [MeV/cm]","reco_shower_kalman_dEdx_plane2_median[i_shr[1]]", {20,0,8});

	Vars var_photonl1("Leading Shower Photon Conversion Distance [cm]","reco_shower_conversion_distance[i_shr[0]]",{10,0,5});
	Vars var_photonl1l("Leading Shower Photon Conversion Distance (Large) [cm]","reco_shower_conversion_distance[i_shr[0]]",{10,5,200});

	Vars var_photonl2("SubLeading Shower Photon Conversion Distance [cm]","reco_shower_conversion_distance[i_shr[1]]",{20,0,5});
	Vars var_photonl2l("SubLeading Shower Photon Conversion Distance (Large) [cm]","reco_shower_conversion_distance[i_shr[1]]",{20,10,200});

	Vars var_photonl1L("Leading Shower Photon Conversion Distance [cm] LOGY","reco_shower_conversion_distance[i_shr[0]]",{20,0,10}, true);
	Vars var_photonl1lL("Leading Shower Photon Conversion Distance (Large) [cm] LOGY","reco_shower_conversion_distance[i_shr[0]]",{20,10,200}, true);

	Vars var_photonl2L("SubLeading Shower Photon Conversion Distance [cm] LOGY","reco_shower_conversion_distance[i_shr[1]]",{20,0,10}, true);
	Vars var_photonCl2lL("SubLeading Shower Photon Conversion Distance (Large) [cm] LOGY","reco_shower_conversion_distance[i_shr[1]]",{20,10,200}, true);


	std::vector< Vars> allVars = {varShrKalmandEdx21, varShrKalmandEdx22, varAI, varNMP,  varNMBeta, varMass,  varMassC, varCosOpnAng, varShrCosBeta1,  varShrBeta1, varShrCosBeta2, varShrE1,  varShrE2, var_photonl1, var_photonl1l, var_photonl2, var_photonl2l};
	//std::vector< Vars> allVars = {varShrKalmandEdx2, varNMP, varNMPL, varNMBeta, varMass, varMassL, varCosOpnAng, varCosOpnAngL, varShrCosBeta1, varShrCosBeta1L, varShrBeta1, varShrCosBeta2, varShrE1, varShrE1L, varShrE2, var_photonl1, var_photonl1l, var_photonl2, var_photonl2l};

//	std::vector< Vars> allVars = {varbdtL};//, var22, var77};// , varbdts, varbdtL };
//	std::vector< Vars> allVars = {var2, var22, var6, var66, var7, var77, varbdtL};
//	std::vector< Vars> allVars = {varbdt, varbdts, varbdtL, var0, var00, var1, var2, var22, var3, var33, var4, var44, var5, var55, var6, var66, var7, var77};
	
	return allVars;
}


void DUmmy(){
//Do nothing here;
}

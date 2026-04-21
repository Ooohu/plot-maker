#ifndef VARLIST_H
#define VARLIST_H

#include "utility/PlotHelper.h"

std::vector< Vars> SetMultipleVars(){

	//Vertex Foundamentals
	Vars varRecoST("10*Ntracks + NShowers","10*reco_asso_tracks + reco_asso_showers", {60, 0, 60}, true);
    Vars varX("Reco Vertex X", "reco_vertex_x", {15,-20,270} );//LOGY - true
    Vars varY("Reco Vertex Y", "reco_vertex_y", {15,-150,150});//LOGY - true
    Vars varZ("Reco Vertex Z", "reco_vertex_z", {15,-50,1100});//LOGY - true
    Vars varRecoFlash("Reco Flash Time [us]", "reco_flash_time[0]", {65, 0, 26});
    Vars varSubrun("Subrun Number mod 9", "subrun_number%9", {10, 0, 9}, true);

	//Individual Showers
    Vars varShrKalmandEdx21("Reconstructed Shower dEdx Plane 2 (Kalman) [MeV/cm], Leading","reco_shower_kalman_dEdx_plane2_median[i_shr[0]]", {16,0,8});
    Vars varShrKalmandEdx22("Reconstructed Shower dEdx Plane 2 (Kalman) [MeV/cm], SubLeading","reco_shower_kalman_dEdx_plane2_median[i_shr[1]]", {16,0,8});
    Vars varShrCosBeta1("Reco. Shower Cos(Beta), Leading","(reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)", {40,-1,1});
    Vars varShrBeta1("Reco. Shower Beta [Degree], Leading","180/3.14159*TMath::ACos((reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339))", {36,0,180});
    Vars varShrCosBeta2("Reco. Shower Cos(Beta), SubLeading","(reco_shower_dirx[i_shr[1]]*0.462372)+(reco_shower_diry[i_shr[1]]*0.0488541)+(reco_shower_dirz[i_shr[1]]*0.885339)", {40,-1,1});
//    Vars varShrTheta1("Reco. Shower Theta [Degree], Leading","180/3.14159*TMath::ACos(reco_shower_dirz[i_shr[0]])", {3,0,180});
    Vars varShrTheta1("Reco. Shower Theta [Degree], Leading","180/3.14159*TMath::ACos(reco_shower_dirz[i_shr[0]])", {18,0,180});
    Vars varShrE1("Reconstructed Shower Energy [GeV], Leading","reco_shower_energy_max[i_shr[0]]/1000.0", {20,0,0.5});
    Vars varShrE1l("Reconstructed Shower Energy (large) [GeV], Leading","reco_shower_energy_max[i_shr[0]]/1000.0", {35,0,3.5});
    Vars varShrE2("Reconstructed Shower Energy [GeV], SubLeading","reco_shower_energy_max[i_shr[1]]/1000.0", {20,0,0.5});
    Vars var_photonl1("Shower Photon Conversion Distance [cm], Leading","reco_shower_conversion_distance[i_shr[0]]",{20,0,5});
    Vars var_photonl1l("Shower Photon Conversion Distance (Large) [cm], Leading","reco_shower_conversion_distance[i_shr[0]]",{20,5,200});
    Vars var_photonl2("Shower Photon Conversion Distance [cm], SubLeading","reco_shower_conversion_distance[i_shr[1]]",{20,0,5});
    Vars var_photonl2l("Shower Photon Conversion Distance (Large) [cm], SubLeading","reco_shower_conversion_distance[i_shr[1]]",{20,10,200});
    Vars var_yness1("Shower Zenith Angle, Leading","(180/TMath::Pi())*TMath::Min(fabs(acos(reco_shower_diry[i_shr[0]])), fabs(acos(-reco_shower_diry[i_shr[0]])))",{15,0,90}, false);
    Vars var_yness2("Shower Zenith Angle, SubLeading","(180/TMath::Pi())*TMath::Min(fabs(acos(reco_shower_diry[i_shr[1]])), fabs(acos(-reco_shower_diry[i_shr[1]])))",{15,0,90});


	//Two Showers
    Vars varAI("Energy Assymmetry Index", "(reco_shower_energy_max[i_shr[0]] - reco_shower_energy_max[i_shr[1]] )/(reco_shower_energy_max[0]+reco_shower_energy_max[1])", {10,0,1});

    Vars varNME("Reco. Diphoton Total Energy [GeV]","(reco_shower_energy_max[0]+reco_shower_energy_max[1])/1000",{30,0,1.5});
    Vars varNMP("Reco. Diphoton Total Momentum [GeV]","(sqrt(pow(reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1],2) + pow(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1],2)+pow(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1],2)))/1000",{30,0,1.5});

    Vars varNMBeta("Reco. Diphoton Total Momentum Cos(Beta)","((reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1])*0.462372+(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1])*0.0488541+(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1])*0.885339)/(sqrt(pow(reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1],2) + pow(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1],2)+pow(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1],2)))",{10,-1,1});
    Vars varNMBetaL("Reco. Diphoton Total Momentum Cos(Beta) LOGY","((reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1])*0.462372+(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1])*0.0488541+(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1])*0.885339)/(sqrt(pow(reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1],2) + pow(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1],2)+pow(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1],2)))",{10,-1,1}, true);

    Vars varCosOpnAng("Cosine of Reco Diphoton Opening Angle", "reco_shower_dirx[0]*reco_shower_dirx[1]+reco_shower_diry[0]*reco_shower_diry[1]+reco_shower_dirz[0]*reco_shower_dirz[1]", {8,-1,1});

	//Diphoton Mother Special
    Vars varMass("Reco Invariant Mass [GeV]", "sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {8,0,0.4});
    Vars varMassC("Corrected Reco Invariant Mass [GeV]", "1.21*sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {8,0,0.4});
    Vars varMassCl("Corrected Reco Invariant Mass (Large) [GeV]", "1.21*sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {30,0,1.5});
	Vars varEoverM("Total Shower Energy Over Inv. Mass","((reco_shower_energy_max[0] + reco_shower_energy_max[1]) / sqrt(2.0*reco_shower_energy_max[0]*reco_shower_energy_max[1]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1]))))",{31,0,30});

	//BDT
    double bins = 10;
    Vars var_bdtCosmicPionL("Pion - Cosmic Classifier (Log y)","Pi0CosmicClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma003L("ma003 - Pion Accurate Classifier (Log y)","ma003PionAccurateClassifier",        {bins,0,1}, true);
	Vars var_bdtPionAma0093L("ma0093 - Pion Accurate Classifier (Log y)","ma0093PionAccurateClassifier",        {bins,0,1}, true);
	Vars var_bdtPionAma011L("ma011 - Pion Accurate Classifier (Log y)","ma011PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma0146L("ma0146 - Pion Accurate Classifier (Log y)","ma0146PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma0146tL("ma0146 - Pion Accurate Classifier (Log y, 2bins)","ma0146PionAccurateClassifier",        {2,0,1}, true);//Two bin Test
//    Vars var_bdtPionAma0146L("ma0146 - Pion Accurate Classifier (Log y)","ma0146PionAccurateClassifier",        {bins,0,1}, true, {0.1881,0.2091,0.2181,0.2989,0.2988,0.2237,0.2551,0.3554,0.2730,0.2533});//min sys
//    Vars var_bdtPionAma0146L("ma0146 - Pion Accurate Classifier (Log y)","ma0146PionAccurateClassifier",        {bins,0,1}, true, {0.3084,1.0361,0.9948,1.5467,2.3955,1.3788,0.9396,1.8138,0.9685,1.4788});//max sys
    Vars var_bdtPionAma03L("ma03 - Pion Accurate Classifier (Log y)","ma03PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma04L("ma04 - Pion Accurate Classifier (Log y)","ma04PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma052L("ma052 - Pion Accurate Classifier (Log y)","ma052PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma068L("ma068 - Pion Accurate Classifier (Log y)","ma068PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma084L("ma084 - Pion Accurate Classifier (Log y)","ma084PionAccurateClassifier",        {bins,0,1}, true);


//	std::vector< Vars> allVars = {var_bdtPionAma0146L, varShrE1, varCosOpnAng};
//	std::vector< Vars> allVars = {varMassC};
//	std::vector< Vars> allVars = {var_bdtPionAma0093L};
//	std::vector< Vars> allVars = {var_bdtPionAma011L};
//	std::vector< Vars> allVars = {var_bdtPionAma0146tL};
//	std::vector< Vars> allVars = {var_bdtPionAma0146L};
	std::vector< Vars> allVars = {var_bdtPionAma03L};
//	std::vector< Vars> allVars = {var_bdtPionAma04L};
//	std::vector< Vars> allVars = {var_bdtPionAma052L};
//	std::vector< Vars> allVars = {var_bdtPionAma068L};
//	std::vector< Vars> allVars = {var_bdtPionAma084L};
//	std::vector< Vars> allVars = {var_bdtPionAma0146L, var_bdtPionAma03L, var_bdtPionAma084L};
//	std::vector< Vars> allVars = {var_bdtPionAma003L, var_bdtPionAma0146L, var_bdtPionAma03L, var_bdtPionAma04L, var_bdtPionAma052L, var_bdtPionAma068L, var_bdtPionAma084L, var_bdtPionAma011L};
//	std::vector< Vars> allVars = {varCosOpnAng};

//    std::vector< Vars> allVars = {varX};
//    std::vector< Vars> allVars = {varShrTheta1};
//    std::vector< Vars> allVars = {varX,varY, varZ, varRecoFlash, varRecoST, varSubrun};
//    std::vector< Vars> allVars = {varEoverM};
//    std::vector< Vars> allVars = {varShrKalmandEdx21, varShrKalmandEdx22, varAI, varNME, varNMP,  varNMBeta, varNMBetaL, varMass,  varMassC, varMassCl, varCosOpnAng, varShrCosBeta1,  varShrBeta1, varShrTheta1, varShrCosBeta2, varShrE1, varShrE1l,  varShrE2, var_photonl1, var_photonl1l, var_photonl2, var_photonl2l, var_yness1, var_yness2, varX,varY, varZ, varRecoFlash, varSubrun, var_bdtCosmicPionL, var_bdtPionAma0146L, varRecoST, varEoverM};



return allVars;
}


#endif

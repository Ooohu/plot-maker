#ifndef VARLIST_H
#define VARLIST_H

#include "utility/PlotHelper.h"

std::vector< Vars> SetMultipleVars(){

    //BDTs
    Vars varbdt("NCPi0 Classifier BDT Score","mva",    {10,0,1.1});
    Vars varbdts("NCPi0 Classifier BDT Score (2 bins)","mva",    {2,0,1.1});
    Vars varbdtL("NCPi0 Classifier BDT Score LOGY","mva",    {8,0,1.1}, true);//LOGY - true

    //General
    Vars var0("Reco Vertex X OneBin", "reco_vertex_x", {1,-20,270});
    Vars var00("Reco Vertex X OneBin LOGY", "reco_vertex_x", {1,-20,270}, true);//LOGY - true
    Vars varX("Reco Vertex X", "reco_vertex_x", {20,-20,270} );//LOGY - true
    Vars varY("Reco Vertex Y", "reco_vertex_y", {20,-150,150});//LOGY - true
    Vars varZ("Reco Vertex Z", "reco_vertex_z", {20,-50,1100});//LOGY - true
    Vars varRecoFlash("Reco Flash Time [us]", "reco_flash_time[0]", {65, 0, 26});
    Vars varBeamGPE("BeamGate PE Counts", "Sum$(reco_flash_total_pe_in_beamgate)", {50, 0, 500});

    //Pion Special (NM mother)
    Vars varNME("Reco. Diphoton Total Energy [GeV]","(reco_shower_energy_max[0]+reco_shower_energy_max[1])/1000",{30,0,1.5});
    Vars varNMEL("Reco. Diphoton Total Energy [GeV] LOGY","(reco_shower_energy_max[0]+reco_shower_energy_max[1])/1000",{30,0,1.5}, true);//LOGY - true
    Vars varNMP("Reco. Diphoton Total Momentum [GeV]","(sqrt(pow(reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1],2) + pow(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1],2)+pow(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1],2)))/1000",{30,0,1.5});

    Vars varNMBeta("Reco. Diphoton Total Momentum Cos(Beta)","((reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1])*0.462372+(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1])*0.0488541+(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1])*0.885339)/(sqrt(pow(reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1],2) + pow(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1],2)+pow(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1],2)))",{20,-1,1});
    Vars varNMBetaL("Reco. Diphoton Total Momentum Cos(Beta) LOGY","((reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1])*0.462372+(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1])*0.0488541+(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1])*0.885339)/(sqrt(pow(reco_shower_energy_max[0]*reco_shower_dirx[0]+reco_shower_energy_max[1]*reco_shower_dirx[1],2) + pow(reco_shower_energy_max[0]*reco_shower_diry[0]+reco_shower_energy_max[1]*reco_shower_diry[1],2)+pow(reco_shower_energy_max[0]*reco_shower_dirz[0]+reco_shower_energy_max[1]*reco_shower_dirz[1],2)))",{20,-1,1}, true);

    Vars varMass("Reco Invariant Mass [GeV]", "sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {40,0,0.4});
    //    Vars varMassC("Corrected Reco Invariant Mass [GeV]", "1.21*sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {1,0,0.4});
    Vars varMassC("Corrected Reco Invariant Mass [GeV]", "1.21*sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {40,0,0.4});
    Vars varMassCl("Corrected Reco Invariant Mass (Large) [GeV]", "1.21*sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {50,0,1.5});
    Vars varMassL("Reco Invariant Mass [GeV] LOGY", "sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {20,0,0.6},true);

    Vars varEmRatio("Reconstructed Energy over Reco. Inv. Mass", "(reco_shower_energy_max[i_shr[0]]/1000+reco_shower_energy_max[i_shr[1]]/1000)/(abs(reco_shower_energy_max[i_shr[0]]-reco_shower_energy_max[i_shr[1]])/(reco_shower_energy_max[i_shr[0]]+reco_shower_energy_max[i_shr[1]]))", {40,0,10} );

    //Pion Special (two showers)
    Vars varCosOpnAngONE("Cosine of Reco Diphoton Opening Angle", "reco_shower_dirx[0]*reco_shower_dirx[1]+reco_shower_diry[0]*reco_shower_diry[1]+reco_shower_dirz[0]*reco_shower_dirz[1]", {1,-1,1});
    Vars varCosOpnAng("Cosine of Reco Diphoton Opening Angle", "reco_shower_dirx[0]*reco_shower_dirx[1]+reco_shower_diry[0]*reco_shower_diry[1]+reco_shower_dirz[0]*reco_shower_dirz[1]", {8,-1,1});
    Vars varCosOpnAngL("Cosine of Reco Diphoton Opening Angle LOGY", "reco_shower_dirx[0]*reco_shower_dirx[1]+reco_shower_diry[0]*reco_shower_diry[1]+reco_shower_dirz[0]*reco_shower_dirz[1]", {8,-1,1}, true);//LOGY - true

    Vars varAI("Energy Assymmetry Index", "(reco_shower_energy_max[i_shr[0]] - reco_shower_energy_max[i_shr[1]] )/(reco_shower_energy_max[0]+reco_shower_energy_max[1])", {20,0,1});


    //Individual Showers
    Vars varShrCosBeta1("Reco. Shower Cos(Beta), Leading","(reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)", {40,-1,1});
    Vars varShrCosBeta1L("Reco. Shower Cos(Beta), Leading LOGY","(reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)", {40,-1,1}, true);
    Vars varShrBeta1("Reco. Shower Beta [Degree], Leading","180/3.14159*TMath::ACos((reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339))", {36,0,180});
    Vars varShrTheta1("Reco. Shower Theta [Degree], Leading","180/3.14159*TMath::ACos(reco_shower_dirz[i_shr[0]])", {36,0,180});
    Vars varShrBeta1L("Reco. Shower Beta [Degree], Leading LOGY","180/3.14159*TMath::ACos((reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339))", {18,0,180}, true);


    Vars varShrCosBeta2("Reco. Shower Cos(Beta), SubLeading","(reco_shower_dirx[i_shr[1]]*0.462372)+(reco_shower_diry[i_shr[1]]*0.0488541)+(reco_shower_dirz[i_shr[1]]*0.885339)", {40,-1,1});
    Vars varShrBeta2("Reco. Shower Beta [Degree], SubLeading","180/3.14159*TMath::ACos((reco_shower_dirx[i_shr[1]]*0.462372)+(reco_shower_diry[i_shr[1]]*0.0488541)+(reco_shower_dirz[i_shr[1]]*0.885339))", {30,0,180});

    Vars varShrE1("Reconstructed Shower Energy [GeV], Leading","reco_shower_energy_max[i_shr[0]]/1000.0", {20,0,0.5});
    Vars varShrE1l("Reconstructed Shower Energy (large) [GeV], Leading","reco_shower_energy_max[i_shr[0]]/1000.0", {35,0,3.5});
    Vars varShrE1L("Reconstructed Shower Energy [GeV], Leading LOGY","reco_shower_energy_max[i_shr[0]]/1000.0", {12,0,0.5}, true);

    Vars varShrE2("Reconstructed Shower Energy [GeV], SubLeading","reco_shower_energy_max[i_shr[1]]/1000.0", {20,0,0.5});

    Vars varShrKalmandEdx21("Reconstructed Shower dEdx Plane 2 (Kalman) [MeV/cm], Leading","reco_shower_kalman_dEdx_plane2_median[i_shr[0]]", {20,0,8});
    Vars varShrKalmandEdx22("Reconstructed Shower dEdx Plane 2 (Kalman) [MeV/cm], SubLeading","reco_shower_kalman_dEdx_plane2_median[i_shr[1]]", {20,0,8});

    Vars var_photonl1("Shower Photon Conversion Distance [cm], Leading","reco_shower_conversion_distance[i_shr[0]]",{20,0,5});
    Vars var_photonl1l("Shower Photon Conversion Distance (Large) [cm], Leading","reco_shower_conversion_distance[i_shr[0]]",{20,5,200});

    Vars var_photonl2("Shower Photon Conversion Distance [cm], SubLeading","reco_shower_conversion_distance[i_shr[1]]",{20,0,5});
    Vars var_photonl2l("Shower Photon Conversion Distance (Large) [cm], SubLeading","reco_shower_conversion_distance[i_shr[1]]",{20,10,200});

    Vars var_photonl1L("Shower Photon Conversion Distance [cm], Leading LOGY","reco_shower_conversion_distance[i_shr[0]]",{20,0,10}, true);
    Vars var_photonl1lL("Shower Photon Conversion Distance (Large) [cm], Leading LOGY","reco_shower_conversion_distance[i_shr[0]]",{20,10,200}, true);

    Vars var_photonl2L("Shower Photon Conversion Distance [cm], SubLeading LOGY","reco_shower_conversion_distance[i_shr[1]]",{20,0,10}, true);
    Vars var_photonCl2lL("Shower Photon Conversion Distance (Large) [cm], SubLeading LOGY","reco_shower_conversion_distance[i_shr[1]]",{20,10,200}, true);


    //Cosmic Killer
    Vars var_yness1("Shower Zenith Angle, Leading","(180/TMath::Pi())*TMath::Min(fabs(acos(reco_shower_diry[i_shr[0]])), fabs(acos(-reco_shower_diry[i_shr[0]])))",{20,0,90});
    Vars var_yness2("Shower Zenith Angle, SubLeading","(180/TMath::Pi())*TMath::Min(fabs(acos(reco_shower_diry[i_shr[1]])), fabs(acos(-reco_shower_diry[i_shr[1]])))",{20,0,90});

    //PSV Veto, need new version glee ntuples
    Vars var_clusterlength("Cluster Length [cm]","sss_candidate_wire_tick_based_length",{20,0,20});
    Vars var_clusterdist("Cluster Distance to reco. vertex [cm]","sss_candidate_min_dist",{15,0,250});
    Vars var_clusterenergy("Proton Candidate CLuster Energy [MeV]","sss_candidate_energy",{20,0,20});


    //Vars var_bdtPion("Pion Focused BDT","NuMIFHCRunsAxionV3ma003PionClassifier_mva",        {10,0,1});
    //Vars var_bdtNueCC("NueCC Focused BDT","NuMIFHCRunsAxionV3ma003NueCCClassifier_mva",        {10,0,1});
    //Vars var_bdtCosmic("Cosmic Focused BDT","NuMIFHCRunsAxionV3ma003CosmicClassifier_mva",    {10,0,1});


    Vars var_bdtAxionLike("AxionLike Focused BDT","NuMIFHCRunsAxionV3ma003AxionLikeClassifier_mva", {24,-0.1,1.1});

    //    Vars var_bdtPionL(    "Pion Focused   BDT LOGY","NuMIFHCRunsAxionV3ma003PionClassifier_mva",        {24,0,1}, true);
    //    Vars var_bdtNueCCL(    "NueCC Focused  BDT LOGY","NuMIFHCRunsAxionV3ma003NueCCClassifier_mva",    {24,0,1}, true);
    //    Vars var_bdtCosmicL("Cosmic Focused BDT LOGY","NuMIFHCRunsAxionV3ma003CosmicClassifier_mva", {24,0,1}, true);
    //    Vars var_bdtAxionLikeL("AxionLike Focused BDT LOGY","NuMIFHCRunsAxionV3ma003AxionLikeClassifier_mva", {12,0,1}, true);

    Vars var_runNum1("Run1 Run Number","run_number",{20,4952,6999});//first run till (last run +1)
    Vars var_runNum2("Run2 Run Number","run_number",{20,8745,11948});
    Vars var_runNum2aFHC("Run2a FHC Run Number","run_number",{60,8772,9972});
    Vars var_runNum3("Run3 Run Number","run_number",{20,14117,17567});
    Vars var_runNum4("Run4 Run Number","run_number",{20,19660,23260});
    Vars var_runNum5("Run5 Run Number","run_number",{20,24376,25760});



    ////BDT Stuffs Below
    double bins = 10;
    Vars var_bdtPion("ma084 - Pion Classifier", "ma084PionClassifier",        {bins,0,1});
    Vars var_bdtPion084L("ma084 - Pion Classifier (Log y)","ma084PionClassifier",        {bins,0,1}, true);

    Vars var_bdtPionA ("ma084 - Pion Accurate Classifier","ma084PionAccurateClassifier",        {bins,0,1});
    Vars var_bdtPionAL("ma084 - Pion Accurate Classifier (Log y)","ma084PionAccurateClassifier",        {bins,0,1}, true);


    Vars var_bdtCosmicPion("Pion - Cosmic Classifier (Log y)","Pi0CosmicClassifier",        {bins,0,1});
    Vars var_bdtCosmicPionL("Pion - Cosmic Classifier (Log y)","Pi0CosmicClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma011L("ma011 - Pion Accurate Classifier (Log y)","ma011PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma0146L("ma0146 - Pion Accurate Classifier (Log y)","ma0146PionAccurateClassifier",        {bins,0,1}, true, {1,1,1,1,1,1,1,1,1,1});
    Vars var_bdtPionAma03L("ma03 - Pion Accurate Classifier (Log y)","ma03PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma04L("ma04 - Pion Accurate Classifier (Log y)","ma04PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma052L("ma052 - Pion Accurate Classifier (Log y)","ma052PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma068L("ma068 - Pion Accurate Classifier (Log y)","ma068PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma084L("ma084 - Pion Accurate Classifier (Log y)","ma084PionAccurateClassifier",        {bins,0,1}, true);

    //    std::vector< Vars> allVars = {varEmRatio};
    //std::vector< Vars> allVars = {varMassC};
    //     std::vector< Vars> allVars = {var_runNum1};
    //     std::vector< Vars> allVars = {var_runNum2aFHC};
    std::vector< Vars> allVars = {var_bdtPionAma0146L};
    //    std::vector< Vars> allVars = {varShrKalmandEdx21, varShrKalmandEdx22, varAI, varNME, varNMP,  varNMBeta, varNMBetaL, varMass,  varMassC, varMassCl, varCosOpnAng, varShrCosBeta1,  varShrBeta1, varShrTheta1, varShrCosBeta2, varShrE1, varShrE1l,  varShrE2, var_photonl1, var_photonl1l, var_photonl2, var_photonl2l, var_yness1, var_yness2, varX,varY, varZ, varRecoFlash, varBeamGPE, var_bdtCosmicPionL, var_bdtPionAma0146L};


    //    std::vector< Vars> allVars = {var_runNum1, var_runNum2, var_runNum3, var_runNum4, var_runNum5};

    return allVars;
}


#endif

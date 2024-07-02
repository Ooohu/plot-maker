#include "utility/PlotHelper.h"

std::vector< Vars> SetMultipleVars(){
	Vars varbdt("NCPi0 Classifier BDT Score","mva",	{10,0,1.1});
	Vars varbdts("NCPi0 Classifier BDT Score (2 bins)","mva",	{2,0,1.1});
	Vars varbdtL("NCPi0 Classifier BDT Score Log","mva",	{10,0,1.1}, true);//log scale - true

	Vars var0("Reco Vertex X OneBin", "reco_vertex_x", {1,-20,270});
	Vars var00("Reco Vertex X OneBin log scale", "reco_vertex_x", {1,-20,270}, true);//log scale - true
	Vars var1("Reco Vertex X", "reco_vertex_x", {10,-20,270}, true);//log scale - true
	Vars var2("Reco Invariant Mass [GeV]", "sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {18,0,1.4});
	Vars var22("Reco Invariant Mass [GeV] log scale", "sqrt(2.0*reco_shower_energy_max[i_shr[0]]*reco_shower_energy_max[(i_shr[1])]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1])))/1000", {18,0,1.4}, true);
	Vars var3("Cosine of Reco Openning Angle", "reco_shower_dirx[0]*reco_shower_dirx[1]+reco_shower_diry[0]*reco_shower_diry[1]+reco_shower_dirz[0]*reco_shower_dirz[1]", {8,-1,1});//log scale - true
	Vars var33("Cosine of Reco Openning Angle log scale", "reco_shower_dirx[0]*reco_shower_dirx[1]+reco_shower_diry[0]*reco_shower_diry[1]+reco_shower_dirz[0]*reco_shower_dirz[1]", {8,-1,1}, true);//log scale - true
	Vars var4("Reco. axion momentum z[GeV]","(reco_shower_energy_max[0]*reco_shower_implied_dirz[0]+reco_shower_energy_max[1]*reco_shower_implied_dirz[1])/1000",{20,-0.5,1.4});
	Vars var44("Reco. axion momentum z[GeV]","(reco_shower_energy_max[0]*reco_shower_implied_dirz[0]+reco_shower_energy_max[1]*reco_shower_implied_dirz[1])/1000",{20,-0.5,1.4}, true);
	
	Vars var5("Reco. axion momentum y[GeV]","(reco_shower_energy_max[0]*reco_shower_implied_diry[0]+reco_shower_energy_max[1]*reco_shower_implied_diry[1])/1000",{20,-0.5,1.4});
	Vars var55("Reco. axion momentum y[GeV] log","(reco_shower_energy_max[0]*reco_shower_implied_diry[0]+reco_shower_energy_max[1]*reco_shower_implied_diry[1])/1000",{20,-0.5,1.4}, true);

	Vars var6("Reco. Leading shower cos(beta)","(reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)", {20,-1,1});
	Vars var66("Reco. Leading shower cos(beta) log ","(reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339)", {20,-1,1}, true);
	Vars var666("Reco. Leading shower beta [Degree] log ","180/3.14159*TMath::ACos((reco_shower_dirx[i_shr[0]]*0.462372)+(reco_shower_diry[i_shr[0]]*0.0488541)+(reco_shower_dirz[i_shr[0]]*0.885339))", {60,0,180}, true);

	Vars var7("Reconstructed Leading Shower Energy [GeV]","reco_shower_energy_max[i_shr[0]]/1000.0", {30,0.03,1});
	Vars var77("Reconstructed Leading Shower Energy [GeV] Log","reco_shower_energy_max[i_shr[0]]/1000.0", {30,0.03,1}, true);

//	std::vector< Vars> allVars = {varbdtL,varbdt};// , varbdts, varbdtL };
	std::vector< Vars> allVars = {var666};
//	std::vector< Vars> allVars = {varbdt, varbdts, varbdtL, var0, var00, var1, var2, var22, var3, var33, var4, var44, var5, var55, var6, var66, var7, var77};
	
	return allVars;
}


void DUmmy(){
//Do nothing here;
}

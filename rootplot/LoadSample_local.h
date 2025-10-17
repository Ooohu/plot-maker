#include "./utility/ConfigureSamples.h"

Samples LoadCV( TString tag ){
	Samples axion("CV"+tag," /Users/maco/Documents/Neutrinos/ROOTs/gleeNtuples_numi_run4aMCoverlay_reweighted.root","singlephotonana/vertex_tree","Entry$%3==0");
//OLD Freind of BDT with 12 variables
//	axion.AddFriend("../../../2022Nov_ub_gLEE_Ntuples/hellstroms_hive/hive/build_axion_general/NuMIFHCRun1Axion"+tag+"/NuMIFHCRun1Axion"+tag+"NCPionClassifiee_Axion"+tag+"_app.root","Axion"+tag+"_NuMIFHCRun1Axion"+tag+"NCPionClassifiee");
//NEW Freind of BDT with 3 variables
//	axion.SetScale(3*2.0/58560);//for regular ma03 sample
	axion.SetScale(50000.0*2/391750);
	axion.SetPOT(2e21);
	
	return axion;
};

Samples LoadVar1( TString tag ){
	Samples axion("Var1"+tag,"/Users/maco/Documents/Neutrinos/ROOTs/gleeNtuples_numi_run4aMCoverlay_reweighted.root","singlephotonana/vertex_tree","Entry$%3==1");
//OLD Freind of BDT with 12 variables
//	axion.AddFriend("../../../2022Nov_ub_gLEE_Ntuples/hellstroms_hive/hive/build_axion_general/NuMIFHCRun1Axion"+tag+"/NuMIFHCRun1Axion"+tag+"NCPionClassifiee_Axion"+tag+"_app.root","Axion"+tag+"_NuMIFHCRun1Axion"+tag+"NCPionClassifiee");
//NEW Freind of BDT with 3 variables
//	axion.SetScale(3*2.0/58560);//for regular ma03 sample
	axion.SetScale(50000.0*2/391750);
	axion.SetPOT(2e21);
	
	return axion;
};



Samples LoadVar2( TString tag ){
	Samples axion("Var2"+tag,"/Users/maco/Documents/Neutrinos/ROOTs/gleeNtuples_numi_run4aMCoverlay_reweighted.root","singlephotonana/vertex_tree","Entry$%3==2");
//OLD Freind of BDT with 12 variables
//	axion.AddFriend("../../../2022Nov_ub_gLEE_Ntuples/hellstroms_hive/hive/build_axion_general/NuMIFHCRun1Axion"+tag+"/NuMIFHCRun1Axion"+tag+"NCPionClassifiee_Axion"+tag+"_app.root","Axion"+tag+"_NuMIFHCRun1Axion"+tag+"NCPionClassifiee");
//NEW Freind of BDT with 3 variables
//	axion.SetScale(3*2.0/58560);//for regular ma03 sample
	axion.SetScale(50000.0*2/391750);
	axion.SetPOT(2e21);
	
	return axion;
};




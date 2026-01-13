#include "utility/PlotHelper.h"

std::vector< Vars> SetMultipleVars(){

	double bins = 10;
	Vars var_bdtPion("ma084 - Pion Classifier", "ma084PionClassifier",		{bins,0,1});
	Vars var_bdtPionL("ma084 - Pion Classifier (Log y)","ma084PionClassifier",		{bins,0,1}, true);

	Vars var_bdtPionA ("ma084 - Pion Accurate Classifier","ma084PionAccurateClassifier",		{bins,0,1});
	Vars var_bdtPionAL("ma084 - Pion Accurate Classifier (Log y)","ma084PionAccurateClassifier",		{bins,0,1}, true);


//	std::vector< Vars> allVars = {var_bdtPion, var_bdtPionL, var_bdtPionA, var_bdtPionAL};
	std::vector< Vars> allVars = {var_bdtPionL, var_bdtPionAL};

	return allVars;
}


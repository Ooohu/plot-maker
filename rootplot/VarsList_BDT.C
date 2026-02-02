#include "utility/PlotHelper.h"

std::vector< Vars> SetMultipleVars(){

	double bins = 10;
    Vars var_bdtPionAma011L("ma011 - Pion Accurate Classifier (Log y)","ma011PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma0146L("ma0146 - Pion Accurate Classifier (Log y)","ma0146PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma03L("ma03 - Pion Accurate Classifier (Log y)","ma03PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma04L("ma04 - Pion Accurate Classifier (Log y)","ma04PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma052L("ma052 - Pion Accurate Classifier (Log y)","ma052PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma068L("ma068 - Pion Accurate Classifier (Log y)","ma068PionAccurateClassifier",        {bins,0,1}, true);
    Vars var_bdtPionAma084L("ma084 - Pion Accurate Classifier (Log y)","ma084PionAccurateClassifier",        {bins,0,1}, true);


//	std::vector< Vars> allVars = {var_bdtPion, var_bdtPionL, var_bdtPionA, var_bdtPionAL};
//	std::vector< Vars> allVars = {var_bdtPionL, var_bdtPionAL};
	std::vector< Vars> allVars = {var_bdtPionAma0146L};

	return allVars;
}


#ifndef CONFIGUREVARS_H
#define CONFIGUREVARS_H


// Build a class for storing variables, cuts, and Binnings
class Vars {
public:

  // Constructor
  Vars (TString AxisLabel, TString VarName, std::vector<double> Binning, bool isLog = false) {
	this->v_AxisLabel = AxisLabel;
	this->v_VarName = VarName;
	this->v_Binning = Binning;
	this->v_isLog = isLog;
  }

	//getters
	TString GetAxisLabel() {return v_AxisLabel;}
	TString GetVarName() {return v_VarName;}
	std::vector<double> GetBinning() {return v_Binning;}

  ~Vars() {}


private:

	TString v_AxisLabel;

	TString v_VarName;

	std::vector<double> v_Binning;
	bool v_isLog;
};

#endif

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
	bool GetIsLog() {return v_isLog;}
	TString GetAxisLabel() {return v_AxisLabel;}
	TString GetVarName() {return v_VarName;}
	std::vector<double> GetBinning() {return v_Binning;}

	//Print Summary
	void PrintSummary() {
		std::cout<<"Variable: "<<this->v_VarName;
		std::cout<<" in Binnings: ";
		for (int i = 0; i < this->v_Binning.size(); i++) {
			std::cout<<this->v_Binning[i]<<" ";
		}
		if(v_isLog) std::cout<<" in log scale";
		std::cout<<std::endl;
	}

	void PrintBinEdges() {
		double step = (this->v_Binning[2] - this->v_Binning[1])/this->v_Binning[0];
		double firstbin = this->v_Binning[1];
		while(firstbin < this->v_Binning[2]) {
			std::cout<<firstbin<<" ";
			firstbin += step;
		} 
	}

  ~Vars() {}


private:

	TString v_AxisLabel;

	TString v_VarName;

	std::vector<double> v_Binning;
	bool v_isLog;
};

#endif

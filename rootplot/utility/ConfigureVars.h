
// Build a class for storing variables, cuts, and Binnings
class Var {
public:

  // Constructor
  Var (TString AxisLabel, TString VarName, std::vector<double> Binning, bool isLog = false) {
	this->AxisLabel = AxisLabel;
	this->VarName = VarName;
	this->Binning = Binning;
	this->isLog = isLog;
  }

	//getters
	TString GetAxisLabel() {return AxisLabel;}
	TString GetVarName() {return VarName;}
	std::vector<double> GetBinning() {return Binning;}

  ~Var() {}


private:

	TString AxisLabel;

	TString VarName;

	std::vector<double> Binning;
	bool isLog;
};

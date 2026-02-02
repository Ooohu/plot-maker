#ifndef CONFIGUREVARS_H
#define CONFIGUREVARS_H


// Build a class for storing variables, cuts, and Binnings
class Vars {
	public:

		// Constructor
		Vars(TString AxisLabel,
				TString VarName,
				std::vector<double> Binning,
				bool isLog = false,
				std::vector<double> frac_err = {})
			: v_AxisLabel(AxisLabel),
			v_VarName(VarName),
			v_Binning(Binning),
			v_isLog(isLog),
			v_frac_err(frac_err)
			{
				if (!v_frac_err.empty() &&
						std::accumulate(v_frac_err.begin(), v_frac_err.end(), 0.0) > 0.0)
				{
					v_usesys = true;
				}
			}


		//getters
		bool GetIsLog() {return v_isLog;}
		bool GetUseSys() {return v_usesys;}
		TString GetAxisLabel() {return v_AxisLabel;}
		TString GetVarName() {return v_VarName;}
		std::vector<double> GetBinning() {return v_Binning;}
		std::vector<double> GetFracSys() {return v_frac_err;}

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

		std::vector<double> v_frac_err;
		bool v_usesys = false;//add systematic erros;
};

#endif

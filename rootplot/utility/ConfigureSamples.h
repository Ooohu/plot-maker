#include "Gadget.h"

//Set a class containing the samples
class Samples
{
//Public members

public:
	//Constructor
	Samples(TString SampleName, TString file_path, TString branch_name, TString definition)
	: SampleName(SampleName), file_path(file_path), branch_name(branch_name), definition(definition) {
	this->ttree = GetTree(file_path, branch_name);
	};

	//Destructor
	~Samples() {};

	//Set the samples
	void SetPlotStyle(int col, int fillstyle)
	{
		this->col = col;
		this->fillstyle = fillstyle;
	}
	
	//Draw a TH1D
	TH1D* drawTH1D(TString var, std::vector<double> binnings, TString title="")
	{
		TH1D* h = new TH1D(RandomName(), title, binnings[0], binnings[1], binnings[2]);
		this->ttree->Draw(var+">>"+h->GetName(), this->definition);

		h->SetLineColor(col);
		h->SetFillColor(col);
		h->SetFillStyle(fillstyle);
		return h;
	}

	//Update definitions
	void AddDefinition(TString def)
	{
		this->definition += " && " + def;
	}
	
	//Many ways to Set POT
	//for data, POT = tgt_wcut i.e. triggers number from the target
	//for EXT, POT = (data) tgt_wcut * NuMI_FEMBeamTrigger/ E1DCNT_wcut
	void SetPOT(double POT)
	{
		this->POT = POT;
	}

	void SetMCPOT(TString branch = "singlephotonana/run_subrun_tree")
	{
		double potbranch = 0;
		double POT = 0;
		TTree* tree = GetTree(this->file_path, branch);
		tree->SetBranchAddress("subrun_pot",&potbranch);

		for(int i=0; i<tree->GetEntries(); i++) {
			tree->GetEntry(i);
			POT += (double)potbranch;
		}

		this->POT = POT;
	}

	//getter
	double GetPOT(){ return this->POT;};
	TString GetSampleName(){ return this->SampleName;}
	TString GetFilePath(){ return this->file_path;}
	TString GetBranchName(){ return this->branch_name;}

//Private members
private:

	TString SampleName;
	TString file_path;
	TString branch_name;

	TString definition;//Definition of the event

	double POT;

	int col;
	int fillstyle;

	TTree* ttree;
};

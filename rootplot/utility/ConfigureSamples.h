#ifndef CONFIGURE_SAMPLES_H
#define CONFIGURE_SAMPLES_H

#include "Gadgets.h"

//Set a class containing the samples
class Samples
{
//Public members

public:
	//Constructor
	Samples(TString SampleName, TString file_path, TString branch_name, TString definition)
	: s_SampleName(SampleName), s_file_path(file_path), s_branch_name(branch_name), s_definition(definition) {
	this->s_ttree = GetTree(file_path, branch_name);
	};

	//Destructor
	~Samples() {};

	//Set the samples
	void SetPlotStyle(int col, int fillstyle)
	{
		this->s_col = col;
		this->s_fillstyle = fillstyle;
	}
	
	//Update definitions
	void AddDefinition(TString def)
	{
		this->s_definition += " && " + def;
	}
	
	//Many ways to Set POT
	//for data, POT = tgt_wcut i.e. triggers number from the target
	//for EXT, POT = (data) tgt_wcut * NuMI_FEMBeamTrigger/ E1DCNT_wcut
	void SetPOT(double POT)
	{
		this->s_POT = POT;
	}

	void SetMCPOT(TString branch = "singlephotonana/run_subrun_tree")
	{
		double potbranch = 0;
		double POT = 0;
		TTree* tree = GetTree(this->s_file_path, branch);
		tree->SetBranchAddress("subrun_pot",&potbranch);

		for(int i=0; i<tree->GetEntries(); i++) {
			tree->GetEntry(i);
			POT += (double)potbranch;
		}

		this->s_POT = POT;
	}

	//getter
	double GetPOT(){ return this->s_POT;};
	TTree* GetSampleTree(){ return this->s_ttree;}
	TString GetSampleName(){ return this->s_SampleName;}
	TString GetFilePath(){ return this->s_file_path;}
	TString GetBranchName(){ return this->s_branch_name;}
	TString GetDefinition(){ return this->s_definition;}
	int GetCol(){ return this->s_col;}
	int GetFillStyle(){ return this->s_fillstyle;}

//Private members
private:

	TString s_SampleName;
	TString s_file_path;
	TString s_branch_name;

	TString s_definition;//Definition of the event

	double s_POT;

	int s_col;
	int s_fillstyle;

	TTree* s_ttree;
};

#endif

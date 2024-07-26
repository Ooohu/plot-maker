#ifndef GADGETS_H
#define GADGETS_H
#include <sstream>

// generate random names for histograms
TString RandomName(){
	TString name = "hist";
	for(int i=0;i<10;i++){
		name += (char)(rand()%26+97);
	}
	return name;
}


TTree* GetTree(TString filename, TString treename)
{
  TFile* file = new TFile(filename);
  TTree* tree = (TTree*)file->Get(treename);
  return tree;
}

TString MakeSafeName(TString input){
	std::string safe_name = input.Data();

	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '('), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ')'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '\\'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '/'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '['), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ']'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '+'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '-'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '*'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '.'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ' '), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ','), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '|'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), ':'), safe_name.end());

	return safe_name.c_str();
};

//Histogram Helper

std::string PrintHist(TH1D* tmp_hist){
//		std::cout<<" sum: "<<tmp_hist->Integral()<<std::endl;
	std::stringstream text_buffer;
	text_buffer<<"Bin : ";
	for(int i=1; i<tmp_hist->GetNbinsX()+1; i++){
		text_buffer << tmp_hist->GetBinContent(i) << ",";
	}

	text_buffer<<"\nSErr: ";
	for(int i=1; i<tmp_hist->GetNbinsX()+1; i++){
		text_buffer << tmp_hist->GetBinError(i) << ",";
	}
	text_buffer<<std::endl;

	return text_buffer.str();
}

#endif

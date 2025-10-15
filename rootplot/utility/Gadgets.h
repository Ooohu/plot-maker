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
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '^'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '#'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '{'), safe_name.end());
	safe_name.erase(std::remove(safe_name.begin(), safe_name.end(), '}'), safe_name.end());

	return safe_name.c_str();
};

//Histogram Helper

std::string PrintHist(TH1D* tmp_hist){
//		std::cout<<" sum: "<<tmp_hist->Integral()<<std::endl;
	std::stringstream tmptext_buffer;

	tmptext_buffer<<"\nBin: ";
	for(int i=1; i<tmp_hist->GetNbinsX()+1; i++){
		tmptext_buffer << tmp_hist->GetBinContent(i) << ",";
	}

	tmptext_buffer<<"\nSErr: ";
	for(int i=1; i<tmp_hist->GetNbinsX()+1; i++){
		tmptext_buffer << tmp_hist->GetBinError(i) << ",";
	}
	tmptext_buffer<<std::endl;

	return tmptext_buffer.str();
}

void SetRatioStyle( TH1D* ratio){

	//Take care of the Yaxis first;
	ratio->SetMaximum(1+1);
	ratio->SetMinimum(1-1);
	ratio->GetYaxis()->SetNdivisions(405);

	ratio->SetStats(false);
	ratio->GetYaxis()->SetLabelSize(0.08);//relative to the TPad size y~ 0.04*2, wheere 2=(0.8-0.3)/(0.3-0.05)
	ratio->GetYaxis()->SetTitleSize(0.12);
	ratio->GetYaxis()->SetTitleOffset(0.3);

	//Margin should be larger than the sum of both sizes
	ratio->GetXaxis()->SetLabelSize(0.1);
	ratio->GetXaxis()->SetTitleSize(0.12);

	ratio->SetMarkerSize(1);

	int LineColor = 17;
	TLine* line;
	line = new TLine(ratio->GetXaxis()->GetXmin(),1.0,ratio->GetXaxis()->GetXmax(),1.0 );
	line->SetLineColor(LineColor);
	line->Draw("same");

	TLine* line5;
	line5 = new TLine(ratio->GetXaxis()->GetXmin(),1.05,ratio->GetXaxis()->GetXmax(),1.05);
	line5->SetLineColor(LineColor);
	line5->SetLineStyle(2);
	line5->Draw("same");

	TLine* line10;
	line10 = new TLine(ratio->GetXaxis()->GetXmin(),1.1,ratio->GetXaxis()->GetXmax(),1.1);
	line10->SetLineColor(LineColor);
	line10->SetLineStyle(3);
	line10->Draw("same");

	TLine* line5n;
	line5n = new TLine(ratio->GetXaxis()->GetXmin(),1-0.05,ratio->GetXaxis()->GetXmax(),1-0.05);
	line5n->SetLineColor(LineColor);
	line5n->SetLineStyle(2);
	line5n->Draw("same");

	TLine* line10n;
	line10n = new TLine(ratio->GetXaxis()->GetXmin(),1-0.1,ratio->GetXaxis()->GetXmax(),1-0.1);
	line10n->SetLineColor(LineColor);
	line10n->SetLineStyle(3);
	line10n->Draw("same");
}

void SetHashStyle(TH1D* hist){
	hist->SetFillColor(kGray+1);
	hist->SetMarkerStyle(0);
	hist->SetMarkerSize(0);
	hist->SetFillStyle(3354);
	hist->SetLineColor(kBlack);
}

double Chi2Poisson(const TH1D* hData, const TH1D* hMC) {
	int nbins = hData->GetNbinsX();
	double chi2 = 0.0;

	for (int i = 1; i <= nbins; i++) {
		double O = hData->GetBinContent(i);
		double E = hMC->GetBinContent(i);

		if (E <= 0) continue; // skip bins with no expectation

		if (O > 0) {
			chi2 += 2.0 * (E - O + O * std::log(O / E));
		} else {
			chi2 += 2.0 * E; // when O=0
		}
	}
	return chi2;
}

double Chi2Gaussian(const TH1D* hData, const TH1D* hMC) {
	int nbins = hData->GetNbinsX();
	double chi2 = 0.0;

	for (int i = 1; i <= nbins; i++) {
		double O = hData->GetBinContent(i);
		double E = hMC->GetBinContent(i);
		double sigmaO = hData->GetBinError(i);  // observed error
		double sigmaE = hMC->GetBinError(i);  // expected error (optional)

		// Variance estimate: here I use observed counts O
		double sigma2 = (O > 0) ? sigmaE*sigmaE : 1.0;  // avoid divide by zero

		chi2 += (O - E) * (O - E) / sigma2;
	}
	return chi2;
}



TLatex *GetEstimators( TH1D* data, TH1D* MC){

	TLatex *estimators;//Data/MC ratio, KS Test, Chi^2/(nDoF), Chi^2 p-value;
	double histdata_num = data->Integral();
	double histMC_num = MC->Integral();
	TString text_ratio; text_ratio.Form("Data/MC=%.2f   ",histdata_num/histMC_num); 

	TString text_ks; text_ks.Form("KS: %.2f   ", MC->KolmogorovTest(data)); 
//	TString text_chi2; text_chi2.Form("#chi^{2}/n#it{DOF}=%.2f/%d p=%.2g   ", MC->Chi2Test(data,"UW CHI2"), 
//																			MC->GetNbinsX()-1, 
//																			MC->Chi2Test(data,"UW P"));


	TString text_chi2; text_chi2.Form("#chi^{2}/n#it{DOF}=%.2f/%d p=%.2g   ", data->Chi2Test(MC,"UW CHI2"), 
																			MC->GetNbinsX()-1, 
																			data->Chi2Test(MC,"UW P"));

	//soruce code at https://root.cern.ch/doc/master/TH1_8cxx_source.html#l01995
	std::cout<<"Chi2Test MC->Chi2Test(Data) "<< MC->Chi2Test(data,"WU CHI2")<<std::endl;
	std::cout<<"Chi2Test Data->Chi2Test(MC) "<< data->Chi2Test(MC,"WU CHI2")<<std::endl;

	std::cout<<"Manual check (Poisson ): "<<Chi2Poisson (data, MC)<<std::endl;
	std::cout<<"Manual check (Gaussian): "<<Chi2Gaussian(data, MC)<<std::endl;


//	//chi2 will ignore 0 values, so replace it with something super small would be good.
//	double small_value = 1e-10;
//	TH1D *MC_copy = (TH1D*)MC->Clone("MC_copy");
//	for (int i = 1; i <= MC_copy->GetNbinsX(); i++) {
//		if (MC_copy->GetBinContent(i) == 0) {
//			MC_copy->SetBinContent(i, small_value);  // Replace zero with small value
//		}
//	}
//	TH1D *data_copy = (TH1D*)data->Clone("data_copy");
//	for (int i = 1; i <= data_copy->GetNbinsX(); i++) {
//		if (data_copy->GetBinContent(i) == 0) {
//			data_copy->SetBinContent(i, small_value);  // Replace zero with small value
//		}
//	}
//
//
//	TString text_ks; text_ks.Form("KS: %.2f   ", MC_copy->KolmogorovTest(data_copy)); 
//	TString text_chi2; text_chi2.Form("#chi^{2}/n#it{DOF}=%.2f/%d p=%.2g   ", MC_copy->Chi2Test(data_copy,"UW CHI2"), 
//																			MC_copy->GetNbinsX()-1, 
//																			MC_copy->Chi2Test(data_copy,"UW P"));
//
//	//soruce code at https://root.cern.ch/doc/master/TH1_8cxx_source.html#l01995
//	std::cout<<"Chi2Test Check "<< MC_copy->Chi2Test(data,"WU CHI2")<<std::endl;

	TString combined = text_ratio + text_ks + text_chi2;
	estimators = new TLatex(0.05, 0.6, combined);

	estimators->SetTextColor(kRed-7);
	estimators->SetTextSize(0.5);

	return estimators;
}


#endif

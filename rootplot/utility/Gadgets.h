#ifndef GADGETS_H
#define GADGETS_H
#include <sstream>
#include <vector>
#include <iostream>
#include <cmath>
#include "TRandom3.h"

#include <map>
#include <vector>
#include <string>

#include <fstream>
#include <string>


// Define your color palette once
Color_t sampleColors[] = {
    static_cast<Color_t>(TColor::GetColor("#e41a1c")),
    static_cast<Color_t>(TColor::GetColor("#377eb8")),
    static_cast<Color_t>(TColor::GetColor("#4daf4a")),
    static_cast<Color_t>(TColor::GetColor("#984ea3")),
    static_cast<Color_t>(TColor::GetColor("#ff7f00")),
    static_cast<Color_t>(TColor::GetColor("#ffff33")),
    static_cast<Color_t>(TColor::GetColor("#a65628")),
    static_cast<Color_t>(TColor::GetColor("#f781bf")),
    static_cast<Color_t>(TColor::GetColor("#999999"))
};

// Helper function
Color_t sampleColor(int index) {
    int nColors = sizeof(sampleColors) / sizeof(sampleColors[0]);
    return sampleColors[index % nColors];  // cycle automatically
}



TTree* GetTree(TString filename, TString treename)
{
  TFile* file = new TFile(filename);
  TTree* tree = (TTree*)file->Get(treename);
  return tree;
}


// Text Modifier
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


std::map<TString, TString> varAlias = {
    {"reco_vertex_size", "vt"},
	{"reco_asso_tracks", "trk"},
	{"reco_asso_showers", "shr"},
    {"reco_vertex_dist_to_SCB", "fv"},
    {"Pi0CosmicClassifier", "pi0CBDT"},
    {"(reco_track_dirx*(128.175-reco_vertex_x)+reco_track_diry*(0-reco_vertex_y)+reco_track_dirz*(518.4-reco_vertex_z))", "TtRV"},
	{"((reco_shower_energy_max[0] + reco_shower_energy_max[1]) / sqrt(2.0*reco_shower_energy_max[0]*reco_shower_energy_max[1]*(1.0-(reco_shower_dirx[0]*reco_shower_dirx[1] + reco_shower_diry[0]*reco_shower_diry[1] + reco_shower_dirz[0]*reco_shower_dirz[1]))))", "EovM"}

};

TString ApplyAlias(TString cut)
{
    for (const auto& it : varAlias) {
        cut.ReplaceAll(it.first, it.second);
    }
    return cut;
}


TString CanonicalizeCut(TString cut)
{
    // 1. Remove spaces

	TString tmp_cut = MakeSafeName( 
			ApplyAlias(cut) 
			);

    // 2. Split by &&
    TObjArray* tokens = tmp_cut.Tokenize("&&");

    std::vector<TString> parts;

    for (int i = 0; i < tokens->GetEntries(); ++i) {
        TString part = ((TObjString*)tokens->At(i))->GetString();
        parts.push_back(part);
    }

    delete tokens;

    // 3. Sort alphabetically
    std::sort(parts.begin(), parts.end(),
              [](const TString& a, const TString& b) {
                  return a.CompareTo(b) < 0;
              });

    // 4. Rebuild canonical string
    TString result;
    for (size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) result += "&&";
        result += parts[i];
    }

    return result;
}

TString MakeSuffix(TString cut)
{//Canonicalize text
    TString canonical = CanonicalizeCut(cut);

    canonical.ReplaceAll("&&", "_");
    canonical.ReplaceAll("<=", "le");
    canonical.ReplaceAll(">=", "ge");
    canonical.ReplaceAll("<", "lt");
    canonical.ReplaceAll(">", "gt");
    canonical.ReplaceAll("==", "eq");
    canonical.ReplaceAll(".", "p");

    return canonical;
}


TString RandomName() {
	static TRandom3 rng(0); // seed=0 -> random seed based on time
	TString name = "hist";
	for (int i = 0; i < 10; i++) {
		char c = 'a' + rng.Integer(26);  // random letter a-z
		name += c;
	}
	return name;
}



TString MakeSafeWgtName(const TString& weightBranch){
    // Returns a TString that replaces any NaN/Inf or negative weight with 0
	return Form("(TMath::Finite(%s) && %s > 0 ? %s : 0)", 
			weightBranch.Data(), weightBranch.Data(), weightBranch.Data());
}

//JSON producer, produced via WriteJSON( "JSON_output/test.json", store); 
struct CVErr {
    std::vector<double> cv;
    std::vector<double> err;
};

using JSONStore =
    std::map<std::string,                  // tag
      std::map<std::string,                // variable
        std::map<std::string, CVErr>>>;    // event

void WriteJSON(const std::string& filename, const JSONStore& store) {
    std::ofstream out(filename);
    out << "{\n";

    for (auto t = store.begin(); t != store.end(); ++t) {
        out << "  \"" << t->first << "\": {\n";

        for (auto v = t->second.begin(); v != t->second.end(); ++v) {
            out << "    \"" << v->first << "\": {\n";

            for (auto e = v->second.begin(); e != v->second.end(); ++e) {
                out << "      \"" << e->first << "\": {\n";

                out << "        \"cv\": [";
                for (size_t i = 0; i < e->second.cv.size(); ++i) {
                    out << e->second.cv[i];
                    if (i + 1 < e->second.cv.size()) out << ", ";
                }
                out << "],\n";

                out << "        \"err\": [";
                for (size_t i = 0; i < e->second.err.size(); ++i) {
                    out << e->second.err[i];
                    if (i + 1 < e->second.err.size()) out << ", ";
                }
                out << "]\n";

                out << "      }";
                if (std::next(e) != v->second.end()) out << ",";
                out << "\n";
            }

            out << "    }";
            if (std::next(v) != t->second.end()) out << ",";
            out << "\n";
        }

        out << "  }";
        if (std::next(t) != store.end()) out << ",";
        out << "\n";
    }

    out << "}\n";
}

//void write_array(std::ostream& out, const std::vector<double>& v) {
//    out << "[";
//    for (size_t i = 0; i < v.size(); ++i) {
//        out << v[i];
//        if (i + 1 < v.size()) out << ", ";
//    }
//    out << "]";
//}
//
//void AppendCVErrToJSON(const TString& filename,
//                       const TString& tag,
//                       const TString& variable,
//                       const TString& event,
//                       const std::vector<double>& cv,
//                       const std::vector<double>& err)
//{
//    if (cv.size() != err.size()) {
//        std::cerr << "ERROR: CV and err size mismatch\n";
//        return;
//    }
//
//    // Read existing file if it exists
//    std::ifstream in(filename);
//    std::stringstream buffer;
//    bool file_exists = in.good();
//
//    if (file_exists) {
//        buffer << in.rdbuf();
//    }
//    in.close();
//
//    std::ofstream out(filename);
//
//    // Case 1: new file
//    if (!file_exists || buffer.str().empty()) {
//        out << "{\n";
//        out << "  \"" << tag << "\": {\n";
//    } else {
//        // Remove final "\n}\n"
//        std::string content = buffer.str();
//        content.erase(content.find_last_of('}'));
//        content.erase(content.find_last_of('}'));
//        out << content << ",\n";
//        out << "  \"" << tag << "\": {\n";
//    }
//
//    // Variable block
//    out << "    \"" << variable << "\": {\n";
//    out << "      \"" << event << "\": {\n";
//
//    out << "        \"cv\": ";
//    write_array(out, cv);
//    out << ",\n";
//
//    out << "        \"err\": ";
//    write_array(out, err);
//    out << "\n";
//
//    out << "      }\n";
//    out << "    }\n";
//    out << "  }\n";
//    out << "}\n";
//
//    out.close();
//}



//Histogram Helper
//Print histogram contents as a vector of doble
std::vector<double> HistToCV(const TH1D* h) {
    std::vector<double> v;
    for (int i = 1; i <= h->GetNbinsX(); ++i)
        v.push_back(h->GetBinContent(i));
    return v;
}

std::vector<double> HistToErr(const TH1D* h) {
    std::vector<double> v;
    for (int i = 1; i <= h->GetNbinsX(); ++i)
        v.push_back(h->GetBinError(i));
    return v;
}


std::string PrintSysError(const TH1D* hCV,
                          const std::vector<TH1D*>& variations)
{
    if (!hCV || variations.empty())
        return "Error: Invalid input";

    const int nBins = hCV->GetNbinsX();
    const int nVars = variations.size();

    std::ostringstream cvStream;
    std::ostringstream var1Stream;
    std::ostringstream uncStream;
    std::ostringstream fracStream;

    cvStream  << "\nSummary CV: ";
    var1Stream  << "\nSummary 1st Var: ";
    uncStream << "\nSummary Uncertainty: ";
    fracStream<< "\nSummary Fractional uncertainties, ";

    for (int i = 1; i <= nBins; ++i) {

        double cv = hCV->GetBinContent(i);
        double sqSum = 0.0;

        for (const auto& var : variations) {
            if (!var) continue;
			if(sqSum==0) var1Stream  << std::setprecision(3) << var->GetBinContent(i);	
            double diff = var->GetBinContent(i) - cv;
            sqSum += diff * diff;
        }

        // RMS systematic (multisim style)
        double sys = std::sqrt(sqSum / nVars);

        double frac = (cv != 0.0) ? sys / cv : 0.0;

        // Append values
        cvStream   << std::setprecision(3) <<  cv;
        uncStream  << std::setprecision(3) <<  sys;
        fracStream << std::setprecision(3) <<  frac;

        if (i != nBins) {
            cvStream   << ",";
			var1Stream << ",";
            uncStream  << ",";
            fracStream << ",";
        }
    }

    std::string result =
        cvStream.str() + "\n" +
		var1Stream.str() + "\n" +
        uncStream.str() + "\n" +
        fracStream.str() + "\n";

//    std::cout << result << std::endl;

    return result;
}


std::string PrintHist(TH1D* tmp_hist){

    std::stringstream ss;

    const int nbins = tmp_hist->GetNbinsX();

    // ===== CV (bin contents) =====
    ss << "Summary_CV_bins";
    for(int i = 1; i <= nbins; ++i){
        ss << "," << tmp_hist->GetBinContent(i);
    }
    ss << "\n";

    // ===== Absolute uncertainties =====
    ss << "Summary Uncertainty";
    for(int i = 1; i <= nbins; ++i){
        ss << "," << tmp_hist->GetBinError(i);
    }
    ss << "\n";

//    // ===== Fractional uncertainties =====
//    ss << "Summary Fractional uncertainties";
//    for(int i = 1; i <= nbins; ++i){
//        double content = tmp_hist->GetBinContent(i);
//        double error   = tmp_hist->GetBinError(i);
//
//        double frac = (content != 0.0) ? error / content : 0.0;
//        ss << "," << frac;
//    }
//    ss << "\n";

    return ss.str();
}


void PrintRow( const std::vector<double>& vals)
{
    for (double v : vals) {
        std::cout << ", " << v;
    }
    std::cout << std::endl;
}

void PrintSysErrFromCov( TH1D* cv, TH2D* hCov)
{
			int XBins = cv->GetNbinsX();

			std::cout<<"\nTotal uncertainties (not yet exclude stat. unc.): ";
			for (size_t index = 1; index < XBins+1; ++index) {
				std::cout << std::sqrt(hCov->GetBinContent(index, index)) << ", ";
			}
			std::cout<<"\n"<<std::endl;

//			std::cout<<"\nTotal sys. uncertainties (exclude stat. unc.): ";
//			for (size_t index = 1; index < XBins+1; ++index) {
//				std::cout << std::sqrt(hCov->GetBinContent(index, index)- std::pow(cv->GetBinError(index),2)) << ", ";
//			}

			std::cout<<"\nTotal fractional uncertainties (not yet exclude stat. unc.): ";
			for (size_t index = 1; index < XBins+1; ++index) {
				std::cout << std::sqrt(hCov->GetBinContent(index, index))/ cv->GetBinContent(index) << ", ";
			}
			std::cout<<"\n"<<std::endl;


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

//Assume the distribution is Poisson, take mean=variance
double Chi2PoissonLikelihood(const TH1D* hData, const TH1D* hMC) {

	if(hData->Integral()*hMC->Integral()==0) return 0;

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


//Assume the distribution is Gaussian, take std as independent quantity.
double Chi2Gaussian(const TH1D* hData, const TH1D* hMC) {

    if (hData->Integral() == 0 || hMC->Integral() == 0) return 0;

    int nbins = hData->GetNbinsX();
    double chi2 = 0.0;

    for (int i = 1; i <= nbins; i++) {

        double O = hData->GetBinContent(i);
        double E = hMC->GetBinContent(i);

        // Skip bins with no information
        if (O == 0 && E == 0) continue;

        double sigmaO = hData->GetBinError(i);
        double sigmaE = hMC->GetBinError(i);

        // Combine variances (best practice)
        double sigma2 = sigmaO*sigmaO + sigmaE*sigmaE;

        // Fallback if both are zero
        if (sigma2 <= 0) {
            // reasonable fallback: use Poisson expectation scale
            sigma2 = std::max(1.0, E);
        }

        chi2 += (O - E)*(O - E) / sigma2;
    }

    return chi2;
}



TLatex *GetEstimators( TH1D* data, TH1D* MC){

	TLatex *estimators;//Data/MC ratio, KS Test, Chi^2/(nDoF), Chi^2 p-value;
	double histdata_num = data->Integral();
	double histMC_num = MC->Integral();
	int nDof =  MC->GetNbinsX();

	TString text_ratio; text_ratio.Form("Data/MC=%.2f   ",histdata_num/histMC_num); 

	TString text_ks; text_ks.Form("KS: %.2f   ", MC->KolmogorovTest(data)); 

	//soruce code at https://root.cern.ch/doc/master/TH1_8cxx_source.html#l01995
	std::cout<<"Chi2Test MC->Chi2Test(Data):"<< MC->Chi2Test(data,"WU P")<<std::endl;
	std::cout<<"Chi2Test Data->Chi2Test(MC):"<< data->Chi2Test(MC,"WU P")<<std::endl;


	std::cout<<"Manual check (Poisson ): "<<Chi2PoissonLikelihood (data, MC)<<" p="<< TMath::Prob(Chi2PoissonLikelihood (data, MC), nDof)<<std::endl;
	std::cout<<"Manual check (Gaussian): "<<Chi2Gaussian(data, MC)<<" p="<< TMath::Prob(Chi2Gaussian(data, MC), nDof)<<std::endl;

//Choose one stat. to use
//	TString text_chi2; text_chi2.Form("#chi^{2}/n#it{DoF}=%.2f/%d p=%.2g   ", MC->Chi2Test(data,"UW CHI2"), 
//																			MC->GetNbinsX()-1, 
//																			MC->Chi2Test(data,"UW P"));


//	TString text_chi2; text_chi2.Form("#chi^{2}/n#it{DoF}=%.2f/%d p=%.2g   ", data->Chi2Test(MC,"WW CHI2"), 
//																			MC->GetNbinsX(), 
//																			data->Chi2Test(MC,"UW P"));


	//Manual version
	double chi2 = Chi2Gaussian(data, MC);

	TString text_chi2; text_chi2.Form("#chi^{2}/n#it{DoF}=%.2f/%d p=%.2g   ", chi2, 
																			nDof, 
																			TMath::Prob(chi2, nDof));



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
//	TString text_chi2; text_chi2.Form("#chi^{2}/n#it{DoF}=%.2f/%d p=%.2g   ", MC_copy->Chi2Test(data_copy,"UW CHI2"), 
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


void PrintMultiSimVariation(
    const TH1D* hCV,
    const std::vector<TH1D*>& variations,
	TString label) {
    if (!hCV || variations.empty()) {
        std::cerr << "ERROR: Empty input histograms\n";
        return;
    }

    const int Nbin = hCV->GetNbinsX();
    const int Nuniv = variations.size();

//    std::vector<double> mean(Nbin, 0.0);
    std::vector<double> rms(Nbin, 0.0);
    std::vector<double> rms_stat_removed(Nbin, 0.0);
    std::vector<double> frac_uncertainty(Nbin, 0.0);

    // -----------------------------
    // Mean across universes
    // -----------------------------
//    for (int b = 1; b <= Nbin; ++b) {
//        double sum = 0.0;
//        for (const auto& h : variations)
//            sum += h->GetBinContent(b);
//        mean[b-1] = sum / Nuniv;
//    }

    // -----------------------------
    // RMS (multisim variance)
    // -----------------------------
    for (int b = 1; b <= Nbin; ++b) {
        double var = 0.0;
        for (const auto& h : variations) {
            double diff = h->GetBinContent(b) - hCV->GetBinContent(b);
            var += diff * diff;
        }
        rms[b-1] = std::sqrt(var / Nuniv);  // RMS
    }

    // -----------------------------
    // Remove statistical error
    // -----------------------------
    for (int b = 1; b <= Nbin; ++b) {
        double stat = hCV->GetBinError(b);
        double sys2 = rms[b-1]*rms[b-1] - stat*stat;
        rms_stat_removed[b-1] = (sys2 > 0) ? std::sqrt(sys2) : 0.0;
		frac_uncertainty[b-1] = rms_stat_removed[b-1]/hCV->GetBinContent(b);
    }

    // -----------------------------
    // Printing
    // -----------------------------
    auto print_row = [&](const std::string& label,
                         const std::vector<double>& vals) {
        std::cout << label;
        for (double v : vals)
            std::cout << ", " << v;
        std::cout << "\n";
    };

    // CV row
    std::vector<double> cv(Nbin);
    for (int b = 1; b <= Nbin; ++b)
        cv[b-1] = hCV->GetBinContent(b);

	std::cout<<"Print variations for "<<label<<std::endl;
    print_row("CV", cv);
//    print_row("Mean", mean);
    print_row("RMS (sys+stat)", rms);
    print_row("RMS (stat removed)", rms_stat_removed);
    print_row("Fractional Unvertainties", frac_uncertainty);
}

//Modify histogram and add systematic errors as uncorrelated errors
void AddFractionalSystematics(TH1D* errorHist,
                              const std::vector<double>& frac_err,
							  const TH1D* justMC )
{
    if (!errorHist || !justMC) return;

    int nBins = errorHist->GetNbinsX();

    if ((int)frac_err.size() != nBins) {
        std::cerr << "Size mismatch: frac_err has "
                  << frac_err.size()
                  << " elements, histogram has "
                  << nBins << " bins\n";
        return;
    }

    for (int i = 1; i <= nBins; ++i) {
        double ErrFromContent = justMC->GetBinContent(i);
        double statErrOrig = errorHist->GetBinError(i);

        double systErr = frac_err[i-1] * ErrFromContent;

        double totalErr = std::sqrt(statErrOrig*statErrOrig +
                                    systErr*systErr);

        errorHist->SetBinError(i, totalErr);
    }
}



#endif

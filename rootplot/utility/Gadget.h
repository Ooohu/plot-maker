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


void ExportPNG(TH2F* hist, TString name){
	TCanvas* c = new TCanvas("c","c",800,600);
	hist->Draw("colz");
	c->SaveAs("./output/"+name+".png");
	delete c;
}

void SetHist(TH1D* hist, int line, int fill, int style){
	hist->SetLineColor(line);
	hist->SetFillColor(fill);
	hist->SetFillStyle(style);
}

//Template for drawing different hists
template <typename T>
void ExportPNG(T hist, TString name, TString Xaxis, TString Yaxis= "Events"){
	TCanvas* c = new TCanvas("c","c",800,600);
	hist->Draw("colz");
	hist->GetXaxis()->SetTitle(Xaxis);
	hist->GetYaxis()->SetTitle(Yaxis);
	c->SaveAs("./output/"+name+".png");
	delete c;
}

//Template for drawing different hists
template <typename T>
void ExportPNGwLegend(T hist, TString name, TLegend *leg, TString Xaxis, TString Yaxis= "Events"){
	TCanvas* c = new TCanvas("c","c",800,600);
	TPad *padD = new TPad("padD","padD",0,   0, 1, 0.85);
	TPad *padT = new TPad("padT","padT",0, 0.85, 1,   1);

	padD->Draw();
	padD->cd();
	padD->SetTopMargin(0.2);
	hist->Draw("hist");
	hist->GetXaxis()->SetTitle(Xaxis);
	hist->GetYaxis()->SetTitle(Yaxis);

	c->cd();
	padT->Draw();
	padT->cd();
	leg->Draw();
	c->SaveAs("./output/"+name+".png");
	delete c;
}

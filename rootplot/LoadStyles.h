

TLegend* LoadLegend(){

	TLegend *leg = new TLegend(0.05,0.01,0.95,0.95);
	leg->SetFillStyle(0);
	leg->SetLineWidth(0);
	leg->SetNColumns(3);

	return leg;
}

void SetErrorStyle( TH1D* errorHist){
		errorHist->SetMarkerSize(0);
		errorHist->SetFillStyle(3454);
		errorHist->SetLineWidth(2);
		errorHist->SetLineColor(kBlack);
		errorHist->SetFillColor(kBlack);
}



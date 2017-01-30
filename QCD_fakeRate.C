#include <memory>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <TH2.h>
#include <TH3.h>
#include <THStack.h>
#include <TCanvas.h>
#include "TTree.h"
#include "TFile.h"
#include "TFileCollection.h"
#include "TChain.h"
#include "TText.h"
#include "treeBase_data.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <utility> 
#include <TLorentzVector.h>
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TLatex.h"
#include "TColor.h"
#include "TLine.h"
#include "TROOT.h"
#include <TStyle.h>
#include "TVector3.h"

using namespace std;

void prn(int n, int N, int d, TString& cf, TTree* ch) {

    if (cf != (ch->GetCurrentFile()->GetName())) {
        cout << "\n >> Current File: " << (ch->GetCurrentFile()->GetName()) << endl;
        cf = (ch->GetCurrentFile()->GetName());
    }

    if (n % d == 0) {
        //        fprintf(stdout, "\rProcessed events: \033[1;36;40m%6d of %6d\033[0m", n, N);
        fprintf(stdout, "\rProcessed events: %6d of %6d", n, N);
        fflush(stdout);
    }
    if (n == (N - 1)) {

        fprintf(stdout, "\n");
        fflush(stdout);
    }
}

void CanvasCreator(TH2D * h, string x_title, string y_title, string title, TString pathPNG) {
	
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TCanvas * canvas = new TCanvas(h->GetName(),h->GetName(),350,350,600,600);
        canvas->SetHighLightColor(2);
        canvas->Range(0,0,1,1);
        canvas->SetFillColor(0);
        canvas->SetBorderMode(0);
        canvas->SetBorderSize(2);
        canvas->SetTickx(1);
        canvas->SetTicky(1);
        canvas->SetLeftMargin(0.16);
        canvas->SetRightMargin(0.02);
        canvas->SetTopMargin(0.05);
        canvas->SetBottomMargin(0.13);
        canvas->SetFrameFillStyle(0);
        canvas->SetFrameBorderMode(0);

	h->SetTitle(title.c_str());
	h->SetTitleOffset(1.5);;
	h->GetXaxis()->SetTitle(x_title.c_str());
	h->GetXaxis()->SetTitleOffset(1.25);;
	h->GetYaxis()->SetTitle(y_title.c_str());
	h->GetYaxis()->SetTitleOffset(1.85);;
	h->Draw("COLTEXT");

	pathPNG.Append(h->GetName());
	pathPNG.Append(".png");
        canvas->SaveAs(pathPNG);
}
void CanvasCreator(TH1D * h, string x_title, string y_title, TString pathPNG) {
	
	gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TCanvas * canvas = new TCanvas(h->GetName(),h->GetName(),350,350,500,500);
        canvas->SetHighLightColor(2);
        canvas->Range(0,0,1,1);
        canvas->SetFillColor(0);
        canvas->SetBorderMode(0);
        canvas->SetBorderSize(2);
        canvas->SetTickx(1);
        canvas->SetTicky(1);
        canvas->SetLeftMargin(0.16);
        canvas->SetRightMargin(0.02);
        canvas->SetTopMargin(0.05);
        canvas->SetBottomMargin(0.13);
        canvas->SetFrameFillStyle(0);
        canvas->SetFrameBorderMode(0);

	h->GetXaxis()->SetTitle(x_title.c_str());
	h->GetXaxis()->SetTitleOffset(1.25);;
	h->GetYaxis()->SetTitle(y_title.c_str());
	h->GetYaxis()->SetTitleOffset(1.85);;
	h->SetLineColor(kBlue);
	h->Draw();

	TString name = h->GetName();
	if (name.Contains("pt") && name.Contains("loose")) canvas->SetLogy();

	pathPNG.Append(h->GetName());
	pathPNG.Append(".png");
        canvas->SaveAs(pathPNG);
}

struct Sort{
  bool operator() (std::pair <TH1D*, std::pair <double, double > > comb1, std::pair <TH1D*, std::pair <double, double > > comb2)
        //{return ((comb1.first)->Integral() > (comb2.first)->Integral());}
        {return (((comb1.second).first) < ((comb2.second).first) && ((comb1.second).second) < ((comb2.second).second));}
};

void QCD_fakeRate() {

	TH1::SetDefaultSumw2();


	TH1D * n_loose = new TH1D("n_loose","n_loose",1,1.,2.);
	TH1D * n_tight = new TH1D("n_tight","n_tight",1,1.,2.);

	TString fileNames[4] = {"251116/DiTauData/Tau_Run2016B_PromptReco_v2/H2TauTauTreeProducerTauTau/tree.root","251116/DiTauData/Tau_Run2016C_PromptReco_v2/H2TauTauTreeProducerTauTau/tree.root","251116/DiTauData/Tau_Run2016D_PromptReco_v2/H2TauTauTreeProducerTauTau/tree.root"};

	int gen_match = 6; // fake rate calculation
	double IsoCut = 0.5;

	for (int file = 0; file < 3; file++) {

	TFile* myFile = TFile::Open(fileNames[file]);
	TTree *myTree = (TTree*)(myFile->Get("tree"));

	treeBase_data tr(myTree);

	if (tr.fChain == 0) return;

	Long64_t nentries = tr.fChain->GetEntries();

	TString CurrentFile = "";

	//cout<<"Number of initial entries: "<<nentries<<endl;

    for (Long64_t jentry = 0; jentry < nentries; jentry++) {

        Long64_t ientry = tr.LoadTree(jentry);
        if (ientry < 0) break;
        tr.fChain->GetEntry(jentry);

	if (!(!tr.veto_dilepton && !tr.veto_thirdlepton && !tr.veto_otherlepton)) continue;
	if (!(tr.l1_againstMuon3>0.5 && tr.l1_againstElectronMVA6>0.5 && tr.l1_pt>40.)) continue;
	if (!(tr.l2_againstMuon3>0.5 && tr.l2_againstElectronMVA6>0.5 && tr.l2_pt>40.)) continue;

	if (!(tr.l1_charge == tr.l2_charge)) continue; // SS requirement, to make a pure QCD sample from data
	if (!(tr.pfmet_pt < 30)) continue; // pfmet requirement, to make a pure QCD sample from data, these 2 cuts result in a purity of 98%(94%) for loose(tight) tau selection
	if (tr.l1_byIsolationMVArun2v1DBoldDMwLT>0.5 || tr.l2_byIsolationMVArun2v1DBoldDMwLT>0.5) n_loose->Fill(1.);
	if (tr.l1_byIsolationMVArun2v1DBoldDMwLT>4.5 || tr.l2_byIsolationMVArun2v1DBoldDMwLT>4.5) n_tight->Fill(1.);
	
}
}

	cout<<"*** n_loose->GetBinContent(1): "<<n_loose->GetBinContent(1)<<endl;
	cout<<"*** n_tight->GetBinContent(1): "<<n_tight->GetBinContent(1)<<endl;

	err = sqrt(pow(n_loose->GetBinError(1)/n_loose->GetBinContent(1),2) + pow(n_tight->GetBinError(1)/n_tight->GetBinContent(1),2)) * (n_tight->GetBinContent(1)/n_loose->GetBinContent(1));	
	cout<<"?????????? "<<err<<endl;

	n_tight->Divide(n_loose);
	cout<<"*** FR: "<<n_tight->GetBinContent(1)<<" +- "<<n_tight->GetBinError(1)<<endl;

}

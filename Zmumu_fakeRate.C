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
#include "treeBase_Zmumu.h"
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

void Zmumu_fakeRate() {

	TH1::SetDefaultSumw2();

	double nevents = 0.;
	double nevents_loose = 0.;
	double nevents_tight = 0.;

	TH1D * h_gen_pdgId = new TH1D("gen_pdgId","gen_pdgId",23,0.,23.);

	TH1D * n_loose = new TH1D("n_loose","n_loose",1,1.,2.);
	TH1D * n_tight = new TH1D("n_tight","n_tight",1,1.,2.);

	TH1D * h_pt_loose = new TH1D("pt_loose","pt_loose",13,40.,300.);
	TH1D * h_pt_tight = new TH1D("pt_tight","pt_tight",13,40.,300.);

	TH1D * h_eta_loose = new TH1D("eta_loose","eta_loose",10,-2.5,2.5);
	TH1D * h_eta_tight = new TH1D("eta_tight","eta_tight",10,-2.5,2.5);

	TH1D * h_dm_loose = new TH1D("dm_loose","dm_loose",12,0.,12.);
	TH1D * h_dm_tight = new TH1D("dm_tight","dm_tight",12,0.,12.);

	TH1D * h_jetpt_loose = new TH1D("jetpt_loose","jetpt_loose",15,0.,300.);
	TH1D * h_jetpt_tight = new TH1D("jetpt_tight","jetpt_tight",15,0.,300.);

	//TH1D * h_mt2_loose = new TH1D("mt2_loose","mt2_loose",15,0.,300.);
	//TH1D * h_mt2_tight = new TH1D("mt2_tight","mt2_tight",15,0.,300.);

	TH1D * h_summt_loose = new TH1D("summt_loose","summt_loose",20,0.,600.);
	TH1D * h_summt_tight = new TH1D("summt_tight","summt_tight",20,0.,600.);

	TH1D * h_njets_loose = new TH1D("njets_loose","njets_loose",10,0.,10.);
	TH1D * h_njets_tight = new TH1D("njets_tight","njets_tight",10,0.,10.);

	TString fileName = "/cmsdata2/mzeinali/SUSY_DiTau/CMSSW_8_0_13/src/tree.root";

	double IsoCut = 0.5;
	TString pathPNG = "PlotsFakeRate_Zmumu/";
	mkdir(pathPNG,0777);
	//mkdir(pathPNG.c_str(),0777);

	TFile* myFile = TFile::Open(fileName);
	TTree *myTree = (TTree*)(myFile->Get("tree"));

	treeBase_Zmumu tr(myTree);

	if (tr.fChain == 0) return;

	Long64_t nentries = tr.fChain->GetEntries();

	TString CurrentFile = "";

	cout<<"Number of initial entries: "<<nentries<<endl;

    for (Long64_t jentry = 0; jentry < nentries; jentry++) {

        Long64_t ientry = tr.LoadTree(jentry);
        if (ientry < 0) break;
        tr.fChain->GetEntry(jentry);

	double evt_weight = tr.weight;

	nevents += evt_weight; // x-section weight is not considered since it's unknown! but no matter because it's both used in numerator and denominator.

	double summt = tr.pfmet_mt1+tr.pfmet_mt2;

	int gen_pdgId = fabs(tr.tau1_gen_pdgId);

	if ((gen_pdgId>0 && gen_pdgId<6) || gen_pdgId == 21) h_gen_pdgId->Fill(gen_pdgId);

	if (tr.tau1_byIsolationMVArun2v1DBoldDMwLT>IsoCut && ((gen_pdgId>0 && gen_pdgId<6) || gen_pdgId == 21)) {
		n_loose->Fill(1.,evt_weight);
		nevents_loose += evt_weight;
		h_pt_loose->Fill(tr.tau1_pt,evt_weight);
		h_eta_loose->Fill(tr.tau1_eta,evt_weight);
		h_dm_loose->Fill(tr.tau1_decayMode,evt_weight);
		h_jetpt_loose->Fill(tr.tau1_jet_pt,evt_weight);
		//h_mt2_loose->Fill(tr.mt2,evt_weight);
		h_summt_loose->Fill(summt,evt_weight);
		h_njets_loose->Fill(tr.n_jets,evt_weight);
	}
	if (tr.tau1_byIsolationMVArun2v1DBoldDMwLT>4.5 && ((gen_pdgId>0 && gen_pdgId<6) || gen_pdgId == 21)) {
		n_tight->Fill(1.,evt_weight);
		nevents_tight += evt_weight;
		h_pt_tight->Fill(tr.tau1_pt,evt_weight);
		h_eta_tight->Fill(tr.tau1_eta,evt_weight);
		h_dm_tight->Fill(tr.tau1_decayMode,evt_weight);
		h_jetpt_tight->Fill(tr.tau1_jet_pt,evt_weight);
		//h_mt2_tight->Fill(tr.mt2,evt_weight);
		h_summt_tight->Fill(summt,evt_weight);
		h_njets_tight->Fill(tr.n_jets,evt_weight);
	}

}
	cout<<"events with tr.weight: "<<nevents<<endl;

	CanvasCreator(h_gen_pdgId,"pdg","genid",pathPNG);		

	TH1D * h_loose = new TH1D("h_loose","h_loose",1,0.,1.);
	TH1D * h_tight = new TH1D("h_tight","h_tight",1,0.,1.);
	h_loose->SetBinContent(1,nevents_loose);
	h_loose->SetBinError(1,sqrt(nevents_loose));
	h_tight->SetBinContent(1,nevents_tight);
	h_tight->SetBinError(1,sqrt(nevents_tight));

	double err = sqrt(pow(h_loose->GetBinError(1)/h_loose->GetBinContent(1),2) + pow(h_tight->GetBinError(1)/h_tight->GetBinContent(1),2)) * (h_tight->GetBinContent(1)/h_loose->GetBinContent(1));	
	cout<<"--- error calculation, in another way: "<<err<<endl;

	h_tight->Divide(h_loose);
	cout<<"*** FR: "<<h_tight->GetBinContent(1)<<" +- "<<h_tight->GetBinError(1)<<endl;
	cout<<"---------------------"<<endl;
	cout<<"*** n_loose->GetBinContent(1): "<<n_loose->GetBinContent(1)<<endl;
	cout<<"*** n_tight->GetBinContent(1): "<<n_tight->GetBinContent(1)<<endl;

	err = sqrt(pow(n_loose->GetBinError(1)/n_loose->GetBinContent(1),2) + pow(n_tight->GetBinError(1)/n_tight->GetBinContent(1),2)) * (n_tight->GetBinContent(1)/n_loose->GetBinContent(1));	
	cout<<"?????????? "<<err<<endl;

	n_tight->Divide(n_loose);
	cout<<"*** FR: "<<n_tight->GetBinContent(1)<<" +- "<<n_tight->GetBinError(1)<<endl;

////

	CanvasCreator(h_pt_loose,"p_{T}","Loose fake #taus",pathPNG);		
	CanvasCreator(h_pt_tight,"p_{T}","Tight fake #taus",pathPNG);		

	TH1D * h_FR_pt = (TH1D*) h_pt_tight->Clone("h_FR_pt");
	h_FR_pt->Divide(h_pt_loose);
	CanvasCreator(h_FR_pt,"p_{T}","Fake Rate",pathPNG);		
////

        CanvasCreator(h_eta_loose,"#eta","Loose fake #taus",pathPNG);     
        CanvasCreator(h_eta_tight,"#eta","Tight fake #taus",pathPNG);     

	TH1D * h_FR_eta = (TH1D*) h_eta_tight->Clone("h_FR_eta");
	h_FR_eta->Divide(h_eta_loose);
	CanvasCreator(h_FR_eta,"#eta","Fake Rate",pathPNG);		
////

        CanvasCreator(h_dm_loose,"decay mode","Loose fake #taus",pathPNG);     
        CanvasCreator(h_dm_tight,"decay mode","Tight fake #taus",pathPNG);     

	TH1D * h_FR_dm = (TH1D*) h_dm_tight->Clone("h_FR_dm");
	h_FR_dm->Divide(h_dm_loose);
	CanvasCreator(h_FR_dm,"decay mode","Fake Rate",pathPNG);		
////

	CanvasCreator(h_jetpt_loose,"associated jet p_{T}","Loose fake #taus",pathPNG);		
	CanvasCreator(h_jetpt_tight,"associated jet p_{T}","Tight fake #taus",pathPNG);		

	TH1D * h_FR_jetpt = (TH1D*) h_jetpt_tight->Clone("h_FR_jetpt");
	h_FR_jetpt->Divide(h_jetpt_loose);
	CanvasCreator(h_FR_jetpt,"associated jet p_{T}","Fake Rate",pathPNG);		
////
/*
        CanvasCreator(h_mt2_loose,"M_{T2}","Events with loose fake #taus",pathPNG);     
        CanvasCreator(h_mt2_tight,"M_{T2}","Events with tight fake #taus",pathPNG);     

	TH1D * h_FR_mt2 = (TH1D*) h_mt2_tight->Clone("h_FR_mt2");
	h_FR_mt2->Divide(h_mt2_loose);
	CanvasCreator(h_FR_mt2,"M_{T2}","Fake Rate",pathPNG);		
*/
////

        CanvasCreator(h_summt_loose,"M_{T}^{#tau1}+M_{T}^{#tau2}","Events with loose fake #taus",pathPNG);     
        CanvasCreator(h_summt_tight,"M_{T}^{#tau1}+M_{T}^{#tau2}","Events with tight fake #taus",pathPNG);     

	TH1D * h_FR_summt = (TH1D*) h_summt_tight->Clone("h_FR_summt");
	h_FR_summt->Divide(h_summt_loose);
	CanvasCreator(h_FR_summt,"M_{T}^{#tau1}+M_{T}^{#tau2}","Fake Rate",pathPNG);		
////

        CanvasCreator(h_njets_loose,"N_{jets}","Events with loose fake #taus",pathPNG);     
        CanvasCreator(h_njets_tight,"N_{jets}","Events with tight fake #taus",pathPNG);     

	TH1D * h_FR_njets = (TH1D*) h_njets_tight->Clone("h_FR_njets");
	h_FR_njets->Divide(h_njets_loose);
	CanvasCreator(h_FR_njets,"N_{jets}","Fake Rate",pathPNG);		
////

}

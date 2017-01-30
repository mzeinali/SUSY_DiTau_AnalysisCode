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
#include "treeBase_251116.h"
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

void CanvasCreator(TH1D * h1, TH1D * h2, string m_name, string legend_name) {
	
	//gStyle->SetOptTitle(0);
	gStyle->SetOptStat(0);

	TCanvas * canvas = new TCanvas(m_name.c_str(),m_name.c_str(),632,112,500,502);
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

	h1->SetTitle(legend_name.c_str());
	h1->SetLineColor(2);
	h2->SetLineColor(4);
	h1->SetMaximum(20);
	h1->Draw();
	//h2->SetLineStyle(3);
        h2->Draw("same");

   TLegend * leg = new TLegend(0.6,0.5,0.9,0.7);
   leg->AddEntry(h1,"caloMET","f");
   leg->AddEntry(h2,"pfMET","f");
   leg->Draw();

	//canvas->SetLogy();
        canvas->SaveAs((m_name+legend_name+".png").c_str());
        canvas->SaveAs((m_name+legend_name+".C").c_str());
}

struct Sort{
  bool operator() (std::pair <TH1D*, std::pair <double, double > > comb1, std::pair <TH1D*, std::pair <double, double > > comb2)
        //{return ((comb1.first)->Integral() > (comb2.first)->Integral());}
        {return (((comb1.second).first) < ((comb2.second).first) && ((comb1.second).second) < ((comb2.second).second));}
};

void FakeRate() {

	TH1::SetDefaultSumw2();

	TFile* myFile = TFile::Open("251116/DiTauMC/W1JetsToLNu_LO/H2TauTauTreeProducerTauTau/tree.root");
	//TFile* myFile = TFile::Open("251116/DiTauMC/W2JetsToLNu_LO/H2TauTauTreeProducerTauTau/tree.root");
	//TFile* myFile = TFile::Open("251116/DiTauMC/W3JetsToLNu_LO/H2TauTauTreeProducerTauTau/tree.root");
	//TFile* myFile = TFile::Open("251116/DiTauMC/W4JetsToLNu_LO/H2TauTauTreeProducerTauTau/tree.root");
	TTree *myTree = (TTree*)(myFile->Get("tree"));

	treeBase_251116 tr(myTree);

	if (tr.fChain == 0) return;

	Long64_t nentries = tr.fChain->GetEntries();

	TString CurrentFile = "";

	double nevents = 0;
	cout<<"Number of initial entries: "<<nentries<<endl;

	TH2I * h_gen_match = new TH2I("gen_match","gen_match",7,0,7,7,0,7);
	TH2I * h_isolation = new TH2I("isolation","isolation",14,0,7,14,0,7);

	TH1D * h_pt_loose = new TH1D("pt_loose","pt_loose",32,40.,200.);
	TH1D * h_pt_tight = new TH1D("pt_tight","pt_tight",32,40.,200.);

	TH1D * h_eta_loose = new TH1D("eta_loose","eta_loose",50,-2.5,2.5);
	TH1D * h_eta_tight = new TH1D("eta_tight","eta_tight",50,-2.5,2.5);

	TH1D * h_dm_loose = new TH1D("dm_loose","dm_loose",12,0.,12.);
	TH1D * h_dm_tight = new TH1D("dm_tight","dm_tight",12,0.,12.);

    double xsec_weight = 9644.5 * 12918.1407 / 39855520.0;
    //double xsec_weight = 3144.5 * 12918.1407 / 29984239.0; 
    //double xsec_weight = 954.8 * 12918.1407 / 19869053.0; 
    //double xsec_weight = 485.6 * 12918.1407 / 9174756.0; 

    for (Long64_t jentry = 0; jentry < nentries; jentry++) {

        Long64_t ientry = tr.LoadTree(jentry);
        if (ientry < 0) break;
        tr.fChain->GetEntry(jentry);

	if (!(!tr.veto_dilepton && !tr.veto_thirdlepton && !tr.veto_otherlepton)) continue;
	if (!(tr.l1_againstMuon3>0.5 && tr.l1_againstElectronMVA6>0.5 && tr.l1_pt>40.)) continue;
	if (!(tr.l2_againstMuon3>0.5 && tr.l2_againstElectronMVA6>0.5 && tr.l2_pt>40.)) continue;
	if (!(tr.l1_charge != tr.l2_charge)) continue;

	//if (!(tr.l1_byIsolationMVArun2v1DBoldDMwLT>2.5)) continue;
	//if (!(tr.l2_byIsolationMVArun2v1DBoldDMwLT>2.5)) continue;
	
	double evt_weight = tr.weight * xsec_weight;

	nevents += evt_weight;

	if (tr.l1_byIsolationMVArun2v1DBoldDMwLT>0.5 || tr.l2_byIsolationMVArun2v1DBoldDMwLT>0.5) {
		h_gen_match->Fill(tr.l1_gen_match,tr.l2_gen_match,evt_weight);
		h_isolation->Fill(tr.l1_byIsolationMVArun2v1DBoldDMwLT,tr.l2_byIsolationMVArun2v1DBoldDMwLT,evt_weight);
	}

	if (tr.l1_byIsolationMVArun2v1DBoldDMwLT>0.5 && tr.l1_gen_match == 6) {
		h_pt_loose->Fill(tr.l1_pt,evt_weight);
		h_eta_loose->Fill(tr.l1_eta,evt_weight);
		h_dm_loose->Fill(tr.l1_decayMode,evt_weight);
	}
	if (tr.l2_byIsolationMVArun2v1DBoldDMwLT>0.5 && tr.l2_gen_match == 6) {
		h_pt_loose->Fill(tr.l2_pt,evt_weight);
		h_eta_loose->Fill(tr.l2_eta,evt_weight);
		h_dm_loose->Fill(tr.l2_decayMode,evt_weight);
	}
	
	//if (!(tr.l1_byIsolationMVArun2v1DBoldDMwLT>4.5)) continue;
	//if (!(tr.l2_byIsolationMVArun2v1DBoldDMwLT>4.5)) continue;
	
	if (tr.l1_byIsolationMVArun2v1DBoldDMwLT>4.5 && tr.l1_gen_match == 6) {
		h_pt_tight->Fill(tr.l1_pt,evt_weight);
		h_eta_tight->Fill(tr.l1_eta,evt_weight);
		h_dm_tight->Fill(tr.l1_decayMode,evt_weight);
	}
	if (tr.l2_byIsolationMVArun2v1DBoldDMwLT>4.5 && tr.l2_gen_match == 6) {
		h_pt_tight->Fill(tr.l2_pt,evt_weight);
		h_eta_tight->Fill(tr.l2_eta,evt_weight);
		h_dm_tight->Fill(tr.l2_decayMode,evt_weight);
	}
	
}
	cout<<"*** yields: "<<nevents<<endl;

	TFile * myfile = new TFile("W1JetsToLNu_IsoCut05.root","recreate");

	h_gen_match->SetTitle("W1JetsToLNu");
	h_gen_match->GetXaxis()->SetTitle("l1_gen_match");
	h_gen_match->GetYaxis()->SetTitle("l2_gen_match");
	h_gen_match->Write();

	h_isolation->SetTitle("W1JetsToLNu");
	h_isolation->GetXaxis()->SetTitle("l1_byIsolationMVArun2v1DBoldDMwLT");
	h_isolation->GetYaxis()->SetTitle("l2_byIsolationMVArun2v1DBoldDMwLT");
	h_isolation->Write();
////
	h_pt_loose->SetTitle("W1JetsToLNu");
	h_pt_loose->GetXaxis()->SetTitle("p_{T}");
	h_pt_loose->GetYaxis()->SetTitle("Loose #taus with gen_match == 6");
	h_pt_loose->Write();

	h_pt_tight->SetTitle("W1JetsToLNu");
	h_pt_tight->GetXaxis()->SetTitle("p_{T}");
	h_pt_tight->GetYaxis()->SetTitle("Tight #taus with gen_match == 6");
	h_pt_tight->Write();

	TH1D * h_FR_pt = (TH1D*) h_pt_tight->Clone("h_FR_pt");
	h_FR_pt->SetTitle("W1JetsToLNu - fake rate");
	h_FR_pt->GetXaxis()->SetTitle("p_{T}");
	h_FR_pt->GetYaxis()->SetTitle("Loose / Tight");
	h_FR_pt->Divide(h_pt_loose);
	h_FR_pt->Write();
////
	h_eta_loose->SetTitle("W1JetsToLNu");
	h_eta_loose->GetXaxis()->SetTitle("#eta");
	h_eta_loose->GetYaxis()->SetTitle("Loose #taus with gen_match == 6");
	h_eta_loose->Write();

	h_eta_tight->SetTitle("W1JetsToLNu");
	h_eta_tight->GetXaxis()->SetTitle("#eta");
	h_eta_tight->GetYaxis()->SetTitle("Tight #taus with gen_match == 6");
	h_eta_tight->Write();

	TH1D * h_FR_eta = (TH1D*) h_eta_tight->Clone("h_FR_eta");
	h_FR_eta->SetTitle("W1JetsToLNu - fake rate");
	h_FR_eta->GetXaxis()->SetTitle("#eta");
	h_FR_eta->GetYaxis()->SetTitle("Loose / Tight");
	h_FR_eta->Divide(h_eta_loose);
	h_FR_eta->Write();
////
	h_dm_loose->SetTitle("W1JetsToLNu");
	h_dm_loose->GetXaxis()->SetTitle("decay mode");
	h_dm_loose->GetYaxis()->SetTitle("Loose #taus with gen_match == 6");
	h_dm_loose->Write();

	h_dm_tight->SetTitle("W1JetsToLNu");
	h_dm_tight->GetXaxis()->SetTitle("decay mode");
	h_dm_tight->GetYaxis()->SetTitle("Tight #taus with gen_match == 6");
	h_dm_tight->Write();

	TH1D * h_FR_dm = (TH1D*) h_dm_tight->Clone("h_FR_dm");
	h_FR_dm->SetTitle("W1JetsToLNu - fake rate");
	h_FR_dm->GetXaxis()->SetTitle("decay mode");
	h_FR_dm->GetYaxis()->SetTitle("Loose / Tight");
	h_FR_dm->Divide(h_dm_loose);
	h_FR_dm->Write();
////
        myfile->Close();

}
/*
)))))) hist.name:  W1Jets
)))))) hist.integral weighted:  112.743965149
)))))) hist.integral unweighted:  36.0663386583
         -->> entries found:  73.0
         w:  112.743965149  and error:  14.123093446
         u:  36.0663386583  and error:  4.51792050052
)))))) hist.name:  W2Jets
)))))) hist.integral weighted:  83.8979568481
)))))) hist.integral unweighted:  61.9288195968
         -->> entries found:  114.0
         w:  83.8979568481  and error:  8.40984408492
         u:  61.9288195968  and error:  6.20768063328
)))))) hist.name:  W3Jets
)))))) hist.integral weighted:  31.9809514284
)))))) hist.integral unweighted:  51.5176604986
         -->> entries found:  89.0
         w:  31.9809514284  and error:  3.59562746388
         u:  51.5176604986  and error:  5.79214514715
)))))) hist.name:  W4Jets
)))))) hist.integral weighted:  17.2988674045
)))))) hist.integral unweighted:  25.3007566929
         -->> entries found:  47.0
         w:  17.2988674045  and error:  2.65301851042
         u:  25.3007566929  and error:  3.88021789974
*/

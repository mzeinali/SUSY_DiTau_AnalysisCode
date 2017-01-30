#include <memory>
#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <TH2.h>
#include <THStack.h>
#include <TCanvas.h>
#include "TTree.h"
#include "TFile.h"
#include "TFileCollection.h"
#include "TChain.h"
#include "TText.h"
#include "treeBase.h"
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

void Macro() {
TFile* myFile = TFile::Open("getMT2Hemi/tree.root");

TTree *myTree = (TTree*)(myFile->Get("tree"));

treeBase tr(myTree);

    if (tr.fChain == 0) return;

    Long64_t nentries = tr.fChain->GetEntries();

    TString CurrentFile = "";

    int nevents = 0;
    cout<<"Number of initial entries: "<<nentries<<endl;

    TH1D * h_MT2 = new TH1D("h","h",150,0,150);
    TH2D * h_Counting = new TH2D("h_Counting","h_Counting",1000,0.,1000.,1000,0.,1000.);

    for (Long64_t jentry = 0; jentry < nentries; jentry++) {

        Long64_t ientry = tr.LoadTree(jentry);
        if (ientry < 0) break;
        tr.fChain->GetEntry(jentry);

        //prn(jentry, nentries, 100, CurrentFile, tr.fChain);
	//if (tr.mt2<0.01) {

		nevents++;

	TVector3 l1;
	l1.SetPtEtaPhi(tr.l1_pt,tr.l1_eta,tr.l1_phi);

	TVector3 l2;
	l2.SetPtEtaPhi(tr.l2_pt,tr.l2_eta,tr.l2_phi);

	TVector3 met;
	met.SetPtEtaPhi(tr.pfmet_pt,0,tr.pfmet_phi);
/*		
	cout<<"l1 pt: "<<tr.l1_pt<<", l1 eta: "<<tr.l1_eta<<", l1 phi: "<<tr.l1_phi<<endl;		
	cout<<"l1 x: "<<l1.x()<<endl;		
	cout<<"l1 y: "<<l1.y()<<endl;		
	cout<<"l1 z: "<<l1.z()<<endl;		
	cout<<""<<endl;
*/

	TVector3 vis;
	vis.SetXYZ(l1.x()+l2.x(),l1.y()+l2.y(),l1.z()+l2.z());

	TVector3 unvis;
	unvis.SetXYZ(met.x(),met.y(),0);

	//cout<<""<<endl;
	//cout<<"(l1+l2).MET: "<<vis.Dot(unvis)<<endl;

	double visDotUnvis = vis.Dot(unvis);
	if (visDotUnvis>0) h_MT2->Fill(tr.mt2);


	//}

  
}
        TCanvas * canvas = new TCanvas("c1","c1",632,112,500,502);

	canvas->cd();
	h_MT2->Draw();
	canvas->SaveAs("mt2.pdf");
	canvas->SaveAs("mt2.png");

    cout<<"Number of events with mt2=0: "<<nevents<<endl;

}

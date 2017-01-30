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

void DrawSMS() {

	TH1::SetDefaultSumw2();

	TFile * f = new TFile("SMS_TChipmStauSnu/H2TauTauTreeProducerTauTau/tree.root");
	TH3D * myWeights = (TH3D*)f->Get("SumGenWeightsSMS");

	TFile* myFile = TFile::Open("251116/DiTauMC/SMS_TChipmStauSnu/H2TauTauTreeProducerTauTau/tree.root");
	TTree *myTree = (TTree*)(myFile->Get("tree"));

	treeBase_251116 tr(myTree);

	if (tr.fChain == 0) return;

	Long64_t nentries = tr.fChain->GetEntries();

	TString CurrentFile = "";

	double nevents = 0;
	cout<<"Number of initial entries: "<<nentries<<endl;

	TH2D * h_Counting = new TH2D("h_Counting","h_Counting",1000,0.,1000.,1000,0.,1000.);
	TH2D * h_Yields = new TH2D("h_Yields","h_Yields",1000,0.,1000.,1000,0.,1000.);
	TH1D * h_xsec = new TH1D("h_xsec","h_xsec",1000,0.,1000.);

	ifstream fin("xsec_C1C1_wino.txt");

	double chiMass;
	double xsection;
	double error;
	vector<std::pair <double, double > > XSections;

	while (fin >> chiMass >> xsection >> error) {
		h_xsec->Fill(chiMass,xsection);
		XSections.push_back(std::make_pair(chiMass,xsection));
	}


    //bool binI = true;	
    bool binI = false;	
    int DM = 200;
    vector <std::pair <TH1D*, std::pair <double, double > > > mt2s;

    TH1D * all = NULL;
    if (binI && DM == 200) all = new TH1D("high_stat","high stat.",15,90.,240.);	
    if (binI && DM == 400) all = new TH1D("high_stat","high stat.",40,90.,490.);	
    //else if (!binI) all = new TH1D("high_stat","high stat.",60,0.,600.);	
    else if (!binI) all = new TH1D("high_stat","high stat.",100,0.,1500.);	


    for (Long64_t jentry = 0; jentry < nentries; jentry++) {

        Long64_t ientry = tr.LoadTree(jentry);
        if (ientry < 0) break;
        tr.fChain->GetEntry(jentry);

	if (!(!tr.veto_dilepton && !tr.veto_thirdlepton && !tr.veto_otherlepton)) continue;
	if (!(tr.l1_againstMuon3>0.5 && tr.l1_againstElectronMVA6>0.5 && tr.l1_pt>40.)) continue;
	if (!(tr.l2_againstMuon3>0.5 && tr.l2_againstElectronMVA6>0.5 && tr.l2_pt>40.)) continue;
	if (!(tr.l1_byIsolationMVArun2v1DBoldDMwLT>4.5)) continue;
	if (!(tr.l2_byIsolationMVArun2v1DBoldDMwLT>4.5)) continue;
	if (!(tr.l1_charge != tr.l2_charge)) continue;
	if (!(tr.pfmet_pt > 30)) continue;
	if (!(tr.mvis > 85 || tr.mvis < 55)) continue;
	if (!(tr.mt2 > 20)) continue;

	// ++++ SR I +++++++++++
	//if (!(tr.mt2 > 90)) continue;
	
	// ++++ SR II +++++++++++
	if (!(tr.mt2 < 90)) continue;
	//if (!(tr.mt2 < 90 && (tr.pfmet_mt1+tr.pfmet_mt2) > 250)) continue;
	
	// ++++ SR III +++++++++++
	//if (!(tr.mt2 < 90/* && (tr.pfmet_mt1+tr.pfmet_mt2) > 200*/)) continue;
	
	//if (!(tr.GenSusyMChargino == 400 && tr.GenSusyMNeutralino == 1)) continue;
	//if (!(tr.GenSusyMChargino == 200 && tr.GenSusyMNeutralino == 1)) continue;

	nevents += tr.weight;

	if (tr.GenSusyMChargino != 0 || tr.GenSusyMNeutralino != 0)
		h_Counting->Fill(tr.GenSusyMChargino,tr.GenSusyMNeutralino,tr.weight);

	//if (tr.GenSusyMChargino>400) continue;
	if (!(fabs( tr.GenSusyMChargino - tr.GenSusyMNeutralino - DM ) < 5)) continue;

	// just to start the vector from (250,50) and remove (200,1)/(225,25) since the behaviour is not interesting!
	if (DM == 200 && !( tr.GenSusyMChargino >= 250 && tr.GenSusyMNeutralino >= 50)) continue;

	// just to start the vector from (175,75) and remove (100,1)/(125,25)/(150,50)/(175,75) to get closer to (180,60), the point we used in 8 TeV!
	if (DM == 100 && !( tr.GenSusyMChargino >= 200 && tr.GenSusyMNeutralino >= 100)) continue;

	stringstream ss1;
	stringstream ss2;
	ss1 << tr.GenSusyMChargino;
	ss2 << tr.GenSusyMNeutralino;
	TString name = "h_";
	name.Append(ss1.str());
	name.Append(ss2.str());

	TH1D * h = NULL;
	if (binI && DM == 200) h = new TH1D(name,name,15,90.,240.);	
	if (binI && DM == 400) h = new TH1D(name,name,40,90.,490.);	
	//else if (!binI) h = new TH1D(name,name,60,0.,600.);	
	else if (!binI) h = new TH1D(name,name,100,0.,1500.);	

	//h->Fill(tr.mt2);
	if (binI) h->Fill(tr.mt2,tr.weight);
	if (!binI) h->Fill(tr.pfmet_mt1+tr.pfmet_mt2,tr.weight);
	bool newmember = false;

	for (unsigned int s = 0; s < mt2s.size(); s++) {

		if (((mt2s[s].second).first) == tr.GenSusyMChargino && ((mt2s[s].second).second) == tr.GenSusyMNeutralino) {
			mt2s[s].first->Add(h);
			newmember = true;
		}

	}
	if (newmember == false)
		mt2s.push_back(std::make_pair(h,std::make_pair(tr.GenSusyMChargino,tr.GenSusyMNeutralino)));
	//delete h;
}

	for (int i = 1; i <= h_Counting->GetXaxis()->GetNbins(); i++) {
		double xsec= 0.;		
		for (unsigned int s = 0; s < XSections.size(); s++) {
			if (XSections[s].first == i) xsec = XSections[s].second;
		}
		for (int j = 1; j <= h_Counting->GetYaxis()->GetNbins(); j++) {

			int global = myWeights->FindBin(i,j);
			double sumWeight = myWeights->GetBinContent(global);

			if (sumWeight== 0) continue; 	
			//if (i == 400 && j == 1) {
			//cout<<""<<endl;
			//cout<<">>> myWeights->FindBin(i,j): "<<global<<endl;
			//cout<<">>> myWeights->GetBinContent(global): "<<sumWeight<<endl;
			//cout<<">>> xsec: "<<xsec<<endl;

		        global = h_Counting->FindBin(i,j);
			double content = h_Counting->GetBinContent(global);
			//cout<<">>> h_Counting->FindBin(i,j): "<<global<<endl;
			//cout<<">>> h_Counting->GetBinContent(global): "<<content<<endl;

			double yield = content * xsec * 12918.1407 / (sumWeight * 1000.);

			h_Yields->SetBinContent(global,yield);


			for (unsigned int s = 0; s < mt2s.size(); s++) {

				if (!(((mt2s[s].second).first) == i && ((mt2s[s].second).second) == j)) continue;
				mt2s[s].first->Scale(xsec * 12918.1407 / (sumWeight * 1000.));
			}			

			//}	

		}
	}

Sort mySort;
std::sort(mt2s.begin(), mt2s.end(), mySort);

for (unsigned int s = 0; s < mt2s.size(); s++) {
// the following line is the way how to define all histogram
if(DM == 100 && !(((mt2s[s].second).first) < 300)) continue;
if(DM == 200 && !(((mt2s[s].second).first) < 350)) continue; // this point is starting from (250,50)!
if(DM == 400 && !(((mt2s[s].second).first) < 500)) continue;
all->Add(mt2s[s].first);
cout<<">>>  all integral: "<<all->Integral()<<endl;
int xbin = (((mt2s[s].second).first) - DM)/25;

TH1D * scaleAll = (TH1D*) all->Clone();
scaleAll->Scale(mt2s[0].first->Integral()/all->Integral());

double diff = 0.;
for (int b = 0; b < all->GetNbinsX(); b++)
diff += pow(scaleAll->GetBinContent(b+1)-mt2s[0].first->GetBinContent(b+1),2);

cout<<"		xbin: "<<xbin<<", (m_chi,m_nu): ("<<((mt2s[s].second).first)<<" , "<<((mt2s[s].second).second)<<")"<<", diff: "<<sqrt(diff)<<endl;

}
//cout<<">>>>>>>. mt2s.size() "<<mt2s.size()<<endl;
//cout<<">>>>>>>. mchi: "<<(mt2s[0].second).first<<endl;
//cout<<">>>>>>>. mneu: "<<(mt2s[0].second).second<<endl;
////////////////////////////////////////////////////////////////////////////////
//

int maxbin = h_Yields->GetMaximumBin();
cout<<"^^^ maximum bin: "<<maxbin<<" , and maximum yields: "<<h_Yields->GetBinContent(maxbin)<<endl;
int x = 0;
int y = 0;
int binWithMaxVal = -100;
double maxContent = 0;
for (int i = 1; i <= h_Yields->GetXaxis()->GetNbins(); i++) {
	for (int j = 1; j <= h_Yields->GetYaxis()->GetNbins(); j++) {
		int global = h_Yields->FindBin(i,j);
		double content = h_Yields->GetBinContent(global);
		if (content != 0 && content > maxContent) {
			binWithMaxVal = global;
			maxContent = content;
		}	
	}
}
for (int i = 1; i <= h_Yields->GetXaxis()->GetNbins(); i++) {
	for (int j = 1; j <= h_Yields->GetYaxis()->GetNbins(); j++) {
		int global = h_Yields->FindBin(i,j);
		double content = h_Yields->GetBinContent(global);
		if (global == binWithMaxVal) cout<<"binWithMaxVal: "<<binWithMaxVal<<", mchi = "<<i<<", mnu = "<<j<<" , Yields = "<<content<<endl;
		}	
}
THStack * myStack = new THStack("hs","");
int c = 0;
int step = DM;
TH1D * MT2_400_1 = (TH1D*)mt2s[0].first->Clone();

for (unsigned int s = 0; s < 5 /*mt2s.size()*/; s++)
{
//TColor *color;
//int mycol = color->GetColor(0+c,0+5*c,0+10*c);

//if(!(((mt2s[s].second).first) == step)) continue;
//if(((mt2s[s].second).first) == DM && ((mt2s[s].second).second) == 1) {MT2_400_1 = (TH1D*)mt2s[0].first->Clone();}}
cout<<"+++++++++ ( "<<(mt2s[s].second).first<<" , "<<(mt2s[s].second).second<<" )"<<" , integral: "<<mt2s[s].first->Integral()<<endl;
mt2s[s].first->Scale(1./mt2s[s].first->Integral());
if (s==0) {
mt2s[s].first->SetLineColor(c+1);
mt2s[s].first->SetFillColor(c+1);
}
else {
mt2s[s].first->SetLineColor(c+1);
mt2s[s].first->SetLineWidth(3);
mt2s[s].first->SetLineStyle(c+1);
}
myStack->Add(mt2s[s].first);

c++;
step+=100;
}


//++++++++++++++++++++++++++++++++++++++++
// this piece compares a single versus all
// distribution
/*
MT2_400_1->SetLineColor(1);
MT2_400_1->SetFillColor(1);

all->SetLineColor(2);
all->SetLineWidth(3);

all->Scale(MT2_400_1->Integral()/all->Integral());
myStack->Add(MT2_400_1);
myStack->Add(all);
*/
//++++++++++++++++++++++++++++++++++++++++

double err = 0.;
cout<<"400_1 integral: "<<MT2_400_1->Integral()<<endl;
MT2_400_1->IntegralAndError(1,MT2_400_1->GetNbinsX(),err);
cout<<"MT2_400_1 err: "<<err<<endl;
cout<<"all integral: "<<all->Integral()<<endl;
all->IntegralAndError(1,all->GetNbinsX(),err);
cout<<"all err: "<<err<<endl;
all->Sumw2();
all->Scale(MT2_400_1->Integral()/all->Integral());
cout<<"**** scaling ***** all integral: "<<all->Integral()<<endl;
all->IntegralAndError(1,all->GetNbinsX(),err);
cout<<"**** scaling ***** all err: "<<err<<endl;

TCanvas * canvas = new TCanvas("c1","c1",632,112,500,502);
canvas->cd();
//canvas->Divide(2,1);
//canvas->cd(1);
//canvas->cd(2);
myStack->Draw("hist nostack");
//myStack->Draw("hist");
if (binI) myStack->GetXaxis()->SetTitle("M_{T2}");
if (!binI) myStack->GetXaxis()->SetTitle("#Sigma M_{T}");
TString name = "Normalized to #int";
name.Append(mt2s[0].first->GetName());
//myStack->GetYaxis()->SetTitle(name);
myStack->GetYaxis()->SetTitle("Normalized to 1.");
//myStack->GetYaxis()->SetTitleOffset(1.05);
myStack->GetYaxis()->SetTitleOffset(1.45);
myStack->SetTitle("++ nostack ++");
//myStack->SetTitle("++ 'single' vs 'a few' SMS points ++");
//myStack->Draw("nostack");
//canvas->cd(2);
canvas->BuildLegend();
canvas->SaveAs("summt_200_nostack.png");
//canvas->SaveAs("summt_100_stack.png");
canvas->SetLogy();
canvas->SaveAs("summt_200_nostack_logY.png");
//canvas->SaveAs("summt_100_stack_logY.png");

//
//
///////////////////////////////////////////////////////////////////////////////

	//cout<<"Number of unweighted events (400,1): "<<nevents<<endl;
	int mchi = DM;
	int mnue = 1;

	int global = h_Counting->FindBin(mchi,mnue);
	double content = h_Counting->GetBinContent(global);

	cout<<"**** unweighted (400,1): "<<content<<endl;	

	global = h_Yields->FindBin(mchi,mnue);
	content = h_Yields->GetBinContent(global);

	//cout<<">>> h_Yields->FindBin("<<mchi<<","<<mnue<<"): "<<global<<endl;
	cout<<">>> h_Yields->GetBinContent("<<mchi<<","<<mnue<<"): "<<content<<endl;

	int xmax = -1;
	int ymax = -1;
	double maxYield = 0.;
	for (unsigned int s = 0; s < mt2s.size(); s++) {

		if ((mt2s[s].first)->Integral() > maxYield) {

			maxYield = (mt2s[s].first)->Integral();
			xmax = (mt2s[s].second).first;
			ymax = (mt2s[s].second).second;

		}

		if(((mt2s[s].second).first) == DM && ((mt2s[s].second).second) == 1)

		cout<<"********* "<<(mt2s[s].first)->Integral()<<endl;

	}
	cout<<"+++++ maxYield: "<<maxYield<<endl;
	cout<<"+++++ xmax:     "<<xmax<<endl;
	cout<<"+++++ ymax:     "<<ymax<<endl;
/*	TFile * myfile = new TFile("file.root","recreate");

	h_xsec->Write();
	h_Counting->Write();
	h_Yields->Write();

	myfile->Close();
*/

}

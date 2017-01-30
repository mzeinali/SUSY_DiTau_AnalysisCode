#include <memory>
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <TH2.h>
#include <THStack.h>
#include <TCanvas.h>
#include "TTree.h"
#include "TFile.h"
#include "TFileCollection.h"
#include "TChain.h"
#include "TText.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <utility> 
#include <TLorentzVector.h>
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TLatex.h"
#include "TColor.h"
#include "TLine.h"
#include "TEfficiency.h"
#include "TBinomialEfficiencyFitter.h"
#include "TList.h"

#include "TLorentzVector.h"
#include "TGraphAsymmErrors.h"
#include "TMultiGraph.h"

#include "TLatex.h"
#include "TLegend.h"
#include "TLegendEntry.h"
#include "TLine.h"
#include "TArrow.h"
#include "TBox.h"
#include "TMath.h"

#include "TString.h"
#include "TObject.h"
#include "TFile.h"
#include "TDirectory.h"
#include "TH2.h"
#include "TH3.h"
#include "TF1.h"
#include "THStack.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TChain.h"
#include "TChainElement.h"
#include "TEventList.h"
#include "TCut.h"
#include "TTreeFormula.h"
#include "TStyle.h"
#include "TRandom.h"
#include "TROOT.h"
#include "TVirtualPad.h"
#include "TClonesArray.h"
#include "TGraph2D.h"
#include "TMatrixD.h"

#include "TMatrixT.h"
#include "TVectorD.h"
#include "TPaveStats.h"
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <map>

void DrawGraphDM(){

int DM[3] = {100,200,400};
std::vector<int > chMass_vec[3];
std::vector<int > neMass_vec[3];
for (int a = 0; a < 3; a++){
for (int i = 0; i < 29; i++) {
int x = i * 25 + 100;
for (int j = 0; j < x; j++) {
int y = j * 25;
if (!(x-y == DM[a])) continue;
cout<<"		+++++++ x: "<<x<<" , y: "<<y<<endl;
chMass_vec[a].push_back(x);
neMass_vec[a].push_back(y);
}
}
}

TMultiGraph *mg = new TMultiGraph();;
TString names[3] = {"DM = 100","DM = 200","DM = 400"};

for (int a = 0; a < 3; a++){
const int size = chMass_vec[a].size();
double Ch[size], Nu[size];
for (int s = 0 ; s < chMass_vec[a].size(); s++) {
	Ch[s] = chMass_vec[a].at(s);
	Nu[s] = neMass_vec[a].at(s);
}
TGraph *gr = new TGraph(size,Ch,Nu);
gr->SetFillStyle(3005);
gr->SetMarkerStyle(a+20);
gr->SetMarkerColor(a+2);
gr->SetLineColor(a+2);
gr->SetTitle(names[a]);
mg->Add(gr);
}
TCanvas *c1 = new TCanvas("c1", "optimization",53,26,900,700);
mg->Draw("apl");
mg->SetTitle("SMS points with various mass difference (DM)");
mg->GetXaxis()->SetTitle("m_{#chi^{#pm}}");
mg->GetXaxis()->SetTitleSize(0.05);
mg->GetXaxis()->SetTitleOffset(0.9);
mg->GetYaxis()->SetTitle("m_{#chi^{0}}");
mg->GetYaxis()->SetTitleSize(0.05);
mg->GetYaxis()->SetTitleOffset(0.9);

c1->BuildLegend();

//mg->Draw("AC*");

}

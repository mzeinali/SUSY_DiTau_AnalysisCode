void Counter(){

//TFile * f = new TFile("SMS_TStauStau/H2TauTauTreeProducerTauTau/tree.root");
//cout<<"**** scanning of SMS_TStauStau ****"<<endl;
TFile * f = new TFile("SMS_TChipmStauSnu/H2TauTauTreeProducerTauTau/tree.root"); // when running on 230816
//TFile * f = new TFile("SMSTChipmStauSnu_cmsswFalse/SMS_TChipmStauSnu/H2TauTauTreeProducerTauTau/tree.root"); // these are for hte 251116, which should be the same with the previous ones
cout<<"**** scanning of SMS_TChipmStauSnu ****"<<endl;

TH3D * myWeights = (TH3D*)f->Get("SumGenWeightsSMS");
//f->Draw();
int x = 0;
int y = 0;
//int DM = 700;
//int Sum = 0;
for (int x = 0; x < 3000; x++)
for (int y = 0; y < 3000; y++) {
//if (!(fabs(x-y-DM)<5)) continue;
int global = myWeights->FindBin(x,y);
int content = myWeights->GetBinContent(global);
if (content != 0) {
	cout<<"x = "<<x<<", y = "<<y<<" , NEvents = "<<content<<endl;
	//Sum += content;
}	
}
cout<<endl;
//cout<<"Nr of events: "<<fixed<<Sum<<endl;
cout<<"**** THE END ****"<<endl;

}

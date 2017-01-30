//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Jan 24 13:06:38 2017 by ROOT version 6.06/01
// from TTree tree/H2TauTauTreeProducerMuMu
// found on file: tree.root
//////////////////////////////////////////////////////////

#ifndef treeBase_Zmumu_h
#define treeBase_Zmumu_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class treeBase_Zmumu {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           run;
   Int_t           lumi;
   Int_t           event;
   Int_t           bx;
   Int_t           orbit_number;
   Int_t           is_data;
   Double_t        nPU;
   Int_t           pass_leptons;
   Int_t           veto_dilepton;
   Int_t           veto_thirdlepton;
   Int_t           veto_otherlepton;
   Int_t           n_jets;
   Int_t           n_jets_puid;
   Int_t           n_jets_20;
   Int_t           n_jets_20_puid;
   Int_t           n_bjets;
   Int_t           n_jets_csvl;
   Int_t           n_vertices;
   Double_t        rho;
   Double_t        weight;
   Double_t        weight_vertex;
   Double_t        weight_njet;
   Double_t        delta_phi_dil_jet1;
   Double_t        delta_phi_dil_jet2;
   Double_t        delta_eta_dil_jet1;
   Double_t        delta_eta_dil_jet2;
   Double_t        mvis;
   Double_t        mt_total;
   Double_t        sum_lepton_mt;
   Double_t        sqsum_lepton_mt;
   Double_t        pzeta_met;
   Double_t        pzeta_vis;
   Double_t        pzeta_disc;
   Double_t        mt;
   Double_t        mt_leg2;
   Double_t        met_cov00;
   Double_t        met_cov10;
   Double_t        met_cov11;
   Double_t        met_phi;
   Double_t        met_px;
   Double_t        met_py;
   Double_t        met_pt;
   Double_t        pthiggs;
   Double_t        delta_phi_l1_l2;
   Double_t        delta_eta_l1_l2;
   Double_t        delta_r_l1_l2;
   Double_t        delta_phi_l1_met;
   Double_t        delta_phi_l2_met;
   Double_t        svfit_mass;
   Double_t        svfit_transverse_mass;
   Double_t        svfit_mass_error;
   Double_t        svfit_pt;
   Double_t        svfit_l1_pt;
   Double_t        svfit_l1_eta;
   Double_t        svfit_l1_phi;
   Double_t        svfit_l1_charge;
   Double_t        svfit_l1_mass;
   Double_t        svfit_l2_pt;
   Double_t        svfit_l2_eta;
   Double_t        svfit_l2_phi;
   Double_t        svfit_l2_charge;
   Double_t        svfit_l2_mass;
   Double_t        geninfo_mcweight;
   Int_t           geninfo_nup;
   Double_t        geninfo_htgen;
   Double_t        geninfo_invmass;
   Double_t        weight_gen;
   Double_t        genmet_pt;
   Double_t        genmet_px;
   Double_t        genmet_py;
   Double_t        genmet_phi;
   Double_t        vbf_mjj;
   Double_t        vbf_deta;
   Int_t           vbf_n_central20;
   Int_t           vbf_n_central;
   Double_t        vbf_jdphi;
   Double_t        vbf_dijetpt;
   Double_t        vbf_dijetphi;
   Double_t        vbf_dphidijethiggs;
   Double_t        vbf_mindetajetvis;
   Double_t        jet1_pt;
   Double_t        jet1_eta;
   Double_t        jet1_phi;
   Double_t        jet1_charge;
   Double_t        jet1_mass;
   Double_t        jet1_mva_pu;
   Double_t        jet1_id_pu;
   Double_t        jet1_flavour_parton;
   Double_t        jet1_csv;
   Double_t        jet1_genjet_pt;
   Double_t        jet1_nConstituents;
   Double_t        jet1_rawFactor;
   Double_t        jet1_chargedHadronEnergy;
   Double_t        jet1_neutralHadronEnergy;
   Double_t        jet1_neutralEmEnergy;
   Double_t        jet1_muonEnergy;
   Double_t        jet1_chargedEmEnergy;
   Double_t        jet1_chargedHadronMultiplicity;
   Double_t        jet1_chargedMultiplicity;
   Double_t        jet1_neutralMultiplicity;
   Double_t        jet2_pt;
   Double_t        jet2_eta;
   Double_t        jet2_phi;
   Double_t        jet2_charge;
   Double_t        jet2_mass;
   Double_t        jet2_mva_pu;
   Double_t        jet2_id_pu;
   Double_t        jet2_flavour_parton;
   Double_t        jet2_csv;
   Double_t        jet2_genjet_pt;
   Double_t        jet2_nConstituents;
   Double_t        jet2_rawFactor;
   Double_t        jet2_chargedHadronEnergy;
   Double_t        jet2_neutralHadronEnergy;
   Double_t        jet2_neutralEmEnergy;
   Double_t        jet2_muonEnergy;
   Double_t        jet2_chargedEmEnergy;
   Double_t        jet2_chargedHadronMultiplicity;
   Double_t        jet2_chargedMultiplicity;
   Double_t        jet2_neutralMultiplicity;
   Double_t        bjet1_pt;
   Double_t        bjet1_eta;
   Double_t        bjet1_phi;
   Double_t        bjet1_charge;
   Double_t        bjet1_mass;
   Double_t        bjet1_mva_pu;
   Double_t        bjet1_id_pu;
   Double_t        bjet1_flavour_parton;
   Double_t        bjet1_csv;
   Double_t        bjet1_genjet_pt;
   Double_t        bjet1_nConstituents;
   Double_t        bjet1_rawFactor;
   Double_t        bjet1_chargedHadronEnergy;
   Double_t        bjet1_neutralHadronEnergy;
   Double_t        bjet1_neutralEmEnergy;
   Double_t        bjet1_muonEnergy;
   Double_t        bjet1_chargedEmEnergy;
   Double_t        bjet1_chargedHadronMultiplicity;
   Double_t        bjet1_chargedMultiplicity;
   Double_t        bjet1_neutralMultiplicity;
   Double_t        bjet2_pt;
   Double_t        bjet2_eta;
   Double_t        bjet2_phi;
   Double_t        bjet2_charge;
   Double_t        bjet2_mass;
   Double_t        bjet2_mva_pu;
   Double_t        bjet2_id_pu;
   Double_t        bjet2_flavour_parton;
   Double_t        bjet2_csv;
   Double_t        bjet2_genjet_pt;
   Double_t        bjet2_nConstituents;
   Double_t        bjet2_rawFactor;
   Double_t        bjet2_chargedHadronEnergy;
   Double_t        bjet2_neutralHadronEnergy;
   Double_t        bjet2_neutralEmEnergy;
   Double_t        bjet2_muonEnergy;
   Double_t        bjet2_chargedEmEnergy;
   Double_t        bjet2_chargedHadronMultiplicity;
   Double_t        bjet2_chargedMultiplicity;
   Double_t        bjet2_neutralMultiplicity;
   Double_t        HT_allJets;
   Double_t        HT_jets;
   Double_t        HT_bJets;
   Double_t        HT_cleanJets;
   Double_t        HT_jets30;
   Double_t        HT_cleanJets30;
   Double_t        genboson_pt;
   Double_t        genboson_eta;
   Double_t        genboson_phi;
   Double_t        genboson_charge;
   Double_t        genboson_mass;
   Double_t        genboson_pdgId;
   Double_t        gen_top_1_pt;
   Double_t        gen_top_2_pt;
   Double_t        gen_top_weight;
   Double_t        puppimet_pt;
   Double_t        puppimet_phi;
   Double_t        puppimet_mt1;
   Double_t        puppimet_mt2;
   Double_t        pfmet_pt;
   Double_t        pfmet_phi;
   Double_t        pfmet_mt1;
   Double_t        pfmet_mt2;
   Double_t        l1_pt;
   Double_t        l1_eta;
   Double_t        l1_phi;
   Double_t        l1_charge;
   Double_t        l1_mass;
   Double_t        l1_jet_pt;
   Double_t        l1_jet_eta;
   Double_t        l1_jet_phi;
   Double_t        l1_jet_charge;
   Double_t        l1_jet_mass;
   Double_t        l1_dxy;
   Double_t        l1_dxy_error;
   Double_t        l1_dz;
   Double_t        l1_dz_error;
   Double_t        l1_weight;
   Double_t        l1_weight_trigger;
   Double_t        l1_weight_eff_data_trigger;
   Double_t        l1_eff_trigger_data;
   Double_t        l1_eff_trigger_mc;
   Double_t        l1_weight_idiso;
   Double_t        l1_eff_idiso_data;
   Double_t        l1_eff_idiso_mc;
   Double_t        l1_gen_match;
   Double_t        l1_reliso05;
   Double_t        l1_reliso05_03;
   Double_t        l1_muonid_loose;
   Double_t        l1_muonid_medium;
   Double_t        l1_muonid_tight;
   Double_t        l1_muonid_tightnovtx;
   Double_t        l1_muonid_highpt;
   Double_t        l1_dxy_innertrack;
   Double_t        l1_dz_innertrack;
   Double_t        l2_pt;
   Double_t        l2_eta;
   Double_t        l2_phi;
   Double_t        l2_charge;
   Double_t        l2_mass;
   Double_t        l2_jet_pt;
   Double_t        l2_jet_eta;
   Double_t        l2_jet_phi;
   Double_t        l2_jet_charge;
   Double_t        l2_jet_mass;
   Double_t        l2_dxy;
   Double_t        l2_dxy_error;
   Double_t        l2_dz;
   Double_t        l2_dz_error;
   Double_t        l2_weight;
   Double_t        l2_weight_trigger;
   Double_t        l2_weight_eff_data_trigger;
   Double_t        l2_eff_trigger_data;
   Double_t        l2_eff_trigger_mc;
   Double_t        l2_weight_idiso;
   Double_t        l2_eff_idiso_data;
   Double_t        l2_eff_idiso_mc;
   Double_t        l2_gen_match;
   Double_t        l2_reliso05;
   Double_t        l2_reliso05_03;
   Double_t        l2_muonid_loose;
   Double_t        l2_muonid_medium;
   Double_t        l2_muonid_tight;
   Double_t        l2_muonid_tightnovtx;
   Double_t        l2_muonid_highpt;
   Double_t        l2_dxy_innertrack;
   Double_t        l2_dz_innertrack;
   Double_t        l1_gen_pt;
   Double_t        l1_gen_eta;
   Double_t        l1_gen_phi;
   Double_t        l1_gen_charge;
   Double_t        l1_gen_mass;
   Double_t        l1_gen_pdgId;
   Double_t        l2_gen_pt;
   Double_t        l2_gen_eta;
   Double_t        l2_gen_phi;
   Double_t        l2_gen_charge;
   Double_t        l2_gen_mass;
   Double_t        l2_gen_pdgId;
   Double_t        tau1_pt;
   Double_t        tau1_eta;
   Double_t        tau1_phi;
   Double_t        tau1_charge;
   Double_t        tau1_mass;
   Double_t        tau1_jet_pt;
   Double_t        tau1_jet_eta;
   Double_t        tau1_jet_phi;
   Double_t        tau1_jet_charge;
   Double_t        tau1_jet_mass;
   Double_t        tau1_dxy;
   Double_t        tau1_dxy_error;
   Double_t        tau1_dz;
   Double_t        tau1_dz_error;
   Double_t        tau1_weight;
   Double_t        tau1_weight_trigger;
   Double_t        tau1_weight_eff_data_trigger;
   Double_t        tau1_eff_trigger_data;
   Double_t        tau1_eff_trigger_mc;
   Double_t        tau1_weight_idiso;
   Double_t        tau1_eff_idiso_data;
   Double_t        tau1_eff_idiso_mc;
   Double_t        tau1_gen_match;
   Double_t        tau1_decayMode;
   Double_t        tau1_zImpact;
   Double_t        tau1_dz_selfvertex;
   Double_t        tau1_ptScale;
   Int_t           tau1_againstElectronMVA6;
   Int_t           tau1_againstMuon3;
   Double_t        tau1_byCombinedIsolationDeltaBetaCorrRaw3Hits;
   Double_t        tau1_byIsolationMVArun2v1DBoldDMwLTraw;
   Double_t        tau1_byIsolationMVArun2v1DBnewDMwLTraw;
   Double_t        tau1_byIsolationMVArun2v1DBdR03oldDMwLTraw;
   Int_t           tau1_byCombinedIsolationDeltaBetaCorr3Hits;
   Int_t           tau1_byIsolationMVArun2v1DBoldDMwLT;
   Int_t           tau1_byIsolationMVArun2v1DBnewDMwLT;
   Int_t           tau1_byIsolationMVArun2v1DBdR03oldDMwLT;
   Double_t        tau1_chargedIsoPtSum;
   Double_t        tau1_decayModeFinding;
   Double_t        tau1_footprintCorrection;
   Double_t        tau1_neutralIsoPtSum;
   Double_t        tau1_puCorrPtSum;
   Double_t        tau1_photonPtSumOutsideSignalCone;
   Double_t        tau1_byTightIsolationMVArun2v1DBoldDMwLT;
   Double_t        tau1_gen_pt;
   Double_t        tau1_gen_eta;
   Double_t        tau1_gen_phi;
   Double_t        tau1_gen_charge;
   Double_t        tau1_gen_mass;
   Double_t        tau1_gen_pdgId;

   // List of branches
   TBranch        *b_run;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_event;   //!
   TBranch        *b_bx;   //!
   TBranch        *b_orbit_number;   //!
   TBranch        *b_is_data;   //!
   TBranch        *b_nPU;   //!
   TBranch        *b_pass_leptons;   //!
   TBranch        *b_veto_dilepton;   //!
   TBranch        *b_veto_thirdlepton;   //!
   TBranch        *b_veto_otherlepton;   //!
   TBranch        *b_n_jets;   //!
   TBranch        *b_n_jets_puid;   //!
   TBranch        *b_n_jets_20;   //!
   TBranch        *b_n_jets_20_puid;   //!
   TBranch        *b_n_bjets;   //!
   TBranch        *b_n_jets_csvl;   //!
   TBranch        *b_n_vertices;   //!
   TBranch        *b_rho;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_weight_vertex;   //!
   TBranch        *b_weight_njet;   //!
   TBranch        *b_delta_phi_dil_jet1;   //!
   TBranch        *b_delta_phi_dil_jet2;   //!
   TBranch        *b_delta_eta_dil_jet1;   //!
   TBranch        *b_delta_eta_dil_jet2;   //!
   TBranch        *b_mvis;   //!
   TBranch        *b_mt_total;   //!
   TBranch        *b_sum_lepton_mt;   //!
   TBranch        *b_sqsum_lepton_mt;   //!
   TBranch        *b_pzeta_met;   //!
   TBranch        *b_pzeta_vis;   //!
   TBranch        *b_pzeta_disc;   //!
   TBranch        *b_mt;   //!
   TBranch        *b_mt_leg2;   //!
   TBranch        *b_met_cov00;   //!
   TBranch        *b_met_cov10;   //!
   TBranch        *b_met_cov11;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_met_px;   //!
   TBranch        *b_met_py;   //!
   TBranch        *b_met_pt;   //!
   TBranch        *b_pthiggs;   //!
   TBranch        *b_delta_phi_l1_l2;   //!
   TBranch        *b_delta_eta_l1_l2;   //!
   TBranch        *b_delta_r_l1_l2;   //!
   TBranch        *b_delta_phi_l1_met;   //!
   TBranch        *b_delta_phi_l2_met;   //!
   TBranch        *b_svfit_mass;   //!
   TBranch        *b_svfit_transverse_mass;   //!
   TBranch        *b_svfit_mass_error;   //!
   TBranch        *b_svfit_pt;   //!
   TBranch        *b_svfit_l1_pt;   //!
   TBranch        *b_svfit_l1_eta;   //!
   TBranch        *b_svfit_l1_phi;   //!
   TBranch        *b_svfit_l1_charge;   //!
   TBranch        *b_svfit_l1_mass;   //!
   TBranch        *b_svfit_l2_pt;   //!
   TBranch        *b_svfit_l2_eta;   //!
   TBranch        *b_svfit_l2_phi;   //!
   TBranch        *b_svfit_l2_charge;   //!
   TBranch        *b_svfit_l2_mass;   //!
   TBranch        *b_geninfo_mcweight;   //!
   TBranch        *b_geninfo_nup;   //!
   TBranch        *b_geninfo_htgen;   //!
   TBranch        *b_geninfo_invmass;   //!
   TBranch        *b_weight_gen;   //!
   TBranch        *b_genmet_pt;   //!
   TBranch        *b_genmet_px;   //!
   TBranch        *b_genmet_py;   //!
   TBranch        *b_genmet_phi;   //!
   TBranch        *b_vbf_mjj;   //!
   TBranch        *b_vbf_deta;   //!
   TBranch        *b_vbf_n_central20;   //!
   TBranch        *b_vbf_n_central;   //!
   TBranch        *b_vbf_jdphi;   //!
   TBranch        *b_vbf_dijetpt;   //!
   TBranch        *b_vbf_dijetphi;   //!
   TBranch        *b_vbf_dphidijethiggs;   //!
   TBranch        *b_vbf_mindetajetvis;   //!
   TBranch        *b_jet1_pt;   //!
   TBranch        *b_jet1_eta;   //!
   TBranch        *b_jet1_phi;   //!
   TBranch        *b_jet1_charge;   //!
   TBranch        *b_jet1_mass;   //!
   TBranch        *b_jet1_mva_pu;   //!
   TBranch        *b_jet1_id_pu;   //!
   TBranch        *b_jet1_flavour_parton;   //!
   TBranch        *b_jet1_csv;   //!
   TBranch        *b_jet1_genjet_pt;   //!
   TBranch        *b_jet1_nConstituents;   //!
   TBranch        *b_jet1_rawFactor;   //!
   TBranch        *b_jet1_chargedHadronEnergy;   //!
   TBranch        *b_jet1_neutralHadronEnergy;   //!
   TBranch        *b_jet1_neutralEmEnergy;   //!
   TBranch        *b_jet1_muonEnergy;   //!
   TBranch        *b_jet1_chargedEmEnergy;   //!
   TBranch        *b_jet1_chargedHadronMultiplicity;   //!
   TBranch        *b_jet1_chargedMultiplicity;   //!
   TBranch        *b_jet1_neutralMultiplicity;   //!
   TBranch        *b_jet2_pt;   //!
   TBranch        *b_jet2_eta;   //!
   TBranch        *b_jet2_phi;   //!
   TBranch        *b_jet2_charge;   //!
   TBranch        *b_jet2_mass;   //!
   TBranch        *b_jet2_mva_pu;   //!
   TBranch        *b_jet2_id_pu;   //!
   TBranch        *b_jet2_flavour_parton;   //!
   TBranch        *b_jet2_csv;   //!
   TBranch        *b_jet2_genjet_pt;   //!
   TBranch        *b_jet2_nConstituents;   //!
   TBranch        *b_jet2_rawFactor;   //!
   TBranch        *b_jet2_chargedHadronEnergy;   //!
   TBranch        *b_jet2_neutralHadronEnergy;   //!
   TBranch        *b_jet2_neutralEmEnergy;   //!
   TBranch        *b_jet2_muonEnergy;   //!
   TBranch        *b_jet2_chargedEmEnergy;   //!
   TBranch        *b_jet2_chargedHadronMultiplicity;   //!
   TBranch        *b_jet2_chargedMultiplicity;   //!
   TBranch        *b_jet2_neutralMultiplicity;   //!
   TBranch        *b_bjet1_pt;   //!
   TBranch        *b_bjet1_eta;   //!
   TBranch        *b_bjet1_phi;   //!
   TBranch        *b_bjet1_charge;   //!
   TBranch        *b_bjet1_mass;   //!
   TBranch        *b_bjet1_mva_pu;   //!
   TBranch        *b_bjet1_id_pu;   //!
   TBranch        *b_bjet1_flavour_parton;   //!
   TBranch        *b_bjet1_csv;   //!
   TBranch        *b_bjet1_genjet_pt;   //!
   TBranch        *b_bjet1_nConstituents;   //!
   TBranch        *b_bjet1_rawFactor;   //!
   TBranch        *b_bjet1_chargedHadronEnergy;   //!
   TBranch        *b_bjet1_neutralHadronEnergy;   //!
   TBranch        *b_bjet1_neutralEmEnergy;   //!
   TBranch        *b_bjet1_muonEnergy;   //!
   TBranch        *b_bjet1_chargedEmEnergy;   //!
   TBranch        *b_bjet1_chargedHadronMultiplicity;   //!
   TBranch        *b_bjet1_chargedMultiplicity;   //!
   TBranch        *b_bjet1_neutralMultiplicity;   //!
   TBranch        *b_bjet2_pt;   //!
   TBranch        *b_bjet2_eta;   //!
   TBranch        *b_bjet2_phi;   //!
   TBranch        *b_bjet2_charge;   //!
   TBranch        *b_bjet2_mass;   //!
   TBranch        *b_bjet2_mva_pu;   //!
   TBranch        *b_bjet2_id_pu;   //!
   TBranch        *b_bjet2_flavour_parton;   //!
   TBranch        *b_bjet2_csv;   //!
   TBranch        *b_bjet2_genjet_pt;   //!
   TBranch        *b_bjet2_nConstituents;   //!
   TBranch        *b_bjet2_rawFactor;   //!
   TBranch        *b_bjet2_chargedHadronEnergy;   //!
   TBranch        *b_bjet2_neutralHadronEnergy;   //!
   TBranch        *b_bjet2_neutralEmEnergy;   //!
   TBranch        *b_bjet2_muonEnergy;   //!
   TBranch        *b_bjet2_chargedEmEnergy;   //!
   TBranch        *b_bjet2_chargedHadronMultiplicity;   //!
   TBranch        *b_bjet2_chargedMultiplicity;   //!
   TBranch        *b_bjet2_neutralMultiplicity;   //!
   TBranch        *b_HT_allJets;   //!
   TBranch        *b_HT_jets;   //!
   TBranch        *b_HT_bJets;   //!
   TBranch        *b_HT_cleanJets;   //!
   TBranch        *b_HT_jets30;   //!
   TBranch        *b_HT_cleanJets30;   //!
   TBranch        *b_genboson_pt;   //!
   TBranch        *b_genboson_eta;   //!
   TBranch        *b_genboson_phi;   //!
   TBranch        *b_genboson_charge;   //!
   TBranch        *b_genboson_mass;   //!
   TBranch        *b_genboson_pdgId;   //!
   TBranch        *b_gen_top_1_pt;   //!
   TBranch        *b_gen_top_2_pt;   //!
   TBranch        *b_gen_top_weight;   //!
   TBranch        *b_puppimet_pt;   //!
   TBranch        *b_puppimet_phi;   //!
   TBranch        *b_puppimet_mt1;   //!
   TBranch        *b_puppimet_mt2;   //!
   TBranch        *b_pfmet_pt;   //!
   TBranch        *b_pfmet_phi;   //!
   TBranch        *b_pfmet_mt1;   //!
   TBranch        *b_pfmet_mt2;   //!
   TBranch        *b_l1_pt;   //!
   TBranch        *b_l1_eta;   //!
   TBranch        *b_l1_phi;   //!
   TBranch        *b_l1_charge;   //!
   TBranch        *b_l1_mass;   //!
   TBranch        *b_l1_jet_pt;   //!
   TBranch        *b_l1_jet_eta;   //!
   TBranch        *b_l1_jet_phi;   //!
   TBranch        *b_l1_jet_charge;   //!
   TBranch        *b_l1_jet_mass;   //!
   TBranch        *b_l1_dxy;   //!
   TBranch        *b_l1_dxy_error;   //!
   TBranch        *b_l1_dz;   //!
   TBranch        *b_l1_dz_error;   //!
   TBranch        *b_l1_weight;   //!
   TBranch        *b_l1_weight_trigger;   //!
   TBranch        *b_l1_weight_eff_data_trigger;   //!
   TBranch        *b_l1_eff_trigger_data;   //!
   TBranch        *b_l1_eff_trigger_mc;   //!
   TBranch        *b_l1_weight_idiso;   //!
   TBranch        *b_l1_eff_idiso_data;   //!
   TBranch        *b_l1_eff_idiso_mc;   //!
   TBranch        *b_l1_gen_match;   //!
   TBranch        *b_l1_reliso05;   //!
   TBranch        *b_l1_reliso05_03;   //!
   TBranch        *b_l1_muonid_loose;   //!
   TBranch        *b_l1_muonid_medium;   //!
   TBranch        *b_l1_muonid_tight;   //!
   TBranch        *b_l1_muonid_tightnovtx;   //!
   TBranch        *b_l1_muonid_highpt;   //!
   TBranch        *b_l1_dxy_innertrack;   //!
   TBranch        *b_l1_dz_innertrack;   //!
   TBranch        *b_l2_pt;   //!
   TBranch        *b_l2_eta;   //!
   TBranch        *b_l2_phi;   //!
   TBranch        *b_l2_charge;   //!
   TBranch        *b_l2_mass;   //!
   TBranch        *b_l2_jet_pt;   //!
   TBranch        *b_l2_jet_eta;   //!
   TBranch        *b_l2_jet_phi;   //!
   TBranch        *b_l2_jet_charge;   //!
   TBranch        *b_l2_jet_mass;   //!
   TBranch        *b_l2_dxy;   //!
   TBranch        *b_l2_dxy_error;   //!
   TBranch        *b_l2_dz;   //!
   TBranch        *b_l2_dz_error;   //!
   TBranch        *b_l2_weight;   //!
   TBranch        *b_l2_weight_trigger;   //!
   TBranch        *b_l2_weight_eff_data_trigger;   //!
   TBranch        *b_l2_eff_trigger_data;   //!
   TBranch        *b_l2_eff_trigger_mc;   //!
   TBranch        *b_l2_weight_idiso;   //!
   TBranch        *b_l2_eff_idiso_data;   //!
   TBranch        *b_l2_eff_idiso_mc;   //!
   TBranch        *b_l2_gen_match;   //!
   TBranch        *b_l2_reliso05;   //!
   TBranch        *b_l2_reliso05_03;   //!
   TBranch        *b_l2_muonid_loose;   //!
   TBranch        *b_l2_muonid_medium;   //!
   TBranch        *b_l2_muonid_tight;   //!
   TBranch        *b_l2_muonid_tightnovtx;   //!
   TBranch        *b_l2_muonid_highpt;   //!
   TBranch        *b_l2_dxy_innertrack;   //!
   TBranch        *b_l2_dz_innertrack;   //!
   TBranch        *b_l1_gen_pt;   //!
   TBranch        *b_l1_gen_eta;   //!
   TBranch        *b_l1_gen_phi;   //!
   TBranch        *b_l1_gen_charge;   //!
   TBranch        *b_l1_gen_mass;   //!
   TBranch        *b_l1_gen_pdgId;   //!
   TBranch        *b_l2_gen_pt;   //!
   TBranch        *b_l2_gen_eta;   //!
   TBranch        *b_l2_gen_phi;   //!
   TBranch        *b_l2_gen_charge;   //!
   TBranch        *b_l2_gen_mass;   //!
   TBranch        *b_l2_gen_pdgId;   //!
   TBranch        *b_tau1_pt;   //!
   TBranch        *b_tau1_eta;   //!
   TBranch        *b_tau1_phi;   //!
   TBranch        *b_tau1_charge;   //!
   TBranch        *b_tau1_mass;   //!
   TBranch        *b_tau1_jet_pt;   //!
   TBranch        *b_tau1_jet_eta;   //!
   TBranch        *b_tau1_jet_phi;   //!
   TBranch        *b_tau1_jet_charge;   //!
   TBranch        *b_tau1_jet_mass;   //!
   TBranch        *b_tau1_dxy;   //!
   TBranch        *b_tau1_dxy_error;   //!
   TBranch        *b_tau1_dz;   //!
   TBranch        *b_tau1_dz_error;   //!
   TBranch        *b_tau1_weight;   //!
   TBranch        *b_tau1_weight_trigger;   //!
   TBranch        *b_tau1_weight_eff_data_trigger;   //!
   TBranch        *b_tau1_eff_trigger_data;   //!
   TBranch        *b_tau1_eff_trigger_mc;   //!
   TBranch        *b_tau1_weight_idiso;   //!
   TBranch        *b_tau1_eff_idiso_data;   //!
   TBranch        *b_tau1_eff_idiso_mc;   //!
   TBranch        *b_tau1_gen_match;   //!
   TBranch        *b_tau1_decayMode;   //!
   TBranch        *b_tau1_zImpact;   //!
   TBranch        *b_tau1_dz_selfvertex;   //!
   TBranch        *b_tau1_ptScale;   //!
   TBranch        *b_tau1_againstElectronMVA6;   //!
   TBranch        *b_tau1_againstMuon3;   //!
   TBranch        *b_tau1_byCombinedIsolationDeltaBetaCorrRaw3Hits;   //!
   TBranch        *b_tau1_byIsolationMVArun2v1DBoldDMwLTraw;   //!
   TBranch        *b_tau1_byIsolationMVArun2v1DBnewDMwLTraw;   //!
   TBranch        *b_tau1_byIsolationMVArun2v1DBdR03oldDMwLTraw;   //!
   TBranch        *b_tau1_byCombinedIsolationDeltaBetaCorr3Hits;   //!
   TBranch        *b_tau1_byIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tau1_byIsolationMVArun2v1DBnewDMwLT;   //!
   TBranch        *b_tau1_byIsolationMVArun2v1DBdR03oldDMwLT;   //!
   TBranch        *b_tau1_chargedIsoPtSum;   //!
   TBranch        *b_tau1_decayModeFinding;   //!
   TBranch        *b_tau1_footprintCorrection;   //!
   TBranch        *b_tau1_neutralIsoPtSum;   //!
   TBranch        *b_tau1_puCorrPtSum;   //!
   TBranch        *b_tau1_photonPtSumOutsideSignalCone;   //!
   TBranch        *b_tau1_byTightIsolationMVArun2v1DBoldDMwLT;   //!
   TBranch        *b_tau1_gen_pt;   //!
   TBranch        *b_tau1_gen_eta;   //!
   TBranch        *b_tau1_gen_phi;   //!
   TBranch        *b_tau1_gen_charge;   //!
   TBranch        *b_tau1_gen_mass;   //!
   TBranch        *b_tau1_gen_pdgId;   //!

   treeBase_Zmumu(TTree *tree=0);
   virtual ~treeBase_Zmumu();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

treeBase_Zmumu::treeBase_Zmumu(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("tree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("tree.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

treeBase_Zmumu::~treeBase_Zmumu()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t treeBase_Zmumu::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t treeBase_Zmumu::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void treeBase_Zmumu::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("bx", &bx, &b_bx);
   fChain->SetBranchAddress("orbit_number", &orbit_number, &b_orbit_number);
   fChain->SetBranchAddress("is_data", &is_data, &b_is_data);
   fChain->SetBranchAddress("nPU", &nPU, &b_nPU);
   fChain->SetBranchAddress("pass_leptons", &pass_leptons, &b_pass_leptons);
   fChain->SetBranchAddress("veto_dilepton", &veto_dilepton, &b_veto_dilepton);
   fChain->SetBranchAddress("veto_thirdlepton", &veto_thirdlepton, &b_veto_thirdlepton);
   fChain->SetBranchAddress("veto_otherlepton", &veto_otherlepton, &b_veto_otherlepton);
   fChain->SetBranchAddress("n_jets", &n_jets, &b_n_jets);
   fChain->SetBranchAddress("n_jets_puid", &n_jets_puid, &b_n_jets_puid);
   fChain->SetBranchAddress("n_jets_20", &n_jets_20, &b_n_jets_20);
   fChain->SetBranchAddress("n_jets_20_puid", &n_jets_20_puid, &b_n_jets_20_puid);
   fChain->SetBranchAddress("n_bjets", &n_bjets, &b_n_bjets);
   fChain->SetBranchAddress("n_jets_csvl", &n_jets_csvl, &b_n_jets_csvl);
   fChain->SetBranchAddress("n_vertices", &n_vertices, &b_n_vertices);
   fChain->SetBranchAddress("rho", &rho, &b_rho);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("weight_vertex", &weight_vertex, &b_weight_vertex);
   fChain->SetBranchAddress("weight_njet", &weight_njet, &b_weight_njet);
//    fChain->SetBranchAddress("weight_njet", &weight_njet, &b_weight_njet);
   fChain->SetBranchAddress("delta_phi_dil_jet1", &delta_phi_dil_jet1, &b_delta_phi_dil_jet1);
   fChain->SetBranchAddress("delta_phi_dil_jet2", &delta_phi_dil_jet2, &b_delta_phi_dil_jet2);
   fChain->SetBranchAddress("delta_eta_dil_jet1", &delta_eta_dil_jet1, &b_delta_eta_dil_jet1);
   fChain->SetBranchAddress("delta_eta_dil_jet2", &delta_eta_dil_jet2, &b_delta_eta_dil_jet2);
   fChain->SetBranchAddress("mvis", &mvis, &b_mvis);
   fChain->SetBranchAddress("mt_total", &mt_total, &b_mt_total);
   fChain->SetBranchAddress("sum_lepton_mt", &sum_lepton_mt, &b_sum_lepton_mt);
   fChain->SetBranchAddress("sqsum_lepton_mt", &sqsum_lepton_mt, &b_sqsum_lepton_mt);
   fChain->SetBranchAddress("pzeta_met", &pzeta_met, &b_pzeta_met);
   fChain->SetBranchAddress("pzeta_vis", &pzeta_vis, &b_pzeta_vis);
   fChain->SetBranchAddress("pzeta_disc", &pzeta_disc, &b_pzeta_disc);
   fChain->SetBranchAddress("mt", &mt, &b_mt);
   fChain->SetBranchAddress("mt_leg2", &mt_leg2, &b_mt_leg2);
   fChain->SetBranchAddress("met_cov00", &met_cov00, &b_met_cov00);
   fChain->SetBranchAddress("met_cov10", &met_cov10, &b_met_cov10);
   fChain->SetBranchAddress("met_cov11", &met_cov11, &b_met_cov11);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("met_px", &met_px, &b_met_px);
   fChain->SetBranchAddress("met_py", &met_py, &b_met_py);
   fChain->SetBranchAddress("met_pt", &met_pt, &b_met_pt);
   fChain->SetBranchAddress("pthiggs", &pthiggs, &b_pthiggs);
   fChain->SetBranchAddress("delta_phi_l1_l2", &delta_phi_l1_l2, &b_delta_phi_l1_l2);
   fChain->SetBranchAddress("delta_eta_l1_l2", &delta_eta_l1_l2, &b_delta_eta_l1_l2);
   fChain->SetBranchAddress("delta_r_l1_l2", &delta_r_l1_l2, &b_delta_r_l1_l2);
   fChain->SetBranchAddress("delta_phi_l1_met", &delta_phi_l1_met, &b_delta_phi_l1_met);
   fChain->SetBranchAddress("delta_phi_l2_met", &delta_phi_l2_met, &b_delta_phi_l2_met);
   fChain->SetBranchAddress("svfit_mass", &svfit_mass, &b_svfit_mass);
   fChain->SetBranchAddress("svfit_transverse_mass", &svfit_transverse_mass, &b_svfit_transverse_mass);
   fChain->SetBranchAddress("svfit_mass_error", &svfit_mass_error, &b_svfit_mass_error);
   fChain->SetBranchAddress("svfit_pt", &svfit_pt, &b_svfit_pt);
   fChain->SetBranchAddress("svfit_l1_pt", &svfit_l1_pt, &b_svfit_l1_pt);
   fChain->SetBranchAddress("svfit_l1_eta", &svfit_l1_eta, &b_svfit_l1_eta);
   fChain->SetBranchAddress("svfit_l1_phi", &svfit_l1_phi, &b_svfit_l1_phi);
   fChain->SetBranchAddress("svfit_l1_charge", &svfit_l1_charge, &b_svfit_l1_charge);
   fChain->SetBranchAddress("svfit_l1_mass", &svfit_l1_mass, &b_svfit_l1_mass);
   fChain->SetBranchAddress("svfit_l2_pt", &svfit_l2_pt, &b_svfit_l2_pt);
   fChain->SetBranchAddress("svfit_l2_eta", &svfit_l2_eta, &b_svfit_l2_eta);
   fChain->SetBranchAddress("svfit_l2_phi", &svfit_l2_phi, &b_svfit_l2_phi);
   fChain->SetBranchAddress("svfit_l2_charge", &svfit_l2_charge, &b_svfit_l2_charge);
   fChain->SetBranchAddress("svfit_l2_mass", &svfit_l2_mass, &b_svfit_l2_mass);
   fChain->SetBranchAddress("geninfo_mcweight", &geninfo_mcweight, &b_geninfo_mcweight);
   fChain->SetBranchAddress("geninfo_nup", &geninfo_nup, &b_geninfo_nup);
   fChain->SetBranchAddress("geninfo_htgen", &geninfo_htgen, &b_geninfo_htgen);
   fChain->SetBranchAddress("geninfo_invmass", &geninfo_invmass, &b_geninfo_invmass);
   fChain->SetBranchAddress("weight_gen", &weight_gen, &b_weight_gen);
   fChain->SetBranchAddress("genmet_pt", &genmet_pt, &b_genmet_pt);
   fChain->SetBranchAddress("genmet_px", &genmet_px, &b_genmet_px);
   fChain->SetBranchAddress("genmet_py", &genmet_py, &b_genmet_py);
   fChain->SetBranchAddress("genmet_phi", &genmet_phi, &b_genmet_phi);
   fChain->SetBranchAddress("vbf_mjj", &vbf_mjj, &b_vbf_mjj);
   fChain->SetBranchAddress("vbf_deta", &vbf_deta, &b_vbf_deta);
   fChain->SetBranchAddress("vbf_n_central20", &vbf_n_central20, &b_vbf_n_central20);
   fChain->SetBranchAddress("vbf_n_central", &vbf_n_central, &b_vbf_n_central);
   fChain->SetBranchAddress("vbf_jdphi", &vbf_jdphi, &b_vbf_jdphi);
   fChain->SetBranchAddress("vbf_dijetpt", &vbf_dijetpt, &b_vbf_dijetpt);
   fChain->SetBranchAddress("vbf_dijetphi", &vbf_dijetphi, &b_vbf_dijetphi);
   fChain->SetBranchAddress("vbf_dphidijethiggs", &vbf_dphidijethiggs, &b_vbf_dphidijethiggs);
   fChain->SetBranchAddress("vbf_mindetajetvis", &vbf_mindetajetvis, &b_vbf_mindetajetvis);
   fChain->SetBranchAddress("jet1_pt", &jet1_pt, &b_jet1_pt);
   fChain->SetBranchAddress("jet1_eta", &jet1_eta, &b_jet1_eta);
   fChain->SetBranchAddress("jet1_phi", &jet1_phi, &b_jet1_phi);
   fChain->SetBranchAddress("jet1_charge", &jet1_charge, &b_jet1_charge);
   fChain->SetBranchAddress("jet1_mass", &jet1_mass, &b_jet1_mass);
   fChain->SetBranchAddress("jet1_mva_pu", &jet1_mva_pu, &b_jet1_mva_pu);
   fChain->SetBranchAddress("jet1_id_pu", &jet1_id_pu, &b_jet1_id_pu);
   fChain->SetBranchAddress("jet1_flavour_parton", &jet1_flavour_parton, &b_jet1_flavour_parton);
   fChain->SetBranchAddress("jet1_csv", &jet1_csv, &b_jet1_csv);
   fChain->SetBranchAddress("jet1_genjet_pt", &jet1_genjet_pt, &b_jet1_genjet_pt);
   fChain->SetBranchAddress("jet1_nConstituents", &jet1_nConstituents, &b_jet1_nConstituents);
   fChain->SetBranchAddress("jet1_rawFactor", &jet1_rawFactor, &b_jet1_rawFactor);
   fChain->SetBranchAddress("jet1_chargedHadronEnergy", &jet1_chargedHadronEnergy, &b_jet1_chargedHadronEnergy);
   fChain->SetBranchAddress("jet1_neutralHadronEnergy", &jet1_neutralHadronEnergy, &b_jet1_neutralHadronEnergy);
   fChain->SetBranchAddress("jet1_neutralEmEnergy", &jet1_neutralEmEnergy, &b_jet1_neutralEmEnergy);
   fChain->SetBranchAddress("jet1_muonEnergy", &jet1_muonEnergy, &b_jet1_muonEnergy);
   fChain->SetBranchAddress("jet1_chargedEmEnergy", &jet1_chargedEmEnergy, &b_jet1_chargedEmEnergy);
   fChain->SetBranchAddress("jet1_chargedHadronMultiplicity", &jet1_chargedHadronMultiplicity, &b_jet1_chargedHadronMultiplicity);
   fChain->SetBranchAddress("jet1_chargedMultiplicity", &jet1_chargedMultiplicity, &b_jet1_chargedMultiplicity);
   fChain->SetBranchAddress("jet1_neutralMultiplicity", &jet1_neutralMultiplicity, &b_jet1_neutralMultiplicity);
   fChain->SetBranchAddress("jet2_pt", &jet2_pt, &b_jet2_pt);
   fChain->SetBranchAddress("jet2_eta", &jet2_eta, &b_jet2_eta);
   fChain->SetBranchAddress("jet2_phi", &jet2_phi, &b_jet2_phi);
   fChain->SetBranchAddress("jet2_charge", &jet2_charge, &b_jet2_charge);
   fChain->SetBranchAddress("jet2_mass", &jet2_mass, &b_jet2_mass);
   fChain->SetBranchAddress("jet2_mva_pu", &jet2_mva_pu, &b_jet2_mva_pu);
   fChain->SetBranchAddress("jet2_id_pu", &jet2_id_pu, &b_jet2_id_pu);
   fChain->SetBranchAddress("jet2_flavour_parton", &jet2_flavour_parton, &b_jet2_flavour_parton);
   fChain->SetBranchAddress("jet2_csv", &jet2_csv, &b_jet2_csv);
   fChain->SetBranchAddress("jet2_genjet_pt", &jet2_genjet_pt, &b_jet2_genjet_pt);
   fChain->SetBranchAddress("jet2_nConstituents", &jet2_nConstituents, &b_jet2_nConstituents);
   fChain->SetBranchAddress("jet2_rawFactor", &jet2_rawFactor, &b_jet2_rawFactor);
   fChain->SetBranchAddress("jet2_chargedHadronEnergy", &jet2_chargedHadronEnergy, &b_jet2_chargedHadronEnergy);
   fChain->SetBranchAddress("jet2_neutralHadronEnergy", &jet2_neutralHadronEnergy, &b_jet2_neutralHadronEnergy);
   fChain->SetBranchAddress("jet2_neutralEmEnergy", &jet2_neutralEmEnergy, &b_jet2_neutralEmEnergy);
   fChain->SetBranchAddress("jet2_muonEnergy", &jet2_muonEnergy, &b_jet2_muonEnergy);
   fChain->SetBranchAddress("jet2_chargedEmEnergy", &jet2_chargedEmEnergy, &b_jet2_chargedEmEnergy);
   fChain->SetBranchAddress("jet2_chargedHadronMultiplicity", &jet2_chargedHadronMultiplicity, &b_jet2_chargedHadronMultiplicity);
   fChain->SetBranchAddress("jet2_chargedMultiplicity", &jet2_chargedMultiplicity, &b_jet2_chargedMultiplicity);
   fChain->SetBranchAddress("jet2_neutralMultiplicity", &jet2_neutralMultiplicity, &b_jet2_neutralMultiplicity);
   fChain->SetBranchAddress("bjet1_pt", &bjet1_pt, &b_bjet1_pt);
   fChain->SetBranchAddress("bjet1_eta", &bjet1_eta, &b_bjet1_eta);
   fChain->SetBranchAddress("bjet1_phi", &bjet1_phi, &b_bjet1_phi);
   fChain->SetBranchAddress("bjet1_charge", &bjet1_charge, &b_bjet1_charge);
   fChain->SetBranchAddress("bjet1_mass", &bjet1_mass, &b_bjet1_mass);
   fChain->SetBranchAddress("bjet1_mva_pu", &bjet1_mva_pu, &b_bjet1_mva_pu);
   fChain->SetBranchAddress("bjet1_id_pu", &bjet1_id_pu, &b_bjet1_id_pu);
   fChain->SetBranchAddress("bjet1_flavour_parton", &bjet1_flavour_parton, &b_bjet1_flavour_parton);
   fChain->SetBranchAddress("bjet1_csv", &bjet1_csv, &b_bjet1_csv);
   fChain->SetBranchAddress("bjet1_genjet_pt", &bjet1_genjet_pt, &b_bjet1_genjet_pt);
   fChain->SetBranchAddress("bjet1_nConstituents", &bjet1_nConstituents, &b_bjet1_nConstituents);
   fChain->SetBranchAddress("bjet1_rawFactor", &bjet1_rawFactor, &b_bjet1_rawFactor);
   fChain->SetBranchAddress("bjet1_chargedHadronEnergy", &bjet1_chargedHadronEnergy, &b_bjet1_chargedHadronEnergy);
   fChain->SetBranchAddress("bjet1_neutralHadronEnergy", &bjet1_neutralHadronEnergy, &b_bjet1_neutralHadronEnergy);
   fChain->SetBranchAddress("bjet1_neutralEmEnergy", &bjet1_neutralEmEnergy, &b_bjet1_neutralEmEnergy);
   fChain->SetBranchAddress("bjet1_muonEnergy", &bjet1_muonEnergy, &b_bjet1_muonEnergy);
   fChain->SetBranchAddress("bjet1_chargedEmEnergy", &bjet1_chargedEmEnergy, &b_bjet1_chargedEmEnergy);
   fChain->SetBranchAddress("bjet1_chargedHadronMultiplicity", &bjet1_chargedHadronMultiplicity, &b_bjet1_chargedHadronMultiplicity);
   fChain->SetBranchAddress("bjet1_chargedMultiplicity", &bjet1_chargedMultiplicity, &b_bjet1_chargedMultiplicity);
   fChain->SetBranchAddress("bjet1_neutralMultiplicity", &bjet1_neutralMultiplicity, &b_bjet1_neutralMultiplicity);
   fChain->SetBranchAddress("bjet2_pt", &bjet2_pt, &b_bjet2_pt);
   fChain->SetBranchAddress("bjet2_eta", &bjet2_eta, &b_bjet2_eta);
   fChain->SetBranchAddress("bjet2_phi", &bjet2_phi, &b_bjet2_phi);
   fChain->SetBranchAddress("bjet2_charge", &bjet2_charge, &b_bjet2_charge);
   fChain->SetBranchAddress("bjet2_mass", &bjet2_mass, &b_bjet2_mass);
   fChain->SetBranchAddress("bjet2_mva_pu", &bjet2_mva_pu, &b_bjet2_mva_pu);
   fChain->SetBranchAddress("bjet2_id_pu", &bjet2_id_pu, &b_bjet2_id_pu);
   fChain->SetBranchAddress("bjet2_flavour_parton", &bjet2_flavour_parton, &b_bjet2_flavour_parton);
   fChain->SetBranchAddress("bjet2_csv", &bjet2_csv, &b_bjet2_csv);
   fChain->SetBranchAddress("bjet2_genjet_pt", &bjet2_genjet_pt, &b_bjet2_genjet_pt);
   fChain->SetBranchAddress("bjet2_nConstituents", &bjet2_nConstituents, &b_bjet2_nConstituents);
   fChain->SetBranchAddress("bjet2_rawFactor", &bjet2_rawFactor, &b_bjet2_rawFactor);
   fChain->SetBranchAddress("bjet2_chargedHadronEnergy", &bjet2_chargedHadronEnergy, &b_bjet2_chargedHadronEnergy);
   fChain->SetBranchAddress("bjet2_neutralHadronEnergy", &bjet2_neutralHadronEnergy, &b_bjet2_neutralHadronEnergy);
   fChain->SetBranchAddress("bjet2_neutralEmEnergy", &bjet2_neutralEmEnergy, &b_bjet2_neutralEmEnergy);
   fChain->SetBranchAddress("bjet2_muonEnergy", &bjet2_muonEnergy, &b_bjet2_muonEnergy);
   fChain->SetBranchAddress("bjet2_chargedEmEnergy", &bjet2_chargedEmEnergy, &b_bjet2_chargedEmEnergy);
   fChain->SetBranchAddress("bjet2_chargedHadronMultiplicity", &bjet2_chargedHadronMultiplicity, &b_bjet2_chargedHadronMultiplicity);
   fChain->SetBranchAddress("bjet2_chargedMultiplicity", &bjet2_chargedMultiplicity, &b_bjet2_chargedMultiplicity);
   fChain->SetBranchAddress("bjet2_neutralMultiplicity", &bjet2_neutralMultiplicity, &b_bjet2_neutralMultiplicity);
   fChain->SetBranchAddress("HT_allJets", &HT_allJets, &b_HT_allJets);
   fChain->SetBranchAddress("HT_jets", &HT_jets, &b_HT_jets);
   fChain->SetBranchAddress("HT_bJets", &HT_bJets, &b_HT_bJets);
   fChain->SetBranchAddress("HT_cleanJets", &HT_cleanJets, &b_HT_cleanJets);
   fChain->SetBranchAddress("HT_jets30", &HT_jets30, &b_HT_jets30);
   fChain->SetBranchAddress("HT_cleanJets30", &HT_cleanJets30, &b_HT_cleanJets30);
   fChain->SetBranchAddress("genboson_pt", &genboson_pt, &b_genboson_pt);
   fChain->SetBranchAddress("genboson_eta", &genboson_eta, &b_genboson_eta);
   fChain->SetBranchAddress("genboson_phi", &genboson_phi, &b_genboson_phi);
   fChain->SetBranchAddress("genboson_charge", &genboson_charge, &b_genboson_charge);
   fChain->SetBranchAddress("genboson_mass", &genboson_mass, &b_genboson_mass);
   fChain->SetBranchAddress("genboson_pdgId", &genboson_pdgId, &b_genboson_pdgId);
   fChain->SetBranchAddress("gen_top_1_pt", &gen_top_1_pt, &b_gen_top_1_pt);
   fChain->SetBranchAddress("gen_top_2_pt", &gen_top_2_pt, &b_gen_top_2_pt);
   fChain->SetBranchAddress("gen_top_weight", &gen_top_weight, &b_gen_top_weight);
   fChain->SetBranchAddress("puppimet_pt", &puppimet_pt, &b_puppimet_pt);
   fChain->SetBranchAddress("puppimet_phi", &puppimet_phi, &b_puppimet_phi);
   fChain->SetBranchAddress("puppimet_mt1", &puppimet_mt1, &b_puppimet_mt1);
   fChain->SetBranchAddress("puppimet_mt2", &puppimet_mt2, &b_puppimet_mt2);
   fChain->SetBranchAddress("pfmet_pt", &pfmet_pt, &b_pfmet_pt);
   fChain->SetBranchAddress("pfmet_phi", &pfmet_phi, &b_pfmet_phi);
   fChain->SetBranchAddress("pfmet_mt1", &pfmet_mt1, &b_pfmet_mt1);
   fChain->SetBranchAddress("pfmet_mt2", &pfmet_mt2, &b_pfmet_mt2);
   fChain->SetBranchAddress("l1_pt", &l1_pt, &b_l1_pt);
   fChain->SetBranchAddress("l1_eta", &l1_eta, &b_l1_eta);
   fChain->SetBranchAddress("l1_phi", &l1_phi, &b_l1_phi);
   fChain->SetBranchAddress("l1_charge", &l1_charge, &b_l1_charge);
   fChain->SetBranchAddress("l1_mass", &l1_mass, &b_l1_mass);
   fChain->SetBranchAddress("l1_jet_pt", &l1_jet_pt, &b_l1_jet_pt);
   fChain->SetBranchAddress("l1_jet_eta", &l1_jet_eta, &b_l1_jet_eta);
   fChain->SetBranchAddress("l1_jet_phi", &l1_jet_phi, &b_l1_jet_phi);
   fChain->SetBranchAddress("l1_jet_charge", &l1_jet_charge, &b_l1_jet_charge);
   fChain->SetBranchAddress("l1_jet_mass", &l1_jet_mass, &b_l1_jet_mass);
   fChain->SetBranchAddress("l1_dxy", &l1_dxy, &b_l1_dxy);
   fChain->SetBranchAddress("l1_dxy_error", &l1_dxy_error, &b_l1_dxy_error);
   fChain->SetBranchAddress("l1_dz", &l1_dz, &b_l1_dz);
   fChain->SetBranchAddress("l1_dz_error", &l1_dz_error, &b_l1_dz_error);
   fChain->SetBranchAddress("l1_weight", &l1_weight, &b_l1_weight);
   fChain->SetBranchAddress("l1_weight_trigger", &l1_weight_trigger, &b_l1_weight_trigger);
   fChain->SetBranchAddress("l1_weight_eff_data_trigger", &l1_weight_eff_data_trigger, &b_l1_weight_eff_data_trigger);
   fChain->SetBranchAddress("l1_eff_trigger_data", &l1_eff_trigger_data, &b_l1_eff_trigger_data);
   fChain->SetBranchAddress("l1_eff_trigger_mc", &l1_eff_trigger_mc, &b_l1_eff_trigger_mc);
   fChain->SetBranchAddress("l1_weight_idiso", &l1_weight_idiso, &b_l1_weight_idiso);
   fChain->SetBranchAddress("l1_eff_idiso_data", &l1_eff_idiso_data, &b_l1_eff_idiso_data);
   fChain->SetBranchAddress("l1_eff_idiso_mc", &l1_eff_idiso_mc, &b_l1_eff_idiso_mc);
   fChain->SetBranchAddress("l1_gen_match", &l1_gen_match, &b_l1_gen_match);
   fChain->SetBranchAddress("l1_reliso05", &l1_reliso05, &b_l1_reliso05);
   fChain->SetBranchAddress("l1_reliso05_03", &l1_reliso05_03, &b_l1_reliso05_03);
   fChain->SetBranchAddress("l1_muonid_loose", &l1_muonid_loose, &b_l1_muonid_loose);
   fChain->SetBranchAddress("l1_muonid_medium", &l1_muonid_medium, &b_l1_muonid_medium);
   fChain->SetBranchAddress("l1_muonid_tight", &l1_muonid_tight, &b_l1_muonid_tight);
   fChain->SetBranchAddress("l1_muonid_tightnovtx", &l1_muonid_tightnovtx, &b_l1_muonid_tightnovtx);
   fChain->SetBranchAddress("l1_muonid_highpt", &l1_muonid_highpt, &b_l1_muonid_highpt);
   fChain->SetBranchAddress("l1_dxy_innertrack", &l1_dxy_innertrack, &b_l1_dxy_innertrack);
   fChain->SetBranchAddress("l1_dz_innertrack", &l1_dz_innertrack, &b_l1_dz_innertrack);
   fChain->SetBranchAddress("l2_pt", &l2_pt, &b_l2_pt);
   fChain->SetBranchAddress("l2_eta", &l2_eta, &b_l2_eta);
   fChain->SetBranchAddress("l2_phi", &l2_phi, &b_l2_phi);
   fChain->SetBranchAddress("l2_charge", &l2_charge, &b_l2_charge);
   fChain->SetBranchAddress("l2_mass", &l2_mass, &b_l2_mass);
   fChain->SetBranchAddress("l2_jet_pt", &l2_jet_pt, &b_l2_jet_pt);
   fChain->SetBranchAddress("l2_jet_eta", &l2_jet_eta, &b_l2_jet_eta);
   fChain->SetBranchAddress("l2_jet_phi", &l2_jet_phi, &b_l2_jet_phi);
   fChain->SetBranchAddress("l2_jet_charge", &l2_jet_charge, &b_l2_jet_charge);
   fChain->SetBranchAddress("l2_jet_mass", &l2_jet_mass, &b_l2_jet_mass);
   fChain->SetBranchAddress("l2_dxy", &l2_dxy, &b_l2_dxy);
   fChain->SetBranchAddress("l2_dxy_error", &l2_dxy_error, &b_l2_dxy_error);
   fChain->SetBranchAddress("l2_dz", &l2_dz, &b_l2_dz);
   fChain->SetBranchAddress("l2_dz_error", &l2_dz_error, &b_l2_dz_error);
   fChain->SetBranchAddress("l2_weight", &l2_weight, &b_l2_weight);
   fChain->SetBranchAddress("l2_weight_trigger", &l2_weight_trigger, &b_l2_weight_trigger);
   fChain->SetBranchAddress("l2_weight_eff_data_trigger", &l2_weight_eff_data_trigger, &b_l2_weight_eff_data_trigger);
   fChain->SetBranchAddress("l2_eff_trigger_data", &l2_eff_trigger_data, &b_l2_eff_trigger_data);
   fChain->SetBranchAddress("l2_eff_trigger_mc", &l2_eff_trigger_mc, &b_l2_eff_trigger_mc);
   fChain->SetBranchAddress("l2_weight_idiso", &l2_weight_idiso, &b_l2_weight_idiso);
   fChain->SetBranchAddress("l2_eff_idiso_data", &l2_eff_idiso_data, &b_l2_eff_idiso_data);
   fChain->SetBranchAddress("l2_eff_idiso_mc", &l2_eff_idiso_mc, &b_l2_eff_idiso_mc);
   fChain->SetBranchAddress("l2_gen_match", &l2_gen_match, &b_l2_gen_match);
   fChain->SetBranchAddress("l2_reliso05", &l2_reliso05, &b_l2_reliso05);
   fChain->SetBranchAddress("l2_reliso05_03", &l2_reliso05_03, &b_l2_reliso05_03);
   fChain->SetBranchAddress("l2_muonid_loose", &l2_muonid_loose, &b_l2_muonid_loose);
   fChain->SetBranchAddress("l2_muonid_medium", &l2_muonid_medium, &b_l2_muonid_medium);
   fChain->SetBranchAddress("l2_muonid_tight", &l2_muonid_tight, &b_l2_muonid_tight);
   fChain->SetBranchAddress("l2_muonid_tightnovtx", &l2_muonid_tightnovtx, &b_l2_muonid_tightnovtx);
   fChain->SetBranchAddress("l2_muonid_highpt", &l2_muonid_highpt, &b_l2_muonid_highpt);
   fChain->SetBranchAddress("l2_dxy_innertrack", &l2_dxy_innertrack, &b_l2_dxy_innertrack);
   fChain->SetBranchAddress("l2_dz_innertrack", &l2_dz_innertrack, &b_l2_dz_innertrack);
   fChain->SetBranchAddress("l1_gen_pt", &l1_gen_pt, &b_l1_gen_pt);
   fChain->SetBranchAddress("l1_gen_eta", &l1_gen_eta, &b_l1_gen_eta);
   fChain->SetBranchAddress("l1_gen_phi", &l1_gen_phi, &b_l1_gen_phi);
   fChain->SetBranchAddress("l1_gen_charge", &l1_gen_charge, &b_l1_gen_charge);
   fChain->SetBranchAddress("l1_gen_mass", &l1_gen_mass, &b_l1_gen_mass);
   fChain->SetBranchAddress("l1_gen_pdgId", &l1_gen_pdgId, &b_l1_gen_pdgId);
   fChain->SetBranchAddress("l2_gen_pt", &l2_gen_pt, &b_l2_gen_pt);
   fChain->SetBranchAddress("l2_gen_eta", &l2_gen_eta, &b_l2_gen_eta);
   fChain->SetBranchAddress("l2_gen_phi", &l2_gen_phi, &b_l2_gen_phi);
   fChain->SetBranchAddress("l2_gen_charge", &l2_gen_charge, &b_l2_gen_charge);
   fChain->SetBranchAddress("l2_gen_mass", &l2_gen_mass, &b_l2_gen_mass);
   fChain->SetBranchAddress("l2_gen_pdgId", &l2_gen_pdgId, &b_l2_gen_pdgId);
   fChain->SetBranchAddress("tau1_pt", &tau1_pt, &b_tau1_pt);
   fChain->SetBranchAddress("tau1_eta", &tau1_eta, &b_tau1_eta);
   fChain->SetBranchAddress("tau1_phi", &tau1_phi, &b_tau1_phi);
   fChain->SetBranchAddress("tau1_charge", &tau1_charge, &b_tau1_charge);
   fChain->SetBranchAddress("tau1_mass", &tau1_mass, &b_tau1_mass);
   fChain->SetBranchAddress("tau1_jet_pt", &tau1_jet_pt, &b_tau1_jet_pt);
   fChain->SetBranchAddress("tau1_jet_eta", &tau1_jet_eta, &b_tau1_jet_eta);
   fChain->SetBranchAddress("tau1_jet_phi", &tau1_jet_phi, &b_tau1_jet_phi);
   fChain->SetBranchAddress("tau1_jet_charge", &tau1_jet_charge, &b_tau1_jet_charge);
   fChain->SetBranchAddress("tau1_jet_mass", &tau1_jet_mass, &b_tau1_jet_mass);
   fChain->SetBranchAddress("tau1_dxy", &tau1_dxy, &b_tau1_dxy);
   fChain->SetBranchAddress("tau1_dxy_error", &tau1_dxy_error, &b_tau1_dxy_error);
   fChain->SetBranchAddress("tau1_dz", &tau1_dz, &b_tau1_dz);
   fChain->SetBranchAddress("tau1_dz_error", &tau1_dz_error, &b_tau1_dz_error);
   fChain->SetBranchAddress("tau1_weight", &tau1_weight, &b_tau1_weight);
   fChain->SetBranchAddress("tau1_weight_trigger", &tau1_weight_trigger, &b_tau1_weight_trigger);
   fChain->SetBranchAddress("tau1_weight_eff_data_trigger", &tau1_weight_eff_data_trigger, &b_tau1_weight_eff_data_trigger);
   fChain->SetBranchAddress("tau1_eff_trigger_data", &tau1_eff_trigger_data, &b_tau1_eff_trigger_data);
   fChain->SetBranchAddress("tau1_eff_trigger_mc", &tau1_eff_trigger_mc, &b_tau1_eff_trigger_mc);
   fChain->SetBranchAddress("tau1_weight_idiso", &tau1_weight_idiso, &b_tau1_weight_idiso);
   fChain->SetBranchAddress("tau1_eff_idiso_data", &tau1_eff_idiso_data, &b_tau1_eff_idiso_data);
   fChain->SetBranchAddress("tau1_eff_idiso_mc", &tau1_eff_idiso_mc, &b_tau1_eff_idiso_mc);
   fChain->SetBranchAddress("tau1_gen_match", &tau1_gen_match, &b_tau1_gen_match);
   fChain->SetBranchAddress("tau1_decayMode", &tau1_decayMode, &b_tau1_decayMode);
   fChain->SetBranchAddress("tau1_zImpact", &tau1_zImpact, &b_tau1_zImpact);
   fChain->SetBranchAddress("tau1_dz_selfvertex", &tau1_dz_selfvertex, &b_tau1_dz_selfvertex);
   fChain->SetBranchAddress("tau1_ptScale", &tau1_ptScale, &b_tau1_ptScale);
   fChain->SetBranchAddress("tau1_againstElectronMVA6", &tau1_againstElectronMVA6, &b_tau1_againstElectronMVA6);
   fChain->SetBranchAddress("tau1_againstMuon3", &tau1_againstMuon3, &b_tau1_againstMuon3);
   fChain->SetBranchAddress("tau1_byCombinedIsolationDeltaBetaCorrRaw3Hits", &tau1_byCombinedIsolationDeltaBetaCorrRaw3Hits, &b_tau1_byCombinedIsolationDeltaBetaCorrRaw3Hits);
   fChain->SetBranchAddress("tau1_byIsolationMVArun2v1DBoldDMwLTraw", &tau1_byIsolationMVArun2v1DBoldDMwLTraw, &b_tau1_byIsolationMVArun2v1DBoldDMwLTraw);
   fChain->SetBranchAddress("tau1_byIsolationMVArun2v1DBnewDMwLTraw", &tau1_byIsolationMVArun2v1DBnewDMwLTraw, &b_tau1_byIsolationMVArun2v1DBnewDMwLTraw);
   fChain->SetBranchAddress("tau1_byIsolationMVArun2v1DBdR03oldDMwLTraw", &tau1_byIsolationMVArun2v1DBdR03oldDMwLTraw, &b_tau1_byIsolationMVArun2v1DBdR03oldDMwLTraw);
   fChain->SetBranchAddress("tau1_byCombinedIsolationDeltaBetaCorr3Hits", &tau1_byCombinedIsolationDeltaBetaCorr3Hits, &b_tau1_byCombinedIsolationDeltaBetaCorr3Hits);
   fChain->SetBranchAddress("tau1_byIsolationMVArun2v1DBoldDMwLT", &tau1_byIsolationMVArun2v1DBoldDMwLT, &b_tau1_byIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tau1_byIsolationMVArun2v1DBnewDMwLT", &tau1_byIsolationMVArun2v1DBnewDMwLT, &b_tau1_byIsolationMVArun2v1DBnewDMwLT);
   fChain->SetBranchAddress("tau1_byIsolationMVArun2v1DBdR03oldDMwLT", &tau1_byIsolationMVArun2v1DBdR03oldDMwLT, &b_tau1_byIsolationMVArun2v1DBdR03oldDMwLT);
   fChain->SetBranchAddress("tau1_chargedIsoPtSum", &tau1_chargedIsoPtSum, &b_tau1_chargedIsoPtSum);
   fChain->SetBranchAddress("tau1_decayModeFinding", &tau1_decayModeFinding, &b_tau1_decayModeFinding);
   fChain->SetBranchAddress("tau1_footprintCorrection", &tau1_footprintCorrection, &b_tau1_footprintCorrection);
   fChain->SetBranchAddress("tau1_neutralIsoPtSum", &tau1_neutralIsoPtSum, &b_tau1_neutralIsoPtSum);
   fChain->SetBranchAddress("tau1_puCorrPtSum", &tau1_puCorrPtSum, &b_tau1_puCorrPtSum);
   fChain->SetBranchAddress("tau1_photonPtSumOutsideSignalCone", &tau1_photonPtSumOutsideSignalCone, &b_tau1_photonPtSumOutsideSignalCone);
   fChain->SetBranchAddress("tau1_byTightIsolationMVArun2v1DBoldDMwLT", &tau1_byTightIsolationMVArun2v1DBoldDMwLT, &b_tau1_byTightIsolationMVArun2v1DBoldDMwLT);
   fChain->SetBranchAddress("tau1_gen_pt", &tau1_gen_pt, &b_tau1_gen_pt);
   fChain->SetBranchAddress("tau1_gen_eta", &tau1_gen_eta, &b_tau1_gen_eta);
   fChain->SetBranchAddress("tau1_gen_phi", &tau1_gen_phi, &b_tau1_gen_phi);
   fChain->SetBranchAddress("tau1_gen_charge", &tau1_gen_charge, &b_tau1_gen_charge);
   fChain->SetBranchAddress("tau1_gen_mass", &tau1_gen_mass, &b_tau1_gen_mass);
   fChain->SetBranchAddress("tau1_gen_pdgId", &tau1_gen_pdgId, &b_tau1_gen_pdgId);
   Notify();
}

Bool_t treeBase_Zmumu::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void treeBase_Zmumu::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t treeBase_Zmumu::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
void treeBase_Zmumu::Loop()
{
//   In a ROOT session, you can do:
//      root> .L treeBase_Zmumu.C
//      root> treeBase_Zmumu t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   }
}
#endif // #ifdef treeBase_Zmumu_cxx

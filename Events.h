#ifndef EVENT_H
#define EVENT_H
#include "TTree.h"
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include "TLorentzVector.h"
#include <stdio.h>
#include "TColor.h"
#include "TF1.h"
#include "TLegend.h"
#include "TVector3.h"
#include "TFile.h"
#include "TChain.h"
#include "TH1.h"
#include "TH1F.h"
#include "TH3F.h"

#include "TVector2.h"
#include "TCanvas.h"
using namespace std;

  class Events{

       // Declaration of leaf types
      UInt_t          RunNum;
      UInt_t          LumiBlockNum;
      UInt_t          EvtNum;
      Int_t           NVtx;
      Int_t           isoElectronTracks;
      Int_t           isoMuonTracks;
      Int_t           isoPionTracks;
      Int_t           Leptons;
      Int_t           LeptonsNoMiniIsolation;
      Int_t           NJets;
      Int_t           BTags;
      Float_t         Weight;
      Float_t         HT;
      Float_t         MHT;
      Float_t         MHTPhi;
      Float_t         DeltaPhi1;
      Float_t         DeltaPhi2;
      Float_t         DeltaPhi3;
      Float_t         MinDeltaPhiN;
      Float_t         DeltaPhiN1;
      Float_t         DeltaPhiN2;
      Float_t         DeltaPhiN3;
      Float_t         METPt;
      Float_t         METPhi;
      UChar_t         JetID;
      UChar_t         passing;
      UShort_t        allJetNum;
      Float_t         allJetPt[140];   //[allJetNum]
      Float_t         allJetEta[140];   //[allJetNum]
      Float_t         allJetPhi[140];   //[allJetNum]
      Float_t         allJetE[140];   //[allJetNum]
      Int_t           allJet_allJetID[140];   //[allJetNum]
      UShort_t        JetsNum;
      Float_t         JetsPt[17];   //[JetsNum]
      Float_t         JetsEta[17];   //[JetsNum]
      Float_t         JetsPhi[17];   //[JetsNum]
      Float_t         JetsE[17];   //[JetsNum]
      Float_t         Jets_bDiscriminator[17];   //[JetsNum]
      Float_t         Jets_chargedEmEnergyFraction[17];   //[JetsNum]
      Float_t         Jets_chargedHadronEnergyFraction[17];   //[JetsNum]
      Int_t           Jets_chargedHadronMultiplicity[17];   //[JetsNum]
      Int_t           Jets_electronMultiplicity[17];   //[JetsNum]
      Float_t         Jets_jetArea[17];   //[JetsNum]
      Float_t         Jets_muonEnergyFraction[17];   //[JetsNum]
      Int_t           Jets_muonMultiplicity[17];   //[JetsNum]
      Float_t         Jets_neutralEmEnergyFraction[17];   //[JetsNum]
      Int_t           Jets_neutralHadronMultiplicity[17];   //[JetsNum]
      Float_t         Jets_photonEnergyFraction[17];   //[JetsNum]
      Int_t           Jets_photonMultiplicity[17];   //[JetsNum]
      UShort_t        SelectedPFCandidatesNum;
      Float_t         SelectedPFCandidatesPt[145];   //[SelectedPFCandidatesNum]
      Float_t         SelectedPFCandidatesEta[145];   //[SelectedPFCandidatesNum]
      Float_t         SelectedPFCandidatesPhi[145];   //[SelectedPFCandidatesNum]
      Float_t         SelectedPFCandidatesE[145];   //[SelectedPFCandidatesNum]
      Int_t           SelectedPFCandidates_Charge[145];   //[SelectedPFCandidatesNum]
      Int_t           SelectedPFCandidates_Typ[145];   //[SelectedPFCandidatesNum]
      UShort_t        GenBosonNum;
      Float_t         GenBosonPt[2];   //[GenBosonNum]
      Float_t         GenBosonEta[2];   //[GenBosonNum]
      Float_t         GenBosonPhi[2];   //[GenBosonNum]
      Float_t         GenBosonE[2];   //[GenBosonNum]
      Int_t           GenBoson_GenBosonPDGId[2];   //[GenBosonNum]
      UShort_t        GenMuNum;
      Float_t         GenMuPt[2];   //[GenMuNum]
      Float_t         GenMuEta[2];   //[GenMuNum]
      Float_t         GenMuPhi[2];   //[GenMuNum]
      Float_t         GenMuE[2];   //[GenMuNum]
      Int_t           GenMu_GenMuFromTau[2];   //[GenMuNum]
      UShort_t        GenElecNum;
      Float_t         GenElecPt[2];   //[GenElecNum]
      Float_t         GenElecEta[2];   //[GenElecNum]
      Float_t         GenElecPhi[2];   //[GenElecNum]
      Float_t         GenElecE[2];   //[GenElecNum]
      Int_t           GenElec_GenElecFromTau[2];   //[GenElecNum]
      UShort_t        GenTauNum;
      Float_t         GenTauPt[2];   //[GenTauNum]
      Float_t         GenTauEta[2];   //[GenTauNum]
      Float_t         GenTauPhi[2];   //[GenTauNum]
      Float_t         GenTauE[2];   //[GenTauNum]
      Int_t           GenTau_GenTauHad[2];   //[GenTauNum]
      UShort_t        TauDaughtersNum;
      Float_t         TauDaughtersPt[11];   //[TauDaughtersNum]
      Float_t         TauDaughtersEta[11];   //[TauDaughtersNum]
      Float_t         TauDaughtersPhi[11];   //[TauDaughtersNum]
      Float_t         TauDaughtersE[11];   //[TauDaughtersNum]
      Int_t           TauDaughters_TauDaughtersPDGId[11];   //[TauDaughtersNum]
      UShort_t        SelectedPFCandidates_1Num;
      Float_t         SelectedPFCandidates_1Pt[145];   //[SelectedPFCandidates_1Num]
      Float_t         SelectedPFCandidates_1Eta[145];   //[SelectedPFCandidates_1Num]
      Float_t         SelectedPFCandidates_1Phi[145];   //[SelectedPFCandidates_1Num]
      Float_t         SelectedPFCandidates_1E[145];   //[SelectedPFCandidates_1Num]
      Int_t           SelectedPFCandidates_1_Charge[145];   //[SelectedPFCandidates_1Num]
      Int_t           SelectedPFCandidates_1_Typ[145];   //[SelectedPFCandidates_1Num]
      Float_t         SelectedPFCandidates_1_mT[145];   //[SelectedPFCandidates_1Num]
      Int_t           SelectedPFCandidates_1_Typ_1[145];   //[SelectedPFCandidates_1Num]
      Float_t         SelectedPFCandidates_1_dZ[145];   //[SelectedPFCandidates_1Num]
      UShort_t        MuonsNum;
      Float_t         MuonsPt[4];   //[MuonsNum]
      Float_t         MuonsEta[4];   //[MuonsNum]
      Float_t         MuonsPhi[4];   //[MuonsNum]
      Float_t         MuonsE[4];   //[MuonsNum]
      UShort_t        selectedIDMuonsNum;
      Float_t         selectedIDMuonsPt[4];   //[selectedIDMuonsNum]
      Float_t         selectedIDMuonsEta[4];   //[selectedIDMuonsNum]
      Float_t         selectedIDMuonsPhi[4];   //[selectedIDMuonsNum]
      Float_t         selectedIDMuonsE[4];   //[selectedIDMuonsNum]
      
      UShort_t        ElectronsNum;
      Float_t         ElectronsPt[4];   //[ElectronsNum]
      Float_t         ElectronsEta[4];   //[ElectronsNum]
      Float_t         ElectronsPhi[4];   //[ElectronsNum]
      Float_t         ElectronsE[4];   //[ElectronsNum]

      TTree *         fChain;
      int             currentEntry_;
      int             template_Entries;
      TBranch        *b_RunNum;   //!
      TBranch        *b_LumiBlockNum;   //!
      TBranch        *b_EvtNum;   //!
      TBranch        *b_NVtx;   //!
      TBranch        *b_isoElectronTracks;   //!
      TBranch        *b_isoMuonTracks;   //!
      TBranch        *b_isoPionTracks;   //!
      TBranch        *b_Leptons;   //!
      TBranch        *b_LeptonsNoMiniIsolation;   //!
      TBranch        *b_NJets;   //!
      TBranch        *b_BTags;   //!
      TBranch        *b_Weight;   //!
      TBranch        *b_HT;   //!
      TBranch        *b_MHT;   //!
      TBranch        *b_DeltaPhi1;   //!
      TBranch        *b_DeltaPhi2;   //!
      TBranch        *b_DeltaPhi3;   //!
      TBranch        *b_minDeltaPhiN;   //!
      TBranch        *b_DeltaPhiN1;   //!
      TBranch        *b_DeltaPhiN2;   //!
      TBranch        *b_DeltaPhiN3;   //!
      TBranch        *b_METPt;   //!
      TBranch        *b_METPhi;   //!
      TBranch        *b_JetID;   //!
      TBranch        *b_passing;   //!
      TBranch        *b_allJetNum;   //!
      TBranch        *b_allJetPt;   //!
      TBranch        *b_allJetEta;   //!
      TBranch        *b_allJetPhi;   //!
      TBranch        *b_allJetE;   //!
      TBranch        *b_allJet_allJetID;   //!
      TBranch        *b_JetsNum;   //!
      TBranch        *b_JetsPt;   //!
      TBranch        *b_JetsEta;   //!
      TBranch        *b_JetsPhi;   //!
      TBranch        *b_JetsE;   //!
      TBranch        *b_Jets_bDiscriminator;   //!
      TBranch        *b_Jets_chargedEmEnergyFraction;   //!
      TBranch        *b_Jets_chargedHadronEnergyFraction;   //!
      TBranch        *b_Jets_chargedHadronMultiplicity;   //!
      TBranch        *b_Jets_electronMultiplicity;   //!
      TBranch        *b_Jets_jetArea;   //!
      TBranch        *b_Jets_muonEnergyFraction;   //!
      TBranch        *b_Jets_muonMultiplicity;   //!
      TBranch        *b_Jets_neutralEmEnergyFraction;   //!
      TBranch        *b_Jets_neutralHadronMultiplicity;   //!
      TBranch        *b_Jets_photonEnergyFraction;   //!
      TBranch        *b_Jets_photonMultiplicity;   //!
      TBranch        *b_SelectedPFCandidatesNum;   //!
      TBranch        *b_SelectedPFCandidatesPt;   //!
      TBranch        *b_SelectedPFCandidatesEta;   //!
      TBranch        *b_SelectedPFCandidatesPhi;   //!
      TBranch        *b_SelectedPFCandidatesE;   //!
      TBranch        *b_SelectedPFCandidates_Charge;   //!
      TBranch        *b_SelectedPFCandidates_Typ;   //!
      TBranch        *b_GenBosonNum;   //!
      TBranch        *b_GenBosonPt;   //!
      TBranch        *b_GenBosonEta;   //!
      TBranch        *b_GenBosonPhi;   //!
      TBranch        *b_GenBosonE;   //!
      TBranch        *b_GenBoson_GenBosonPDGId;   //!
      TBranch        *b_GenMuNum;   //!
      TBranch        *b_GenMuPt;   //!
      TBranch        *b_GenMuEta;   //!
      TBranch        *b_GenMuPhi;   //!
      TBranch        *b_GenMuE;   //!
      TBranch        *b_GenMu_GenMuFromTau;   //!
      TBranch        *b_GenElecNum;   //!
      TBranch        *b_GenElecPt;   //!
      TBranch        *b_GenElecEta;   //!
      TBranch        *b_GenElecPhi;   //!
      TBranch        *b_GenElecE;   //!
      TBranch        *b_GenElec_GenElecFromTau;   //!
      TBranch        *b_GenTauNum;   //!
      TBranch        *b_GenTauPt;   //!
      TBranch        *b_GenTauEta;   //!
      TBranch        *b_GenTauPhi;   //!
      TBranch        *b_GenTauE;   //!
      TBranch        *b_GenTau_GenTauHad;   //!
      TBranch        *b_TauDaughtersNum;   //!
      TBranch        *b_TauDaughtersPt;   //!
      TBranch        *b_TauDaughtersEta;   //!
      TBranch        *b_TauDaughtersPhi;   //!
      TBranch        *b_TauDaughtersE;   //!
      TBranch        *b_TauDaughters_TauDaughtersPDGId;   //!
      TBranch        *b_SelectedPFCandidates_1Num;   //!
      TBranch        *b_SelectedPFCandidates_1Pt;   //!
      TBranch        *b_SelectedPFCandidates_1Eta;   //!
      TBranch        *b_SelectedPFCandidates_1Phi;   //!
      TBranch        *b_SelectedPFCandidates_1E;   //!
      TBranch        *b_SelectedPFCandidates_1_Charge;   //!
      TBranch        *b_SelectedPFCandidates_1_Typ;   //!
      TBranch        *b_SelectedPFCandidates_1_mT;   //!
      TBranch        *b_SelectedPFCandidates_1_Typ_1;   //!
      TBranch        *b_SelectedPFCandidates_1_dZ;   //!
      TBranch        *b_MuonsNum;   //!
      TBranch        *b_MuonsPt;   //!
      TBranch        *b_MuonsEta;   //!
      TBranch        *b_MuonsPhi;   //!
      TBranch        *b_MuonsE;   //!
      TBranch        *b_selectedIDMuonsNum;   //!
      TBranch        *b_selectedIDMuonsPt;   //!
      TBranch        *b_selectedIDMuonsEta;   //!
      TBranch        *b_selectedIDMuonsPhi;   //!
      TBranch        *b_selectedIDMuonsE;   //!
      TBranch        *b_ElectronsNum;   //!
      TBranch        *b_ElectronsPt;   //!
      TBranch        *b_ElectronsEta;   //!
      TBranch        *b_ElectronsPhi;   //!
      TBranch        *b_ElectronsE;   //!
      /*
      vector<double>  JetsPtVec;
      vector<double>  JetsEtaVec;
      vector<double>  JetsPhiVec;
      
      vector<double>  GoodJetsPtVec;
      vector<double>  GoodJetsEtaVec;
      vector<double>  GoodJetsPhiVec;
      
      vector<double>  MuonsPtVec;
      vector<double>  MuonsEtaVec;
      vector<double>  MuonsPhiVec;
      
      vector<double>  GenTauPtVec;
      vector<double>  GenTauEtaVec;
      vector<double>  GenTauPhiVec;
      
      vector<double>  GenTauPtVec;
      vector<double>  GenTauEtaVec;
      vector<double>  GenTauPhiVec;
      */
      vector<TLorentzVector>  GenTau;
      vector<TLorentzVector> allJets;
      vector<TLorentzVector>  GenMu;

      vector<TLorentzVector>  GenMuTau;
      vector<TLorentzVector> GoodJets;
      vector<TLorentzVector>  SelMuons;
      vector<TLorentzVector>  MatchedJet;
      vector<float>  MatchedJetB;

      vector<TLorentzVector>  MatchedTauJet;
      vector<float>  MatchedTauJetB;


      TH1F*templatesToRead[4];
      TH1F*TauBEff;
      vector<float>SmearedMuonPt;
      vector<float>SmearedMuonWeight;


public:
//constructor
Events(TTree * ttree_);

//Functions
  bool loadNext();
  int nJets() const;
  int nBtags() const;
      int nEle() const;
  int nIsoElec() const ;
  int nIsoMu() const ;
  int nIsoPion() const;
  double weight() const ;
  double ht() const ;
  double mht() const ;
  double mhtphi() const ;

  double minDeltaPhiN() const ;
  int nGenMu() const ;
  int JetId() const ;
  vector<TLorentzVector> SelMu_();
  vector<TLorentzVector> GenMu_();
  vector<TLorentzVector> GenTau_();
  vector<TLorentzVector> MatchTauJets_();
  vector<float>TauJetsBtagged_();
  vector<TLorentzVector> AllJets_();
  vector<TLorentzVector> GoodJets_();
  vector<TLorentzVector> MuMatchedJet_();

  vector<float> TempResponsePt(float muPt);
  vector<float> TempResponseWeight(float muPt);
  float TempResponsePtRandom(float muPt);
  float dphiN(TLorentzVector& muJet,TLorentzVector& MHTVec);
  float dTheta(TLorentzVector& muJet,int gjetindex);
  float JetBtagEff(float visiblePt);
  vector<float>MatchJetsBtagged_();
 // void fillSearchBins(TH3F*inputRectoHisto, TH1F*input1D);
      /*
   vector<double>  csvVec() const;
   vector<double>  Jets_chargedEmEnergyFraction_() const;
   vector<double>  Jets_chargedHadronEnergyFraction_() const;
   vector<int>     Jets_chargedHadronMultiplicity_() const;
   vector<int>     Jets_electronMultiplicity_() const;
   vector<double>  Jets_jetArea_() const;
   vector<double>  Jets_muonEnergyFraction_() const;
   vector<int>     Jets_muonMultiplicity_() const;
   vector<double>  Jets_neutralEmEnergyFraction_() const;
   vector<int>     Jets_neutralHadronMultiplicity_() const;
   vector<double>  Jets_photonEnergyFraction_() const; 
   vector<int>     Jets_photonMultiplicity_() const;

   vector<int>     GenTauHadVec_() const;   
      */
};//end of class Events
#endif

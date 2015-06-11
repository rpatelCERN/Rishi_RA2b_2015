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
      TTree *         fChain;
      int             currentEntry_;
      int             template_Entries;

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
      Float_t         MHTPhi;
      Float_t         MHT;
      Float_t         DeltaPhi1;
      Float_t         DeltaPhi2;
      Float_t         DeltaPhi3;
      Float_t         minDeltaPhiN;
      Float_t         DeltaPhiN1;
      Float_t         DeltaPhiN2;
      Float_t         DeltaPhiN3;
      Float_t         METPt;
      Float_t         METPhi;
      UChar_t         JetID;
   vector<double>  *testVec;
   vector<double>  *MuonsPtVec;
   vector<double>  *MuonsEtaVec;
   vector<double>  *MuonsPhiVec;
   UShort_t        MuonsNum;
   Float_t         MuonsE[4];   //[MuonsNum]
   Float_t         MuonsTLorentzVector[4];   //[MuonsNum]
   vector<double>  *ElectronsPtVec;
   vector<double>  *ElectronsEtaVec;
   vector<double>  *ElectronsPhiVec;
   UShort_t        ElectronsNum;
   Float_t         ElectronsE[4];   //[ElectronsNum]
   Float_t         ElectronsTLorentzVector[4];   //[ElectronsNum]
   vector<double>  *IsolatedTracksPtVec;
   vector<double>  *IsolatedTracksEtaVec;
   vector<double>  *IsolatedTracksPhiVec;
   UShort_t        IsolatedTracksNum;
   Float_t         IsolatedTracksE[1];   //[IsolatedTracksNum]
   Float_t         IsolatedTracksTLorentzVector[1];   //[IsolatedTracksNum]
   vector<double>  *selectedIDIsoMuonsPtVec;
   vector<double>  *selectedIDIsoMuonsEtaVec;
   vector<double>  *selectedIDIsoMuonsPhiVec;
   UShort_t        selectedIDIsoMuonsNum;
   Float_t         selectedIDIsoMuonsE[4];   //[selectedIDIsoMuonsNum]
   Float_t         selectedIDIsoMuonsTLorentzVector[4];   //[selectedIDIsoMuonsNum]
   vector<double>  *selectedIDMuonsPtVec;
   vector<double>  *selectedIDMuonsEtaVec;
   vector<double>  *selectedIDMuonsPhiVec;
   UShort_t        selectedIDMuonsNum;
   Float_t         selectedIDMuonsE[6];   //[selectedIDMuonsNum]
   Float_t         selectedIDMuonsTLorentzVector[6];   //[selectedIDMuonsNum]
   vector<double>  *selectedIDIsoElectronsPtVec;
   vector<double>  *selectedIDIsoElectronsEtaVec;
   vector<double>  *selectedIDIsoElectronsPhiVec;
   UShort_t        selectedIDIsoElectronsNum;
   Float_t         selectedIDIsoElectronsE[4];   //[selectedIDIsoElectronsNum]
   Float_t         selectedIDIsoElectronsTLorentzVector[4];   //[selectedIDIsoElectronsNum]
   vector<double>  *selectedIDElectronsPtVec;
   vector<double>  *selectedIDElectronsEtaVec;
   vector<double>  *selectedIDElectronsPhiVec;
   UShort_t        selectedIDElectronsNum;
   Float_t         selectedIDElectronsE[5];   //[selectedIDElectronsNum]
   Float_t         selectedIDElectronsTLorentzVector[5];   //[selectedIDElectronsNum]
   vector<double>  *SelectedPFCandidatesPtVec;
   vector<double>  *SelectedPFCandidatesEtaVec;
   vector<double>  *SelectedPFCandidatesPhiVec;
   UShort_t        SelectedPFCandidatesNum;
   Float_t         SelectedPFCandidatesE[149];   //[SelectedPFCandidatesNum]
   Float_t         SelectedPFCandidatesTLorentzVector[149];   //[SelectedPFCandidatesNum]
   Int_t           SelectedPFCandidates_Charge[149];   //[SelectedPFCandidatesNum]
   Int_t           SelectedPFCandidates_Typ[149];   //[SelectedPFCandidatesNum]
   vector<double>  *GenBosonPtVec;
   vector<double>  *GenBosonEtaVec;
   vector<double>  *GenBosonPhiVec;
   UShort_t        GenBosonNum;
   Float_t         GenBosonE[2];   //[GenBosonNum]
   Float_t         GenBosonTLorentzVector[2];   //[GenBosonNum]
   Int_t           GenBoson_GenBosonPDGId[2];   //[GenBosonNum]
   vector<double>  *GenMuPtVec;
   vector<double>  *GenMuEtaVec;
   vector<double>  *GenMuPhiVec;
   UShort_t        GenMuNum;
   Float_t         GenMuE[2];   //[GenMuNum]
   Float_t         GenMuTLorentzVector[2];   //[GenMuNum]
   Int_t           GenMu_GenMuFromTau[2];   //[GenMuNum]
   vector<double>  *GenElecPtVec;
   vector<double>  *GenElecEtaVec;
   vector<double>  *GenElecPhiVec;
   UShort_t        GenElecNum;
   Float_t         GenElecE[2];   //[GenElecNum]
   Float_t         GenElecTLorentzVector[2];   //[GenElecNum]
   Int_t           GenElec_GenElecFromTau[2];   //[GenElecNum]
   vector<double>  *GenTauPtVec;
   vector<double>  *GenTauEtaVec;
   vector<double>  *GenTauPhiVec;
   UShort_t        GenTauNum;
   Float_t         GenTauE[2];   //[GenTauNum]
   Float_t         GenTauTLorentzVector[2];   //[GenTauNum]
   Int_t           GenTau_GenTauHad[2];   //[GenTauNum]
   vector<double>  *selectedIDIsoMuonsNoMiniIsoPtVec;
   vector<double>  *selectedIDIsoMuonsNoMiniIsoEtaVec;
   vector<double>  *selectedIDIsoMuonsNoMiniIsoPhiVec;
   UShort_t        selectedIDIsoMuonsNoMiniIsoNum;
   Float_t         selectedIDIsoMuonsNoMiniIsoE[4];   //[selectedIDIsoMuonsNoMiniIsoNum]
   Float_t         selectedIDIsoMuonsNoMiniIsoTLorentzVector[4];   //[selectedIDIsoMuonsNoMiniIsoNum]
   vector<double>  *selectedIDIsoElectronsNoMiniIsoPtVec;
   vector<double>  *selectedIDIsoElectronsNoMiniIsoEtaVec;
   vector<double>  *selectedIDIsoElectronsNoMiniIsoPhiVec;
   UShort_t        selectedIDIsoElectronsNoMiniIsoNum;
   Float_t         selectedIDIsoElectronsNoMiniIsoE[4];   //[selectedIDIsoElectronsNoMiniIsoNum]
   Float_t         selectedIDIsoElectronsNoMiniIsoTLorentzVector[4];   //[selectedIDIsoElectronsNoMiniIsoNum]
   vector<double>  *JetsPtVec;
   vector<double>  *JetsEtaVec;
   vector<double>  *JetsPhiVec;
   UShort_t        JetsNum;
   Float_t         JetsE[17];   //[JetsNum]
   Float_t         JetsTLorentzVector[17];   //[JetsNum]
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
   vector<double>  *slimmedElectronsPtVec;
   vector<double>  *slimmedElectronsEtaVec;
   vector<double>  *slimmedElectronsPhiVec;
   UShort_t        slimmedElectronsNum;
   Float_t         slimmedElectronsE[14];   //[slimmedElectronsNum]
   Float_t         slimmedElectronsTLorentzVector[14];   //[slimmedElectronsNum]
   vector<double>  *slimmedMuonsPtVec;
   vector<double>  *slimmedMuonsEtaVec;
   vector<double>  *slimmedMuonsPhiVec;
   UShort_t        slimmedMuonsNum;
   Float_t         slimmedMuonsE[44];   //[slimmedMuonsNum]
   Float_t         slimmedMuonsTLorentzVector[44];   //[slimmedMuonsNum]
   vector<double>  *slimJetPtVec;
   vector<double>  *slimJetEtaVec;
   vector<double>  *slimJetPhiVec;
   UShort_t        slimJetNum;
   Float_t         slimJetE[82];   //[slimJetNum]
   Float_t         slimJetTLorentzVector[82];   //[slimJetNum]
   Int_t           slimJet_slimJetID[82];   //[slimJetNum]
   vector<double>  *GenTauNuPtVec;
   vector<double>  *GenTauNuEtaVec;
   vector<double>  *GenTauNuPhiVec;
   UShort_t        GenTauNuNum;
   Float_t         GenTauNuE[5];   //[GenTauNuNum]
   Float_t         GenTauNuTLorentzVector[5];   //[GenTauNuNum]
   Float_t         GenTauNu_TauNuMomPt[5];   //[GenTauNuNum]

      
      // List of branches
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
      TBranch        *b_MHTPhi;   //!
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
      TBranch        *b_testVec;   //!
      TBranch        *b_MuonsPtVec;   //!
      TBranch        *b_MuonsEtaVec;   //!
      TBranch        *b_MuonsPhiVec;   //!
      TBranch        *b_MuonsNum;   //!
      TBranch        *b_MuonsE;   //!
      TBranch        *b_MuonsTLorentzVector;   //!
      TBranch        *b_ElectronsPtVec;   //!
      TBranch        *b_ElectronsEtaVec;   //!
      TBranch        *b_ElectronsPhiVec;   //!
      TBranch        *b_ElectronsNum;   //!
      TBranch        *b_ElectronsE;   //!
      TBranch        *b_ElectronsTLorentzVector;   //!
      TBranch        *b_IsolatedTracksPtVec;   //!
      TBranch        *b_IsolatedTracksEtaVec;   //!
      TBranch        *b_IsolatedTracksPhiVec;   //!
      TBranch        *b_IsolatedTracksNum;   //!
      TBranch        *b_IsolatedTracksE;   //!
      TBranch        *b_IsolatedTracksTLorentzVector;   //!
      TBranch        *b_selectedIDIsoMuonsPtVec;   //!
      TBranch        *b_selectedIDIsoMuonsEtaVec;   //!
      TBranch        *b_selectedIDIsoMuonsPhiVec;   //!
      TBranch        *b_selectedIDIsoMuonsNum;   //!
      TBranch        *b_selectedIDIsoMuonsE;   //!
      TBranch        *b_selectedIDIsoMuonsTLorentzVector;   //!
      TBranch        *b_selectedIDMuonsPtVec;   //!
      TBranch        *b_selectedIDMuonsEtaVec;   //!
      TBranch        *b_selectedIDMuonsPhiVec;   //!
      TBranch        *b_selectedIDMuonsNum;   //!
      TBranch        *b_selectedIDMuonsE;   //!
      TBranch        *b_selectedIDMuonsTLorentzVector;   //!
      TBranch        *b_selectedIDIsoElectronsPtVec;   //!
      TBranch        *b_selectedIDIsoElectronsEtaVec;   //!
      TBranch        *b_selectedIDIsoElectronsPhiVec;   //!
      TBranch        *b_selectedIDIsoElectronsNum;   //!
      TBranch        *b_selectedIDIsoElectronsE;   //!
      TBranch        *b_selectedIDIsoElectronsTLorentzVector;   //!
      TBranch        *b_selectedIDElectronsPtVec;   //!
      TBranch        *b_selectedIDElectronsEtaVec;   //!
      TBranch        *b_selectedIDElectronsPhiVec;   //!
      TBranch        *b_selectedIDElectronsNum;   //!
      TBranch        *b_selectedIDElectronsE;   //!
      TBranch        *b_selectedIDElectronsTLorentzVector;   //!
      TBranch        *b_SelectedPFCandidatesPtVec;   //!
      TBranch        *b_SelectedPFCandidatesEtaVec;   //!
      TBranch        *b_SelectedPFCandidatesPhiVec;   //!
      TBranch        *b_SelectedPFCandidatesNum;   //!
      TBranch        *b_SelectedPFCandidatesE;   //!
      TBranch        *b_SelectedPFCandidatesTLorentzVector;   //!
      TBranch        *b_SelectedPFCandidates_Charge;   //!
      TBranch        *b_SelectedPFCandidates_Typ;   //!
      TBranch        *b_GenBosonPtVec;   //!
      TBranch        *b_GenBosonEtaVec;   //!
      TBranch        *b_GenBosonPhiVec;   //!
      TBranch        *b_GenBosonNum;   //!
      TBranch        *b_GenBosonE;   //!
      TBranch        *b_GenBosonTLorentzVector;   //!
      TBranch        *b_GenBoson_GenBosonPDGId;   //!
      TBranch        *b_GenMuPtVec;   //!
      TBranch        *b_GenMuEtaVec;   //!
      TBranch        *b_GenMuPhiVec;   //!
      TBranch        *b_GenMuNum;   //!
      TBranch        *b_GenMuE;   //!
      TBranch        *b_GenMuTLorentzVector;   //!
      TBranch        *b_GenMu_GenMuFromTau;   //!
      TBranch        *b_GenElecPtVec;   //!
      TBranch        *b_GenElecEtaVec;   //!
      TBranch        *b_GenElecPhiVec;   //!
      TBranch        *b_GenElecNum;   //!
      TBranch        *b_GenElecE;   //!
      TBranch        *b_GenElecTLorentzVector;   //!
      TBranch        *b_GenElec_GenElecFromTau;   //!
      TBranch        *b_GenTauPtVec;   //!
      TBranch        *b_GenTauEtaVec;   //!
      TBranch        *b_GenTauPhiVec;   //!
      TBranch        *b_GenTauNum;   //!
      TBranch        *b_GenTauE;   //!
      TBranch        *b_GenTauTLorentzVector;   //!
      TBranch        *b_GenTau_GenTauHad;   //!
      TBranch        *b_selectedIDIsoMuonsNoMiniIsoPtVec;   //!
      TBranch        *b_selectedIDIsoMuonsNoMiniIsoEtaVec;   //!
      TBranch        *b_selectedIDIsoMuonsNoMiniIsoPhiVec;   //!
      TBranch        *b_selectedIDIsoMuonsNoMiniIsoNum;   //!
      TBranch        *b_selectedIDIsoMuonsNoMiniIsoE;   //!
      TBranch        *b_selectedIDIsoMuonsNoMiniIsoTLorentzVector;   //!
      TBranch        *b_selectedIDIsoElectronsNoMiniIsoPtVec;   //!
      TBranch        *b_selectedIDIsoElectronsNoMiniIsoEtaVec;   //!
      TBranch        *b_selectedIDIsoElectronsNoMiniIsoPhiVec;   //!
      TBranch        *b_selectedIDIsoElectronsNoMiniIsoNum;   //!
      TBranch        *b_selectedIDIsoElectronsNoMiniIsoE;   //!
      TBranch        *b_selectedIDIsoElectronsNoMiniIsoTLorentzVector;   //!
      TBranch        *b_JetsPtVec;   //!
      TBranch        *b_JetsEtaVec;   //!
      TBranch        *b_JetsPhiVec;   //!
      TBranch        *b_JetsNum;   //!
      TBranch        *b_JetsE;   //!
      TBranch        *b_JetsTLorentzVector;   //!
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
      TBranch        *b_slimmedElectronsPtVec;   //!
      TBranch        *b_slimmedElectronsEtaVec;   //!
      TBranch        *b_slimmedElectronsPhiVec;   //!
      TBranch        *b_slimmedElectronsNum;   //!
      TBranch        *b_slimmedElectronsE;   //!
      TBranch        *b_slimmedElectronsTLorentzVector;   //!
      TBranch        *b_slimmedMuonsPtVec;   //!
      TBranch        *b_slimmedMuonsEtaVec;   //!
      TBranch        *b_slimmedMuonsPhiVec;   //!
      TBranch        *b_slimmedMuonsNum;   //!
      TBranch        *b_slimmedMuonsE;   //!
      TBranch        *b_slimmedMuonsTLorentzVector;   //!
      TBranch        *b_slimJetPtVec;   //!
      TBranch        *b_slimJetEtaVec;   //!
      TBranch        *b_slimJetPhiVec;   //!
      TBranch        *b_slimJetNum;   //!
      TBranch        *b_slimJetE;   //!
      TBranch        *b_slimJetTLorentzVector;   //!
      TBranch        *b_slimJet_slimJetID;   //!
      TBranch        *b_GenTauNuPtVec;   //!
      TBranch        *b_GenTauNuEtaVec;   //!
      TBranch        *b_GenTauNuPhiVec;   //!
      TBranch        *b_GenTauNuNum;   //!
      TBranch        *b_GenTauNuE;   //!
      TBranch        *b_GenTauNuTLorentzVector;   //!
      TBranch        *b_GenTauNu_TauNuMomPt;   //!      /*
   
      

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
  bool loadNext(int start);
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
  void setStart(int start);
  double MinDeltaPhiN() const ;
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
  bool Baseline();
  bool BaselineMu();
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

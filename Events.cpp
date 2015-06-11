#include "Events.h"
#include <vector>
#include "TMath.h"

  //Constructor
  Events::Events(TTree * ttree_) : currentEntry_(-1) {

     


     fChain = ttree_;
    
    /// the variables
      testVec = 0;
      MuonsPtVec = 0;
      MuonsEtaVec = 0;
      MuonsPhiVec = 0;
      ElectronsPtVec = 0;
      ElectronsEtaVec = 0;
      ElectronsPhiVec = 0;
      IsolatedTracksPtVec = 0;
      IsolatedTracksEtaVec = 0;
      IsolatedTracksPhiVec = 0;
      selectedIDIsoMuonsPtVec = 0;
      selectedIDIsoMuonsEtaVec = 0;
      selectedIDIsoMuonsPhiVec = 0;
      selectedIDMuonsPtVec = 0;
      selectedIDMuonsEtaVec = 0;
      selectedIDMuonsPhiVec = 0;
      selectedIDIsoElectronsPtVec = 0;
      selectedIDIsoElectronsEtaVec = 0;
      selectedIDIsoElectronsPhiVec = 0;
      selectedIDElectronsPtVec = 0;
      selectedIDElectronsEtaVec = 0;
      selectedIDElectronsPhiVec = 0;
      SelectedPFCandidatesPtVec = 0;
      SelectedPFCandidatesEtaVec = 0;
      SelectedPFCandidatesPhiVec = 0;
      GenBosonPtVec = 0;
      GenBosonEtaVec = 0;
      GenBosonPhiVec = 0;
      GenMuPtVec = 0;
      GenMuEtaVec = 0;
      GenMuPhiVec = 0;
      GenElecPtVec = 0;
      GenElecEtaVec = 0;
      GenElecPhiVec = 0;
      GenTauPtVec = 0;
      GenTauEtaVec = 0;
      GenTauPhiVec = 0;
      selectedIDIsoMuonsNoMiniIsoPtVec = 0;
      selectedIDIsoMuonsNoMiniIsoEtaVec = 0;
      selectedIDIsoMuonsNoMiniIsoPhiVec = 0;
      selectedIDIsoElectronsNoMiniIsoPtVec = 0;
      selectedIDIsoElectronsNoMiniIsoEtaVec = 0;
      selectedIDIsoElectronsNoMiniIsoPhiVec = 0;
      JetsPtVec = 0;
      JetsEtaVec = 0;
      JetsPhiVec = 0;
      slimmedElectronsPtVec = 0;
      slimmedElectronsEtaVec = 0;
      slimmedElectronsPhiVec = 0;
      slimmedMuonsPtVec = 0;
      slimmedMuonsEtaVec = 0;
      slimmedMuonsPhiVec = 0;
      slimJetPtVec = 0;
      slimJetEtaVec = 0;
      slimJetPhiVec = 0;
      GenTauNuPtVec = 0;
      GenTauNuEtaVec = 0;
      GenTauNuPhiVec = 0;

      
      fChain->SetBranchAddress("RunNum", &RunNum, &b_RunNum);
      fChain->SetBranchAddress("LumiBlockNum", &LumiBlockNum, &b_LumiBlockNum);
      fChain->SetBranchAddress("EvtNum", &EvtNum, &b_EvtNum);
      fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
      fChain->SetBranchAddress("isoElectronTracks", &isoElectronTracks, &b_isoElectronTracks);
      fChain->SetBranchAddress("isoMuonTracks", &isoMuonTracks, &b_isoMuonTracks);
      fChain->SetBranchAddress("isoPionTracks", &isoPionTracks, &b_isoPionTracks);
      fChain->SetBranchAddress("Leptons", &Leptons, &b_Leptons);
      fChain->SetBranchAddress("LeptonsNoMiniIsolation", &LeptonsNoMiniIsolation, &b_LeptonsNoMiniIsolation);
      fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
      fChain->SetBranchAddress("BTags", &BTags, &b_BTags);
      fChain->SetBranchAddress("Weight", &Weight, &b_Weight);
      fChain->SetBranchAddress("HT", &HT, &b_HT);
      fChain->SetBranchAddress("MHTPhi", &MHTPhi, &b_MHTPhi);
      fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
      fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
      fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
      fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
      fChain->SetBranchAddress("minDeltaPhiN", &minDeltaPhiN, &b_minDeltaPhiN);
      fChain->SetBranchAddress("DeltaPhiN1", &DeltaPhiN1, &b_DeltaPhiN1);
      fChain->SetBranchAddress("DeltaPhiN2", &DeltaPhiN2, &b_DeltaPhiN2);
      fChain->SetBranchAddress("DeltaPhiN3", &DeltaPhiN3, &b_DeltaPhiN3);
      fChain->SetBranchAddress("METPt", &METPt, &b_METPt);
      fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
      fChain->SetBranchAddress("JetID", &JetID, &b_JetID);
      fChain->SetBranchAddress("testVec", &testVec, &b_testVec);
      fChain->SetBranchAddress("MuonsPtVec", &MuonsPtVec, &b_MuonsPtVec);
      fChain->SetBranchAddress("MuonsEtaVec", &MuonsEtaVec, &b_MuonsEtaVec);
      fChain->SetBranchAddress("MuonsPhiVec", &MuonsPhiVec, &b_MuonsPhiVec);
      fChain->SetBranchAddress("MuonsNum", &MuonsNum, &b_MuonsNum);
      fChain->SetBranchAddress("MuonsE", MuonsE, &b_MuonsE);
      fChain->SetBranchAddress("MuonsTLorentzVector", MuonsTLorentzVector, &b_MuonsTLorentzVector);
      fChain->SetBranchAddress("ElectronsPtVec", &ElectronsPtVec, &b_ElectronsPtVec);
      fChain->SetBranchAddress("ElectronsEtaVec", &ElectronsEtaVec, &b_ElectronsEtaVec);
      fChain->SetBranchAddress("ElectronsPhiVec", &ElectronsPhiVec, &b_ElectronsPhiVec);
      fChain->SetBranchAddress("ElectronsNum", &ElectronsNum, &b_ElectronsNum);
      fChain->SetBranchAddress("ElectronsE", ElectronsE, &b_ElectronsE);
      fChain->SetBranchAddress("ElectronsTLorentzVector", ElectronsTLorentzVector, &b_ElectronsTLorentzVector);
      fChain->SetBranchAddress("IsolatedTracksPtVec", &IsolatedTracksPtVec, &b_IsolatedTracksPtVec);
      fChain->SetBranchAddress("IsolatedTracksEtaVec", &IsolatedTracksEtaVec, &b_IsolatedTracksEtaVec);
      fChain->SetBranchAddress("IsolatedTracksPhiVec", &IsolatedTracksPhiVec, &b_IsolatedTracksPhiVec);
      fChain->SetBranchAddress("IsolatedTracksNum", &IsolatedTracksNum, &b_IsolatedTracksNum);
      fChain->SetBranchAddress("IsolatedTracksE", &IsolatedTracksE, &b_IsolatedTracksE);
      fChain->SetBranchAddress("IsolatedTracksTLorentzVector", &IsolatedTracksTLorentzVector, &b_IsolatedTracksTLorentzVector);
      fChain->SetBranchAddress("selectedIDIsoMuonsPtVec", &selectedIDIsoMuonsPtVec, &b_selectedIDIsoMuonsPtVec);
      fChain->SetBranchAddress("selectedIDIsoMuonsEtaVec", &selectedIDIsoMuonsEtaVec, &b_selectedIDIsoMuonsEtaVec);
      fChain->SetBranchAddress("selectedIDIsoMuonsPhiVec", &selectedIDIsoMuonsPhiVec, &b_selectedIDIsoMuonsPhiVec);
      fChain->SetBranchAddress("selectedIDIsoMuonsNum", &selectedIDIsoMuonsNum, &b_selectedIDIsoMuonsNum);
      fChain->SetBranchAddress("selectedIDIsoMuonsE", selectedIDIsoMuonsE, &b_selectedIDIsoMuonsE);
      fChain->SetBranchAddress("selectedIDIsoMuonsTLorentzVector", selectedIDIsoMuonsTLorentzVector, &b_selectedIDIsoMuonsTLorentzVector);
      fChain->SetBranchAddress("selectedIDMuonsPtVec", &selectedIDMuonsPtVec, &b_selectedIDMuonsPtVec);
      fChain->SetBranchAddress("selectedIDMuonsEtaVec", &selectedIDMuonsEtaVec, &b_selectedIDMuonsEtaVec);
      fChain->SetBranchAddress("selectedIDMuonsPhiVec", &selectedIDMuonsPhiVec, &b_selectedIDMuonsPhiVec);
      fChain->SetBranchAddress("selectedIDMuonsNum", &selectedIDMuonsNum, &b_selectedIDMuonsNum);
      fChain->SetBranchAddress("selectedIDMuonsE", selectedIDMuonsE, &b_selectedIDMuonsE);
      fChain->SetBranchAddress("selectedIDMuonsTLorentzVector", selectedIDMuonsTLorentzVector, &b_selectedIDMuonsTLorentzVector);
      fChain->SetBranchAddress("selectedIDIsoElectronsPtVec", &selectedIDIsoElectronsPtVec, &b_selectedIDIsoElectronsPtVec);
      fChain->SetBranchAddress("selectedIDIsoElectronsEtaVec", &selectedIDIsoElectronsEtaVec, &b_selectedIDIsoElectronsEtaVec);
      fChain->SetBranchAddress("selectedIDIsoElectronsPhiVec", &selectedIDIsoElectronsPhiVec, &b_selectedIDIsoElectronsPhiVec);
      fChain->SetBranchAddress("selectedIDIsoElectronsNum", &selectedIDIsoElectronsNum, &b_selectedIDIsoElectronsNum);
      fChain->SetBranchAddress("selectedIDIsoElectronsE", selectedIDIsoElectronsE, &b_selectedIDIsoElectronsE);
      fChain->SetBranchAddress("selectedIDIsoElectronsTLorentzVector", selectedIDIsoElectronsTLorentzVector, &b_selectedIDIsoElectronsTLorentzVector);
      fChain->SetBranchAddress("selectedIDElectronsPtVec", &selectedIDElectronsPtVec, &b_selectedIDElectronsPtVec);
      fChain->SetBranchAddress("selectedIDElectronsEtaVec", &selectedIDElectronsEtaVec, &b_selectedIDElectronsEtaVec);
      fChain->SetBranchAddress("selectedIDElectronsPhiVec", &selectedIDElectronsPhiVec, &b_selectedIDElectronsPhiVec);
      fChain->SetBranchAddress("selectedIDElectronsNum", &selectedIDElectronsNum, &b_selectedIDElectronsNum);
      fChain->SetBranchAddress("selectedIDElectronsE", selectedIDElectronsE, &b_selectedIDElectronsE);
      fChain->SetBranchAddress("selectedIDElectronsTLorentzVector", selectedIDElectronsTLorentzVector, &b_selectedIDElectronsTLorentzVector);
      fChain->SetBranchAddress("SelectedPFCandidatesPtVec", &SelectedPFCandidatesPtVec, &b_SelectedPFCandidatesPtVec);
      fChain->SetBranchAddress("SelectedPFCandidatesEtaVec", &SelectedPFCandidatesEtaVec, &b_SelectedPFCandidatesEtaVec);
      fChain->SetBranchAddress("SelectedPFCandidatesPhiVec", &SelectedPFCandidatesPhiVec, &b_SelectedPFCandidatesPhiVec);
      fChain->SetBranchAddress("SelectedPFCandidatesNum", &SelectedPFCandidatesNum, &b_SelectedPFCandidatesNum);
      fChain->SetBranchAddress("SelectedPFCandidatesE", SelectedPFCandidatesE, &b_SelectedPFCandidatesE);
      fChain->SetBranchAddress("SelectedPFCandidatesTLorentzVector", SelectedPFCandidatesTLorentzVector, &b_SelectedPFCandidatesTLorentzVector);
      fChain->SetBranchAddress("SelectedPFCandidates_Charge", SelectedPFCandidates_Charge, &b_SelectedPFCandidates_Charge);
      fChain->SetBranchAddress("SelectedPFCandidates_Typ", SelectedPFCandidates_Typ, &b_SelectedPFCandidates_Typ);
      fChain->SetBranchAddress("GenBosonPtVec", &GenBosonPtVec, &b_GenBosonPtVec);
      fChain->SetBranchAddress("GenBosonEtaVec", &GenBosonEtaVec, &b_GenBosonEtaVec);
      fChain->SetBranchAddress("GenBosonPhiVec", &GenBosonPhiVec, &b_GenBosonPhiVec);
      fChain->SetBranchAddress("GenBosonNum", &GenBosonNum, &b_GenBosonNum);
      fChain->SetBranchAddress("GenBosonE", GenBosonE, &b_GenBosonE);
      fChain->SetBranchAddress("GenBosonTLorentzVector", GenBosonTLorentzVector, &b_GenBosonTLorentzVector);
      fChain->SetBranchAddress("GenBoson_GenBosonPDGId", GenBoson_GenBosonPDGId, &b_GenBoson_GenBosonPDGId);
      fChain->SetBranchAddress("GenMuPtVec", &GenMuPtVec, &b_GenMuPtVec);
      fChain->SetBranchAddress("GenMuEtaVec", &GenMuEtaVec, &b_GenMuEtaVec);
      fChain->SetBranchAddress("GenMuPhiVec", &GenMuPhiVec, &b_GenMuPhiVec);
      fChain->SetBranchAddress("GenMuNum", &GenMuNum, &b_GenMuNum);
      fChain->SetBranchAddress("GenMuE", GenMuE, &b_GenMuE);
      fChain->SetBranchAddress("GenMuTLorentzVector", GenMuTLorentzVector, &b_GenMuTLorentzVector);
      fChain->SetBranchAddress("GenMu_GenMuFromTau", GenMu_GenMuFromTau, &b_GenMu_GenMuFromTau);
      fChain->SetBranchAddress("GenElecPtVec", &GenElecPtVec, &b_GenElecPtVec);
      fChain->SetBranchAddress("GenElecEtaVec", &GenElecEtaVec, &b_GenElecEtaVec);
      fChain->SetBranchAddress("GenElecPhiVec", &GenElecPhiVec, &b_GenElecPhiVec);
      fChain->SetBranchAddress("GenElecNum", &GenElecNum, &b_GenElecNum);
      fChain->SetBranchAddress("GenElecE", GenElecE, &b_GenElecE);
      fChain->SetBranchAddress("GenElecTLorentzVector", GenElecTLorentzVector, &b_GenElecTLorentzVector);
      fChain->SetBranchAddress("GenElec_GenElecFromTau", GenElec_GenElecFromTau, &b_GenElec_GenElecFromTau);
      fChain->SetBranchAddress("GenTauPtVec", &GenTauPtVec, &b_GenTauPtVec);
      fChain->SetBranchAddress("GenTauEtaVec", &GenTauEtaVec, &b_GenTauEtaVec);
      fChain->SetBranchAddress("GenTauPhiVec", &GenTauPhiVec, &b_GenTauPhiVec);
      fChain->SetBranchAddress("GenTauNum", &GenTauNum, &b_GenTauNum);
      fChain->SetBranchAddress("GenTauE", GenTauE, &b_GenTauE);
      fChain->SetBranchAddress("GenTauTLorentzVector", GenTauTLorentzVector, &b_GenTauTLorentzVector);
      fChain->SetBranchAddress("GenTau_GenTauHad", GenTau_GenTauHad, &b_GenTau_GenTauHad);
      fChain->SetBranchAddress("selectedIDIsoMuonsNoMiniIsoPtVec", &selectedIDIsoMuonsNoMiniIsoPtVec, &b_selectedIDIsoMuonsNoMiniIsoPtVec);
      fChain->SetBranchAddress("selectedIDIsoMuonsNoMiniIsoEtaVec", &selectedIDIsoMuonsNoMiniIsoEtaVec, &b_selectedIDIsoMuonsNoMiniIsoEtaVec);
      fChain->SetBranchAddress("selectedIDIsoMuonsNoMiniIsoPhiVec", &selectedIDIsoMuonsNoMiniIsoPhiVec, &b_selectedIDIsoMuonsNoMiniIsoPhiVec);
      fChain->SetBranchAddress("selectedIDIsoMuonsNoMiniIsoNum", &selectedIDIsoMuonsNoMiniIsoNum, &b_selectedIDIsoMuonsNoMiniIsoNum);
      fChain->SetBranchAddress("selectedIDIsoMuonsNoMiniIsoE", selectedIDIsoMuonsNoMiniIsoE, &b_selectedIDIsoMuonsNoMiniIsoE);
      fChain->SetBranchAddress("selectedIDIsoMuonsNoMiniIsoTLorentzVector", selectedIDIsoMuonsNoMiniIsoTLorentzVector, &b_selectedIDIsoMuonsNoMiniIsoTLorentzVector);
      fChain->SetBranchAddress("selectedIDIsoElectronsNoMiniIsoPtVec", &selectedIDIsoElectronsNoMiniIsoPtVec, &b_selectedIDIsoElectronsNoMiniIsoPtVec);
      fChain->SetBranchAddress("selectedIDIsoElectronsNoMiniIsoEtaVec", &selectedIDIsoElectronsNoMiniIsoEtaVec, &b_selectedIDIsoElectronsNoMiniIsoEtaVec);
      fChain->SetBranchAddress("selectedIDIsoElectronsNoMiniIsoPhiVec", &selectedIDIsoElectronsNoMiniIsoPhiVec, &b_selectedIDIsoElectronsNoMiniIsoPhiVec);
      fChain->SetBranchAddress("selectedIDIsoElectronsNoMiniIsoNum", &selectedIDIsoElectronsNoMiniIsoNum, &b_selectedIDIsoElectronsNoMiniIsoNum);
      fChain->SetBranchAddress("selectedIDIsoElectronsNoMiniIsoE", selectedIDIsoElectronsNoMiniIsoE, &b_selectedIDIsoElectronsNoMiniIsoE);
      fChain->SetBranchAddress("selectedIDIsoElectronsNoMiniIsoTLorentzVector", selectedIDIsoElectronsNoMiniIsoTLorentzVector, &b_selectedIDIsoElectronsNoMiniIsoTLorentzVector);
      fChain->SetBranchAddress("JetsPtVec", &JetsPtVec, &b_JetsPtVec);
      fChain->SetBranchAddress("JetsEtaVec", &JetsEtaVec, &b_JetsEtaVec);
      fChain->SetBranchAddress("JetsPhiVec", &JetsPhiVec, &b_JetsPhiVec);
      fChain->SetBranchAddress("JetsNum", &JetsNum, &b_JetsNum);
      fChain->SetBranchAddress("JetsE", JetsE, &b_JetsE);
      fChain->SetBranchAddress("JetsTLorentzVector", JetsTLorentzVector, &b_JetsTLorentzVector);
      fChain->SetBranchAddress("Jets_bDiscriminator", Jets_bDiscriminator, &b_Jets_bDiscriminator);
      fChain->SetBranchAddress("Jets_chargedEmEnergyFraction", Jets_chargedEmEnergyFraction, &b_Jets_chargedEmEnergyFraction);
      fChain->SetBranchAddress("Jets_chargedHadronEnergyFraction", Jets_chargedHadronEnergyFraction, &b_Jets_chargedHadronEnergyFraction);
      fChain->SetBranchAddress("Jets_chargedHadronMultiplicity", Jets_chargedHadronMultiplicity, &b_Jets_chargedHadronMultiplicity);
      fChain->SetBranchAddress("Jets_electronMultiplicity", Jets_electronMultiplicity, &b_Jets_electronMultiplicity);
      fChain->SetBranchAddress("Jets_jetArea", Jets_jetArea, &b_Jets_jetArea);
      fChain->SetBranchAddress("Jets_muonEnergyFraction", Jets_muonEnergyFraction, &b_Jets_muonEnergyFraction);
      fChain->SetBranchAddress("Jets_muonMultiplicity", Jets_muonMultiplicity, &b_Jets_muonMultiplicity);
      fChain->SetBranchAddress("Jets_neutralEmEnergyFraction", Jets_neutralEmEnergyFraction, &b_Jets_neutralEmEnergyFraction);
      fChain->SetBranchAddress("Jets_neutralHadronMultiplicity", Jets_neutralHadronMultiplicity, &b_Jets_neutralHadronMultiplicity);
      fChain->SetBranchAddress("Jets_photonEnergyFraction", Jets_photonEnergyFraction, &b_Jets_photonEnergyFraction);
      fChain->SetBranchAddress("Jets_photonMultiplicity", Jets_photonMultiplicity, &b_Jets_photonMultiplicity);
      fChain->SetBranchAddress("slimmedElectronsPtVec", &slimmedElectronsPtVec, &b_slimmedElectronsPtVec);
      fChain->SetBranchAddress("slimmedElectronsEtaVec", &slimmedElectronsEtaVec, &b_slimmedElectronsEtaVec);
      fChain->SetBranchAddress("slimmedElectronsPhiVec", &slimmedElectronsPhiVec, &b_slimmedElectronsPhiVec);
      fChain->SetBranchAddress("slimmedElectronsNum", &slimmedElectronsNum, &b_slimmedElectronsNum);
      fChain->SetBranchAddress("slimmedElectronsE", slimmedElectronsE, &b_slimmedElectronsE);
      fChain->SetBranchAddress("slimmedElectronsTLorentzVector", slimmedElectronsTLorentzVector, &b_slimmedElectronsTLorentzVector);
      fChain->SetBranchAddress("slimmedMuonsPtVec", &slimmedMuonsPtVec, &b_slimmedMuonsPtVec);
      fChain->SetBranchAddress("slimmedMuonsEtaVec", &slimmedMuonsEtaVec, &b_slimmedMuonsEtaVec);
      fChain->SetBranchAddress("slimmedMuonsPhiVec", &slimmedMuonsPhiVec, &b_slimmedMuonsPhiVec);
      fChain->SetBranchAddress("slimmedMuonsNum", &slimmedMuonsNum, &b_slimmedMuonsNum);
      fChain->SetBranchAddress("slimmedMuonsE", slimmedMuonsE, &b_slimmedMuonsE);
      fChain->SetBranchAddress("slimmedMuonsTLorentzVector", slimmedMuonsTLorentzVector, &b_slimmedMuonsTLorentzVector);
      fChain->SetBranchAddress("slimJetPtVec", &slimJetPtVec, &b_slimJetPtVec);
      fChain->SetBranchAddress("slimJetEtaVec", &slimJetEtaVec, &b_slimJetEtaVec);
      fChain->SetBranchAddress("slimJetPhiVec", &slimJetPhiVec, &b_slimJetPhiVec);
      fChain->SetBranchAddress("slimJetNum", &slimJetNum, &b_slimJetNum);
      fChain->SetBranchAddress("slimJetE", slimJetE, &b_slimJetE);
      fChain->SetBranchAddress("slimJetTLorentzVector", slimJetTLorentzVector, &b_slimJetTLorentzVector);
      fChain->SetBranchAddress("slimJet_slimJetID", slimJet_slimJetID, &b_slimJet_slimJetID);
      fChain->SetBranchAddress("GenTauNuPtVec", &GenTauNuPtVec, &b_GenTauNuPtVec);
      fChain->SetBranchAddress("GenTauNuEtaVec", &GenTauNuEtaVec, &b_GenTauNuEtaVec);
      fChain->SetBranchAddress("GenTauNuPhiVec", &GenTauNuPhiVec, &b_GenTauNuPhiVec);
      fChain->SetBranchAddress("GenTauNuNum", &GenTauNuNum, &b_GenTauNuNum);
      fChain->SetBranchAddress("GenTauNuE", GenTauNuE, &b_GenTauNuE);
      fChain->SetBranchAddress("GenTauNuTLorentzVector", GenTauNuTLorentzVector, &b_GenTauNuTLorentzVector);
      fChain->SetBranchAddress("GenTauNu_TauNuMomPt", GenTauNu_TauNuMomPt, &b_GenTauNu_TauNuMomPt);


    // Number of total entries

    template_Entries = fChain->GetEntries();
    TFile*f1=new TFile("HadTau_TauResponseTemplates_TTbar_.root");
      templatesToRead[0]=(TH1F*)f1->Get("hTauResp_0");
       templatesToRead[1]=(TH1F*)f1->Get("hTauResp_1");
       templatesToRead[2]=(TH1F*)f1->Get("hTauResp_2");
       templatesToRead[3]=(TH1F*)f1->Get("hTauResp_3");
      
      TFile*f2=new TFile("TauBTagEff.root");
      TauBEff=(TH1F*)f2->Get("GenTauPtB");
     // f1->Close();

  }//end of class constructor Event


  // A function to make events available
void Events::setStart(int start){
currentEntry_=start;

}
  bool Events::loadNext(int start) {
    if( currentEntry_ < 0 ) {
      std::cout << "Processing " << template_Entries << " events" << std::endl;
    }

    ++currentEntry_;

    if( currentEntry_ == template_Entries ) {

      return false;

    } else {

      if( currentEntry_ > 0 && currentEntry_%100000 == 0 ) {
        std::cout << " Processed " << currentEntry_ << " events" << std::endl;
      }

   	  //currentEntry_=start; 
          fChain->GetEntry(currentEntry_);
          return true;
   

    }

  }


// Some Functions

  // Event weight (for luminosity and PU profile)
  double Events::weight() const { return Weight; }

  // HT and MHT
  double Events::ht() const { return HT; }
  double Events::mht() const { return MHT; }
  double Events::mhtphi() const { return MHTPhi; }
double Events::MinDeltaPhiN()const{return minDeltaPhiN;}
  // MET


  // Number of HT jets
  int Events::nJets() const { return NJets; }
  int Events::nEle() const { return ElectronsNum; }

  // Number of B jets
  int Events::nBtags() const { return BTags; }
int Events::nGenMu()const {return GenMuNum;}

  int Events::nIsoElec() const { return isoElectronTracks; }
  int Events::nIsoMu() const { return isoMuonTracks; }
  int Events::nIsoPion() const { return isoPionTracks; }

  // DeltaPhi between leading three MHT jets and MHT
  // To see if an event passes the jetId requirement or not.
  int Events::JetId() const {

    return JetID;
  }
   vector<TLorentzVector>  Events::GenMu_(){
       GenMu.resize(0);
       for(int m=0; m<GenMuNum; m++){
           if(GenMu_GenMuFromTau[m]!=0)continue;
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE((*GenMuPtVec)[m],(*GenMuEtaVec)[m],(*GenMuPhiVec)[m],GenMuE[m]);
           GenMu.push_back(tmp);
       }
       
       return GenMu;

   }
   vector<TLorentzVector>  Events::GenTau_(){
       GenTau.resize(0);
       for(int t=0; t<GenTauNum; t++){
           if((*GenTauPtVec)[t]<20 || fabs((*GenTauEtaVec)[t])>2.1 )continue;
           if(GenTau_GenTauHad[t]!=1)continue;
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE((*GenTauPtVec)[t],(*GenTauEtaVec)[t],(*GenTauPhiVec)[t],GenTauE[t]);
           GenTau.push_back(tmp);
       }
       return GenTau;
   
   }
   vector<TLorentzVector>  Events::GoodJets_(){
       GoodJets.resize(0);
       MatchedJetB.resize(0);

       for(int j=0; j<JetsNum; ++j){
           //if(allJet_allJetID[j]!=1)continue;
           
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE((*JetsPtVec)[j],(*JetsEtaVec)[j],(*JetsPhiVec)[j],JetsE[j]);

           GoodJets.push_back(tmp);
           MatchedJetB.push_back(Jets_bDiscriminator[j]);
       }
       return GoodJets;
   }
   vector<TLorentzVector>  Events::AllJets_(){
       allJets.resize(0);
       for(int j=0; j<JetsNum; ++j){
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE((*JetsPtVec)[j],(*JetsEtaVec)[j],(*JetsPhiVec)[j],JetsE[j]);
           allJets.push_back(tmp);
       }
       return allJets;
   }
   vector<TLorentzVector>  Events::SelMu_(){
       SelMuons.resize(0);

       
       for(int m=0; m<MuonsNum; m++){
           
           if((*MuonsPtVec)[m]<20 || fabs((*MuonsEtaVec)[m])>2.1 )continue;
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE((*MuonsPtVec)[m],(*MuonsEtaVec)[m],(*MuonsPhiVec)[m],MuonsE[m]);
           SelMuons.push_back(tmp);
       }
       return SelMuons;
   }
  vector<TLorentzVector>  Events::MuMatchedJet_(){
      MatchedJet.resize(0);
      std::vector<float>tmp=MatchedJetB;
      MatchedJetB.resize(0);
      for(int i=0; i<GoodJets.size(); ++i){
          bool match=false;
          
          for(int m=0; m<SelMuons.size(); ++m){
              //std::cout<<"in loop "<<std::endl;

           float deta=GoodJets[i].Eta()-SelMuons[m].Eta();
           float dphi=GoodJets[i].Phi()-SelMuons[m].Phi();
           float dR=sqrt((deta*deta)+(dphi*dphi));
              if(dR<0.4)match=true;
              
        }
          if(match)MatchedJet.push_back(GoodJets[i]);
          if(match)MatchedJetB.push_back(tmp[i]);
       }
      
      
      return MatchedJet;
  }
vector<float>Events::MatchJetsBtagged_(){return MatchedJetB;}

vector<float> Events::TempResponsePt(float muPt){
    TH1F*response;
    SmearedMuonPt.resize(0);
    if(muPt>20 && muPt<30)response=templatesToRead[0];
    if(muPt>30 && muPt<50)response=templatesToRead[1];
    if(muPt>50 && muPt<100)response=templatesToRead[2];
    if( muPt>=100)response=templatesToRead[3];
    for(int i=1; i<=50; ++i){
        SmearedMuonPt.push_back(muPt*response->GetBinCenter(i));
    }
    return SmearedMuonPt;
}

vector<float> Events::TempResponseWeight(float muPt){
    TH1F*response;
    SmearedMuonWeight.resize(0);
    if(muPt>20 && muPt<30)response=templatesToRead[0];
    if(muPt>30 && muPt<50)response=templatesToRead[1];
    if(muPt>50 && muPt<100)response=templatesToRead[2];
    if( muPt>=100)response=templatesToRead[3];
    for(int i=1; i<=50; ++i){
        SmearedMuonWeight.push_back(response->GetBinContent(i));
    }
    return SmearedMuonWeight;
}

float Events::TempResponsePtRandom(float muPt){
    TH1F*response;
    SmearedMuonPt.resize(0);
    if(muPt>20 && muPt<30)response=templatesToRead[0];
    if(muPt>30 && muPt<50)response=templatesToRead[1];
    if(muPt>50 && muPt<100)response=templatesToRead[2];
    if( muPt>=100)response=templatesToRead[3];
    //for(int i=0; i<50; ++i){
    float smear=response->GetRandom();
    float SmearedMuonPt=muPt*smear;
    //}
    return SmearedMuonPt;
}
float Events::dTheta(TLorentzVector& muJet, int gjetindex){
    float sum=0;
    float deltaT=0;
    float jres=0.1;
     for(int j=0; j<GoodJets.size(); ++j){
         if(GoodJets[j].Pt()<30 || fabs(GoodJets[j].Eta())>2.4)continue;
         if(j==gjetindex)continue;
         float deta=muJet.Eta()-GoodJets[j].Eta();
         float dphi=muJet.Phi()-GoodJets[j].Phi();
         float dR=sqrt((deta*deta)+(dphi*dphi));
         //skip over the jet that matches the muon
         if(dR<0.4)continue;
         float add=(GoodJets[gjetindex].Px()*GoodJets[j].Py()-GoodJets[j].Px()*GoodJets[gjetindex].Py());
         add=(add*add);
         sum=sum+add;
         
     }
    if(muJet.Pt()>30 && fabs(muJet.Eta())>2.4){
        
         float add=(GoodJets[gjetindex].Px()*muJet.Py()-muJet.Px()*GoodJets[gjetindex].Py());
        sum=sum+add;
    }
     deltaT=jres*sqrt(sum)/GoodJets[gjetindex].Pt();
    return deltaT;
}

float Events::dphiN(TLorentzVector& muJet,TLorentzVector& MHTVec )
{
    float dphi=0;
    int jetcount=0;
    double pi=TMath::Pi();
    double dpnhat[3];
    for(int i=0; i<3; ++i)dpnhat[i]=999;
    std::vector<TLorentzVector>GoodJets=GoodJets_();
    for(int j=0; j<GoodJets.size(); ++j){
        if(GoodJets[j].Pt()<30 || fabs(GoodJets[j].Eta())>2.4)continue;
        float deta=muJet.Eta()-GoodJets[j].Eta();
        float dphi=muJet.Phi()-GoodJets[j].Phi();
        float dR=sqrt((deta*deta)+(dphi*dphi));
        if(jetcount>2)continue;
        //skip over the jet that matches the muon
        if(dR<0.4 && muJet.Pt()>30 && fabs(muJet.Eta())<2.4){
            float dp=acos(cos(GoodJets[j].Phi()-MHTVec.Phi()));
            float dT=dTheta(muJet, j);
            if(dT/MHTVec.Pt()>=1.0)dpnhat[jetcount]=dp/(pi/2.0);
            else dpnhat[jetcount]=dp/asin(dT/MHTVec.Phi());
            ++jetcount;
            continue;
        }
        if(dR<0.4 && (muJet.Pt()<30 || fabs(muJet.Eta())>2.4)){
            continue;
        }
        
        float dp=acos(cos(GoodJets[j].Phi()-MHTVec.Phi()));
        float dT=dTheta(muJet,j);
        if(dT/MHTVec.Pt()>=1.0)dpnhat[jetcount]=dp/(pi/2.0);
        else dpnhat[jetcount]=dp/asin(dT/MHTVec.Phi());
        ++jetcount;
    }
    dphi=9999;
    //std::cout<<"Good Jets size "<<GoodJets.size()<<std::endl;
    for(int i=0; i<3;++i){
        if(fabs(dpnhat[i])<dphi)dphi=dpnhat[i];//std::cout<<dpnhat[i]<<std::endl;;//get min
    }
    
    
    return dphi;
}
/*
vector<TLorentzVector>Events::MatchTauJets_(){
    MatchedTauJet.resize(0);
    MatchedTauJetB.resize(0);
    for(int j=0; j<JetsNum; ++j){
        //if(allJet_allJetID[j]!=1)continue;
        
        bool match=false;
        float dRMin=99;
        int jindex=-1;
        float csvm=-1;
        for(int t=0; t<TauDaughtersNum; ++t){
            if(abs(TauDaughters_TauDaughtersPDGId[t])==16 )continue;
            float deta=TauDaughtersEta[t]-JetsEta[j];
            float dphi=TauDaughtersPhi[t]-JetsPhi[j];
            float dR=sqrt((deta*deta)+(dphi*dphi));
            if(dR>0.4)continue;
            match=true;
            if(dRMin>dR){
                csvm=Jets_bDiscriminator[j];
                jindex=j;
            }
        }
        if(match){
        TLorentzVector tmp;
        tmp.SetPtEtaPhiE(JetsPt[jindex],JetsEta[jindex],JetsPhi[jindex],JetsE[jindex]);
        MatchedTauJet.push_back(tmp);
        MatchedTauJetB.push_back(csvm);
        }
    }
    return MatchedTauJet;

}
*/
//vector<float>Events::TauJetsBtagged_(){return MatchedTauJetB;}


float Events::JetBtagEff(float visiblePt){
    int bin=TauBEff->FindBin(visiblePt);
    float TauBeff= TauBEff->GetBinContent(bin);
   
    return TauBeff;
}
bool Events::Baseline(){
bool pass=false;
if(HT>500 && NJets>=4 && MHT>200 && fabs(minDeltaPhiN)>6.0 &&  isoMuonTracks==0 && isoPionTracks==0 && isoElectronTracks==0 && (MuonsNum==0 && ElectronsNum==0))pass=true;
return pass;
}
bool Events::BaselineMu(){
bool pass=false;
if(HT>500 && NJets>=4 &&  isoPionTracks==0 && isoElectronTracks==0 && (ElectronsNum==0))pass=true;
return pass;
}

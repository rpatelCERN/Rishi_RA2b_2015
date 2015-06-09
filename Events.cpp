#include "Events.h"
#include <vector>
#include "TMath.h"

  //Constructor
  Events::Events(TTree * ttree_) : currentEntry_(-1) {



     fChain = ttree_;
    
    /// the variables
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
      fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
      fChain->SetBranchAddress("DeltaPhi1", &DeltaPhi1, &b_DeltaPhi1);
      fChain->SetBranchAddress("DeltaPhi2", &DeltaPhi2, &b_DeltaPhi2);
      fChain->SetBranchAddress("DeltaPhi3", &DeltaPhi3, &b_DeltaPhi3);
      fChain->SetBranchAddress("minDeltaPhiN", &MinDeltaPhiN, &b_minDeltaPhiN);
      fChain->SetBranchAddress("DeltaPhiN1", &DeltaPhiN1, &b_DeltaPhiN1);
      fChain->SetBranchAddress("DeltaPhiN2", &DeltaPhiN2, &b_DeltaPhiN2);
      fChain->SetBranchAddress("DeltaPhiN3", &DeltaPhiN3, &b_DeltaPhiN3);
      fChain->SetBranchAddress("METPt", &METPt, &b_METPt);
      fChain->SetBranchAddress("METPhi", &METPhi, &b_METPhi);
      fChain->SetBranchAddress("JetID", &JetID, &b_JetID);
      fChain->SetBranchAddress("passing", &passing, &b_passing);
      fChain->SetBranchAddress("allJetNum", &allJetNum, &b_allJetNum);
      fChain->SetBranchAddress("allJetPt", allJetPt, &b_allJetPt);
      fChain->SetBranchAddress("allJetEta", allJetEta, &b_allJetEta);
      fChain->SetBranchAddress("allJetPhi", allJetPhi, &b_allJetPhi);
      fChain->SetBranchAddress("allJetE", allJetE, &b_allJetE);
      fChain->SetBranchAddress("allJet_allJetID", allJet_allJetID, &b_allJet_allJetID);
      fChain->SetBranchAddress("JetsNum", &JetsNum, &b_JetsNum);
      fChain->SetBranchAddress("JetsPt", JetsPt, &b_JetsPt);
      fChain->SetBranchAddress("JetsEta", JetsEta, &b_JetsEta);
      fChain->SetBranchAddress("JetsPhi", JetsPhi, &b_JetsPhi);
      fChain->SetBranchAddress("JetsE", JetsE, &b_JetsE);
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
      fChain->SetBranchAddress("SelectedPFCandidatesNum", &SelectedPFCandidatesNum, &b_SelectedPFCandidatesNum);
      fChain->SetBranchAddress("SelectedPFCandidatesPt", SelectedPFCandidatesPt, &b_SelectedPFCandidatesPt);
      fChain->SetBranchAddress("SelectedPFCandidatesEta", SelectedPFCandidatesEta, &b_SelectedPFCandidatesEta);
      fChain->SetBranchAddress("SelectedPFCandidatesPhi", SelectedPFCandidatesPhi, &b_SelectedPFCandidatesPhi);
      fChain->SetBranchAddress("SelectedPFCandidatesE", SelectedPFCandidatesE, &b_SelectedPFCandidatesE);
      fChain->SetBranchAddress("SelectedPFCandidates_Charge", SelectedPFCandidates_Charge, &b_SelectedPFCandidates_Charge);
      fChain->SetBranchAddress("SelectedPFCandidates_Typ", SelectedPFCandidates_Typ, &b_SelectedPFCandidates_Typ);
      fChain->SetBranchAddress("GenBosonNum", &GenBosonNum, &b_GenBosonNum);
      fChain->SetBranchAddress("GenBosonPt", GenBosonPt, &b_GenBosonPt);
      fChain->SetBranchAddress("GenBosonEta", GenBosonEta, &b_GenBosonEta);
      fChain->SetBranchAddress("GenBosonPhi", GenBosonPhi, &b_GenBosonPhi);
      fChain->SetBranchAddress("GenBosonE", GenBosonE, &b_GenBosonE);
      fChain->SetBranchAddress("GenBoson_GenBosonPDGId", GenBoson_GenBosonPDGId, &b_GenBoson_GenBosonPDGId);
      fChain->SetBranchAddress("GenMuNum", &GenMuNum, &b_GenMuNum);
      fChain->SetBranchAddress("GenMuPt", GenMuPt, &b_GenMuPt);
      fChain->SetBranchAddress("GenMuEta", GenMuEta, &b_GenMuEta);
      fChain->SetBranchAddress("GenMuPhi", GenMuPhi, &b_GenMuPhi);
      fChain->SetBranchAddress("GenMuE", GenMuE, &b_GenMuE);
      fChain->SetBranchAddress("GenMu_GenMuFromTau", GenMu_GenMuFromTau, &b_GenMu_GenMuFromTau);
      fChain->SetBranchAddress("GenElecNum", &GenElecNum, &b_GenElecNum);
      fChain->SetBranchAddress("GenElecPt", GenElecPt, &b_GenElecPt);
      fChain->SetBranchAddress("GenElecEta", GenElecEta, &b_GenElecEta);
      fChain->SetBranchAddress("GenElecPhi", GenElecPhi, &b_GenElecPhi);
      fChain->SetBranchAddress("GenElecE", GenElecE, &b_GenElecE);
      fChain->SetBranchAddress("GenElec_GenElecFromTau", GenElec_GenElecFromTau, &b_GenElec_GenElecFromTau);
      fChain->SetBranchAddress("GenTauNum", &GenTauNum, &b_GenTauNum);
      fChain->SetBranchAddress("GenTauPt", GenTauPt, &b_GenTauPt);
      fChain->SetBranchAddress("GenTauEta", GenTauEta, &b_GenTauEta);
      fChain->SetBranchAddress("GenTauPhi", GenTauPhi, &b_GenTauPhi);
      fChain->SetBranchAddress("GenTauE", GenTauE, &b_GenTauE);
      fChain->SetBranchAddress("GenTau_GenTauHad", GenTau_GenTauHad, &b_GenTau_GenTauHad);
      fChain->SetBranchAddress("TauDaughtersNum", &TauDaughtersNum, &b_TauDaughtersNum);
      fChain->SetBranchAddress("TauDaughtersPt", TauDaughtersPt, &b_TauDaughtersPt);
      fChain->SetBranchAddress("TauDaughtersEta", TauDaughtersEta, &b_TauDaughtersEta);
      fChain->SetBranchAddress("TauDaughtersPhi", TauDaughtersPhi, &b_TauDaughtersPhi);
      fChain->SetBranchAddress("TauDaughtersE", TauDaughtersE, &b_TauDaughtersE);
      fChain->SetBranchAddress("TauDaughters_TauDaughtersPDGId", TauDaughters_TauDaughtersPDGId, &b_TauDaughters_TauDaughtersPDGId);
      fChain->SetBranchAddress("SelectedPFCandidates_1Num", &SelectedPFCandidates_1Num, &b_SelectedPFCandidates_1Num);
      fChain->SetBranchAddress("SelectedPFCandidates_1Pt", SelectedPFCandidates_1Pt, &b_SelectedPFCandidates_1Pt);
      fChain->SetBranchAddress("SelectedPFCandidates_1Eta", SelectedPFCandidates_1Eta, &b_SelectedPFCandidates_1Eta);
      fChain->SetBranchAddress("SelectedPFCandidates_1Phi", SelectedPFCandidates_1Phi, &b_SelectedPFCandidates_1Phi);
      fChain->SetBranchAddress("SelectedPFCandidates_1E", SelectedPFCandidates_1E, &b_SelectedPFCandidates_1E);
      fChain->SetBranchAddress("SelectedPFCandidates_1_Charge", SelectedPFCandidates_1_Charge, &b_SelectedPFCandidates_1_Charge);
      fChain->SetBranchAddress("SelectedPFCandidates_1_Typ", SelectedPFCandidates_1_Typ, &b_SelectedPFCandidates_1_Typ);
      fChain->SetBranchAddress("SelectedPFCandidates_1_mT", SelectedPFCandidates_1_mT, &b_SelectedPFCandidates_1_mT);
      fChain->SetBranchAddress("SelectedPFCandidates_1_Typ_1", SelectedPFCandidates_1_Typ_1, &b_SelectedPFCandidates_1_Typ_1);
      fChain->SetBranchAddress("SelectedPFCandidates_1_dZ", SelectedPFCandidates_1_dZ, &b_SelectedPFCandidates_1_dZ);
      fChain->SetBranchAddress("MuonsNum", &MuonsNum, &b_MuonsNum);
      fChain->SetBranchAddress("MuonsPt", MuonsPt, &b_MuonsPt);
      fChain->SetBranchAddress("MuonsEta", MuonsEta, &b_MuonsEta);
      fChain->SetBranchAddress("MuonsPhi", MuonsPhi, &b_MuonsPhi);
      fChain->SetBranchAddress("MuonsE", MuonsE, &b_MuonsE);
      fChain->SetBranchAddress("selectedIDMuonsNum", &selectedIDMuonsNum, &b_selectedIDMuonsNum);
      fChain->SetBranchAddress("selectedIDMuonsPt", selectedIDMuonsPt, &b_selectedIDMuonsPt);
      fChain->SetBranchAddress("selectedIDMuonsEta", selectedIDMuonsEta, &b_selectedIDMuonsEta);
      fChain->SetBranchAddress("selectedIDMuonsPhi", selectedIDMuonsPhi, &b_selectedIDMuonsPhi);
      fChain->SetBranchAddress("selectedIDMuonsE", selectedIDMuonsE, &b_selectedIDMuonsE);
      fChain->SetBranchAddress("ElectronsNum", &ElectronsNum, &b_ElectronsNum);
      fChain->SetBranchAddress("ElectronsPt", ElectronsPt, &b_ElectronsPt);
      fChain->SetBranchAddress("ElectronsEta", ElectronsEta, &b_ElectronsEta);
      fChain->SetBranchAddress("ElectronsPhi", ElectronsPhi, &b_ElectronsPhi);
      fChain->SetBranchAddress("ElectronsE", ElectronsE, &b_ElectronsE);

    // Number of total entries

    template_Entries = fChain->GetEntries();
    TFile*f1=new TFile("TTJetsResponse.root");
      templatesToRead[0]=(TH1F*)f1->Get("response2");
       templatesToRead[1]=(TH1F*)f1->Get("response3");
       templatesToRead[2]=(TH1F*)f1->Get("response4");
       templatesToRead[3]=(TH1F*)f1->Get("response5");
      
      TFile*f2=new TFile("TauBTagEff.root");
      TauBEff=(TH1F*)f2->Get("GenTauPtB");
     // f1->Close();

  }//end of class constructor Event


  // A function to make events available
  bool Events::loadNext() {

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

    return passing;
  }
   vector<TLorentzVector>  Events::GenMu_(){
       GenMu.resize(0);
       for(int m=0; m<GenMuNum; m++){
           if(GenMu_GenMuFromTau[m]!=0)continue;
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE(GenMuPt[m],GenMuEta[m],GenMuPhi[m],GenMuE[m]);
           GenMu.push_back(tmp);
       }
       
       return GenMu;

   }
   vector<TLorentzVector>  Events::GenTau_(){
       GenTau.resize(0);
       for(int t=0; t<GenTauNum; t++){
           if(GenTauPt[t]<20 || fabs(GenTauEta[t])>2.1 )continue;
           if(GenTau_GenTauHad[t]!=1)continue;
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE(GenTauPt[t],GenTauEta[t],GenTauPhi[t],GenTauE[t]);
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
           tmp.SetPtEtaPhiE(JetsPt[j],JetsEta[j],JetsPhi[j],JetsE[j]);

           GoodJets.push_back(tmp);
           MatchedJetB.push_back(Jets_bDiscriminator[j]);
       }
       return GoodJets;
   }
   vector<TLorentzVector>  Events::AllJets_(){
       allJets.resize(0);
       for(int j=0; j<allJetNum; ++j){
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE(allJetPt[j],allJetEta[j],allJetPhi[j],allJetE[j]);
           allJets.push_back(tmp);
       }
       return allJets;
   }
   vector<TLorentzVector>  Events::SelMu_(){
       SelMuons.resize(0);
       /*
       for(int m=0; m<GenMuNum; ++m){
           if(GenMu_GenMuFromTau[m]!=0)continue;
           if(GenMuPt[m]<20 || fabs(GenMuEta[m])>2.1 )continue;
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE(GenMuPt[m],GenMuEta[m],GenMuPhi[m],GenMuE[m]);
           SelMuons.push_back(tmp);

       }
        */
       
       for(int m=0; m<selectedIDMuonsNum; m++){
       
           if(selectedIDMuonsPt[m]<20 || fabs(selectedIDMuonsEta[m])>2.1 )continue;
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE(selectedIDMuonsPt[m],selectedIDMuonsEta[m],selectedIDMuonsPhi[m],selectedIDMuonsE[m]);
           SelMuons.push_back(tmp);
       }
       
       /*
       for(int m=0; m<MuonsNum; m++){
           
           if(MuonsPt[m]<20 || fabs(MuonsEta[m])>2.1 )continue;
           TLorentzVector tmp;
           tmp.SetPtEtaPhiE(MuonsPt[m],MuonsEta[m],MuonsPhi[m],MuonsE[m]);
           SelMuons.push_back(tmp);
       }
       */
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

vector<float>Events::TauJetsBtagged_(){return MatchedTauJetB;}


float Events::JetBtagEff(float visiblePt){
    int bin=TauBEff->FindBin(visiblePt);
    float TauBeff= TauBEff->GetBinContent(bin);
   
    return TauBeff;
}


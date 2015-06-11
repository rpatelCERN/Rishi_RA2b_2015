
//Lost Lepton Efficiency and Acceptance maps
#include "Events.h"
//#include "Selection.h"
#include "TTree.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "TChain.h"
#include <cmath>
#include <map>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include "TLorentzVector.h"
#include <stdio.h>
#include "TColor.h"
#include "TF1.h"
#include "TLegend.h"
#include "TVector3.h"
#include "TFile.h"
#include "TH1.h"
#include "TVector2.h"
#include "TCanvas.h"
#include "TH2.h"
#include "TH3F.h"
#include "TString.h"
using namespace std;


void fillAllSearchBins(TH3F*inputRectoHisto[4], TH1F*input1D){
    int ibin=0;
    
    for(int nb=0; nb<=3; nb++){
       inputRectoHisto[nb]->Sumw2();
    for ( int ij=1; ij<=3; ij++ ) {
        for ( int mhti=1; mhti<=3; mhti++ ){
            for ( int hti=1; hti<=3; hti++ ) {
                
                if(hti<2 && mhti==3)continue;
                if(mhti==1){
                    ++ibin;
                   input1D->SetBinContent(ibin,inputRectoHisto[nb]->GetBinContent( ij, mhti, hti ));
                   input1D->SetBinError(ibin,inputRectoHisto[nb]->GetBinError( ij, mhti, hti ));
                    
                }
                if(mhti==3){
                    if(hti==3)continue;
                    ++ibin;
                    input1D->SetBinContent(ibin,inputRectoHisto[nb]->GetBinContent( ij, mhti, 2 )+inputRectoHisto[nb]->GetBinContent( ij, mhti, 3 ) );
                    float err1= inputRectoHisto[nb]->GetBinError( ij, mhti, 2 )*inputRectoHisto[nb]->GetBinError( ij, mhti, 2 );
                    float err2= inputRectoHisto[nb]->GetBinError( ij, mhti, 3 )*inputRectoHisto[nb]->GetBinError( ij, mhti, 3 );
                    float totalerr=sqrt(err1*err1+(err2*err2));
                    input1D->SetBinError(ibin,totalerr );
                    
                    
                }
                if(mhti==2){
                    if(hti==2)continue;
                    ++ibin;
                    
                    input1D->SetBinContent(ibin,inputRectoHisto[nb]->GetBinContent( ij, mhti, 1 )+inputRectoHisto[nb]->GetBinContent( ij, mhti, 2 ));
                    float err1= inputRectoHisto[nb]->GetBinError( ij, mhti, 1 )*inputRectoHisto[nb]->GetBinError( ij, mhti, 1 );
                    float err2= inputRectoHisto[nb]->GetBinError( ij, mhti, 2 )*inputRectoHisto[nb]->GetBinError( ij, mhti, 2 );
                    
                    input1D->SetBinError(ibin,sqrt((err1*err1)+(err2*err2)));
                    
                    
                    if(hti==3){
                        
                        input1D->SetBinContent(ibin,inputRectoHisto[nb]->GetBinContent( ij, mhti, hti ));
                        input1D->SetBinError(ibin,inputRectoHisto[nb]->GetBinError( ij, mhti, hti ));
                        
                        
                    }
                    
                    
                }
            }
        }
    }
}
    
    
}


void fillSearchBins(TH3F*inputRectoHisto, TH1F*input1D){
    int ibin=0;
    inputRectoHisto->Sumw2();
    for ( int ij=1; ij<=3; ij++ ) {
        for ( int mhti=1; mhti<=3; mhti++ ){
            for ( int hti=1; hti<=3; hti++ ) {
                
                if(hti<2 && mhti==3)continue;
                if(mhti==1){
                    ++ibin;
                    input1D->SetBinContent(ibin,inputRectoHisto->GetBinContent( ij, mhti, hti ));
                    input1D->SetBinError(ibin,inputRectoHisto->GetBinError( ij, mhti, hti ));

                }
                if(mhti==3){
                    if(hti==3)continue;
                    ++ibin;
                    input1D->SetBinContent(ibin,inputRectoHisto->GetBinContent( ij, mhti, 2 )+inputRectoHisto->GetBinContent( ij, mhti, 3 ) );
                    float err1= inputRectoHisto->GetBinError( ij, mhti, 2 )*inputRectoHisto->GetBinError( ij, mhti, 2 );
                    float err2= inputRectoHisto->GetBinError( ij, mhti, 3 )*inputRectoHisto->GetBinError( ij, mhti, 3 );
                    float totalerr=sqrt(err1*err1+(err2*err2));
                   input1D->SetBinError(ibin,totalerr );

                    
                }
                if(mhti==2){
                    if(hti==2)continue;
                    ++ibin;
                    
                    input1D->SetBinContent(ibin,inputRectoHisto->GetBinContent( ij, mhti, 1 )+inputRectoHisto->GetBinContent( ij, mhti, 2 ));
                    float err1= inputRectoHisto->GetBinError( ij, mhti, 1 )*inputRectoHisto->GetBinError( ij, mhti, 1 );
                    float err2= inputRectoHisto->GetBinError( ij, mhti, 2 )*inputRectoHisto->GetBinError( ij, mhti, 2 );

                   input1D->SetBinError(ibin,sqrt((err1*err1)+(err2*err2)));

                    
                    if(hti==3){
                        
                        input1D->SetBinContent(ibin,inputRectoHisto->GetBinContent( ij, mhti, hti ));
                        input1D->SetBinError(ibin,inputRectoHisto->GetBinError( ij, mhti, hti ));

                        
                    }
                    
                    
                }
            }
        }
    }
    //std::cout<<"Ibins "<<ibin<<std::endl;
}

void muContributionBin(std::vector<float>&SmearedNJ,std::vector<float>&SmearedMHT,
                       std::vector<float>&SmearedHT, std::vector<float>SmearedWeight,TH3F*TempHisto,TH3F*TempHistoWeight)
                       {
        
                           
                           
            for(int i=0; i<SmearedNJ.size();++i){
                    TempHisto->Fill(SmearedNJ[i],SmearedMHT[i],SmearedHT[i]);//fill each bin with the appropriate weight //when you read back the error you get the sum of the weights in that bin
                TempHistoWeight->Fill(SmearedNJ[i],SmearedMHT[i],SmearedHT[i],SmearedWeight[i]);
            }
                           

    }

void muContributionAllBins(std::vector<float>&SmearedPhi,std::vector<float>&SmearedNJ,std::vector<float>&SmearedMHT,
                       std::vector<float>&SmearedHT, std::vector<float>SmearedNB,std::vector<float>SmearedNoB,std::vector<float>SmearedWeight,std::vector<float>SmearedNBWeight, std::vector<float>SmearedNoBWeight,TH3F*TempHistoWeight[4])
{
    
    
    
    for(int i=0; i<SmearedNJ.size();++i){
        int beffBin=SmearedNB[i];
        int zbeffBin=SmearedNoB[i];
        if(beffBin>=3)beffBin=3;
        if(zbeffBin>=3)zbeffBin=3;

        if(fabs(SmearedPhi[i])>6.0){
        TempHistoWeight[beffBin]->Fill(SmearedNJ[i],SmearedMHT[i],SmearedHT[i]);//fill each bin with the appropriate weight //when you read back the error you get the sum of the weights in that bin
        TempHistoWeight[zbeffBin]->Fill(SmearedNJ[i],SmearedMHT[i],SmearedHT[i]);
	}
    }
    
    
}
int main(int argc, char *argv[]){

  /////////////////////////////////////
    string fin=argv[1];
    char*i;
    char*s;
    char*f;
    int index=strtol(argv[2], &i, 10);
    long start=strtol(argv[3], &s, 10);
    long finish=strtol(argv[4], &s, 10);
    TChain *sample_AUX = new TChain("TreeMaker2/PreSelection");
    sample_AUX->Add(fin.c_str());
    Events * evt = new Events(sample_AUX);
    float MHTBins[4]={200, 500., 750.,9999.};
    float HTBins[4]={500., 800., 1200.,9999.};
    float NJBins[4]={4, 7,9,99};
    TH3F*Recthisto=new TH3F("Recthisto","",3, NJBins,3,MHTBins,3,HTBins);
    TH3F*RecthistoTau[4];

    TH3F*MuonYields=new TH3F("MuonYields","",3, NJBins,3,MHTBins,3,HTBins);
    TH3F*MuonYieldsAll[4];
    TH3F*Weights=new TH3F("Weights","",3, NJBins,3,MHTBins,3,HTBins);

    TH3F*MuonWeighted=new TH3F("MuonWeighted","",3, NJBins,3,MHTBins,3,HTBins);
    TH3F*HadTauYields=new TH3F("HadTauYields","",3, NJBins,3,MHTBins,3,HTBins);
    
    TH3F*RecthistoScan=new TH3F("RecthistoScan","",3, NJBins,3,MHTBins,3,HTBins);
   
    TH3F*RecthistoSamp=new TH3F("RecthistoSamp","",3, NJBins,3,MHTBins,3,HTBins);
    TH3F*RecthistoBbins[4];
    TH3F*tempHistoBbins[4];
    for(int i=0; i<4; ++i){
       // RecthistoBbins[i]=(TH3F*)RecthistoScan->Clone(TString::Format("RecthistoScan_%d", i));
        RecthistoBbins[i]=new TH3F(TString::Format("RecthistoScan_%d", i), "",3, NJBins,3,MHTBins,3,HTBins);
        tempHistoBbins[i]=new TH3F(TString::Format("tempHistoBbins_%d", i), "",3, NJBins,3,MHTBins,3,HTBins);
        MuonYieldsAll[i]=new TH3F(TString::Format("MuonYieldsAll_%d", i), "",3, NJBins,3,MHTBins,3,HTBins);
        RecthistoTau[i]=new TH3F(TString::Format("RecthistoTau_%d", i), "",3, NJBins,3,MHTBins,3,HTBins);
    }

    TH3F*tempHisto=new TH3F("tempHisto","",3, NJBins,3,MHTBins,3,HTBins);
    TH3F*tempHistoWeight=new TH3F("tempHistoWeight","",3, NJBins,3,MHTBins,3,HTBins);
  //  tempHistoWeight->Sumw2();
/*
    TH1F*MuPredictedHT=new TH1F("MuPredictedHT"," ", 50, 500., 2000);
    TH1F*MuPredictedMHT=new TH1F("MuPredictedMHT"," ", 50, 500., 2000);
    TH1F*MuPredictedNJ=new TH1F("MuPredictedNJ"," ", 20, 0., 20);
    TH1F*MuPredictedNB=new TH1F("MuPredictedNB"," ", 10, 0., 10);

    
    TH1F*Deltaphi=new TH1F("DeltaPhi","", 100, 0.0, 10);
    TH1F*DeltaphiSample=(TH1F*)Deltaphi->Clone("DeltaPhiSample");
    
    TH1F*GenTauPt=new TH1F("GenTauPt","", 100, 0.0,500);
    TH1F*GenTauPtB=new TH1F("GenTauPtB","", 100, 0.0,500);

    TH1F*GenHTTau=(TH1F*)MuPredictedHT->Clone("GenHTTau");
    TH1F*GenNJTau=(TH1F*)MuPredictedNJ->Clone("GenNJTau");
    TH1F*GenMHTTau=(TH1F*)MuPredictedMHT->Clone("GENMHTTau");
    
    
    TH1F*MuPredictedHTSample=(TH1F*)MuPredictedHT->Clone("MuPredictedHTSample");
    TH1F*MuPredictedNJSample=(TH1F*)MuPredictedNJ->Clone("MuPredictedNJSample");
    TH1F*MuPredictedMHTSample=(TH1F*)MuPredictedMHT->Clone("MuPredictedMHTSample");
    
    
    TH1F*MuPredictedHTBase=(TH1F*)MuPredictedHT->Clone("MuPredictedHTBase");
    TH1F*MuPredictedNJBase=(TH1F*)MuPredictedNJ->Clone("MuPredictedNJBase");
    TH1F*MuPredictedMHTBase=(TH1F*)MuPredictedMHT->Clone("MuPredictedMHTBase");
    
    TH1F*MuPredictedHTBaseSamp=(TH1F*)MuPredictedHT->Clone("MuPredictedHTBaseSamp");
    TH1F*MuPredictedNJBaseSamp=(TH1F*)MuPredictedNJ->Clone("MuPredictedNJBaseSamp");
    TH1F*MuPredictedMHTBaseSamp=(TH1F*)MuPredictedMHT->Clone("MuPredictedMHTBaseSamp");
  */  
    int eventN=0;
   evt->setStart(start); 
    while( evt->loadNext(start) ){

        ++eventN;
	//std::cout<<eventN<<std::endl;
    //   if(eventN<start)continue;
       if(eventN>finish)break;
       if(evt->JetId()!=1)continue;
       if(evt->nEle()!=0)continue;
        
        //mu event:
        std::vector<TLorentzVector>GoodJets=evt->GoodJets_();
        std::vector<TLorentzVector>Mu=evt->SelMu_();
        std::vector<TLorentzVector>GenTauHad=evt->GenTau_();
        std::vector<TLorentzVector>GenMu=evt->GenMu_();

        std::vector<TLorentzVector>MuJets=evt->MuMatchedJet_();
        std::vector<float>BTagJets=evt->MatchJetsBtagged_();
        
        if(evt->SelMu_().size()>1)continue;
      //  if(MuJets.size()==0 && Mu.size()!=0)
        //{//std::cout<<"No matched Jet "<<std::endl;
          //  continue;
       // }
            //else std::cout<<"Matches Found "<<std::endl;
        TLorentzVector mockMHT(0,0,0,0);
        for(int j=0; j<GoodJets.size();++j){
            if(GoodJets[j].Pt()<30)continue;
            if(fabs(GoodJets[j].Eta())>5.0)continue;
            mockMHT=mockMHT-GoodJets[j];
        }
        //std::cout<<"Mock MHT "<<mockMHT.Pt()<<std::endl;
        bool isBTag=false;
        for(int j=0; j<MuJets.size();++j){
            if(MuJets[j].Pt()<30)continue;
            if(fabs(MuJets[j].Eta())>5.0)continue;
            mockMHT=mockMHT+MuJets[j];
            if(BTagJets[j]>0.814 && fabs(MuJets[j].Eta())<2.4)isBTag=true;
        }
        
        
        float MHT=mockMHT.Pt();
        float HT=evt->ht();
        int NJets=evt->nJets();
        int NB=evt->nBtags();
        if(isBTag)NB=NB-1;//muon jet is btagged
        //remove Mu from HT comp
        for(int j=0; j<MuJets.size();++j){
            if(MuJets[j].Pt()<30)continue;
             if(fabs(MuJets[j].Eta())>2.4)continue;
            HT=HT-MuJets[j].Pt();//remove muPT from HT
            
            NJets=NJets-1;//Remove the muon jet counted in NJet count
            
        }
        //if(MuJets.size()==0)NJets=NJets+1;//muon a jet and the NJet count is correct the muon is not counted
      //  std::cout<<"NJets w/o Muon Jet "<<NJets<<std::endl;
        //smear the muon pT
        
        for(int m=0; m<Mu.size();++m){
            std::vector<float>residuals;

                    for(int j=0; j<MuJets.size();++j){
                        float deta=fabs(Mu[m].Eta()-MuJets[j].Eta());
                        float dphi=(Mu[m].Phi()-MuJets[j].Phi());
                        float dR=sqrt((deta*deta)+(dphi*dphi));
                        if(dR>0.4)continue;
                        residuals.push_back(MuJets[j].Pt()-Mu[m].Pt());
                    }
            for(int r=0; r<residuals.size();++r)HT=HT+residuals[r];
            //compute the smeared mu Pt
            std::vector<float>SmearedPt=evt->TempResponsePt(Mu[m].Pt());
            std::vector<float>SmearedWeight=evt->TempResponseWeight(Mu[m].Pt());
            //compute the smeared HT and NJets
            std::vector<float>SmearedHT;
            std::vector<float>SmearedMHT;
	    std::vector<float>SmearedPhi;
            std::vector<float>SmearedNJets;
            std::vector<float>SmearedNB;
            std::vector<float>SmearedNBWeight;
            std::vector<float>SmearedNoB;
            std::vector<float>SmearedNoBWeight;
            TLorentzVector tmpMu;
            //scan across the full template
            for(int i=0; i<SmearedPt.size(); ++i){
                float SHT=HT;//HT without mu Pt
                int SNJ=NJets; //counted without muon jet
                int sB=NB;
                if(SmearedPt[i]>30){SHT=SHT+SmearedPt[i]; SNJ=SNJ+1;}//SHT will change but NJets will either be the same or decrement
                SmearedHT.push_back(SHT);
                SmearedNJets.push_back(SNJ);
                tmpMu.SetPtEtaPhiE(SmearedPt[i], Mu[m].Eta(),Mu[m].Phi(), Mu[m].E());
                TLorentzVector tmpMHT=mockMHT;
                if(tmpMu.Pt()>30)tmpMHT=tmpMHT-tmpMu;
                SmearedMHT.push_back(tmpMHT.Pt());
                //  std::cout<<"Delta Phi "<<<<std::endl;
                
                float btageff=evt->JetBtagEff(SmearedPt[i]);
                float zerobeff=(1-btageff);
                SmearedNoB.push_back(sB);
                SmearedNoBWeight.push_back(zerobeff);
                if(tmpMu.Pt()>30)SmearedNB.push_back(sB+1);
                else SmearedNB.push_back(sB);
                SmearedNBWeight.push_back(btageff);
            
                //also compute deltaPhi
                float dphi=evt->dphiN(tmpMu,tmpMHT);
              SmearedPhi.push_back(dphi);
              if(GenMu.size()==1){
                  if(fabs(GenMu[0].Eta())<2.1 && GenMu[0].Pt()>20){
                //if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )MuPredictedHTBase->Fill(SHT, SmearedWeight[i]);
                //if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )MuPredictedNJBase->Fill(SNJ, SmearedWeight[i]);
                //if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )MuPredictedMHTBase->Fill(tmpMHT.Pt(), SmearedWeight[i]);
                if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )RecthistoScan->Fill(SNJ, tmpMHT.Pt(),SHT,  SmearedWeight[i]);
                //fill the right b bin
                      int beffBin=SmearedNB[i];
                      int zbeffBin=SmearedNoB[i];
                      if(beffBin>=3)beffBin=3;
                      if(zbeffBin>=3)zbeffBin=3;
                      if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )RecthistoBbins[beffBin]->Fill(SNJ, tmpMHT.Pt(),SHT,  SmearedNBWeight[i]*SmearedWeight[i]);
                      if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )RecthistoBbins[zbeffBin]->Fill(SNJ, tmpMHT.Pt(),SHT,  SmearedNoBWeight[i]*SmearedWeight[i]);
                     /* 
                      MuPredictedHT->Fill(SHT, SmearedWeight[i]);
                      MuPredictedNJ->Fill(SNJ, SmearedWeight[i]);
                      MuPredictedMHT->Fill(tmpMHT.Pt(), SmearedWeight[i]);
                      Deltaphi->Fill(evt->dphiN(tmpMu,tmpMHT ));
                      MuPredictedNB->Fill(SmearedNB[i], SmearedNBWeight[i]);
                      MuPredictedNB->Fill(SmearedNoB[i], SmearedNoBWeight[i]);
*/
                  }
                }
            }
            
      
            //how many entries:

            //TH3F*tempHisto;
            float MHTBins[4]={200, 500., 750.,9999.};
            float HTBins[4]={500., 800., 1200.,9999.};
            float NJBins[4]={4, 7,9,99};
         //   TH3F*tempH=(TH3F*)tempHisto->Clone("tempH");
            tempHisto->Reset();
            tempHistoWeight->Reset();
            for(int b=0; b<4; ++b)tempHistoBbins[b]->Reset();
            muContributionBin(SmearedNJets, SmearedMHT,SmearedHT,SmearedWeight,tempHisto,tempHistoWeight );
            muContributionAllBins(SmearedPhi,SmearedNJets, SmearedMHT,SmearedHT,SmearedNB,SmearedNoB, SmearedWeight,SmearedNBWeight, SmearedNoBWeight, tempHistoBbins);
           // delete tempHisto;
            //fill count
            for(int i=1; i<=3; ++i)
                for(int j=1; j<=3; ++j)
                    for(int k=1; k<=3; ++k){
                        
                        if(tempHisto->GetBinContent(i,j,k)!=0){
                            
                            float x=tempHisto->ProjectionX()->GetBinCenter(i);
                            float y=tempHisto->ProjectionY()->GetBinCenter(j);
                            float z=tempHisto->	ProjectionZ()->GetBinCenter(k);
                           // std::cout<<" Bins NJ:MHT:HT"<<x<<":"<<y<<":"<<z<<std::endl;
                            MuonYields->Fill(x,y,z);
                            
                            Weights->Fill(x,y,z,tempHistoWeight->GetBinError(i,j,k));
                        }
                        for(int b=0; b<4; ++b){
                        if(tempHistoBbins[b]->GetBinContent(i,j,k)!=0){
                            float x=tempHistoBbins[b]->ProjectionX()->GetBinCenter(i);
                            float y=tempHistoBbins[b]->ProjectionY()->GetBinCenter(j);
                            float z=tempHistoBbins[b]->	ProjectionZ()->GetBinCenter(k);
                            if(evt->BaselineMu())MuonYieldsAll[b]->Fill(x,y,z);
                        }
                      }
                    }

            //fill the histogram

            //sample the template once
            float SHT=HT;//HT without mu Pt
            int SNJ=NJets;
            TLorentzVector tmpMHT=mockMHT;
            float smearedPtSample=evt->TempResponsePtRandom(Mu[m].Pt());
            if(smearedPtSample>30){SHT=SHT+smearedPtSample; SNJ=SNJ+1;}
            tmpMu.SetPtEtaPhiE(smearedPtSample, Mu[m].Eta(),Mu[m].Phi(), Mu[m].E());
            if(tmpMu.Pt()>30)tmpMHT=tmpMHT-tmpMu;
             if(GenMu.size()==1){
                if(fabs(GenMu[0].Eta())<2.1 && GenMu[0].Pt()>20){
          //  MuPredictedHTSample->Fill(SHT);
          //  MuPredictedNJSample->Fill(SNJ);
          //  MuPredictedMHTSample->Fill(tmpMHT.Pt());
            //        DeltaphiSample->Fill(evt->dphiN(tmpMu,tmpMHT ));
                    float dphi=evt->dphiN(tmpMu,tmpMHT);

                    //if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )MuPredictedHTBaseSamp->Fill(SHT);
                    //if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )MuPredictedNJBaseSamp->Fill(SNJ);
                    //if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )MuPredictedMHTBaseSamp->Fill(tmpMHT.Pt());
                    if(SHT>500 && SNJ>=4 && tmpMHT.Pt()>200 && fabs(dphi)>6. )
                        RecthistoSamp->Fill(SNJ, tmpMHT.Pt(),SHT);
                }
             }
        }
        
       //now you can fill the event info
        
        
        
        //tau Event:
        
            for(int T=0; T<GenTauHad.size(); ++T){
               // if(evt->SelMu_().size()>0)continue;
               // if(fabs(GenTauHad[T].Eta())>2.1)continue;
               // if(fabs(GenTauHad[T].Pt())<20)continue;
                //fill Event variables
              //   if(evt->ht()>500 && evt->nJets()>=4 && mockMHT.Pt()>200){
           //        GenHTTau->Fill(evt->ht());
           //        GenNJTau->Fill(evt->nJets());
           //        GenMHTTau->Fill(evt->mht());
                int bbin=evt->nBtags();
                if(bbin>=3)bbin=3;
	if(evt->Baseline()){
             
	        RecthistoTau[bbin]->Fill(evt->nJets(),evt->mht(),evt->ht());
	       }
            }
        
        
    }
    //fill event yields

//    TH1F*MuScanBins=new TH1F("MuScanBins", "", 18, 0, 18);
//    TH1F*MuSampleBins=new TH1F("MuSampleBins", "", 18, 0, 18);
//    TH1F*MuControlSeed=new TH1F("MuControlSeed", "", 18, 0, 18);
    TH1F*MuControlSeedAll=new TH1F("MuControlSeedAll", "", 72, 0, 72);
    TH1F*TauBkgPredMC=new TH1F("TauBkgPredMC", "", 72, 0, 72);

//    TH1F*TestWeights=new TH1F("TestWeights", "", 18,0,18);
    TH1F*AllBins=new TH1F("AllBins", "", 72,0,72);
/*
    fillSearchBins(RecthistoScan,MuScanBins);
    fillSearchBins(RecthistoSamp,MuSampleBins);
    fillSearchBins(MuonYields,MuControlSeed);
*/
    fillAllSearchBins(RecthistoBbins,AllBins);
    fillAllSearchBins(MuonYieldsAll,MuControlSeedAll);
    fillAllSearchBins(RecthistoTau,TauBkgPredMC);
    TFile*f2=new TFile(TString::Format("output_%d.root",index).Data(), "RECREATE");
    f2->cd();
/*
    MuPredictedHT->Write();
    MuPredictedMHT->Write();
    MuPredictedNJ->Write();
    MuPredictedNB->Write();
    MuPredictedHTSample->Write();
    MuPredictedNJSample->Write();
    MuPredictedMHTSample->Write();
    GenTauPt->Write();
*/ 
 //  GenTauPtB->Write();
 //   RecthistoScan->Write();
 //   RecthistoSamp->Write();
 //   MuPredictedHTBase->Write();
 //   MuPredictedMHTBase->Write();
  //  MuPredictedNJBase->Write();
 //   MuPredictedHTBaseSamp->Write();
 //   MuPredictedNJBaseSamp->Write();
 //GenHTTau-   MuPredictedMHTBaseSamp->Write();
 //   GenHTTau->Write();
 //   GenNJTau->Write();
 //   GenMHTTau->Write();
//    MuScanBins->Write();
//    MuSampleBins->Write();
//    MuControlSeed->Write();
//    TestWeights->Write();

    AllBins->Write();
    MuControlSeedAll->Write();
    TauBkgPredMC->Write();
return 1;
}

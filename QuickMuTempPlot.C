//
//  QuickClosePlot.C
//  
//
//  Created by Rishi Patel on 6/2/15.
//
//

#include <stdio.h>


void QuickMuTempPlot(){
    TFile*f0=new TFile("output.root");
    TCanvas*c0=new TCanvas("c0", "", 1600, 800);
    c0->Divide(2,1);
    c0->cd(1);
    
    MuScanBins->Sumw2();
    //TH1F*weight=(TH1F*)MuScanBins->Clone("SumWeights");
    //MuSampleBins->Sumw2();

    MuScanBins->SetLineWidth(2.2);
    MuScanBins->SetLineColor(kRed);
    
    MuSampleBins->SetLineWidth(2.2);
    MuSampleBins->SetLineColor(kBlue);
    MuScanBins->Draw();
    MuSampleBins->Draw("esame");
    TLegend*leg=new TLegend(0.6909548,0.4404223,0.8907035,0.6425339);
    leg->AddEntry(MuScanBins,"Scanning Template ");
    leg->AddEntry(MuSampleBins,"1 Sample Template ");
    leg->Draw();
    c0->cd(2);
    MuControlSeed->SetLineWidth(2.2);

    MuControlSeed->SetLineColor(kRed);
    MuControlSeed->Draw("e");
    for(int i=1; i<=18;++i){
        std::cout<<"N "<<MuControlSeed->GetBinContent(i)<<std::endl;
        std::cout<<"Nerr "<<MuControlSeed->GetBinError(i)/MuControlSeed->GetBinContent(i)<<"sqrt "<<sqrt(MuControlSeed->GetBinContent(i))/MuControlSeed->GetBinContent(i)<<std::endl;
    }
    c0->Print("SearchbinsNJMHTHT.pdf");
    
    TCanvas*c1=new TCanvas("c1", "", 1600, 800);
    c1->cd();
    TH1F*weight=new TH1F("weight","", 18,0,18);
    for(int i=1; i<=18;++i){
        float den=MuScanBins->GetBinContent(i);
        if(den<0.0000001)den=1.0;
        std::cout<<"MuScanBins->GetBinError(i) "<<MuScanBins->GetBinError(i)/MuScanBins->GetBinContent(i)<<std::endl;
        
        weight->SetBinContent(i, MuScanBins->GetBinError(i)/den);
    }
    weight->Draw();
    c1->Print("SumofWeights.pdf");
    
    //table
    for(int i=1; i<=18;++i ){
        float den=MuScanBins->GetBinContent(i);
        if(den<0.0000001)den=1.0;
        std::cout<<" Nseed "<<MuControlSeed->GetBinContent(i)<<" Sum of Weights "<<MuScanBins->GetBinContent(i)<<" sum(sqrtW) "<<MuScanBins->GetBinError(i)/den<<std::endl;
    }
    
    /*
    TCanvas*c0=new TCanvas("c0", "", 1600, 800);
    c0->Divide(2,1);
    MuPredictedHTBase->Sumw2();
    MuPredictedHTBaseSamp->Sumw2();
    c0->cd(1);
    MuPredictedHTBase->SetLineWidth(2.2);
    MuPredictedHTBase->SetLineColor(kRed);
    MuPredictedHTBase->Draw();
    MuPredictedHTBaseSamp->SetLineWidth(2.2);
    MuPredictedHTBaseSamp->SetLineColor(kBlue);
    MuPredictedHTBaseSamp->Draw("same");
    TLegend*leg=new TLegend(0.6909548,0.4404223,0.8907035,0.6425339);
    leg->AddEntry(MuPredictedHTBase,"Scanning Template ");
    leg->AddEntry(MuPredictedHTBaseSamp,"1 Sample Template ");
    leg->Draw();
    c0->cd(2);
    
    TH1F*num=(TH1F*)MuPredictedHTBase->Clone("num");
    //num->Sumw2();
    num->SetLineColor(kBlack);
    num->Divide(MuPredictedHTBaseSamp);
    num->Draw();
    c0->Print("HTBasePredictions.pdf");
    
    TCanvas*c1=new TCanvas("c1", "", 1600, 800);
    c1->Divide(2,1);
    MuPredictedMHTBase->Sumw2();
    MuPredictedMHTBaseSamp->Sumw2();
    c1->cd(1);
    MuPredictedMHTBase->SetLineWidth(2.2);
    MuPredictedMHTBase->SetLineColor(kRed);
    MuPredictedMHTBase->Draw();
    MuPredictedMHTBaseSamp->SetLineWidth(2.2);
    MuPredictedMHTBaseSamp->SetLineColor(kBlue);
    MuPredictedMHTBaseSamp->Draw("same");
    TLegend*leg2=new TLegend(0.6909548,0.4404223,0.8907035,0.6425339);
    leg2->AddEntry(MuPredictedHTBase,"Scanning Template ");
    leg2->AddEntry(MuPredictedHTBaseSamp,"1 Sample Template ");
    leg2->Draw();
    c1->cd(2);
    TH1F*num2=(TH1F*)MuPredictedMHTBase->Clone("num2");
    //num2->Sumw2();
    num2->SetLineColor(kBlack);
    num2->Divide(MuPredictedMHTBaseSamp);
    num2->Draw();
    c1->Print("MHTBasePredictions.pdf");
    
    TCanvas*c2=new TCanvas("c2", "", 1600, 800);
    c2->Divide(2,1);
    MuPredictedNJBase->Sumw2();
    MuPredictedNJBaseSamp->Sumw2();
    c2->cd(1);
    MuPredictedNJBase->SetLineWidth(2.2);
    MuPredictedNJBase->SetLineColor(kRed);
    MuPredictedNJBase->Draw();
    MuPredictedNJBaseSamp->SetLineWidth(2.2);
    MuPredictedNJBaseSamp->SetLineColor(kBlue);
    MuPredictedNJBaseSamp->Draw("same");
    TLegend*leg3=new TLegend(0.6909548,0.4404223,0.8907035,0.6425339);
    leg3->AddEntry(MuPredictedNJBase,"Scanning Template ");
    leg3->AddEntry(MuPredictedNJBaseSamp,"1 Sample Template ");
    leg3->Draw();
    c2->cd(2);
    TH1F*num3=(TH1F*)MuPredictedNJBase->Clone("num3");
    // num3->Sumw2();
    num3->SetLineColor(kBlack);
    num3->Divide(MuPredictedNJBase);
    num3->Draw();
    c2->Print("NJBasePredictions.pdf");
    
    TCanvas*c3=new TCanvas("c3", "", 1600, 800);
 //   GenTauPtB->Sumw2();
  //  GenTauPt->Sumw2();
    GenTauPtB->Divide(GenTauPt);
    GenTauPtB->Draw();
    TFile*f1=new TFile("TauBTagEff.root","RECREATE");
    GenTauPtB->Write();
    */
    /*
    TCanvas*c0=new TCanvas("c0", "", 1600, 800);
    c0->Divide(2,1);
    MuPredictedHT->Sumw2();
    MuPredictedHTSample->Sumw2();
    c0->cd(1);
    MuPredictedHT->SetLineWidth(2.2);
    MuPredictedHT->SetLineColor(kRed);
    MuPredictedHT->Draw();
    MuPredictedHTSample->SetLineWidth(2.2);
    MuPredictedHTSample->SetLineColor(kBlue);
    MuPredictedHTSample->Draw("same");
    TLegend*leg=new TLegend(0.6909548,0.4404223,0.8907035,0.6425339);
    leg->AddEntry(MuPredictedHT,"Scanning Template ");
    leg->AddEntry(MuPredictedHTSample,"1 Sample Template ");
    leg->Draw();
    c0->cd(2);
  
    TH1F*num=(TH1F*)MuPredictedHT->Clone("num");
    //num->Sumw2();
    num->SetLineColor(kBlack);
    num->Divide(MuPredictedHTSample);
    num->Draw();
    c0->Print("HTPredictions.pdf");
    
    TCanvas*c1=new TCanvas("c1", "", 1600, 800);
    c1->Divide(2,1);
    MuPredictedMHT->Sumw2();
    MuPredictedMHTSample->Sumw2();
    c1->cd(1);
    MuPredictedMHT->SetLineWidth(2.2);
    MuPredictedMHT->SetLineColor(kRed);
    MuPredictedMHT->Draw();
    MuPredictedMHTSample->SetLineWidth(2.2);
    MuPredictedMHTSample->SetLineColor(kBlue);
    MuPredictedMHTSample->Draw("same");
    TLegend*leg2=new TLegend(0.6909548,0.4404223,0.8907035,0.6425339);
    leg2->AddEntry(MuPredictedHT,"Scanning Template ");
    leg2->AddEntry(MuPredictedHTSample,"1 Sample Template ");
    leg2->Draw();
    c1->cd(2);
    TH1F*num2=(TH1F*)MuPredictedMHT->Clone("num2");
    //num2->Sumw2();
    num2->SetLineColor(kBlack);
    num2->Divide(MuPredictedMHTSample);
    num2->Draw();
    c1->Print("MHTPredictions.pdf");

    TCanvas*c2=new TCanvas("c2", "", 1600, 800);
    c2->Divide(2,1);
    MuPredictedNJBase->Sumw2();
    MuPredictedNJBaseSample->Sumw2();
    c2->cd(1);
    MuPredictedNJBase->SetLineWidth(2.2);
    MuPredictedNJBase->SetLineColor(kRed);
    MuPredictedNJBase->Draw();
    MuPredictedNJBaseSample->SetLineWidth(2.2);
    MuPredictedNJBaseSample->SetLineColor(kBlue);
    MuPredictedNJBaseSample->Draw("same");
    TLegend*leg3=new TLegend(0.6909548,0.4404223,0.8907035,0.6425339);
    leg3->AddEntry(MuPredictedHT,"Scanning Template ");
    leg3->AddEntry(MuPredictedHTSample,"1 Sample Template ");
    leg3->Draw();
    c2->cd(2);
    TH1F*num3=(TH1F*)MuPredictedNJBase->Clone("num3");
   // num3->Sumw2();
    num3->SetLineColor(kBlack);
    num3->Divide(MuPredictedNJBase);
    num3->Draw();
    c2->Print("NJBasePredictions.pdf");
*/
}
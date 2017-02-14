#include "TTree.h"
#include "TFile.h"

void TrigEfficiencyMaker(TString filename){


  TFile *oldfile= new TFile(filename);
  TString output_name = "Trigger_Efficiency.root";
  cout <<"Fine till here 1" << endl;
  TTree *oldtree = (TTree*) oldfile->Get("tree_had");
  cout <<"HERE 2" << endl;

  oldtree->Draw("HT_ak8 >> numerator(400, 0, 4000)", "(((HT800_Count == 1) || (Trim_Count == 1)) && (Any_Mu_Count == 1))");
  cout <<"One draw" << endl;
  oldtree->Draw("HT_ak8 >> denom(400, 0, 4000)", "(Any_Mu_Count == 1)");

  cout << "Draws fine" << endl;

  TH1F *numerator = (TH1F*)gDirectory->Get("numerator");
  TH1F *denom = (TH1F*)gDirectory->Get("denom");

  cout << "Sum Breaks" << endl;
  numerator->Sumw2();
  denom->Sumw2();
  numerator->Divide(denom);
  numerator->Sumw2();
  TFile f("TriggerEfficiency.root", "new");
  numerator->Write("PFHT800_OR_Trim_Efficiency");

}

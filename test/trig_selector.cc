#include "TTree.h"
#include "TFile.h"

void trig_selector(TString filename){


  TFile *oldfile= new TFile(filename);
  TString newname = "PFHT800_OR_Trim50_"+filename;
  cout <<"Fine till here 1" << endl;
  TTree *oldtree = (TTree*) oldfile->Get("tree_had");
  //  Event *event   = 0;
  float _HT800_Count = 0;
  float _Trim_Count = 0;
  oldtree->SetBranchAddress("HT800_Count", &(_HT800_Count));
  oldtree->SetBranchAddress("Trim_Count", &(_Trim_Count));
  TFile *newfile = new TFile(newname, "RECREATE");
  TTree *newtree = oldtree->CloneTree(0);
  int counter = 0;
  Int_t N_entries = oldtree->GetEntriesFast();
  for (int i = 0; i < N_entries; i++){
    oldtree->GetEntry(i);
    if ((_HT800_Count == 1) || (_Trim_Count == 1)){
      newtree->Fill();
      counter++;
    }    
  }
  newfile->cd();
  cout << "Original Entries " << N_entries << endl;
  cout << "Slimmed Entries " << counter << endl;
  newtree->Print();
  newtree->AutoSave();
  newfile->Write();
  newfile->Close();

}

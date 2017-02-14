#include "TTree.h"
#include "TFile.h"

void _2W_slimmer(TString filename){


  TFile *oldfile= new TFile(filename);
  TString newname = "slimmed_2W_"+filename;
  cout <<"Fine till here 1" << endl;
  TTree *oldtree = (TTree*) oldfile->Get("tree_had");
  cout <<"HERE 2" << endl;
  //  Event *event   = 0;
  float _n_W_tags = 0;
  cout <<"Setting Branch Fails" << endl;
  oldtree->SetBranchAddress("n_W_tags", &(_n_W_tags));
  cout <<"newfile breaks" << endl;
  TFile *newfile = new TFile(newname, "RECREATE");
  cout << "3" << endl;
  TTree *newtree = oldtree->CloneTree(0);
  cout << "4" << endl;
  int counter = 0;
  cout <<"5" << endl;
  Int_t N_entries = oldtree->GetEntriesFast();
  for (int i = 0; i < N_entries; i++){
    oldtree->GetEntry(i);
    if (_n_W_tags == 2){
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

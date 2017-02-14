#include "TTree.h"
#include "TFile.h"

void gen_selector(TString filename){


  TFile *oldfile= new TFile(filename);
  TString newname = "genfiltered_2Zt_"+filename;
  cout <<"Fine till here 1" << endl;
  TTree *oldtree = (TTree*) oldfile->Get("tree_had");
  cout << 2 << endl;
  std::vector<float>* GenID = 0;
  std::vector<float>* Daughter0ID = 0;
  std::vector<float>* Daughter1ID = 0;

  oldtree->SetBranchAddress("GenID", &(GenID));
  cout << 3 << endl;
  oldtree->SetBranchAddress("Daughter0ID", &(Daughter0ID));
  oldtree->SetBranchAddress("Daughter1ID", &(Daughter1ID));
  cout << 4 << endl;
  TFile *newfile = new TFile(newname, "RECREATE");
  TTree *newtree = oldtree->CloneTree(0);
  int counter = 0;
  Int_t N_entries = oldtree->GetEntriesFast();
  bool decay_1 = false;
  bool decay_2 = false;
  for (int i = 0; i < N_entries; i++){
    oldtree->GetEntry(i);
    decay_1 = false;
    decay_2 = false;
    for (int j =0; j < (*GenID).size(); j++){
      if ((*GenID)[j] == 8000001){  //Check this number, should be one of the 2 T' (we can 
	if (((abs((*Daughter0ID)[j]) == 23) && (abs((*Daughter1ID)[j]) == 6)) || ((abs((*Daughter1ID)[j]) == 23) && (abs((*Daughter0ID)[j]) == 6))){
	  decay_1 = true;
	}
      }
      if ((*GenID)[j] == -8000001){
        if (((abs((*Daughter0ID)[j]) == 23) && (abs((*Daughter1ID)[j]) == 6)) || ((abs((*Daughter1ID)[j]) == 23) && (abs((*Daughter0ID)[j]) == 6))){
          decay_2 = true;
        }
      }
    }
    if (decay_1 && decay_2){
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

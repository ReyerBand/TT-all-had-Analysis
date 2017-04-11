#include "TTree.h"
#include "TFile.h"

void N_W_slimmer(TString filename, int n, int shift = 0){


  TFile *oldfile= TFile::Open(filename);
  stringstream n_cut;
  n_cut << n << "W_" << shift << "_";
  TString newname;
  string filepath = "root://cmsxrootd.fnal.gov//store/user/rband/ForCutting/";
  if (filename.Contains(filepath)){
    filename.ReplaceAll(filepath, "");
    newname = n_cut.str()+filename;
  }
  else{
    newname = n_cut.str()+filename;
  }
  TTree *oldtree = (TTree*) oldfile->Get("tree_had");
  float n_W_tags = 0;
  float W_tag_SF = 1;
  float total_SF;
  float SF = 1.03; //From 2016 AN in tau21 < 0.55

  if (shift == 1){
    SF+=0.14;
  }
  else if (shift == -1){
    SF-=0.14;
  }

  oldtree->SetBranchAddress("n_W_tags", &(n_W_tags));
  oldtree->SetBranchAddress("W_tag_SF", &(W_tag_SF));
  oldtree->SetBranchAddress("total_SF", &(total_SF));

  TFile *newfile = new TFile(newname, "RECREATE");
  TTree *newtree = oldtree->CloneTree(0);
  int counter = 0;
  Int_t N_entries = oldtree->GetEntriesFast();
  for (int i = 0; i < N_entries; i++){
    oldtree->GetEntry(i);
    if (n_W_tags == n){
      W_tag_SF = (pow(SF, n)) * (pow(1 - SF,2 - n));
      if (n == 1){ W_tag_SF *= 2;}
      total_SF *= W_tag_SF;
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

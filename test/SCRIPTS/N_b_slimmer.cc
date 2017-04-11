#include "TTree.h"
#include "TFile.h"

void N_b_slimmer(TString filename, int n, int shift = 0;){


  TFile *oldfile= TFile::Open(filename);
  stringstream n_cut;
  n_cut << n << "b_" << shift << "_";
  string filepath = "root://cmsxrootd.fnal.gov//store/user/rband/ForCutting/";
  TString newname;
  if (filename.Contains(filepath)){
    filename.ReplaceAll(filepath, "");
    newname = n_cut.str()+filename;
  }
  else{
    newname = n_cut.str()+filename;
  }
  TTree *oldtree = (TTree*) oldfile->Get("tree_had");
  std::vector<float>* b_tag_SF = 0;
  float n_b_tags;
  float total_SF;
  oldtree->SetBranchAddress("n_b_tags", &(n_b_tags));
  oldtree->SetBranchAddress("b_tag_SF", &(b_tag_SF));
  oldtree->SetBranchAddress("total_SF", &(total_SF));

  TFile *newfile = new TFile(newname, "RECREATE");
  TTree *newtree = oldtree->CloneTree(0);
  int counter = 0;
  Int_t N_entries = oldtree->GetEntriesFast();
  for (int i = 0; i < N_entries; i++){
    oldtree->GetEntry(i);
    if (n_b_tags == n){
      if (n == 2){
	total_SF *= ((*b_tag_SF)[0]) * ((*b_tag_SF)[1]);
      }
      if (n == 1){
	total_SF *= ((1 - (*b_tag_SF)[0]) * (*b_tag_SF)[1]) + ((1 - (*b_tag_SF)[1]) * (*b_tag_SF)[0]);
      }
      if (n == 0){
        total_SF *= (1 - (*b_tag_SF)[0]) * (1 - (*b_tag_SF)[1]);
      }
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

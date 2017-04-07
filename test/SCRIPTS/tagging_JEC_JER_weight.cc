#include "TTree.h"
#include "TFile.h"


void tagging_JEC_JER_weight(TString filename, int JEC = 0, int JER = 0, bool Data = false){
  //JEC/JER -1,0,1 is down, nominal, up
  stringstream jecname;
  stringstream jername;
  jecname << JEC;
  jername << JER;
  TString newname;
  string filepath = "root://cmsxrootd.fnal.gov//store/user/rband/ForCutting/";
  TFile *oldfile= TFile::Open(filename);

  if (filename.Contains(filepath)){
    filename.ReplaceAll(filepath,"");
    newname = "JEC_"+jecname.str()+"_JER_"+jername.str()+"_"+filename;
  }
  else{
    newname = "JEC_"+jecname.str()+"_JER_"+jername.str()+"_"+filename;
  }
  cout << "Newname is " << newname << endl;
  TFile *triginfo = new TFile("/uscms_data/d3/rband/TT_Analysis/CMSSW_8_0_6/src/Analysis/TPRIME/test/TriggerEfficiency.root");
  TTree *oldtree = (TTree*) oldfile->Get("b2gntuple/tree_had");
  TH1F *PFHT800_Eff = (TH1F*) triginfo->Get("PFHT800_Efficiency");
  //Declaring the many variables needed from the TTree
  cout << "Before assign" << endl;
  std::vector<float>* jetak8RawPtPuppi = 0;
  oldtree->SetBranchAddress("jetak8RawPtPuppi", &(jetak8RawPtPuppi));
  cout << "First Assign" << endl;
  std::vector<float>* jetak8RawEtaPuppi = 0;
  oldtree->SetBranchAddress("jetak8RawEtaPuppi", &(jetak8RawEtaPuppi));
  std::vector<float>* jetak8RawPhiPuppi = 0;
  oldtree->SetBranchAddress("jetak8RawPhiPuppi", &(jetak8RawPhiPuppi));
  std::vector<float>* jetak8PuppiJERSF = 0;
  oldtree->SetBranchAddress("jetak8PuppiJERSF", &(jetak8PuppiJERSF));
  std::vector<float>* jetak8PuppiJERUp = 0;
  oldtree->SetBranchAddress("jetak8PuppiJERUp", &(jetak8PuppiJERUp));
  std::vector<float>* jetak8PuppiJERDown = 0;
  oldtree->SetBranchAddress("jetak8PuppiJERDown", &(jetak8PuppiJERDown));
  std::vector<float>* jetak8PuppiJECSF = 0;
  oldtree->SetBranchAddress("jetak8PuppiJECSF", &(jetak8PuppiJECSF));
  std::vector<float>* jetak8PuppiJECUncert = 0;
  oldtree->SetBranchAddress("jetak8PuppiJECUncert", &(jetak8PuppiJECUncert));
  std::vector<float>* jetak8Puppisoftmass = 0;
  oldtree->SetBranchAddress("jetak8Puppisoftmass", &(jetak8Puppisoftmass));
  std::vector<float>* jetak8Puppitau1 = 0;
  oldtree->SetBranchAddress("jetak8Puppitau1", &(jetak8Puppitau1));
  std::vector<float>* jetak8Puppitau2 = 0;
  oldtree->SetBranchAddress("jetak8Puppitau2", &(jetak8Puppitau2));
  std::vector<float>* jetak8Puppitau3 = 0;
  oldtree->SetBranchAddress("jetak8Puppitau3", &(jetak8Puppitau3));
  std::vector<float>* jetak8Puppitau21 = 0;
  oldtree->SetBranchAddress("jetak8Puppitau21", &(jetak8Puppitau21));
  std::vector<float>* jetak8Puppitau32 = 0;
  oldtree->SetBranchAddress("jetak8Puppitau32", &(jetak8Puppitau32));
  cout << "here" << endl;
  std::vector<float>* ak8NHEF = 0;
  oldtree->SetBranchAddress("ak8NHEF", &(ak8NHEF));
  std::vector<float>* ak8NEEF = 0;
  oldtree->SetBranchAddress("ak8NEEF", &(ak8NEEF));
  std::vector<float>* ak8CHEF = 0;
  oldtree->SetBranchAddress("ak8CHEF", &(ak8CHEF));
  std::vector<float>* ak8CEEF = 0;
  oldtree->SetBranchAddress("ak8CEEF", &(ak8CEEF));
  std::vector<float>* ak8MEF = 0;
  oldtree->SetBranchAddress("ak8MEF", &(ak8MEF));
  std::vector<float>* ak8CM = 0;
  oldtree->SetBranchAddress("ak8CM", &(ak8CM));
  std::vector<float>* ak8NC = 0;
  oldtree->SetBranchAddress("ak8NC", &(ak8NC));


  std::vector<float>* jetak4RawPtPuppi = 0;
  oldtree->SetBranchAddress("jetak4RawPtPuppi", &(jetak4RawPtPuppi));
  std::vector<float>* jetak4RawEtaPuppi = 0;
  oldtree->SetBranchAddress("jetak4RawEtaPuppi", &(jetak4RawEtaPuppi));
  std::vector<float>* jetak4RawPhiPuppi = 0;
  oldtree->SetBranchAddress("jetak4RawPhiPuppi", &(jetak4RawPhiPuppi));
  std::vector<float>* jetak4RawEPuppi = 0;
  oldtree->SetBranchAddress("jetak4RawEPuppi", &(jetak4RawEPuppi));
  std::vector<float>* jetak4SV0massPuppi = 0;
  oldtree->SetBranchAddress("jetak4SV0massPuppi", &(jetak4SV0massPuppi));
  std::vector<float>* jetak4SV1massPuppi = 0;
  oldtree->SetBranchAddress("jetak4SV1massPuppi", &(jetak4SV1massPuppi));
  std::vector<float>* jetak4PuppiJERSF = 0;
  oldtree->SetBranchAddress("jetak4PuppiJERSF", &(jetak4PuppiJERSF));
  std::vector<float>* jetak4PuppiJERUp = 0;
  oldtree->SetBranchAddress("jetak4PuppiJERUp", &(jetak4PuppiJERUp));
  std::vector<float>* jetak4PuppiJERDown = 0;
  oldtree->SetBranchAddress("jetak4PuppiJERDown", &(jetak4PuppiJERDown));
  std::vector<float>* jetak4PuppiJECSF = 0;
  oldtree->SetBranchAddress("jetak4PuppiJECSF", &(jetak4PuppiJECSF));
  std::vector<float>* jetak4PuppiJECUncert = 0;
  oldtree->SetBranchAddress("jetak4PuppiJECUncert", &(jetak4PuppiJECUncert));
  std::vector<float>* jetak4PuppiCSVv2 = 0;
  oldtree->SetBranchAddress("jetak4PuppiCSVv2", &(jetak4PuppiCSVv2));

  std::vector<float>* ak4NHEF = 0;
  oldtree->SetBranchAddress("ak4NHEF", &(ak4NHEF));
  std::vector<float>* ak4NEEF = 0;
  oldtree->SetBranchAddress("ak4NEEF", &(ak4NEEF));
  std::vector<float>* ak4CHEF = 0;
  oldtree->SetBranchAddress("ak4CHEF", &(ak4CHEF));
  std::vector<float>* ak4CEEF = 0;
  oldtree->SetBranchAddress("ak4CEEF", &(ak4CEEF));
  std::vector<float>* ak4MEF = 0;
  oldtree->SetBranchAddress("ak4MEF", &(ak4MEF));
  std::vector<float>* ak4CM = 0;
  oldtree->SetBranchAddress("ak4CM", &(ak4CM));
  std::vector<float>* ak4NC = 0;
  oldtree->SetBranchAddress("ak4NC", &(ak4NC));
  float Weight;
  oldtree->SetBranchAddress("Weight", &(Weight));


  TFile *newfile = new TFile(newname, "RECREATE");
  TTree *newtree = oldtree->CloneTree(0);

  //Declare all the new branches of variables that are used in the analysis (T' Mass, number of b/W tags etc.)
  std::vector<std::string> listOfNewVars;
  std::vector<std::string> listOfNewVectorVars;
  std::map<std::string, float> newTreeVars;
  std::map<std::string, std::vector<float> > newTreeVectorVars;
  listOfNewVars.push_back("T1_Pt");
  listOfNewVars.push_back("T1_Eta");
  listOfNewVars.push_back("T1_Phi");
  listOfNewVars.push_back("T1_M");

  listOfNewVars.push_back("T2_Pt");
  listOfNewVars.push_back("T2_Eta");
  listOfNewVars.push_back("T2_Phi");
  listOfNewVars.push_back("T2_M");

  listOfNewVars.push_back("TDeltaR");
  listOfNewVars.push_back("TDeltaEta");
  listOfNewVars.push_back("TDeltaPhi");
  listOfNewVars.push_back("TDeltaM");

  listOfNewVars.push_back("W1_Pt");
  listOfNewVars.push_back("W1_Eta");
  listOfNewVars.push_back("W1_Phi");
  listOfNewVars.push_back("W1_M");
  listOfNewVars.push_back("W1_softmass");

  listOfNewVars.push_back("W2_Pt");
  listOfNewVars.push_back("W2_Eta");
  listOfNewVars.push_back("W2_Phi");
  listOfNewVars.push_back("W2_M");
  listOfNewVars.push_back("W2_softmass");

  listOfNewVars.push_back("b1_Pt");
  listOfNewVars.push_back("b1_Eta");
  listOfNewVars.push_back("b1_Phi");
  listOfNewVars.push_back("b1_M");

  listOfNewVars.push_back("b2_Pt");
  listOfNewVars.push_back("b2_Eta");
  listOfNewVars.push_back("b2_Phi");
  listOfNewVars.push_back("b2_M");


  listOfNewVars.push_back("n_b_tags");
  listOfNewVars.push_back("n_W_tags");
  listOfNewVars.push_back("deltaR_1_1");
  listOfNewVars.push_back("deltaR_1_2");
  listOfNewVars.push_back("deltaR_2_1");
  listOfNewVars.push_back("deltaR_2_2");
  listOfNewVars.push_back("deltaR");
  listOfNewVars.push_back("HT_ak8");
  listOfNewVars.push_back("HT_ak4");
  listOfNewVars.push_back("QCD_Weight");
  listOfNewVars.push_back("QCD_Sample");
  listOfNewVars.push_back("W_tag_SF");
  listOfNewVars.push_back("total_SF");

  listOfNewVectorVars.push_back("ak8pt");
  listOfNewVectorVars.push_back("ak8Eta");
  listOfNewVectorVars.push_back("ak8Phi");
  listOfNewVectorVars.push_back("ak8Mass");
  listOfNewVectorVars.push_back("tau21");
  listOfNewVectorVars.push_back("softmass");

  listOfNewVectorVars.push_back("ak4pt");
  listOfNewVectorVars.push_back("ak4Eta");
  listOfNewVectorVars.push_back("ak4Phi");
  listOfNewVectorVars.push_back("ak4Mass");
  listOfNewVectorVars.push_back("CSV");
  listOfNewVectorVars.push_back("b_tag_SF");

  for (unsigned i = 0; i < listOfNewVars.size(); i++){
    newTreeVars[ listOfNewVars[i] ] = -999.99;
    newtree->Branch( (listOfNewVars[i]).c_str() , &(newTreeVars[ listOfNewVars[i] ]), (listOfNewVars[i]+"/F").c_str() );
  }

  std::vector<float> filler;
  filler.push_back(-999.99);
  for (unsigned i = 0; i < listOfNewVectorVars.size(); i++){
    newTreeVectorVars[ listOfNewVectorVars[i] ] = filler;
    newtree->Branch( (listOfNewVectorVars[i]).c_str() , &(newTreeVectorVars[ listOfNewVectorVars[i] ]));
  }


  int counter = 0;
  Int_t N_entries = oldtree->GetEntriesFast();
 
  for (int i = 0; i < N_entries; i++){
    oldtree->GetEntry(i);
    float N_W = 0;
    float N_b = 0;
    int b1_index = -1;
    int b2_index = -1;
    int W1_index = -1;
    int W2_index = -1;
    float deltaR_1_1;
    float deltaR_1_2;
    float deltaR_2_1;
    float deltaR_2_2;
    float HT_ak8 = 0;
    float HT_ak4 = 0;
    bool separated_jets = false;
    bool pre_selection_passed = false;
    TLorentzVector W1, W2, b1, b2, b3, b4, b5, b6, T1, T2, temp1;


    std::vector<float> *ak8pt = new std::vector<float>;
    std::vector<float> *ak8Eta = new std::vector<float>;
    std::vector<float> *ak8Phi = new std::vector<float>;
    std::vector<float> *ak8Mass = new std::vector<float>;

    std::vector<float> *ak4pt = new std::vector<float>;
    std::vector<float> *ak4Eta = new std::vector<float>;
    std::vector<float> *ak4Phi = new std::vector<float>;
    std::vector<float> *ak4E = new std::vector<float>;
    std::vector<float> *ak4Mass = new std::vector<float>;
    std::vector<float> *softmass = new std::vector<float>;
    std::vector<float> *tau21 = new std::vector<float>;
    std::vector<float> *CSV = new std::vector<float>;
    std::vector<float> *b_tag_SF = new std::vector<float>;


    float ak8PtPuppi;
    float ak4PtPuppi;
    float ak4EPuppi;
    for (int i = 0; i < (*jetak8RawPtPuppi).size(); i++){
      if ((((*ak8NHEF)[i] < 0.99) && ((*ak8NEEF)[i] < 0.99) && ((*ak8NC)[i] > 1)) && (((abs((*jetak8RawEtaPuppi)[i]) <= 2.4) && ( (*ak8CHEF)[i] > 0) && ((*ak8CM)[i] > 0) && ((*ak8CEEF)[i] < 0.99)) || (abs((*jetak8RawEtaPuppi)[i]) > 2.4)) && (abs((*jetak8RawEtaPuppi)[i]) <= 2.7)){ //Jet ID cut (loose) 
	//Applying JEC and JER as determined in the options.  Cutting out jets shifted below 20 GeV
	ak8PtPuppi = ((*jetak8PuppiJECSF)[i])*((*jetak8RawPtPuppi)[i]);
	if (JEC == 1){ak8PtPuppi *= (1+(*jetak8PuppiJECUncert)[i]);}
	if (JEC == -1){ak8PtPuppi *= (1-(*jetak8PuppiJECUncert)[i]);}
	if (JER == 0){    ak8PtPuppi *= (*jetak8PuppiJERSF)[i];}
	if (JER == 1){    ak8PtPuppi *= (*jetak8PuppiJERUp)[i];}
	if (JER == -1){    ak8PtPuppi *= (*jetak8PuppiJERDown)[i];}
	if (ak8PtPuppi >= 20){
	  ak8pt->push_back(ak8PtPuppi);
	  ak8Eta->push_back((*jetak8RawEtaPuppi)[i]);
	  ak8Phi->push_back((*jetak8RawPhiPuppi)[i]);
	  ak8Mass->push_back((*jetak8Puppisoftmass)[i]);
	  tau21->push_back((*jetak8Puppitau21)[i]);
	  softmass->push_back((*jetak8Puppisoftmass)[i]);
	}
      }
    }
    for (int i = 0; i < (*jetak4RawPtPuppi).size(); i++){
      if ((((*ak4NHEF)[i] < 0.99) && ((*ak4NEEF)[i] < 0.99) && ((*ak4NC)[i] > 1)) && (((abs((*jetak4RawEtaPuppi)[i]) <= 2.4) && ( (*ak4CHEF)[i] > 0) && ((*ak4CM)[i] > 0) && ((*ak4CEEF)[i] < 0.99)) || (abs((*jetak4RawEtaPuppi)[i]) > 2.4)) && (abs((*jetak4RawEtaPuppi)[i]) <= 2.7)){
	ak4PtPuppi = ((*jetak4PuppiJECSF)[i])*((*jetak4RawPtPuppi)[i]);
        ak4EPuppi = ((*jetak4PuppiJECSF)[i])*((*jetak4RawEPuppi)[i]);
	if (JEC == 1){
	  ak4PtPuppi *= (1+(*jetak4PuppiJECUncert)[i]);
          ak4EPuppi *= (1+(*jetak4PuppiJECUncert)[i]);
	}
	if (JEC == -1){
	  ak4PtPuppi *= (1-(*jetak4PuppiJECUncert)[i]);
          ak4EPuppi *= (1-(*jetak4PuppiJECUncert)[i]);
	}
	if (JER == 0){
	  ak4PtPuppi *= (*jetak4PuppiJERSF)[i];
          ak4EPuppi *= (*jetak4PuppiJERSF)[i];
	}
	if (JER == 1){
	  ak4PtPuppi *= (*jetak4PuppiJERUp)[i];
          ak4EPuppi *= (*jetak4PuppiJERUp)[i];
	}
	if (JER == -1){
	  ak4PtPuppi *= (*jetak4PuppiJERDown)[i];
          ak4EPuppi *= (*jetak4PuppiJERDown)[i];
	}
        if (ak4PtPuppi >= 20){
	  ak4pt->push_back(ak4PtPuppi);
	  ak4E->push_back(ak4EPuppi);
	  ak4Eta->push_back((*jetak4RawEtaPuppi)[i]);
	  ak4Phi->push_back((*jetak4RawPhiPuppi)[i]);
	  ak4Mass->push_back((*jetak4SV0massPuppi)[i]);
	  CSV->push_back((*jetak4PuppiCSVv2)[i]);
	}
      }
    }

    //Now implementing the tagging.  Only saves leading 2 W and b jets. We later select on 2W and 0,1,2 b-tags  
    //First, determine if there are 2 W ak8 jets in the sample.
    //Then, look for 2 ak4 jets passing CSV cut.  If not enough W's or b's, take the leading resolved ak8/ak4 that is seperated from the tagged jets.

    if ((ak8pt->size() > 1) && (ak4pt->size() > 1)){
      if ((ak8pt->at(0) > 200) && (ak8pt->at(1) > 200) && ((abs((*ak8Eta)[0])) < 2.4) && ((abs((*ak8Eta)[1])) < 2.4) && (ak4pt->at(0) > 30) && (ak4pt->at(1) > 30) && ((abs((*ak4Eta)[0])) < 2.4) && ((abs((*ak4Eta)[1])) < 2.4)){
	pre_selection_passed = true;
      }
    }
    if (pre_selection_passed){
      for (int i = 0; i < ak8pt->size(); i++){
	HT_ak8+= ak8pt->at(i);
	if ((i == 0) || (i == 1)){
	  if ((tau21->at(i) < 0.55) && (softmass->at(i) > 65) && (softmass->at(i) < 105)){
	    N_W++;
	    if (N_W == 1){
	      W1_index = i;
	      W1.SetPtEtaPhiM(ak8pt->at(i), (*ak8Eta)[i], (*ak8Phi)[i], (*ak8Mass)[i]);
	    }
	    if (N_W == 2){
	      W2_index= i;
	      W2.SetPtEtaPhiM(ak8pt->at(i), (*ak8Eta)[i], (*ak8Phi)[i], (*ak8Mass)[i]);
	    }
	  }
	}
      }
      if (N_W == 0){
	W1.SetPtEtaPhiM(ak8pt->at(0), (*ak8Eta)[0], (*ak8Phi)[0], (*ak8Mass)[0]);
        W2.SetPtEtaPhiM(ak8pt->at(1), (*ak8Eta)[1], (*ak8Phi)[1], (*ak8Mass)[1]);
      }
      if (N_W == 1){
	if (W1_index ==0){
	  W2.SetPtEtaPhiM(ak8pt->at(1), (*ak8Eta)[1], (*ak8Phi)[1], (*ak8Mass)[1]);
	}
	else{
	  W2.SetPtEtaPhiM(ak8pt->at(0), (*ak8Eta)[0], (*ak8Phi)[0], (*ak8Mass)[0]);
	}
      }
      int n_b_considered = 0; //Want to avoid tagging all ak4s, since the inefficiency makes the SF quite large
      for (int i = 0; i < ak4pt->size(); i++){
        HT_ak4+= ak4pt->at(i);
	temp1.SetPtEtaPhiM(ak4pt->at(i), (*ak4Eta)[i], (*ak4Phi)[i], (*ak4Mass)[i]);
	if ((W1.DeltaR(temp1) > 0.8) && (W2.DeltaR(temp1) > 0.8) && (n_b_considered < 2)){
	  n_b_considered++;
	  if (CSV->at(i) > 0.8484){
	    N_b++;
	    if (N_b == 1){
	      b1_index = i;
	      b1.SetPtEtaPhiE(ak4pt->at(i), (*ak4Eta)[i], (*ak4Phi)[i], ak4E->at(i));
	      b_tag_SF->push_back(0.561694*((1.+(0.31439*b1.Pt()))/(1.+(0.17756*b1.Pt()))));
	    }
	    if (N_b == 2){
	      b2.SetPtEtaPhiE(ak4pt->at(i), (*ak4Eta)[i], (*ak4Phi)[i], ak4E->at(i));
	      b_tag_SF->push_back(0.561694*((1.+(0.31439*b2.Pt()))/(1.+(0.17756*b2.Pt()))));
	    }
	  }
	}  
      }
      if (N_b == 0){
	int jet_count = 0;
	for (int i = 0; i < ak4pt->size(); i++){
	  temp1.SetPtEtaPhiE(ak4pt->at(i), (*ak4Eta)[i], (*ak4Phi)[i], ak4E->at(i));
	  if ((W1.DeltaR(temp1) > 0.8) && (W2.DeltaR(temp1) > 0.8) && (jet_count < 2)){
	    jet_count++;
	    if (jet_count == 1){
	      b1.SetPtEtaPhiE(ak4pt->at(i), (*ak4Eta)[i], (*ak4Phi)[i], ak4E->at(i));
	      b_tag_SF->push_back(0.561694*((1.+(0.31439*b1.Pt()))/(1.+(0.17756*b1.Pt()))));
	    }
            if (jet_count == 2){
              b2.SetPtEtaPhiE(ak4pt->at(i), (*ak4Eta)[i], (*ak4Phi)[i], ak4E->at(i));
              b_tag_SF->push_back(0.561694*((1.+(0.31439*b2.Pt()))/(1.+(0.17756*b2.Pt()))));
            }
	  }
	}
      }
      if (N_b == 1){
	bool b2_found = false;
	for (int i = 0; i < ak4pt->size(); i++){
	  temp1.SetPtEtaPhiE(ak4pt->at(i), (*ak4Eta)[i], (*ak4Phi)[i], ak4E->at(i));
	  if ((W1.DeltaR(temp1) > 0.8) && (W2.DeltaR(temp1) > 0.8) && (b1_index != i) && !(b2_found)){
	    b2_found = true;
	    b2.SetPtEtaPhiE(ak4pt->at(i), (*ak4Eta)[i], (*ak4Phi)[i], ak4E->at(i));
	    b_tag_SF->push_back(0.561694*((1.+(0.31439*b2.Pt()))/(1.+(0.17756*b2.Pt()))));
	  }
	}
      }

      newTreeVars["W1_Pt"] = W1.Pt();
      newTreeVars["W1_Eta"] = W1.Eta();
      newTreeVars["W1_Phi"] = W1.Phi();
      newTreeVars["W1_M"] = W1.M();
      newTreeVars["W2_Pt"] = W2.Pt();
      newTreeVars["W2_Eta"] = W2.Eta();
      newTreeVars["W2_Phi"] = W2.Phi();
      newTreeVars["W2_M"] = W2.M();
      newTreeVars["b1_Pt"] = b1.Pt();
      newTreeVars["b1_Eta"] = b1.Eta();
      newTreeVars["b1_Phi"] = b1.Phi();
      newTreeVars["b1_M"] = b1.M();
      newTreeVars["b2_Pt"] = b2.Pt();
      newTreeVars["b2_Eta"] = b2.Eta();
      newTreeVars["b2_Phi"] = b2.Phi();
      newTreeVars["b2_M"] = b2.M();

      //Checking kinematics and separation again, probably unnecessary 
      if ((W1.Pt() > 200) && (W2.Pt() > 200) && (b1.Pt() > 30) && (b2.Pt() > 30) && (abs(W1.Eta()) < 2.4) && (abs(W2.Eta()) < 2.4) && (abs(b1.Eta()) < 2.4) && (abs(b2.Eta()) < 2.4)){
	newTreeVars["n_W_tags"] = N_W;
	newTreeVars["n_b_tags"] = N_b;

	deltaR_1_1 = abs(W1.DeltaR(b1));
	deltaR_1_2 = abs(W1.DeltaR(b2));
	deltaR_2_1 = abs(W2.DeltaR(b1));
	deltaR_2_2 = abs(W2.DeltaR(b2));


	newTreeVars["deltaR_1_1"] = deltaR_1_1;
	newTreeVars["deltaR_1_2"] = deltaR_1_2;
	newTreeVars["deltaR_2_1"] = deltaR_2_1;
	newTreeVars["deltaR_2_2"] = deltaR_2_2;
	  
	  
	if((deltaR_1_1 > 0.8) && (deltaR_1_2 > 0.8) && (deltaR_2_1 > 0.8) && (deltaR_2_2 > 0.8)){
	  separated_jets = true;
	}
      }
    
      if (separated_jets){
	TLorentzVector TCandidate1_1 = b1+W1;
	TLorentzVector TCandidate1_2 = b1+W2;
	TLorentzVector TCandidate2_1 = b2+W1;
	TLorentzVector TCandidate2_2 = b2+W2;

	if (abs(TCandidate1_1.M() - TCandidate2_2.M()) < abs(TCandidate1_2.M() - TCandidate2_1.M())){
	  T1 = TCandidate1_1;
	  T2 = TCandidate2_2;
	}
	else {
	  T1 = TCandidate1_2;
	  T2 = TCandidate2_1;
	}

	newTreeVectorVars["ak8pt"] = (*ak8pt);
        newTreeVectorVars["ak8Eta"] = (*ak8Eta);
        newTreeVectorVars["ak8Phi"] = (*ak8Phi);
        newTreeVectorVars["ak8Mass"] = (*ak8Mass);
        newTreeVectorVars["ak4pt"] = (*ak4pt);
        newTreeVectorVars["ak4Eta"] = (*ak4Eta);
        newTreeVectorVars["ak4Phi"] = (*ak4Phi);
        newTreeVectorVars["ak4Mass"] = (*ak4Mass);
        newTreeVectorVars["tau21"] = (*tau21);
        newTreeVectorVars["softmass"] = (*softmass);
        newTreeVectorVars["CSV"] = (*CSV);
	newTreeVectorVars["b_tag_SF"] = (*b_tag_SF);

	newTreeVars["total_SF"] = 1;
	newTreeVars["W_tag_SF"] = 1;
	newTreeVars["T1_Pt"] = T1.Pt();
	newTreeVars["T1_Eta"] = T1.Eta();
	newTreeVars["T1_Phi"] = T1.Phi();
	newTreeVars["T1_M"] = T1.M();
	newTreeVars["T2_Pt"] = T2.Pt();
	newTreeVars["T2_Eta"] = T2.Eta();
	newTreeVars["T2_Phi"] = T2.Phi();
	newTreeVars["T2_M"] = T2.M();
	newTreeVars["TDeltaR"] = T1.DeltaR(T2);
	newTreeVars["TDeltaPhi"] = abs(T1.Phi() - T2.Phi());
	newTreeVars["TDeltaEta"] = abs(T1.Eta() - T2.Eta());
	newTreeVars["TDeltaM"] = abs(2*(T1.M() - T2.M())/(T1.M() + T2.M())); //Maybe remove 2?

	//Playing with various HT definitions, need to be consistent between pre-selection definition of HT
	newTreeVars["HT_ak8"] = HT_ak8;
	newTreeVars["HT_ak4"] = HT_ak4;
	if (!Data){
	  int index = PFHT800_Eff->FindBin(HT_ak8);
	  Weight *= PFHT800_Eff->GetBinContent(index);
	}
	//This is the efficiency for the OR of PFHT800 and the TRIM jet 50 trigger
	//Here, I'm storing the scaling for the QCDs as part of the event weight, so that all the QCD files can be combined after selection.
	if (filename.Contains("QCD")){
	  double sigma_QCD_HT_100to200 = 27540000;
	  double sigma_QCD_HT_200to300 = 1717000;
	  double sigma_QCD_HT_300to500 = 351300;
	  //Now has matching efficiency
	  double sigma_QCD_HT_500to700 = 31630;
	  double sigma_QCD_HT_700to1000 = 6802;
	  double sigma_QCD_HT_1000to1500 = 1206;
	  double sigma_QCD_HT_1500to2000 = 120.4;
	  double sigma_QCD_HT_2000toInf = 25.25;

	  double N_QCD_HT_100to200 = 81672890;
	  double N_QCD_HT_200to300 = 18523829;
	  double N_QCD_HT_300to500 = 17035891;

	  double N_QCD_HT_500to700 = 18929951;
	  double N_QCD_HT_700to1000 = 15629253;
	  double N_QCD_HT_1000to1500 = 4767100;
	  double N_QCD_HT_1500to2000 = 3970819;
	  double N_QCD_HT_2000toInf = 1991645;

	  double QCD_HT_100to200_weight = sigma_QCD_HT_100to200/N_QCD_HT_100to200;
	  double QCD_HT_200to300_weight = sigma_QCD_HT_200to300/N_QCD_HT_200to300;
	  double QCD_HT_300to500_weight = sigma_QCD_HT_300to500/N_QCD_HT_300to500;
	  double QCD_HT_500to700_weight = sigma_QCD_HT_500to700/N_QCD_HT_500to700;
	  double QCD_HT_700to1000_weight =  sigma_QCD_HT_700to1000/N_QCD_HT_700to1000;
	  double QCD_HT_1000to1500_weight =  sigma_QCD_HT_1000to1500/N_QCD_HT_1000to1500;
	  double QCD_HT_1500to2000_weight =  sigma_QCD_HT_1500to2000/N_QCD_HT_1500to2000;
	  double QCD_HT_2000toInf_weight =  sigma_QCD_HT_2000toInf/N_QCD_HT_2000toInf;

          double sigma_QCD_Pt_170to300 = 117276;
          double sigma_QCD_Pt_300to470 = 7823;
          double sigma_QCD_Pt_470to600 = 648.2;
          double sigma_QCD_Pt_600to800 = 186.9;
          double sigma_QCD_Pt_800to1000 = 32.293;
          double sigma_QCD_Pt_1000to1400 = 9.4183;
          double sigma_QCD_Pt_1400to1800 = 0.84265;
          double sigma_QCD_Pt_1800to2400 = 0.114943;
          double sigma_QCD_Pt_2400to3200 = 0.00682981;
          double sigma_QCD_Pt_3200toInf = 0.000165445;

          double N_QCD_Pt_170to300 = 7838066;
          double N_QCD_Pt_300to470 = 18253032;
          double N_QCD_Pt_470to600 = 15458074;
          double N_QCD_Pt_600to800 =  19324269;
          double N_QCD_Pt_800to1000 = 15704980;
          double N_QCD_Pt_1000to1400 = 6982586;
          double N_QCD_Pt_1400to1800 = 2477018;
          double N_QCD_Pt_1800to2400 = 1552064;
          double N_QCD_Pt_2400to3200 = 596904;
          double N_QCD_Pt_3200toInf = 391735;

	  double QCD_Pt_170to300_weight = sigma_QCD_Pt_170to300/N_QCD_Pt_170to300;
          double QCD_Pt_300to470_weight = sigma_QCD_Pt_300to470/N_QCD_Pt_300to470;
          double QCD_Pt_470to600_weight = sigma_QCD_Pt_470to600/N_QCD_Pt_470to600;
          double QCD_Pt_600to800_weight = sigma_QCD_Pt_600to800/N_QCD_Pt_600to800;
          double QCD_Pt_800to1000_weight = sigma_QCD_Pt_800to1000/N_QCD_Pt_800to1000;
          double QCD_Pt_1000to1400_weight = sigma_QCD_Pt_1000to1400/N_QCD_Pt_1000to1400;
          double QCD_Pt_1400to1800_weight = sigma_QCD_Pt_1400to1800/N_QCD_Pt_1400to1800;
          double QCD_Pt_1800to2400_weight = sigma_QCD_Pt_1800to2400/N_QCD_Pt_1800to2400;
          double QCD_Pt_2400to3200_weight = sigma_QCD_Pt_2400to3200/N_QCD_Pt_2400to3200;
          double QCD_Pt_3200toInf_weight = sigma_QCD_Pt_3200toInf/N_QCD_Pt_3200toInf;


	  //These weights need to be scaled by the luminosity when plotted (other samples will not)
	  if (filename.Contains("HT_100to200") ){
	    newTreeVars["QCD_Weight"] = QCD_HT_100to200_weight;
	    newTreeVars["QCD_Sample"] = 1;
	  }
	  if (filename.Contains("HT_200to300") ){
	    newTreeVars["QCD_Weight"] = QCD_HT_200to300_weight;
            newTreeVars["QCD_Sample"] = 2;
	  }
	  if (filename.Contains("HT_300to500") ){
	    newTreeVars["QCD_Weight"] = QCD_HT_300to500_weight;
            newTreeVars["QCD_Sample"] = 3;
	  }
	  if (filename.Contains("HT_500to700") ){
	    newTreeVars["QCD_Weight"] = QCD_HT_500to700_weight;
            newTreeVars["QCD_Sample"] = 4;
	  }
	  if (filename.Contains("HT_700to1000") ){
	    newTreeVars["QCD_Weight"] = QCD_HT_700to1000_weight;
            newTreeVars["QCD_Sample"] = 5;
	  }
	  if (filename.Contains("HT_1000to1500") ){
	    newTreeVars["QCD_Weight"] = QCD_HT_1000to1500_weight;
            newTreeVars["QCD_Sample"] = 6;
	  }
	  if (filename.Contains("HT_1500to2000") ){
	    newTreeVars["QCD_Weight"] = QCD_HT_1500to2000_weight;
            newTreeVars["QCD_Sample"] = 7;
	  }
	  if (filename.Contains("HT_2000toInf") ){
	    newTreeVars["QCD_Weight"] = QCD_HT_2000toInf_weight;
            newTreeVars["QCD_Sample"] = 8;
	  }

          if (filename.Contains("Pt_170to300") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_170to300_weight;
            newTreeVars["QCD_Sample"] = 1;
          }
          if (filename.Contains("Pt_300to470") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_300to470_weight;
            newTreeVars["QCD_Sample"] = 2;
          }
          if (filename.Contains("Pt_470to600") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_470to600_weight;
            newTreeVars["QCD_Sample"] = 3;
          }
          if (filename.Contains("Pt_600to800") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_600to800_weight;
            newTreeVars["QCD_Sample"] = 4;
          }
          if (filename.Contains("Pt_800to1000") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_800to1000_weight;
            newTreeVars["QCD_Sample"] = 5;
          }
          if (filename.Contains("Pt_1000to1400") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_1000to1400_weight;
            newTreeVars["QCD_Sample"] = 6;
          }
          if (filename.Contains("Pt_1400to1800") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_1400to1800_weight;
            newTreeVars["QCD_Sample"] = 7;
          }
          if (filename.Contains("Pt_1800to2400") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_1800to2400_weight;
            newTreeVars["QCD_Sample"] = 8;
          }
          if (filename.Contains("Pt_2400to3200") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_2400to3200_weight;
            newTreeVars["QCD_Sample"] = 9;
          }
          if (filename.Contains("Pt_3200toInf") ){
            newTreeVars["QCD_Weight"] = QCD_Pt_3200toInf_weight;
            newTreeVars["QCD_Sample"] = 10;
          }



	}
	newtree->Fill(); 
	counter++;
      }
    }
  
    delete ak8pt;
    delete ak8Eta;
    delete ak8Phi;
    delete ak8Mass;
    delete ak4pt;
    delete ak4Eta;
    delete ak4Phi;
    delete ak4Mass;
    delete ak4E;
    delete softmass;
    delete CSV;
    delete tau21;
    delete b_tag_SF;
  }

  newfile->cd();
  cout << "Original Entries " << N_entries << endl;
  cout << "Slimmed Entries " << counter << endl;
  newtree->Print();
  newtree->AutoSave();
  newfile->Write();
  newfile->Close();
}

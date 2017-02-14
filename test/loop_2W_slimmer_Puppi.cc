#include "TTree.h"
#include "TFile.h"
#include<sstream>

void loop_2W_slimmer(){
  for (int i = -1; i < 2; i++){
      string jec;
      string jer;
      stringstream sjec;
      stringstream sjer;
      sjec << i;
      jec += sjec.str();
      jer = "0";
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_QCD_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_800_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_900_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1000_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1100_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1200_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1300_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1400_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1500_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1600_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1700_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_ttbar_Puppi.root");
      _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_WJets_Puppi.root");
      sjec.clear();
      sjer.clear();
      jec = "";
      jer = "";
  }
  for (int i = -1; i < 2; i++){
    string jec;
    string jer;
    stringstream sjec;
    stringstream sjer;
    sjer << i;
    jer += sjer.str();
    jec = "0";
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_QCD_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_800_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_900_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1000_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1100_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1200_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1300_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1400_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1500_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1600_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_TprimeTprime_1700_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_ttbar_Puppi.root");
    _2W_slimmer("FullCut_JEC_"+jec+"_JER_"+jer+"_WJets_Puppi.root");
    sjec.clear();
    sjer.clear();
    jec = "";
    jer = "";
  }
}

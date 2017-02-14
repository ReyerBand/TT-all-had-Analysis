#include "TTree.h"
#include "TFile.h"
#include<sstream>

void loop_2W_slimmer(int JEC = 0, int JER = 0){  
  _2W_slimmer("FullCut_JEC_0_JER_0_QCD.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_800.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_900.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_1000.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_1100.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_1200.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_1300.root"); 
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_1400.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_1500.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_1600.root");
  _2W_slimmer("genfiltered_2WbFullCut_JEC_0_JER_0_TprimeTprime_1700.root");
  //  _2W_slimmer("FullCut_JEC_0_JER_0_ttbar.root");
  _2W_slimmer("FullCut_JEC_0_JER_0_WJets.root");
}

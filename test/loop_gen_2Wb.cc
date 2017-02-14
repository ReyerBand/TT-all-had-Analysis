#include "TTree.h"
#include "TFile.h"
#include<sstream>

void loop_gen_2Wb(int JEC = 0, int JER = 0){
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_800.root");
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_900.root");
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_1000.root");
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_1100.root");
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_1200.root");
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_1300.root");  
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_1400.root");
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_1500.root");
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_1600.root");
  gen_selector("FullCut_JEC_0_JER_0_TprimeTprime_1700.root");
}

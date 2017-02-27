#include "TTree.h"
#include "TFile.h"
#include<sstream>

void loop_tagging(int JEC = 0, int JER = 0){    
  //  tagging_JEC_JER_weight("QCD_500to700.root", JEC, JER);
  tagging_JEC_JER_weight("QCD_700to1000.root", JEC, JER);
  tagging_JEC_JER_weight("QCD_1000to1500.root", JEC, JER);
  tagging_JEC_JER_weight("QCD_1500to2000.root", JEC, JER);
  tagging_JEC_JER_weight("QCD_2000toInf.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_800.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_900.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_1000.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_1100.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_1200.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_1300.root", JEC, JER); 
  tagging_JEC_JER_weight("TprimeTprime_1400.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_1500.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_1600.root", JEC, JER);
  tagging_JEC_JER_weight("TprimeTprime_1700.root", JEC, JER);
  //  tagging_JEC_JER_weight("ttbar.root", JEC, JER);
  tagging_JEC_JER_weight("WJets.root", JEC, JER);
  
}

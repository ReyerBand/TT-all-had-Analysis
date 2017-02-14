#include "TTree.h"
#include "TFile.h"
#include<sstream>

void loop_selector_Puppi(int JEC = 0, int JER = 0){  
  FullSelectionMC_Puppi("QCD_500to700.root", JEC, JER);
  FullSelectionMC_Puppi("QCD_700to1000.root", JEC, JER);
  FullSelectionMC_Puppi("QCD_1000to1500.root", JEC, JER);
  FullSelectionMC_Puppi("QCD_1500to2000.root", JEC, JER);
  FullSelectionMC_Puppi("QCD_2000toInf.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_800.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_900.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_1000.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_1100.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_1200.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_1300.root", JEC, JER); 
  FullSelectionMC_Puppi("TprimeTprime_1400.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_1500.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_1600.root", JEC, JER);
  FullSelectionMC_Puppi("TprimeTprime_1700.root", JEC, JER);
  //  FullSelectionMC_Puppi("ttbar.root", JEC, JER);
  FullSelectionMC_Puppi("WJets.root", JEC, JER);
}

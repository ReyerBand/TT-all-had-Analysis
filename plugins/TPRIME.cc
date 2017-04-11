// -*- C++ -*-
//
// Package:    Analysis/TPRIME
// Class:      TPRIME
// 
/**\class TPRIME TPRIME.cc Analysis/TPRIME/plugins/TPRIME.cc

   Description: [one line class summary]

   Implementation:
   [Notes on implementation]
*/
//
// Original Author:  reyer band
//         Created:  Mon, 10 Oct 2016 11:51:32 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include <TTree.h>
#include <TSystem.h>
#include <TLorentzVector.h>
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include <memory>
#include <iostream>
#include <fstream>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Common/interface/TriggerNames.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "TTree.h"
#include "TLorentzVector.h"
#include "SimDataFormats/GeneratorProducts/interface/GenEventInfoProduct.h"

#include "CondFormats/JetMETObjects/interface/JetCorrectorParameters.h"
#include "CondFormats/JetMETObjects/interface/JetCorrectionUncertainty.h"
#include "CondFormats/JetMETObjects/interface/FactorizedJetCorrector.h"
#include "JetMETCorrections/Modules/interface/JetResolution.h"

using namespace std;
using namespace edm;
using namespace reco;
//
// class declaration
//

// If the analyzer does not use TFileService, please remove
// the template argument to the base class so the class inherits
// from  edm::one::EDAnalyzer<> and also remove the line from
// constructor "usesResource("TFileService");"
// This will improve performance in multithreaded jobs.

class TPRIME : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
public:
  explicit TPRIME(const edm::ParameterSet&);
  ~TPRIME();

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


private:
  virtual void beginJob() override;
  virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
  virtual void endJob() override;

  // ----------member data ---------------------------
  TTree *tree_had;
  TTree *tree_gen;
  std::vector<std::string> listOfHadVars;
  std::vector<std::string> listOfGenVars;
  std::map<std::string, std::vector<float>> hadTreeVars;
  std::map<std::string, std::vector<float>> genTreeVars;

  double JECshift_;
  double JERshift_;
  bool Data;
  bool Signal_MC;
  bool Puppi;
  string L1AK8file;
  string L2AK8file;
  string L3AK8file;
  string ResJetAK8file;
  string L1AK4file;
  string L2AK4file;
  string L3AK4file;
  string ResJetAK4file;
  string AK8UncertFile;
  string AK4UncertFile;

  edm::EDGetTokenT<GenEventInfoProduct> generatorToken_;
  //Trigger Info
  edm::EDGetTokenT<std::vector<float> > triggerBitTreeToken_;
  edm::EDGetTokenT<std::vector<string> > triggerNameTreeToken_;
  edm::EDGetTokenT<std::vector<float> > METBitTreeToken_;
  edm::EDGetTokenT<std::vector<string> > METNameTreeToken_;

  edm::EDGetTokenT<unsigned int> evtInfoRunNumberToken_;
  edm::EDGetTokenT<ULong64_t> evtInfoEventNumberToken_;


  //For JER
  edm::EDGetTokenT<double> RhoToken_;
  //Gen ID 
  edm::EDGetTokenT<std::vector<float> > PartIDToken_;
  edm::EDGetTokenT<std::vector<float> > PartPtToken_;
  edm::EDGetTokenT<std::vector<float> > PartStatusToken_;
  edm::EDGetTokenT<std::vector<float> > PartMom0IDToken_;
  edm::EDGetTokenT<std::vector<float> > PartMom1IDToken_;
  edm::EDGetTokenT<std::vector<float> > PartDau0IDToken_;
  edm::EDGetTokenT<std::vector<float> > PartDau1IDToken_;
  edm::EDGetTokenT<vector<reco::GenParticle> > GenParticleToken_;
  //Jet Stuff
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetPtToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetPhiToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetEtaToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetEToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjettrimmedMassToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetAreaToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetCSVv2Token_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetsoftMassToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSsubjetIndex0Token_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSsubjetIndex1Token_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjettau1Token_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjettau2Token_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjettau3Token_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetneutralHadronEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetneutralEmEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetchargedHadronEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetMuonEnergyToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetchargedMultiplicityToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetneutralMultiplicityToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetchargedEmEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetNumConstituentsToken_;

  //AK8CHS Gen Jet info                                                                                                                                                        

  edm::EDGetTokenT<std::vector<float> > ak8CHSGenjetPtToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSGenjetPhiToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSGenjetEtaToken_;

  //AK8 Puppi 
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetPtToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetPhiToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetEtaToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetEToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetAreaToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetCSVv2Token_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetsoftMassToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijettrimmedMassToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppisubjetIndex0Token_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppisubjetIndex1Token_;
  edm::EDGetTokenT<std::vector<float> > ak8Puppijettau1Token_;
  edm::EDGetTokenT<std::vector<float> > ak8Puppijettau2Token_;
  edm::EDGetTokenT<std::vector<float> > ak8Puppijettau3Token_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetneutralHadronEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetneutralEmEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetchargedHadronEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetMuonEnergyToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetchargedMultiplicityToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetneutralMultiplicityToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetchargedEmEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetNumConstituentsToken_;

  //AK8Puppi Gen data                                                                                                                                                                                             

  edm::EDGetTokenT<std::vector<float> > ak8PuppiGenjetPtToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppiGenjetPhiToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppiGenjetEtaToken_;


  //AK4CHS                                                                                                                                                 
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetPtToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetPhiToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetEtaToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetEToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetSV0massToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetSV1massToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetAreaToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetCSVv2Token_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSsubjetIndex0Token_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSsubjetIndex1Token_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjettau1Token_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjettau2Token_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjettau3Token_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetneutralHadronEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetneutralEmEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetchargedHadronEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetMuonEnergyToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetchargedMultiplicityToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetneutralMultiplicityToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetchargedEmEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetNumConstituentsToken_;

  //AK4CHS Gen data                                                                                                                                                        

  edm::EDGetTokenT<std::vector<float> > ak4CHSGenjetPtToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSGenjetPhiToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSGenjetEtaToken_;



  edm::EDGetTokenT<std::vector<float> > ak4PuppijetPtToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetPhiToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetEtaToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetEToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetSV0massToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetSV1massToken_;

  edm::EDGetTokenT<std::vector<float> > ak4PuppijetAreaToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetCSVv2Token_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppisubjetIndex0Token_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppisubjetIndex1Token_;
  edm::EDGetTokenT<std::vector<float> > ak4Puppijettau1Token_;
  edm::EDGetTokenT<std::vector<float> > ak4Puppijettau2Token_;
  edm::EDGetTokenT<std::vector<float> > ak4Puppijettau3Token_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetneutralHadronEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetneutralEmEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetchargedHadronEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetMuonEnergyToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetchargedMultiplicityToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetneutralMultiplicityToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetchargedEmEnergyFracToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetNumConstituentsToken_;
  //AK4Puppi Gen data                                                                                                                                                                                      

  edm::EDGetTokenT<std::vector<float> > ak4PuppiGenjetPtToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppiGenjetPhiToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppiGenjetEtaToken_;

  //JER                                                                                                                                                                                          
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetJERSFToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetJERSFDownToken_;
  edm::EDGetTokenT<std::vector<float> > ak8CHSjetJERSFUpToken_;

  edm::EDGetTokenT<std::vector<float> > ak4CHSjetJERSFToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetJERSFDownToken_;
  edm::EDGetTokenT<std::vector<float> > ak4CHSjetJERSFUpToken_;

  edm::EDGetTokenT<std::vector<float> > ak8PuppijetJERSFToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetJERSFDownToken_;
  edm::EDGetTokenT<std::vector<float> > ak8PuppijetJERSFUpToken_;

  edm::EDGetTokenT<std::vector<float> > ak4PuppijetJERSFToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetJERSFDownToken_;
  edm::EDGetTokenT<std::vector<float> > ak4PuppijetJERSFUpToken_;

  //JEC
  JetCorrectorParameters *ResJetParAK8;
  JetCorrectorParameters *L3JetParAK8;
  JetCorrectorParameters *L2JetParAK8;
  JetCorrectorParameters *L1JetParAK8;
  vector<JetCorrectorParameters> vParAK8;
  FactorizedJetCorrector *JetCorrectorAK8;

  JetCorrectorParameters *ResJetParAK4;
  JetCorrectorParameters *L3JetParAK4;
  JetCorrectorParameters *L2JetParAK4;
  JetCorrectorParameters *L1JetParAK4;
  vector<JetCorrectorParameters> vParAK4;
  FactorizedJetCorrector *JetCorrectorAK4;

  JetCorrectionUncertainty *ak8jecUnc;
  JetCorrectionUncertainty *ak4jecUnc;

};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
TPRIME::TPRIME(const edm::ParameterSet& iConfig):
  JECshift_  (iConfig.getParameter<double>("JECshift")),
  JERshift_  (iConfig.getParameter<double>("JERshift")),
  Data       (iConfig.getParameter<bool>("Data")),
  Signal_MC  (iConfig.getParameter<bool>("Signal_MC")),
  Puppi      (iConfig.getParameter<bool>("Puppi")),
  L1AK8file  (iConfig.getParameter<string>("L1AK8File")),
  L2AK8file  (iConfig.getParameter<string>("L2AK8File")),
  L3AK8file  (iConfig.getParameter<string>("L3AK8File")),
  ResJetAK8file (iConfig.getParameter<string>("L23AK8File")),
  L1AK4file (iConfig.getParameter<string>("L1AK4File")),
  L2AK4file (iConfig.getParameter<string>("L2AK4File")),
  L3AK4file (iConfig.getParameter<string>("L3AK4File")),
  ResJetAK4file (iConfig.getParameter<string>("L23AK4File")),
  AK8UncertFile (iConfig.getParameter<string>("AK8UncertFile")),
  AK4UncertFile (iConfig.getParameter<string>("AK4UncertFile"))
{
  //now do what ever initialization is needed
  usesResource("TFileService");
  edm::Service<TFileService> fs;
  tree_had = fs->make<TTree>("tree_had","tree_had");
  tree_gen = fs->make<TTree>("tree_gen","tree_gen");
  /*
  listOfHadVars.push_back("HT800_Count");
  listOfHadVars.push_back("IsoMu_Count");
  listOfHadVars.push_back("Single_Jet_Count");
  listOfHadVars.push_back("Trim_Count");
  listOfHadVars.push_back("IsoMu_HT800_Count");
  listOfHadVars.push_back("Event_Number");
  */

  if (!Puppi){
    listOfHadVars.push_back("jetak8RawPtCHS");
    listOfHadVars.push_back("jetak8RawEtaCHS");
    listOfHadVars.push_back("jetak8RawPhiCHS");
    listOfHadVars.push_back("jetak8RawECHS");
    listOfHadVars.push_back("jetak4RawPtCHS");
    listOfHadVars.push_back("jetak4RawEtaCHS");
    listOfHadVars.push_back("jetak4RawPhiCHS");
    listOfHadVars.push_back("jetak4RawECHS");
    listOfHadVars.push_back("jetak4SV0massCHS");
    listOfHadVars.push_back("jetak4SV1massCHS");

  }

  if (Puppi){
    listOfHadVars.push_back("jetak8RawPtPuppi");
    listOfHadVars.push_back("jetak8RawEtaPuppi");
    listOfHadVars.push_back("jetak8RawPhiPuppi");
    listOfHadVars.push_back("jetak8RawEPuppi");
    listOfHadVars.push_back("jetak4RawPtPuppi");
    listOfHadVars.push_back("jetak4RawEtaPuppi");
    listOfHadVars.push_back("jetak4RawPhiPuppi");
    listOfHadVars.push_back("jetak4RawEPuppi");
    listOfHadVars.push_back("jetak4SV0massPuppi");
    listOfHadVars.push_back("jetak4SV1massPuppi");

  }

  listOfHadVars.push_back("numak4jets");
  listOfHadVars.push_back("numak8jets");
  listOfHadVars.push_back("GenID");
  listOfHadVars.push_back("Daughter0ID");
  listOfHadVars.push_back("Daughter1ID");
  listOfHadVars.push_back("Mom0ID");
  listOfHadVars.push_back("Mom1ID");

  if(!Puppi){
    listOfHadVars.push_back("jetak8CHSsoftmass");
    listOfHadVars.push_back("jetak8CHStrimmass");
    listOfHadVars.push_back("jetak4CHSCSVv2");
    listOfHadVars.push_back("jetak8CHStau1");
    listOfHadVars.push_back("jetak8CHStau2");
    listOfHadVars.push_back("jetak8CHStau3");
    listOfHadVars.push_back("jetak8CHStau21");
    listOfHadVars.push_back("jetak8CHStau32");
    listOfHadVars.push_back("jetak8CHSJECSF");
    listOfHadVars.push_back("jetak8CHSJECUncert");
    listOfHadVars.push_back("jetak8CHSJERSF");
    listOfHadVars.push_back("jetak8CHSJERUp");
    listOfHadVars.push_back("jetak8CHSJERDown");
    listOfHadVars.push_back("jetak4CHSJECSF");
    listOfHadVars.push_back("jetak4CHSJECUncert");
    listOfHadVars.push_back("jetak4CHSJERSF");
    listOfHadVars.push_back("jetak4CHSJERUp");
    listOfHadVars.push_back("jetak4CHSJERDown");

  }
  if (Puppi){
    listOfHadVars.push_back("jetak8Puppisoftmass");
    listOfHadVars.push_back("jetak8Puppitrimmass");
    listOfHadVars.push_back("jetak4PuppiCSVv2");
    listOfHadVars.push_back("jetak8Puppitau1");
    listOfHadVars.push_back("jetak8Puppitau2");
    listOfHadVars.push_back("jetak8Puppitau3");
    listOfHadVars.push_back("jetak8Puppitau21");
    listOfHadVars.push_back("jetak8Puppitau32");
    listOfHadVars.push_back("jetak8PuppiJECSF");
    listOfHadVars.push_back("jetak8PuppiJECUncert");
    listOfHadVars.push_back("jetak8PuppiJERSF");
    listOfHadVars.push_back("jetak8PuppiJERUp");
    listOfHadVars.push_back("jetak8PuppiJERDown");
    listOfHadVars.push_back("jetak4PuppiJECSF");
    listOfHadVars.push_back("jetak4PuppiJECUncert");
    listOfHadVars.push_back("jetak4PuppiJERSF");
    listOfHadVars.push_back("jetak4PuppiJERUp");
    listOfHadVars.push_back("jetak4PuppiJERDown");
  }

  listOfHadVars.push_back("ak8NHEF");
  listOfHadVars.push_back("ak8NEEF");
  listOfHadVars.push_back("ak8CEEF");
  listOfHadVars.push_back("ak8CHEF");
  listOfHadVars.push_back("ak8MEF");
  listOfHadVars.push_back("ak8CM");
  listOfHadVars.push_back("ak8NM");
  listOfHadVars.push_back("ak8NC");

  listOfHadVars.push_back("ak4NHEF");
  listOfHadVars.push_back("ak4NEEF");
  listOfHadVars.push_back("ak4CEEF");
  listOfHadVars.push_back("ak4CHEF");
  listOfHadVars.push_back("ak4MEF");
  listOfHadVars.push_back("ak4CM");
  listOfHadVars.push_back("ak4NM");
  listOfHadVars.push_back("ak4NC");


  listOfGenVars.push_back("GenID");
  listOfGenVars.push_back("Daughter0ID");
  listOfGenVars.push_back("Daughter1ID");
  listOfGenVars.push_back("MomID");


  //  listOfHadVars.push_back("HT");
  std::vector<float> filler;
  filler.push_back(-999.99);
  for (unsigned i = 0; i < listOfHadVars.size(); i++){
    hadTreeVars[ listOfHadVars[i] ] = filler;
    tree_had->Branch( (listOfHadVars[i]).c_str() , &(hadTreeVars[ listOfHadVars[i] ]));
  }
  for (unsigned i = 0; i < listOfGenVars.size(); i++){
    genTreeVars[ listOfGenVars[i] ] = filler;
    tree_gen->Branch( (listOfGenVars[i]).c_str() , &(genTreeVars[ listOfGenVars[i] ]));
  }
  // float HT;
  float HT800_Count;
  float Iso_Mu_Count;
  float Any_Mu_Count;
  float Single_Jet_Count;
  float Trim_Count;
  float Run_Number;
  ULong64_t Event_Number;
  float Weight;
  //  tree_had->Branch("HT", &HT, "HT/F");
  tree_had->Branch("HT800_Count", &HT800_Count, "HT800_Count/F");
  tree_had->Branch("Iso_Mu_Count", &Iso_Mu_Count, "Iso_Mu_Count/F");
  tree_had->Branch("Any_Mu_Count", &Any_Mu_Count, "Any_Mu_Count/F");
  tree_had->Branch("Single_Jet_Count", &Single_Jet_Count, "Single_Jet_Count/F");
  tree_had->Branch("Trim_Count", &Trim_Count, "Trim_Count/F");
  tree_had->Branch("Run_Number", &Run_Number, "Run_Number/F");
  tree_had->Branch("Event_Number", &Event_Number, "Event_Number/l");
  tree_had->Branch("Weight", &Weight, "Weight/F");
  edm::InputTag generatorTag("generator","","SIM");
  edm::InputTag triggerBitTreeTag("TriggerUserData", "triggerBitTree", "b2gEDMNtuples");
  edm::InputTag triggerNameTreeTag("TriggerUserData", "triggerNameTree", "b2gEDMNtuples");
  edm::InputTag METBitTreeTag("METUserData", "triggerBitTree", "b2gEDMNtuples");
  edm::InputTag METNameTreeTag("METUserData", "triggerNameTree", "b2gEDMNtuples");

  edm::InputTag evtInfoRunNumberTag("eventInfo", "evtInfoRunNumber", "b2gEDMNtuples");
  edm::InputTag evtInfoEventNumberTag("eventInfo", "evtInfoEventNumber", "b2gEDMNtuples");

  edm::InputTag GenParticleTag("filteredPrunedGenParticles", "", "b2gEDMNtuples");
  edm::InputTag PartIDTag("genPart","genPartID","b2gEDMNtuples");
  edm::InputTag PartPtTag("genPart","genPartPt","b2gEDMNtuples");
  edm::InputTag PartStatusTag("genPart","genPartStatus","b2gEDMNtuples");
  edm::InputTag PartMom0IDTag("genPart","genPartMom0ID","b2gEDMNtuples");
  edm::InputTag PartMom1IDTag("genPart","genPartMom1ID","b2gEDMNtuples");
  edm::InputTag PartDau0IDTag("genPart","genPartDau0ID","b2gEDMNtuples");
  edm::InputTag PartDau1IDTag("genPart","genPartDau1ID","b2gEDMNtuples");
  edm::InputTag RhoTag("fixedGridRhoFastjetAll", "", "RECO");
  edm::InputTag ak8CHSjetPtTag("jetsAK8CHS", "jetAK8CHSPt", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetEtaTag("jetsAK8CHS", "jetAK8CHSEta", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetPhiTag("jetsAK8CHS", "jetAK8CHSPhi", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetETag("jetsAK8CHS", "jetAK8CHSE", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetAreaTag("jetsAK8CHS", "jetAK8CHSjetArea", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetsoftMassTag("jetsAK8CHS", "jetAK8CHSsoftDropMass", "b2gEDMNtuples");
  edm::InputTag ak8CHSjettrimMassTag("jetsAK8CHS", "jetAK8CHStrimmedMass", "b2gEDMNtuples");
  edm::InputTag ak8CHSsubjetIndex0Tag("jetsAK8CHS", "jetAK8CHSvSubjetIndex0", "b2gEDMNtuples");
  edm::InputTag ak8CHSsubjetIndex1Tag("jetsAK8CHS", "jetAK8CHSvSubjetIndex1", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetCSVv2Tag("jetsAK8CHS", "jetAK8CHSCSVv2", "b2gEDMNtuples");
  edm::InputTag ak8CHSjettau1Tag("jetsAK8CHS","jetAK8CHStau1", "b2gEDMNtuples");
  edm::InputTag ak8CHSjettau2Tag("jetsAK8CHS","jetAK8CHStau2", "b2gEDMNtuples");
  edm::InputTag ak8CHSjettau3Tag("jetsAK8CHS","jetAK8CHStau3", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetJERSFTag("jetsAK8CHS", "jetAK8CHSJERSF", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetJERSFDownTag("jetsAK8CHS", "jetAK8CHSJERSFDown", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetJERSFUpTag("jetsAK8CHS", "jetAK8CHSJERSFUp", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetneutralHadronEnergyFracTag("jetsAK8CHS", "jetAK8PCHSneutralHadronEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetneutralEmEnergyFracTag("jetsAK8CHS", "jetAK8CHSneutralEmEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetchargedHadronEnergyFracTag("jetsAK8CHS", "jetAK8PCHSchargedHadronEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetMuonEnergyTag("jetsAK8CHS", "jetAK8PCHSMuonEnergy", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetchargedEmEnergyFracTag("jetsAK8CHS", "jetAK8PCHSchargedEmEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetchargedMultiplicityTag("jetsAK8CHS", "jetAK8PCHSchargedMultiplicity", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetneutralMultiplicityTag("jetsAK8CHS", "jetAK8PCHSneutralMultiplicity", "b2gEDMNtuples");
  edm::InputTag ak8CHSjetNumConstituentsTag("jetsAK8CHS", "jetAK8PCHSNumConstituents", "b2gEDMNtuples");

  edm::InputTag ak4CHSjetPtTag("jetsAK4CHS", "jetAK4CHSPt", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetEtaTag("jetsAK4CHS", "jetAK4CHSEta", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetPhiTag("jetsAK4CHS", "jetAK4CHSPhi", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetETag("jetsAK4CHS", "jetAK4CHSE", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetAreaTag("jetsAK4CHS", "jetAK4CHSjetArea", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetSV0massTag("jetsAK4CHS", "jetAK4CHSSV0mass", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetSV1massTag("jetsAK4CHS", "jetAK4CHSSV1mass", "b2gEDMNtuples");

  edm::InputTag ak4CHSsubjetIndex0Tag("jetsAK4CHS", "jetAK4CHSvSubjetIndex0", "b2gEDMNtuples");
  edm::InputTag ak4CHSsubjetIndex1Tag("jetsAK4CHS", "jetAK4CHSvSubjetIndex1", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetCSVv2Tag("jetsAK4CHS", "jetAK4CHSCSVv2", "b2gEDMNtuples");
  edm::InputTag ak4CHSjettau1Tag("jetsAK4CHS","jetAK4CHStau1", "b2gEDMNtuples");
  edm::InputTag ak4CHSjettau2Tag("jetsAK4CHS","jetAK4CHStau2", "b2gEDMNtuples");
  edm::InputTag ak4CHSjettau3Tag("jetsAK4CHS","jetAK4CHStau3", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetJERSFTag("jetsAK4CHS", "jetAK4CHSJERSF", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetJERSFDownTag("jetsAK4CHS", "jetAK4CHSJERSFDown", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetJERSFUpTag("jetsAK4CHS", "jetAK4CHSJERSFUp", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetneutralHadronEnergyFracTag("jetsAK4CHS", "jetAK4PCHSneutralHadronEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetneutralEmEnergyFracTag("jetsAK4CHS", "jetAK4CHSneutralEmEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetchargedHadronEnergyFracTag("jetsAK4CHS", "jetAK4PCHSchargedHadronEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetMuonEnergyTag("jetsAK4CHS", "jetAK4PCHSMuonEnergy", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetchargedEmEnergyFracTag("jetsAK4CHS", "jetAK4PCHSchargedEmEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetchargedMultiplicityTag("jetsAK4CHS", "jetAK4PCHSchargedMultiplicity", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetneutralMultiplicityTag("jetsAK4CHS", "jetAK4PCHSneutralMultiplicity", "b2gEDMNtuples");
  edm::InputTag ak4CHSjetNumConstituentsTag("jetsAK4CHS", "jetAK4PCHSNumConstituents", "b2gEDMNtuples");

  edm::InputTag ak8PuppijetPtTag("jetsAK8Puppi", "jetAK8PuppiPt", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetEtaTag("jetsAK8Puppi", "jetAK8PuppiEta", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetPhiTag("jetsAK8Puppi", "jetAK8PuppiPhi", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetETag("jetsAK8Puppi", "jetAK8PuppiE", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetAreaTag("jetsAK8Puppi", "jetAK8PuppijetArea", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetsoftMassTag("jetsAK8Puppi", "jetAK8PuppisoftDropMass", "b2gEDMNtuples");
  edm::InputTag ak8PuppijettrimMassTag("jetsAK8Puppi", "jetAK8PuppitrimmedMass", "b2gEDMNtuples");

  edm::InputTag ak8PuppisubjetIndex0Tag("jetsAK8Puppi", "jetAK8PuppivSubjetIndex0", "b2gEDMNtuples");
  edm::InputTag ak8PuppisubjetIndex1Tag("jetsAK8Puppi", "jetAK8PuppivSubjetIndex1", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetCSVv2Tag("jetsAK8Puppi", "jetAK8PuppiCSVv2", "b2gEDMNtuples");
  edm::InputTag ak8Puppijettau1Tag("jetsAK8Puppi","jetAK8Puppitau1", "b2gEDMNtuples");
  edm::InputTag ak8Puppijettau2Tag("jetsAK8Puppi","jetAK8Puppitau2", "b2gEDMNtuples");
  edm::InputTag ak8Puppijettau3Tag("jetsAK8Puppi","jetAK8Puppitau3", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetJERSFTag("jetsAK8Puppi", "jetAK8PuppiJERSF", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetJERSFDownTag("jetsAK8Puppi", "jetAK8PuppiJERSFDown", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetJERSFUpTag("jetsAK8Puppi", "jetAK8PuppiJERSFUp", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetneutralHadronEnergyFracTag("jetsAK8Puppi", "jetAK8PuppineutralHadronEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetneutralEmEnergyFracTag("jetsAK8Puppi", "jetAK8PuppineutralEmEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetchargedHadronEnergyFracTag("jetsAK8Puppi", "jetAK8PuppichargedHadronEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetMuonEnergyTag("jetsAK8Puppi", "jetAK8PuppiMuonEnergy", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetchargedEmEnergyFracTag("jetsAK8Puppi", "jetAK8PuppichargedEmEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetchargedMultiplicityTag("jetsAK8Puppi", "jetAK8PuppichargedMultiplicity", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetneutralMultiplicityTag("jetsAK8Puppi", "jetAK8PuppineutralMultiplicity", "b2gEDMNtuples");
  edm::InputTag ak8PuppijetNumConstituentsTag("jetsAK8Puppi", "jetAK8PuppiNumConstituents", "b2gEDMNtuples");

  edm::InputTag ak4PuppijetPtTag("jetsAK4Puppi", "jetAK4PuppiPt", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetEtaTag("jetsAK4Puppi", "jetAK4PuppiEta", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetPhiTag("jetsAK4Puppi", "jetAK4PuppiPhi", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetETag("jetsAK4Puppi", "jetAK4PuppiE", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetAreaTag("jetsAK4Puppi", "jetAK4PuppijetArea", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetSV0massTag("jetsAK4Puppi", "jetAK4PuppiSV0mass", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetSV1massTag("jetsAK4Puppi", "jetAK4PuppiSV1mass", "b2gEDMNtuples");

  edm::InputTag ak4PuppisubjetIndex0Tag("jetsAK4Puppi", "jetAK4PuppivSubjetIndex0", "b2gEDMNtuples");
  edm::InputTag ak4PuppisubjetIndex1Tag("jetsAK4Puppi", "jetAK4PuppivSubjetIndex1", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetCSVv2Tag("jetsAK4Puppi", "jetAK4PuppiCSVv2", "b2gEDMNtuples");
  edm::InputTag ak4Puppijettau1Tag("jetsAK4Puppi","jetAK4Puppitau1", "b2gEDMNtuples");
  edm::InputTag ak4Puppijettau2Tag("jetsAK4Puppi","jetAK4Puppitau2", "b2gEDMNtuples");
  edm::InputTag ak4Puppijettau3Tag("jetsAK4Puppi","jetAK4Puppitau3", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetJERSFTag("jetsAK4Puppi", "jetAK4PuppiJERSF", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetJERSFDownTag("jetsAK4Puppi", "jetAK4PuppiJERSFDown", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetJERSFUpTag("jetsAK4Puppi", "jetAK4PuppiJERSFUp", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetneutralHadronEnergyFracTag("jetsAK4Puppi", "jetAK4PuppineutralHadronEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetneutralEmEnergyFracTag("jetsAK4Puppi", "jetAK4PuppineutralEmEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetchargedHadronEnergyFracTag("jetsAK4Puppi", "jetAK4PuppichargedHadronEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetMuonEnergyTag("jetsAK4Puppi", "jetAK4PuppiMuonEnergy", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetchargedEmEnergyFracTag("jetsAK4Puppi", "jetAK4PuppichargedEmEnergyFrac", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetchargedMultiplicityTag("jetsAK4Puppi", "jetAK4PuppichargedMultiplicity", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetneutralMultiplicityTag("jetsAK4Puppi", "jetAK4PuppineutralMultiplicity", "b2gEDMNtuples");
  edm::InputTag ak4PuppijetNumConstituentsTag("jetsAK4Puppi", "jetAK4PuppiNumConstituents", "b2gEDMNtuples");


  generatorToken_ = consumes<GenEventInfoProduct> (generatorTag);
  evtInfoRunNumberToken_ = consumes<unsigned int >(evtInfoRunNumberTag);
  evtInfoEventNumberToken_ = consumes<ULong64_t >(evtInfoEventNumberTag);
  triggerBitTreeToken_ = consumes<std::vector<float> >(triggerBitTreeTag);
  triggerNameTreeToken_ = consumes<std::vector<std::string>, edm::InRun >(triggerNameTreeTag);
  METBitTreeToken_ = consumes<std::vector<float> >(METBitTreeTag);
  METNameTreeToken_ = consumes<std::vector<std::string>, edm::InRun >(METNameTreeTag);

  if (!Data){
    GenParticleToken_ = consumes<vector<reco::GenParticle> > (GenParticleTag);
    PartIDToken_ = consumes<std::vector<float> >(PartIDTag);
    PartPtToken_ = consumes<std::vector<float> >(PartPtTag); 
    PartStatusToken_ = consumes<std::vector<float> >(PartStatusTag);
    PartMom0IDToken_ = consumes<std::vector<float> >(PartMom0IDTag);
    PartMom1IDToken_ = consumes<std::vector<float> >(PartMom1IDTag);
    PartDau0IDToken_ = consumes<std::vector<float> >(PartDau0IDTag);
    PartDau1IDToken_ = consumes<std::vector<float> >(PartDau1IDTag);                                                                                                                                
  }                  

  RhoToken_ =  consumes<double >(RhoTag);
  if (!Puppi){
    ak8CHSjetPtToken_ = consumes<std::vector<float> >(ak8CHSjetPtTag);
    ak8CHSjetEtaToken_ = consumes<std::vector<float> >(ak8CHSjetEtaTag);
    ak8CHSjetPhiToken_ = consumes<std::vector<float> >(ak8CHSjetPhiTag);
    ak8CHSjetEToken_ = consumes<std::vector<float> >(ak8CHSjetETag);
    ak8CHSjetsoftMassToken_ = consumes<std::vector<float> >(ak8CHSjetsoftMassTag);
    ak8CHSjettrimmedMassToken_ = consumes<std::vector<float> >(ak8CHSjettrimMassTag);
    ak8CHSjetAreaToken_ = consumes<std::vector<float> >(ak8CHSjetAreaTag);
    ak8CHSsubjetIndex0Token_ = consumes<std::vector<float> >(ak8CHSsubjetIndex0Tag);
    ak8CHSsubjetIndex1Token_ = consumes<std::vector<float> >(ak8CHSsubjetIndex1Tag);
    ak8CHSjetCSVv2Token_ = consumes<std::vector<float> >(ak8CHSjetCSVv2Tag);
    ak8CHSjettau1Token_ = consumes<std::vector<float> >(ak8CHSjettau1Tag);
    ak8CHSjettau2Token_ = consumes<std::vector<float> >(ak8CHSjettau2Tag);
    ak8CHSjettau3Token_ = consumes<std::vector<float> >(ak8CHSjettau3Tag);

    ak8CHSjetneutralHadronEnergyFracToken_ = consumes<std::vector<float> >(ak8CHSjetneutralHadronEnergyFracTag);
    ak8CHSjetneutralEmEnergyFracToken_ =  consumes<std::vector<float> >(ak8CHSjetneutralEmEnergyFracTag);
    ak8CHSjetchargedHadronEnergyFracToken_ =  consumes<std::vector<float> >(ak8CHSjetchargedHadronEnergyFracTag);
    ak8CHSjetMuonEnergyToken_ =  consumes<std::vector<float> >(ak8CHSjetMuonEnergyTag);
    ak8CHSjetchargedMultiplicityToken_ =  consumes<std::vector<float> >(ak8CHSjetchargedMultiplicityTag);
    ak8CHSjetneutralMultiplicityToken_ =  consumes<std::vector<float> >(ak8CHSjetneutralMultiplicityTag);
    ak8CHSjetchargedEmEnergyFracToken_ =  consumes<std::vector<float> >(ak8CHSjetchargedEmEnergyFracTag);
    ak8CHSjetNumConstituentsToken_ =  consumes<std::vector<float> >(ak8CHSjetNumConstituentsTag);

    ak8CHSjetJERSFToken_ = consumes<std::vector<float> >(ak8CHSjetJERSFTag);
    ak8CHSjetJERSFDownToken_ = consumes<std::vector<float> >(ak8CHSjetJERSFDownTag);
    ak8CHSjetJERSFUpToken_ = consumes<std::vector<float> >(ak8CHSjetJERSFUpTag);

    ak4CHSjetPtToken_ = consumes<std::vector<float> >(ak4CHSjetPtTag);
    ak4CHSjetEtaToken_ = consumes<std::vector<float> >(ak4CHSjetEtaTag);
    ak4CHSjetPhiToken_ = consumes<std::vector<float> >(ak4CHSjetPhiTag);
    ak4CHSjetEToken_ = consumes<std::vector<float> >(ak4CHSjetETag);
    ak4CHSjetSV0massToken_ = consumes<std::vector<float> >(ak4CHSjetSV0massTag);
    ak4CHSjetSV1massToken_ = consumes<std::vector<float> >(ak4CHSjetSV1massTag);
    ak4CHSjetAreaToken_ = consumes<std::vector<float> >(ak4CHSjetAreaTag);
    ak4CHSsubjetIndex0Token_ = consumes<std::vector<float> >(ak4CHSsubjetIndex0Tag);
    ak4CHSsubjetIndex1Token_ = consumes<std::vector<float> >(ak4CHSsubjetIndex1Tag);
    ak4CHSjetCSVv2Token_ = consumes<std::vector<float> >(ak4CHSjetCSVv2Tag);
    ak4CHSjettau1Token_ = consumes<std::vector<float> >(ak4CHSjettau1Tag);
    ak4CHSjettau2Token_ = consumes<std::vector<float> >(ak4CHSjettau2Tag);
    ak4CHSjettau3Token_ = consumes<std::vector<float> >(ak4CHSjettau3Tag);

    ak4CHSjetneutralHadronEnergyFracToken_ = consumes<std::vector<float> >(ak4CHSjetneutralHadronEnergyFracTag);
    ak4CHSjetneutralEmEnergyFracToken_ =  consumes<std::vector<float> >(ak4CHSjetneutralEmEnergyFracTag);
    ak4CHSjetchargedHadronEnergyFracToken_ =  consumes<std::vector<float> >(ak4CHSjetchargedHadronEnergyFracTag);
    ak4CHSjetMuonEnergyToken_ =  consumes<std::vector<float> >(ak4CHSjetMuonEnergyTag);
    ak4CHSjetchargedMultiplicityToken_ =  consumes<std::vector<float> >(ak4CHSjetchargedMultiplicityTag);
    ak4CHSjetneutralMultiplicityToken_ =  consumes<std::vector<float> >(ak4CHSjetneutralMultiplicityTag);
    ak4CHSjetchargedEmEnergyFracToken_ =  consumes<std::vector<float> >(ak4CHSjetchargedEmEnergyFracTag);
    ak4CHSjetNumConstituentsToken_ =  consumes<std::vector<float> >(ak4CHSjetNumConstituentsTag);


    ak4CHSjetJERSFToken_ = consumes<std::vector<float> >(ak4CHSjetJERSFTag);
    ak4CHSjetJERSFDownToken_ = consumes<std::vector<float> >(ak4CHSjetJERSFDownTag);
    ak4CHSjetJERSFUpToken_ = consumes<std::vector<float> >(ak4CHSjetJERSFUpTag);

  }
  if (Puppi){
    ak8PuppijetPtToken_ = consumes<std::vector<float> >(ak8PuppijetPtTag);
    ak8PuppijetEtaToken_ = consumes<std::vector<float> >(ak8PuppijetEtaTag);
    ak8PuppijetPhiToken_ = consumes<std::vector<float> >(ak8PuppijetPhiTag);
    ak8PuppijetEToken_ = consumes<std::vector<float> >(ak8PuppijetETag);
    ak8PuppijetsoftMassToken_ = consumes<std::vector<float> >(ak8PuppijetsoftMassTag);
    ak8PuppijettrimmedMassToken_ = consumes<std::vector<float> >(ak8PuppijettrimMassTag);
    ak8PuppijetAreaToken_ = consumes<std::vector<float> >(ak8PuppijetAreaTag);
    ak8PuppisubjetIndex0Token_ = consumes<std::vector<float> >(ak8PuppisubjetIndex0Tag);
    ak8PuppisubjetIndex1Token_ = consumes<std::vector<float> >(ak8PuppisubjetIndex1Tag);
    ak8PuppijetCSVv2Token_ = consumes<std::vector<float> >(ak8PuppijetCSVv2Tag);
    ak8Puppijettau1Token_ = consumes<std::vector<float> >(ak8Puppijettau1Tag);
    ak8Puppijettau2Token_ = consumes<std::vector<float> >(ak8Puppijettau2Tag);
    ak8Puppijettau3Token_ = consumes<std::vector<float> >(ak8Puppijettau3Tag);

    ak8PuppijetneutralHadronEnergyFracToken_ = consumes<std::vector<float> >(ak8PuppijetneutralHadronEnergyFracTag);
    ak8PuppijetneutralEmEnergyFracToken_ =  consumes<std::vector<float> >(ak8PuppijetneutralEmEnergyFracTag);
    ak8PuppijetchargedHadronEnergyFracToken_ =  consumes<std::vector<float> >(ak8PuppijetchargedHadronEnergyFracTag);
    ak8PuppijetMuonEnergyToken_ =  consumes<std::vector<float> >(ak8PuppijetMuonEnergyTag);
    ak8PuppijetchargedMultiplicityToken_ =  consumes<std::vector<float> >(ak8PuppijetchargedMultiplicityTag);
    ak8PuppijetneutralMultiplicityToken_ =  consumes<std::vector<float> >(ak8PuppijetneutralMultiplicityTag);
    ak8PuppijetchargedEmEnergyFracToken_ =  consumes<std::vector<float> >(ak8PuppijetchargedEmEnergyFracTag);
    ak8PuppijetNumConstituentsToken_ =  consumes<std::vector<float> >(ak8PuppijetNumConstituentsTag);


    ak8PuppijetJERSFToken_ = consumes<std::vector<float> >(ak8PuppijetJERSFTag);
    ak8PuppijetJERSFDownToken_ = consumes<std::vector<float> >(ak8PuppijetJERSFDownTag);
    ak8PuppijetJERSFUpToken_ = consumes<std::vector<float> >(ak8PuppijetJERSFUpTag);

    ak4PuppijetPtToken_ = consumes<std::vector<float> >(ak4PuppijetPtTag);
    ak4PuppijetEtaToken_ = consumes<std::vector<float> >(ak4PuppijetEtaTag);
    ak4PuppijetPhiToken_ = consumes<std::vector<float> >(ak4PuppijetPhiTag);
    ak4PuppijetEToken_ = consumes<std::vector<float> >(ak4PuppijetETag);
    ak4PuppijetSV0massToken_ = consumes<std::vector<float> >(ak4PuppijetSV0massTag);
    ak4PuppijetSV1massToken_ = consumes<std::vector<float> >(ak4PuppijetSV1massTag);
    ak4PuppijetAreaToken_ = consumes<std::vector<float> >(ak4PuppijetAreaTag);
    ak4PuppisubjetIndex0Token_ = consumes<std::vector<float> >(ak4PuppisubjetIndex0Tag);
    ak4PuppisubjetIndex1Token_ = consumes<std::vector<float> >(ak4PuppisubjetIndex1Tag);
    ak4PuppijetCSVv2Token_ = consumes<std::vector<float> >(ak4PuppijetCSVv2Tag);
    ak4Puppijettau1Token_ = consumes<std::vector<float> >(ak4Puppijettau1Tag);
    ak4Puppijettau2Token_ = consumes<std::vector<float> >(ak4Puppijettau2Tag);
    ak4Puppijettau3Token_ = consumes<std::vector<float> >(ak4Puppijettau3Tag);

    ak4PuppijetneutralHadronEnergyFracToken_ = consumes<std::vector<float> >(ak4PuppijetneutralHadronEnergyFracTag);
    ak4PuppijetneutralEmEnergyFracToken_ =  consumes<std::vector<float> >(ak4PuppijetneutralEmEnergyFracTag);
    ak4PuppijetchargedHadronEnergyFracToken_ =  consumes<std::vector<float> >(ak4PuppijetchargedHadronEnergyFracTag);
    ak4PuppijetMuonEnergyToken_ =  consumes<std::vector<float> >(ak4PuppijetMuonEnergyTag);
    ak4PuppijetchargedMultiplicityToken_ =  consumes<std::vector<float> >(ak4PuppijetchargedMultiplicityTag);
    ak4PuppijetneutralMultiplicityToken_ =  consumes<std::vector<float> >(ak4PuppijetneutralMultiplicityTag);
    ak4PuppijetchargedEmEnergyFracToken_ =  consumes<std::vector<float> >(ak4PuppijetchargedEmEnergyFracTag);
    ak4PuppijetNumConstituentsToken_ =  consumes<std::vector<float> >(ak4PuppijetNumConstituentsTag);

    ak4PuppijetJERSFToken_ = consumes<std::vector<float> >(ak4PuppijetJERSFTag);
    ak4PuppijetJERSFDownToken_ = consumes<std::vector<float> >(ak4PuppijetJERSFDownTag);
    ak4PuppijetJERSFUpToken_ = consumes<std::vector<float> >(ak4PuppijetJERSFUpTag);

  }

  //Get the JECs                                                                                                                                                        
  ResJetParAK8 = new JetCorrectorParameters(ResJetAK8file);
  L3JetParAK8  = new JetCorrectorParameters(L3AK8file);
  L2JetParAK8  = new JetCorrectorParameters(L2AK8file);
  L1JetParAK8  = new JetCorrectorParameters(L1AK8file);
  vParAK8.push_back(*L1JetParAK8);
  vParAK8.push_back(*L2JetParAK8);
  vParAK8.push_back(*L3JetParAK8);
  vParAK8.push_back(*ResJetParAK8);
  JetCorrectorAK8 = new FactorizedJetCorrector(vParAK8);

  ResJetParAK4 = new JetCorrectorParameters(ResJetAK4file);
  L3JetParAK4  = new JetCorrectorParameters(L3AK4file);
  L2JetParAK4  = new JetCorrectorParameters(L2AK4file);
  L1JetParAK4  = new JetCorrectorParameters(L1AK4file);
  vParAK4.push_back(*L1JetParAK4);
  vParAK4.push_back(*L2JetParAK4);
  vParAK4.push_back(*L3JetParAK4);
  vParAK4.push_back(*ResJetParAK4);
  JetCorrectorAK4 = new FactorizedJetCorrector(vParAK4);

  ak8jecUnc = new JetCorrectionUncertainty(AK8UncertFile);
  ak4jecUnc = new JetCorrectionUncertainty(AK4UncertFile);



}


TPRIME::~TPRIME()
{
 
  // do anything here that needs to be done at desctruction time
  // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
TPRIME::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;
  using namespace std;
  using namespace reco;
  /*
  for (unsigned i = 0; i < listOfHadVars.size(); i++){
    hadTreeVars[ listOfHadVars[i] ] = filler;
  }

  for (unsigned i = 0; i < listOfGenVars.size(); i++){
    genTreeVars[ listOfGenVars[i] ] = filler;
  }
  
  */
  edm::Handle<GenEventInfoProduct> generatorHandle;
  edm::Handle<std::vector<float> > triggerBitTreeHandle;
  edm::Handle<std::vector<string> > triggerNameTreeHandle;
  edm::Handle<std::vector<float> > METBitTreeHandle;
  edm::Handle<vector<string> > METNameTreeHandle;
  edm::Handle<unsigned int> evtInfoRunNumberHandle;
  edm::Handle<ULong64_t> evtInfoEventNumberHandle;

  edm::Handle<vector<reco::GenParticle> > GenParticleHandle;
  edm::Handle<vector<float> > PartIDHandle;                                                                                                                                                                       
  edm::Handle<vector<float> > PartPtHandle;                                                                                                                                                                         
  edm::Handle<vector<float> > PartStatusHandle;                                                                                                                                                                     
  edm::Handle<vector<float> > PartMom0IDHandle;                                                                                                                                                                     
  edm::Handle<vector<float> > PartMom1IDHandle;                                                                                                                                                                     
  edm::Handle<vector<float> > PartDau0IDHandle;                                                                                                                                                                     
  edm::Handle<vector<float> > PartDau1IDHandle;                                                                                                                                                                     


  edm::Handle<double>  RhoHandle;
  //   if (!Puppi){
  edm::Handle<vector<float> > ak8CHSjetPtHandle;
  edm::Handle<vector<float> > ak8CHSjetPhiHandle;
  edm::Handle<vector<float> > ak8CHSjetEtaHandle;
  edm::Handle<vector<float> > ak8CHSjetEHandle;
  edm::Handle<vector<float> > ak8CHSjetAreaHandle;
  edm::Handle<vector<float> > ak8CHSjetsoftMassHandle;
  edm::Handle<vector<float> > ak8CHSjettrimMassHandle;
  edm::Handle<vector<float> > ak8CHSjetCSVv2Handle;
  edm::Handle<vector<float> > ak8CHSjettau1Handle;
  edm::Handle<vector<float> > ak8CHSjettau2Handle;
  edm::Handle<vector<float> > ak8CHSjettau3Handle;

  edm::Handle<vector<float> > ak8CHSjetneutralHadronEnergyFracHandle;
  edm::Handle<vector<float> > ak8CHSjetneutralEmEnergyFracHandle;
  edm::Handle<vector<float> > ak8CHSjetchargedHadronEnergyFracHandle;
  edm::Handle<vector<float> > ak8CHSjetMuonEnergyHandle;
  edm::Handle<vector<float> > ak8CHSjetchargedMultiplicityHandle;
  edm::Handle<vector<float> > ak8CHSjetchargedEmEnergyFracHandle;
  edm::Handle<vector<float> > ak8CHSjetneutralMultiplicityHandle;
  //  edm::Handle<vector<float> > ak8CHSjetNumConstituentsHandle;


  edm::Handle<vector<float> > ak4CHSjetPtHandle;
  edm::Handle<vector<float> > ak4CHSjetPhiHandle;
  edm::Handle<vector<float> > ak4CHSjetEtaHandle;
  edm::Handle<vector<float> > ak4CHSjetEHandle;
  edm::Handle<vector<float> > ak4CHSjetAreaHandle;
  edm::Handle<vector<float> > ak4CHSjetSV0massHandle;
  edm::Handle<vector<float> > ak4CHSjetSV1massHandle;
  edm::Handle<vector<float> > ak4CHSjetCSVv2Handle;
  edm::Handle<vector<float> > ak4CHSjettau1Handle;
  edm::Handle<vector<float> > ak4CHSjettau2Handle;
  edm::Handle<vector<float> > ak4CHSjettau3Handle;

  edm::Handle<vector<float> > ak4CHSjetneutralHadronEnergyFracHandle;
  edm::Handle<vector<float> > ak4CHSjetneutralEmEnergyFracHandle;
  edm::Handle<vector<float> > ak4CHSjetchargedHadronEnergyFracHandle;
  edm::Handle<vector<float> > ak4CHSjetMuonEnergyHandle;
  edm::Handle<vector<float> > ak4CHSjetchargedMultiplicityHandle;
  edm::Handle<vector<float> > ak4CHSjetneutralMultiplicityHandle;
  edm::Handle<vector<float> > ak4CHSjetchargedEmEnergyFracHandle;
  //  edm::Handle<vector<float> > ak4CHSjetNumConstituentsHandle;


  edm::Handle<vector<float> > ak8CHSJERSFHandle;
  edm::Handle<vector<float> > ak8CHSJERSFDownHandle;
  edm::Handle<vector<float> > ak8CHSJERSFUpHandle;
  edm::Handle<vector<float> > ak4CHSJERSFHandle;
  edm::Handle<vector<float> > ak4CHSJERSFDownHandle;
  edm::Handle<vector<float> > ak4CHSJERSFUpHandle;
  //   }
  //  if (Puppi){
  edm::Handle<vector<float> > ak8PuppijetPtHandle;
  edm::Handle<vector<float> > ak8PuppijetPhiHandle;
  edm::Handle<vector<float> > ak8PuppijetEtaHandle;
  edm::Handle<vector<float> > ak8PuppijetEHandle;
  edm::Handle<vector<float> > ak8PuppijetAreaHandle;
  edm::Handle<vector<float> > ak8PuppijetsoftMassHandle;
  edm::Handle<vector<float> > ak8PuppijettrimMassHandle;
  edm::Handle<vector<float> > ak8PuppijetCSVv2Handle;
  edm::Handle<vector<float> > ak8Puppijettau1Handle;
  edm::Handle<vector<float> > ak8Puppijettau2Handle;
  edm::Handle<vector<float> > ak8Puppijettau3Handle;

  edm::Handle<vector<float> > ak8PuppijetneutralHadronEnergyFracHandle;
  edm::Handle<vector<float> > ak8PuppijetneutralEmEnergyFracHandle;
  edm::Handle<vector<float> > ak8PuppijetchargedHadronEnergyFracHandle;
  edm::Handle<vector<float> > ak8PuppijetMuonEnergyHandle;
  edm::Handle<vector<float> > ak8PuppijetchargedMultiplicityHandle;
  edm::Handle<vector<float> > ak8PuppijetneutralMultiplicityHandle;
  edm::Handle<vector<float> > ak8PuppijetchargedEmEnergyFracHandle;
  //  edm::Handle<vector<float> > ak8PuppijetNumConstituentsHandle;


  edm::Handle<vector<float> > ak4PuppijetPtHandle;
  edm::Handle<vector<float> > ak4PuppijetPhiHandle;
  edm::Handle<vector<float> > ak4PuppijetEtaHandle;
  edm::Handle<vector<float> > ak4PuppijetEHandle;
  edm::Handle<vector<float> > ak4PuppijetAreaHandle;
  edm::Handle<vector<float> > ak4PuppijetSV0massHandle;
  edm::Handle<vector<float> > ak4PuppijetSV1massHandle;
  edm::Handle<vector<float> > ak4PuppijetCSVv2Handle;
  edm::Handle<vector<float> > ak4Puppijettau1Handle;
  edm::Handle<vector<float> > ak4Puppijettau2Handle;
  edm::Handle<vector<float> > ak4Puppijettau3Handle;

  edm::Handle<vector<float> > ak4PuppijetneutralHadronEnergyFracHandle;
  edm::Handle<vector<float> > ak4PuppijetneutralEmEnergyFracHandle;
  edm::Handle<vector<float> > ak4PuppijetchargedHadronEnergyFracHandle;
  edm::Handle<vector<float> > ak4PuppijetMuonEnergyHandle;
  edm::Handle<vector<float> > ak4PuppijetchargedMultiplicityHandle;
  edm::Handle<vector<float> > ak4PuppijetneutralMultiplicityHandle;
  edm::Handle<vector<float> > ak4PuppijetchargedEmEnergyFracHandle;
  //  edm::Handle<vector<float> > ak4PuppijetNumConstituentsHandle;


  edm::Handle<vector<float> > ak8PuppiJERSFHandle;
  edm::Handle<vector<float> > ak8PuppiJERSFDownHandle;
  edm::Handle<vector<float> > ak8PuppiJERSFUpHandle;
  edm::Handle<vector<float> > ak4PuppiJERSFHandle;
  edm::Handle<vector<float> > ak4PuppiJERSFDownHandle;
  edm::Handle<vector<float> > ak4PuppiJERSFUpHandle;

  // }
  iEvent.getByToken(generatorToken_, generatorHandle);
  iEvent.getByToken(triggerBitTreeToken_, triggerBitTreeHandle);
  iEvent.getRun().getByToken(triggerNameTreeToken_, triggerNameTreeHandle);
  iEvent.getByToken(METBitTreeToken_, METBitTreeHandle);
  iEvent.getRun().getByToken(METNameTreeToken_, METNameTreeHandle);

  iEvent.getByToken(evtInfoRunNumberToken_,evtInfoRunNumberHandle);
  iEvent.getByToken(evtInfoEventNumberToken_,evtInfoEventNumberHandle);


  if(Signal_MC){
    iEvent.getByToken(GenParticleToken_, GenParticleHandle);
    /*
    iEvent.getByToken(PartIDToken_, PartIDHandle);
    iEvent.getByToken(PartPtToken_, PartPtHandle);
    iEvent.getByToken(PartStatusToken_, PartStatusHandle);
    iEvent.getByToken(PartMom0IDToken_, PartMom0IDHandle);
    iEvent.getByToken(PartMom1IDToken_, PartMom1IDHandle);
    iEvent.getByToken(PartDau0IDToken_, PartDau0IDHandle);
    iEvent.getByToken(PartDau1IDToken_, PartDau1IDHandle);
    */
  }
  iEvent.getByToken(RhoToken_, RhoHandle);
  
  if(!Puppi){
    iEvent.getByToken(ak8CHSjetPtToken_, ak8CHSjetPtHandle);
    iEvent.getByToken(ak8CHSjetEtaToken_, ak8CHSjetEtaHandle);
    iEvent.getByToken(ak8CHSjetPhiToken_, ak8CHSjetPhiHandle);
    iEvent.getByToken(ak8CHSjetEToken_, ak8CHSjetEHandle);
    iEvent.getByToken(ak8CHSjetAreaToken_, ak8CHSjetAreaHandle);
    iEvent.getByToken(ak8CHSjetsoftMassToken_, ak8CHSjetsoftMassHandle);
    iEvent.getByToken(ak8CHSjettrimmedMassToken_, ak8CHSjettrimMassHandle);
    iEvent.getByToken(ak8CHSjetCSVv2Token_, ak8CHSjetCSVv2Handle);
    iEvent.getByToken(ak8CHSjettau1Token_, ak8CHSjettau1Handle);
    iEvent.getByToken(ak8CHSjettau2Token_, ak8CHSjettau2Handle);
    iEvent.getByToken(ak8CHSjettau3Token_, ak8CHSjettau3Handle);

    iEvent.getByToken(ak8CHSjetneutralHadronEnergyFracToken_, ak8CHSjetneutralHadronEnergyFracHandle);
    iEvent.getByToken(ak8CHSjetneutralEmEnergyFracToken_, ak8CHSjetneutralEmEnergyFracHandle);
    iEvent.getByToken(ak8CHSjetchargedHadronEnergyFracToken_, ak8CHSjetchargedHadronEnergyFracHandle);
    iEvent.getByToken(ak8CHSjetMuonEnergyToken_, ak8CHSjetMuonEnergyHandle);
    iEvent.getByToken(ak8CHSjetchargedMultiplicityToken_, ak8CHSjetchargedMultiplicityHandle);
    iEvent.getByToken(ak8CHSjetneutralMultiplicityToken_, ak8CHSjetneutralMultiplicityHandle);
    iEvent.getByToken(ak8CHSjetchargedEmEnergyFracToken_, ak8CHSjetchargedEmEnergyFracHandle);
    //    iEvent.getByToken(ak8CHSjetNumConstituentsToken_, ak8CHSjetNumConstituentsHandle);

    iEvent.getByToken(ak8CHSjetJERSFToken_, ak8CHSJERSFHandle);
    iEvent.getByToken(ak8CHSjetJERSFUpToken_, ak8CHSJERSFUpHandle);
    iEvent.getByToken(ak8CHSjetJERSFDownToken_, ak8CHSJERSFDownHandle);

    iEvent.getByToken(ak4CHSjetPtToken_, ak4CHSjetPtHandle);
    iEvent.getByToken(ak4CHSjetEtaToken_, ak4CHSjetEtaHandle);
    iEvent.getByToken(ak4CHSjetPhiToken_, ak4CHSjetPhiHandle);
    iEvent.getByToken(ak4CHSjetEToken_, ak4CHSjetEHandle);
    iEvent.getByToken(ak4CHSjetSV0massToken_, ak4CHSjetSV0massHandle);
    iEvent.getByToken(ak4CHSjetSV1massToken_, ak4CHSjetSV1massHandle);
    iEvent.getByToken(ak4CHSjetAreaToken_, ak4CHSjetAreaHandle);
    iEvent.getByToken(ak4CHSjetCSVv2Token_, ak4CHSjetCSVv2Handle);
    iEvent.getByToken(ak4CHSjettau1Token_, ak4CHSjettau1Handle);
    iEvent.getByToken(ak4CHSjettau2Token_, ak4CHSjettau2Handle);
    iEvent.getByToken(ak4CHSjettau3Token_, ak4CHSjettau3Handle);

    iEvent.getByToken(ak4CHSjetneutralHadronEnergyFracToken_, ak4CHSjetneutralHadronEnergyFracHandle);
    iEvent.getByToken(ak4CHSjetneutralEmEnergyFracToken_, ak4CHSjetneutralEmEnergyFracHandle);
    iEvent.getByToken(ak4CHSjetchargedHadronEnergyFracToken_, ak4CHSjetchargedHadronEnergyFracHandle);
    iEvent.getByToken(ak4CHSjetMuonEnergyToken_, ak4CHSjetMuonEnergyHandle);
    iEvent.getByToken(ak4CHSjetchargedMultiplicityToken_, ak4CHSjetchargedMultiplicityHandle);
    iEvent.getByToken(ak4CHSjetneutralMultiplicityToken_, ak4CHSjetneutralMultiplicityHandle);
    iEvent.getByToken(ak4CHSjetchargedEmEnergyFracToken_, ak4CHSjetchargedEmEnergyFracHandle);
    //    iEvent.getByToken(ak4CHSjetNumConstituentsToken_, ak4CHSjetNumConstituentsHandle);


    iEvent.getByToken(ak4CHSjetJERSFToken_, ak4CHSJERSFHandle);
    iEvent.getByToken(ak4CHSjetJERSFUpToken_, ak4CHSJERSFUpHandle);
    iEvent.getByToken(ak4CHSjetJERSFDownToken_, ak4CHSJERSFDownHandle);

  }
  if(Puppi){
    iEvent.getByToken(ak8PuppijetPtToken_, ak8PuppijetPtHandle);
    iEvent.getByToken(ak8PuppijetEtaToken_, ak8PuppijetEtaHandle);
    iEvent.getByToken(ak8PuppijetPhiToken_, ak8PuppijetPhiHandle);
    iEvent.getByToken(ak8PuppijetEToken_, ak8PuppijetEHandle);
    iEvent.getByToken(ak8PuppijetAreaToken_, ak8PuppijetAreaHandle);
    iEvent.getByToken(ak8PuppijetsoftMassToken_, ak8PuppijetsoftMassHandle);
    iEvent.getByToken(ak8PuppijettrimmedMassToken_, ak8PuppijettrimMassHandle);
    iEvent.getByToken(ak8PuppijetCSVv2Token_, ak8PuppijetCSVv2Handle);
    iEvent.getByToken(ak8Puppijettau1Token_, ak8Puppijettau1Handle);
    iEvent.getByToken(ak8Puppijettau2Token_, ak8Puppijettau2Handle);
    iEvent.getByToken(ak8Puppijettau3Token_, ak8Puppijettau3Handle);

    iEvent.getByToken(ak8PuppijetneutralHadronEnergyFracToken_, ak8PuppijetneutralHadronEnergyFracHandle);
    iEvent.getByToken(ak8PuppijetneutralEmEnergyFracToken_, ak8PuppijetneutralEmEnergyFracHandle);
    iEvent.getByToken(ak8PuppijetchargedHadronEnergyFracToken_, ak8PuppijetchargedHadronEnergyFracHandle);
    iEvent.getByToken(ak8PuppijetMuonEnergyToken_, ak8PuppijetMuonEnergyHandle);
    iEvent.getByToken(ak8PuppijetchargedMultiplicityToken_, ak8PuppijetchargedMultiplicityHandle);
    iEvent.getByToken(ak8PuppijetneutralMultiplicityToken_, ak8PuppijetneutralMultiplicityHandle);
    iEvent.getByToken(ak8PuppijetchargedEmEnergyFracToken_, ak8PuppijetchargedEmEnergyFracHandle);
    //    iEvent.getByToken(ak8PuppijetNumConstituentsToken_, ak8PuppijetNumConstituentsHandle);

    iEvent.getByToken(ak8PuppijetJERSFToken_, ak8PuppiJERSFHandle);
    iEvent.getByToken(ak8PuppijetJERSFUpToken_, ak8PuppiJERSFUpHandle);
    iEvent.getByToken(ak8PuppijetJERSFDownToken_, ak8PuppiJERSFDownHandle);

    iEvent.getByToken(ak4PuppijetPtToken_, ak4PuppijetPtHandle);
    iEvent.getByToken(ak4PuppijetEtaToken_, ak4PuppijetEtaHandle);
    iEvent.getByToken(ak4PuppijetPhiToken_, ak4PuppijetPhiHandle);
    iEvent.getByToken(ak4PuppijetEToken_, ak4PuppijetEHandle);
    iEvent.getByToken(ak4PuppijetSV0massToken_, ak4PuppijetSV0massHandle);
    iEvent.getByToken(ak4PuppijetSV1massToken_, ak4PuppijetSV1massHandle);
    iEvent.getByToken(ak4PuppijetAreaToken_, ak4PuppijetAreaHandle);
    iEvent.getByToken(ak4PuppijetCSVv2Token_, ak4PuppijetCSVv2Handle);
    iEvent.getByToken(ak4Puppijettau1Token_, ak4Puppijettau1Handle);
    iEvent.getByToken(ak4Puppijettau2Token_, ak4Puppijettau2Handle);
    iEvent.getByToken(ak4Puppijettau3Token_, ak4Puppijettau3Handle);

    iEvent.getByToken(ak4PuppijetneutralHadronEnergyFracToken_, ak4PuppijetneutralHadronEnergyFracHandle);
    iEvent.getByToken(ak4PuppijetneutralEmEnergyFracToken_, ak4PuppijetneutralEmEnergyFracHandle);
    iEvent.getByToken(ak4PuppijetchargedHadronEnergyFracToken_, ak4PuppijetchargedHadronEnergyFracHandle);
    iEvent.getByToken(ak4PuppijetMuonEnergyToken_, ak4PuppijetMuonEnergyHandle);
    iEvent.getByToken(ak4PuppijetchargedMultiplicityToken_, ak4PuppijetchargedMultiplicityHandle);
    iEvent.getByToken(ak4PuppijetneutralMultiplicityToken_, ak4PuppijetneutralMultiplicityHandle);
    iEvent.getByToken(ak4PuppijetchargedEmEnergyFracToken_, ak4PuppijetchargedEmEnergyFracHandle);
    //    iEvent.getByToken(ak4PuppijetNumConstituentsToken_, ak4PuppijetNumConstituentsHandle);


    iEvent.getByToken(ak4PuppijetJERSFToken_, ak4PuppiJERSFHandle);
    iEvent.getByToken(ak4PuppijetJERSFUpToken_, ak4PuppiJERSFUpHandle);
    iEvent.getByToken(ak4PuppijetJERSFDownToken_, ak4PuppiJERSFDownHandle);

  }
  bool MET_filters = true;
  //Copied directly from B2GTTbar because it was more efficient than the way I did it

  vector <string> filterFlags;
  filterFlags.push_back("Flag_goodVertices");
  filterFlags.push_back("Flag_globalTightHalo2016Filter");
  filterFlags.push_back("Flag_HBHENoiseFilter");
  filterFlags.push_back("Flag_HBHENoiseIsoFilter");
  filterFlags.push_back("Flag_EcalDeadCellTriggerPrimitiveFilter");
  filterFlags.push_back("Flag_eeBadScFilter");
  filterFlags.push_back("Flag_muonBadTrackFilter");
  filterFlags.push_back("Flag_chargedHadronTrackResolutionFilter");

  for (unsigned int i = 0; i < METBitTreeHandle->size(); i++){
    if ( std::find( filterFlags.begin(), filterFlags.end(), METNameTreeHandle->at(i) ) != filterFlags.end() ) {
      if ((*METBitTreeHandle)[i] == 0){
	MET_filters = false;
      }
    }
  }

  if (MET_filters){

    double AK8_JEC_UNCERT = 0;
    double AK4_JEC_UNCERT = 0;
    double ak8correction = 1;
    double ak4correction = 1;
    double rho = (*RhoHandle);
    float Run_Number = 0;
    //Code now only saves the leading 4 ak8 and ak4 jets, presumably any signal events would have the 2W and 2b jets in the leading 4 of an event (Need 4 for both to ensure we don't overlap W/b jets
    //May run into trouble with low mass T' where there is less merging of the W jets?
    float HT800_Count = 0;
    float Iso_Mu_Count = 0;
    float Any_Mu_Count = 0;
    float Single_Jet_Count = 0;
    float Trim_Count = 0;
    ULong64_t Event_Number = 0;
    float Weight = 1;
    //  tree_had->SetBranchAddress("HT", &HT);
    tree_had->SetBranchAddress("HT800_Count", &HT800_Count);
    tree_had->SetBranchAddress("Iso_Mu_Count", &Iso_Mu_Count);
    tree_had->SetBranchAddress("Any_Mu_Count", &Any_Mu_Count);
    tree_had->SetBranchAddress("Trim_Count", &Trim_Count);
    tree_had->SetBranchAddress("Single_Jet_Count", &Single_Jet_Count);
    tree_had->SetBranchAddress("Run_Number", &Run_Number);
    tree_had->SetBranchAddress("Event_Number", &Event_Number);
    tree_had->SetBranchAddress("Weight", &Weight);
    if (!Data){
      Weight = generatorHandle->weight();
    }
    std::vector<float> *PartID = new std::vector<float>;
    std::vector<float> *Dau0ID = new std::vector<float>;
    std::vector<float> *Dau1ID = new std::vector<float>;
    //    std::vector<float> *MomID = new std::vector<float>;

    if (Signal_MC){
      for(unsigned int i = 0; i < GenParticleHandle->size(); ++ i) {
	const GenParticle & p = (*GenParticleHandle)[i];
	float id = p.pdgId();
	PartID->push_back(id);
	unsigned int n = p.numberOfDaughters();
	if (n > 1){
	  const Candidate * d0 = p.daughter(0);
	  const Candidate * d1 = p.daughter(1);
	  Dau0ID->push_back(d0->pdgId());
          Dau1ID->push_back(d1->pdgId());
	}
	if (n == 0){
	  Dau0ID->push_back(999);
          Dau1ID->push_back(999);
	}
	if (n == 1){
          const Candidate * d0 = p.daughter(0);
	  Dau0ID->push_back(d0->pdgId());
          Dau1ID->push_back(999);
	}
      }
      hadTreeVars["GenID"] = (*PartID);
      hadTreeVars["Daughter0ID"] = (*Dau0ID);
      hadTreeVars["Daughter1ID"] = (*Dau1ID);
    }
 

    
    for (unsigned int i = 0; i < triggerBitTreeHandle->size(); i++){
      if((*triggerNameTreeHandle)[i].find("PFHT800") !=string::npos){
	if (triggerBitTreeHandle->at(i) == 1){
	HT800_Count = 1;
	}
      }
      if((*triggerNameTreeHandle)[i].find("IsoMu") !=string::npos){ //Currently this means any IsoMu trigger that fires gets counted                                                           
	if ((*triggerBitTreeHandle)[i] == 1){
	  Iso_Mu_Count = 1;
	}
      }
      if((*triggerNameTreeHandle)[i].find("SingleMu") !=string::npos){
        if ((*triggerBitTreeHandle)[i] == 1){
          Any_Mu_Count = 1;
        }
      }

      if((*triggerNameTreeHandle)[i].find("HLT_AK8PFHT700_TrimR0p1PT0p03Mass50") !=string::npos){
	if ((*triggerBitTreeHandle)[i] == 1){
	  Trim_Count = 1;
	}
      }
      if((*triggerNameTreeHandle)[i].find("PFJet400") !=string::npos){ //Currently this means any version of PFJet400 trigger that fires gets counted                                          
	if ((*triggerBitTreeHandle)[i] == 1){
	  Single_Jet_Count = 1;
	}
      }
    }
    
    Run_Number = (*evtInfoRunNumberHandle);
    Event_Number = (*evtInfoEventNumberHandle);
    if (!Puppi){
      if ((ak8CHSjetPtHandle->size()) > 1){
	if (((*ak8CHSjetPtHandle)[0] > 180) && ((*ak8CHSjetPtHandle)[1] > 180) && ((*ak8CHSjetEtaHandle)[0] < 2.4) && ((*ak8CHSjetEtaHandle)[1] < 2.4)){
	  for (unsigned int i = 0; (i < ak8CHSjetPtHandle->size()); i++){
	    //	  HT+= (*ak8CHSjetPtHandle)[i];
	  }
	  //	hadTreeVars["HT"] = HT;
	  hadTreeVars[("jetak8RawPtCHS")] = (*ak8CHSjetPtHandle);
	  hadTreeVars[("jetak8RawEtaCHS")] = (*ak8CHSjetEtaHandle);
	  hadTreeVars[("jetak8RawPhiCHS")] = (*ak8CHSjetPhiHandle);
          hadTreeVars[("jetak8RawECHS")] = (*ak8CHSjetEHandle);
	  hadTreeVars[("jetak8CHSsoftmass")] = (*ak8CHSjetsoftMassHandle);
	  hadTreeVars[("jetak8CHStrimmass")] = (*ak8CHSjettrimMassHandle);
	  hadTreeVars[("jetak8CHStau1")] = (*ak8CHSjettau1Handle);
	  hadTreeVars[("jetak8CHStau2")] = (*ak8CHSjettau2Handle);
	  hadTreeVars[("jetak8CHStau3")] = (*ak8CHSjettau3Handle);
	  std::vector<float> *ak8CHSjettau21 = new std::vector<float>;
	  std::vector<float> *ak8CHSjettau32 = new std::vector<float>;
	  for (unsigned int i = 0; i < ak8CHSjetPtHandle->size(); i++){
	    ak8CHSjettau21->push_back(((*ak8CHSjettau2Handle)[i])/((*ak8CHSjettau1Handle)[i]));
	    ak8CHSjettau32->push_back(((*ak8CHSjettau3Handle)[i])/((*ak8CHSjettau2Handle)[i]));
	  }
	  hadTreeVars[("jetak8CHStau21")] = (*ak8CHSjettau21);
	  hadTreeVars[("jetak8CHStau32")] = (*ak8CHSjettau32);
	  delete ak8CHSjettau21;
	  delete ak8CHSjettau32;
	  std::vector<float> *ak8correctionvector = new std::vector<float>;
	  std::vector<float> *ak8uncertvector = new std::vector<float>;

	  for (unsigned int i = 0; (i < ak8CHSjetPtHandle->size()); i++){
	    JetCorrectorAK8->setJetEta((*ak8CHSjetEtaHandle)[i]);
	    JetCorrectorAK8->setJetPt((*ak8CHSjetPtHandle)[i]);
	    JetCorrectorAK8->setJetA((*ak8CHSjetAreaHandle)[i]);
	    JetCorrectorAK8->setRho(rho);
	    ak8correction = JetCorrectorAK8->getCorrection();
	    ak8jecUnc->setJetEta((*ak8CHSjetEtaHandle)[i]);
	    ak8jecUnc->setJetPt(ak8correction * (*ak8CHSjetPtHandle)[i]);
	    AK8_JEC_UNCERT = ak8jecUnc->getUncertainty(true);
	    ak8correctionvector->push_back(ak8correction);
	    ak8uncertvector->push_back(AK8_JEC_UNCERT);
	    hadTreeVars[("jetak8CHSJECSF")] = (*ak8correctionvector);
	    hadTreeVars[("jetak8CHSJECUncert")] = (*ak8uncertvector);
	  }
	  hadTreeVars[("jetak8CHSJERSF")] = (*ak8CHSJERSFHandle);
	  hadTreeVars[("jetak8CHSJERUp")] = (*ak8CHSJERSFUpHandle);
	  hadTreeVars[("jetak8CHSJERDown")] = (*ak8CHSJERSFDownHandle);

	  hadTreeVars["ak8NHEF"] = *ak8CHSjetneutralHadronEnergyFracHandle;
	  hadTreeVars["ak8NEEF"] = *ak8CHSjetneutralEmEnergyFracHandle;
	  hadTreeVars["ak8CHEF"] = *ak8CHSjetchargedHadronEnergyFracHandle;
	  hadTreeVars["ak8MEF"] = *ak8CHSjetMuonEnergyHandle;
	  hadTreeVars["ak8CM"] = *ak8CHSjetchargedMultiplicityHandle;
	  hadTreeVars["ak8CEEF"] = *ak8CHSjetchargedEmEnergyFracHandle;
          hadTreeVars["ak8NM"] = *ak8CHSjetneutralMultiplicityHandle;
	  std::vector<float> *ak8numcon = new std::vector<float>;
	  for (unsigned int j = 0; j < ak8CHSjetchargedMultiplicityHandle->size(); j++){
	    ak8numcon->push_back((*ak8CHSjetchargedMultiplicityHandle)[j] + (*ak8CHSjetneutralMultiplicityHandle)[j]);
	  }
	  hadTreeVars["ak8NC"] = *ak8numcon;


	  delete ak8correctionvector;
	  delete ak8uncertvector;
	  delete ak8numcon;
	  hadTreeVars[("jetak4RawPtCHS")] = (*ak4CHSjetPtHandle);
	  hadTreeVars[("jetak4RawEtaCHS")] = (*ak4CHSjetEtaHandle);
	  hadTreeVars[("jetak4RawPhiCHS")] = (*ak4CHSjetPhiHandle);
          hadTreeVars[("jetak4RawECHS")] = (*ak4CHSjetEHandle);
	  hadTreeVars[("jetak4SV0massCHS")] = (*ak4CHSjetSV0massHandle);
          hadTreeVars[("jetak4SV1massCHS")] = (*ak4CHSjetSV1massHandle);
	  hadTreeVars[("jetak4CHSCSVv2")] = (*ak4CHSjetCSVv2Handle);

	  std::vector<float> *ak4correctionvector = new std::vector<float>;
	  std::vector<float> *ak4uncertvector = new std::vector<float>;
	  for (unsigned int i = 0; (i < ak4CHSjetPtHandle->size()); i++){
	    JetCorrectorAK4->setJetEta((*ak4CHSjetEtaHandle)[i]);
	    JetCorrectorAK4->setJetPt((*ak4CHSjetPtHandle)[i]);
	    JetCorrectorAK4->setJetA((*ak4CHSjetAreaHandle)[i]);
	    JetCorrectorAK4->setRho(rho);
	    ak4correction = JetCorrectorAK4->getCorrection();
	    ak4jecUnc->setJetEta((*ak4CHSjetEtaHandle)[i]);
	    ak4jecUnc->setJetPt(ak4correction * (*ak4CHSjetPtHandle)[i]);
	    AK4_JEC_UNCERT = ak4jecUnc->getUncertainty(true);
	    ak4correctionvector->push_back(ak4correction);
	    ak4uncertvector->push_back(AK4_JEC_UNCERT);
	    hadTreeVars[("jetak4CHSJECSF")] = (*ak4correctionvector);
	    hadTreeVars[("jetak4CHSJECUncert")] = (*ak4uncertvector);
	  }
          hadTreeVars[("jetak4CHSJERSF")] = (*ak4CHSJERSFHandle);
          hadTreeVars[("jetak4CHSJERUp")] = (*ak4CHSJERSFUpHandle);
          hadTreeVars[("jetak4CHSJERDown")] = (*ak4CHSJERSFDownHandle);

          hadTreeVars["ak4NHEF"] = *ak4CHSjetneutralHadronEnergyFracHandle;
          hadTreeVars["ak4NEEF"] = *ak4CHSjetneutralEmEnergyFracHandle;
          hadTreeVars["ak4CHEF"] = *ak4CHSjetchargedHadronEnergyFracHandle;
          hadTreeVars["ak4MEF"] = *ak4CHSjetMuonEnergyHandle;
          hadTreeVars["ak4CM"] = *ak4CHSjetchargedMultiplicityHandle;
          hadTreeVars["ak4CEEF"] = *ak4CHSjetchargedEmEnergyFracHandle;
          hadTreeVars["ak4NM"] = *ak4CHSjetneutralMultiplicityHandle;
	  std::vector<float> *ak4numcon = new std::vector<float>;
          for (unsigned int j = 0; j < ak4CHSjetchargedMultiplicityHandle->size(); j++){
            ak4numcon->push_back((*ak4CHSjetchargedMultiplicityHandle)[j] + (*ak4CHSjetneutralMultiplicityHandle)[j]);
          }
          hadTreeVars["ak4NC"] = *ak4numcon;

          delete ak4correctionvector;
          delete ak4uncertvector;
	  delete ak4numcon;
	  //	  hadTreeVars["numak8jets"] = (*ak8CHSjetPtHandle).size();
	  // hadTreeVars["numak4jets"] = (*ak4CHSjetPtHandle).size();
	  tree_had->Fill();
	}
      }
    }

    if (Puppi){
      if ((ak8PuppijetPtHandle->size()) > 1){
	if (((*ak8PuppijetPtHandle)[0] > 180) && ((*ak8PuppijetPtHandle)[1] > 180) && ((*ak8PuppijetEtaHandle)[0] < 2.4) && ((*ak8PuppijetEtaHandle)[1] < 2.4)){
	  //ak8PuppijetPt = (*ak8PuppijetPtHandle);
	  hadTreeVars[("jetak8RawPtPuppi")] = (*ak8PuppijetPtHandle);
	  hadTreeVars[("jetak8RawEtaPuppi")] = (*ak8PuppijetEtaHandle);
	  hadTreeVars[("jetak8RawPhiPuppi")] = (*ak8PuppijetPhiHandle);
          hadTreeVars[("jetak8RawEPuppi")] = (*ak8PuppijetEHandle);
	  hadTreeVars[("jetak8Puppisoftmass")] = (*ak8PuppijetsoftMassHandle);
	  hadTreeVars[("jetak8Puppitrimmass")] = (*ak8PuppijettrimMassHandle);
	  hadTreeVars[("jetak8Puppitau1")] = (*ak8Puppijettau1Handle);
	  hadTreeVars[("jetak8Puppitau2")] = (*ak8Puppijettau2Handle);
	  hadTreeVars[("jetak8Puppitau3")] = (*ak8Puppijettau3Handle);
	  std::vector<float> *ak8Puppijettau21 = new std::vector<float>;
	  std::vector<float> *ak8Puppijettau32 = new std::vector<float>;
	  for (unsigned int i = 0; i < ak8PuppijetPtHandle->size(); i++){
	    ak8Puppijettau21->push_back(((*ak8Puppijettau2Handle)[i])/((*ak8Puppijettau1Handle)[i]));
	    ak8Puppijettau32->push_back(((*ak8Puppijettau3Handle)[i])/((*ak8Puppijettau2Handle)[i]));
	  }
	  hadTreeVars[("jetak8Puppitau21")] = (*ak8Puppijettau21);
	  hadTreeVars[("jetak8Puppitau32")] = (*ak8Puppijettau32);
	  delete ak8Puppijettau21;
	  delete ak8Puppijettau32;
	  std::vector<float> *ak8correctionvector = new std::vector<float>;
	  std::vector<float> *ak8uncertvector = new std::vector<float>;

	  for (unsigned int i = 0; (i < ak8PuppijetPtHandle->size()); i++){
	    JetCorrectorAK8->setJetEta((*ak8PuppijetEtaHandle)[i]);
	    JetCorrectorAK8->setJetPt((*ak8PuppijetPtHandle)[i]);
	    JetCorrectorAK8->setJetA((*ak8PuppijetAreaHandle)[i]);
	    JetCorrectorAK8->setRho(rho);
	    ak8correction = JetCorrectorAK8->getCorrection();
	    ak8jecUnc->setJetEta((*ak8PuppijetEtaHandle)[i]);
	    ak8jecUnc->setJetPt(ak8correction * (*ak8PuppijetPtHandle)[i]);
	    AK8_JEC_UNCERT = ak8jecUnc->getUncertainty(true);
	    ak8correctionvector->push_back(ak8correction);
	    ak8uncertvector->push_back(AK8_JEC_UNCERT);
	    hadTreeVars[("jetak8PuppiJECSF")] = (*ak8correctionvector);
	    hadTreeVars[("jetak8PuppiJECUncert")] = (*ak8uncertvector);
	  }
	  hadTreeVars[("jetak8PuppiJERSF")] = (*ak8PuppiJERSFHandle);
	  hadTreeVars[("jetak8PuppiJERUp")] = (*ak8PuppiJERSFUpHandle);
	  hadTreeVars[("jetak8PuppiJERDown")] = (*ak8PuppiJERSFDownHandle);

          hadTreeVars["ak8NHEF"] = *ak8PuppijetneutralHadronEnergyFracHandle;
          hadTreeVars["ak8NEEF"] = *ak8PuppijetneutralEmEnergyFracHandle;
          hadTreeVars["ak8CHEF"] = *ak8PuppijetchargedHadronEnergyFracHandle;
          hadTreeVars["ak8MEF"] = *ak8PuppijetMuonEnergyHandle;
          hadTreeVars["ak8CM"] = *ak8PuppijetchargedMultiplicityHandle;
          hadTreeVars["ak8CEEF"] = *ak8PuppijetchargedEmEnergyFracHandle;
          hadTreeVars["ak8NM"] = *ak8PuppijetneutralMultiplicityHandle;
	  std::vector<float> *ak8numcon = new std::vector<float>;
          for (unsigned int j = 0; j < ak8PuppijetchargedMultiplicityHandle->size(); j++){
            ak8numcon->push_back((*ak8PuppijetchargedMultiplicityHandle)[j] + (*ak8PuppijetneutralMultiplicityHandle)[j]);
          }
          hadTreeVars["ak8NC"] = *ak8numcon;



	  delete ak8correctionvector;
	  delete ak8uncertvector;
	  delete ak8numcon;
	  hadTreeVars[("jetak4RawPtPuppi")] = (*ak4PuppijetPtHandle);
	  hadTreeVars[("jetak4RawEtaPuppi")] = (*ak4PuppijetEtaHandle);
	  hadTreeVars[("jetak4RawPhiPuppi")] = (*ak4PuppijetPhiHandle);
          hadTreeVars[("jetak4RawEPuppi")] = (*ak4PuppijetEHandle);
	  hadTreeVars[("jetak4SV0massPuppi")] = (*ak4PuppijetSV0massHandle);
          hadTreeVars[("jetak4SV1massPuppi")] = (*ak4PuppijetSV1massHandle);
	  hadTreeVars[("jetak4PuppiCSVv2")] = (*ak4PuppijetCSVv2Handle);

	  std::vector<float> *ak4correctionvector = new std::vector<float>;
	  std::vector<float> *ak4uncertvector = new std::vector<float>;
	  for (unsigned int i = 0; (i < ak4PuppijetPtHandle->size()); i++){
	    JetCorrectorAK4->setJetEta((*ak4PuppijetEtaHandle)[i]);
	    JetCorrectorAK4->setJetPt((*ak4PuppijetPtHandle)[i]);
	    JetCorrectorAK4->setJetA((*ak4PuppijetAreaHandle)[i]);
	    JetCorrectorAK4->setRho(rho);
	    ak4correction = JetCorrectorAK4->getCorrection();
	    ak4jecUnc->setJetEta((*ak4PuppijetEtaHandle)[i]);
	    ak4jecUnc->setJetPt(ak4correction * (*ak4PuppijetPtHandle)[i]);
	    AK4_JEC_UNCERT = ak4jecUnc->getUncertainty(true);
	    ak4correctionvector->push_back(ak4correction);
	    ak4uncertvector->push_back(AK4_JEC_UNCERT);
	    hadTreeVars[("jetak4PuppiJECSF")] = (*ak4correctionvector);
	    hadTreeVars[("jetak4PuppiJECUncert")] = (*ak4uncertvector);
	  }
	  hadTreeVars[("jetak4PuppiJERSF")] = (*ak4PuppiJERSFHandle);
	  hadTreeVars[("jetak4PuppiJERUp")] = (*ak4PuppiJERSFUpHandle);
	  hadTreeVars[("jetak4PuppiJERDown")] = (*ak4PuppiJERSFDownHandle);

          hadTreeVars["ak4NHEF"] = *ak4PuppijetneutralHadronEnergyFracHandle;
          hadTreeVars["ak4NEEF"] = *ak4PuppijetneutralEmEnergyFracHandle;
          hadTreeVars["ak4CHEF"] = *ak4PuppijetchargedHadronEnergyFracHandle;
          hadTreeVars["ak4MEF"] = *ak4PuppijetMuonEnergyHandle;
          hadTreeVars["ak4CM"] = *ak4PuppijetchargedMultiplicityHandle;
          hadTreeVars["ak4CEEF"] = *ak4PuppijetchargedEmEnergyFracHandle;
          hadTreeVars["ak4NM"] = *ak4PuppijetneutralMultiplicityHandle;
	  std::vector<float> *ak4numcon = new std::vector<float>;
          for (unsigned int j = 0; j < ak4PuppijetchargedMultiplicityHandle->size(); j++){
            ak4numcon->push_back((*ak4PuppijetchargedMultiplicityHandle)[j] + (*ak4PuppijetneutralMultiplicityHandle)[j]);
          }
          hadTreeVars["ak4NC"] = *ak4numcon;

	  delete ak4numcon;
	  delete ak4correctionvector;
	  delete ak4uncertvector;
	  //	hadTreeVars["numak8jets"] = (*ak8PuppijetPtHandle).size();
	  //	hadTreeVars["numak4jets"] = (*ak4PuppijetPtHandle).size();
	  tree_had->Fill();
	}
      }
    }
    delete PartID;
    delete Dau0ID;
    delete Dau1ID;
    //    delete MomID;

    /*
    #ifdef THIS_IS_AN_EVENT_EXAMPLE
    Handle<ExampleData> pIn;
    iEvent.getByLabel("example",pIn);
    #endif
   
    #ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
    ESHandle<SetupData> pSetup;
    iSetup.get<SetupRecord>().get(pSetup);
    #endif
  */
  }
}

// ------------ method called once each job just before starting event loop  ------------
void 
TPRIME::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TPRIME::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
TPRIME::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(TPRIME);

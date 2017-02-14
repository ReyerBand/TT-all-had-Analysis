import FWCore.ParameterSet.Config as cms

process = cms.Process("B2GNtuple")

process.load("FWCore.MessageService.MessageLogger_cfi")
process.load('JetMETCorrections.Configuration.JetCorrectors_cff')
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1),
                                        allowUnscheduled = cms.untracked.bool(True))

process.MessageLogger.cerr.FwkReport.reportEvery = 1000

###############################################################################
#INPUT
#text_file = open("input/JetHT_Run2015B_B2GAnaFW_v74x_V5p1_DATA.txt", "r")
#lines = text_file.readlines()
#print lines

#files = cms.untracked.vstring()
#files.extend(lines)

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use                                                                                                                                                                              
    #fileNames = cms.untracked.vstring("/store/user/knash/JetHT/crab_Run2015D-PromptReco-v3_Oct9_v74x_V7_25ns_v2/151013_175415/0000/B2GEDMNtuple_1.root")
    #fileNames = cms.untracked.vstring("/store/user/jdolen/B2GAnaFW/JetHT/Run2015D-05Oct2015-v1/JetHT/B2GAnaFW_v74x_V8p2_25ns/151023_194322/0000/B2GEDMNtuple_1.root")
     #fileNames = cms.untracked.vstring("/store/user/jpilot/ZprimeToTT_M-1000_W-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/B2GAnaFW_v74x_V6p1_25ns_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/151012_125345/0000/B2GEDMNtuple_1.root", "/store/user/jpilot/ZprimeToTT_M-1000_W-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/B2GAnaFW_v74x_V6p1_25ns_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/151012_125345/0000/B2GEDMNtuple_2.root", "/store/user/jpilot/ZprimeToTT_M-1000_W-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/B2GAnaFW_v74x_V6p1_25ns_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/151012_125345/0000/B2GEDMNtuple_3.root", "/store/user/jpilot/ZprimeToTT_M-1000_W-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/B2GAnaFW_v74x_V6p1_25ns_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/151012_125345/0000/B2GEDMNtuple_4.root", "/store/user/jpilot/ZprimeToTT_M-1000_W-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/B2GAnaFW_v74x_V6p1_25ns_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/151012_125345/0000/B2GEDMNtuple_5.root", "/store/user/jpilot/ZprimeToTT_M-1000_W-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/B2GAnaFW_v74x_V6p1_25ns_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/151012_125345/0000/B2GEDMNtuple_6.root", "/store/user/jpilot/ZprimeToTT_M-1000_W-100_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/B2GAnaFW_v74x_V6p1_25ns_RunIISpring15DR74-Asympt25ns_MCRUN2_74_V9-v2/151012_125345/0000/B2GEDMNtuple_7.root")
    fileNames = cms.untracked.vstring("/store/group/lpctlbsm/B2GAnaFW_80X_V1p0/JetHT/RunIISpring16MiniAODv2_B2GAnaFW_80x_V1p0/160718_083513/0000/B2GEDMNtuple_1.root")
    #fileNames = files
)

###############################################################################
#PRODUCER
process.b2gntuple = cms.EDAnalyzer('TPRIME',
                                   #testSrc = cms.string('hola')
                                   #negativeWeights = cms.bool(True),
                                   #isMC = cms.bool(True),
                                   #isFlat = cms.bool(False),
                                   #applyFilters = cms.bool(True),
                                   JERshift = cms.double(0),
                                   JECshift = cms.double(0),
                                   Data = cms.bool(True),
                                   Signal_MC = cms.bool(False),
                                   Puppi = cms.bool(True),
                                   #reweightTopPt = cms.bool(False),
                                   L1AK8File = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_L1FastJet_AK8PFchs.txt'),
                                   L2AK8File = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_L2Relative_AK8PFchs.txt'),
                                   L3AK8File = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_L3Absolute_AK8PFchs.txt'),
                                   L23AK8File = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_L2L3Residual_AK8PFchs.txt'),
                                   L1AK4File = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_L1FastJet_AK4PFchs.txt'),
                                   L2AK4File = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_L2Relative_AK4PFchs.txt'),
                                   L3AK4File = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_L3Absolute_AK4PFchs.txt'),
                                   L23AK4File = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_L2L3Residual_AK4PFchs.txt'),
                                   AK8UncertFile = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_Uncertainty_AK8PFchs.txt'),
                                   AK4UncertFile = cms.string('80X_dataRun2_Prompt_ICHEP16JEC_v0_Uncertainty_AK4PFchs.txt'),
                                   )

###############################################################################
#OUTPUT
 
#process.TFileService = cms.Service("TFileService", fileName = cms.string("histo_DATA.root"))
process.TFileService = cms.Service("TFileService", fileName = cms.string("Result.root") )

process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string("Out.root"),
                               outputCommands = cms.untracked.vstring('drop *'))

process.p = cms.Path(process.b2gntuple)
process.outpath = cms.EndPath(process.out)

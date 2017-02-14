from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'TprimeTprime_M-1600'
config.General.workArea = 'TprimeTprime_1600GeV'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.inputFiles = ['80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK8PFchs.txt']

config.JobType.psetName = 'TT_cfg.py'
config.JobType.outputFiles = ['Result.root']

config.section_("Data")
config.Data.inputDataset = '/TprimeTprime_M-1600_TuneCUETP8M1_13TeV-madgraph-pythia8/vorobiev-B2GAnaFW_RunIISpring16MiniAODv2_25ns_v80x_v2p0-a5c23f9700079f8bc7b9d2b4fb46cf81/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.ignoreLocality = True
config.Data.publication = False
# This string is used to construct the output dataset name

config.section_("Site")
config.Site.whitelist = ['T2_CH_*']
config.Site.storageSite = 'T3_US_FNALLPC'


from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'TprimeTprime_ttbar_background'
config.General.workArea = 'ttbar'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.inputFiles = ['80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK8PFchs.txt']

config.JobType.psetName = 'TT_cfg.py'
config.JobType.outputFiles = ['Result.root']

config.section_("Data")
config.Data.inputDataset = '/TT_TuneCUETP8M1_13TeV-powheg-pythia8/asparker-RunIISpring16MiniAODv2_B2GAnaFW_80x_V2p0-9c09e10dd1f806cf9fdf5818b1c7d288/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.ignoreLocality = True
config.Data.publication = False
# This string is used to construct the output dataset name

config.section_("Site")
config.Site.whitelist = ['T2_US_*']
config.Site.storageSite = 'T3_US_FNALLPC'


from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'TT_QCD_background_100to200'
config.General.workArea = 'QCD'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.inputFiles = ['80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1FastJet_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L1RC_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2L3Residual_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L2Relative_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_L3Absolute_AK8PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK4PF.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK4PFchs.txt', '80X_mcRun2_asymptotic_2016_miniAODv2_v1_Uncertainty_AK8PFchs.txt']

config.JobType.psetName = 'TT_cfg.py'
config.JobType.outputFiles = ['Result.root']

config.section_("Data")
config.Data.inputDataset = '/QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8/grauco-b2ganafw80xv1_QCD_HT100to200_TuneCUETP8M1_13TeV-madgraphMLM-pythia8_03Jul-00167b1786e7451729dcc6725ee3b1a8/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.ignoreLocality = True
config.Data.publication = False
# This string is used to construct the output dataset name

config.section_("Site")
config.Site.whitelist = ['T2_US_*']
config.Site.blacklist = ['T2_US_Nebraska']
config.Site.storageSite = 'T3_US_FNALLPC'


from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'Data2016_Analysis'
config.General.workArea = 'Data2016'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.inputFiles = ['80X_dataRun2_Prompt_ICHEP16JEC_v0_L1FastJet_AK4PF.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L1FastJet_AK4PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L1FastJet_AK8PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L1RC_AK4PF.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L1RC_AK4PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L1RC_AK8PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L2L3Residual_AK4PF.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L2L3Residual_AK4PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L2L3Residual_AK8PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L2Relative_AK4PF.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L2Relative_AK4PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L2Relative_AK8PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L3Absolute_AK4PF.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L3Absolute_AK4PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_L3Absolute_AK8PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_Uncertainty_AK4PF.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_Uncertainty_AK4PFchs.txt', '80X_dataRun2_Prompt_ICHEP16JEC_v0_Uncertainty_AK8PFchs.txt']

config.JobType.psetName = 'TT_cfg_data.py'
config.JobType.outputFiles = ['Result.root']

config.section_("Data")
config.Data.inputDataset = '/JetHT/asparker-RunIISpring16MiniAODv2_B2GAnaFW_80x_V1p0-c9ad27f972ae59d36cd924fb5f87408c/USER'
config.Data.inputDBS = 'phys03'
config.Data.splitting = 'FileBased'
config.Data.unitsPerJob = 10
config.Data.ignoreLocality = True
config.Data.publication = False
# This string is used to construct the output dataset name

config.section_("Site")
#config.Site.whitelist = ['T2_US_*']
config.Site.blacklist = ['T2_US_Nebraska', 'T3_US_UMiss']
config.Site.storageSite = 'T3_US_FNALLPC'


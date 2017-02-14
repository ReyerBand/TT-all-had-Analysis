from WMCore.Configuration import Configuration
config = Configuration()

config.section_("General")
config.General.requestName = 'Data_Jet_Ht'
config.General.workArea = 'Data_JetHt'
config.General.transferLogs = True

config.section_("JobType")
config.JobType.pluginName = 'Analysis'
config.JobType.psetName = 'TT_cfg.py'
config.JobType.outputFiles = ['Data_Result.root']

config.section_("Data")
config.Data.inputDataset = '/JetHT/devdatta-B2GAnaFW_76X_V1p3-c4c3f6dc16a584b6ec5462c242b1cbe4/USER'
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


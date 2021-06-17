#from WMCore.Configuration import Configuration
import CRABClient
from dbs.apis.dbsClient import DbsApi
from CRABClient.UserUtilities import Configuration#, getUsernameFromSiteDB
config = Configuration()

datasetnames = [
'/MuOnia/Run2016B-21Feb2020_ver1_UL2016_HIPM-v1/MINIAOD', 
'/MuOnia/Run2016B-21Feb2020_ver2_UL2016_HIPM-v1/MINIAOD', 
'/MuOnia/Run2016C-21Feb2020_UL2016_HIPM-v1/MINIAOD', 
'/MuOnia/Run2016D-21Feb2020_UL2016_HIPM-v1/MINIAOD', 
'/MuOnia/Run2016E-21Feb2020_UL2016_HIPM-v1/MINIAOD', 
'/MuOnia/Run2016F-21Feb2020_UL2016_HIPM-v1/MINIAOD', 

'/MuOnia/Run2016F-21Feb2020_UL2016-v1/MINIAOD',
'/MuOnia/Run2016G-21Feb2020_UL2016-v1/MINIAOD', 
'/MuOnia/Run2016H-21Feb2020_UL2016-v1/MINIAOD', 

'/MuOnia/Run2017B-09Aug2019_UL2017-v1/MINIAOD', 
'/MuOnia/Run2017C-09Aug2019_UL2017-v1/MINIAOD', 
'/MuOnia/Run2017D-09Aug2019_UL2017-v1/MINIAOD', 
'/MuOnia/Run2017E-09Aug2019_UL2017-v1/MINIAOD', 
'/MuOnia/Run2017F-09Aug2019_UL2017-v1/MINIAOD', 

'/MuOnia/Run2018A-12Nov2019_UL2018-v1/MINIAOD', 
'/MuOnia/Run2018B-12Nov2019_UL2018-v1/MINIAOD', 
'/MuOnia/Run2018C-12Nov2019_UL2018-v1/MINIAOD', 
'/MuOnia/Run2018D-12Nov2019_UL2018-v1/MINIAOD'
]

psetS = [
'run-upspipi-miniaod2016.py',
'run-chipipi-miniaod2016.py',
'run-upspipi-miniaod2017.py',
'run-chipipi-miniaod2017.py',
'run-upspipi-miniaod.py',
'run-chipipi-miniaod.py'
]

#runNumber = [
#'',
#'297620,297656',
#'299420'
#]

decays = [
'1Spipi',
'1Ppipi'
]

jsonfile = [
'',
'/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Legacy_2016/Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON_MuonPhys.txt',
'/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/Legacy_2017/Cert_294927-306462_13TeV_UL2017_Collisions17_MuonJSON.txt',
'/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/Legacy_2018/Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON_MuonPhys.txt'
]

#eventsPerJob = [
#10,
#20
#]

workDir = 'XbDecays_2018DataRunII_UL_miniAODv2_v1'
decay = decays[1]
pset = psetS[1]
#runNum = runNumber[0]
lumi = jsonfile[3] #no json: 0, 2016json: 1, 2017json: 2, 2018json: 3
#epj = eventsPerJob[0]

datasetName = datasetnames[3]	

print "*****************"
print decay
print pset
print datasetName
print "*****************"

import datetime
timestamp = datetime.datetime.now().strftime("_%Y%m%d_%H%M%S")

dataset = filter(None, datasetName.split('/'))

config.section_('General')
config.General.transferOutputs  = True
config.General.workArea         = '%s' % (workDir)
#config.General.requestName      = dataset[0]+'_'+dataset[1]+'_'+dataset[2]+'_'+runNum+'_'+decay+'_dM1'+timestamp
config.General.requestName      = dataset[0]+'_'+dataset[1]+'_'+dataset[2]+'_'+decay+timestamp
config.General.transferLogs     = False

config.section_('JobType')
config.JobType.psetName         = pset
config.JobType.pluginName       = 'Analysis'
#config.JobType.priority			= 20
config.JobType.numCores 		= 4
config.JobType.maxMemoryMB      = 10000
#config.JobType.maxJobRuntimeMin = 2750
config.JobType.allowUndistributedCMSSW = True

config.section_('Data')
config.Data.inputDataset        = datasetName
config.Data.inputDBS            = 'global'
#config.Data.totalUnits          = -1
#config.Data.unitsPerJob         = epj
#config.Data.splitting           = 'LumiBased'
config.Data.splitting           = 'Automatic'
#config.Data.runRange            = runNum
config.Data.lumiMask            = lumi
config.Data.outLFNDirBase       = '/store/user/slezki/%s' % (workDir)
config.Data.publication         = False
#config.Data.ignoreLocality      = True

config.section_('Site')
config.Site.storageSite         = 'T2_IT_Bari'
#config.Site.blacklist           = ['T2_TW_NCHC', 'T2_US_Vanderbilt']
#config.Site.blacklist           = ['T1*', 'T2_BR_SPRACE', 'T2_US_Wisconsin', 'T1_RU_JINR', 'T2_RU_JINR', 'T2_EE_Estonia']
#config.Site.whitelist		= ['T2*']

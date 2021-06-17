#!/bin/bash

##
## just use : ./crabCfgCreator.sh
##

echo " "
echo "SL*******************************************************SL"
echo "SL*******************************************************SL"
echo "SL************* MISSION HAS BEEN STARTED ****************SL"
echo "SL*******************************************************SL"
echo "SL*******************************************************SL"
echo "SL************** You can drink a coffee *****************SL"
echo "SL*******************************************************SL"
echo "SL*******************************************************SL"
echo " "

PyFile=crabConfig_Data.py
#rm ${PyFile}

#s1=$1

counter=0

#if [ $s1 == 2016 ]; then
#	start=0
#	finish=8
#elif [ $s1 == 2017 ]; then
#	start=8
#	finish=13
#fi

start=0
finish=9
k=1

for (( i=0; i<6; i++ ))
do

#if [ $i -lt 3 ]; then
#	start=0
#	finish=8
#elif [ $i -ge 3 ]; then
#	start=8
#	finish=13
#fi

if [ $i -ge 2 ] && [ $i -lt 4 ]; then
	start=9
	finish=14
	k=2
elif [ $i -ge 4 ]; then
	start=14
	finish=18
	k=3
fi

for (( j=${start}; j<${finish}; j++ ))
do

counter=$((counter+1))

#if [ $s1 == 2017 ]; then
	#i=$((i+3))
#fi

rm ${PyFile} 
echo "${PyFile} was deleted"
echo " "

echo "i = ${i}"
echo "j = ${j}"
echo " "

#k=1

#if [ $j -gt 7 ]; then 
#	k=2
#fi

echo "k = ${k}"
echo " "

cat>> ${PyFile} <<pyFile
import CRABClient
from dbs.apis.dbsClient import DbsApi
from CRABClient.UserUtilities import Configuration#, getUsernameFromSiteDB
config = Configuration()

psetS = [
'run-upspipi-miniaod2016.py',
'run-chipipi-miniaod2016.py',
'run-upspipi-miniaod2017.py',
'run-chipipi-miniaod2017.py',
'run-upspipi-miniaod.py',
'run-chipipi-miniaod.py'
]

decays = [
'1Spipi',
'1Ppipi',
'1Spipi',
'1Ppipi',
'1Spipi',
'1Ppipi'
]

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
'/MuOnia/Run2018D-12Nov2019_UL2018-v1/MINIAOD',
]

runNumber = [
'',
'297620,297656',
'299420'
]

jsonfile = [
'',
'/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions16/13TeV/Legacy_2016/Cert_271036-284044_13TeV_Legacy2016_Collisions16_JSON_MuonPhys.txt',
'/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions17/13TeV/Legacy_2017/Cert_294927-306462_13TeV_UL2017_Collisions17_MuonJSON.txt',
'/afs/cern.ch/cms/CAF/CMSCOMM/COMM_DQM/certification/Collisions18/13TeV/Legacy_2018/Cert_314472-325175_13TeV_Legacy2018_Collisions18_JSON_MuonPhys.txt'
]

workDir = 'XbDecays_DataRunII_UltraLegacy_miniAOD_v2'
decay = decays[$i]
pset = psetS[$i]
runNum = runNumber[0]
lumi = jsonfile[$k] #no json: 0, 2016json: 1, 2017json: 2, 2018json: 3

datasetName = datasetnames[$j]

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
config.General.requestName      = dataset[0]+'_'+dataset[1]+'_'+dataset[2]+'_'+runNum+'_'+decay+timestamp
config.General.transferLogs     = False

config.section_('JobType')
config.JobType.psetName         = pset
config.JobType.pluginName       = 'Analysis'
config.JobType.allowUndistributedCMSSW = True

config.section_('Data')
config.Data.inputDataset        = datasetName
config.Data.inputDBS            = 'global'
config.Data.splitting           = 'Automatic'
config.Data.runRange            = runNum
config.Data.lumiMask            = lumi
config.Data.outLFNDirBase       = '/store/user/slezki/%s' % (workDir)
config.Data.publication         = False
#config.Data.ignoreLocality      = True

config.section_('Site')
config.Site.storageSite         = 'T2_IT_Bari'

pyFile

echo "${PyFile} was created for ${i} and ${j}"
echo " "

crab submit ${PyFile} 

echo " "
echo "Crab task was submitted for ${i} and ${j}"
echo " "

#if [ $j -eq 12 ]; then 

#rm ${PyFile} 
#echo "${PyFile} was deleted for ${i} and ${j}"
#echo " "

#fi

echo "$counter"

done

done
#echo "$counter"

echo " "
echo "SL***************************************************SL"
echo "SL***************************************************SL"
echo "SL*************** MISSION COMPLETED *****************SL"
echo "SL***************************************************SL"
echo "SL***************************************************SL"
echo "SL**************** Are you here??? ******************SL"
echo "SL***************************************************SL"
echo "SL*********** Please check tasks' status ************SL"
echo "SL***************************************************SL"
echo "SL***************************************************SL"
echo " "

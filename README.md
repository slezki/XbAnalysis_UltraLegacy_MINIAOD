# X_b-Analysis

This package is mean to be run using Ultra Legacy MINIAOD RUN-II

* Setup: (it has being tested on 10_6_20 should run in any of the recent cmssw releases)

```
export SCRAM_ARCH=slc7_amd64_gcc700
scram p -n CMSSW_10620_ul CMSSW_10_6_20
cd CMSSW_10620_ul/src/
cmsenv
git clone git@github.com:slezki/XbAnalysis_UltraLegacy_MINIAOD.git Ponia/Onia/
scram b

```

* Run: (use your favorite input sample)

```
voms-proxy-init -rfc -voms cms -valid 192:00
cmsRun Ponia/Onia/test/run-upspipi-miniaod.py (for Y(1S)π<sup>+</sup>π<sup>-</sup> reconstruction 2018 UL Dataset)
```

* To send multiple tasks in CRAB for 2016-2017-2018 Data Run II:

```
chmod a+x crabCfgCreator.sh (just once)
./crabCfgCreator.sh 
```

* Check status (or resubmit, report etc..) for CRAB tasks:

```
chmod a+x crabTools.sh (just once)
./crabTools.sh status workDir (workDir: see crabCfgCreator.sh file; status can be change with all CRAB commands which can be used after sent tasks.) 
```

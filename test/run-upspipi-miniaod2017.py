#input_filename = '/store/data/Run2017D/MuOnia/MINIAOD/31Mar2018-v1/100000/940B61F6-6C39-E811-B130-0CC47A7C3434.root'
ouput_filename = 'rootuple_2017_UpsPiPi.root'

import FWCore.ParameterSet.Config as cms
process = cms.Process('UpsPiPi')

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_dataRun2_v32', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_dataRun2_v13', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_mc2017_realistic_v8', '')

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(1000))
#"""
process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(
    #'/store/data/Run2017E/MuOnia/MINIAOD/31Mar2018-v1/30000/5C242E20-D837-E811-BE0B-0CC47A010854.root',
    #'/store/data/Run2017E/MuOnia/MINIAOD/31Mar2018-v1/30000/107114D9-9C37-E811-AEBF-1866DA87967B.root',
    #'/store/data/Run2017E/MuOnia/MINIAOD/31Mar2018-v1/30000/BC8B1164-DA37-E811-B03C-1866DA87A65E.root',
    #'/store/data/Run2017E/MuOnia/MINIAOD/31Mar2018-v1/30000/A28442E1-D937-E811-8369-D4AE526A0455.root',
    #'/store/data/Run2017E/MuOnia/MINIAOD/31Mar2018-v1/30000/884FBF39-DB37-E811-83B4-1866DA87967B.root',
    #'/store/data/Run2017E/MuOnia/MINIAOD/31Mar2018-v1/30000/30A2AA3A-DB37-E811-B4B7-1866DA87AB31.root'

    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/7421F2E8-F399-3F4F-B544-8B237687F2A4.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/FA938AB4-5F37-D44B-9183-6CE6323A8023.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/5A263B94-94E4-3244-9C36-62BC678390B7.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/5CA7496B-6F4C-1C48-B273-D117C9D3BEA5.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/B8F10C76-033C-F44F-B67B-D98715877C31.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/1E25171F-822B-E742-9BC0-F0B865F53040.root',

  )
)

"""
process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/270000/A6DC54C7-7199-EA11-9685-246E96D14D60.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/270000/5A300CB9-3999-EA11-AA23-001E675827BC.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/270000/840B5EB8-B099-EA11-8875-0CC47AFC3C72.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/270000/52C89A3E-6899-EA11-962B-484D7E8DF0FA.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p4_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/120000/D461388F-06A1-EA11-9647-008CFA111280.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p4_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/120000/1436619A-7CA1-EA11-8645-008CFA197928.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p4_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/120000/A201B014-82A1-EA11-A761-008CFA197DDC.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p4_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/120000/CEDF99BC-8BA1-EA11-AE6A-008CFA197E8C.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p4_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/120000/36AA579A-7CA1-EA11-830C-008CFA197928.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p4_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/120000/6065085E-54A2-EA11-A562-008CFAC8BF80.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/270000/44CCF902-7C99-EA11-84E6-001E67A3F8A8.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/270000/921A6B27-EF99-EA11-96AE-EC0D9A0B3350.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p4_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/120000/A6693BD4-60A2-EA11-9C74-001E67398809.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p4_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/120000/089F1D7C-8BA1-EA11-8A5C-001E674FBF86.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIFall17MiniAODv2/chib0_Tochib1PiPi_m11p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/PU2017_12Apr2018_94X_mc2017_realistic_v14-v1/270000/0AE4002C-7899-EA11-B3F4-008CFA064788.root'

  )
)
"""

process.TFileService = cms.Service("TFileService",fileName = cms.string(ouput_filename))
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))

process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(4)

process.load("Ponia.Onia.slimmedMuonsTriggerMatcher2017_cfi")

process.oniaSelectedMuons = cms.EDFilter('PATMuonSelector',
   src = cms.InputTag('slimmedMuonsWithTrigger'),
   cut = cms.string('muonID(\"TMOneStationTight\")'
                    ' && abs(innerTrack.dxy) < 0.3'
                    ' && abs(innerTrack.dz)  < 20.'
                    ' && innerTrack.hitPattern.trackerLayersWithMeasurement > 5'
                    ' && innerTrack.hitPattern.pixelLayersWithMeasurement > 0'
                    ' && innerTrack.quality(\"highPurity\")'
                    ' && (pt > 4.)'
   ),
   filter = cms.bool(True)
)

#process.load("HeavyFlavorAnalysis.Onia2MuMu.onia2MuMuPAT_cfi")
process.load("Ponia.Onia.onia2MuMuPAT_cfi")
process.onia2MuMuPAT.muons=cms.InputTag('oniaSelectedMuons')
process.onia2MuMuPAT.primaryVertexTag=cms.InputTag('offlineSlimmedPrimaryVertices')
process.onia2MuMuPAT.beamSpotTag=cms.InputTag('offlineBeamSpot')
process.onia2MuMuPAT.higherPuritySelection=cms.string("")
process.onia2MuMuPAT.lowerPuritySelection=cms.string("")
process.onia2MuMuPAT.dimuonSelection=cms.string("8.5 < mass && mass < 11.5")
process.onia2MuMuPAT.addMCTruth = cms.bool(False)

process.triggerSelection = cms.EDFilter("TriggerResultsFilter",
                                        triggerConditions = cms.vstring('HLT_Dimuon12_Upsilon_eta1p5_v*'),
                                        hltResults = cms.InputTag( "TriggerResults", "", "HLT" ),
                                        l1tResults = cms.InputTag( "" ),
                                        throw = cms.bool(False)
                                        )

#process.Onia2MuMuFiltered = cms.EDProducer('DiMuonFilterByFilter',
process.Onia2MuMuFiltered = cms.EDProducer('DiMuonFilter',
      OniaTag             = cms.InputTag("onia2MuMuPAT"),
      singlemuonSelection = cms.string(""),
      #dimuonSelection     = cms.string("8.6 < mass && mass < 11.4 && pt > 10. && abs(y) < 1.2 && charge==0 && userFloat('vProb') > 0.01"),
      dimuonSelection     = cms.string("8.8 < mass && mass < 11.4 && pt > 11. && charge==0 && userFloat('vProb') > 0.01"),
      do_trigger_match    = cms.bool(True),
      HLTFilters          = cms.vstring('HLT_Dimuon12_Upsilon_eta1p5_v*'), # Path by path
      #HLTFilters          = cms.vstring('hltDisplacedmumuFilterDimuon12Upsilons'), # Filter by filter
)

process.DiMuonCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("Onia2MuMuFiltered"),
    minNumber = cms.uint32(1),
    #filter = cms.bool(True)
)

process.OniaPseudoTrackTrackCandidateProducer = cms.EDProducer('OniaPseudoTrackTrackProducer',
    Onia = cms.InputTag("Onia2MuMuFiltered"),
    Track = cms.InputTag("packedPFCandidates"),
    OniaMassCuts = cms.vdouble(9.,11.2), #1S
    CandidateMassCuts = cms.vdouble(9.8,12.5),
    Track1Mass = cms.double(0.13957061),#pions
    Track2Mass = cms.double(0.13957061),#pions
    ConstraintMass = cms.double(9.46030),#upsilon1S
    is_dimuon = cms.bool(True)
)

process.candidateCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("OniaPseudoTrackTrackCandidateProducer"),
    minNumber = cms.uint32(1),
    #filter = cms.bool(True)
)

process.upspipiSequence = cms.Sequence(
                                   process.triggerSelection *
                                   process.slimmedMuonsWithTriggerSequence *
                                   process.oniaSelectedMuons *
                                   process.onia2MuMuPAT*
                                   process.Onia2MuMuFiltered *                                   
                                   process.DiMuonCounter *
                                   process.OniaPseudoTrackTrackCandidateProducer *
                                   process.candidateCounter 
                                   )

process.rootuple = cms.EDAnalyzer('OniaRecoTrackTrackRootupler',
                          TheCandidates = cms.InputTag("OniaPseudoTrackTrackCandidateProducer"),
                          TheUps = cms.InputTag("Onia2MuMuFiltered"),
                          PrimaryVertices = cms.InputTag("offlineSlimmedPrimaryVertices"),
                          TriggerResults = cms.InputTag("TriggerResults", "", "HLT"),
                          GenParticles = cms.InputTag("prunedGenParticles"),
                          Track1Mass = cms.double(0.13957061),
                          Track2Mass = cms.double(0.13957061),
                          DimuonMass = cms.double(9.46030), #1S
                          candidate_pdgid = cms.uint32(0),
                          onia_pdgid = cms.uint32(553),
                          ditrack_pdgid = cms.uint32(0),
                          track1_pdgid = cms.int32(211),
                          track2_pdgid = cms.int32(-211),
                          isMC = cms.bool(False),
                          OnlyBest = cms.bool(False)
)

process.p = cms.Path(process.upspipiSequence*process.rootuple)

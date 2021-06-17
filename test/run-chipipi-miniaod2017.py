#input_filename = '/store/data/Run2017D/MuOnia/MINIAOD/17Nov2017-v1/40000/0231F5F1-5DFD-E711-AD72-002590A887F0.root'
ouput_filename = 'rootuple_2017_chiPiPi.root'

import FWCore.ParameterSet.Config as cms
process = cms.Process('chiPiPi')

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_dataRun2_v32', '')

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(1000))
process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/7421F2E8-F399-3F4F-B544-8B237687F2A4.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/FA938AB4-5F37-D44B-9183-6CE6323A8023.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/5A263B94-94E4-3244-9C36-62BC678390B7.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/5CA7496B-6F4C-1C48-B273-D117C9D3BEA5.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/B8F10C76-033C-F44F-B67B-D98715877C31.root',
    '/store/data/Run2017E/MuOnia/MINIAOD/09Aug2019_UL2017-v1/20000/1E25171F-822B-E742-9BC0-F0B865F53040.root',
  )
)
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
      HLTFilters          = cms.vstring('HLT_Dimuon12_Upsilon_eta1p5_v*'),
      #HLTFilters          = cms.vstring('hltDisplacedmumuFilterDimuon12Upsilons'),
)

process.diMuonCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("Onia2MuMuFiltered"),
    minNumber = cms.uint32(1),
    #filter = cms.bool(True)
)

process.chiProducer = cms.EDProducer('OniaPhotonProducer',
    conversions     = cms.InputTag("oniaPhotonCandidates","conversions"),
    dimuons         = cms.InputTag("Onia2MuMuFiltered"),
    pi0OnlineSwitch = cms.bool(False),
    deltaMass       = cms.vdouble(0.0,5.0),#difference between dimuon and chi candidate mass
    dzmax           = cms.double(0.5),
    triggerMatch    = cms.bool(False)  # trigger match is performed in Onia2MuMuFiltered
)

process.chiCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("chiProducer"),
    minNumber = cms.uint32(1),
    #filter = cms.bool(True)
)

process.OniaPseudoTrackTrackCandidateProducer = cms.EDProducer('OniaPseudoTrackTrackProducer',
    Onia = cms.InputTag("chiProducer"),
    Track = cms.InputTag("packedPFCandidates"),
    OniaMassCuts = cms.vdouble(9.,11.2),
    CandidateMassCuts = cms.vdouble(9.8,12.5),
    Track1Mass = cms.double(0.13957061),#pions
    Track2Mass = cms.double(0.13957061),#pions
    ConstraintMass = cms.double(9.46030),#upsilon
    is_dimuon = cms.bool(False)
)

process.candidateCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("OniaPseudoTrackTrackCandidateProducer"),
    minNumber = cms.uint32(1),
    #filter    = cms.bool(True)
)

process.chibSequence = cms.Sequence(
                                   process.triggerSelection *
                                   process.slimmedMuonsWithTriggerSequence *
                                   process.oniaSelectedMuons *
                                   process.onia2MuMuPAT*
                                   process.Onia2MuMuFiltered *
                                   process.diMuonCounter *
                                   process.chiProducer *
                                   process.chiCounter *
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
                          DimuonMass = cms.double(9.46030),
                          candidate_pdgid = cms.uint32(0),
                          onia_pdgid = cms.uint32(20553),
                          ditrack_pdgid = cms.uint32(0),
                          track1_pdgid = cms.int32(211),
                          track2_pdgid = cms.int32(-211),
                          isMC = cms.bool(False),
                          OnlyBest = cms.bool(False),
)

process.p = cms.Path(process.chibSequence*process.rootuple)

#input_filename = '/store/data/Run2016E/MuOnia/MINIAOD/17Jul2018-v1/210000/A20438E2-C98F-E811-A09C-0CC47A5FBE25.root'
ouput_filename = 'rootuple_2016_chiPiPi.root'

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
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(10000))
process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(
    #'/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/20000/F95F0269-0ABD-504B-8E77-298988B58C3C.root',
    #'/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/7C7F1C66-9A8D-5E49-9743-3A6944BBF22B.root',
    #'/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/114F36C1-5C27-C94F-8267-F956A0917E82.root',
    #'/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/17154B4D-8FFE-F04A-AA07-F01DE9E34403.root',
    #'/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/9F61B6A1-6043-5241-B68F-ED34B57F6B4A.root',
    #'/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/5D2FAEF7-BCA2-664E-9694-F732D52947A3.root',
    #'/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/3AA7FDD0-7448-7548-9F74-2DADD7F58157.root'

    '/store/data/Run2016D/MuOnia/MINIAOD/21Feb2020_UL2016_HIPM-v1/50000/0D9EB04F-62D1-CD4D-8F03-CA5DB3D524FD.root',
    '/store/data/Run2016D/MuOnia/MINIAOD/21Feb2020_UL2016_HIPM-v1/50000/DF64EB2E-4CDA-0F42-9B16-7139C1A94FF2.root',
    '/store/data/Run2016D/MuOnia/MINIAOD/21Feb2020_UL2016_HIPM-v1/50000/09F160CE-F770-4B4C-99B6-B0F51EE05475.root',
    '/store/data/Run2016D/MuOnia/MINIAOD/21Feb2020_UL2016_HIPM-v1/50000/4B9C1A01-B32E-2D42-8969-60E356B0C81F.root',
    '/store/data/Run2016D/MuOnia/MINIAOD/21Feb2020_UL2016_HIPM-v1/50000/F50D9811-CA70-984F-BEDB-DA896A74BE55.root',
    '/store/data/Run2016D/MuOnia/MINIAOD/21Feb2020_UL2016_HIPM-v1/50000/0C60C7C7-0850-A149-B9A7-07B3522B5042.root'


  )
)
process.TFileService = cms.Service("TFileService",fileName = cms.string(ouput_filename))
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))

process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(4)

process.load("Ponia.Onia.slimmedMuonsTriggerMatcher2016_cfi")

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
                                        triggerConditions = cms.vstring('HLT_Dimuon8_Upsilon_Barrel_v*'),
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
      HLTFilters          = cms.vstring('HLT_Dimuon8_Upsilon_Barrel_v*'),
      #HLTFilters          = cms.vstring('hltDisplacedmumuFilterDimuon8UpsilonBarrel'),
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

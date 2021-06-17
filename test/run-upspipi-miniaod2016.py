#input_filename = '/store/data/Run2016E/MuOnia/MINIAOD/17Jul2018-v1/210000/A20438E2-C98F-E811-A09C-0CC47A5FBE25.root'
ouput_filename = 'rootuple_2016_UpsPiPi.root'

import FWCore.ParameterSet.Config as cms
process = cms.Process('UpsPiPi')

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_dataRun2_v32', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_mcRun2_asymptotic_v8', '')

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(1000))
process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/DC363B8B-C78D-E811-B460-38EAA78D8ACC.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/0A9CF7D2-CB8D-E811-8C89-8CDCD4A9A484.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/941712D6-CB8D-E811-82A5-0CC47AF973C2.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/4C8D32D1-D28D-E811-91A7-0CC47AF973C2.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/18850B14-DA8D-E811-B879-9CB65482A8E8.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/08223D1E-DA8D-E811-BA64-00215AA9D8C0.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/B46B3320-E28D-E811-96D5-D4856444779A.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/50339FD4-F48D-E811-BEE4-984BE164408A.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/DA85090D-FD8D-E811-99E1-38EAA78D8F94.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/70082F15-168E-E811-9925-D4856445E56C.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/B43A8DC9-198E-E811-9896-38EAA78D8B54.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/1C7F48D2-1C8E-E811-9076-D4856444C72A.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/B828BEEF-208E-E811-A07D-00215A4909F6.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/E8274B37-2C8E-E811-BCE5-00215A4909F6.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/A02EB0D3-2F8E-E811-945F-00215AAA5746.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/FEBFF8CD-2F8E-E811-A115-441EA1616D3A.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/1C3157F1-328E-E811-91ED-00215A4909F6.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/329C62F1-328E-E811-A8C9-00215A4909F6.root',
    #'/store/data/Run2016F/MuOnia/MINIAOD/17Jul2018-v1/50000/182AB148-378E-E811-9FFB-00215A4909F6.root'


    '/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/20000/F95F0269-0ABD-504B-8E77-298988B58C3C.root',
    '/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/7C7F1C66-9A8D-5E49-9743-3A6944BBF22B.root',
    '/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/114F36C1-5C27-C94F-8267-F956A0917E82.root',
    '/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/17154B4D-8FFE-F04A-AA07-F01DE9E34403.root',
    '/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/9F61B6A1-6043-5241-B68F-ED34B57F6B4A.root',
    '/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/5D2FAEF7-BCA2-664E-9694-F732D52947A3.root',
    '/store/data/Run2016H/MuOnia/MINIAOD/21Feb2020_UL2016-v1/70000/3AA7FDD0-7448-7548-9F74-2DADD7F58157.root'


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
)

process.DiMuonCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("Onia2MuMuFiltered"),
    minNumber = cms.uint32(1),
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
                          OnlyBest = cms.bool(False),
)

process.p = cms.Path(process.upspipiSequence*process.rootuple)

#input_filename = '/store/data/Run2018C/MuOnia/MINIAOD/17Sep2018-v1/10000/06A10462-ADA8-BC48-9D28-E9197FADC075.root'
ouput_filename = 'rootuple_2018_chiPiPi.root'

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

    #'/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/130000/1C0FDF45-1DE1-694F-AE16-17ADFD9DF062.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/130000/7AFE0636-4079-5F4F-98DE-83CC954784F5.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/130000/953B00CA-35B9-1D40-BBBE-5C07E0FBE184.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/260000/B10B4EA8-2C83-2B45-8C6B-6C3525159FBC.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/260000/A5AF0288-299F-F04E-9690-B1FAC92EF488.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/260000/2F9297EE-250F-254E-962A-4A08E1825597.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/110000/C2B40656-2B5F-B343-AC50-FDB1DA104156.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/110000/98F1DC20-D009-C04B-A2A4-A2FD498946DC.root'


    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/33986C31-566D-1B47-8B7B-534678031DDD.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/416F7870-C6C7-FB42-A78C-9B78984A3FB1.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/46CEED25-728F-C545-B051-C4E9D571FFCB.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/4A23D2BF-DF34-AE41-BA6C-1B4253BF6DAD.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/4AB84268-856D-8A4B-92C6-81B6E5B2055A.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/4F74569F-A694-E447-BD0D-BE340FC999E5.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/4F9A65CA-9666-014D-B244-C8AA83308D96.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/4FB2EFA2-BE67-3F47-8A8B-0E665DCC5D4B.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/4FBF16CF-3B63-DF4C-873D-E2083ED785D3.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/504B66B2-55C8-1F41-9EFD-9244597EC207.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/5669AAFB-9B57-E443-9A70-2CC65EE6DA5E.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/56DE7825-91DD-8B4B-8A0C-96928B607509.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/576EFD31-AEE6-9E44-AD45-9A5CF007D6D1.root',
    '/store/data/Run2018B/MuOnia/MINIAOD/12Nov2019_UL2018-v1/00000/59E1015A-86D1-4247-8528-351DEC921EF7.root'

  )
)
#process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')
#process.source.duplicateCheckMode = cms.untracked.string('checkEachRealDataFile')
process.TFileService = cms.Service("TFileService",fileName = cms.string(ouput_filename))
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))

process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(4)

process.oniaSelectedMuons = cms.EDFilter('PATMuonSelector',
   #src = cms.InputTag('slimmedMuonsWithTrigger'),
   src = cms.InputTag('slimmedMuons'),
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
                                        triggerConditions = cms.vstring('HLT_Dimuon12_Upsilon_eta1p5_v*',
                                                                        'HLT_Dimuon12_Upsilon_y1p4_v*'
                                                                        ),
                                        hltResults = cms.InputTag( "TriggerResults", "", "HLT" ),
                                        l1tResults = cms.InputTag( "" ),
                                        throw = cms.bool(False)
                                        )
#print "** ** bug ** **"
process.Onia2MuMuFiltered = cms.EDProducer('DiMuonFilter',
      OniaTag             = cms.InputTag("onia2MuMuPAT"),
      singlemuonSelection = cms.string(""),
 #     TriggerInput = cms.InputTag("unpackPatTriggers"),
 #     TriggerResults = cms.InputTag("TriggerResults", "", "HLT"),
      #dimuonSelection     = cms.string("8.6 < mass && mass < 11.4 && pt > 10. && abs(y) < 1.2 && charge==0 && userFloat('vProb') > 0.01"),
      #dimuonSelection     = cms.string("8.8 < mass && mass < 11.4 && pt > 12. && charge==0"),
      dimuonSelection     = cms.string("8.8 < mass && mass < 11.4 && pt > 11. && charge==0 && userFloat('vProb') > 0.01"),
      do_trigger_match    = cms.bool(True),
      HLTFilters          = cms.vstring(
                                        #'hltDisplacedmumuFilterDimuon12Upsilons',
                                        #'hltDisplacedmumuFilterDimuon10UpsilonBarrelnoCow',
                                        #'hltDisplacedmumuFilterDimuon12Upsilonsv3'
                                        'HLT_Dimuon12_Upsilon_eta1p5_v*',
                                        'HLT_Dimuon12_Upsilon_y1p4_v*'
                                        ),
)

process.diMuonCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("Onia2MuMuFiltered"),
    minNumber = cms.uint32(1),
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
)

process.chibSequence = cms.Sequence(
                                   process.triggerSelection *
                                   #process.slimmedMuonsWithTriggerSequence *
                                   #process.unpackPatTriggers *
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

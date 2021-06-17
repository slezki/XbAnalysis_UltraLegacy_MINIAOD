#input_filename = '/store/data/Run2018C/MuOnia/MINIAOD/17Sep2018-v1/10000/06A10462-ADA8-BC48-9D28-E9197FADC075.root'
ouput_filename = 'rootuple_2018_UpsPiPi.root'
#ouput_filename = 'rootuple_316240.root'

import FWCore.ParameterSet.Config as cms
process = cms.Process('UpsPiPi')

process.load('Configuration.StandardSequences.GeometryRecoDB_cff')
process.load('Configuration.StandardSequences.MagneticField_38T_cff')
process.load('Configuration.StandardSequences.Reconstruction_cff')
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_condDBv2_cff')
from Configuration.AlCa.GlobalTag_condDBv2 import GlobalTag
process.GlobalTag = GlobalTag(process.GlobalTag, '106X_dataRun2_v32', '')
#process.GlobalTag = GlobalTag(process.GlobalTag, '102X_upgrade2018_realistic_v21', '')

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 10
process.maxEvents = cms.untracked.PSet(input = cms.untracked.int32(100))

#"""
process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/170/00000/D08343DC-BDB5-7642-AE3D-D981691FFD75.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/FE3014AD-9DD6-5C40-8C88-345E7551D520.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/DCAB3AF3-9328-7B4A-BED7-992421442D3C.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/414AB740-DDAA-AB45-91CF-1D552A9A8F42.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/FA464CBE-12CE-2C4B-B0F1-BBCBC1E8FC9F.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/D79E10A6-55D5-944A-ADDE-424765D21C22.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/E9391A14-56ED-0847-A551-30B43FB8F9FF.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/AEC94F80-4C38-F54D-9768-92E53ACB88A5.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/B4EF84EF-3B2A-8B41-8E59-B439A1499CC0.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/A1908948-988D-144C-9FB9-B36057580B36.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/588329D2-D0DB-F147-9C86-44ED2FF863F1.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/7CA00AE5-82B6-D446-8F94-96506BAB21FB.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/96D3BB6D-4D3B-8F45-B9BB-D4DD5A2EC363.root',
    #'/store/data/Run2018D/MuOnia/MINIAOD/PromptReco-v2/000/325/022/00000/111504B7-B175-AC4A-95E1-048424515BB5.root'

    '/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/130000/1C0FDF45-1DE1-694F-AE16-17ADFD9DF062.root',
    '/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/130000/7AFE0636-4079-5F4F-98DE-83CC954784F5.root',
    '/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/130000/953B00CA-35B9-1D40-BBBE-5C07E0FBE184.root',
    '/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/260000/B10B4EA8-2C83-2B45-8C6B-6C3525159FBC.root',
    '/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/260000/A5AF0288-299F-F04E-9690-B1FAC92EF488.root',
    '/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/260000/2F9297EE-250F-254E-962A-4A08E1825597.root',
    '/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/110000/C2B40656-2B5F-B343-AC50-FDB1DA104156.root',
    '/store/data/Run2018D/MuOnia/MINIAOD/12Nov2019_UL2018-v1/110000/98F1DC20-D009-C04B-A2A4-A2FD498946DC.root'

  )
)

"""
process.source = cms.Source("PoolSource",fileNames = cms.untracked.vstring(
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/10C610CB-D993-5B44-BF86-9257B060D0C8.root',
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/FBDCB5C2-4996-9149-A620-974857E16730.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/1FB3DBFD-DF3D-4E4C-81ED-1F897036A27A.root',
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/32C05DC7-B1C8-E144-A795-3938FF8CBCDC.root',
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/762B35BB-F4CF-6C46-A29E-B5DD2815C5C0.root',
    #'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/C82AE65D-54C1-8048-B9EC-D1CCB9B3DD71.root',
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/EC632828-FA7C-6340-8393-24FD3BACD7AC.root',
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/EDA7812C-2234-8741-8549-7963994572A8.root',
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/C4601DA1-7488-CD49-A775-F16DE90EF418.root',
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/8B17AE61-48D2-5949-AF45-DBE73FF0FB41.root',
    'root://xrootd-cms.infn.it//store/mc/RunIIAutumn18MiniAOD/chib0_ToUpsilon1SPiPi_m10p7_TuneCP5_13TeV-pythia8-evtgen/MINIAODSIM/102X_upgrade2018_realistic_v15-v1/90000/B5D5AD27-54C8-F644-8B24-5CEFCF37FC59.root'
  )
)
"""

process.TFileService = cms.Service("TFileService",fileName = cms.string(ouput_filename))
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))

process.options.numberOfThreads=cms.untracked.uint32(4)
process.options.numberOfStreams=cms.untracked.uint32(4)

process.oniaSelectedMuons = cms.EDFilter('PATMuonSelector',
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

process.Onia2MuMuFiltered = cms.EDProducer('DiMuonFilter',
      OniaTag             = cms.InputTag("onia2MuMuPAT"),
      singlemuonSelection = cms.string(""),
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

process.DiMuonCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("Onia2MuMuFiltered"),
    minNumber = cms.uint32(1),
)

process.OniaPseudoTrackTrackCandidateProducer = cms.EDProducer('OniaPseudoTrackTrackProducer',
    Onia = cms.InputTag("Onia2MuMuFiltered"),
    Track = cms.InputTag("packedPFCandidates"),
    OniaMassCuts = cms.vdouble(9.,11.2), #1S
    CandidateMassCuts = cms.vdouble(9.5,12.5),
    Track1Mass = cms.double(0.13957061),#pions
    Track2Mass = cms.double(0.13957061),#pions
    ConstraintMass = cms.double(9.46030),#upsilon 1S
    is_dimuon = cms.bool(True)
)

process.candidateCounter = cms.EDFilter('CandViewCountFilter',
    src       = cms.InputTag("OniaPseudoTrackTrackCandidateProducer"),
    minNumber = cms.uint32(1),
)

process.upspipiSequence = cms.Sequence(
                                   process.triggerSelection *
                                   #process.slimmedMuonsWithTriggerSequence *
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

#include <memory>

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/PatCandidates/interface/CompositeCandidate.h"
#include "DataFormats/HepMCCandidate/interface/GenParticle.h"
#include "DataFormats/HepMCCandidate/interface/GenParticleFwd.h"
#include "DataFormats/PatCandidates/interface/UserData.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "DataFormats/Common/interface/TriggerResults.h"
#include "FWCore/Common/interface/TriggerNames.h"

#include "TLorentzVector.h"
#include "TTree.h"
#include <vector>
#include <sstream>

class OniaRecoTrackTrackRootupler : public edm::EDAnalyzer {
   public:
      explicit OniaRecoTrackTrackRootupler(const edm::ParameterSet&);
      ~OniaRecoTrackTrackRootupler() override {};
      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

   private:
      void analyze(const edm::Event&, const edm::EventSetup&) override;
  
  std::string file_name;
  const edm::EDGetTokenT<pat::CompositeCandidateCollection> TheCandidateLabel;
  const edm::EDGetTokenT<pat::CompositeCandidateCollection> TheUpsLabel;
  const edm::EDGetTokenT<reco::VertexCollection>            ThePrimaryVertexLabel;
  const edm::EDGetTokenT<edm::TriggerResults>               TheTriggerResultLabel;
  const edm::EDGetTokenT<reco::GenParticleCollection>       TheGenParticleLabel;
  const double Track1Mass_;
  const double Track2Mass_;
  const double DimuonMass_;
  const int  candidate_pdgid_, onia_pdgid_, ditrack_pdgid_, track1_pdgid_, track2_pdgid_;
  const bool isMC_,OnlyBest_;

  UInt_t run, event, nCandPerEvent, numPrimaryVertices, trigger, luminosityBlock;  

  TLorentzVector candidate_p4;
  TLorentzVector onia_p4;
  TLorentzVector dimuon_p4;
  TLorentzVector photon_p4;
  TLorentzVector ele_trk0;
  TLorentzVector ele_trk1;
  TLorentzVector track1_p4;
  TLorentzVector track2_p4;
  TLorentzVector muonp_p4;
  TLorentzVector muonn_p4;
  TLorentzVector ditrack_p4;

  Double_t conv_vertex;
  Double_t conv_vertex_x;
  Double_t conv_vertex_y;
  Double_t conv_vertex_z;
  Double_t conv_vertex_r;
  Double_t conv_vertex_eta;
  Double_t conv_vertex_theta;
  Double_t conv_vertex_phi;

  Int_t    candidate_charge, track1_nvsh, track1_nvph, track2_nvsh, track2_nvph, gen_candidate_charge;
  Double_t candidate_vMass, candidate_vProb,  candidate_vChi2, candidate_cosAlpha, candidate_ctauPV, candidate_ctauErrPV;
  Double_t candidate_cosAlpha3D, candidate_lxy, candidate_lxyErr, candidate_lxyz, candidate_lxyzErr;

  Double_t thePrimaryV_X, thePrimaryV_Y, thePrimaryV_Z, TheDecayVertex_X, TheDecayVertex_Y, TheDecayVertex_Z, thePrimaryV_2D_position, thePrimaryV_3D_position, TheDecayVertex_2D_position, TheDecayVertex_3D_position, TheVertexDistance_2D, TheVertexDistance_3D;

  Double_t track1_d0, track1_d0Err, track1_dz, track1_dxy, track1_dzErr, track1_dxyErr, track1_dzAssocPV;
  Double_t track2_d0, track2_d0Err, track2_dz, track2_dxy, track2_dzErr, track2_dxyErr, track2_dzAssocPV;
  Double_t dimuon_vProb, dimuon_vChi2, dimuon_DCA, dimuon_ctauPV, dimuon_ctauErrPV, dimuon_cosAlpha, dimuon_nSigma;
  Double_t track2_dRdimuon, track1_dRdimuon, ditrack_dRdimuon;

  Int_t validFit, validStateFit;
  Int_t candidate_validFit, candidate_validStateFit;

  Int_t track1_charge, track2_charge;
  Int_t track1_PV, track2_PV, track1_refVtx, track2_refVtx, track1_pvAssocQ, track2_pvAssocQ;

  Int_t Chi_index, dimuon_vertexWeight, iPVwithmuons, diMuInChi_index, dimuon_diMuIndx;
  Int_t track1_Index, track2_Index;
  Int_t dimuon_validFit;
  Int_t ups_validFit;
  
  Double_t track1_SQopQop, track1_SQopLam, track1_SQopPhi, track1_SQopDxy, track1_SQopDsz, track1_SLamLam;
  Double_t track1_SLamPhi, track1_SLamDxy, track1_SLamDsz, track1_SPhiPhi, track1_SPhiDxy, track1_SPhiDsz;
  Double_t track1_SDxyDxy, track1_SDxyDsz, track1_SDszDsz;
  
  Double_t track2_SQopQop, track2_SQopLam, track2_SQopPhi, track2_SQopDxy, track2_SQopDsz, track2_SLamLam;
  Double_t track2_SLamPhi, track2_SLamDxy, track2_SLamDsz, track2_SPhiPhi, track2_SPhiDxy, track2_SPhiDsz;
  Double_t track2_SDxyDxy, track2_SDxyDsz, track2_SDszDsz;

  Double_t track1_eigenValues, track2_eigenValues;
  
  Double_t mu1_SQopQop, mu1_SQopLam, mu1_SQopPhi, mu1_SQopDxy, mu1_SQopDsz, mu1_SLamLam;
  Double_t mu1_SLamPhi, mu1_SLamDxy, mu1_SLamDsz, mu1_SPhiPhi, mu1_SPhiDxy, mu1_SPhiDsz;
  Double_t mu1_SDxyDxy, mu1_SDxyDsz, mu1_SDszDsz;
  
  Double_t mu2_SQopQop, mu2_SQopLam, mu2_SQopPhi, mu2_SQopDxy, mu2_SQopDsz, mu2_SLamLam;
  Double_t mu2_SLamPhi, mu2_SLamDxy, mu2_SLamDsz, mu2_SPhiPhi, mu2_SPhiDxy, mu2_SPhiDsz;
  Double_t mu2_SDxyDxy, mu2_SDxyDsz, mu2_SDszDsz;

  Double_t mu1_eigenValues, mu2_eigenValues;
  
  Int_t mu1_charge_, mu2_charge_;

  Double_t ups_mu1_SQopQop, ups_mu1_SQopLam, ups_mu1_SQopPhi, ups_mu1_SQopDxy, ups_mu1_SQopDsz, ups_mu1_SLamLam;
  Double_t ups_mu1_SLamPhi, ups_mu1_SLamDxy, ups_mu1_SLamDsz, ups_mu1_SPhiPhi, ups_mu1_SPhiDxy, ups_mu1_SPhiDsz;
  Double_t ups_mu1_SDxyDxy, ups_mu1_SDxyDsz, ups_mu1_SDszDsz;
  
  Double_t ups_mu2_SQopQop, ups_mu2_SQopLam, ups_mu2_SQopPhi, ups_mu2_SQopDxy, ups_mu2_SQopDsz, ups_mu2_SLamLam;
  Double_t ups_mu2_SLamPhi, ups_mu2_SLamDxy, ups_mu2_SLamDsz, ups_mu2_SPhiPhi, ups_mu2_SPhiDxy, ups_mu2_SPhiDsz;
  Double_t ups_mu2_SDxyDxy, ups_mu2_SDxyDsz, ups_mu2_SDszDsz;

  Double_t ups_mu1_eigenValues, ups_mu2_eigenValues;

  Double_t Chi_dZ, Chi_dM;

  Double_t invm1Spipi;
  Double_t invm2Spipi;

  Double_t invmchi11Ppipi;
  Double_t invmchi21Ppipi;

  TLorentzVector gen_candidate_p4;
  Int_t          gen_candidate_pdgId;
  TLorentzVector gen_onia_p4;
  TLorentzVector gen_dimuon_p4;
  TLorentzVector gen_photon_p4;
  Int_t          gen_onia_pdgId;
  TLorentzVector gen_ditrack_p4;
  TLorentzVector gen_track1_p4;
  Int_t          gen_track1_pdgid;
  TLorentzVector gen_track2_p4;
  Int_t          gen_track2_pdgid;
  TLorentzVector gen_muonp_p4;
  TLorentzVector gen_muonn_p4;

  TLorentzVector track1;
  TLorentzVector track2;

  TLorentzVector ups_p4, muonP_p4, muonN_p4;
  Double_t ups_vMass, ups_vertexWeight, ups_vProb, ups_vChi2, ups_DCA, ups_ctauPV, ups_ctauErrPV, ups_cosAlpha;
  Double_t ups_lxyPV, ups_lxyErrPV, ups_ctauBS, ups_ctauErrBS, ups_lxyBS, ups_lxyErrBS;
  Double_t mu1_pt, mu1_ptErr, mu1_d0, mu1_d0Err, mu1_dz, mu1_dzErr, mu1_dxy, mu1_dxyErr, mu2_pt, mu2_ptErr, mu2_d0, mu2_d0Err, mu2_dz, mu2_dzErr, mu2_dxy, mu2_dxyErr;
  Int_t mu1_nvsh, mu1_nvph, mu2_nvsh, mu2_nvph, iPVwithmuons_ups, mu1_charge, mu2_charge;
  Int_t ups_diMuIndx;

  TTree* TheTree;
  TTree* UpsTree;
  bool is_dimuon_;
};

// 2016 par
static const double Y_sig_par_A = 0.064;
static const double Y_sig_par_B = 0.009;
static const double Y_sig_par_C = 0.030;

static const Double_t ups1SMass =  9.46030;
static const Double_t ups2SMass = 10.02326;

static const Double_t chib01PMass =  9.85944;
static const Double_t chib11PMass =  9.89278;
static const Double_t chib21PMass =  9.91221;

static const Double_t chib02PMass =  10.2325;
static const Double_t chib12PMass =  10.25546;
static const Double_t chib22PMass =  10.26865;

static const Double_t ele_mass = 0.000511;

OniaRecoTrackTrackRootupler::OniaRecoTrackTrackRootupler(const edm::ParameterSet& iConfig):
TheCandidateLabel(consumes<pat::CompositeCandidateCollection>(iConfig.getParameter < edm::InputTag > ("TheCandidates"))),
TheUpsLabel(consumes<pat::CompositeCandidateCollection>(iConfig.getParameter < edm::InputTag > ("TheUps"))),
ThePrimaryVertexLabel(consumes<reco::VertexCollection>(iConfig.getParameter < edm::InputTag > ("PrimaryVertices"))),
TheTriggerResultLabel(consumes<edm::TriggerResults>(iConfig.getParameter < edm::InputTag > ("TriggerResults"))),
TheGenParticleLabel(consumes<reco::GenParticleCollection>(iConfig.getParameter < edm::InputTag > ("GenParticles"))),
Track1Mass_(iConfig.getParameter<double>("Track1Mass")),
Track2Mass_(iConfig.getParameter<double>("Track2Mass")),
DimuonMass_(iConfig.getParameter<double>("DimuonMass")),
candidate_pdgid_(iConfig.getParameter<uint32_t>("candidate_pdgid")),
onia_pdgid_(iConfig.getParameter<uint32_t>("onia_pdgid")),
ditrack_pdgid_(iConfig.getParameter<uint32_t>("ditrack_pdgid")),
track1_pdgid_(iConfig.getParameter<int32_t>("track1_pdgid")),
track2_pdgid_(iConfig.getParameter<int32_t>("track2_pdgid")),
isMC_(iConfig.getParameter<bool>("isMC")),
OnlyBest_(iConfig.getParameter<bool>("OnlyBest"))
{
        is_dimuon_ = (onia_pdgid_ == 333 || onia_pdgid_ == 443 || onia_pdgid_ == 100443 || onia_pdgid_ == 553 || onia_pdgid_ == 100553 || onia_pdgid_ == 200553);
	edm::Service<TFileService> fs;
        TheTree = fs->make<TTree>("CandidateTree","CandidateTree");

        TheTree->Branch("run",                &run,                "run/I");
        TheTree->Branch("event",              &event,              "event/I");
        TheTree->Branch("luminosityBlock",              &luminosityBlock,              "luminosityBlock/I");
        TheTree->Branch("nCandPerEvent", &nCandPerEvent, "nCandPerEvent/I");
        TheTree->Branch("numPrimaryVertices", &numPrimaryVertices, "numPrimaryVertices/I");
        TheTree->Branch("trigger",            &trigger,            "trigger/I");

        TheTree->Branch("candidate_p4","TLorentzVector", &candidate_p4);
        TheTree->Branch("track1_p4",   "TLorentzVector", &track1_p4);
        TheTree->Branch("track2_p4",   "TLorentzVector", &track2_p4);
        TheTree->Branch("ditrack_p4",   "TLorentzVector", &ditrack_p4);
        TheTree->Branch("dimuon_p4",   "TLorentzVector", &dimuon_p4);

        if (!is_dimuon_) {
          TheTree->Branch("diMuInChi_index",      &diMuInChi_index,        "diMuInChi_index/I");
          TheTree->Branch("Chi_index",      &Chi_index,        "Chi_index/I");
          TheTree->Branch("Chi_dZ",      &Chi_dZ,        "Chi_dZ/D");
          TheTree->Branch("Chi_dM",      &Chi_dM,        "Chi_dM/D");
          TheTree->Branch("onia_p4",     "TLorentzVector", &onia_p4);
          TheTree->Branch("photon_p4",   "TLorentzVector", &photon_p4);
          TheTree->Branch("ele_trk0",    "TLorentzVector", &ele_trk0);
          TheTree->Branch("ele_trk1",    "TLorentzVector", &ele_trk1);

          TheTree->Branch("conv_vertex",  &conv_vertex,  "conv_vertex/D");
          TheTree->Branch("conv_vertex_x",  &conv_vertex_x,  "conv_vertex_x/D");
          TheTree->Branch("conv_vertex_y",  &conv_vertex_y,  "conv_vertex_y/D");
          TheTree->Branch("conv_vertex_z",  &conv_vertex_z,  "conv_vertex_z/D");
          TheTree->Branch("conv_vertex_r",  &conv_vertex_r,  "conv_vertex_r/D");
          TheTree->Branch("conv_vertex_eta",  &conv_vertex_eta,  "conv_vertex_eta/D");
          TheTree->Branch("conv_vertex_theta",  &conv_vertex_theta,  "conv_vertex_theta/D");
          TheTree->Branch("conv_vertex_phi", &conv_vertex_phi, "conv_vertex_phi/D");
        }

        TheTree->Branch("muonp_p4",    "TLorentzVector", &muonp_p4);
        TheTree->Branch("muonn_p4",    "TLorentzVector", &muonn_p4);

        if (is_dimuon_) {
          TheTree->Branch("invm1Spipi",      &invm1Spipi,          "invm1Spipi/D");
          TheTree->Branch("invm2Spipi",      &invm2Spipi,          "invm2Spipi/D");
        } else {
          TheTree->Branch("invmchi11Ppipi",      &invmchi11Ppipi,          "invmchi11Ppipi/D");
          TheTree->Branch("invmchi21Ppipi",      &invmchi21Ppipi,          "invmchi21Ppipi/D");       
        }

        TheTree->Branch("iPVwithmuons",        &iPVwithmuons,        "iPVwithmuons/I");

        TheTree->Branch("dimuon_diMuIndx",       &dimuon_diMuIndx,        "dimuon_diMuIndx/I");
        TheTree->Branch("dimuon_vertexWeight",        &dimuon_vertexWeight,        "dimuon_vertexWeight/I");
        TheTree->Branch("dimuon_vProb",        &dimuon_vProb,        "dimuon_vProb/D");
        TheTree->Branch("dimuon_vNChi2",       &dimuon_vChi2,        "dimuon_vNChi2/D");
        TheTree->Branch("dimuon_DCA",          &dimuon_DCA,          "dimuon_DCA/D");
        TheTree->Branch("dimuon_ctauPV",       &dimuon_ctauPV,       "dimuon_ctauPV/D");
        TheTree->Branch("dimuon_ctauErrPV",    &dimuon_ctauErrPV,    "dimuon_ctauErrPV/D");
        TheTree->Branch("dimuon_cosAlpha",     &dimuon_cosAlpha,     "dimuon_cosAlpha/D");
        TheTree->Branch("dimuon_nSigma",       &dimuon_nSigma,       "dimuon_nSigma/D");

        TheTree->Branch("candidate_vMass",      &candidate_vMass,        "candidate_vMass/D");
        TheTree->Branch("candidate_vProb",      &candidate_vProb,        "candidate_vProb/D");
        TheTree->Branch("candidate_vChi2",      &candidate_vChi2,        "candidate_vChi2/D");
        TheTree->Branch("candidate_cosAlpha",   &candidate_cosAlpha,     "candidate_cosAlpha/D");
        TheTree->Branch("candidate_ctauPV",     &candidate_ctauPV,       "candidate_ctauPV/D");
        TheTree->Branch("candidate_ctauErrPV",  &candidate_ctauErrPV,    "candidate_ctauErrPV/D");
        TheTree->Branch("candidate_charge",     &candidate_charge,       "candidate_charge/I");
        TheTree->Branch("candidate_lxy",        &candidate_lxy,          "candidate_lxy/D");
        TheTree->Branch("candidate_lxyErr",     &candidate_lxyErr,       "candidate_lxyErr/D");
        TheTree->Branch("candidate_lxyz",       &candidate_lxyz,         "candidate_lxyz/D");
        TheTree->Branch("candidate_lxyzErr",    &candidate_lxyzErr,      "candidate_lxyzErr/D");

        TheTree->Branch("candidate_validFit",     &candidate_validFit,       "candidate_validFit/I");
        TheTree->Branch("candidate_validStateFit",     &candidate_validStateFit,       "candidate_validStateFit/I");

        TheTree->Branch("thePrimaryV_X",      &thePrimaryV_X,        "thePrimaryV_X/D");
        TheTree->Branch("thePrimaryV_Y",      &thePrimaryV_Y,        "thePrimaryV_Y/D");
        TheTree->Branch("thePrimaryV_Z",      &thePrimaryV_Z,        "thePrimaryV_Z/D");
        TheTree->Branch("TheDecayVertex_X",      &TheDecayVertex_X,        "TheDecayVertex_X/D");
        TheTree->Branch("TheDecayVertex_Y",      &TheDecayVertex_Y,        "TheDecayVertex_Y/D");
        TheTree->Branch("TheDecayVertex_Z",      &TheDecayVertex_Z,        "TheDecayVertex_Z/D");
        TheTree->Branch("thePrimaryV_2D_position",      &thePrimaryV_2D_position,        "thePrimaryV_2D_position/D");
        TheTree->Branch("thePrimaryV_3D_position",      &thePrimaryV_3D_position,        "thePrimaryV_3D_position/D");
        TheTree->Branch("TheDecayVertex_2D_position",      &TheDecayVertex_2D_position,        "TheDecayVertex_2D_position/D");
        TheTree->Branch("TheDecayVertex_3D_position",      &TheDecayVertex_3D_position,        "TheDecayVertex_3D_position/D");
        TheTree->Branch("TheVertexDistance_2D",      &TheVertexDistance_2D,        "TheVertexDistance_2D/D");
        TheTree->Branch("TheVertexDistance_3D",      &TheVertexDistance_3D,        "TheVertexDistance_3D/D");

        TheTree->Branch("track1_Index",    &track1_Index,    "track1_Index/I");
        TheTree->Branch("track2_Index",    &track2_Index,    "track2_Index/I");

        TheTree->Branch("track1_d0",    &track1_d0,    "track1_d0/D");
        TheTree->Branch("track1_d0Err", &track1_d0Err, "track1_d0Err/D");
        TheTree->Branch("track1_dz",    &track1_dz,    "track1_dz/D");
        TheTree->Branch("track1_dzErr",    &track1_dzErr,    "track1_dzErr/D");
        TheTree->Branch("track1_dxy",   &track1_dxy,   "track1_dxy/D");
        TheTree->Branch("track1_dxyErr",   &track1_dxyErr,   "track1_dxyErr/D");
        TheTree->Branch("track1_nvsh",  &track1_nvsh,  "track1_nvsh/I");
        TheTree->Branch("track1_nvph",  &track1_nvph,  "track1_nvph/I");
        TheTree->Branch("track1_dRdimuon",  &track1_dRdimuon,  "track1_dRdimuon/D");
        TheTree->Branch("track1_charge",  &track1_charge,  "track1_charge/I");
        TheTree->Branch("track1_PV",  &track1_PV,  "track1_PV/I");
        TheTree->Branch("track1_refVtx",  &track1_refVtx,  "track1_refVtx/I");
        TheTree->Branch("track1_pvAssocQ",  &track1_pvAssocQ,  "track1_pvAssocQ/I");
        TheTree->Branch("track1_dzAssocPV",    &track1_dzAssocPV,    "track1_dzAssocPV/D");

        TheTree->Branch("track2_d0",    &track2_d0,    "track2_d0/D");
        TheTree->Branch("track2_d0Err", &track2_d0Err, "track2_d0Err/D");
        TheTree->Branch("track2_dz",    &track2_dz,    "track2_dz/D");
        TheTree->Branch("track2_dzErr",    &track2_dzErr,    "track2_dzErr/D");
        TheTree->Branch("track2_dxy",   &track2_dxy,   "track2_dxy/D");
        TheTree->Branch("track2_dxyErr",   &track2_dxyErr,   "track2_dxyErr/D");
        TheTree->Branch("track2_nvsh",  &track2_nvsh,  "track2_nvsh/I");
        TheTree->Branch("track2_nvph",  &track2_nvph,  "track2_nvph/I");
        TheTree->Branch("track2_dRdimuon",  &track2_dRdimuon,  "track2_dRdimuon/D");
        TheTree->Branch("track2_charge",  &track2_charge,  "track2_charge/I");
        TheTree->Branch("track2_PV",  &track2_PV,  "track2_PV/I");
        TheTree->Branch("track2_refVtx",  &track2_refVtx,  "track2_refVtx/I");
        TheTree->Branch("track2_pvAssocQ",  &track2_pvAssocQ,  "track2_pvAssocQ/I");
        TheTree->Branch("track2_dzAssocPV",    &track2_dzAssocPV,    "track2_dzAssocPV/D");

        TheTree->Branch("ditrack_dRdimuon",  &ditrack_dRdimuon,  "ditrack_dRdimuon/D");

        TheTree->Branch("track1_eigenValues",        &track1_eigenValues,        "track1_eigenValues/D");
        TheTree->Branch("track2_eigenValues",        &track2_eigenValues,        "track2_eigenValues/D");
        
        TheTree->Branch("track1_SQopQop",        &track1_SQopQop,        "track1_SQopQop/D");
        TheTree->Branch("track1_SQopLam",        &track1_SQopLam,        "track1_SQopLam/D");
        TheTree->Branch("track1_SQopPhi",        &track1_SQopPhi,        "track1_SQopPhi/D");
        TheTree->Branch("track1_SQopDxy",        &track1_SQopDxy,        "track1_SQopDxy/D");
        TheTree->Branch("track1_SQopDsz",        &track1_SQopDsz,        "track1_SQopDsz/D");

        TheTree->Branch("track1_SLamLam",        &track1_SLamLam,        "track1_SLamLam/D");
        TheTree->Branch("track1_SLamPhi",        &track1_SLamPhi,        "track1_SLamPhi/D");
        TheTree->Branch("track1_SLamDxy",        &track1_SLamDxy,        "track1_SLamDxy/D");
        TheTree->Branch("track1_SLamDsz",        &track1_SLamDsz,        "track1_SLamDsz/D");
        TheTree->Branch("track1_SPhiPhi",        &track1_SPhiPhi,        "track1_SPhiPhi/D");

        TheTree->Branch("track1_SPhiDxy",        &track1_SPhiDxy,        "track1_SPhiDxy/D");
        TheTree->Branch("track1_SPhiDsz",        &track1_SPhiDsz,        "track1_SPhiDsz/D");
        TheTree->Branch("track1_SDxyDxy",        &track1_SDxyDxy,        "track1_SDxyDxy/D");
        TheTree->Branch("track1_SDxyDsz",        &track1_SDxyDsz,        "track1_SDxyDsz/D");
        TheTree->Branch("track1_SDszDsz",        &track1_SDszDsz,        "track1_SDszDsz/D");

        TheTree->Branch("track2_SQopQop",        &track2_SQopQop,        "track2_SQopQop/D");
        TheTree->Branch("track2_SQopLam",        &track2_SQopLam,        "track2_SQopLam/D");
        TheTree->Branch("track2_SQopPhi",        &track2_SQopPhi,        "track2_SQopPhi/D");
        TheTree->Branch("track2_SQopDxy",        &track2_SQopDxy,        "track2_SQopDxy/D");
        TheTree->Branch("track2_SQopDsz",        &track2_SQopDsz,        "track2_SQopDsz/D");

        TheTree->Branch("track2_SLamLam",        &track2_SLamLam,        "track2_SLamLam/D");
        TheTree->Branch("track2_SLamPhi",        &track2_SLamPhi,        "track2_SLamPhi/D");
        TheTree->Branch("track2_SLamDxy",        &track2_SLamDxy,        "track2_SLamDxy/D");
        TheTree->Branch("track2_SLamDsz",        &track2_SLamDsz,        "track2_SLamDsz/D");
        TheTree->Branch("track2_SPhiPhi",        &track2_SPhiPhi,        "track2_SPhiPhi/D");

        TheTree->Branch("track2_SPhiDxy",        &track2_SPhiDxy,        "track2_SPhiDxy/D");
        TheTree->Branch("track2_SPhiDsz",        &track2_SPhiDsz,        "track2_SPhiDsz/D");
        TheTree->Branch("track2_SDxyDxy",        &track2_SDxyDxy,        "track2_SDxyDxy/D");
        TheTree->Branch("track2_SDxyDsz",        &track2_SDxyDsz,        "track2_SDxyDsz/D");
        TheTree->Branch("track2_SDszDsz",        &track2_SDszDsz,        "track2_SDszDsz/D");

        TheTree->Branch("dimuon_validFit",     &dimuon_validFit,       "dimuon_validFit/I");

        TheTree->Branch("mu1_charge",        &mu1_charge_,        "mu1_charge/I");
        TheTree->Branch("mu2_charge",        &mu2_charge_,        "mu2_charge/I");

        TheTree->Branch("mu1_eigenValues",        &mu1_eigenValues,        "mu1_eigenValues/D");
        TheTree->Branch("mu2_eigenValues",        &mu2_eigenValues,        "mu2_eigenValues/D");
        
        TheTree->Branch("mu1_SQopQop",        &mu1_SQopQop,        "mu1_SQopQop/D");
        TheTree->Branch("mu1_SQopLam",        &mu1_SQopLam,        "mu1_SQopLam/D");
        TheTree->Branch("mu1_SQopPhi",        &mu1_SQopPhi,        "mu1_SQopPhi/D");
        TheTree->Branch("mu1_SQopDxy",        &mu1_SQopDxy,        "mu1_SQopDxy/D");
        TheTree->Branch("mu1_SQopDsz",        &mu1_SQopDsz,        "mu1_SQopDsz/D");

        TheTree->Branch("mu1_SLamLam",        &mu1_SLamLam,        "mu1_SLamLam/D");
        TheTree->Branch("mu1_SLamPhi",        &mu1_SLamPhi,        "mu1_SLamPhi/D");
        TheTree->Branch("mu1_SLamDxy",        &mu1_SLamDxy,        "mu1_SLamDxy/D");
        TheTree->Branch("mu1_SLamDsz",        &mu1_SLamDsz,        "mu1_SLamDsz/D");
        TheTree->Branch("mu1_SPhiPhi",        &mu1_SPhiPhi,        "mu1_SPhiPhi/D");

        TheTree->Branch("mu1_SPhiDxy",        &mu1_SPhiDxy,        "mu1_SPhiDxy/D");
        TheTree->Branch("mu1_SPhiDsz",        &mu1_SPhiDsz,        "mu1_SPhiDsz/D");
        TheTree->Branch("mu1_SDxyDxy",        &mu1_SDxyDxy,        "mu1_SDxyDxy/D");
        TheTree->Branch("mu1_SDxyDsz",        &mu1_SDxyDsz,        "mu1_SDxyDsz/D");
        TheTree->Branch("mu1_SDszDsz",        &mu1_SDszDsz,        "mu1_SDszDsz/D");

        TheTree->Branch("mu2_SQopQop",        &mu2_SQopQop,        "mu2_SQopQop/D");
        TheTree->Branch("mu2_SQopLam",        &mu2_SQopLam,        "mu2_SQopLam/D");
        TheTree->Branch("mu2_SQopPhi",        &mu2_SQopPhi,        "mu2_SQopPhi/D");
        TheTree->Branch("mu2_SQopDxy",        &mu2_SQopDxy,        "mu2_SQopDxy/D");
        TheTree->Branch("mu2_SQopDsz",        &mu2_SQopDsz,        "mu2_SQopDsz/D");

        TheTree->Branch("mu2_SLamLam",        &mu2_SLamLam,        "mu2_SLamLam/D");
        TheTree->Branch("mu2_SLamPhi",        &mu2_SLamPhi,        "mu2_SLamPhi/D");
        TheTree->Branch("mu2_SLamDxy",        &mu2_SLamDxy,        "mu2_SLamDxy/D");
        TheTree->Branch("mu2_SLamDsz",        &mu2_SLamDsz,        "mu2_SLamDsz/D");
        TheTree->Branch("mu2_SPhiPhi",        &mu2_SPhiPhi,        "mu2_SPhiPhi/D");

        TheTree->Branch("mu2_SPhiDxy",        &mu2_SPhiDxy,        "mu2_SPhiDxy/D");
        TheTree->Branch("mu2_SPhiDsz",        &mu2_SPhiDsz,        "mu2_SPhiDsz/D");
        TheTree->Branch("mu2_SDxyDxy",        &mu2_SDxyDxy,        "mu2_SDxyDxy/D");
        TheTree->Branch("mu2_SDxyDsz",        &mu2_SDxyDsz,        "mu2_SDxyDsz/D");
        TheTree->Branch("mu2_SDszDsz",        &mu2_SDszDsz,        "mu2_SDszDsz/D");


	if(isMC_)
	  {
      TheTree->Branch("gen_candidate_pdgId", &gen_candidate_pdgId, "gen_candidate_pdgId/I");
      TheTree->Branch("gen_onia_pdgId",      &gen_onia_pdgId,      "gen_onia_pdgId/I");
	    TheTree->Branch("gen_candidate_p4","TLorentzVector", &gen_candidate_p4);
	    if (!is_dimuon_) TheTree->Branch("gen_onia_p4",     "TLorentzVector", &gen_onia_p4);
      TheTree->Branch("gen_dimuon_p4",   "TLorentzVector", &gen_dimuon_p4);
      if (!is_dimuon_) TheTree->Branch("gen_photon_p4",   "TLorentzVector", &gen_photon_p4);
      if (ditrack_pdgid_) TheTree->Branch("gen_ditrack_p4",   "TLorentzVector", &gen_ditrack_p4);
	    TheTree->Branch("gen_track1_p4",   "TLorentzVector", &gen_track1_p4);
      TheTree->Branch("gen_track1_pdgid", &gen_track1_pdgid, "gen_track1_pdgid/I");
      TheTree->Branch("gen_track2_p4",   "TLorentzVector", &gen_track2_p4);
      TheTree->Branch("gen_track2_pdgid", &gen_track2_pdgid, "gen_track2_pdgid/I");
      TheTree->Branch("gen_muonp_p4",    "TLorentzVector", &gen_muonp_p4);
      TheTree->Branch("gen_muonn_p4",    "TLorentzVector", &gen_muonn_p4);
      TheTree->Branch("gen_candidate_charge",     &gen_candidate_charge,       "gen_candidate_charge/I");
	  }

        UpsTree = fs->make<TTree>("UpsTree","UpsTree");

        UpsTree->Branch("run",                &run,                "run/I");
        UpsTree->Branch("event",              &event,              "event/I");
        UpsTree->Branch("numPrimaryVertices", &numPrimaryVertices, "numPrimaryVertices/I");
        UpsTree->Branch("trigger",            &trigger,            "trigger/I");
        UpsTree->Branch("ups_p4",   "TLorentzVector", &ups_p4);
        UpsTree->Branch("muonP_p4",    "TLorentzVector", &muonP_p4);
        UpsTree->Branch("muonN_p4",    "TLorentzVector", &muonN_p4);

        UpsTree->Branch("iPVwithmuons_ups",        &iPVwithmuons_ups,        "iPVwithmuons_ups/I");

        UpsTree->Branch("ups_diMuIndx",       &ups_diMuIndx,        "ups_diMuIndx/I");
        UpsTree->Branch("ups_vertexWeight",        &ups_vertexWeight,        "ups_vertexWeight/D");
        UpsTree->Branch("ups_vProb",        &ups_vProb,        "ups_vProb/D");
        UpsTree->Branch("ups_vMass",        &ups_vMass,        "ups_vMass/D");
        UpsTree->Branch("ups_vNChi2",       &ups_vChi2,        "ups_vNChi2/D");
        UpsTree->Branch("ups_DCA",          &ups_DCA,          "ups_DCA/D");
        UpsTree->Branch("ups_ctauPV",       &ups_ctauPV,       "ups_ctauPV/D");
        UpsTree->Branch("ups_ctauErrPV",    &ups_ctauErrPV,    "ups_ctauErrPV/D");
        UpsTree->Branch("ups_lxyPV",        &ups_lxyPV,          "ups_lxyPV/D");
        UpsTree->Branch("ups_lxyErrPV",     &ups_lxyErrPV,       "ups_lxyErrPV/D");
        UpsTree->Branch("ups_cosAlpha",     &ups_cosAlpha,     "ups_cosAlpha/D");
        UpsTree->Branch("ups_ctauBS",       &ups_ctauBS,       "ups_ctauBS/D");
        UpsTree->Branch("ups_ctauErrBS",    &ups_ctauErrBS,    "ups_ctauErrBS/D");
        UpsTree->Branch("ups_lxyBS",        &ups_lxyBS,          "ups_lxyBS/D");
        UpsTree->Branch("ups_lxyErrBS",     &ups_lxyErrBS,       "ups_lxyErrBS/D");

        UpsTree->Branch("ups_validFit",     &ups_validFit,       "ups_validFit/I");

        UpsTree->Branch("mu1_pt",    &mu1_pt,    "mu1_pt/D");
        UpsTree->Branch("mu1_ptErr",    &mu1_ptErr,    "mu1_ptErr/D");
        UpsTree->Branch("mu1_d0",    &mu1_d0,    "mu1_d0/D");
        UpsTree->Branch("mu1_d0Err", &mu1_d0Err, "mu1_d0Err/D");
        UpsTree->Branch("mu1_dz",    &mu1_dz,    "mu1_dz/D");
        UpsTree->Branch("mu1_dzErr",    &mu1_dzErr,    "mu1_dzErr/D");
        UpsTree->Branch("mu1_dxy",   &mu1_dxy,   "mu1_dxy/D");
        UpsTree->Branch("mu1_dxyErr",   &mu1_dxyErr,   "mu1_dxyErr/D");
        UpsTree->Branch("mu1_nvsh",  &mu1_nvsh,  "mu1_nvsh/I");
        UpsTree->Branch("mu1_nvph",  &mu1_nvph,  "mu1_nvph/I");
        UpsTree->Branch("mu1_charge",  &mu1_charge,  "mu1_charge/I");

        UpsTree->Branch("mu2_pt",    &mu2_pt,    "mu2_pt/D");
        UpsTree->Branch("mu2_ptErr",    &mu2_ptErr,    "mu2_ptErr/D");
        UpsTree->Branch("mu2_d0",    &mu2_d0,    "mu2_d0/D");
        UpsTree->Branch("mu2_d0Err", &mu2_d0Err, "mu2_d0Err/D");
        UpsTree->Branch("mu2_dz",    &mu2_dz,    "mu2_dz/D");
        UpsTree->Branch("mu2_dzErr",    &mu2_dzErr,    "mu2_dzErr/D");
        UpsTree->Branch("mu2_dxy",   &mu2_dxy,   "mu2_dxy/D");
        UpsTree->Branch("mu2_dxyErr",   &mu2_dxyErr,   "mu2_dxyErr/D");
        UpsTree->Branch("mu2_nvsh",  &mu2_nvsh,  "mu2_nvsh/I");
        UpsTree->Branch("mu2_nvph",  &mu2_nvph,  "mu2_nvph/I");
        UpsTree->Branch("mu2_charge",  &mu2_charge,  "mu2_charge/I");

        UpsTree->Branch("ups_mu1_eigenValues",        &ups_mu1_eigenValues,        "ups_mu1_eigenValues/D");
        UpsTree->Branch("ups_mu2_eigenValues",        &ups_mu2_eigenValues,        "ups_mu2_eigenValues/D");
        
        UpsTree->Branch("ups_mu1_SQopQop",        &ups_mu1_SQopQop,        "ups_mu1_SQopQop/D");
        UpsTree->Branch("ups_mu1_SQopLam",        &ups_mu1_SQopLam,        "ups_mu1_SQopLam/D");
        UpsTree->Branch("ups_mu1_SQopPhi",        &ups_mu1_SQopPhi,        "ups_mu1_SQopPhi/D");
        UpsTree->Branch("ups_mu1_SQopDxy",        &ups_mu1_SQopDxy,        "ups_mu1_SQopDxy/D");
        UpsTree->Branch("ups_mu1_SQopDsz",        &ups_mu1_SQopDsz,        "ups_mu1_SQopDsz/D");

        UpsTree->Branch("ups_mu1_SLamLam",        &ups_mu1_SLamLam,        "ups_mu1_SLamLam/D");
        UpsTree->Branch("ups_mu1_SLamPhi",        &ups_mu1_SLamPhi,        "ups_mu1_SLamPhi/D");
        UpsTree->Branch("ups_mu1_SLamDxy",        &ups_mu1_SLamDxy,        "ups_mu1_SLamDxy/D");
        UpsTree->Branch("ups_mu1_SLamDsz",        &ups_mu1_SLamDsz,        "ups_mu1_SLamDsz/D");
        UpsTree->Branch("ups_mu1_SPhiPhi",        &ups_mu1_SPhiPhi,        "ups_mu1_SPhiPhi/D");

        UpsTree->Branch("ups_mu1_SPhiDxy",        &ups_mu1_SPhiDxy,        "ups_mu1_SPhiDxy/D");
        UpsTree->Branch("ups_mu1_SPhiDsz",        &ups_mu1_SPhiDsz,        "ups_mu1_SPhiDsz/D");
        UpsTree->Branch("ups_mu1_SDxyDxy",        &ups_mu1_SDxyDxy,        "ups_mu1_SDxyDxy/D");
        UpsTree->Branch("ups_mu1_SDxyDsz",        &ups_mu1_SDxyDsz,        "ups_mu1_SDxyDsz/D");
        UpsTree->Branch("ups_mu1_SDszDsz",        &ups_mu1_SDszDsz,        "ups_mu1_SDszDsz/D");

        UpsTree->Branch("ups_mu2_SQopQop",        &ups_mu2_SQopQop,        "ups_mu2_SQopQop/D");
        UpsTree->Branch("ups_mu2_SQopLam",        &ups_mu2_SQopLam,        "ups_mu2_SQopLam/D");
        UpsTree->Branch("ups_mu2_SQopPhi",        &ups_mu2_SQopPhi,        "ups_mu2_SQopPhi/D");
        UpsTree->Branch("ups_mu2_SQopDxy",        &ups_mu2_SQopDxy,        "ups_mu2_SQopDxy/D");
        UpsTree->Branch("ups_mu2_SQopDsz",        &ups_mu2_SQopDsz,        "ups_mu2_SQopDsz/D");

        UpsTree->Branch("ups_mu2_SLamLam",        &ups_mu2_SLamLam,        "ups_mu2_SLamLam/D");
        UpsTree->Branch("ups_mu2_SLamPhi",        &ups_mu2_SLamPhi,        "ups_mu2_SLamPhi/D");
        UpsTree->Branch("ups_mu2_SLamDxy",        &ups_mu2_SLamDxy,        "ups_mu2_SLamDxy/D");
        UpsTree->Branch("ups_mu2_SLamDsz",        &ups_mu2_SLamDsz,        "ups_mu2_SLamDsz/D");
        UpsTree->Branch("ups_mu2_SPhiPhi",        &ups_mu2_SPhiPhi,        "ups_mu2_SPhiPhi/D");

        UpsTree->Branch("ups_mu2_SPhiDxy",        &ups_mu2_SPhiDxy,        "ups_mu2_SPhiDxy/D");
        UpsTree->Branch("ups_mu2_SPhiDsz",        &ups_mu2_SPhiDsz,        "ups_mu2_SPhiDsz/D");
        UpsTree->Branch("ups_mu2_SDxyDxy",        &ups_mu2_SDxyDxy,        "ups_mu2_SDxyDxy/D");
        UpsTree->Branch("ups_mu2_SDxyDsz",        &ups_mu2_SDxyDsz,        "ups_mu2_SDxyDsz/D");
        UpsTree->Branch("ups_mu2_SDszDsz",        &ups_mu2_SDszDsz,        "ups_mu2_SDszDsz/D");



}

void OniaRecoTrackTrackRootupler::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup) {
  using namespace std;

  edm::Handle < pat::CompositeCandidateCollection >TheCandidates;
  iEvent.getByToken(TheCandidateLabel, TheCandidates);

  edm::Handle < pat::CompositeCandidateCollection >TheUps;
  iEvent.getByToken(TheUpsLabel, TheUps);

  edm::Handle < reco::VertexCollection  >ThePrimaryVertices;
  iEvent.getByToken(ThePrimaryVertexLabel, ThePrimaryVertices);

  edm::Handle < edm::TriggerResults > triggerResults_handle;
  iEvent.getByToken(TheTriggerResultLabel, triggerResults_handle);

  numPrimaryVertices = ThePrimaryVertices->size();
  run = iEvent.id().run();
  event = iEvent.id().event();
  luminosityBlock = iEvent.id().luminosityBlock();

  gen_onia_p4.SetPtEtaPhiM(0,0,0,0);
  gen_photon_p4.SetPtEtaPhiM(0,0,0,0);
  gen_ditrack_p4.SetPtEtaPhiM(0,0,0,0);
  
  if ( isMC_ ) {
    edm::Handle<reco::GenParticleCollection> GenParticles;
    iEvent.getByToken(TheGenParticleLabel, GenParticles);
    int foundit = 0;
    //int gen_track1_pdgid_ = 0;
    //int gen_track2_pdgid_ = 0;
    gen_candidate_pdgId = 0;
    if (GenParticles.isValid() ) {
      for ( reco::GenParticleCollection::const_iterator itParticle = GenParticles->begin(); itParticle != GenParticles->end(); ++itParticle ) {
        int pdgId = itParticle->pdgId();
        if ( abs(pdgId) ==  candidate_pdgid_ ) {
          //const reco::Candidate* gen_y2s = itParticle
          gen_candidate_charge = itParticle->charge();
          gen_candidate_p4.SetPtEtaPhiM(itParticle->pt(),itParticle->eta(),itParticle->phi(),itParticle->mass());
          gen_candidate_pdgId = pdgId;
          foundit++;
          for (uint i = 0; i < itParticle->numberOfDaughters(); ++i) {
            const reco::Candidate* b = itParticle->daughter(i);
            int bpdgid = b->pdgId();
            if ( abs(bpdgid) == onia_pdgid_ && b->status() == 2 ) {
              gen_onia_pdgId = bpdgid;
              const reco::Candidate* d = nullptr;
              const reco::Candidate* g = nullptr;
              if (is_dimuon_) {
                d = b;
              } else {
                gen_onia_p4.SetPtEtaPhiM(b->pt(),b->eta(),b->phi(),b->mass());
                if (b->daughter(0)->pdgId() == 22) {
                   g = b->daughter(0);
                   d = b->daughter(1);
                } else {
                   g = b->daughter(1);
                   d = b->daughter(0);
                }
              }
              if (g) gen_photon_p4.SetPtEtaPhiM(g->pt(),g->eta(),g->phi(),g->mass());
              if (d) {
                   gen_dimuon_p4.SetPtEtaPhiM(d->pt(),d->eta(),d->phi(),d->mass());
                   foundit++;
                   for (uint j = 0; j < d->numberOfDaughters(); ++j) {
                     const reco::Candidate* p = d->daughter(j);
                     if ( p->pdgId() == -13 && p->status() == 1 ) {
                        gen_muonp_p4.SetPtEtaPhiM(p->pt(),p->eta(),p->phi(),p->mass());
                        foundit++;
                     }
                     if ( p->pdgId() == 13 && p->status() == 1 ) {
                        gen_muonn_p4.SetPtEtaPhiM(p->pt(),p->eta(),p->phi(),p->mass());
                        foundit++;
                     }
                   }
              } // d
            }
            if (ditrack_pdgid_ && abs(bpdgid) == ditrack_pdgid_) {
              gen_ditrack_p4.SetPtEtaPhiM(b->pt(),b->eta(),b->phi(),b->mass());
              for (uint k = 0; k < b->numberOfDaughters(); ++k) {
                const reco::Candidate* p = b->daughter(k);
                if ( p->pdgId() == track1_pdgid_ && p->status() == 1 ) {
                   std::cout<<" in dipion - pion 1 "<<std::endl;
                   //track1.SetPtEtaPhiM(p->pt(),p->eta(),p->phi(),p->mass());
                   //gen_track1_pdgid_ = track1_pdgid_;
                   gen_track1_p4.SetPtEtaPhiM(p->pt(),p->eta(),p->phi(),p->mass());
                   gen_track1_pdgid = track1_pdgid_;
                   foundit++;
                }
                if ( p->pdgId() == track2_pdgid_ && p->status() == 1 ) {
                   std::cout<<" in dipion - pion 2 "<<std::endl;
                   //track2.SetPtEtaPhiM(p->pt(),p->eta(),p->phi(),p->mass());
                   //gen_track2_pdgid_ = track2_pdgid_;
                   gen_track2_p4.SetPtEtaPhiM(p->pt(),p->eta(),p->phi(),p->mass());
                   gen_track2_pdgid = track2_pdgid_;
                   foundit++;
                }
              }
            } else {
              if ( bpdgid == track1_pdgid_ && b->status() == 1 ) {
                //std::cout<<" pion 1 "<<std::endl;
                //track1.SetPtEtaPhiM(b->pt(),b->eta(),b->phi(),b->mass());
                //gen_track1_pdgid_ = track1_pdgid_;
                gen_track1_p4.SetPtEtaPhiM(b->pt(),b->eta(),b->phi(),b->mass());
                gen_track1_pdgid = track1_pdgid_;
                foundit++;
              }
              if ( bpdgid == track2_pdgid_ && b->status() == 1 ) {
                //std::cout<<" pion 2 "<<std::endl;
                //track2.SetPtEtaPhiM(b->pt(),b->eta(),b->phi(),b->mass());
                //gen_track2_pdgid_ = track2_pdgid_;
                gen_track2_p4.SetPtEtaPhiM(b->pt(),b->eta(),b->phi(),b->mass());
                gen_track2_pdgid = track2_pdgid_;             
                foundit++;
              }
            }
          }
          if ( foundit == 6 ) break;
          else {
            foundit = 0;
            gen_candidate_pdgId = 0;
          }
        } // if ( abs(
      }   // for ( reco
    }
    if (!gen_candidate_pdgId) std::cout << "OniaRecoTrackTrackRootupler: didn't find the given decay " << run << "," << event << std::endl;
  } // end if isMC

   trigger = 0;
   if (triggerResults_handle.isValid()) {
      const edm::TriggerNames & TheTriggerNames = iEvent.triggerNames(*triggerResults_handle);
      unsigned int NTRIGGERS = 10;
      std::string TriggersToTest[NTRIGGERS] = {
        "HLT_Dimuon20_Jpsi_Barrel_Seagulls","HLT_Dimuon25_Jpsi",
        "HLT_Dimuon10_PsiPrime_Barrel_Seagulls","HLT_Dimuon18_PsiPrime",
        "HLT_Dimuon10_Upsilon_Barrel_Seagulls","HLT_Dimuon12_Upsilon_eta1p5",
        "HLT_Dimuon14_Phi_Barrel_Seagulls","HLT_Dimuon12_Upsilon_y1p4",
        "HLT_Dimuon8_Upsilon_Barrel","HLT_Dimuon13_Upsilon"
      };

      for (unsigned int i = 0; i < NTRIGGERS; i++) {
         for (int version = 1; version < 19; version++) {
            std::stringstream ss;
            ss << TriggersToTest[i] << "_v" << version;
            unsigned int bit = TheTriggerNames.triggerIndex(edm::InputTag(ss.str()).label());
            if (bit < triggerResults_handle->size() && triggerResults_handle->accept(bit) && !triggerResults_handle->error(bit)) {
               trigger += (1<<i);
               break;
            }
         }
      }
    } else std::cout << "*** NO triggerResults found " << iEvent.id().run() << "," << iEvent.id().event() << std::endl;

  //onia_p4.SetPtEtaPhiM(0,0,0,0);
  //photon_p4.SetPtEtaPhiM(0,0,0,0);
// grabbing candidate information. Notice we are just keeping combinations with succesfull vertex fit
  if (TheCandidates.isValid() && !TheCandidates->empty()) {
    pat::CompositeCandidate TheCandidate_;
    nCandPerEvent = TheCandidates->size();
    for (unsigned int i=0; i< TheCandidates->size(); i++){
      TheCandidate_       = TheCandidates->at(i);
      candidate_vMass     = TheCandidate_.userFloat("vMass");
      candidate_vProb     = TheCandidate_.userFloat("vProb");
      candidate_vChi2     = TheCandidate_.userFloat("vChi2");
      candidate_cosAlpha  = TheCandidate_.userFloat("cosAlpha");
      candidate_ctauPV    = TheCandidate_.userFloat("ctauPV");
      candidate_ctauErrPV = TheCandidate_.userFloat("ctauErrPV");
      candidate_charge    = TheCandidate_.charge();
      candidate_lxy       = TheCandidate_.userFloat("lxy");
      candidate_lxyErr    = TheCandidate_.userFloat("lxyErr");
      candidate_lxyz      = TheCandidate_.userFloat("lxyz");
      candidate_lxyzErr   = TheCandidate_.userFloat("lxyzErr");

      candidate_validFit = TheCandidate_.userInt("validFit");
      candidate_validStateFit = TheCandidate_.userInt("validStateFit");

      thePrimaryV_X = TheCandidate_.userFloat("thePrimaryV_X");
      thePrimaryV_Y = TheCandidate_.userFloat("thePrimaryV_Y");
      thePrimaryV_Z = TheCandidate_.userFloat("thePrimaryV_Z");
      TheDecayVertex_X = TheCandidate_.userFloat("TheDecayVertex_X");
      TheDecayVertex_Y = TheCandidate_.userFloat("TheDecayVertex_Y");
      TheDecayVertex_Z = TheCandidate_.userFloat("TheDecayVertex_Z");
      thePrimaryV_2D_position = TheCandidate_.userFloat("thePrimaryV_2D_position");
      thePrimaryV_3D_position = TheCandidate_.userFloat("thePrimaryV_3D_position");
      TheDecayVertex_2D_position = TheCandidate_.userFloat("TheDecayVertex_2D_position");
      TheDecayVertex_3D_position = TheCandidate_.userFloat("TheDecayVertex_3D_position");
      TheVertexDistance_2D = TheCandidate_.userFloat("TheVertexDistance_2D");
      TheVertexDistance_3D = TheCandidate_.userFloat("TheVertexDistance_3D");

      ditrack_dRdimuon    = TheCandidate_.userFloat("ditrack_dRdimuon");
      track1_dRdimuon    = TheCandidate_.userFloat("track1_dRdimuon");
      track2_dRdimuon    = TheCandidate_.userFloat("track2_dRdimuon");
      track1_PV  = TheCandidate_.userInt("track1_PV");
      track2_PV  = TheCandidate_.userInt("track2_PV");
      track1_refVtx  = TheCandidate_.userInt("track1_refVtx");
      track2_refVtx  = TheCandidate_.userInt("track2_refVtx");
      track1_pvAssocQ  = TheCandidate_.userInt("track1_pvAssocQ");
      track2_pvAssocQ  = TheCandidate_.userInt("track2_pvAssocQ");

      track1_dzAssocPV = TheCandidate_.userFloat("track1_dzAssocPV");
      track2_dzAssocPV = TheCandidate_.userFloat("track2_dzAssocPV");

      //collect covariance matrix
      track1_SQopQop = TheCandidate_.userFloat("track1_SQopQop");
      track1_SQopLam = TheCandidate_.userFloat("track1_SQopLam");
      track1_SQopPhi = TheCandidate_.userFloat("track1_SQopPhi");
      track1_SQopDxy = TheCandidate_.userFloat("track1_SQopDxy");
      track1_SQopDsz = TheCandidate_.userFloat("track1_SQopDsz");
      track1_SLamLam = TheCandidate_.userFloat("track1_SLamLam");
      track1_SLamPhi = TheCandidate_.userFloat("track1_SLamPhi");
      track1_SLamDxy = TheCandidate_.userFloat("track1_SLamDxy");
      track1_SLamDsz = TheCandidate_.userFloat("track1_SLamDsz");
      track1_SPhiPhi = TheCandidate_.userFloat("track1_SPhiPhi");
      track1_SPhiDxy = TheCandidate_.userFloat("track1_SPhiDxy");
      track1_SPhiDsz = TheCandidate_.userFloat("track1_SPhiDsz");
      track1_SDxyDxy = TheCandidate_.userFloat("track1_SDxyDxy");
      track1_SDxyDsz = TheCandidate_.userFloat("track1_SDxyDsz");
      track1_SDszDsz = TheCandidate_.userFloat("track1_SDszDsz");

      track2_SQopQop = TheCandidate_.userFloat("track2_SQopQop");
      track2_SQopLam = TheCandidate_.userFloat("track2_SQopLam");
      track2_SQopPhi = TheCandidate_.userFloat("track2_SQopPhi");
      track2_SQopDxy = TheCandidate_.userFloat("track2_SQopDxy");
      track2_SQopDsz = TheCandidate_.userFloat("track2_SQopDsz");
      track2_SLamLam = TheCandidate_.userFloat("track2_SLamLam");
      track2_SLamPhi = TheCandidate_.userFloat("track2_SLamPhi");
      track2_SLamDxy = TheCandidate_.userFloat("track2_SLamDxy");
      track2_SLamDsz = TheCandidate_.userFloat("track2_SLamDsz");
      track2_SPhiPhi = TheCandidate_.userFloat("track2_SPhiPhi");
      track2_SPhiDxy = TheCandidate_.userFloat("track2_SPhiDxy");
      track2_SPhiDsz = TheCandidate_.userFloat("track2_SPhiDsz");
      track2_SDxyDxy = TheCandidate_.userFloat("track2_SDxyDxy");
      track2_SDxyDsz = TheCandidate_.userFloat("track2_SDxyDsz");
      track2_SDszDsz = TheCandidate_.userFloat("track2_SDszDsz");

      track1_eigenValues = TheCandidate_.userFloat("track1_eigenValues");
      track2_eigenValues = TheCandidate_.userFloat("track2_eigenValues");


      const pat::CompositeCandidate *TheOnia_   = nullptr;
      const pat::CompositeCandidate *ThePhoton_ = nullptr;
      const pat::CompositeCandidate *TheDimuon_ = nullptr;
      const reco::Vertex *ThePrimaryV_ = nullptr;
      if (TheCandidate_.userInt("isDimuon")) {
         TheDimuon_ = dynamic_cast <pat::CompositeCandidate *>(TheCandidate_.daughter("onia"));
         ThePrimaryV_ = TheDimuon_->userData<reco::Vertex>("PVwithmuons");
      } else {
         TheOnia_   = dynamic_cast <pat::CompositeCandidate *>(TheCandidate_.daughter("onia"));
         TheDimuon_ = dynamic_cast <pat::CompositeCandidate *>(TheCandidate_.daughter("onia")->daughter("dimuon"));
         ThePrimaryV_ = TheDimuon_->userData<reco::Vertex>("PVwithmuons");
         ThePhoton_ = dynamic_cast <pat::CompositeCandidate *>(TheCandidate_.daughter("onia")->daughter("photon"));
         onia_p4.SetPtEtaPhiM(TheOnia_->pt(),TheOnia_->eta(),TheOnia_->phi(),TheOnia_->mass());
         photon_p4.SetPtEtaPhiM(ThePhoton_->pt(),ThePhoton_->eta(),ThePhoton_->phi(),ThePhoton_->mass());
         Double_t ele1_pt = (dynamic_cast<const pat::CompositeCandidate *>(TheCandidate_.daughter("onia")->daughter("photon"))->
                                    userData<reco::Track>("track0"))->pt();
         Double_t ele2_pt = (dynamic_cast<const pat::CompositeCandidate *>(TheCandidate_.daughter("onia")->daughter("photon"))->
                                    userData<reco::Track>("track1"))->pt();
         Double_t ele1_eta = (dynamic_cast<const pat::CompositeCandidate *>(TheCandidate_.daughter("onia")->daughter("photon"))->
                                    userData<reco::Track>("track0"))->eta();
         Double_t ele2_eta = (dynamic_cast<const pat::CompositeCandidate *>(TheCandidate_.daughter("onia")->daughter("photon"))->
                                    userData<reco::Track>("track1"))->eta();
         Double_t ele1_phi = (dynamic_cast<const pat::CompositeCandidate *>(TheCandidate_.daughter("onia")->daughter("photon"))->
                                    userData<reco::Track>("track0"))->phi();
         Double_t ele2_phi = (dynamic_cast<const pat::CompositeCandidate *>(TheCandidate_.daughter("onia")->daughter("photon"))->
                                    userData<reco::Track>("track1"))->phi();
         ele_trk0.SetPtEtaPhiM(ele1_pt, ele1_eta, ele1_phi, ele_mass);
         ele_trk1.SetPtEtaPhiM(ele2_pt, ele2_eta, ele2_phi, ele_mass);

        conv_vertex = TheCandidate_.daughter("onia")->daughter("photon")->vertex().rho();
        conv_vertex_x = TheCandidate_.daughter("onia")->daughter("photon")->vertex().x();
        conv_vertex_y = TheCandidate_.daughter("onia")->daughter("photon")->vertex().y();
        conv_vertex_z = TheCandidate_.daughter("onia")->daughter("photon")->vertex().z();
        conv_vertex_r = TheCandidate_.daughter("onia")->daughter("photon")->vertex().r();
        conv_vertex_eta = TheCandidate_.daughter("onia")->daughter("photon")->vertex().eta();
        conv_vertex_phi = TheCandidate_.daughter("onia")->daughter("photon")->vertex().phi();
        conv_vertex_theta = TheCandidate_.daughter("onia")->daughter("photon")->vertex().theta();

        diMuInChi_index = TheOnia_->userInt("index_diMuInChi");
        Chi_index = TheOnia_->userInt("index_Chi");
        Chi_dZ = TheOnia_->userFloat("dz");
        Chi_dM = TheOnia_->userFloat("deltaM");

      }
      const reco::Track *TheTrack1_ =  dynamic_cast <const reco::Track *>(TheCandidate_.userData<reco::Track>("track1"));
      const reco::Track *TheTrack2_ =  dynamic_cast <const reco::Track *>(TheCandidate_.userData<reco::Track>("track2"));

      candidate_p4.SetPtEtaPhiM(TheCandidate_.pt(),TheCandidate_.eta(),TheCandidate_.phi(),TheCandidate_.mass());
      dimuon_p4.SetPtEtaPhiM(TheDimuon_->pt(),TheDimuon_->eta(),TheDimuon_->phi(),TheDimuon_->mass());
      track1_p4.SetPtEtaPhiM(TheTrack1_->pt(),TheTrack1_->eta(),TheTrack1_->phi(),Track1Mass_);
      track2_p4.SetPtEtaPhiM(TheTrack2_->pt(),TheTrack2_->eta(),TheTrack2_->phi(),Track2Mass_);
      ditrack_p4 = track1_p4 + track2_p4;

      typedef math::XYZPoint Point;
      Point pv_(ThePrimaryV_->x(),ThePrimaryV_->y(),ThePrimaryV_->z());

      track1_d0      = TheTrack1_->d0();
      track1_d0Err   = TheTrack1_->d0Error();
      track1_dz      = TheTrack1_->dz(pv_);
      track1_dzErr   = TheTrack1_->dzError();
      track1_dxy     = TheTrack1_->dxy(pv_);
      track1_dxyErr  = TheTrack1_->dxyError();
      track1_nvsh    = TheTrack1_->hitPattern().numberOfValidStripHits();
      track1_nvph    = TheTrack1_->hitPattern().numberOfValidPixelHits();
      track1_charge  = TheTrack1_->charge();

      track2_d0      = TheTrack2_->d0();
      track2_d0Err   = TheTrack2_->d0Error();
      track2_dz      = TheTrack2_->dz(pv_);
      track2_dzErr   = TheTrack2_->dzError();
      track2_dxy     = TheTrack2_->dxy(pv_);
      track2_dxyErr  = TheTrack2_->dxyError();
      track2_nvsh    = TheTrack2_->hitPattern().numberOfValidStripHits();
      track2_nvph    = TheTrack2_->hitPattern().numberOfValidPixelHits();
      track2_charge  = TheTrack2_->charge();

      iPVwithmuons = TheDimuon_->userInt("iPV");

      dimuon_diMuIndx     = TheDimuon_->userInt("diMuIndex");
      dimuon_vertexWeight = TheDimuon_->userFloat("vertexWeight");
      dimuon_vProb        = TheDimuon_->userFloat("vProb");
      dimuon_vChi2        = TheDimuon_->userFloat("vNChi2");
      dimuon_DCA          = TheDimuon_->userFloat("DCA");
      dimuon_ctauPV       = TheDimuon_->userFloat("ppdlPV");
      dimuon_ctauErrPV    = TheDimuon_->userFloat("ppdlErrPV");
      dimuon_cosAlpha     = TheDimuon_->userFloat("cosAlpha");

      dimuon_validFit = TheDimuon_->userInt("validFit");

      mu1_charge_ = TheDimuon_->userInt("mu1_charge");
      mu2_charge_ = TheDimuon_->userInt("mu2_charge");

      mu1_SQopQop = TheDimuon_->userFloat("mu1_SQopQop");
      mu1_SQopLam = TheDimuon_->userFloat("mu1_SQopLam");
      mu1_SQopPhi = TheDimuon_->userFloat("mu1_SQopPhi");
      mu1_SQopDxy = TheDimuon_->userFloat("mu1_SQopDxy");
      mu1_SQopDsz = TheDimuon_->userFloat("mu1_SQopDsz");
      mu1_SLamLam = TheDimuon_->userFloat("mu1_SLamLam");
      mu1_SLamPhi = TheDimuon_->userFloat("mu1_SLamPhi");
      mu1_SLamDxy = TheDimuon_->userFloat("mu1_SLamDxy");
      mu1_SLamDsz = TheDimuon_->userFloat("mu1_SLamDsz");
      mu1_SPhiPhi = TheDimuon_->userFloat("mu1_SPhiPhi");
      mu1_SPhiDxy = TheDimuon_->userFloat("mu1_SPhiDxy");
      mu1_SPhiDsz = TheDimuon_->userFloat("mu1_SPhiDsz");
      mu1_SDxyDxy = TheDimuon_->userFloat("mu1_SDxyDxy");
      mu1_SDxyDsz = TheDimuon_->userFloat("mu1_SDxyDsz");
      mu1_SDszDsz = TheDimuon_->userFloat("mu1_SDszDsz");

      mu2_SQopQop = TheDimuon_->userFloat("mu2_SQopQop");
      mu2_SQopLam = TheDimuon_->userFloat("mu2_SQopLam");
      mu2_SQopPhi = TheDimuon_->userFloat("mu2_SQopPhi");
      mu2_SQopDxy = TheDimuon_->userFloat("mu2_SQopDxy");
      mu2_SQopDsz = TheDimuon_->userFloat("mu2_SQopDsz");
      mu2_SLamLam = TheDimuon_->userFloat("mu2_SLamLam");
      mu2_SLamPhi = TheDimuon_->userFloat("mu2_SLamPhi");
      mu2_SLamDxy = TheDimuon_->userFloat("mu2_SLamDxy");
      mu2_SLamDsz = TheDimuon_->userFloat("mu2_SLamDsz");
      mu2_SPhiPhi = TheDimuon_->userFloat("mu2_SPhiPhi");
      mu2_SPhiDxy = TheDimuon_->userFloat("mu2_SPhiDxy");
      mu2_SPhiDsz = TheDimuon_->userFloat("mu2_SPhiDsz");
      mu2_SDxyDxy = TheDimuon_->userFloat("mu2_SDxyDxy");
      mu2_SDxyDsz = TheDimuon_->userFloat("mu2_SDxyDsz");
      mu2_SDszDsz = TheDimuon_->userFloat("mu2_SDszDsz");

      mu1_eigenValues = TheDimuon_->userFloat("mu1_eigenValues");
      mu2_eigenValues = TheDimuon_->userFloat("mu2_eigenValues");

      const reco::Candidate::LorentzVector vP = TheDimuon_->daughter("muon1")->p4();
      const reco::Candidate::LorentzVector vM = TheDimuon_->daughter("muon2")->p4();
      if (TheDimuon_->daughter("muon1")->charge() > 0) {
      	 muonp_p4.SetPtEtaPhiM(vP.pt(), vP.eta(), vP.phi(), vP.mass());
      	 muonn_p4.SetPtEtaPhiM(vM.pt(), vM.eta(), vM.phi(), vM.mass());
      } else {
         muonn_p4.SetPtEtaPhiM(vP.pt(), vP.eta(), vP.phi(), vP.mass());
         muonp_p4.SetPtEtaPhiM(vM.pt(), vM.eta(), vM.phi(), vM.mass());
      }

      double y1w = TMath::Abs(dimuon_p4.Rapidity());
      double y1s_sigma = Y_sig_par_A + Y_sig_par_B*y1w + Y_sig_par_C*y1w*y1w;
      double onia_sigma = y1s_sigma*DimuonMass_/ups1SMass;
      dimuon_nSigma = TMath::Abs(dimuon_p4.M() - DimuonMass_) / onia_sigma;

      if (TheCandidate_.userInt("isDimuon")) {
        double QValue = candidate_p4.M() - dimuon_p4.M();
        invm1Spipi = QValue + ups1SMass;
        invm2Spipi = QValue + ups2SMass;
      } else {
        double QValue = candidate_p4.M() - onia_p4.M();
        invmchi11Ppipi = QValue + chib11PMass;
        invmchi21Ppipi = QValue + chib21PMass;
      }

      TheTree->Fill();
      if (OnlyBest_) break; 
    }
  } else std::cout<< "No candidate information " << run << "," << event <<std::endl;
 
  if (TheUps.isValid() && !TheUps->empty()) {
    pat::CompositeCandidate TheUps_;
    for (unsigned int i=0; i< TheUps->size(); i++){
      TheUps_       = TheUps->at(i);

      ups_p4.SetPtEtaPhiM(TheUps_.pt(),TheUps_.eta(),TheUps_.phi(),TheUps_.mass());

      ups_diMuIndx    = TheUps_.userInt("diMuIndex");
      ups_vertexWeight = TheUps_.userFloat("vertexWeight");
      ups_vProb        = TheUps_.userFloat("vProb");
      ups_vMass        = TheUps_.userFloat("vMass");
      ups_vChi2        = TheUps_.userFloat("vNChi2");
      ups_DCA          = TheUps_.userFloat("DCA");
      ups_ctauPV       = TheUps_.userFloat("ppdlPV");
      ups_ctauErrPV    = TheUps_.userFloat("ppdlErrPV");
      ups_cosAlpha     = TheUps_.userFloat("cosAlpha");

      ups_lxyPV        = TheUps_.userFloat("lxyPV");
      ups_lxyErrPV     = TheUps_.userFloat("lxyErrPV");
      ups_ctauBS       = TheUps_.userFloat("ppdlBS");
      ups_ctauErrBS    = TheUps_.userFloat("ppdlErrBS");
      ups_lxyBS        = TheUps_.userFloat("lxyBS");
      ups_lxyErrBS     = TheUps_.userFloat("lxyErrBS");

      iPVwithmuons_ups = TheUps_.userInt("iPV");

      const reco::Candidate::LorentzVector muP = TheUps_.daughter("muon1")->p4();
      const reco::Candidate::LorentzVector muM = TheUps_.daughter("muon2")->p4();
      if (TheUps_.daughter("muon1")->charge() > 0) {
         muonP_p4.SetPtEtaPhiM(muP.pt(), muP.eta(), muP.phi(), muP.mass());
         muonN_p4.SetPtEtaPhiM(muM.pt(), muM.eta(), muM.phi(), muM.mass());
      } else {
         muonN_p4.SetPtEtaPhiM(muP.pt(), muP.eta(), muP.phi(), muP.mass());
         muonP_p4.SetPtEtaPhiM(muM.pt(), muM.eta(), muM.phi(), muM.mass());
      }

      ups_validFit = TheUps_.userInt("validFit");

      //double testPt1 = 0.;
      if (TheUps_.userInt("mu1_charge") > 0) {
        //testPt1 = TheUps_.userFloat("mu1_pt");
        mu1_pt      = TheUps_.userFloat("mu1_pt");
        mu1_ptErr   = TheUps_.userFloat("mu1_ptErr");
        mu1_d0      = TheUps_.userFloat("mu1_d0");
        mu1_d0Err   = TheUps_.userFloat("mu1_d0Err");
        mu1_dz      = TheUps_.userFloat("mu1_dz");
        mu1_dzErr   = TheUps_.userFloat("mu1_dzErr");
        mu1_dxy     = TheUps_.userFloat("mu1_dxy");
        mu1_dxyErr  = TheUps_.userFloat("mu1_dxyErr");
        mu1_nvsh    = TheUps_.userInt("mu1_nvsh");
        mu1_nvph    = TheUps_.userInt("mu1_nvph");
        mu1_charge  = TheUps_.userInt("mu1_charge");

        mu2_pt      = TheUps_.userFloat("mu2_pt");
        mu2_ptErr   = TheUps_.userFloat("mu2_ptErr");
        mu2_d0      = TheUps_.userFloat("mu2_d0");
        mu2_d0Err   = TheUps_.userFloat("mu2_d0Err");
        mu2_dz      = TheUps_.userFloat("mu2_dz");
        mu2_dzErr   = TheUps_.userFloat("mu2_dzErr");
        mu2_dxy     = TheUps_.userFloat("mu2_dxy");
        mu2_dxyErr  = TheUps_.userFloat("mu2_dxyErr");
        mu2_nvsh    = TheUps_.userInt("mu2_nvsh");
        mu2_nvph    = TheUps_.userInt("mu2_nvph");
        mu2_charge  = TheUps_.userInt("mu2_charge");

        ups_mu1_SQopQop = TheUps_.userFloat("mu1_SQopQop");
        ups_mu1_SQopLam = TheUps_.userFloat("mu1_SQopLam");
        ups_mu1_SQopPhi = TheUps_.userFloat("mu1_SQopPhi");
        ups_mu1_SQopDxy = TheUps_.userFloat("mu1_SQopDxy");
        ups_mu1_SQopDsz = TheUps_.userFloat("mu1_SQopDsz");
        ups_mu1_SLamLam = TheUps_.userFloat("mu1_SLamLam");
        ups_mu1_SLamPhi = TheUps_.userFloat("mu1_SLamPhi");
        ups_mu1_SLamDxy = TheUps_.userFloat("mu1_SLamDxy");
        ups_mu1_SLamDsz = TheUps_.userFloat("mu1_SLamDsz");
        ups_mu1_SPhiPhi = TheUps_.userFloat("mu1_SPhiPhi");
        ups_mu1_SPhiDxy = TheUps_.userFloat("mu1_SPhiDxy");
        ups_mu1_SPhiDsz = TheUps_.userFloat("mu1_SPhiDsz");
        ups_mu1_SDxyDxy = TheUps_.userFloat("mu1_SDxyDxy");
        ups_mu1_SDxyDsz = TheUps_.userFloat("mu1_SDxyDsz");
        ups_mu1_SDszDsz = TheUps_.userFloat("mu1_SDszDsz");

        ups_mu2_SQopQop = TheUps_.userFloat("mu2_SQopQop");
        ups_mu2_SQopLam = TheUps_.userFloat("mu2_SQopLam");
        ups_mu2_SQopPhi = TheUps_.userFloat("mu2_SQopPhi");
        ups_mu2_SQopDxy = TheUps_.userFloat("mu2_SQopDxy");
        ups_mu2_SQopDsz = TheUps_.userFloat("mu2_SQopDsz");
        ups_mu2_SLamLam = TheUps_.userFloat("mu2_SLamLam");
        ups_mu2_SLamPhi = TheUps_.userFloat("mu2_SLamPhi");
        ups_mu2_SLamDxy = TheUps_.userFloat("mu2_SLamDxy");
        ups_mu2_SLamDsz = TheUps_.userFloat("mu2_SLamDsz");
        ups_mu2_SPhiPhi = TheUps_.userFloat("mu2_SPhiPhi");
        ups_mu2_SPhiDxy = TheUps_.userFloat("mu2_SPhiDxy");
        ups_mu2_SPhiDsz = TheUps_.userFloat("mu2_SPhiDsz");
        ups_mu2_SDxyDxy = TheUps_.userFloat("mu2_SDxyDxy");
        ups_mu2_SDxyDsz = TheUps_.userFloat("mu2_SDxyDsz");
        ups_mu2_SDszDsz = TheUps_.userFloat("mu2_SDszDsz");

        ups_mu1_eigenValues = TheUps_.userFloat("mu1_eigenValues");
        ups_mu2_eigenValues = TheUps_.userFloat("mu2_eigenValues");

      } else {
        //testPt1 = TheUps_.userFloat("mu2_pt");
        mu1_pt      = TheUps_.userFloat("mu2_pt");
        mu1_ptErr   = TheUps_.userFloat("mu2_ptErr");
        mu1_d0      = TheUps_.userFloat("mu2_d0");
        mu1_d0Err   = TheUps_.userFloat("mu2_d0Err");
        mu1_dz      = TheUps_.userFloat("mu2_dz");
        mu1_dzErr   = TheUps_.userFloat("mu2_dzErr");
        mu1_dxy     = TheUps_.userFloat("mu2_dxy");
        mu1_dxyErr  = TheUps_.userFloat("mu2_dxyErr");
        mu1_nvsh    = TheUps_.userInt("mu2_nvsh");
        mu1_nvph    = TheUps_.userInt("mu2_nvph");
        mu1_charge  = TheUps_.userInt("mu2_charge");

        mu2_pt      = TheUps_.userFloat("mu1_pt");
        mu2_ptErr   = TheUps_.userFloat("mu1_ptErr");
        mu2_d0      = TheUps_.userFloat("mu1_d0");
        mu2_d0Err   = TheUps_.userFloat("mu1_d0Err");
        mu2_dz      = TheUps_.userFloat("mu1_dz");
        mu2_dzErr   = TheUps_.userFloat("mu1_dzErr");
        mu2_dxy     = TheUps_.userFloat("mu1_dxy");
        mu2_dxyErr  = TheUps_.userFloat("mu1_dxyErr");
        mu2_nvsh    = TheUps_.userInt("mu1_nvsh");
        mu2_nvph    = TheUps_.userInt("mu1_nvph");
        mu2_charge  = TheUps_.userInt("mu1_charge");

        ups_mu1_SQopQop = TheUps_.userFloat("mu2_SQopQop");
        ups_mu1_SQopLam = TheUps_.userFloat("mu2_SQopLam");
        ups_mu1_SQopPhi = TheUps_.userFloat("mu2_SQopPhi");
        ups_mu1_SQopDxy = TheUps_.userFloat("mu2_SQopDxy");
        ups_mu1_SQopDsz = TheUps_.userFloat("mu2_SQopDsz");
        ups_mu1_SLamLam = TheUps_.userFloat("mu2_SLamLam");
        ups_mu1_SLamPhi = TheUps_.userFloat("mu2_SLamPhi");
        ups_mu1_SLamDxy = TheUps_.userFloat("mu2_SLamDxy");
        ups_mu1_SLamDsz = TheUps_.userFloat("mu2_SLamDsz");
        ups_mu1_SPhiPhi = TheUps_.userFloat("mu2_SPhiPhi");
        ups_mu1_SPhiDxy = TheUps_.userFloat("mu2_SPhiDxy");
        ups_mu1_SPhiDsz = TheUps_.userFloat("mu2_SPhiDsz");
        ups_mu1_SDxyDxy = TheUps_.userFloat("mu2_SDxyDxy");
        ups_mu1_SDxyDsz = TheUps_.userFloat("mu2_SDxyDsz");
        ups_mu1_SDszDsz = TheUps_.userFloat("mu2_SDszDsz");

        ups_mu2_SQopQop = TheUps_.userFloat("mu1_SQopQop");
        ups_mu2_SQopLam = TheUps_.userFloat("mu1_SQopLam");
        ups_mu2_SQopPhi = TheUps_.userFloat("mu1_SQopPhi");
        ups_mu2_SQopDxy = TheUps_.userFloat("mu1_SQopDxy");
        ups_mu2_SQopDsz = TheUps_.userFloat("mu1_SQopDsz");
        ups_mu2_SLamLam = TheUps_.userFloat("mu1_SLamLam");
        ups_mu2_SLamPhi = TheUps_.userFloat("mu1_SLamPhi");
        ups_mu2_SLamDxy = TheUps_.userFloat("mu1_SLamDxy");
        ups_mu2_SLamDsz = TheUps_.userFloat("mu1_SLamDsz");
        ups_mu2_SPhiPhi = TheUps_.userFloat("mu1_SPhiPhi");
        ups_mu2_SPhiDxy = TheUps_.userFloat("mu1_SPhiDxy");
        ups_mu2_SPhiDsz = TheUps_.userFloat("mu1_SPhiDsz");
        ups_mu2_SDxyDxy = TheUps_.userFloat("mu1_SDxyDxy");
        ups_mu2_SDxyDsz = TheUps_.userFloat("mu1_SDxyDsz");
        ups_mu2_SDszDsz = TheUps_.userFloat("mu1_SDszDsz");

        ups_mu1_eigenValues = TheUps_.userFloat("mu2_eigenValues");
        ups_mu2_eigenValues = TheUps_.userFloat("mu1_eigenValues");

      }

      //std::cout<<" ===> pt = "<<muonP_p4.Pt()<<" single one = "<<testPt1<<std::endl;

      UpsTree->Fill();
    }
  } else std::cout<< "No Upsilon candidate information " << run << "," << event <<std::endl;



}

void OniaRecoTrackTrackRootupler::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}
DEFINE_FWK_MODULE(OniaRecoTrackTrackRootupler);

#ifndef __OniaPseudoTrackTrackProducer_h_
#define __OniaPseudoTrackTrackProducer_h_

#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/PatCandidates/interface/CompositeCandidate.h"
#include "DataFormats/PatCandidates/interface/Muon.h"
#include "DataFormats/Math/interface/LorentzVector.h"
#include "DataFormats/PatCandidates/interface/PackedCandidate.h"
#include "DataFormats/TrackReco/interface/TrackFwd.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "RecoVertex/KinematicFitPrimitives/interface/RefCountedKinematicParticle.h"
#include "TrackingTools/TransientTrack/interface/TransientTrackBuilder.h"

#include "CommonTools/Utils/interface/PtComparator.h"

#include <vector>
class OniaPseudoTrackTrackProducer : public edm::EDProducer {
	
 public: 
  explicit OniaPseudoTrackTrackProducer(const edm::ParameterSet& ps);
 
 private:

  virtual void produce(edm::Event& event, const edm::EventSetup& esetup) override;
  virtual void endJob();

  const edm::EDGetTokenT<pat::CompositeCandidateCollection> OniaCollection_;
  const edm::EDGetTokenT<pat::PackedCandidateCollection> TrakCollection_;
  std::vector<double> OniaMassCuts_;
  std::vector<double> CandidateMassCuts_;
  const double Track1Mass_;
  const double Track2Mass_;
  const double ConstraintMass_;
  const bool is_dimuon_;

  const bool IsTheSame(const reco::Track& tk, const pat::Muon& mu);
//  const pat::CompositeCandidate makeCandidate(const pat::CompositeCandidate& onia, const reco::Track& track1, const reco::Track& track2);
//  const pat::CompositeCandidate FitVtx(const reco::Track &mu1, const reco::Track &mu2, RefCountedKinematicParticle thePhoton, const reco::Track &tk1, const reco::Track &tk2, const reco::Vertex &thePrimaryV, edm::ESHandle<TransientTrackBuilder> &theB);
  const RefCountedKinematicParticle FitPhoton(const reco::Track &tk0, const reco::Track &tk1, edm::ESHandle<TransientTrackBuilder> &theB);

  int candidates;
  int nevents;
  /*int fpv0;
  int fpv1;
  int fpv2;
  int fpv3;
  int fpv23;*/
  std::vector<reco::Track> pions;
  std::vector<int> pionsPV;
  std::vector<int> refVtx;
  std::vector<int> pvAssocQ;
  std::vector<float> dzAssocPV;
  //std::vector<std::tuple<reco::Track, int>> pions;
  //std::vector<reco::Track> pionp;
  //std::vector<reco::Track> pionm;
  //float dxy,dz;
  std::vector<int> piIndex;
  std::vector<reco::TrackBase::CovarianceMatrix> covMatrix;

  std::vector<float> eigenValues;

  GreaterByPt<reco::Track> PtComparator;

  template<typename T>
  struct GreaterByVProb {
         typedef T first_argument_type;
         typedef T second_argument_type;
         bool operator()( const T & t1, const T & t2 ) const { return t1.userFloat("vProb") > t2.userFloat("vProb"); }
  };
};

#endif

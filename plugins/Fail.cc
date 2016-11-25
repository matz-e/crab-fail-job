// -*- C++ -*-
//
// Package:    Crab/Fail
// Class:      Fail
// 
/**\class Fail Fail.cc Crab/Fail/plugins/Fail.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Matthias Wolf
//         Created:  Fri, 25 Nov 2016 10:06:36 GMT
//
//


// system include files
#include <cstdlib>
#include <iostream>
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
//
// class declaration
//

class Fail : public edm::one::EDAnalyzer<>  {
   public:
      explicit Fail(const edm::ParameterSet&);
      ~Fail();

      static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);


   private:
      virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;

      // ----------member data ---------------------------
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
Fail::Fail(const edm::ParameterSet& iConfig)

{
   //now do what ever initialization is needed
   std::string::size_type sz;
   char* env_id = std::getenv("CRAB_Id");
   char* env_retry = std::getenv("CRAB_Retry");

   if (not env_id or not env_retry) {
      std::cout << "Not all needed CRAB parameters found in the environment!" << std::endl;
   } else {
      int id = std::stoi(env_id);
      int retry = std::stoi(env_retry);

      std::cout << "CRAB Id (Retry): " << id << " (" << retry << ")" << std::endl;
      assert(id != 1 or retry > 3);
   }
}


Fail::~Fail()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
Fail::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
}


// ------------ method called once each job just before starting event loop  ------------
void 
Fail::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
Fail::endJob() 
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
Fail::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(Fail);

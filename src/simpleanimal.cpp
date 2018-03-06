#include "simpleanimal.h"
#include <plog/Log.h>


//' Implementation of constructor
SimpleAnimal::SimpleAnimal(string psindTvdNr){
  LOGD << " *** Constructor called with psindTvdNr: " << psindTvdNr;
  // take argument and run it through verification
  indTvdNr = getVerifiedTvdNr(psindTvdNr);
  LOGD << " *** TVD-Nr was set to: " << indTvdNr;
}


//' Verification function of Tvd-Nr
string SimpleAnimal::getVerifiedTvdNr(string psindTvdNr){
  LOGD << " *** TVD-Nr verification called with psindTvdNr: " << psindTvdNr;
  // check whether first two positions of psindTvdNr are letters
  string countryCode = psindTvdNr.substr(2);
  LOGD << " *** Country code: " << countryCode;

  return(NULL);
}

//' Writing TVD-Nr to cout
void SimpleAnimal::to_out(void){
  std::cout << "Animal object with TVD-Nr: " << indTvdNr << std::endl;
}

//' Writing TVD-Nr to LOGD
void SimpleAnimal::to_logd(void){
  LOGD << "Animal object with TVD-Nr: " << indTvdNr;
}

//' Getter for animals TVD-Nr
string SimpleAnimal::getIndTvdNr(void){
  return(indTvdNr);
}

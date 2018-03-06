#include "constants.h"
#include "simpleanimal.h"
#include <cstring>
#include <iostream>
#include <plog/Log.h>


//' Implementation of constructor
SimpleAnimal::SimpleAnimal(std::string psindTvdNr){
  LOGD << " *** Constructor called with psindTvdNr: " << psindTvdNr;
  // take argument and run it through verification
  indTvdNr = getVerifiedTvdNr(psindTvdNr);
  LOGD << " *** TVD-Nr was set to: " << indTvdNr;
}


//' Verification function of Tvd-Nr
std::string SimpleAnimal::getVerifiedTvdNr(std::string psindTvdNr){
  LOGD << " *** TVD-Nr verification called with psindTvdNr: " << psindTvdNr;
  // check for length of TVD-Nr
  if (psindTvdNr.size() != CONSTANTS::TVD_NR_LENGTH){
    LOGD << " *** Wrong length of TVD-Nr: " << psindTvdNr << " length found: " << psindTvdNr.size() << " should be: " << CONSTANTS::TVD_NR_LENGTH;
    return(CONSTANTS::STRING_NA);
  }

  // check whether first two positions of psindTvdNr are letters
  std::string countryCode = psindTvdNr.substr(0,CONSTANTS::COUNTRY_CODE_LENGTH);
  LOGD << " *** Country code: " << countryCode;
  // countryCode should not be numeric
  if (std::strspn(countryCode.c_str(), CONSTANTS::LETTERS) != CONSTANTS::COUNTRY_CODE_LENGTH){
    LOGD << " *** Country code is not alphabetic: " << countryCode;
    return(CONSTANTS::STRING_NA);
  }

  // check whether second parts is only numeric
  std::string aniMM = psindTvdNr.substr(CONSTANTS::COUNTRY_CODE_LENGTH);
  LOGD << " *** Numeric part of TVD-Nr: " << aniMM;
  // aniMM must be all numbers
  if (std::strspn(aniMM.c_str(), CONSTANTS::NUMBERS) != (CONSTANTS::TVD_NR_LENGTH - CONSTANTS::COUNTRY_CODE_LENGTH)){
    LOGD << " *** Second part of TVD-nr is not numeric: " << aniMM;
    return(CONSTANTS::STRING_NA);
  }

  LOGD << " *** All checks passed for TVD-Nr: " << psindTvdNr;
  return(psindTvdNr);
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
std::string SimpleAnimal::getIndTvdNr(void){
  return(indTvdNr);
}

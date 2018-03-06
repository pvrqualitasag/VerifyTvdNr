//
//
//
//   Implementation of SimpleAnimalMap
//

#include "constants.h"
#include "simpleanimalmap.h"
#include <fstream>
#include <iostream>
#include <Rcpp.h>
#include <plog/Log.h>

using namespace Rcpp;

//' Empty constructor for SimpleAnimalMap object
SimpleAnimalMap::SimpleAnimalMap(void){}


//' Reading data from a file
void SimpleAnimalMap::readTvdNrInput(std::string psinputFile){
  LOGD << " *** Reading TVD-Nr from inputfile: " << psinputFile;
  // create if stream and check whether we can read from it
  std::ifstream datafile(psinputFile.c_str());
  if (!datafile){
    LOGD << " *** Cannot read from file: " << psinputFile;
  }

  // declare local input data and read from file line-by-line
  std::string inputLine;
  unsigned lineNr = 0;
  unsigned aniNr = 0;
  while(std::getline(datafile, inputLine)){
    lineNr++;
    LOGD << " *** ";
    LOGD << " *** Reading input on line: " << lineNr << " : " << inputLine;
    // new simpleanimal record
    SimpleAnimal* curAni = new SimpleAnimal(inputLine);
    // check whether curAni already in map
    std::map<std::string, SimpleAnimal*>::iterator samit = this->find(curAni->getIndTvdNr());
    // if curAni was not found, then insert it
    if (samit == this->end()){
      // animals with Tvd-Nr that is NA are not included in the map
      if (curAni->getIndTvdNr().compare(CONSTANTS::STRING_NA) == 0){
        LOGD << " *** Current animal not inserted because TVD-Nr is NA: " << curAni->getIndTvdNr();
      } else {
        (*this)[curAni->getIndTvdNr()] = curAni;
        aniNr++;
        LOGD << " *** Insert animal with TVD-Nr: " << curAni->getIndTvdNr();
      }
    } else {
      LOGD << " *** Found Animal with TVD-Nr: " << curAni->getIndTvdNr();
    }
    delete curAni;
  }
  // close data file
  datafile.close();

  LOGD << " *** Number of lines read: " << lineNr;
  LOGD << " *** Number of animals inserted: " << aniNr;
  LOGD << " *** Reading TVD-Nr DONE";
}

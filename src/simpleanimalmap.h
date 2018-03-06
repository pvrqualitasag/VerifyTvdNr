//
//
//
//   Header file for class SimpleAnimalMap
//
#include "simpleanimal.h"
#include <map>
#include <Rcpp.h>

using namespace Rcpp;

class SimpleAnimalMap : public std::map<std::string,SimpleAnimal*> {
public:
  // constructor
  SimpleAnimalMap(void);

  // reading data
  void readTvdNrInput(std::string psinputFile);
};

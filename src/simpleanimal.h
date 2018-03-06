#include <Rcpp.h>
using namespace Rcpp;

class SimpleAnimal {
public:
  // constructor for simpleanimal object
  SimpleAnimal(std::string psindTvdNr);
  // verify Tvd-Number
  std::string getVerifiedTvdNr(std::string psindTvdNr);
  // output function
  void to_out(void);
  // write object content to logd
  void to_logd(void);
  // getter for TvdNr
  std::string getIndTvdNr(void);
private:
  std::string indTvdNr;    // TVD-Number of animal
};

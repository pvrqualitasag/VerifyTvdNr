#include <Rcpp.h>
using namespace Rcpp;

using namespace std;

class SimpleAnimal {
public:
  // constructor for simpleanimal object
  SimpleAnimal(string psindTvdNr);
  // verify Tvd-Number
  string getVerifiedTvdNr(string psindTvdNr);
  // output function
  void to_out(void);
  // write object content to logd
  void to_logd(void);
  // getter for TvdNr
  string getIndTvdNr(void);
private:
  string indTvdNr;    // TVD-Number of animal
};

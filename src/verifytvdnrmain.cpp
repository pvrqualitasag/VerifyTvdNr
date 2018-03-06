
#include <iostream>
#include <chrono>
#include <ctime>
#include <Rcpp.h>
#include "simpleanimalmap.h"
#include <plog/Log.h>

using namespace Rcpp;

//' Testing Verification function of TVD-Numbers
//'
//' An object of class simpleanimal is created where
//' the constructor calls a verification function.
//' This should verify that the specified TVD-Nr is
//' valid.
//'
//' @param psinputFile name of an input file name
// [[Rcpp::export]]
void verifyTvdNrMain(std::string psinputFile){
  //Time tracking
  std::chrono::time_point<std::chrono::system_clock> start, end;
  start = std::chrono::system_clock::now();
  time_t start_time = std::chrono::system_clock::to_time_t(start);
  std::cout<<"-----------------------------------------------------------------"<< std::endl;
  std::cout << "START verifyTvdNrMain() at " << std::ctime(&start_time) << std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;

  // logfile init
  plog::init(plog::debug, "verifyTvdNrMain.log");
  LOGD << " *** Starting verifyTvdNrMain ***";
  LOGD << " *** Input file: " << psinputFile;

  // create object of SimpleAnimalMap and read input from psinputFile
  SimpleAnimalMap sam;
  sam.readTvdNrInput(psinputFile);

  LOGD << " *** End of verifyTvdNrMain ***";
  //Time tracking
  end = std::chrono::system_clock::now();
  std::chrono::duration<double> elapsed_seconds = end-start;
  std::time_t end_time = std::chrono::system_clock::to_time_t(end);
  std::cout<<"\n-----------------------------------------------------------------"<< std::endl;
  std::cout << "END Merge_main() at " << std::ctime(&end_time)
            << "elapsed time: " << elapsed_seconds.count() << " s"<<std::endl;
  std::cout<<"-----------------------------------------------------------------"<< std::endl;
}

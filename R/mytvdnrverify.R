###
###
###
###   Purpose:   Calling TVD-Nr verification
###   started:   2018/03/06 (pvr)
###
### ############################################ ###

#' Simple R-interface that calls the TVD-Nr verification
#'
#' Inside of the inst/extdata we have a simple input file
#' containing TVD-Numbers to be verified.
#'
#' @param psinputfile inputfile with TVD-numbers
#' @export mytvdnrverify
mytvdnrverify <- function(psinputfile){
  verifyTvdNrMain(psinputfile)
  return(invisible(TRUE))

}

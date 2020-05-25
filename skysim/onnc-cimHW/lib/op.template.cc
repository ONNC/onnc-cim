//===- ${OperatorName}.cc -------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "${OperatorName}.hh"
#include "diagnostic/msgHandling.hh"
#include <Eigen/Dense>

namespace cimHW {

cimHW${OperatorName}Op::cimHW${OperatorName}Op(
  const std::string &configFile
    ${argument_list}
  )
	: cimHWOp("${OperatorName}")
  , m_cimCU(configFile)
{
  verbose1(opName());  
}

void cimHW${OperatorName}Op::simulate() 
{
  // copy back to output
  //memcpy(m_output_Y, result.data(), sizeof(numType) * ;
  verbose1("\n");
}

} // namespace cimHW
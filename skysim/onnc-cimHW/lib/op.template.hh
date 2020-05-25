//===- ${OperatorName}.hh -------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include "hardware/ComputeUnit.hh"
#include <cimHWOp.hh>

namespace cimHW {

class cimHW${OperatorName}Op : public cimHWOp {
public:
  cimHW${OperatorName}Op(
    const std::string &configFile
    ${argument_list}
  );

  virtual void simulate() final;

private:

  // Use a compute unit
  ComputeUnit               m_cimCU;
};

} // namespace cimHW
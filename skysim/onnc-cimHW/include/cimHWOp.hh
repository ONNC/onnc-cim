//===- cimHWOp.hh ---------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <string>

namespace cimHW {

using element_type        = float;
using const_element_type  = const element_type;
using dim_type            = int32_t;
using const_dim_type      = const dim_type;

class cimHWOp {
public:
  cimHWOp(const std::string &type);
  virtual ~cimHWOp();

  const std::string&  opName() const;
  virtual void        simulate() = 0;

private:
  const std::string   m_opName;
};

} // namespace cimHW
//===- cimHWOp.cc ---------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include <cimHWOp.hh>

namespace cimHW {

cimHWOp::cimHWOp(const std::string &type)
  : m_opName(type)
{

}

cimHWOp::~cimHWOp()
{
}

const std::string&  cimHWOp::opName() const
{
  return m_opName;
}

} // namespace cimHW
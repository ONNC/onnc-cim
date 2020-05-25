//===- cimHWSimulator.cc --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This file is auto-generated, be causion to modify
#include <cimHWSimulator.hh>
#include "factory/createOpFactory.hh"

namespace cimHW {

cimHWSimulator::cimHWSimulator() noexcept
  : m_opFactory(std::move(CreateOpFactory::createFactory()))
{
}

${interpreter_visitors}

} // namespace cimHW
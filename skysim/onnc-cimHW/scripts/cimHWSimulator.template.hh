//===- cimHWSimulator.hh --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This file is auto-generated, be causion to modify
#pragma once
#include <cimHWOp.hh>
#include <abstractOpFactory.hh>
#include <string>
#include <memory>

namespace cimHW {

class cimHWSimulator {
public:
  cimHWSimulator() noexcept;

${interpreter_visitors}

private:
  std::unique_ptr<AbstractOpFactory> m_opFactory;
};

} // namespace cimHW
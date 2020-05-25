//===- abstractOpFactory.hh -----------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This file is auto-generated, be causion to modify
#pragma once
#include <cimHWOp.hh>
#include <memory>

namespace cimHW {
  
class AbstractOpFactory {
public:
  AbstractOpFactory();
  virtual ~AbstractOpFactory();

${interpreter_visitors}

};

} // namespace cimHW

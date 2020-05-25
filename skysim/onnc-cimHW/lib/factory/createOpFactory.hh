//===- createOpFactory.hh -------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <abstractOpFactory.hh>
#include "cimHWOpFactory.hh"
#include <memory>

namespace cimHW {

class CreateOpFactory {
public:
  static std::unique_ptr<AbstractOpFactory> createFactory()
  {
    return std::make_unique<cimHWOpFactory>();
  }
};

} // namespace cimHW
//===- CIMInterpreter.h ---------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include "CIMComputeEngine.h"
#include "Compute/CIMComputeVisitor.h"
#include <onnc/Runtime/Interpreter.h>
#include <onnc/Support/Path.h>

namespace onnc {

template <typename OperatorVisitorT = CIMComputeVisitor>
class CIMInterpreterVisitor : public InterpreterVisitor<OperatorVisitorT>
{
public:
  CIMInterpreterVisitor(std::unique_ptr<ComputeEngine> pEngine)
    : InterpreterVisitor<OperatorVisitorT>(std::move(pEngine))
  {}

  using Base = InterpreterVisitor<OperatorVisitorT>;
};

class CIMInterpreter : public Interpreter
{
public:
  CIMInterpreter(const onnc::Path &configFilePath) noexcept
    : Interpreter(std::make_unique<CIMInterpreterVisitor<>>(
                    std::make_unique<CIMComputeEngine>(configFilePath)
                  )
      )
  {}

  // XXX(a127a127):
  //   Temporary hack, should use something like "Context" or "Environment",
  //   should not expose Interpreter visitor implementation.
  ComputeEngine& getComputeEngine() override
  {
    auto p_IV = static_cast<CIMInterpreterVisitor<>*>(&getVisitor());
    return p_IV->getComputeEngine();
  }
};

} // namespace onnc

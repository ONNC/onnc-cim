//===- X86Interpreter.h ---------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef ONNC_X86_INTERPRETER_H
#define ONNC_X86_INTERPRETER_H
#include "Compute/X86ComputeVisitor.h"
#include "Compute/X86ConvRelu.h"

#include <onnc/Runtime/Interpreter.h>

namespace onnc {

template <typename OperatorVisitorT = X86ComputeVisitor>
class X86InterpreterVisitor : public InterpreterVisitor<OperatorVisitorT>
{
public:
  X86InterpreterVisitor(std::unique_ptr<ComputeEngine> pEngine)
    : InterpreterVisitor<OperatorVisitorT>(std::move(pEngine))
  {}

  using Base = InterpreterVisitor<OperatorVisitorT>;
  void visit(X86ConvRelu& pX86ConvRelu) override
  {
    Base::visit(pX86ConvRelu.m_Conv);
    Base::visit(pX86ConvRelu.m_Relu);
  }
};

class X86Interpreter : public Interpreter
{
public:
  X86Interpreter() noexcept
    : Interpreter(std::make_unique<X86InterpreterVisitor<>>(std::make_unique<BasicComputeEngine>()))
  {}

  // XXX(a127a127):
  //   Temporary hack, should use something like "Context" or "Environment",
  //   should not expose Interpreter visitor implementation.
  ComputeEngine& getComputeEngine() override
  {
    auto p_IV = static_cast<X86InterpreterVisitor<>*>(&getVisitor());
    return p_IV->getComputeEngine();
  }
};

} // namespace onnc

#endif
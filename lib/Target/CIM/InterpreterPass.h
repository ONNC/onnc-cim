//===- InterpreterPass.h --------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <onnc/Core/CustomPass.h>
#include <onnc/IR/Compute/Tensor.h>
#include <onnc/Runtime/Interpreter.h>

#include <functional>

namespace onnc {
class TargetBackend;

namespace cim_internal {

/** \class InterpreterPass
 *  \brief Run interpreter.
 */
class InterpreterPass : public CustomPass<InterpreterPass>
{
public:
  InterpreterPass(TargetBackend *pBackend,
                  std::unique_ptr<char[]> pInputMem,
                  std::function<void(const Tensor&, const void*)> pOutputListener,
                  unsigned int pVerbose);

  ReturnType runOnModule(Module& pModule) override;

private:
  ReturnType runInterpreter(Module& pModule);

  TargetBackend *m_pBackend;
  std::unique_ptr<char[]> m_pInputMem;
  std::function<void(const Tensor&, const void*)> m_OutputListener;
  unsigned int m_Verbose;
  std::unique_ptr<Interpreter> m_pInterpreter;
};

} // namespace of cim
} // namespace of onnc

//===- CIMBackend.h -------------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef TARGET_CIM_CIM_BACKEND_H
#define TARGET_CIM_CIM_BACKEND_H
#include <string>
#include <onnc/Target/TargetBackend.h>

namespace onnc {

class CIMBackend : public TargetBackend
{
public:
  CIMBackend(const TargetOptions& pOptions);

  virtual ~CIMBackend() = default;

  void addTensorSel(PassManager& pPM) override;

  void addOnncIrOptimization(PassManager& pPM, OptimizationOptions& options) override;

  void addTensorSched(PassManager& pPM) override;
  
  void addMemAlloc(PassManager& pPM) override;

  void addCodeEmit(PassManager& pPM, const Path& pOutput) override;

  Interpreter *createTargetInterpreter() const override;

  void RegisterLowers(LowerRegistry& pRegistry) const override;
};

}  // namespace onnc

#endif

//===- CIMComputeVisitor.h ------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <onnc/IR/CustomVisitor.h>

namespace onnc {

/** \class CIMComputeVisitor
 */
class CIMComputeVisitor : public CustomVisitor<CIMComputeVisitor>
{
public:
  CIMComputeVisitor() = default;

  using BaseType::visit;
  static bool classof(const ComputeVisitor* pOp);
};

} // namespace of onnc

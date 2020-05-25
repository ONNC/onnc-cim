//===- CIMComputeVisitor.cpp ----------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "CIMComputeVisitor.h"

using namespace onnc;

bool CIMComputeVisitor::classof(const ComputeVisitor* pOp) {
  if (nullptr == pOp)
    return false;
  return (pOp->getVisitorID() == id());
}

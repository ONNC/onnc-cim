//===- CIMTargetInfo.cpp --------------------------------------------------===//
//
//                             The ONNC Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "CIMTargetInfo.h"
#include <onnc/IR/Quadruple.h>
#include <onnc/Target/TargetRegistry.h>

using namespace onnc;

//===----------------------------------------------------------------------===//
// Non-member functions
//===----------------------------------------------------------------------===//

  
static unsigned int CIMMatchFn(const Quadruple& pQuadruple)
{
  unsigned int score = 0;
  if (Quadruple::cim == pQuadruple.getArch()) {
    score += 10;
  }

  return score;
}


Target& onnc::getTheCIMTarget()
{
  static Target cim_target;
  return cim_target;
}


extern "C" void InitializeCIMONNCPlatform() {
  onnc::TargetRegistry::RegisterTarget(onnc::getTheCIMTarget(), "cim",
                                       "CIM DLA", CIMMatchFn);
}

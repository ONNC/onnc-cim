//===- CrossBarUnit.hh ----------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include "types.hh"
#include "BitlineReceiver.hh"
#include "CrossBarArray.hh"
#include "WordLineDriver.hh"

namespace cimHW {

class CrossBarUnit {
public:
  CrossBarUnit(const unsigned maxWordlines, const std::shared_ptr<nlohmann::json> &errorTable,
               const unsigned xIntegerLen, const unsigned xFractionLen,
               const unsigned wIntegerLen, const unsigned wFractionLen) noexcept;
  
  void                            setCell(const VectorXnum &kernelVector);
  RowVectorXf                     compute(const MatrixXfRowMajor &inputVector, const unsigned OUSize);

private:
  // basic property of a compute unit
  const unsigned                  m_maxWordlines;

  // 3 must component of a xbar
  WordLineDriver                  m_wordlineDriver;
  CrossBarArray                   m_xbarArray;
  BitlineReceiver                 m_bitlineReceiver;
};

} // namespace cimHW

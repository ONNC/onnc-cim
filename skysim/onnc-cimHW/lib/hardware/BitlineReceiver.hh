//===- BitlineReceiver.hh -------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include "types.hh"

namespace cimHW {

class BitlineReceiver {
 public:
  BitlineReceiver(const unsigned featureIntegerLen, const unsigned featureFractionLen,
                  const unsigned filterIntegerLen, const unsigned filterFractionLen) noexcept;

  void                            setOUNums(const unsigned wordlines, const unsigned OUSize);
  void                            addVector(const RowVectorXui &vector);
  numType                         fetchResult() const;
  void                            reset();

private:
  void                            composeFeatureBits();
  numType                         composeFilterBits() const;

private:
  // basic property of a converter
  const unsigned                  m_bitlines;
  const unsigned                  m_featureIntegerLen;
  const unsigned                  m_featureFractionLen;
  const unsigned                  m_filterIntegerLen;
  const unsigned                  m_filterFractionLen;

  // internal counter and buffer
  unsigned                        m_OUNums;
  unsigned                        m_OUNumsIndex;
  RowVectorXui                    m_OUbuffer;
  unsigned                        m_SHCounter;
  RowVectorXf                     m_SHbuffer;
};

} // namespace cimHW

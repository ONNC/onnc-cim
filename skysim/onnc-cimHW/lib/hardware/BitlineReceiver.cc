//===- BitlineReceiver.cc -------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "BitlineReceiver.hh"

namespace cimHW {

BitlineReceiver::BitlineReceiver(const unsigned featureIntegerLen, const unsigned featureFractionLen,
                                 const unsigned filterIntegerLen, const unsigned filterFractionLen) noexcept
 : m_featureIntegerLen(featureIntegerLen)
 , m_featureFractionLen(featureFractionLen)
 , m_filterIntegerLen(filterIntegerLen)
 , m_filterFractionLen(filterFractionLen)
 , m_bitlines(filterIntegerLen + filterFractionLen)
 , m_OUbuffer(filterIntegerLen + filterFractionLen)
 , m_SHbuffer(filterIntegerLen + filterFractionLen)
{
  // initialize
  reset(); 
}

void BitlineReceiver::setOUNums(const unsigned wordlines, const unsigned OUSize)
{
  // once a new size of operation units is set
  // all beffer and counter are reset
  reset();
  // calculate the number of operation required to finish a wordline
  m_OUNums = wordlines / OUSize;
  if(wordlines % OUSize)
    ++m_OUNums;
}

void BitlineReceiver::addVector(const RowVectorXui &vector)
{
  m_OUbuffer += vector;
  if(++m_OUNumsIndex == m_OUNums)
  {
    composeFeatureBits();
    m_OUNumsIndex = 0;
    m_OUbuffer.setZero();
  }
}

numType BitlineReceiver::fetchResult() const
{
  return composeFilterBits();
}

void BitlineReceiver::composeFeatureBits()
{
  auto powfWithNeg = [](int base, int exp) {
    return (exp < 0)? 1.0f/std::pow(base, -exp) : std::pow(base, exp);
  };

  if(m_SHCounter > 0)
    m_SHbuffer += m_OUbuffer.cast<numType>() * powfWithNeg(2, (m_featureIntegerLen - 1 - m_SHCounter));
  else
    m_SHbuffer -= m_OUbuffer.cast<numType>() * powfWithNeg(2, (m_featureIntegerLen - 1));
  ++m_SHCounter;
}

numType BitlineReceiver::composeFilterBits() const
{
  auto powfWithNeg = [](int base, int exp) {
    return (exp < 0)? 1.0f/std::pow(base, -exp) : std::pow(base, exp);
  };

  numType result = 0;
  for(int filterBit = 0; filterBit < m_bitlines; filterBit++)
  {
    if(filterBit > 0)
      result += m_SHbuffer(filterBit) * powfWithNeg(2, (m_filterIntegerLen - 1 - filterBit));
    else
      result -= m_SHbuffer(filterBit) * powfWithNeg(2, (m_filterIntegerLen - 1));  
  }
  return result;
}

void BitlineReceiver::reset()
{
  m_OUNums = 1;

  m_OUNumsIndex = 0;
  m_OUbuffer.setZero();

  m_SHCounter = 0;
  m_SHbuffer.setZero();
}

} // namespace cimHW

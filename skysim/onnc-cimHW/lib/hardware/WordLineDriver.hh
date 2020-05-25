//===- WordLineDriver.hh --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include "types.hh"
#include "CrossBarArray.hh"

namespace cimHW {

class WordLineDriver {
public:
  WordLineDriver(const unsigned maxWordlines, const unsigned integerLen, const unsigned fractionLen) noexcept;

  void                            setInput(const VectorXnum &inputVector, const unsigned OUSize);
  CrossBarArray::WordLineVector   getNextWordLine();
  virtual RowVectorXui            quantize2TwoComplement(const numType x) const;
  void                            reset();

private:
  // basic property of a wordline driver
  const unsigned                  m_maxWordlines;
  const unsigned                  m_integerLen;
  const unsigned                  m_fractionLen;
  const unsigned                  m_nBits;

  // internal cursor              
  unsigned                        m_wordlines;
  unsigned                        m_bitsIndex;
  unsigned                        m_OUSize;
  unsigned                        m_OUIndex;
  MatrixXuiRowMajor               m_buffer;
};

} // namespace cimHW

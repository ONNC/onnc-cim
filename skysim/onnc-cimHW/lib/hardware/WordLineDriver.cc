//===- WordLineDriver.cc --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "WordLineDriver.hh"
#include "../diagnostic/msgHandling.hh"

namespace cimHW {

WordLineDriver::WordLineDriver(const unsigned maxWordlines, const unsigned integerLen, const unsigned fractionLen) noexcept
  : m_maxWordlines(maxWordlines)
  , m_integerLen(integerLen)
  , m_fractionLen(fractionLen)
  , m_nBits(integerLen + fractionLen)
{
  // initialize
  reset();
}

void WordLineDriver::setInput(const VectorXnum &inputVector, const unsigned OUSize)
{
  if(inputVector.size() > m_maxWordlines)
    error("[WordLineDriver] input size exceeds the max of wordlines");

  // allocate new resource
  m_wordlines = inputVector.size();
  m_buffer = MatrixXuiRowMajor(m_wordlines, m_integerLen + m_fractionLen);
  // initialize
  reset();
  // convert to binary expr
  for (int i = 0; i < m_wordlines; i++)
    m_buffer.row(i) = quantize2TwoComplement(inputVector(i));

  // the amount of wordlines a operation unit computes in a cycle
  m_OUSize = OUSize;
}

CrossBarArray::WordLineVector WordLineDriver::getNextWordLine()
{
  // reach the end of buffer
  if(m_bitsIndex >= m_nBits)
    return CrossBarArray::WordLineVector{0, VectorXui(0)};

  // get the size of operation unit
  CrossBarArray::WordLineVector wl;
  auto size = (m_OUIndex + m_OUSize > m_wordlines)?(m_wordlines - m_OUIndex) : m_OUSize;
  wl.vector = m_buffer.block(m_OUIndex, m_bitsIndex, size, 1);
  wl.startLine = m_OUIndex;

  // increment the cursor to next one
  m_OUIndex += size;
  if(m_OUIndex >= m_wordlines)
  {
    m_OUIndex = 0;
    ++m_bitsIndex;
  }
  return wl;
}

RowVectorXui WordLineDriver::quantize2TwoComplement(const numType x) const
{
  // the boundary of 2's complement of given length IL, FL
  float maximum = (1 << (m_integerLen - 1)) - (1 / float(1 << m_fractionLen));
  float minimum = -1 * (1 << (m_integerLen - 1));

  // truncate the number to given IL, FL
  float truncated_x;
  if(x <= minimum)
    truncated_x = minimum;
  else if(x >= maximum)
    truncated_x = maximum;
  else
    truncated_x = x;
  // shift FL part to integer
  unsigned quantized = static_cast<unsigned>(truncated_x * (1 << m_fractionLen));

  // convert to 2's complement
  RowVectorXui binary_expr(m_nBits);
  for (int bit = m_nBits - 1; bit >= 0; bit--)
  {
    binary_expr(bit) = quantized & 0x01;
    quantized >>= 1;
  }
  return binary_expr;
}

void WordLineDriver::reset()
{
  // reset index status
  m_bitsIndex = 0;
  m_OUIndex = 0;
  // clean buffer
  m_buffer.setZero();
}

} // namespace cimHW

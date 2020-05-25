//===- CrossBarArray.cc ---------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "CrossBarArray.hh"
#include "../diagnostic/msgHandling.hh"

namespace cimHW {

CrossBarArray::CrossBarArray(const unsigned maxWordlines, const unsigned integerLen, const unsigned fractionLen, const std::shared_ptr<nlohmann::json> &errorTable) noexcept
  : m_maxWordlines(maxWordlines)
  , m_integerLen(integerLen)
  , m_fractionLen(fractionLen)  
  , m_bitlines(integerLen + fractionLen)
  , m_errorTable(errorTable)
  , gen(rd())
{
}

void CrossBarArray::setCell(const VectorXnum &kernel)
{
  if(kernel.size() > m_maxWordlines)
    error("[CrossBarArray] Kernel size exceeds xbar capacity");

  m_wordlines = kernel.size();
  m_cell = MatrixXuiRowMajor(m_wordlines, m_bitlines);
  for (int i = 0; i < m_wordlines; i++)
    m_cell.row(i) = quantize2TwoComplement(kernel(i));
}

RowVectorXui CrossBarArray::compute(const WordLineVector &wlVector)
{
  if(wlVector.startLine + wlVector.vector.size() > m_wordlines)
    error("[CrossBarArray] input size exceeds active wordlines");

  // get the electrofied wordline for this operation
  m_openWordLine = wlVector.vector.sum();
  // perform CrossBarUnit and insert error element-wise
  return (wlVector.vector.transpose() * m_cell.block(wlVector.startLine, 0, wlVector.vector.size(), m_cell.cols()))
          .unaryExpr(std::bind(&CrossBarArray::errorInsert, this, std::placeholders::_1));
}

RowVectorXui CrossBarArray::quantize2TwoComplement(const numType x)
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
  RowVectorXui binary_expr(m_bitlines);
  for (int bit = m_bitlines - 1; bit >= 0; bit--)
  {
    binary_expr(bit) = quantized & 0x01;
    quantized >>= 1;
  }
  return binary_expr;
}

bitType CrossBarArray::errorInsert(const bitType value)
{
  // look up a pre-defined error table, format of table should be in three dimension
  // [openwordline][value][changed]
  // openwordline: the number of wordlines electrified this time, 1 wordlines electrified maps to index 0
  // value: the actual value should be properly sensed
  // changed: the wrongly sensed value
  if(m_errorTable && m_openWordLine>0)
  {
    std::uniform_int_distribution<> dis(0, 99);
    return (*m_errorTable)[m_openWordLine-1][value][dis(gen)];
  }
  return value;
}

} // namespace cimHW

//===- CrossBarUnit.cc ----------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "CrossBarUnit.hh"

namespace cimHW {

CrossBarUnit::CrossBarUnit(const unsigned maxWordlines, const std::shared_ptr<nlohmann::json> &errorTable,
                   const unsigned xIntegerLen, const unsigned xFractionLen,
                   const unsigned wIntegerLen, const unsigned wFractionLen) noexcept
 : m_maxWordlines(maxWordlines)
 , m_wordlineDriver(maxWordlines, xIntegerLen, xFractionLen)
 , m_xbarArray(maxWordlines, wIntegerLen, wFractionLen, errorTable)
 , m_bitlineReceiver(xIntegerLen, xFractionLen, wIntegerLen, wFractionLen)
{
}

void CrossBarUnit::setCell(const VectorXnum &kernelVector)
{
  m_xbarArray.setCell(kernelVector);
}

RowVectorXf CrossBarUnit::compute(const MatrixXfRowMajor &inputVector, const unsigned OUSize)
{
  RowVectorXf result(inputVector.cols());
  for(int i=0; i<inputVector.cols(); i++)
  {
    m_wordlineDriver.setInput(inputVector.col(i), OUSize);
    m_bitlineReceiver.setOUNums(inputVector.rows(), OUSize);

    unsigned OUIndex = 0;
    auto wl = m_wordlineDriver.getNextWordLine();
    while(wl.vector.size() != 0)
    {
      auto dot = m_xbarArray.compute(wl);
      m_bitlineReceiver.addVector(dot);
      wl = m_wordlineDriver.getNextWordLine();
    }
    result(i) = m_bitlineReceiver.fetchResult();
  }
  return result;
}

} // namespace cimHW
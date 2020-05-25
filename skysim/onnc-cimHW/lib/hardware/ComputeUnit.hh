//===- ComputeUnit.hh -----------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include "types.hh"
#include "CrossBarUnit.hh"
#include <string>
#include <memory>
#include <nlohmann/json.hpp>

namespace cimHW {

class ComputeUnit {
public:
  explicit ComputeUnit(const std::string &configFilePath) noexcept;

  unsigned                                    getMaxWordLine();
  virtual RowVectorXf                         compute(const MatrixXfRowMajor &data, const VectorXnum &kernel);

private:
  // configuration
  std::unique_ptr<nlohmann::json>             m_cimConfig;
  // xbar error table
  std::shared_ptr<nlohmann::json>             m_errorTable;

  // basic property of a compute unit
  unsigned                                    m_xbarNum;
  unsigned                                    m_wordlines;
  unsigned                                    m_bitlines;
  unsigned                                    m_OUSize;
  unsigned                                    m_Verbose;

  // qutization used by quantizer
  unsigned                                    m_xIntegerLen;
  unsigned                                    m_xFractionLen;
  unsigned                                    m_wIntegerLen;
  unsigned                                    m_wFractionLen;

  // xbar unit, only one unit for a operation unit for now
  std::vector<std::unique_ptr<CrossBarUnit>>  m_xBarUnits;
};

} // namespace cimHW
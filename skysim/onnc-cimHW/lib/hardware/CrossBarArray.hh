//===- CrossBarArray.hh ---------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include "types.hh"
#include <memory>
#include <nlohmann/json.hpp>
#include <random>

namespace cimHW {

class CrossBarArray {
public:
  struct WordLineVector {
    unsigned startLine;
    VectorXui vector;
  };

public:
  CrossBarArray(const unsigned maxWordlines, const unsigned integerLen, const unsigned fractionLen, const std::shared_ptr<nlohmann::json> &errorTable) noexcept;

  void                            setCell(const VectorXnum &kernel);
  RowVectorXui                    compute(const WordLineVector &wlVector);
  virtual RowVectorXui            quantize2TwoComplement(const numType x);
  virtual bitType                 errorInsert(const bitType value);

private:
  // basic property of an xbar
  const unsigned                  m_maxWordlines;
  const unsigned                  m_integerLen;
  const unsigned                  m_fractionLen;
  const unsigned                  m_bitlines;
  unsigned                        m_openWordLine;

  // the content of xbar
  unsigned                        m_wordlines;
  MatrixXuiRowMajor               m_cell;

  // error model to be look-up
  std::shared_ptr<nlohmann::json> m_errorTable;
  // random generator used to insert error
  std::random_device              rd;
  std::mt19937                    gen;
};

} // namespace cimHW

//===- gemm.hh ------------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include "hardware/ComputeUnit.hh"
#include <cimHWOp.hh>
#include <vector>

namespace cimHW {

class cimHWGemmOp : public cimHWOp {
public:
  cimHWGemmOp(
    const std::string &configFile,
    const_element_type* input_A_, const_dim_type input_A_ndim_, const_dim_type* input_A_dims_,
    const_element_type* input_B_, const_dim_type input_B_ndim_, const_dim_type* input_B_dims_,
    const_element_type* input_C_, const_dim_type input_C_ndim_, const_dim_type* input_C_dims_,
    element_type* output_Y_, const_dim_type output_Y_ndim_, const_dim_type* output_Y_dims_,
    const_element_type alpha_, const_element_type beta_,
    const_dim_type transA_, const_dim_type transB_);

  virtual void simulate() final;

private:
  const_element_type*       m_input_A;
  const_element_type*       m_input_B;
  const_element_type*       m_input_C;
  element_type*             m_output_Y;
  const_element_type        m_alpha, m_beta;

  dim_type                  m_M;
  dim_type                  m_N;
  dim_type                  m_K;
  MatrixXfRowMajor          m_matrix_A;
  MatrixXfRowMajor          m_matrix_B;

  std::vector<dim_type>     m_C_shape;
  dim_type                  m_C_size;

  // Use a compute unit
  ComputeUnit               m_cimCU;
};

} // namespace cimHW
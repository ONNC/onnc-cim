//===- gemm.cc ------------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "gemm.hh"
#include "diagnostic/msgHandling.hh"
#include <Eigen/Dense>

namespace cimHW {

cimHWGemmOp::cimHWGemmOp(
  const std::string &configFile,
  const_element_type* input_A_, const_dim_type input_A_ndim_, const_dim_type* input_A_dims_,
  const_element_type* input_B_, const_dim_type input_B_ndim_, const_dim_type* input_B_dims_,
  const_element_type* input_C_, const_dim_type input_C_ndim_, const_dim_type* input_C_dims_,
  element_type* output_Y_, const_dim_type output_Y_ndim_, const_dim_type* output_Y_dims_,
  const_element_type alpha_, const_element_type beta_,
  const_dim_type transA_, const_dim_type transB_)
	: cimHWOp("Gemm")
  , m_input_A(input_A_)
  , m_input_B(input_B_)
  , m_input_C(input_C_)
  , m_output_Y(output_Y_)
  , m_alpha(alpha_), m_beta(beta_)
  , m_cimCU(configFile)
{
  verbose1(opName());

  // input data validation check
  if(input_A_ndim_ != 2 || input_B_ndim_ != 2)
    error("Rank of inputs should be 2");

  // handle transition of matrix, finally the matrix should look like...
  // (m_M, m_K) x (m_K, m_N)
  if(!transA_)
  {
    m_M = input_A_dims_[0];
    m_K = input_A_dims_[1];
  }
  else
  {
    m_M = input_A_dims_[1];
    m_K = input_A_dims_[0];
  }
  if(!transB_)
  {
    m_N = input_B_dims_[1];
    if(m_K != input_B_dims_[0])
      error("The dimension of matrics to be gemm should be consistent");
  }
  else
  {
    m_N = input_B_dims_[0];
    if(m_K != input_B_dims_[1])
      error("The dimension of matrics to be gemm should be consistent");
  }
  
  // map to proper view of matrix according to transision
  m_matrix_A = (!transA_)?
              Eigen::Map<const MatrixXfRowMajor>(m_input_A, m_M, m_K).eval() :
              Eigen::Map<const MatrixXfRowMajor>(m_input_A, m_K, m_M).transpose();
  m_matrix_B = (!transB_)?
              Eigen::Map<const MatrixXfRowMajor>(m_input_B, m_K, m_N).eval() :
              Eigen::Map<const MatrixXfRowMajor>(m_input_B, m_N, m_K).transpose();

  // transform C's shape and size
  m_C_shape = std::vector<dim_type>(input_C_dims_, input_C_dims_ + input_C_ndim_);
  m_C_size = std::accumulate(m_C_shape.cbegin(), m_C_shape.cend(), 1, std::multiplies<dim_type>());
}

void cimHWGemmOp::simulate() 
{
  // take matrixA as kernel and matrixB as data to use ComputeUnit
  MatrixXfRowMajor result = MatrixXfRowMajor::Zero(m_M, m_N);
  for(int i=0; i<m_matrix_A.rows(); i++)
    result.row(i) = m_cimCU.compute(m_matrix_B, m_matrix_A.row(i).transpose());

  // multiply alpha
  result *= m_alpha;
  // Broadcast the bias as needed if bias is given
  if (m_beta != 0 && m_input_C != nullptr) {
    MatrixXfRowMajor bias_mat(m_M, m_N);
    if (m_C_size == 1) {
      // C is (), (1,) or (1, 1), set the scalar
      bias_mat.setConstant(*m_input_C);
    } else if (m_C_shape.size() == 1 || m_C_shape[0] == 1) {
      // C is (N,) or (1, N)
      bias_mat.rowwise() = Eigen::Map<const RowVectorXf>(m_input_C, m_N);
    } else if (m_C_shape[1] == 1) {
      // C is (M, 1)
      bias_mat.colwise() = Eigen::Map<const Eigen::VectorXf>(m_input_C, m_M);
    } else {
      // C is (M, N), no broadcast needed.
      bias_mat = Eigen::Map<const MatrixXfRowMajor>(m_input_C, m_M, m_N);
    }
    // multiply apply beta
    result += bias_mat * m_beta;
  }  

  // copy back to output
  memcpy(m_output_Y, result.data(), sizeof(numType) * m_M * m_N);
  verbose1("\n");
}

} // namespace cimHW
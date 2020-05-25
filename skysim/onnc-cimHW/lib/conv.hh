//===- conv.hh ------------------------------------------------------------===//
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

class cimHWConvOp : public cimHWOp {
public:
  cimHWConvOp(
    const std::string &configFilePath,
    const_element_type* input_X_, const_dim_type input_X_ndim_, const_dim_type* input_X_dims_,
    const_element_type* input_W_, const_dim_type input_W_ndim_, const_dim_type* input_W_dims_,
    const_element_type* input_B_, const_dim_type input_B_ndim_, const_dim_type* input_B_dims_,
    element_type* output_Y_, const_dim_type output_Y_ndim_, const_dim_type* output_Y_dims_,
    const char* auto_pad_,
    const_dim_type* dilations_, const_dim_type number_of_dilations_,
    const_dim_type group_,
    const_dim_type* kernel_shape_, const_dim_type number_of_kernel_shape_,
    const_dim_type* pads_, const_dim_type number_of_pads_,
    const_dim_type* strides_, const_dim_type number_of_strides_
  );

  virtual void simulate() final;

private:
  // input tensors
	const_element_type*       m_input_X;
	const_element_type*       m_input_W;
	const_element_type*       m_input_B;
	element_type*             m_output_Y;
  // shape of input tensors
  std::vector<dim_type>     m_input_X_shape;
  std::vector<dim_type>     m_input_W_shape;
  std::vector<dim_type>     m_input_B_shape;
  std::vector<dim_type>     m_output_Y_shape;

  // basic property of conv
  dim_type                  m_NInputs;
  dim_type                  m_Channel;
  dim_type                  m_OutputChannel;

  // inferred shape of from input tensors, below are the attributes regarding to conv
  std::vector<dim_type>     m_image_shape;
  std::vector<dim_type>     m_kernel_shape;
  std::vector<dim_type>     m_output_shape;

  // kernel related properties
  std::vector<dim_type>     m_pads;
  std::vector<dim_type>     m_strides;
  std::vector<dim_type>     m_dilations;
  dim_type                  m_group;

  // Use a compute unit
  ComputeUnit               m_cimCU;
};

} // namespace cimHW
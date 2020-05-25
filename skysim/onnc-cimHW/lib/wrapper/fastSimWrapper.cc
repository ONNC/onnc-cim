//===- fastSimWrapper.cc --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "fastSimWrapper.hh"

namespace cimHW {

fastsimAbsOp::fastsimAbsOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Abs")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimAbsOp::simulate()
{
	m_op.inference();
}

fastsimAcosOp::fastsimAcosOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Acos")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimAcosOp::simulate()
{
	m_op.inference();
}

fastsimAddOp::fastsimAddOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Add")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimAddOp::simulate()
{
	m_op.inference();
}

fastsimAndOp::fastsimAndOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("And")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimAndOp::simulate()
{
	m_op.inference();
}

fastsimArgMaxOp::fastsimArgMaxOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type axis
  ,dim_type keepdims
)
: cimHWOp("ArgMax")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axis
  , keepdims)
{
}

void fastsimArgMaxOp::simulate()
{
	m_op.inference();
}

fastsimArgMinOp::fastsimArgMinOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type axis
  ,dim_type keepdims
)
: cimHWOp("ArgMin")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axis
  , keepdims)
{
}

void fastsimArgMinOp::simulate()
{
	m_op.inference();
}

fastsimAsinOp::fastsimAsinOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Asin")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimAsinOp::simulate()
{
	m_op.inference();
}

fastsimAtanOp::fastsimAtanOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Atan")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimAtanOp::simulate()
{
	m_op.inference();
}

fastsimAveragePoolOp::fastsimAveragePoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,const char* auto_pad
  ,dim_type count_include_pad
  ,dim_type* kernel_shape
  ,const_dim_type number_of_kernel_shape
  ,dim_type* pads
  ,const_dim_type number_of_pads
  ,dim_type* strides
  ,const_dim_type number_of_strides
)
: cimHWOp("AveragePool")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, auto_pad
  , count_include_pad
  , kernel_shape
  , number_of_kernel_shape
  , pads
  , number_of_pads
  , strides
  , number_of_strides)
{
}

void fastsimAveragePoolOp::simulate()
{
	m_op.inference();
}

fastsimBatchNormalizationOp::fastsimBatchNormalizationOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_scale
  ,const_dim_type input_scale_ndim, const_dim_type* input_scale_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,const_element_type* input_mean
  ,const_dim_type input_mean_ndim, const_dim_type* input_mean_dims
  ,const_element_type* input_var
  ,const_dim_type input_var_ndim, const_dim_type* input_var_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type* output_mean
  ,const_dim_type output_mean_ndim, const_dim_type* output_mean_dims
  ,element_type* output_var
  ,const_dim_type output_var_ndim, const_dim_type* output_var_dims
  ,element_type* output_saved_mean
  ,const_dim_type output_saved_mean_ndim, const_dim_type* output_saved_mean_dims
  ,element_type* output_saved_var
  ,const_dim_type output_saved_var_ndim, const_dim_type* output_saved_var_dims
	,element_type epsilon
  ,element_type momentum
  ,dim_type spatial
)
: cimHWOp("BatchNormalization")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_scale
  ,input_scale_ndim, input_scale_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,input_mean
  ,input_mean_ndim, input_mean_dims
  ,input_var
  ,input_var_ndim, input_var_dims,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_mean
  ,output_mean_ndim, output_mean_dims
  ,output_var
  ,output_var_ndim, output_var_dims
  ,output_saved_mean
  ,output_saved_mean_ndim, output_saved_mean_dims
  ,output_saved_var
  ,output_saved_var_ndim, output_saved_var_dims, epsilon
  , momentum
  , spatial)
{
}

void fastsimBatchNormalizationOp::simulate()
{
	m_op.inference();
}

fastsimCastOp::fastsimCastOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type to
)
: cimHWOp("Cast")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, to)
{
}

void fastsimCastOp::simulate()
{
	m_op.inference();
}

fastsimCeilOp::fastsimCeilOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Ceil")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimCeilOp::simulate()
{
	m_op.inference();
}

fastsimClipOp::fastsimClipOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type max
  ,element_type min
)
: cimHWOp("Clip")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, max
  , min)
{
}

void fastsimClipOp::simulate()
{
	m_op.inference();
}

fastsimConcatOp::fastsimConcatOp(
	void* context
	,const_element_type* const* input_inputs
  ,dim_type input_inputs_ntensor
  ,const_dim_type* input_inputs_ndim, const_dim_type* const* input_inputs_dims
	,element_type* output_concat_result
  ,const_dim_type output_concat_result_ndim, const_dim_type* output_concat_result_dims
	,dim_type axis
)
: cimHWOp("Concat")
, m_op(
	input_inputs
  ,input_inputs_ntensor
  ,input_inputs_ndim, input_inputs_dims,output_concat_result
  ,output_concat_result_ndim, output_concat_result_dims, axis)
{
}

void fastsimConcatOp::simulate()
{
	m_op.inference();
}

fastsimConstantOp::fastsimConstantOp(
	void* context
	
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,const void* value
)
: cimHWOp("Constant")
, m_op(
	output_output
  ,output_output_ndim, output_output_dims, value)
{
}

void fastsimConstantOp::simulate()
{
	m_op.inference();
}

fastsimConvOp::fastsimConvOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_W
  ,const_dim_type input_W_ndim, const_dim_type* input_W_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,const char* auto_pad
  ,dim_type* dilations
  ,const_dim_type number_of_dilations
  ,dim_type group
  ,dim_type* kernel_shape
  ,const_dim_type number_of_kernel_shape
  ,dim_type* pads
  ,const_dim_type number_of_pads
  ,dim_type* strides
  ,const_dim_type number_of_strides
)
: cimHWOp("Conv")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_W
  ,input_W_ndim, input_W_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_Y
  ,output_Y_ndim, output_Y_dims, auto_pad
  , dilations
  , number_of_dilations
  , group
  , kernel_shape
  , number_of_kernel_shape
  , pads
  , number_of_pads
  , strides
  , number_of_strides)
{
}

void fastsimConvOp::simulate()
{
	m_op.inference();
}

fastsimConvTransposeOp::fastsimConvTransposeOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_W
  ,const_dim_type input_W_ndim, const_dim_type* input_W_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,const char* auto_pad
  ,dim_type* dilations
  ,const_dim_type number_of_dilations
  ,dim_type group
  ,dim_type* kernel_shape
  ,const_dim_type number_of_kernel_shape
  ,dim_type* output_padding
  ,const_dim_type number_of_output_padding
  ,dim_type* output_shape
  ,const_dim_type number_of_output_shape
  ,dim_type* pads
  ,const_dim_type number_of_pads
  ,dim_type* strides
  ,const_dim_type number_of_strides
)
: cimHWOp("ConvTranspose")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_W
  ,input_W_ndim, input_W_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_Y
  ,output_Y_ndim, output_Y_dims, auto_pad
  , dilations
  , number_of_dilations
  , group
  , kernel_shape
  , number_of_kernel_shape
  , output_padding
  , number_of_output_padding
  , output_shape
  , number_of_output_shape
  , pads
  , number_of_pads
  , strides
  , number_of_strides)
{
}

void fastsimConvTransposeOp::simulate()
{
	m_op.inference();
}

fastsimCosOp::fastsimCosOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Cos")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimCosOp::simulate()
{
	m_op.inference();
}

fastsimDepthToSpaceOp::fastsimDepthToSpaceOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type blocksize
)
: cimHWOp("DepthToSpace")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, blocksize)
{
}

void fastsimDepthToSpaceOp::simulate()
{
	m_op.inference();
}

fastsimDivOp::fastsimDivOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Div")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimDivOp::simulate()
{
	m_op.inference();
}

fastsimDropoutOp::fastsimDropoutOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type* output_mask
  ,const_dim_type output_mask_ndim, const_dim_type* output_mask_dims
	,element_type ratio
)
: cimHWOp("Dropout")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_output
  ,output_output_ndim, output_output_dims
  ,output_mask
  ,output_mask_ndim, output_mask_dims, ratio)
{
}

void fastsimDropoutOp::simulate()
{
	m_op.inference();
}

fastsimEluOp::fastsimEluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
)
: cimHWOp("Elu")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha)
{
}

void fastsimEluOp::simulate()
{
	m_op.inference();
}

fastsimEqualOp::fastsimEqualOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Equal")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimEqualOp::simulate()
{
	m_op.inference();
}

fastsimExpOp::fastsimExpOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Exp")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimExpOp::simulate()
{
	m_op.inference();
}

fastsimExpandOp::fastsimExpandOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Expand")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims
  ,input_shape
  ,input_shape_ndim, input_shape_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimExpandOp::simulate()
{
	m_op.inference();
}

fastsimFlattenOp::fastsimFlattenOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
)
: cimHWOp("Flatten")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, axis)
{
}

void fastsimFlattenOp::simulate()
{
	m_op.inference();
}

fastsimFloorOp::fastsimFloorOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Floor")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimFloorOp::simulate()
{
	m_op.inference();
}

fastsimGRUOp::fastsimGRUOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_W
  ,const_dim_type input_W_ndim, const_dim_type* input_W_dims
  ,const_element_type* input_R
  ,const_dim_type input_R_ndim, const_dim_type* input_R_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,const_element_type* input_sequence_lens
  ,const_dim_type input_sequence_lens_ndim, const_dim_type* input_sequence_lens_dims
  ,const_element_type* input_initial_h
  ,const_dim_type input_initial_h_ndim, const_dim_type* input_initial_h_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type* output_Y_h
  ,const_dim_type output_Y_h_ndim, const_dim_type* output_Y_h_dims
	,element_type* activation_alpha
  ,const_dim_type number_of_activation_alpha
  ,element_type* activation_beta
  ,const_dim_type number_of_activation_beta
  ,const char** activations
  ,const_dim_type number_of_activations
  ,element_type clip
  ,const char* direction
  ,dim_type hidden_size
  ,dim_type linear_before_reset
)
: cimHWOp("GRU")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_W
  ,input_W_ndim, input_W_dims
  ,input_R
  ,input_R_ndim, input_R_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,input_sequence_lens
  ,input_sequence_lens_ndim, input_sequence_lens_dims
  ,input_initial_h
  ,input_initial_h_ndim, input_initial_h_dims,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_Y_h
  ,output_Y_h_ndim, output_Y_h_dims, activation_alpha
  , number_of_activation_alpha
  , activation_beta
  , number_of_activation_beta
  , activations
  , number_of_activations
  , clip
  , direction
  , hidden_size
  , linear_before_reset)
{
}

void fastsimGRUOp::simulate()
{
	m_op.inference();
}

fastsimGatherOp::fastsimGatherOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_indices
  ,const_dim_type input_indices_ndim, const_dim_type* input_indices_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
)
: cimHWOp("Gather")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims
  ,input_indices
  ,input_indices_ndim, input_indices_dims,output_output
  ,output_output_ndim, output_output_dims, axis)
{
}

void fastsimGatherOp::simulate()
{
	m_op.inference();
}

fastsimGemmOp::fastsimGemmOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,const_element_type* input_C
  ,const_dim_type input_C_ndim, const_dim_type* input_C_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type beta
  ,dim_type transA
  ,dim_type transB
)
: cimHWOp("Gemm")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,input_C
  ,input_C_ndim, input_C_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha
  , beta
  , transA
  , transB)
{
}

void fastsimGemmOp::simulate()
{
	m_op.inference();
}

fastsimGlobalAveragePoolOp::fastsimGlobalAveragePoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("GlobalAveragePool")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimGlobalAveragePoolOp::simulate()
{
	m_op.inference();
}

fastsimGlobalLpPoolOp::fastsimGlobalLpPoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,dim_type p
)
: cimHWOp("GlobalLpPool")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, p)
{
}

void fastsimGlobalLpPoolOp::simulate()
{
	m_op.inference();
}

fastsimGlobalMaxPoolOp::fastsimGlobalMaxPoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("GlobalMaxPool")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimGlobalMaxPoolOp::simulate()
{
	m_op.inference();
}

fastsimGreaterOp::fastsimGreaterOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Greater")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimGreaterOp::simulate()
{
	m_op.inference();
}

fastsimHardSigmoidOp::fastsimHardSigmoidOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type beta
)
: cimHWOp("HardSigmoid")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha
  , beta)
{
}

void fastsimHardSigmoidOp::simulate()
{
	m_op.inference();
}

fastsimHardmaxOp::fastsimHardmaxOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
)
: cimHWOp("Hardmax")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, axis)
{
}

void fastsimHardmaxOp::simulate()
{
	m_op.inference();
}

fastsimIdentityOp::fastsimIdentityOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Identity")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimIdentityOp::simulate()
{
	m_op.inference();
}

fastsimInstanceNormalizationOp::fastsimInstanceNormalizationOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_scale
  ,const_dim_type input_scale_ndim, const_dim_type* input_scale_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type epsilon
)
: cimHWOp("InstanceNormalization")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims
  ,input_scale
  ,input_scale_ndim, input_scale_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_output
  ,output_output_ndim, output_output_dims, epsilon)
{
}

void fastsimInstanceNormalizationOp::simulate()
{
	m_op.inference();
}

fastsimLRNOp::fastsimLRNOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type beta
  ,element_type bias
  ,dim_type size
)
: cimHWOp("LRN")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha
  , beta
  , bias
  , size)
{
}

void fastsimLRNOp::simulate()
{
	m_op.inference();
}

fastsimLSTMOp::fastsimLSTMOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_W
  ,const_dim_type input_W_ndim, const_dim_type* input_W_dims
  ,const_element_type* input_R
  ,const_dim_type input_R_ndim, const_dim_type* input_R_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,const_element_type* input_sequence_lens
  ,const_dim_type input_sequence_lens_ndim, const_dim_type* input_sequence_lens_dims
  ,const_element_type* input_initial_h
  ,const_dim_type input_initial_h_ndim, const_dim_type* input_initial_h_dims
  ,const_element_type* input_initial_c
  ,const_dim_type input_initial_c_ndim, const_dim_type* input_initial_c_dims
  ,const_element_type* input_P
  ,const_dim_type input_P_ndim, const_dim_type* input_P_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type* output_Y_h
  ,const_dim_type output_Y_h_ndim, const_dim_type* output_Y_h_dims
  ,element_type* output_Y_c
  ,const_dim_type output_Y_c_ndim, const_dim_type* output_Y_c_dims
	,element_type* activation_alpha
  ,const_dim_type number_of_activation_alpha
  ,element_type* activation_beta
  ,const_dim_type number_of_activation_beta
  ,const char** activations
  ,const_dim_type number_of_activations
  ,element_type clip
  ,const char* direction
  ,dim_type hidden_size
  ,dim_type input_forget
)
: cimHWOp("LSTM")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_W
  ,input_W_ndim, input_W_dims
  ,input_R
  ,input_R_ndim, input_R_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,input_sequence_lens
  ,input_sequence_lens_ndim, input_sequence_lens_dims
  ,input_initial_h
  ,input_initial_h_ndim, input_initial_h_dims
  ,input_initial_c
  ,input_initial_c_ndim, input_initial_c_dims
  ,input_P
  ,input_P_ndim, input_P_dims,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_Y_h
  ,output_Y_h_ndim, output_Y_h_dims
  ,output_Y_c
  ,output_Y_c_ndim, output_Y_c_dims, activation_alpha
  , number_of_activation_alpha
  , activation_beta
  , number_of_activation_beta
  , activations
  , number_of_activations
  , clip
  , direction
  , hidden_size
  , input_forget)
{
}

void fastsimLSTMOp::simulate()
{
	m_op.inference();
}

fastsimLeakyReluOp::fastsimLeakyReluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
)
: cimHWOp("LeakyRelu")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha)
{
}

void fastsimLeakyReluOp::simulate()
{
	m_op.inference();
}

fastsimLessOp::fastsimLessOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Less")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimLessOp::simulate()
{
	m_op.inference();
}

fastsimLogOp::fastsimLogOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Log")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimLogOp::simulate()
{
	m_op.inference();
}

fastsimLogSoftmaxOp::fastsimLogSoftmaxOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
)
: cimHWOp("LogSoftmax")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, axis)
{
}

void fastsimLogSoftmaxOp::simulate()
{
	m_op.inference();
}

fastsimLpNormalizationOp::fastsimLpNormalizationOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
  ,dim_type p
)
: cimHWOp("LpNormalization")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, axis
  , p)
{
}

void fastsimLpNormalizationOp::simulate()
{
	m_op.inference();
}

fastsimLpPoolOp::fastsimLpPoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,const char* auto_pad
  ,dim_type* kernel_shape
  ,const_dim_type number_of_kernel_shape
  ,dim_type p
  ,dim_type* pads
  ,const_dim_type number_of_pads
  ,dim_type* strides
  ,const_dim_type number_of_strides
)
: cimHWOp("LpPool")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, auto_pad
  , kernel_shape
  , number_of_kernel_shape
  , p
  , pads
  , number_of_pads
  , strides
  , number_of_strides)
{
}

void fastsimLpPoolOp::simulate()
{
	m_op.inference();
}

fastsimMatMulOp::fastsimMatMulOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("MatMul")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimMatMulOp::simulate()
{
	m_op.inference();
}

fastsimMaxOp::fastsimMaxOp(
	void* context
	,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
	,element_type* output_max
  ,const_dim_type output_max_ndim, const_dim_type* output_max_dims
	
)
: cimHWOp("Max")
, m_op(
	input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims,output_max
  ,output_max_ndim, output_max_dims)
{
}

void fastsimMaxOp::simulate()
{
	m_op.inference();
}

fastsimMaxPoolOp::fastsimMaxPoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type* output_Indices
  ,const_dim_type output_Indices_ndim, const_dim_type* output_Indices_dims
	,const char* auto_pad
  ,dim_type* kernel_shape
  ,const_dim_type number_of_kernel_shape
  ,dim_type* pads
  ,const_dim_type number_of_pads
  ,dim_type storage_order
  ,dim_type* strides
  ,const_dim_type number_of_strides
)
: cimHWOp("MaxPool")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_Indices
  ,output_Indices_ndim, output_Indices_dims, auto_pad
  , kernel_shape
  , number_of_kernel_shape
  , pads
  , number_of_pads
  , storage_order
  , strides
  , number_of_strides)
{
}

void fastsimMaxPoolOp::simulate()
{
	m_op.inference();
}

fastsimMaxRoiPoolOp::fastsimMaxRoiPoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_rois
  ,const_dim_type input_rois_ndim, const_dim_type* input_rois_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,dim_type* pooled_shape
  ,const_dim_type number_of_pooled_shape
  ,element_type spatial_scale
)
: cimHWOp("MaxRoiPool")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_rois
  ,input_rois_ndim, input_rois_dims,output_Y
  ,output_Y_ndim, output_Y_dims, pooled_shape
  , number_of_pooled_shape
  , spatial_scale)
{
}

void fastsimMaxRoiPoolOp::simulate()
{
	m_op.inference();
}

fastsimMeanOp::fastsimMeanOp(
	void* context
	,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
	,element_type* output_mean
  ,const_dim_type output_mean_ndim, const_dim_type* output_mean_dims
	
)
: cimHWOp("Mean")
, m_op(
	input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims,output_mean
  ,output_mean_ndim, output_mean_dims)
{
}

void fastsimMeanOp::simulate()
{
	m_op.inference();
}

fastsimMinOp::fastsimMinOp(
	void* context
	,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
	,element_type* output_min
  ,const_dim_type output_min_ndim, const_dim_type* output_min_dims
	
)
: cimHWOp("Min")
, m_op(
	input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims,output_min
  ,output_min_ndim, output_min_dims)
{
}

void fastsimMinOp::simulate()
{
	m_op.inference();
}

fastsimMulOp::fastsimMulOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Mul")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimMulOp::simulate()
{
	m_op.inference();
}

fastsimMultinomialOp::fastsimMultinomialOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type dtype
  ,dim_type sample_size
  ,element_type seed
)
: cimHWOp("Multinomial")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, dtype
  , sample_size
  , seed)
{
}

void fastsimMultinomialOp::simulate()
{
	m_op.inference();
}

fastsimNegOp::fastsimNegOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Neg")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimNegOp::simulate()
{
	m_op.inference();
}

fastsimNotOp::fastsimNotOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Not")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimNotOp::simulate()
{
	m_op.inference();
}

fastsimOrOp::fastsimOrOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Or")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimOrOp::simulate()
{
	m_op.inference();
}

fastsimPReluOp::fastsimPReluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_slope
  ,const_dim_type input_slope_ndim, const_dim_type* input_slope_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("PRelu")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_slope
  ,input_slope_ndim, input_slope_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimPReluOp::simulate()
{
	m_op.inference();
}

fastsimPadOp::fastsimPadOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,const char* mode
  ,dim_type* pads
  ,const_dim_type number_of_pads
  ,element_type value
)
: cimHWOp("Pad")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_output
  ,output_output_ndim, output_output_dims, mode
  , pads
  , number_of_pads
  , value)
{
}

void fastsimPadOp::simulate()
{
	m_op.inference();
}

fastsimPowOp::fastsimPowOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_Y
  ,const_dim_type input_Y_ndim, const_dim_type* input_Y_dims
	,element_type* output_Z
  ,const_dim_type output_Z_ndim, const_dim_type* output_Z_dims
	
)
: cimHWOp("Pow")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_Y
  ,input_Y_ndim, input_Y_dims,output_Z
  ,output_Z_ndim, output_Z_dims)
{
}

void fastsimPowOp::simulate()
{
	m_op.inference();
}

fastsimRNNOp::fastsimRNNOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_W
  ,const_dim_type input_W_ndim, const_dim_type* input_W_dims
  ,const_element_type* input_R
  ,const_dim_type input_R_ndim, const_dim_type* input_R_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,const_element_type* input_sequence_lens
  ,const_dim_type input_sequence_lens_ndim, const_dim_type* input_sequence_lens_dims
  ,const_element_type* input_initial_h
  ,const_dim_type input_initial_h_ndim, const_dim_type* input_initial_h_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type* output_Y_h
  ,const_dim_type output_Y_h_ndim, const_dim_type* output_Y_h_dims
	,element_type* activation_alpha
  ,const_dim_type number_of_activation_alpha
  ,element_type* activation_beta
  ,const_dim_type number_of_activation_beta
  ,const char** activations
  ,const_dim_type number_of_activations
  ,element_type clip
  ,const char* direction
  ,dim_type hidden_size
)
: cimHWOp("RNN")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims
  ,input_W
  ,input_W_ndim, input_W_dims
  ,input_R
  ,input_R_ndim, input_R_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,input_sequence_lens
  ,input_sequence_lens_ndim, input_sequence_lens_dims
  ,input_initial_h
  ,input_initial_h_ndim, input_initial_h_dims,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_Y_h
  ,output_Y_h_ndim, output_Y_h_dims, activation_alpha
  , number_of_activation_alpha
  , activation_beta
  , number_of_activation_beta
  , activations
  , number_of_activations
  , clip
  , direction
  , hidden_size)
{
}

void fastsimRNNOp::simulate()
{
	m_op.inference();
}

fastsimRandomNormalOp::fastsimRandomNormalOp(
	void* context
	
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type dtype
  ,element_type mean
  ,element_type scale
  ,element_type seed
  ,dim_type* shape
  ,const_dim_type number_of_shape
)
: cimHWOp("RandomNormal")
, m_op(
	output_output
  ,output_output_ndim, output_output_dims, dtype
  , mean
  , scale
  , seed
  , shape
  , number_of_shape)
{
}

void fastsimRandomNormalOp::simulate()
{
	m_op.inference();
}

fastsimRandomNormalLikeOp::fastsimRandomNormalLikeOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type dtype
  ,element_type mean
  ,element_type scale
  ,element_type seed
)
: cimHWOp("RandomNormalLike")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, dtype
  , mean
  , scale
  , seed)
{
}

void fastsimRandomNormalLikeOp::simulate()
{
	m_op.inference();
}

fastsimRandomUniformOp::fastsimRandomUniformOp(
	void* context
	
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type dtype
  ,element_type high
  ,element_type low
  ,element_type seed
  ,dim_type* shape
  ,const_dim_type number_of_shape
)
: cimHWOp("RandomUniform")
, m_op(
	output_output
  ,output_output_ndim, output_output_dims, dtype
  , high
  , low
  , seed
  , shape
  , number_of_shape)
{
}

void fastsimRandomUniformOp::simulate()
{
	m_op.inference();
}

fastsimRandomUniformLikeOp::fastsimRandomUniformLikeOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type dtype
  ,element_type high
  ,element_type low
  ,element_type seed
)
: cimHWOp("RandomUniformLike")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, dtype
  , high
  , low
  , seed)
{
}

void fastsimRandomUniformLikeOp::simulate()
{
	m_op.inference();
}

fastsimReciprocalOp::fastsimReciprocalOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Reciprocal")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimReciprocalOp::simulate()
{
	m_op.inference();
}

fastsimReduceL1Op::fastsimReduceL1Op(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceL1")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceL1Op::simulate()
{
	m_op.inference();
}

fastsimReduceL2Op::fastsimReduceL2Op(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceL2")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceL2Op::simulate()
{
	m_op.inference();
}

fastsimReduceLogSumOp::fastsimReduceLogSumOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceLogSum")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceLogSumOp::simulate()
{
	m_op.inference();
}

fastsimReduceLogSumExpOp::fastsimReduceLogSumExpOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceLogSumExp")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceLogSumExpOp::simulate()
{
	m_op.inference();
}

fastsimReduceMaxOp::fastsimReduceMaxOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceMax")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceMaxOp::simulate()
{
	m_op.inference();
}

fastsimReduceMeanOp::fastsimReduceMeanOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceMean")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceMeanOp::simulate()
{
	m_op.inference();
}

fastsimReduceMinOp::fastsimReduceMinOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceMin")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceMinOp::simulate()
{
	m_op.inference();
}

fastsimReduceProdOp::fastsimReduceProdOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceProd")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceProdOp::simulate()
{
	m_op.inference();
}

fastsimReduceSumOp::fastsimReduceSumOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceSum")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceSumOp::simulate()
{
	m_op.inference();
}

fastsimReduceSumSquareOp::fastsimReduceSumSquareOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
: cimHWOp("ReduceSumSquare")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_reduced
  ,output_reduced_ndim, output_reduced_dims, axes
  , number_of_axes
  , keepdims)
{
}

void fastsimReduceSumSquareOp::simulate()
{
	m_op.inference();
}

fastsimReluOp::fastsimReluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Relu")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimReluOp::simulate()
{
	m_op.inference();
}

fastsimReshapeOp::fastsimReshapeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
	,element_type* output_reshaped
  ,const_dim_type output_reshaped_ndim, const_dim_type* output_reshaped_dims
	
)
: cimHWOp("Reshape")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims
  ,input_shape
  ,input_shape_ndim, input_shape_dims,output_reshaped
  ,output_reshaped_ndim, output_reshaped_dims)
{
}

void fastsimReshapeOp::simulate()
{
	m_op.inference();
}

fastsimSeluOp::fastsimSeluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type gamma
)
: cimHWOp("Selu")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha
  , gamma)
{
}

void fastsimSeluOp::simulate()
{
	m_op.inference();
}

fastsimShapeOp::fastsimShapeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_shape
  ,const_dim_type output_shape_ndim, const_dim_type* output_shape_dims
	
)
: cimHWOp("Shape")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_shape
  ,output_shape_ndim, output_shape_dims)
{
}

void fastsimShapeOp::simulate()
{
	m_op.inference();
}

fastsimSigmoidOp::fastsimSigmoidOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Sigmoid")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimSigmoidOp::simulate()
{
	m_op.inference();
}

fastsimSinOp::fastsimSinOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Sin")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimSinOp::simulate()
{
	m_op.inference();
}

fastsimSizeOp::fastsimSizeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_size
  ,const_dim_type output_size_ndim, const_dim_type* output_size_dims
	
)
: cimHWOp("Size")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_size
  ,output_size_ndim, output_size_dims)
{
}

void fastsimSizeOp::simulate()
{
	m_op.inference();
}

fastsimSliceOp::fastsimSliceOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type* ends
  ,const_dim_type number_of_ends
  ,dim_type* starts
  ,const_dim_type number_of_starts
)
: cimHWOp("Slice")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_output
  ,output_output_ndim, output_output_dims, axes
  , number_of_axes
  , ends
  , number_of_ends
  , starts
  , number_of_starts)
{
}

void fastsimSliceOp::simulate()
{
	m_op.inference();
}

fastsimSoftmaxOp::fastsimSoftmaxOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
)
: cimHWOp("Softmax")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, axis)
{
}

void fastsimSoftmaxOp::simulate()
{
	m_op.inference();
}

fastsimSoftplusOp::fastsimSoftplusOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Softplus")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimSoftplusOp::simulate()
{
	m_op.inference();
}

fastsimSoftsignOp::fastsimSoftsignOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Softsign")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimSoftsignOp::simulate()
{
	m_op.inference();
}

fastsimSpaceToDepthOp::fastsimSpaceToDepthOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type blocksize
)
: cimHWOp("SpaceToDepth")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, blocksize)
{
}

void fastsimSpaceToDepthOp::simulate()
{
	m_op.inference();
}

fastsimSplitOp::fastsimSplitOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* const* output_outputs
  ,dim_type output_outputs_ntensor
  ,const_dim_type* output_outputs_ndim, const_dim_type* const* output_outputs_dims
	,dim_type axis
  ,dim_type* split
  ,const_dim_type number_of_split
)
: cimHWOp("Split")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_outputs
  ,output_outputs_ntensor
  ,output_outputs_ndim, output_outputs_dims, axis
  , split
  , number_of_split)
{
}

void fastsimSplitOp::simulate()
{
	m_op.inference();
}

fastsimSqrtOp::fastsimSqrtOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
)
: cimHWOp("Sqrt")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims)
{
}

void fastsimSqrtOp::simulate()
{
	m_op.inference();
}

fastsimSqueezeOp::fastsimSqueezeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_squeezed
  ,const_dim_type output_squeezed_ndim, const_dim_type* output_squeezed_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
)
: cimHWOp("Squeeze")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_squeezed
  ,output_squeezed_ndim, output_squeezed_dims, axes
  , number_of_axes)
{
}

void fastsimSqueezeOp::simulate()
{
	m_op.inference();
}

fastsimSubOp::fastsimSubOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Sub")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimSubOp::simulate()
{
	m_op.inference();
}

fastsimSumOp::fastsimSumOp(
	void* context
	,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
	,element_type* output_sum
  ,const_dim_type output_sum_ndim, const_dim_type* output_sum_dims
	
)
: cimHWOp("Sum")
, m_op(
	input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims,output_sum
  ,output_sum_ndim, output_sum_dims)
{
}

void fastsimSumOp::simulate()
{
	m_op.inference();
}

fastsimTanOp::fastsimTanOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Tan")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimTanOp::simulate()
{
	m_op.inference();
}

fastsimTanhOp::fastsimTanhOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Tanh")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimTanhOp::simulate()
{
	m_op.inference();
}

fastsimTileOp::fastsimTileOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_repeats
  ,const_dim_type input_repeats_ndim, const_dim_type* input_repeats_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
)
: cimHWOp("Tile")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims
  ,input_repeats
  ,input_repeats_ndim, input_repeats_dims,output_output
  ,output_output_ndim, output_output_dims)
{
}

void fastsimTileOp::simulate()
{
	m_op.inference();
}

fastsimTopKOp::fastsimTopKOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Values
  ,const_dim_type output_Values_ndim, const_dim_type* output_Values_dims
  ,element_type* output_Indices
  ,const_dim_type output_Indices_ndim, const_dim_type* output_Indices_dims
	,dim_type axis
  ,dim_type k
)
: cimHWOp("TopK")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Values
  ,output_Values_ndim, output_Values_dims
  ,output_Indices
  ,output_Indices_ndim, output_Indices_dims, axis
  , k)
{
}

void fastsimTopKOp::simulate()
{
	m_op.inference();
}

fastsimTransposeOp::fastsimTransposeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_transposed
  ,const_dim_type output_transposed_ndim, const_dim_type* output_transposed_dims
	,dim_type* perm
  ,const_dim_type number_of_perm
)
: cimHWOp("Transpose")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_transposed
  ,output_transposed_ndim, output_transposed_dims, perm
  , number_of_perm)
{
}

void fastsimTransposeOp::simulate()
{
	m_op.inference();
}

fastsimUnsqueezeOp::fastsimUnsqueezeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_expanded
  ,const_dim_type output_expanded_ndim, const_dim_type* output_expanded_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
)
: cimHWOp("Unsqueeze")
, m_op(
	input_data
  ,input_data_ndim, input_data_dims,output_expanded
  ,output_expanded_ndim, output_expanded_dims, axes
  , number_of_axes)
{
}

void fastsimUnsqueezeOp::simulate()
{
	m_op.inference();
}

fastsimUpsampleOp::fastsimUpsampleOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,const char* mode
  ,element_type* scales
  ,const_dim_type number_of_scales
)
: cimHWOp("Upsample")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, mode
  , scales
  , number_of_scales)
{
}

void fastsimUpsampleOp::simulate()
{
	m_op.inference();
}

fastsimXorOp::fastsimXorOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
)
: cimHWOp("Xor")
, m_op(
	input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims,output_C
  ,output_C_ndim, output_C_dims)
{
}

void fastsimXorOp::simulate()
{
	m_op.inference();
}

fastsimATenOp::fastsimATenOp(
	void* context
	,const_element_type* const* input_input
  ,dim_type input_input_ntensor
  ,const_dim_type* input_input_ndim, const_dim_type* const* input_input_dims
	,element_type* const* output_output
  ,dim_type output_output_ntensor
  ,const_dim_type* output_output_ndim, const_dim_type* const* output_output_dims
	
)
: cimHWOp("ATen")
, m_op(
	input_input
  ,input_input_ntensor
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ntensor
  ,output_output_ndim, output_output_dims)
{
}

void fastsimATenOp::simulate()
{
	m_op.inference();
}

fastsimAffineOp::fastsimAffineOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type beta
)
: cimHWOp("Affine")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha
  , beta)
{
}

void fastsimAffineOp::simulate()
{
	m_op.inference();
}

fastsimConstantFillOp::fastsimConstantFillOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type dtype
  ,dim_type* extra_shape
  ,const_dim_type number_of_extra_shape
  ,dim_type input_as_shape
  ,dim_type* shape
  ,const_dim_type number_of_shape
  ,element_type value
)
: cimHWOp("ConstantFill")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, dtype
  , extra_shape
  , number_of_extra_shape
  , input_as_shape
  , shape
  , number_of_shape
  , value)
{
}

void fastsimConstantFillOp::simulate()
{
	m_op.inference();
}

fastsimCropOp::fastsimCropOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type* border
  ,const_dim_type number_of_border
  ,dim_type* scale
  ,const_dim_type number_of_scale
)
: cimHWOp("Crop")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, border
  , number_of_border
  , scale
  , number_of_scale)
{
}

void fastsimCropOp::simulate()
{
	m_op.inference();
}

fastsimGRUUnitOp::fastsimGRUUnitOp(
	void* context
	,const_element_type* input_hidden_prev
  ,const_dim_type input_hidden_prev_ndim, const_dim_type* input_hidden_prev_dims
  ,const_element_type* input_gates
  ,const_dim_type input_gates_ndim, const_dim_type* input_gates_dims
  ,const_element_type* input_seq_lengths
  ,const_dim_type input_seq_lengths_ndim, const_dim_type* input_seq_lengths_dims
  ,const_element_type* input_t
  ,const_dim_type input_t_ndim, const_dim_type* input_t_dims
	,element_type* output_hidden
  ,const_dim_type output_hidden_ndim, const_dim_type* output_hidden_dims
	,dim_type drop_states
)
: cimHWOp("GRUUnit")
, m_op(
	input_hidden_prev
  ,input_hidden_prev_ndim, input_hidden_prev_dims
  ,input_gates
  ,input_gates_ndim, input_gates_dims
  ,input_seq_lengths
  ,input_seq_lengths_ndim, input_seq_lengths_dims
  ,input_t
  ,input_t_ndim, input_t_dims,output_hidden
  ,output_hidden_ndim, output_hidden_dims, drop_states)
{
}

void fastsimGRUUnitOp::simulate()
{
	m_op.inference();
}

fastsimGivenTensorFillOp::fastsimGivenTensorFillOp(
	void* context
	,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
	,element_type* output_X
  ,const_dim_type output_X_ndim, const_dim_type* output_X_dims
	,dim_type* extra_shape
  ,const_dim_type number_of_extra_shape
  ,dim_type input_as_shape
  ,dim_type* shape
  ,const_dim_type number_of_shape
  ,element_type* values
  ,const_dim_type number_of_values
)
: cimHWOp("GivenTensorFill")
, m_op(
	input_shape
  ,input_shape_ndim, input_shape_dims,output_X
  ,output_X_ndim, output_X_dims, extra_shape
  , number_of_extra_shape
  , input_as_shape
  , shape
  , number_of_shape
  , values
  , number_of_values)
{
}

void fastsimGivenTensorFillOp::simulate()
{
	m_op.inference();
}

fastsimImageScalerOp::fastsimImageScalerOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type* bias
  ,const_dim_type number_of_bias
  ,element_type scale
)
: cimHWOp("ImageScaler")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, bias
  , number_of_bias
  , scale)
{
}

void fastsimImageScalerOp::simulate()
{
	m_op.inference();
}

fastsimMeanVarianceNormalizationOp::fastsimMeanVarianceNormalizationOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type across_channels
  ,dim_type normalize_variance
)
: cimHWOp("MeanVarianceNormalization")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, across_channels
  , normalize_variance)
{
}

void fastsimMeanVarianceNormalizationOp::simulate()
{
	m_op.inference();
}

fastsimParametricSoftplusOp::fastsimParametricSoftplusOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type beta
)
: cimHWOp("ParametricSoftplus")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha
  , beta)
{
}

void fastsimParametricSoftplusOp::simulate()
{
	m_op.inference();
}

fastsimScaleOp::fastsimScaleOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type scale
)
: cimHWOp("Scale")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, scale)
{
}

void fastsimScaleOp::simulate()
{
	m_op.inference();
}

fastsimScaledTanhOp::fastsimScaledTanhOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type alpha
  ,element_type beta
)
: cimHWOp("ScaledTanh")
, m_op(
	input_input
  ,input_input_ndim, input_input_dims,output_output
  ,output_output_ndim, output_output_dims, alpha
  , beta)
{
}

void fastsimScaledTanhOp::simulate()
{
	m_op.inference();
}

fastsimThresholdedReluOp::fastsimThresholdedReluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
)
: cimHWOp("ThresholdedRelu")
, m_op(
	input_X
  ,input_X_ndim, input_X_dims,output_Y
  ,output_Y_ndim, output_Y_dims, alpha)
{
}

void fastsimThresholdedReluOp::simulate()
{
	m_op.inference();
}

} // namespace cimHW
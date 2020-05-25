//===- cimHWSimulator.hh --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This file is auto-generated, be causion to modify
#pragma once
#include <cimHWOp.hh>
#include <abstractOpFactory.hh>
#include <string>
#include <memory>

namespace cimHW {

class cimHWSimulator {
public:
  cimHWSimulator() noexcept;

void cimHW_Abs_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Acos_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_Add_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_And_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_ArgMax_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type axis
  ,dim_type keepdims
);

void cimHW_ArgMin_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type axis
  ,dim_type keepdims
);

void cimHW_Asin_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_Atan_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_AveragePool_float(
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
);

void cimHW_BatchNormalization_float(
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
);

void cimHW_Cast_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type to
);

void cimHW_Ceil_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Clip_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type max
  ,element_type min
);

void cimHW_Concat_float(
  void* context
  ,const_element_type* const* input_inputs
  ,dim_type input_inputs_ntensor
  ,const_dim_type* input_inputs_ndim, const_dim_type* const* input_inputs_dims
  ,element_type* output_concat_result
  ,const_dim_type output_concat_result_ndim, const_dim_type* output_concat_result_dims
  ,dim_type axis
);

void cimHW_Constant_float(
  void* context
  
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,const void* value
);

void cimHW_Conv_float(
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
);

void cimHW_ConvTranspose_float(
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
);

void cimHW_Cos_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_DepthToSpace_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type blocksize
);

void cimHW_Div_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_Dropout_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type* output_mask
  ,const_dim_type output_mask_ndim, const_dim_type* output_mask_dims
  ,element_type ratio
);

void cimHW_Elu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
);

void cimHW_Equal_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_Exp_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_Expand_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_Flatten_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

void cimHW_Floor_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_GRU_float(
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
);

void cimHW_Gather_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_indices
  ,const_dim_type input_indices_ndim, const_dim_type* input_indices_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

void cimHW_Gemm_float(
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
);

void cimHW_GlobalAveragePool_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_GlobalLpPool_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,dim_type p
);

void cimHW_GlobalMaxPool_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Greater_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_HardSigmoid_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
);

void cimHW_Hardmax_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

void cimHW_Identity_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_InstanceNormalization_float(
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
);

void cimHW_LRN_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
  ,element_type bias
  ,dim_type size
);

void cimHW_LSTM_float(
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
);

void cimHW_LeakyRelu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
);

void cimHW_Less_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_Log_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_LogSoftmax_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

void cimHW_LpNormalization_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
  ,dim_type p
);

void cimHW_LpPool_float(
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
);

void cimHW_MatMul_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Max_float(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_max
  ,const_dim_type output_max_ndim, const_dim_type* output_max_dims
  
);

void cimHW_MaxPool_float(
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
);

void cimHW_MaxRoiPool_float(
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
);

void cimHW_Mean_float(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_mean
  ,const_dim_type output_mean_ndim, const_dim_type* output_mean_dims
  
);

void cimHW_Min_float(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_min
  ,const_dim_type output_min_ndim, const_dim_type* output_min_dims
  
);

void cimHW_Mul_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_Multinomial_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type dtype
  ,dim_type sample_size
  ,element_type seed
);

void cimHW_Neg_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Not_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Or_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_PRelu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_slope
  ,const_dim_type input_slope_ndim, const_dim_type* input_slope_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Pad_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,const char* mode
  ,dim_type* pads
  ,const_dim_type number_of_pads
  ,element_type value
);

void cimHW_Pow_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_Y
  ,const_dim_type input_Y_ndim, const_dim_type* input_Y_dims
  ,element_type* output_Z
  ,const_dim_type output_Z_ndim, const_dim_type* output_Z_dims
  
);

void cimHW_RNN_float(
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
);

void cimHW_RandomNormal_float(
  void* context
  
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type dtype
  ,element_type mean
  ,element_type scale
  ,element_type seed
  ,dim_type* shape
  ,const_dim_type number_of_shape
);

void cimHW_RandomNormalLike_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type dtype
  ,element_type mean
  ,element_type scale
  ,element_type seed
);

void cimHW_RandomUniform_float(
  void* context
  
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type dtype
  ,element_type high
  ,element_type low
  ,element_type seed
  ,dim_type* shape
  ,const_dim_type number_of_shape
);

void cimHW_RandomUniformLike_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type dtype
  ,element_type high
  ,element_type low
  ,element_type seed
);

void cimHW_Reciprocal_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_ReduceL1_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceL2_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceLogSum_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceLogSumExp_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceMax_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceMean_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceMin_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceProd_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceSum_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_ReduceSumSquare_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

void cimHW_Relu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Reshape_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
  ,element_type* output_reshaped
  ,const_dim_type output_reshaped_ndim, const_dim_type* output_reshaped_dims
  
);

void cimHW_Selu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type gamma
);

void cimHW_Shape_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_shape
  ,const_dim_type output_shape_ndim, const_dim_type* output_shape_dims
  
);

void cimHW_Sigmoid_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Sin_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_Size_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_size
  ,const_dim_type output_size_ndim, const_dim_type* output_size_dims
  
);

void cimHW_Slice_float(
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
);

void cimHW_Softmax_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

void cimHW_Softplus_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Softsign_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_SpaceToDepth_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type blocksize
);

void cimHW_Split_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* const* output_outputs
  ,dim_type output_outputs_ntensor
  ,const_dim_type* output_outputs_ndim, const_dim_type* const* output_outputs_dims
  ,dim_type axis
  ,dim_type* split
  ,const_dim_type number_of_split
);

void cimHW_Sqrt_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

void cimHW_Squeeze_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_squeezed
  ,const_dim_type output_squeezed_ndim, const_dim_type* output_squeezed_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
);

void cimHW_Sub_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_Sum_float(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_sum
  ,const_dim_type output_sum_ndim, const_dim_type* output_sum_dims
  
);

void cimHW_Tan_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_Tanh_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_Tile_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_repeats
  ,const_dim_type input_repeats_ndim, const_dim_type* input_repeats_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

void cimHW_TopK_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Values
  ,const_dim_type output_Values_ndim, const_dim_type* output_Values_dims
  ,element_type* output_Indices
  ,const_dim_type output_Indices_ndim, const_dim_type* output_Indices_dims
  ,dim_type axis
  ,dim_type k
);

void cimHW_Transpose_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_transposed
  ,const_dim_type output_transposed_ndim, const_dim_type* output_transposed_dims
  ,dim_type* perm
  ,const_dim_type number_of_perm
);

void cimHW_Unsqueeze_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_expanded
  ,const_dim_type output_expanded_ndim, const_dim_type* output_expanded_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
);

void cimHW_Upsample_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,const char* mode
  ,element_type* scales
  ,const_dim_type number_of_scales
);

void cimHW_Xor_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

void cimHW_ATen_float(
  void* context
  ,const_element_type* const* input_input
  ,dim_type input_input_ntensor
  ,const_dim_type* input_input_ndim, const_dim_type* const* input_input_dims
  ,element_type* const* output_output
  ,dim_type output_output_ntensor
  ,const_dim_type* output_output_ndim, const_dim_type* const* output_output_dims
  
);

void cimHW_Affine_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
);

void cimHW_ConstantFill_float(
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
);

void cimHW_Crop_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type* border
  ,const_dim_type number_of_border
  ,dim_type* scale
  ,const_dim_type number_of_scale
);

void cimHW_GRUUnit_float(
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
);

void cimHW_GivenTensorFill_float(
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
);

void cimHW_ImageScaler_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type* bias
  ,const_dim_type number_of_bias
  ,element_type scale
);

void cimHW_MeanVarianceNormalization_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type across_channels
  ,dim_type normalize_variance
);

void cimHW_ParametricSoftplus_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
);

void cimHW_Scale_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type scale
);

void cimHW_ScaledTanh_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type alpha
  ,element_type beta
);

void cimHW_ThresholdedRelu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
);

private:
  std::unique_ptr<AbstractOpFactory> m_opFactory;
};

} // namespace cimHW
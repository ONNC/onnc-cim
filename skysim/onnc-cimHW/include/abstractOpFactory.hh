//===- abstractOpFactory.hh -----------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This file is auto-generated, be causion to modify
#pragma once
#include <cimHWOp.hh>
#include <memory>

namespace cimHW {
  
class AbstractOpFactory {
public:
  AbstractOpFactory();
  virtual ~AbstractOpFactory();

virtual std::unique_ptr<cimHWOp> createAbsOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createAcosOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createAddOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createAndOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createArgMaxOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type axis
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createArgMinOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type axis
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createAsinOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createAtanOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createAveragePoolOp(
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

virtual std::unique_ptr<cimHWOp> createBatchNormalizationOp(
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

virtual std::unique_ptr<cimHWOp> createCastOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type to
);

virtual std::unique_ptr<cimHWOp> createCeilOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createClipOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type max
  ,element_type min
);

virtual std::unique_ptr<cimHWOp> createConcatOp(
  void* context
  ,const_element_type* const* input_inputs
  ,dim_type input_inputs_ntensor
  ,const_dim_type* input_inputs_ndim, const_dim_type* const* input_inputs_dims
  ,element_type* output_concat_result
  ,const_dim_type output_concat_result_ndim, const_dim_type* output_concat_result_dims
  ,dim_type axis
);

virtual std::unique_ptr<cimHWOp> createConstantOp(
  void* context
  
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,const void* value
);

virtual std::unique_ptr<cimHWOp> createConvOp(
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

virtual std::unique_ptr<cimHWOp> createConvTransposeOp(
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

virtual std::unique_ptr<cimHWOp> createCosOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createDepthToSpaceOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type blocksize
);

virtual std::unique_ptr<cimHWOp> createDivOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createDropoutOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type* output_mask
  ,const_dim_type output_mask_ndim, const_dim_type* output_mask_dims
  ,element_type ratio
);

virtual std::unique_ptr<cimHWOp> createEluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
);

virtual std::unique_ptr<cimHWOp> createEqualOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createExpOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createExpandOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createFlattenOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

virtual std::unique_ptr<cimHWOp> createFloorOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createGRUOp(
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

virtual std::unique_ptr<cimHWOp> createGatherOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_indices
  ,const_dim_type input_indices_ndim, const_dim_type* input_indices_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

virtual std::unique_ptr<cimHWOp> createGemmOp(
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

virtual std::unique_ptr<cimHWOp> createGlobalAveragePoolOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createGlobalLpPoolOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,dim_type p
);

virtual std::unique_ptr<cimHWOp> createGlobalMaxPoolOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createGreaterOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createHardSigmoidOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
);

virtual std::unique_ptr<cimHWOp> createHardmaxOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

virtual std::unique_ptr<cimHWOp> createIdentityOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createInstanceNormalizationOp(
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

virtual std::unique_ptr<cimHWOp> createLRNOp(
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

virtual std::unique_ptr<cimHWOp> createLSTMOp(
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

virtual std::unique_ptr<cimHWOp> createLeakyReluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
);

virtual std::unique_ptr<cimHWOp> createLessOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createLogOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createLogSoftmaxOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

virtual std::unique_ptr<cimHWOp> createLpNormalizationOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
  ,dim_type p
);

virtual std::unique_ptr<cimHWOp> createLpPoolOp(
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

virtual std::unique_ptr<cimHWOp> createMatMulOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createMaxOp(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_max
  ,const_dim_type output_max_ndim, const_dim_type* output_max_dims
  
);

virtual std::unique_ptr<cimHWOp> createMaxPoolOp(
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

virtual std::unique_ptr<cimHWOp> createMaxRoiPoolOp(
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

virtual std::unique_ptr<cimHWOp> createMeanOp(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_mean
  ,const_dim_type output_mean_ndim, const_dim_type* output_mean_dims
  
);

virtual std::unique_ptr<cimHWOp> createMinOp(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_min
  ,const_dim_type output_min_ndim, const_dim_type* output_min_dims
  
);

virtual std::unique_ptr<cimHWOp> createMulOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createMultinomialOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type dtype
  ,dim_type sample_size
  ,element_type seed
);

virtual std::unique_ptr<cimHWOp> createNegOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createNotOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createOrOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createPReluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_slope
  ,const_dim_type input_slope_ndim, const_dim_type* input_slope_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createPadOp(
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

virtual std::unique_ptr<cimHWOp> createPowOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_Y
  ,const_dim_type input_Y_ndim, const_dim_type* input_Y_dims
  ,element_type* output_Z
  ,const_dim_type output_Z_ndim, const_dim_type* output_Z_dims
  
);

virtual std::unique_ptr<cimHWOp> createRNNOp(
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

virtual std::unique_ptr<cimHWOp> createRandomNormalOp(
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

virtual std::unique_ptr<cimHWOp> createRandomNormalLikeOp(
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

virtual std::unique_ptr<cimHWOp> createRandomUniformOp(
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

virtual std::unique_ptr<cimHWOp> createRandomUniformLikeOp(
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

virtual std::unique_ptr<cimHWOp> createReciprocalOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createReduceL1Op(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceL2Op(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceLogSumOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceLogSumExpOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceMaxOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceMeanOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceMinOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceProdOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceSumOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReduceSumSquareOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual std::unique_ptr<cimHWOp> createReluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createReshapeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
  ,element_type* output_reshaped
  ,const_dim_type output_reshaped_ndim, const_dim_type* output_reshaped_dims
  
);

virtual std::unique_ptr<cimHWOp> createSeluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type gamma
);

virtual std::unique_ptr<cimHWOp> createShapeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_shape
  ,const_dim_type output_shape_ndim, const_dim_type* output_shape_dims
  
);

virtual std::unique_ptr<cimHWOp> createSigmoidOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createSinOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createSizeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_size
  ,const_dim_type output_size_ndim, const_dim_type* output_size_dims
  
);

virtual std::unique_ptr<cimHWOp> createSliceOp(
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

virtual std::unique_ptr<cimHWOp> createSoftmaxOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
);

virtual std::unique_ptr<cimHWOp> createSoftplusOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createSoftsignOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createSpaceToDepthOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type blocksize
);

virtual std::unique_ptr<cimHWOp> createSplitOp(
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

virtual std::unique_ptr<cimHWOp> createSqrtOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);

virtual std::unique_ptr<cimHWOp> createSqueezeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_squeezed
  ,const_dim_type output_squeezed_ndim, const_dim_type* output_squeezed_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
);

virtual std::unique_ptr<cimHWOp> createSubOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createSumOp(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_sum
  ,const_dim_type output_sum_ndim, const_dim_type* output_sum_dims
  
);

virtual std::unique_ptr<cimHWOp> createTanOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createTanhOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createTileOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_repeats
  ,const_dim_type input_repeats_ndim, const_dim_type* input_repeats_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createTopKOp(
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

virtual std::unique_ptr<cimHWOp> createTransposeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_transposed
  ,const_dim_type output_transposed_ndim, const_dim_type* output_transposed_dims
  ,dim_type* perm
  ,const_dim_type number_of_perm
);

virtual std::unique_ptr<cimHWOp> createUnsqueezeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_expanded
  ,const_dim_type output_expanded_ndim, const_dim_type* output_expanded_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
);

virtual std::unique_ptr<cimHWOp> createUpsampleOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,const char* mode
  ,element_type* scales
  ,const_dim_type number_of_scales
);

virtual std::unique_ptr<cimHWOp> createXorOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
);

virtual std::unique_ptr<cimHWOp> createATenOp(
  void* context
  ,const_element_type* const* input_input
  ,dim_type input_input_ntensor
  ,const_dim_type* input_input_ndim, const_dim_type* const* input_input_dims
  ,element_type* const* output_output
  ,dim_type output_output_ntensor
  ,const_dim_type* output_output_ndim, const_dim_type* const* output_output_dims
  
);

virtual std::unique_ptr<cimHWOp> createAffineOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
);

virtual std::unique_ptr<cimHWOp> createConstantFillOp(
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

virtual std::unique_ptr<cimHWOp> createCropOp(
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

virtual std::unique_ptr<cimHWOp> createGRUUnitOp(
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

virtual std::unique_ptr<cimHWOp> createGivenTensorFillOp(
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

virtual std::unique_ptr<cimHWOp> createImageScalerOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type* bias
  ,const_dim_type number_of_bias
  ,element_type scale
);

virtual std::unique_ptr<cimHWOp> createMeanVarianceNormalizationOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type across_channels
  ,dim_type normalize_variance
);

virtual std::unique_ptr<cimHWOp> createParametricSoftplusOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
);

virtual std::unique_ptr<cimHWOp> createScaleOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type scale
);

virtual std::unique_ptr<cimHWOp> createScaledTanhOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type alpha
  ,element_type beta
);

virtual std::unique_ptr<cimHWOp> createThresholdedReluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
);

};

} // namespace cimHW

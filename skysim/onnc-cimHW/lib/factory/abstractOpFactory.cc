//===- abstractOpFactory.cc -----------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This file is auto-generated, be causion to modify
#include <abstractOpFactory.hh>
#include "../wrapper/fastSimWrapper.hh"

namespace cimHW {

AbstractOpFactory::AbstractOpFactory() {}
AbstractOpFactory::~AbstractOpFactory() {}

std::unique_ptr<cimHWOp> AbstractOpFactory::createAbsOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimAbsOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createAcosOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimAcosOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createAddOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimAddOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createAndOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimAndOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createArgMaxOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type axis
  ,dim_type keepdims
)
{
return std::make_unique<fastsimArgMaxOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axis
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createArgMinOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type axis
  ,dim_type keepdims
)
{
return std::make_unique<fastsimArgMinOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axis
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createAsinOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimAsinOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createAtanOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimAtanOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createAveragePoolOp(
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
{
return std::make_unique<fastsimAveragePoolOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , auto_pad
  , count_include_pad
  , kernel_shape
  , number_of_kernel_shape
  , pads
  , number_of_pads
  , strides
  , number_of_strides
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createBatchNormalizationOp(
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
{
return std::make_unique<fastsimBatchNormalizationOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,input_scale
  ,input_scale_ndim, input_scale_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,input_mean
  ,input_mean_ndim, input_mean_dims
  ,input_var
  ,input_var_ndim, input_var_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_mean
  ,output_mean_ndim, output_mean_dims
  ,output_var
  ,output_var_ndim, output_var_dims
  ,output_saved_mean
  ,output_saved_mean_ndim, output_saved_mean_dims
  ,output_saved_var
  ,output_saved_var_ndim, output_saved_var_dims
  , epsilon
  , momentum
  , spatial
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createCastOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type to
)
{
return std::make_unique<fastsimCastOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , to
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createCeilOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimCeilOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createClipOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type max
  ,element_type min
)
{
return std::make_unique<fastsimClipOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , max
  , min
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createConcatOp(
  void* context
  ,const_element_type* const* input_inputs
  ,dim_type input_inputs_ntensor
  ,const_dim_type* input_inputs_ndim, const_dim_type* const* input_inputs_dims
  ,element_type* output_concat_result
  ,const_dim_type output_concat_result_ndim, const_dim_type* output_concat_result_dims
  ,dim_type axis
)
{
return std::make_unique<fastsimConcatOp>(
  context
  ,input_inputs
  ,input_inputs_ntensor
  ,input_inputs_ndim, input_inputs_dims
  ,output_concat_result
  ,output_concat_result_ndim, output_concat_result_dims
  , axis
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createConstantOp(
  void* context
  
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,const void* value
)
{
return std::make_unique<fastsimConstantOp>(
  context
  
  ,output_output
  ,output_output_ndim, output_output_dims
  , value
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createConvOp(
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
{
return std::make_unique<fastsimConvOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,input_W
  ,input_W_ndim, input_W_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , auto_pad
  , dilations
  , number_of_dilations
  , group
  , kernel_shape
  , number_of_kernel_shape
  , pads
  , number_of_pads
  , strides
  , number_of_strides
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createConvTransposeOp(
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
{
return std::make_unique<fastsimConvTransposeOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,input_W
  ,input_W_ndim, input_W_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , auto_pad
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
  , number_of_strides
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createCosOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimCosOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createDepthToSpaceOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type blocksize
)
{
return std::make_unique<fastsimDepthToSpaceOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , blocksize
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createDivOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimDivOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createDropoutOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type* output_mask
  ,const_dim_type output_mask_ndim, const_dim_type* output_mask_dims
  ,element_type ratio
)
{
return std::make_unique<fastsimDropoutOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  ,output_mask
  ,output_mask_ndim, output_mask_dims
  , ratio
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createEluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
)
{
return std::make_unique<fastsimEluOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createEqualOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimEqualOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createExpOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimExpOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createExpandOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimExpandOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,input_shape
  ,input_shape_ndim, input_shape_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createFlattenOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
return std::make_unique<fastsimFlattenOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createFloorOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimFloorOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGRUOp(
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
{
return std::make_unique<fastsimGRUOp>(
  context
  ,input_X
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
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_Y_h
  ,output_Y_h_ndim, output_Y_h_dims
  , activation_alpha
  , number_of_activation_alpha
  , activation_beta
  , number_of_activation_beta
  , activations
  , number_of_activations
  , clip
  , direction
  , hidden_size
  , linear_before_reset
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGatherOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_indices
  ,const_dim_type input_indices_ndim, const_dim_type* input_indices_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
return std::make_unique<fastsimGatherOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,input_indices
  ,input_indices_ndim, input_indices_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGemmOp(
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
{
return std::make_unique<fastsimGemmOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,input_C
  ,input_C_ndim, input_C_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , beta
  , transA
  , transB
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGlobalAveragePoolOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimGlobalAveragePoolOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGlobalLpPoolOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,dim_type p
)
{
return std::make_unique<fastsimGlobalLpPoolOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , p
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGlobalMaxPoolOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimGlobalMaxPoolOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGreaterOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimGreaterOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createHardSigmoidOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
)
{
return std::make_unique<fastsimHardSigmoidOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , beta
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createHardmaxOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
return std::make_unique<fastsimHardmaxOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createIdentityOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimIdentityOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createInstanceNormalizationOp(
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
{
return std::make_unique<fastsimInstanceNormalizationOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,input_scale
  ,input_scale_ndim, input_scale_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , epsilon
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createLRNOp(
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
{
return std::make_unique<fastsimLRNOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , beta
  , bias
  , size
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createLSTMOp(
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
{
return std::make_unique<fastsimLSTMOp>(
  context
  ,input_X
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
  ,input_P_ndim, input_P_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_Y_h
  ,output_Y_h_ndim, output_Y_h_dims
  ,output_Y_c
  ,output_Y_c_ndim, output_Y_c_dims
  , activation_alpha
  , number_of_activation_alpha
  , activation_beta
  , number_of_activation_beta
  , activations
  , number_of_activations
  , clip
  , direction
  , hidden_size
  , input_forget
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createLeakyReluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
)
{
return std::make_unique<fastsimLeakyReluOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createLessOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimLessOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createLogOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimLogOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createLogSoftmaxOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
return std::make_unique<fastsimLogSoftmaxOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createLpNormalizationOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
  ,dim_type p
)
{
return std::make_unique<fastsimLpNormalizationOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
  , p
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createLpPoolOp(
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
{
return std::make_unique<fastsimLpPoolOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , auto_pad
  , kernel_shape
  , number_of_kernel_shape
  , p
  , pads
  , number_of_pads
  , strides
  , number_of_strides
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMatMulOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimMatMulOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMaxOp(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_max
  ,const_dim_type output_max_ndim, const_dim_type* output_max_dims
  
)
{
return std::make_unique<fastsimMaxOp>(
  context
  ,input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims
  ,output_max
  ,output_max_ndim, output_max_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMaxPoolOp(
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
{
return std::make_unique<fastsimMaxPoolOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_Indices
  ,output_Indices_ndim, output_Indices_dims
  , auto_pad
  , kernel_shape
  , number_of_kernel_shape
  , pads
  , number_of_pads
  , storage_order
  , strides
  , number_of_strides
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMaxRoiPoolOp(
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
{
return std::make_unique<fastsimMaxRoiPoolOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,input_rois
  ,input_rois_ndim, input_rois_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , pooled_shape
  , number_of_pooled_shape
  , spatial_scale
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMeanOp(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_mean
  ,const_dim_type output_mean_ndim, const_dim_type* output_mean_dims
  
)
{
return std::make_unique<fastsimMeanOp>(
  context
  ,input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims
  ,output_mean
  ,output_mean_ndim, output_mean_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMinOp(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_min
  ,const_dim_type output_min_ndim, const_dim_type* output_min_dims
  
)
{
return std::make_unique<fastsimMinOp>(
  context
  ,input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims
  ,output_min
  ,output_min_ndim, output_min_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMulOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimMulOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMultinomialOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type dtype
  ,dim_type sample_size
  ,element_type seed
)
{
return std::make_unique<fastsimMultinomialOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , dtype
  , sample_size
  , seed
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createNegOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimNegOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createNotOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimNotOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createOrOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimOrOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createPReluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_slope
  ,const_dim_type input_slope_ndim, const_dim_type* input_slope_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimPReluOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,input_slope
  ,input_slope_ndim, input_slope_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createPadOp(
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
{
return std::make_unique<fastsimPadOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , mode
  , pads
  , number_of_pads
  , value
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createPowOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_Y
  ,const_dim_type input_Y_ndim, const_dim_type* input_Y_dims
  ,element_type* output_Z
  ,const_dim_type output_Z_ndim, const_dim_type* output_Z_dims
  
)
{
return std::make_unique<fastsimPowOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,input_Y
  ,input_Y_ndim, input_Y_dims
  ,output_Z
  ,output_Z_ndim, output_Z_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createRNNOp(
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
{
return std::make_unique<fastsimRNNOp>(
  context
  ,input_X
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
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  ,output_Y_h
  ,output_Y_h_ndim, output_Y_h_dims
  , activation_alpha
  , number_of_activation_alpha
  , activation_beta
  , number_of_activation_beta
  , activations
  , number_of_activations
  , clip
  , direction
  , hidden_size
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createRandomNormalOp(
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
{
return std::make_unique<fastsimRandomNormalOp>(
  context
  
  ,output_output
  ,output_output_ndim, output_output_dims
  , dtype
  , mean
  , scale
  , seed
  , shape
  , number_of_shape
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createRandomNormalLikeOp(
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
{
return std::make_unique<fastsimRandomNormalLikeOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , dtype
  , mean
  , scale
  , seed
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createRandomUniformOp(
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
{
return std::make_unique<fastsimRandomUniformOp>(
  context
  
  ,output_output
  ,output_output_ndim, output_output_dims
  , dtype
  , high
  , low
  , seed
  , shape
  , number_of_shape
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createRandomUniformLikeOp(
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
{
return std::make_unique<fastsimRandomUniformLikeOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , dtype
  , high
  , low
  , seed
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReciprocalOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimReciprocalOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceL1Op(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceL1Op>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceL2Op(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceL2Op>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceLogSumOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceLogSumOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceLogSumExpOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceLogSumExpOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceMaxOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceMaxOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceMeanOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceMeanOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceMinOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceMinOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceProdOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceProdOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceSumOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceSumOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReduceSumSquareOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
)
{
return std::make_unique<fastsimReduceSumSquareOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimReluOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createReshapeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
  ,element_type* output_reshaped
  ,const_dim_type output_reshaped_ndim, const_dim_type* output_reshaped_dims
  
)
{
return std::make_unique<fastsimReshapeOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,input_shape
  ,input_shape_ndim, input_shape_dims
  ,output_reshaped
  ,output_reshaped_ndim, output_reshaped_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSeluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type gamma
)
{
return std::make_unique<fastsimSeluOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , gamma
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createShapeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_shape
  ,const_dim_type output_shape_ndim, const_dim_type* output_shape_dims
  
)
{
return std::make_unique<fastsimShapeOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_shape
  ,output_shape_ndim, output_shape_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSigmoidOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimSigmoidOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSinOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimSinOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSizeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_size
  ,const_dim_type output_size_ndim, const_dim_type* output_size_dims
  
)
{
return std::make_unique<fastsimSizeOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_size
  ,output_size_ndim, output_size_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSliceOp(
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
{
return std::make_unique<fastsimSliceOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axes
  , number_of_axes
  , ends
  , number_of_ends
  , starts
  , number_of_starts
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSoftmaxOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
return std::make_unique<fastsimSoftmaxOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSoftplusOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimSoftplusOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSoftsignOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimSoftsignOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSpaceToDepthOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type blocksize
)
{
return std::make_unique<fastsimSpaceToDepthOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , blocksize
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSplitOp(
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
{
return std::make_unique<fastsimSplitOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_outputs
  ,output_outputs_ntensor
  ,output_outputs_ndim, output_outputs_dims
  , axis
  , split
  , number_of_split
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSqrtOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
return std::make_unique<fastsimSqrtOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSqueezeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_squeezed
  ,const_dim_type output_squeezed_ndim, const_dim_type* output_squeezed_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
)
{
return std::make_unique<fastsimSqueezeOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_squeezed
  ,output_squeezed_ndim, output_squeezed_dims
  , axes
  , number_of_axes
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSubOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimSubOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createSumOp(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_sum
  ,const_dim_type output_sum_ndim, const_dim_type* output_sum_dims
  
)
{
return std::make_unique<fastsimSumOp>(
  context
  ,input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims
  ,output_sum
  ,output_sum_ndim, output_sum_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createTanOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimTanOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createTanhOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimTanhOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createTileOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_repeats
  ,const_dim_type input_repeats_ndim, const_dim_type* input_repeats_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
return std::make_unique<fastsimTileOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,input_repeats
  ,input_repeats_ndim, input_repeats_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createTopKOp(
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
{
return std::make_unique<fastsimTopKOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Values
  ,output_Values_ndim, output_Values_dims
  ,output_Indices
  ,output_Indices_ndim, output_Indices_dims
  , axis
  , k
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createTransposeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_transposed
  ,const_dim_type output_transposed_ndim, const_dim_type* output_transposed_dims
  ,dim_type* perm
  ,const_dim_type number_of_perm
)
{
return std::make_unique<fastsimTransposeOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_transposed
  ,output_transposed_ndim, output_transposed_dims
  , perm
  , number_of_perm
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createUnsqueezeOp(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_expanded
  ,const_dim_type output_expanded_ndim, const_dim_type* output_expanded_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
)
{
return std::make_unique<fastsimUnsqueezeOp>(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_expanded
  ,output_expanded_ndim, output_expanded_dims
  , axes
  , number_of_axes
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createUpsampleOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,const char* mode
  ,element_type* scales
  ,const_dim_type number_of_scales
)
{
return std::make_unique<fastsimUpsampleOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , mode
  , scales
  , number_of_scales
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createXorOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
return std::make_unique<fastsimXorOp>(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createATenOp(
  void* context
  ,const_element_type* const* input_input
  ,dim_type input_input_ntensor
  ,const_dim_type* input_input_ndim, const_dim_type* const* input_input_dims
  ,element_type* const* output_output
  ,dim_type output_output_ntensor
  ,const_dim_type* output_output_ndim, const_dim_type* const* output_output_dims
  
)
{
return std::make_unique<fastsimATenOp>(
  context
  ,input_input
  ,input_input_ntensor
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ntensor
  ,output_output_ndim, output_output_dims
  
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createAffineOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
)
{
return std::make_unique<fastsimAffineOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , beta
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createConstantFillOp(
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
{
return std::make_unique<fastsimConstantFillOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , dtype
  , extra_shape
  , number_of_extra_shape
  , input_as_shape
  , shape
  , number_of_shape
  , value
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createCropOp(
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
{
return std::make_unique<fastsimCropOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , border
  , number_of_border
  , scale
  , number_of_scale
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGRUUnitOp(
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
{
return std::make_unique<fastsimGRUUnitOp>(
  context
  ,input_hidden_prev
  ,input_hidden_prev_ndim, input_hidden_prev_dims
  ,input_gates
  ,input_gates_ndim, input_gates_dims
  ,input_seq_lengths
  ,input_seq_lengths_ndim, input_seq_lengths_dims
  ,input_t
  ,input_t_ndim, input_t_dims
  ,output_hidden
  ,output_hidden_ndim, output_hidden_dims
  , drop_states
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createGivenTensorFillOp(
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
{
return std::make_unique<fastsimGivenTensorFillOp>(
  context
  ,input_shape
  ,input_shape_ndim, input_shape_dims
  ,output_X
  ,output_X_ndim, output_X_dims
  , extra_shape
  , number_of_extra_shape
  , input_as_shape
  , shape
  , number_of_shape
  , values
  , number_of_values
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createImageScalerOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type* bias
  ,const_dim_type number_of_bias
  ,element_type scale
)
{
return std::make_unique<fastsimImageScalerOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , bias
  , number_of_bias
  , scale
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createMeanVarianceNormalizationOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type across_channels
  ,dim_type normalize_variance
)
{
return std::make_unique<fastsimMeanVarianceNormalizationOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , across_channels
  , normalize_variance
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createParametricSoftplusOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
)
{
return std::make_unique<fastsimParametricSoftplusOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , beta
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createScaleOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type scale
)
{
return std::make_unique<fastsimScaleOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , scale
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createScaledTanhOp(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type alpha
  ,element_type beta
)
{
return std::make_unique<fastsimScaledTanhOp>(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , alpha
  , beta
);
}

std::unique_ptr<cimHWOp> AbstractOpFactory::createThresholdedReluOp(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
)
{
return std::make_unique<fastsimThresholdedReluOp>(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
);
}

} // namespace cimHW
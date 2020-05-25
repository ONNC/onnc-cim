//===- cimHWSimulator.cc --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
// This file is auto-generated, be causion to modify
#include <cimHWSimulator.hh>
#include "factory/createOpFactory.hh"

namespace cimHW {

cimHWSimulator::cimHWSimulator() noexcept
  : m_opFactory(std::move(CreateOpFactory::createFactory()))
{
}

void cimHWSimulator::cimHW_Abs_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createAbsOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Acos_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createAcosOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Add_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createAddOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_And_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createAndOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ArgMax_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type axis
  ,dim_type keepdims
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createArgMaxOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axis
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ArgMin_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
  ,dim_type axis
  ,dim_type keepdims
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createArgMinOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axis
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Asin_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createAsinOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Atan_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createAtanOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_AveragePool_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createAveragePoolOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_BatchNormalization_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createBatchNormalizationOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Cast_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type to
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createCastOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , to
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Ceil_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createCeilOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Clip_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type max
  ,element_type min
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createClipOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , max
  , min
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Concat_float(
  void* context
  ,const_element_type* const* input_inputs
  ,dim_type input_inputs_ntensor
  ,const_dim_type* input_inputs_ndim, const_dim_type* const* input_inputs_dims
  ,element_type* output_concat_result
  ,const_dim_type output_concat_result_ndim, const_dim_type* output_concat_result_dims
  ,dim_type axis
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createConcatOp(
  context
  ,input_inputs
  ,input_inputs_ntensor
  ,input_inputs_ndim, input_inputs_dims
  ,output_concat_result
  ,output_concat_result_ndim, output_concat_result_dims
  , axis
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Constant_float(
  void* context
  
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,const void* value
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createConstantOp(
  context
  
  ,output_output
  ,output_output_ndim, output_output_dims
  , value
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Conv_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createConvOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ConvTranspose_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createConvTransposeOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Cos_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createCosOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_DepthToSpace_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type blocksize
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createDepthToSpaceOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , blocksize
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Div_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createDivOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Dropout_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createDropoutOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  ,output_mask
  ,output_mask_ndim, output_mask_dims
  , ratio
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Elu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createEluOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Equal_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createEqualOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Exp_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createExpOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Expand_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createExpandOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,input_shape
  ,input_shape_ndim, input_shape_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Flatten_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createFlattenOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Floor_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createFloorOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_GRU_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createGRUOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Gather_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createGatherOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,input_indices
  ,input_indices_ndim, input_indices_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Gemm_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createGemmOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_GlobalAveragePool_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createGlobalAveragePoolOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_GlobalLpPool_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,dim_type p
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createGlobalLpPoolOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , p
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_GlobalMaxPool_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createGlobalMaxPoolOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Greater_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createGreaterOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_HardSigmoid_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createHardSigmoidOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , beta
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Hardmax_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createHardmaxOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Identity_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createIdentityOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_InstanceNormalization_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createInstanceNormalizationOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_LRN_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createLRNOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_LSTM_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createLSTMOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_LeakyRelu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createLeakyReluOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Less_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createLessOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Log_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createLogOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_LogSoftmax_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createLogSoftmaxOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_LpNormalization_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
  ,dim_type p
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createLpNormalizationOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
  , p
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_LpPool_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createLpPoolOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_MatMul_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createMatMulOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Max_float(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_max
  ,const_dim_type output_max_ndim, const_dim_type* output_max_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createMaxOp(
  context
  ,input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims
  ,output_max
  ,output_max_ndim, output_max_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_MaxPool_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createMaxPoolOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_MaxRoiPool_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createMaxRoiPoolOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Mean_float(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_mean
  ,const_dim_type output_mean_ndim, const_dim_type* output_mean_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createMeanOp(
  context
  ,input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims
  ,output_mean
  ,output_mean_ndim, output_mean_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Min_float(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_min
  ,const_dim_type output_min_ndim, const_dim_type* output_min_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createMinOp(
  context
  ,input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims
  ,output_min
  ,output_min_ndim, output_min_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Mul_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createMulOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Multinomial_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createMultinomialOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , dtype
  , sample_size
  , seed
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Neg_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createNegOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Not_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createNotOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Or_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createOrOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_PRelu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_slope
  ,const_dim_type input_slope_ndim, const_dim_type* input_slope_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createPReluOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,input_slope
  ,input_slope_ndim, input_slope_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Pad_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createPadOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Pow_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_Y
  ,const_dim_type input_Y_ndim, const_dim_type* input_Y_dims
  ,element_type* output_Z
  ,const_dim_type output_Z_ndim, const_dim_type* output_Z_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createPowOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,input_Y
  ,input_Y_ndim, input_Y_dims
  ,output_Z
  ,output_Z_ndim, output_Z_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_RNN_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createRNNOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_RandomNormal_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createRandomNormalOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_RandomNormalLike_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createRandomNormalLikeOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_RandomUniform_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createRandomUniformOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_RandomUniformLike_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createRandomUniformLikeOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Reciprocal_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createReciprocalOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceL1_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceL1Op(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceL2_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceL2Op(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceLogSum_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceLogSumOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceLogSumExp_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceLogSumExpOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceMax_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceMaxOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceMean_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceMeanOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceMin_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceMinOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceProd_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceProdOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceSum_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceSumOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ReduceSumSquare_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createReduceSumSquareOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_reduced
  ,output_reduced_ndim, output_reduced_dims
  , axes
  , number_of_axes
  , keepdims
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Relu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createReluOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Reshape_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
  ,element_type* output_reshaped
  ,const_dim_type output_reshaped_ndim, const_dim_type* output_reshaped_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createReshapeOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,input_shape
  ,input_shape_ndim, input_shape_dims
  ,output_reshaped
  ,output_reshaped_ndim, output_reshaped_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Selu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type gamma
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSeluOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , gamma
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Shape_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_shape
  ,const_dim_type output_shape_ndim, const_dim_type* output_shape_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createShapeOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_shape
  ,output_shape_ndim, output_shape_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Sigmoid_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSigmoidOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Sin_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSinOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Size_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_size
  ,const_dim_type output_size_ndim, const_dim_type* output_size_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSizeOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_size
  ,output_size_ndim, output_size_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Slice_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createSliceOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Softmax_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type axis
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSoftmaxOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , axis
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Softplus_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSoftplusOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Softsign_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSoftsignOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_SpaceToDepth_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type blocksize
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSpaceToDepthOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , blocksize
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Split_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createSplitOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Sqrt_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSqrtOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Squeeze_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_squeezed
  ,const_dim_type output_squeezed_ndim, const_dim_type* output_squeezed_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSqueezeOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_squeezed
  ,output_squeezed_ndim, output_squeezed_dims
  , axes
  , number_of_axes
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Sub_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSubOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Sum_float(
  void* context
  ,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
  ,element_type* output_sum
  ,const_dim_type output_sum_ndim, const_dim_type* output_sum_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createSumOp(
  context
  ,input_data_0
  ,input_data_0_ntensor
  ,input_data_0_ndim, input_data_0_dims
  ,output_sum
  ,output_sum_ndim, output_sum_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Tan_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createTanOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Tanh_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createTanhOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Tile_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_repeats
  ,const_dim_type input_repeats_ndim, const_dim_type* input_repeats_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createTileOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,input_repeats
  ,input_repeats_ndim, input_repeats_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_TopK_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createTopKOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Transpose_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_transposed
  ,const_dim_type output_transposed_ndim, const_dim_type* output_transposed_dims
  ,dim_type* perm
  ,const_dim_type number_of_perm
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createTransposeOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_transposed
  ,output_transposed_ndim, output_transposed_dims
  , perm
  , number_of_perm
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Unsqueeze_float(
  void* context
  ,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,element_type* output_expanded
  ,const_dim_type output_expanded_ndim, const_dim_type* output_expanded_dims
  ,dim_type* axes
  ,const_dim_type number_of_axes
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createUnsqueezeOp(
  context
  ,input_data
  ,input_data_ndim, input_data_dims
  ,output_expanded
  ,output_expanded_ndim, output_expanded_dims
  , axes
  , number_of_axes
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Upsample_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createUpsampleOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , mode
  , scales
  , number_of_scales
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Xor_float(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createXorOp(
  context
  ,input_A
  ,input_A_ndim, input_A_dims
  ,input_B
  ,input_B_ndim, input_B_dims
  ,output_C
  ,output_C_ndim, output_C_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ATen_float(
  void* context
  ,const_element_type* const* input_input
  ,dim_type input_input_ntensor
  ,const_dim_type* input_input_ndim, const_dim_type* const* input_input_dims
  ,element_type* const* output_output
  ,dim_type output_output_ntensor
  ,const_dim_type* output_output_ndim, const_dim_type* const* output_output_dims
  
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createATenOp(
  context
  ,input_input
  ,input_input_ntensor
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ntensor
  ,output_output_ndim, output_output_dims
  
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Affine_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createAffineOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , beta
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ConstantFill_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createConstantFillOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Crop_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createCropOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_GRUUnit_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createGRUUnitOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_GivenTensorFill_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createGivenTensorFillOp(
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
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ImageScaler_float(
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
std::unique_ptr<cimHWOp> op = m_opFactory->createImageScalerOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , bias
  , number_of_bias
  , scale
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_MeanVarianceNormalization_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,dim_type across_channels
  ,dim_type normalize_variance
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createMeanVarianceNormalizationOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , across_channels
  , normalize_variance
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ParametricSoftplus_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
  ,element_type beta
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createParametricSoftplusOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
  , beta
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_Scale_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type scale
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createScaleOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , scale
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ScaledTanh_float(
  void* context
  ,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type alpha
  ,element_type beta
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createScaledTanhOp(
  context
  ,input_input
  ,input_input_ndim, input_input_dims
  ,output_output
  ,output_output_ndim, output_output_dims
  , alpha
  , beta
);
if(op != nullptr)
  op->simulate();
}

void cimHWSimulator::cimHW_ThresholdedRelu_float(
  void* context
  ,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,element_type alpha
)
{
std::unique_ptr<cimHWOp> op = m_opFactory->createThresholdedReluOp(
  context
  ,input_X
  ,input_X_ndim, input_X_dims
  ,output_Y
  ,output_Y_ndim, output_Y_dims
  , alpha
);
if(op != nullptr)
  op->simulate();
}

} // namespace cimHW
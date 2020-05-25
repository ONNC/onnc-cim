//===- fastSimWrapper.hh --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <cimHWOp.hh>
#include <fastsim/operator.hh>

namespace cimHW {

class fastsimAbsOp : public cimHWOp {
public:
fastsimAbsOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
AbsOp m_op;
};

class fastsimAcosOp : public cimHWOp {
public:
fastsimAcosOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
AcosOp m_op;
};

class fastsimAddOp : public cimHWOp {
public:
fastsimAddOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
AddOp m_op;
};

class fastsimAndOp : public cimHWOp {
public:
fastsimAndOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
AndOp m_op;
};

class fastsimArgMaxOp : public cimHWOp {
public:
fastsimArgMaxOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type axis
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ArgMaxOp m_op;
};

class fastsimArgMinOp : public cimHWOp {
public:
fastsimArgMinOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type axis
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ArgMinOp m_op;
};

class fastsimAsinOp : public cimHWOp {
public:
fastsimAsinOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
AsinOp m_op;
};

class fastsimAtanOp : public cimHWOp {
public:
fastsimAtanOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
AtanOp m_op;
};

class fastsimAveragePoolOp : public cimHWOp {
public:
fastsimAveragePoolOp(
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

virtual void simulate() override;

private:
AveragePoolOp m_op;
};

class fastsimBatchNormalizationOp : public cimHWOp {
public:
fastsimBatchNormalizationOp(
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

virtual void simulate() override;

private:
BatchNormalizationOp m_op;
};

class fastsimCastOp : public cimHWOp {
public:
fastsimCastOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type to
);

virtual void simulate() override;

private:
CastOp m_op;
};

class fastsimCeilOp : public cimHWOp {
public:
fastsimCeilOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
CeilOp m_op;
};

class fastsimClipOp : public cimHWOp {
public:
fastsimClipOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type max
  ,element_type min
);

virtual void simulate() override;

private:
ClipOp m_op;
};

class fastsimConcatOp : public cimHWOp {
public:
fastsimConcatOp(
	void* context
	,const_element_type* const* input_inputs
  ,dim_type input_inputs_ntensor
  ,const_dim_type* input_inputs_ndim, const_dim_type* const* input_inputs_dims
	,element_type* output_concat_result
  ,const_dim_type output_concat_result_ndim, const_dim_type* output_concat_result_dims
	,dim_type axis
);

virtual void simulate() override;

private:
ConcatOp m_op;
};

class fastsimConstantOp : public cimHWOp {
public:
fastsimConstantOp(
	void* context
	
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,const void* value
);

virtual void simulate() override;

private:
ConstantOp m_op;
};

class fastsimConvOp : public cimHWOp {
public:
fastsimConvOp(
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

virtual void simulate() override;

private:
ConvOp m_op;
};

class fastsimConvTransposeOp : public cimHWOp {
public:
fastsimConvTransposeOp(
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

virtual void simulate() override;

private:
ConvTransposeOp m_op;
};

class fastsimCosOp : public cimHWOp {
public:
fastsimCosOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
CosOp m_op;
};

class fastsimDepthToSpaceOp : public cimHWOp {
public:
fastsimDepthToSpaceOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type blocksize
);

virtual void simulate() override;

private:
DepthToSpaceOp m_op;
};

class fastsimDivOp : public cimHWOp {
public:
fastsimDivOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
DivOp m_op;
};

class fastsimDropoutOp : public cimHWOp {
public:
fastsimDropoutOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
  ,element_type* output_mask
  ,const_dim_type output_mask_ndim, const_dim_type* output_mask_dims
	,element_type ratio
);

virtual void simulate() override;

private:
DropoutOp m_op;
};

class fastsimEluOp : public cimHWOp {
public:
fastsimEluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
);

virtual void simulate() override;

private:
EluOp m_op;
};

class fastsimEqualOp : public cimHWOp {
public:
fastsimEqualOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
EqualOp m_op;
};

class fastsimExpOp : public cimHWOp {
public:
fastsimExpOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
ExpOp m_op;
};

class fastsimExpandOp : public cimHWOp {
public:
fastsimExpandOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
ExpandOp m_op;
};

class fastsimFlattenOp : public cimHWOp {
public:
fastsimFlattenOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
);

virtual void simulate() override;

private:
FlattenOp m_op;
};

class fastsimFloorOp : public cimHWOp {
public:
fastsimFloorOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
FloorOp m_op;
};

class fastsimGRUOp : public cimHWOp {
public:
fastsimGRUOp(
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

virtual void simulate() override;

private:
GRUOp m_op;
};

class fastsimGatherOp : public cimHWOp {
public:
fastsimGatherOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_indices
  ,const_dim_type input_indices_ndim, const_dim_type* input_indices_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
);

virtual void simulate() override;

private:
GatherOp m_op;
};

class fastsimGemmOp : public cimHWOp {
public:
fastsimGemmOp(
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

virtual void simulate() override;

private:
GemmOp m_op;
};

class fastsimGlobalAveragePoolOp : public cimHWOp {
public:
fastsimGlobalAveragePoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
GlobalAveragePoolOp m_op;
};

class fastsimGlobalLpPoolOp : public cimHWOp {
public:
fastsimGlobalLpPoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,dim_type p
);

virtual void simulate() override;

private:
GlobalLpPoolOp m_op;
};

class fastsimGlobalMaxPoolOp : public cimHWOp {
public:
fastsimGlobalMaxPoolOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
GlobalMaxPoolOp m_op;
};

class fastsimGreaterOp : public cimHWOp {
public:
fastsimGreaterOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
GreaterOp m_op;
};

class fastsimHardSigmoidOp : public cimHWOp {
public:
fastsimHardSigmoidOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type beta
);

virtual void simulate() override;

private:
HardSigmoidOp m_op;
};

class fastsimHardmaxOp : public cimHWOp {
public:
fastsimHardmaxOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
);

virtual void simulate() override;

private:
HardmaxOp m_op;
};

class fastsimIdentityOp : public cimHWOp {
public:
fastsimIdentityOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
IdentityOp m_op;
};

class fastsimInstanceNormalizationOp : public cimHWOp {
public:
fastsimInstanceNormalizationOp(
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

virtual void simulate() override;

private:
InstanceNormalizationOp m_op;
};

class fastsimLRNOp : public cimHWOp {
public:
fastsimLRNOp(
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

virtual void simulate() override;

private:
LRNOp m_op;
};

class fastsimLSTMOp : public cimHWOp {
public:
fastsimLSTMOp(
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

virtual void simulate() override;

private:
LSTMOp m_op;
};

class fastsimLeakyReluOp : public cimHWOp {
public:
fastsimLeakyReluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
);

virtual void simulate() override;

private:
LeakyReluOp m_op;
};

class fastsimLessOp : public cimHWOp {
public:
fastsimLessOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
LessOp m_op;
};

class fastsimLogOp : public cimHWOp {
public:
fastsimLogOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
LogOp m_op;
};

class fastsimLogSoftmaxOp : public cimHWOp {
public:
fastsimLogSoftmaxOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
);

virtual void simulate() override;

private:
LogSoftmaxOp m_op;
};

class fastsimLpNormalizationOp : public cimHWOp {
public:
fastsimLpNormalizationOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
  ,dim_type p
);

virtual void simulate() override;

private:
LpNormalizationOp m_op;
};

class fastsimLpPoolOp : public cimHWOp {
public:
fastsimLpPoolOp(
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

virtual void simulate() override;

private:
LpPoolOp m_op;
};

class fastsimMatMulOp : public cimHWOp {
public:
fastsimMatMulOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
MatMulOp m_op;
};

class fastsimMaxOp : public cimHWOp {
public:
fastsimMaxOp(
	void* context
	,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
	,element_type* output_max
  ,const_dim_type output_max_ndim, const_dim_type* output_max_dims
	
);

virtual void simulate() override;

private:
MaxOp m_op;
};

class fastsimMaxPoolOp : public cimHWOp {
public:
fastsimMaxPoolOp(
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

virtual void simulate() override;

private:
MaxPoolOp m_op;
};

class fastsimMaxRoiPoolOp : public cimHWOp {
public:
fastsimMaxRoiPoolOp(
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

virtual void simulate() override;

private:
MaxRoiPoolOp m_op;
};

class fastsimMeanOp : public cimHWOp {
public:
fastsimMeanOp(
	void* context
	,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
	,element_type* output_mean
  ,const_dim_type output_mean_ndim, const_dim_type* output_mean_dims
	
);

virtual void simulate() override;

private:
MeanOp m_op;
};

class fastsimMinOp : public cimHWOp {
public:
fastsimMinOp(
	void* context
	,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
	,element_type* output_min
  ,const_dim_type output_min_ndim, const_dim_type* output_min_dims
	
);

virtual void simulate() override;

private:
MinOp m_op;
};

class fastsimMulOp : public cimHWOp {
public:
fastsimMulOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
MulOp m_op;
};

class fastsimMultinomialOp : public cimHWOp {
public:
fastsimMultinomialOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type dtype
  ,dim_type sample_size
  ,element_type seed
);

virtual void simulate() override;

private:
MultinomialOp m_op;
};

class fastsimNegOp : public cimHWOp {
public:
fastsimNegOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
NegOp m_op;
};

class fastsimNotOp : public cimHWOp {
public:
fastsimNotOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
NotOp m_op;
};

class fastsimOrOp : public cimHWOp {
public:
fastsimOrOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
OrOp m_op;
};

class fastsimPReluOp : public cimHWOp {
public:
fastsimPReluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_slope
  ,const_dim_type input_slope_ndim, const_dim_type* input_slope_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
PReluOp m_op;
};

class fastsimPadOp : public cimHWOp {
public:
fastsimPadOp(
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

virtual void simulate() override;

private:
PadOp m_op;
};

class fastsimPowOp : public cimHWOp {
public:
fastsimPowOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
  ,const_element_type* input_Y
  ,const_dim_type input_Y_ndim, const_dim_type* input_Y_dims
	,element_type* output_Z
  ,const_dim_type output_Z_ndim, const_dim_type* output_Z_dims
	
);

virtual void simulate() override;

private:
PowOp m_op;
};

class fastsimRNNOp : public cimHWOp {
public:
fastsimRNNOp(
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

virtual void simulate() override;

private:
RNNOp m_op;
};

class fastsimRandomNormalOp : public cimHWOp {
public:
fastsimRandomNormalOp(
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

virtual void simulate() override;

private:
RandomNormalOp m_op;
};

class fastsimRandomNormalLikeOp : public cimHWOp {
public:
fastsimRandomNormalLikeOp(
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

virtual void simulate() override;

private:
RandomNormalLikeOp m_op;
};

class fastsimRandomUniformOp : public cimHWOp {
public:
fastsimRandomUniformOp(
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

virtual void simulate() override;

private:
RandomUniformOp m_op;
};

class fastsimRandomUniformLikeOp : public cimHWOp {
public:
fastsimRandomUniformLikeOp(
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

virtual void simulate() override;

private:
RandomUniformLikeOp m_op;
};

class fastsimReciprocalOp : public cimHWOp {
public:
fastsimReciprocalOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
ReciprocalOp m_op;
};

class fastsimReduceL1Op : public cimHWOp {
public:
fastsimReduceL1Op(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceL1Op m_op;
};

class fastsimReduceL2Op : public cimHWOp {
public:
fastsimReduceL2Op(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceL2Op m_op;
};

class fastsimReduceLogSumOp : public cimHWOp {
public:
fastsimReduceLogSumOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceLogSumOp m_op;
};

class fastsimReduceLogSumExpOp : public cimHWOp {
public:
fastsimReduceLogSumExpOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceLogSumExpOp m_op;
};

class fastsimReduceMaxOp : public cimHWOp {
public:
fastsimReduceMaxOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceMaxOp m_op;
};

class fastsimReduceMeanOp : public cimHWOp {
public:
fastsimReduceMeanOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceMeanOp m_op;
};

class fastsimReduceMinOp : public cimHWOp {
public:
fastsimReduceMinOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceMinOp m_op;
};

class fastsimReduceProdOp : public cimHWOp {
public:
fastsimReduceProdOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceProdOp m_op;
};

class fastsimReduceSumOp : public cimHWOp {
public:
fastsimReduceSumOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceSumOp m_op;
};

class fastsimReduceSumSquareOp : public cimHWOp {
public:
fastsimReduceSumSquareOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_reduced
  ,const_dim_type output_reduced_ndim, const_dim_type* output_reduced_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
  ,dim_type keepdims
);

virtual void simulate() override;

private:
ReduceSumSquareOp m_op;
};

class fastsimReluOp : public cimHWOp {
public:
fastsimReluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
ReluOp m_op;
};

class fastsimReshapeOp : public cimHWOp {
public:
fastsimReshapeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
  ,const_element_type* input_shape
  ,const_dim_type input_shape_ndim, const_dim_type* input_shape_dims
	,element_type* output_reshaped
  ,const_dim_type output_reshaped_ndim, const_dim_type* output_reshaped_dims
	
);

virtual void simulate() override;

private:
ReshapeOp m_op;
};

class fastsimSeluOp : public cimHWOp {
public:
fastsimSeluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type gamma
);

virtual void simulate() override;

private:
SeluOp m_op;
};

class fastsimShapeOp : public cimHWOp {
public:
fastsimShapeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_shape
  ,const_dim_type output_shape_ndim, const_dim_type* output_shape_dims
	
);

virtual void simulate() override;

private:
ShapeOp m_op;
};

class fastsimSigmoidOp : public cimHWOp {
public:
fastsimSigmoidOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
SigmoidOp m_op;
};

class fastsimSinOp : public cimHWOp {
public:
fastsimSinOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
SinOp m_op;
};

class fastsimSizeOp : public cimHWOp {
public:
fastsimSizeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_size
  ,const_dim_type output_size_ndim, const_dim_type* output_size_dims
	
);

virtual void simulate() override;

private:
SizeOp m_op;
};

class fastsimSliceOp : public cimHWOp {
public:
fastsimSliceOp(
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

virtual void simulate() override;

private:
SliceOp m_op;
};

class fastsimSoftmaxOp : public cimHWOp {
public:
fastsimSoftmaxOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type axis
);

virtual void simulate() override;

private:
SoftmaxOp m_op;
};

class fastsimSoftplusOp : public cimHWOp {
public:
fastsimSoftplusOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
SoftplusOp m_op;
};

class fastsimSoftsignOp : public cimHWOp {
public:
fastsimSoftsignOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
SoftsignOp m_op;
};

class fastsimSpaceToDepthOp : public cimHWOp {
public:
fastsimSpaceToDepthOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type blocksize
);

virtual void simulate() override;

private:
SpaceToDepthOp m_op;
};

class fastsimSplitOp : public cimHWOp {
public:
fastsimSplitOp(
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

virtual void simulate() override;

private:
SplitOp m_op;
};

class fastsimSqrtOp : public cimHWOp {
public:
fastsimSqrtOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	
);

virtual void simulate() override;

private:
SqrtOp m_op;
};

class fastsimSqueezeOp : public cimHWOp {
public:
fastsimSqueezeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_squeezed
  ,const_dim_type output_squeezed_ndim, const_dim_type* output_squeezed_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
);

virtual void simulate() override;

private:
SqueezeOp m_op;
};

class fastsimSubOp : public cimHWOp {
public:
fastsimSubOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
SubOp m_op;
};

class fastsimSumOp : public cimHWOp {
public:
fastsimSumOp(
	void* context
	,const_element_type* const* input_data_0
  ,dim_type input_data_0_ntensor
  ,const_dim_type* input_data_0_ndim, const_dim_type* const* input_data_0_dims
	,element_type* output_sum
  ,const_dim_type output_sum_ndim, const_dim_type* output_sum_dims
	
);

virtual void simulate() override;

private:
SumOp m_op;
};

class fastsimTanOp : public cimHWOp {
public:
fastsimTanOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
TanOp m_op;
};

class fastsimTanhOp : public cimHWOp {
public:
fastsimTanhOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
TanhOp m_op;
};

class fastsimTileOp : public cimHWOp {
public:
fastsimTileOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
  ,const_element_type* input_repeats
  ,const_dim_type input_repeats_ndim, const_dim_type* input_repeats_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	
);

virtual void simulate() override;

private:
TileOp m_op;
};

class fastsimTopKOp : public cimHWOp {
public:
fastsimTopKOp(
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

virtual void simulate() override;

private:
TopKOp m_op;
};

class fastsimTransposeOp : public cimHWOp {
public:
fastsimTransposeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_transposed
  ,const_dim_type output_transposed_ndim, const_dim_type* output_transposed_dims
	,dim_type* perm
  ,const_dim_type number_of_perm
);

virtual void simulate() override;

private:
TransposeOp m_op;
};

class fastsimUnsqueezeOp : public cimHWOp {
public:
fastsimUnsqueezeOp(
	void* context
	,const_element_type* input_data
  ,const_dim_type input_data_ndim, const_dim_type* input_data_dims
	,element_type* output_expanded
  ,const_dim_type output_expanded_ndim, const_dim_type* output_expanded_dims
	,dim_type* axes
  ,const_dim_type number_of_axes
);

virtual void simulate() override;

private:
UnsqueezeOp m_op;
};

class fastsimUpsampleOp : public cimHWOp {
public:
fastsimUpsampleOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,const char* mode
  ,element_type* scales
  ,const_dim_type number_of_scales
);

virtual void simulate() override;

private:
UpsampleOp m_op;
};

class fastsimXorOp : public cimHWOp {
public:
fastsimXorOp(
	void* context
	,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
	,element_type* output_C
  ,const_dim_type output_C_ndim, const_dim_type* output_C_dims
	
);

virtual void simulate() override;

private:
XorOp m_op;
};

class fastsimATenOp : public cimHWOp {
public:
fastsimATenOp(
	void* context
	,const_element_type* const* input_input
  ,dim_type input_input_ntensor
  ,const_dim_type* input_input_ndim, const_dim_type* const* input_input_dims
	,element_type* const* output_output
  ,dim_type output_output_ntensor
  ,const_dim_type* output_output_ndim, const_dim_type* const* output_output_dims
	
);

virtual void simulate() override;

private:
ATenOp m_op;
};

class fastsimAffineOp : public cimHWOp {
public:
fastsimAffineOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type beta
);

virtual void simulate() override;

private:
AffineOp m_op;
};

class fastsimConstantFillOp : public cimHWOp {
public:
fastsimConstantFillOp(
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

virtual void simulate() override;

private:
ConstantFillOp m_op;
};

class fastsimCropOp : public cimHWOp {
public:
fastsimCropOp(
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

virtual void simulate() override;

private:
CropOp m_op;
};

class fastsimGRUUnitOp : public cimHWOp {
public:
fastsimGRUUnitOp(
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

virtual void simulate() override;

private:
GRUUnitOp m_op;
};

class fastsimGivenTensorFillOp : public cimHWOp {
public:
fastsimGivenTensorFillOp(
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

virtual void simulate() override;

private:
GivenTensorFillOp m_op;
};

class fastsimImageScalerOp : public cimHWOp {
public:
fastsimImageScalerOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type* bias
  ,const_dim_type number_of_bias
  ,element_type scale
);

virtual void simulate() override;

private:
ImageScalerOp m_op;
};

class fastsimMeanVarianceNormalizationOp : public cimHWOp {
public:
fastsimMeanVarianceNormalizationOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,dim_type across_channels
  ,dim_type normalize_variance
);

virtual void simulate() override;

private:
MeanVarianceNormalizationOp m_op;
};

class fastsimParametricSoftplusOp : public cimHWOp {
public:
fastsimParametricSoftplusOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
  ,element_type beta
);

virtual void simulate() override;

private:
ParametricSoftplusOp m_op;
};

class fastsimScaleOp : public cimHWOp {
public:
fastsimScaleOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type scale
);

virtual void simulate() override;

private:
ScaleOp m_op;
};

class fastsimScaledTanhOp : public cimHWOp {
public:
fastsimScaledTanhOp(
	void* context
	,const_element_type* input_input
  ,const_dim_type input_input_ndim, const_dim_type* input_input_dims
	,element_type* output_output
  ,const_dim_type output_output_ndim, const_dim_type* output_output_dims
	,element_type alpha
  ,element_type beta
);

virtual void simulate() override;

private:
ScaledTanhOp m_op;
};

class fastsimThresholdedReluOp : public cimHWOp {
public:
fastsimThresholdedReluOp(
	void* context
	,const_element_type* input_X
  ,const_dim_type input_X_ndim, const_dim_type* input_X_dims
	,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
	,element_type alpha
);

virtual void simulate() override;

private:
ThresholdedReluOp m_op;
};

} // namespce cimHW
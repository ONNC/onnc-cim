#pragma once
#include <string>
#include <cstdint>

using dim_type = int32_t;
using element_type = float;

class Operator {
protected:
	Operator(const std::string &type): op_type{type} {}
public:
	const std::string op_type;
};

class AbsOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	AbsOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class AcosOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	AcosOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class AddOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	AddOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class AffineOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	element_type beta;
	AffineOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_
	);
	void inference();
};

class AndOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	AndOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class ArgMaxOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type axis;
	dim_type keepdims;
	ArgMaxOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type axis_, dim_type keepdims_
	);
	void inference();
};

class ArgMinOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type axis;
	dim_type keepdims;
	ArgMinOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type axis_, dim_type keepdims_
	);
	void inference();
};

class AsinOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	AsinOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class AtanOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	AtanOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class ATenOp : public Operator {
public:
	const element_type * const * input_input;
	dim_type input_input_ntensor;
	const dim_type * input_input_ndim;
	const dim_type * const * input_input_dims;
	element_type * const * output_output;
	dim_type output_output_ntensor;
	const dim_type * output_output_ndim;
	const dim_type * const * output_output_dims;
	ATenOp(
		const element_type * const * input_input_, dim_type input_input_ntensor_, const dim_type * input_input_ndim_, const dim_type * const * input_input_dims_, element_type * const * output_output_, dim_type output_output_ntensor_, const dim_type * output_output_ndim_, const dim_type * const * output_output_dims_
	);
	void inference();
};

class AveragePoolOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	const char * auto_pad;
	dim_type count_include_pad;
	dim_type * kernel_shape;
	dim_type number_of_kernel_shape;
	dim_type * pads;
	dim_type number_of_pads;
	dim_type * strides;
	dim_type number_of_strides;
	AveragePoolOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * auto_pad_, dim_type count_include_pad_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type * pads_, dim_type number_of_pads_, dim_type * strides_, dim_type number_of_strides_
	);
	void inference();
};

class BatchNormalizationOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_scale;
	dim_type input_scale_ndim;
	const dim_type * input_scale_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	const element_type * input_mean;
	dim_type input_mean_ndim;
	const dim_type * input_mean_dims;
	const element_type * input_var;
	dim_type input_var_ndim;
	const dim_type * input_var_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type * output_mean;
	dim_type output_mean_ndim;
	const dim_type * output_mean_dims;
	element_type * output_var;
	dim_type output_var_ndim;
	const dim_type * output_var_dims;
	element_type * output_saved_mean;
	dim_type output_saved_mean_ndim;
	const dim_type * output_saved_mean_dims;
	element_type * output_saved_var;
	dim_type output_saved_var_ndim;
	const dim_type * output_saved_var_dims;
	element_type epsilon;
	element_type momentum;
	dim_type spatial;
	BatchNormalizationOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_scale_, dim_type input_scale_ndim_, const dim_type * input_scale_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_mean_, dim_type input_mean_ndim_, const dim_type * input_mean_dims_, const element_type * input_var_, dim_type input_var_ndim_, const dim_type * input_var_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_mean_, dim_type output_mean_ndim_, const dim_type * output_mean_dims_, element_type * output_var_, dim_type output_var_ndim_, const dim_type * output_var_dims_, element_type * output_saved_mean_, dim_type output_saved_mean_ndim_, const dim_type * output_saved_mean_dims_, element_type * output_saved_var_, dim_type output_saved_var_ndim_, const dim_type * output_saved_var_dims_, element_type epsilon_, element_type momentum_, dim_type spatial_
	);
	void inference();
};

class CastOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type to;
	CastOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type to_
	);
	void inference();
};

class CeilOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	CeilOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class ClipOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	element_type max;
	element_type min;
	ClipOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type max_, element_type min_
	);
	void inference();
};

class ConcatOp : public Operator {
public:
	const element_type * const * input_inputs;
	dim_type input_inputs_ntensor;
	const dim_type * input_inputs_ndim;
	const dim_type * const * input_inputs_dims;
	element_type * output_concat_result;
	dim_type output_concat_result_ndim;
	const dim_type * output_concat_result_dims;
	dim_type axis;
	ConcatOp(
		const element_type * const * input_inputs_, dim_type input_inputs_ntensor_, const dim_type * input_inputs_ndim_, const dim_type * const * input_inputs_dims_, element_type * output_concat_result_, dim_type output_concat_result_ndim_, const dim_type * output_concat_result_dims_, dim_type axis_
	);
	void inference();
};

class ConstantFillOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type dtype;
	dim_type * extra_shape;
	dim_type number_of_extra_shape;
	dim_type input_as_shape;
	dim_type * shape;
	dim_type number_of_shape;
	element_type value;
	ConstantFillOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, dim_type * extra_shape_, dim_type number_of_extra_shape_, dim_type input_as_shape_, dim_type * shape_, dim_type number_of_shape_, element_type value_
	);
	void inference();
};

class ConstantOp : public Operator {
public:
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	const void * value;
	ConstantOp(
		element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, const void * value_
	);
	void inference();
};

class ConvOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_W;
	dim_type input_W_ndim;
	const dim_type * input_W_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	const char * auto_pad;
	dim_type * dilations;
	dim_type number_of_dilations;
	dim_type group;
	dim_type * kernel_shape;
	dim_type number_of_kernel_shape;
	dim_type * pads;
	dim_type number_of_pads;
	dim_type * strides;
	dim_type number_of_strides;
	ConvOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * auto_pad_, dim_type * dilations_, dim_type number_of_dilations_, dim_type group_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type * pads_, dim_type number_of_pads_, dim_type * strides_, dim_type number_of_strides_
	);
	void inference();
};

class ConvTransposeOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_W;
	dim_type input_W_ndim;
	const dim_type * input_W_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	const char * auto_pad;
	dim_type * dilations;
	dim_type number_of_dilations;
	dim_type group;
	dim_type * kernel_shape;
	dim_type number_of_kernel_shape;
	dim_type * output_padding;
	dim_type number_of_output_padding;
	dim_type * output_shape;
	dim_type number_of_output_shape;
	dim_type * pads;
	dim_type number_of_pads;
	dim_type * strides;
	dim_type number_of_strides;
	ConvTransposeOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * auto_pad_, dim_type * dilations_, dim_type number_of_dilations_, dim_type group_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type * output_padding_, dim_type number_of_output_padding_, dim_type * output_shape_, dim_type number_of_output_shape_, dim_type * pads_, dim_type number_of_pads_, dim_type * strides_, dim_type number_of_strides_
	);
	void inference();
};

class CosOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	CosOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class CropOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type * border;
	dim_type number_of_border;
	dim_type * scale;
	dim_type number_of_scale;
	CropOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type * border_, dim_type number_of_border_, dim_type * scale_, dim_type number_of_scale_
	);
	void inference();
};

class DepthToSpaceOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type blocksize;
	DepthToSpaceOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type blocksize_
	);
	void inference();
};

class DivOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	DivOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class DropoutOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	element_type * output_mask;
	dim_type output_mask_ndim;
	const dim_type * output_mask_dims;
	element_type ratio;
	DropoutOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type * output_mask_, dim_type output_mask_ndim_, const dim_type * output_mask_dims_, element_type ratio_
	);
	void inference();
};

class EluOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	EluOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_
	);
	void inference();
};

class EqualOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	EqualOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class ExpandOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	const element_type * input_shape;
	dim_type input_shape_ndim;
	const dim_type * input_shape_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	ExpandOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, const element_type * input_shape_, dim_type input_shape_ndim_, const dim_type * input_shape_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class ExpOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	ExpOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class FlattenOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type axis;
	FlattenOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
	);
	void inference();
};

class FloorOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	FloorOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class GatherOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	const element_type * input_indices;
	dim_type input_indices_ndim;
	const dim_type * input_indices_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type axis;
	GatherOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, const element_type * input_indices_, dim_type input_indices_ndim_, const dim_type * input_indices_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
	);
	void inference();
};

class GemmOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	const element_type * input_C;
	dim_type input_C_ndim;
	const dim_type * input_C_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	element_type beta;
	dim_type transA;
	dim_type transB;
	GemmOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_C_, dim_type input_C_ndim_, const dim_type * input_C_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_, dim_type transA_, dim_type transB_
	);
	void inference();
};

class GivenTensorFillOp : public Operator {
public:
	const element_type * input_shape;
	dim_type input_shape_ndim;
	const dim_type * input_shape_dims;
	element_type * output_X;
	dim_type output_X_ndim;
	const dim_type * output_X_dims;
	dim_type * extra_shape;
	dim_type number_of_extra_shape;
	dim_type input_as_shape;
	dim_type * shape;
	dim_type number_of_shape;
	element_type * values;
	dim_type number_of_values;
	GivenTensorFillOp(
		const element_type * input_shape_, dim_type input_shape_ndim_, const dim_type * input_shape_dims_, element_type * output_X_, dim_type output_X_ndim_, const dim_type * output_X_dims_, dim_type * extra_shape_, dim_type number_of_extra_shape_, dim_type input_as_shape_, dim_type * shape_, dim_type number_of_shape_, element_type * values_, dim_type number_of_values_
	);
	void inference();
};

class GlobalAveragePoolOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	GlobalAveragePoolOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class GlobalLpPoolOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	dim_type p;
	GlobalLpPoolOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, dim_type p_
	);
	void inference();
};

class GlobalMaxPoolOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	GlobalMaxPoolOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class GreaterOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	GreaterOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class GRUOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_W;
	dim_type input_W_ndim;
	const dim_type * input_W_dims;
	const element_type * input_R;
	dim_type input_R_ndim;
	const dim_type * input_R_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	const element_type * input_sequence_lens;
	dim_type input_sequence_lens_ndim;
	const dim_type * input_sequence_lens_dims;
	const element_type * input_initial_h;
	dim_type input_initial_h_ndim;
	const dim_type * input_initial_h_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type * output_Y_h;
	dim_type output_Y_h_ndim;
	const dim_type * output_Y_h_dims;
	element_type * activation_alpha;
	dim_type number_of_activation_alpha;
	element_type * activation_beta;
	dim_type number_of_activation_beta;
	const char ** activations;
	dim_type number_of_activations;
	element_type clip;
	const char * direction;
	dim_type hidden_size;
	dim_type linear_before_reset;
	GRUOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_R_, dim_type input_R_ndim_, const dim_type * input_R_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_sequence_lens_, dim_type input_sequence_lens_ndim_, const dim_type * input_sequence_lens_dims_, const element_type * input_initial_h_, dim_type input_initial_h_ndim_, const dim_type * input_initial_h_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_Y_h_, dim_type output_Y_h_ndim_, const dim_type * output_Y_h_dims_, element_type * activation_alpha_, dim_type number_of_activation_alpha_, element_type * activation_beta_, dim_type number_of_activation_beta_, const char ** activations_, dim_type number_of_activations_, element_type clip_, const char * direction_, dim_type hidden_size_, dim_type linear_before_reset_
	);
	void inference();
};

class GRUUnitOp : public Operator {
public:
	const element_type * input_hidden_prev;
	dim_type input_hidden_prev_ndim;
	const dim_type * input_hidden_prev_dims;
	const element_type * input_gates;
	dim_type input_gates_ndim;
	const dim_type * input_gates_dims;
	const element_type * input_seq_lengths;
	dim_type input_seq_lengths_ndim;
	const dim_type * input_seq_lengths_dims;
	const element_type * input_t;
	dim_type input_t_ndim;
	const dim_type * input_t_dims;
	element_type * output_hidden;
	dim_type output_hidden_ndim;
	const dim_type * output_hidden_dims;
	dim_type drop_states;
	GRUUnitOp(
		const element_type * input_hidden_prev_, dim_type input_hidden_prev_ndim_, const dim_type * input_hidden_prev_dims_, const element_type * input_gates_, dim_type input_gates_ndim_, const dim_type * input_gates_dims_, const element_type * input_seq_lengths_, dim_type input_seq_lengths_ndim_, const dim_type * input_seq_lengths_dims_, const element_type * input_t_, dim_type input_t_ndim_, const dim_type * input_t_dims_, element_type * output_hidden_, dim_type output_hidden_ndim_, const dim_type * output_hidden_dims_, dim_type drop_states_
	);
	void inference();
};

class HardmaxOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type axis;
	HardmaxOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
	);
	void inference();
};

class HardSigmoidOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	element_type beta;
	HardSigmoidOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_
	);
	void inference();
};

class IdentityOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	IdentityOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class IfOp : public Operator {
public:
	const element_type * input_cond;
	dim_type input_cond_ndim;
	const dim_type * input_cond_dims;
	element_type * const * output_outputs;
	dim_type output_outputs_ntensor;
	const dim_type * output_outputs_ndim;
	const dim_type * const * output_outputs_dims;
	const void * else_branch;
	const void * then_branch;
	IfOp(
		const element_type * input_cond_, dim_type input_cond_ndim_, const dim_type * input_cond_dims_, element_type * const * output_outputs_, dim_type output_outputs_ntensor_, const dim_type * output_outputs_ndim_, const dim_type * const * output_outputs_dims_, const void * else_branch_, const void * then_branch_
	);
	void inference();
};

class ImageScalerOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	element_type * bias;
	dim_type number_of_bias;
	element_type scale;
	ImageScalerOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type * bias_, dim_type number_of_bias_, element_type scale_
	);
	void inference();
};

class InstanceNormalizationOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	const element_type * input_scale;
	dim_type input_scale_ndim;
	const dim_type * input_scale_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	element_type epsilon;
	InstanceNormalizationOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, const element_type * input_scale_, dim_type input_scale_ndim_, const dim_type * input_scale_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type epsilon_
	);
	void inference();
};

class LeakyReluOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	LeakyReluOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_
	);
	void inference();
};

class LessOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	LessOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class LogOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	LogOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class LogSoftmaxOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type axis;
	LogSoftmaxOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
	);
	void inference();
};

class LoopOp : public Operator {
public:
	const element_type * input_M;
	dim_type input_M_ndim;
	const dim_type * input_M_dims;
	const element_type * input_cond;
	dim_type input_cond_ndim;
	const dim_type * input_cond_dims;
	const element_type * const * input_v_initial;
	dim_type input_v_initial_ntensor;
	const dim_type * input_v_initial_ndim;
	const dim_type * const * input_v_initial_dims;
	element_type * const * output_v_final_and_scan_outputs;
	dim_type output_v_final_and_scan_outputs_ntensor;
	const dim_type * output_v_final_and_scan_outputs_ndim;
	const dim_type * const * output_v_final_and_scan_outputs_dims;
	const void * body;
	LoopOp(
		const element_type * input_M_, dim_type input_M_ndim_, const dim_type * input_M_dims_, const element_type * input_cond_, dim_type input_cond_ndim_, const dim_type * input_cond_dims_, const element_type * const * input_v_initial_, dim_type input_v_initial_ntensor_, const dim_type * input_v_initial_ndim_, const dim_type * const * input_v_initial_dims_, element_type * const * output_v_final_and_scan_outputs_, dim_type output_v_final_and_scan_outputs_ntensor_, const dim_type * output_v_final_and_scan_outputs_ndim_, const dim_type * const * output_v_final_and_scan_outputs_dims_, const void * body_
	);
	void inference();
};

class LpNormalizationOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type axis;
	dim_type p;
	LpNormalizationOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_, dim_type p_
	);
	void inference();
};

class LpPoolOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	const char * auto_pad;
	dim_type * kernel_shape;
	dim_type number_of_kernel_shape;
	dim_type p;
	dim_type * pads;
	dim_type number_of_pads;
	dim_type * strides;
	dim_type number_of_strides;
	LpPoolOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * auto_pad_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type p_, dim_type * pads_, dim_type number_of_pads_, dim_type * strides_, dim_type number_of_strides_
	);
	void inference();
};

class LRNOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	element_type beta;
	element_type bias;
	dim_type size;
	LRNOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_, element_type bias_, dim_type size_
	);
	void inference();
};

class LSTMOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_W;
	dim_type input_W_ndim;
	const dim_type * input_W_dims;
	const element_type * input_R;
	dim_type input_R_ndim;
	const dim_type * input_R_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	const element_type * input_sequence_lens;
	dim_type input_sequence_lens_ndim;
	const dim_type * input_sequence_lens_dims;
	const element_type * input_initial_h;
	dim_type input_initial_h_ndim;
	const dim_type * input_initial_h_dims;
	const element_type * input_initial_c;
	dim_type input_initial_c_ndim;
	const dim_type * input_initial_c_dims;
	const element_type * input_P;
	dim_type input_P_ndim;
	const dim_type * input_P_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type * output_Y_h;
	dim_type output_Y_h_ndim;
	const dim_type * output_Y_h_dims;
	element_type * output_Y_c;
	dim_type output_Y_c_ndim;
	const dim_type * output_Y_c_dims;
	element_type * activation_alpha;
	dim_type number_of_activation_alpha;
	element_type * activation_beta;
	dim_type number_of_activation_beta;
	const char ** activations;
	dim_type number_of_activations;
	element_type clip;
	const char * direction;
	dim_type hidden_size;
	dim_type input_forget;
	LSTMOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_R_, dim_type input_R_ndim_, const dim_type * input_R_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_sequence_lens_, dim_type input_sequence_lens_ndim_, const dim_type * input_sequence_lens_dims_, const element_type * input_initial_h_, dim_type input_initial_h_ndim_, const dim_type * input_initial_h_dims_, const element_type * input_initial_c_, dim_type input_initial_c_ndim_, const dim_type * input_initial_c_dims_, const element_type * input_P_, dim_type input_P_ndim_, const dim_type * input_P_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_Y_h_, dim_type output_Y_h_ndim_, const dim_type * output_Y_h_dims_, element_type * output_Y_c_, dim_type output_Y_c_ndim_, const dim_type * output_Y_c_dims_, element_type * activation_alpha_, dim_type number_of_activation_alpha_, element_type * activation_beta_, dim_type number_of_activation_beta_, const char ** activations_, dim_type number_of_activations_, element_type clip_, const char * direction_, dim_type hidden_size_, dim_type input_forget_
	);
	void inference();
};

class MatMulOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	MatMulOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class MaxOp : public Operator {
public:
	const element_type * const * input_data_0;
	dim_type input_data_0_ntensor;
	const dim_type * input_data_0_ndim;
	const dim_type * const * input_data_0_dims;
	element_type * output_max;
	dim_type output_max_ndim;
	const dim_type * output_max_dims;
	MaxOp(
		const element_type * const * input_data_0_, dim_type input_data_0_ntensor_, const dim_type * input_data_0_ndim_, const dim_type * const * input_data_0_dims_, element_type * output_max_, dim_type output_max_ndim_, const dim_type * output_max_dims_
	);
	void inference();
};

class MaxPoolOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type * output_Indices;
	dim_type output_Indices_ndim;
	const dim_type * output_Indices_dims;
	const char * auto_pad;
	dim_type * kernel_shape;
	dim_type number_of_kernel_shape;
	dim_type * pads;
	dim_type number_of_pads;
	dim_type storage_order;
	dim_type * strides;
	dim_type number_of_strides;
	MaxPoolOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_Indices_, dim_type output_Indices_ndim_, const dim_type * output_Indices_dims_, const char * auto_pad_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type * pads_, dim_type number_of_pads_, dim_type storage_order_, dim_type * strides_, dim_type number_of_strides_
	);
	void inference();
};

class MaxRoiPoolOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_rois;
	dim_type input_rois_ndim;
	const dim_type * input_rois_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	dim_type * pooled_shape;
	dim_type number_of_pooled_shape;
	element_type spatial_scale;
	MaxRoiPoolOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_rois_, dim_type input_rois_ndim_, const dim_type * input_rois_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, dim_type * pooled_shape_, dim_type number_of_pooled_shape_, element_type spatial_scale_
	);
	void inference();
};

class MeanOp : public Operator {
public:
	const element_type * const * input_data_0;
	dim_type input_data_0_ntensor;
	const dim_type * input_data_0_ndim;
	const dim_type * const * input_data_0_dims;
	element_type * output_mean;
	dim_type output_mean_ndim;
	const dim_type * output_mean_dims;
	MeanOp(
		const element_type * const * input_data_0_, dim_type input_data_0_ntensor_, const dim_type * input_data_0_ndim_, const dim_type * const * input_data_0_dims_, element_type * output_mean_, dim_type output_mean_ndim_, const dim_type * output_mean_dims_
	);
	void inference();
};

class MeanVarianceNormalizationOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type across_channels;
	dim_type normalize_variance;
	MeanVarianceNormalizationOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type across_channels_, dim_type normalize_variance_
	);
	void inference();
};

class MinOp : public Operator {
public:
	const element_type * const * input_data_0;
	dim_type input_data_0_ntensor;
	const dim_type * input_data_0_ndim;
	const dim_type * const * input_data_0_dims;
	element_type * output_min;
	dim_type output_min_ndim;
	const dim_type * output_min_dims;
	MinOp(
		const element_type * const * input_data_0_, dim_type input_data_0_ntensor_, const dim_type * input_data_0_ndim_, const dim_type * const * input_data_0_dims_, element_type * output_min_, dim_type output_min_ndim_, const dim_type * output_min_dims_
	);
	void inference();
};

class MulOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	MulOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class MultinomialOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type dtype;
	dim_type sample_size;
	element_type seed;
	MultinomialOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, dim_type sample_size_, element_type seed_
	);
	void inference();
};

class NegOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	NegOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class NotOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	NotOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class OrOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	OrOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class PadOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	const char * mode;
	dim_type * pads;
	dim_type number_of_pads;
	element_type value;
	PadOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, const char * mode_, dim_type * pads_, dim_type number_of_pads_, element_type value_
	);
	void inference();
};

class ParametricSoftplusOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	element_type beta;
	ParametricSoftplusOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_
	);
	void inference();
};

class PowOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_Y;
	dim_type input_Y_ndim;
	const dim_type * input_Y_dims;
	element_type * output_Z;
	dim_type output_Z_ndim;
	const dim_type * output_Z_dims;
	PowOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_Y_, dim_type input_Y_ndim_, const dim_type * input_Y_dims_, element_type * output_Z_, dim_type output_Z_ndim_, const dim_type * output_Z_dims_
	);
	void inference();
};

class PReluOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_slope;
	dim_type input_slope_ndim;
	const dim_type * input_slope_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	PReluOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_slope_, dim_type input_slope_ndim_, const dim_type * input_slope_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class RandomNormalOp : public Operator {
public:
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type dtype;
	element_type mean;
	element_type scale;
	element_type seed;
	dim_type * shape;
	dim_type number_of_shape;
	RandomNormalOp(
		element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, element_type mean_, element_type scale_, element_type seed_, dim_type * shape_, dim_type number_of_shape_
	);
	void inference();
};

class RandomNormalLikeOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type dtype;
	element_type mean;
	element_type scale;
	element_type seed;
	RandomNormalLikeOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, element_type mean_, element_type scale_, element_type seed_
	);
	void inference();
};

class RandomUniformOp : public Operator {
public:
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type dtype;
	element_type high;
	element_type low;
	element_type seed;
	dim_type * shape;
	dim_type number_of_shape;
	RandomUniformOp(
		element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, element_type high_, element_type low_, element_type seed_, dim_type * shape_, dim_type number_of_shape_
	);
	void inference();
};

class RandomUniformLikeOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type dtype;
	element_type high;
	element_type low;
	element_type seed;
	RandomUniformLikeOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, element_type high_, element_type low_, element_type seed_
	);
	void inference();
};

class ReciprocalOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	ReciprocalOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class ReduceL1Op : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceL1Op(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceL2Op : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceL2Op(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceLogSumExpOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceLogSumExpOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceLogSumOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceLogSumOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceMaxOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceMaxOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceMeanOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceMeanOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceMinOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceMinOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceProdOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceProdOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceSumOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceSumOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReduceSumSquareOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_reduced;
	dim_type output_reduced_ndim;
	const dim_type * output_reduced_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type keepdims;
	ReduceSumSquareOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
	);
	void inference();
};

class ReluOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	ReluOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class ReshapeOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	const element_type * input_shape;
	dim_type input_shape_ndim;
	const dim_type * input_shape_dims;
	element_type * output_reshaped;
	dim_type output_reshaped_ndim;
	const dim_type * output_reshaped_dims;
	ReshapeOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, const element_type * input_shape_, dim_type input_shape_ndim_, const dim_type * input_shape_dims_, element_type * output_reshaped_, dim_type output_reshaped_ndim_, const dim_type * output_reshaped_dims_
	);
	void inference();
};

class RNNOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	const element_type * input_W;
	dim_type input_W_ndim;
	const dim_type * input_W_dims;
	const element_type * input_R;
	dim_type input_R_ndim;
	const dim_type * input_R_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	const element_type * input_sequence_lens;
	dim_type input_sequence_lens_ndim;
	const dim_type * input_sequence_lens_dims;
	const element_type * input_initial_h;
	dim_type input_initial_h_ndim;
	const dim_type * input_initial_h_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type * output_Y_h;
	dim_type output_Y_h_ndim;
	const dim_type * output_Y_h_dims;
	element_type * activation_alpha;
	dim_type number_of_activation_alpha;
	element_type * activation_beta;
	dim_type number_of_activation_beta;
	const char ** activations;
	dim_type number_of_activations;
	element_type clip;
	const char * direction;
	dim_type hidden_size;
	RNNOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_R_, dim_type input_R_ndim_, const dim_type * input_R_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_sequence_lens_, dim_type input_sequence_lens_ndim_, const dim_type * input_sequence_lens_dims_, const element_type * input_initial_h_, dim_type input_initial_h_ndim_, const dim_type * input_initial_h_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_Y_h_, dim_type output_Y_h_ndim_, const dim_type * output_Y_h_dims_, element_type * activation_alpha_, dim_type number_of_activation_alpha_, element_type * activation_beta_, dim_type number_of_activation_beta_, const char ** activations_, dim_type number_of_activations_, element_type clip_, const char * direction_, dim_type hidden_size_
	);
	void inference();
};

class ScaledTanhOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	element_type alpha;
	element_type beta;
	ScaledTanhOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type alpha_, element_type beta_
	);
	void inference();
};

class ScaleOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	element_type scale;
	ScaleOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type scale_
	);
	void inference();
};

class ScanOp : public Operator {
public:
	const element_type * input_sequence_lens;
	dim_type input_sequence_lens_ndim;
	const dim_type * input_sequence_lens_dims;
	const element_type * const * input_initial_state_and_scan_inputs;
	dim_type input_initial_state_and_scan_inputs_ntensor;
	const dim_type * input_initial_state_and_scan_inputs_ndim;
	const dim_type * const * input_initial_state_and_scan_inputs_dims;
	element_type * const * output_final_state_and_scan_outputs;
	dim_type output_final_state_and_scan_outputs_ntensor;
	const dim_type * output_final_state_and_scan_outputs_ndim;
	const dim_type * const * output_final_state_and_scan_outputs_dims;
	const void * body;
	dim_type * directions;
	dim_type number_of_directions;
	dim_type num_scan_inputs;
	ScanOp(
		const element_type * input_sequence_lens_, dim_type input_sequence_lens_ndim_, const dim_type * input_sequence_lens_dims_, const element_type * const * input_initial_state_and_scan_inputs_, dim_type input_initial_state_and_scan_inputs_ntensor_, const dim_type * input_initial_state_and_scan_inputs_ndim_, const dim_type * const * input_initial_state_and_scan_inputs_dims_, element_type * const * output_final_state_and_scan_outputs_, dim_type output_final_state_and_scan_outputs_ntensor_, const dim_type * output_final_state_and_scan_outputs_ndim_, const dim_type * const * output_final_state_and_scan_outputs_dims_, const void * body_, dim_type * directions_, dim_type number_of_directions_, dim_type num_scan_inputs_
	);
	void inference();
};

class SeluOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	element_type gamma;
	SeluOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type gamma_
	);
	void inference();
};

class ShapeOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_shape;
	dim_type output_shape_ndim;
	const dim_type * output_shape_dims;
	ShapeOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_shape_, dim_type output_shape_ndim_, const dim_type * output_shape_dims_
	);
	void inference();
};

class SigmoidOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	SigmoidOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class SinOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	SinOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class SizeOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_size;
	dim_type output_size_ndim;
	const dim_type * output_size_dims;
	SizeOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_size_, dim_type output_size_ndim_, const dim_type * output_size_dims_
	);
	void inference();
};

class SliceOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type * axes;
	dim_type number_of_axes;
	dim_type * ends;
	dim_type number_of_ends;
	dim_type * starts;
	dim_type number_of_starts;
	SliceOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type * ends_, dim_type number_of_ends_, dim_type * starts_, dim_type number_of_starts_
	);
	void inference();
};

class SoftmaxOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type axis;
	SoftmaxOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
	);
	void inference();
};

class SoftplusOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	SoftplusOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class SoftsignOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	SoftsignOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class SpaceToDepthOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	dim_type blocksize;
	SpaceToDepthOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type blocksize_
	);
	void inference();
};

class SplitOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * const * output_outputs;
	dim_type output_outputs_ntensor;
	const dim_type * output_outputs_ndim;
	const dim_type * const * output_outputs_dims;
	dim_type axis;
	dim_type * split;
	dim_type number_of_split;
	SplitOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * const * output_outputs_, dim_type output_outputs_ntensor_, const dim_type * output_outputs_ndim_, const dim_type * const * output_outputs_dims_, dim_type axis_, dim_type * split_, dim_type number_of_split_
	);
	void inference();
};

class SqrtOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	SqrtOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
	);
	void inference();
};

class SqueezeOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_squeezed;
	dim_type output_squeezed_ndim;
	const dim_type * output_squeezed_dims;
	dim_type * axes;
	dim_type number_of_axes;
	SqueezeOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_squeezed_, dim_type output_squeezed_ndim_, const dim_type * output_squeezed_dims_, dim_type * axes_, dim_type number_of_axes_
	);
	void inference();
};

class SubOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	SubOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};

class SumOp : public Operator {
public:
	const element_type * const * input_data_0;
	dim_type input_data_0_ntensor;
	const dim_type * input_data_0_ndim;
	const dim_type * const * input_data_0_dims;
	element_type * output_sum;
	dim_type output_sum_ndim;
	const dim_type * output_sum_dims;
	SumOp(
		const element_type * const * input_data_0_, dim_type input_data_0_ntensor_, const dim_type * input_data_0_ndim_, const dim_type * const * input_data_0_dims_, element_type * output_sum_, dim_type output_sum_ndim_, const dim_type * output_sum_dims_
	);
	void inference();
};

class TanOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	TanOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class TanhOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	TanhOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class ThresholdedReluOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	element_type alpha;
	ThresholdedReluOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_
	);
	void inference();
};

class TileOp : public Operator {
public:
	const element_type * input_input;
	dim_type input_input_ndim;
	const dim_type * input_input_dims;
	const element_type * input_repeats;
	dim_type input_repeats_ndim;
	const dim_type * input_repeats_dims;
	element_type * output_output;
	dim_type output_output_ndim;
	const dim_type * output_output_dims;
	TileOp(
		const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, const element_type * input_repeats_, dim_type input_repeats_ndim_, const dim_type * input_repeats_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
	);
	void inference();
};

class TopKOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Values;
	dim_type output_Values_ndim;
	const dim_type * output_Values_dims;
	element_type * output_Indices;
	dim_type output_Indices_ndim;
	const dim_type * output_Indices_dims;
	dim_type axis;
	dim_type k;
	TopKOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Values_, dim_type output_Values_ndim_, const dim_type * output_Values_dims_, element_type * output_Indices_, dim_type output_Indices_ndim_, const dim_type * output_Indices_dims_, dim_type axis_, dim_type k_
	);
	void inference();
};

class TransposeOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_transposed;
	dim_type output_transposed_ndim;
	const dim_type * output_transposed_dims;
	dim_type * perm;
	dim_type number_of_perm;
	TransposeOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_transposed_, dim_type output_transposed_ndim_, const dim_type * output_transposed_dims_, dim_type * perm_, dim_type number_of_perm_
	);
	void inference();
};

class UnsqueezeOp : public Operator {
public:
	const element_type * input_data;
	dim_type input_data_ndim;
	const dim_type * input_data_dims;
	element_type * output_expanded;
	dim_type output_expanded_ndim;
	const dim_type * output_expanded_dims;
	dim_type * axes;
	dim_type number_of_axes;
	UnsqueezeOp(
		const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_expanded_, dim_type output_expanded_ndim_, const dim_type * output_expanded_dims_, dim_type * axes_, dim_type number_of_axes_
	);
	void inference();
};

class UpsampleOp : public Operator {
public:
	const element_type * input_X;
	dim_type input_X_ndim;
	const dim_type * input_X_dims;
	element_type * output_Y;
	dim_type output_Y_ndim;
	const dim_type * output_Y_dims;
	const char * mode;
	element_type * scales;
	dim_type number_of_scales;
	UpsampleOp(
		const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * mode_, element_type * scales_, dim_type number_of_scales_
	);
	void inference();
};

class XorOp : public Operator {
public:
	const element_type * input_A;
	dim_type input_A_ndim;
	const dim_type * input_A_dims;
	const element_type * input_B;
	dim_type input_B_ndim;
	const dim_type * input_B_dims;
	element_type * output_C;
	dim_type output_C_ndim;
	const dim_type * output_C_dims;
	XorOp(
		const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
	);
	void inference();
};


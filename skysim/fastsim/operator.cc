#include <cstddef>
#include "fastsim/operator.hh"

typedef int32_t ONNC_INDEX_TYPE;
#ifdef __cplusplus
#define restrict __restrict__
extern "C" {
#endif

#include <onnc-runtime.h>

#ifdef __cplusplus
}
#endif

AbsOp::AbsOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Abs"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void AbsOp::inference() {
	ONNC_RUNTIME_abs_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

AcosOp::AcosOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Acos"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void AcosOp::inference() {
	ONNC_RUNTIME_acos_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

AddOp::AddOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Add"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void AddOp::inference() {
	ONNC_RUNTIME_add_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

AffineOp::AffineOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_
): Operator{"Affine"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	, beta{beta_}
	{}
void AffineOp::inference() {
	ONNC_RUNTIME_affine_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, alpha, beta);
}

AndOp::AndOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"And"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void AndOp::inference() {
	ONNC_RUNTIME_and_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

ArgMaxOp::ArgMaxOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type axis_, dim_type keepdims_
): Operator{"ArgMax"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axis{axis_}
	, keepdims{keepdims_}
	{}
void ArgMaxOp::inference() {
	ONNC_RUNTIME_argmax_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axis, keepdims);
}

ArgMinOp::ArgMinOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type axis_, dim_type keepdims_
): Operator{"ArgMin"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axis{axis_}
	, keepdims{keepdims_}
	{}
void ArgMinOp::inference() {
	ONNC_RUNTIME_argmin_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axis, keepdims);
}

AsinOp::AsinOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Asin"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void AsinOp::inference() {
	ONNC_RUNTIME_asin_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

AtanOp::AtanOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Atan"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void AtanOp::inference() {
	ONNC_RUNTIME_atan_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

ATenOp::ATenOp(
	const element_type * const * input_input_, dim_type input_input_ntensor_, const dim_type * input_input_ndim_, const dim_type * const * input_input_dims_, element_type * const * output_output_, dim_type output_output_ntensor_, const dim_type * output_output_ndim_, const dim_type * const * output_output_dims_
): Operator{"ATen"}
	, input_input{input_input_}
	, input_input_ntensor{input_input_ntensor_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ntensor{output_output_ntensor_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void ATenOp::inference() {
	ONNC_RUNTIME_aten_float(nullptr, input_input, input_input_ntensor, input_input_ndim, input_input_dims, output_output, output_output_ntensor, output_output_ndim, output_output_dims);
}

AveragePoolOp::AveragePoolOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * auto_pad_, dim_type count_include_pad_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type * pads_, dim_type number_of_pads_, dim_type * strides_, dim_type number_of_strides_
): Operator{"AveragePool"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, auto_pad{auto_pad_}
	, count_include_pad{count_include_pad_}
	, kernel_shape{kernel_shape_}
	, number_of_kernel_shape{number_of_kernel_shape_}
	, pads{pads_}
	, number_of_pads{number_of_pads_}
	, strides{strides_}
	, number_of_strides{number_of_strides_}
	{}
void AveragePoolOp::inference() {
	ONNC_RUNTIME_averagepool_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, auto_pad, count_include_pad, kernel_shape, number_of_kernel_shape, pads, number_of_pads, strides, number_of_strides);
}

BatchNormalizationOp::BatchNormalizationOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_scale_, dim_type input_scale_ndim_, const dim_type * input_scale_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_mean_, dim_type input_mean_ndim_, const dim_type * input_mean_dims_, const element_type * input_var_, dim_type input_var_ndim_, const dim_type * input_var_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_mean_, dim_type output_mean_ndim_, const dim_type * output_mean_dims_, element_type * output_var_, dim_type output_var_ndim_, const dim_type * output_var_dims_, element_type * output_saved_mean_, dim_type output_saved_mean_ndim_, const dim_type * output_saved_mean_dims_, element_type * output_saved_var_, dim_type output_saved_var_ndim_, const dim_type * output_saved_var_dims_, element_type epsilon_, element_type momentum_, dim_type spatial_
): Operator{"BatchNormalization"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_scale{input_scale_}
	, input_scale_ndim{input_scale_ndim_}
	, input_scale_dims{input_scale_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, input_mean{input_mean_}
	, input_mean_ndim{input_mean_ndim_}
	, input_mean_dims{input_mean_dims_}
	, input_var{input_var_}
	, input_var_ndim{input_var_ndim_}
	, input_var_dims{input_var_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, output_mean{output_mean_}
	, output_mean_ndim{output_mean_ndim_}
	, output_mean_dims{output_mean_dims_}
	, output_var{output_var_}
	, output_var_ndim{output_var_ndim_}
	, output_var_dims{output_var_dims_}
	, output_saved_mean{output_saved_mean_}
	, output_saved_mean_ndim{output_saved_mean_ndim_}
	, output_saved_mean_dims{output_saved_mean_dims_}
	, output_saved_var{output_saved_var_}
	, output_saved_var_ndim{output_saved_var_ndim_}
	, output_saved_var_dims{output_saved_var_dims_}
	, epsilon{epsilon_}
	, momentum{momentum_}
	, spatial{spatial_}
	{}
void BatchNormalizationOp::inference() {
	ONNC_RUNTIME_batchnormalization_float(nullptr, input_X, input_X_ndim, input_X_dims, input_scale, input_scale_ndim, input_scale_dims, input_B, input_B_ndim, input_B_dims, input_mean, input_mean_ndim, input_mean_dims, input_var, input_var_ndim, input_var_dims, output_Y, output_Y_ndim, output_Y_dims, output_mean, output_mean_ndim, output_mean_dims, output_var, output_var_ndim, output_var_dims, output_saved_mean, output_saved_mean_ndim, output_saved_mean_dims, output_saved_var, output_saved_var_ndim, output_saved_var_dims, epsilon, momentum, spatial);
}

CastOp::CastOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type to_
): Operator{"Cast"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, to{to_}
	{}
void CastOp::inference() {
	ONNC_RUNTIME_cast_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, to);
}

CeilOp::CeilOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Ceil"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void CeilOp::inference() {
	ONNC_RUNTIME_ceil_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

ClipOp::ClipOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type max_, element_type min_
): Operator{"Clip"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, max{max_}
	, min{min_}
	{}
void ClipOp::inference() {
	ONNC_RUNTIME_clip_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, max, min);
}

ConcatOp::ConcatOp(
	const element_type * const * input_inputs_, dim_type input_inputs_ntensor_, const dim_type * input_inputs_ndim_, const dim_type * const * input_inputs_dims_, element_type * output_concat_result_, dim_type output_concat_result_ndim_, const dim_type * output_concat_result_dims_, dim_type axis_
): Operator{"Concat"}
	, input_inputs{input_inputs_}
	, input_inputs_ntensor{input_inputs_ntensor_}
	, input_inputs_ndim{input_inputs_ndim_}
	, input_inputs_dims{input_inputs_dims_}
	, output_concat_result{output_concat_result_}
	, output_concat_result_ndim{output_concat_result_ndim_}
	, output_concat_result_dims{output_concat_result_dims_}
	, axis{axis_}
	{}
void ConcatOp::inference() {
	ONNC_RUNTIME_concat_float(nullptr, input_inputs, input_inputs_ntensor, input_inputs_ndim, input_inputs_dims, output_concat_result, output_concat_result_ndim, output_concat_result_dims, axis);
}

ConstantFillOp::ConstantFillOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, dim_type * extra_shape_, dim_type number_of_extra_shape_, dim_type input_as_shape_, dim_type * shape_, dim_type number_of_shape_, element_type value_
): Operator{"ConstantFill"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, dtype{dtype_}
	, extra_shape{extra_shape_}
	, number_of_extra_shape{number_of_extra_shape_}
	, input_as_shape{input_as_shape_}
	, shape{shape_}
	, number_of_shape{number_of_shape_}
	, value{value_}
	{}
void ConstantFillOp::inference() {
	ONNC_RUNTIME_constantfill_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, dtype, extra_shape, number_of_extra_shape, input_as_shape, shape, number_of_shape, value);
}

ConstantOp::ConstantOp(
	element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, const void * value_
): Operator{"Constant"}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, value{value_}
	{}
void ConstantOp::inference() {
	ONNC_RUNTIME_constant_float(nullptr, output_output, output_output_ndim, output_output_dims, value);
}

ConvOp::ConvOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * auto_pad_, dim_type * dilations_, dim_type number_of_dilations_, dim_type group_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type * pads_, dim_type number_of_pads_, dim_type * strides_, dim_type number_of_strides_
): Operator{"Conv"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_W{input_W_}
	, input_W_ndim{input_W_ndim_}
	, input_W_dims{input_W_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, auto_pad{auto_pad_}
	, dilations{dilations_}
	, number_of_dilations{number_of_dilations_}
	, group{group_}
	, kernel_shape{kernel_shape_}
	, number_of_kernel_shape{number_of_kernel_shape_}
	, pads{pads_}
	, number_of_pads{number_of_pads_}
	, strides{strides_}
	, number_of_strides{number_of_strides_}
	{}
void ConvOp::inference() {
	ONNC_RUNTIME_conv_float(nullptr, input_X, input_X_ndim, input_X_dims, input_W, input_W_ndim, input_W_dims, input_B, input_B_ndim, input_B_dims, output_Y, output_Y_ndim, output_Y_dims, auto_pad, dilations, number_of_dilations, group, kernel_shape, number_of_kernel_shape, pads, number_of_pads, strides, number_of_strides);
}

ConvTransposeOp::ConvTransposeOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * auto_pad_, dim_type * dilations_, dim_type number_of_dilations_, dim_type group_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type * output_padding_, dim_type number_of_output_padding_, dim_type * output_shape_, dim_type number_of_output_shape_, dim_type * pads_, dim_type number_of_pads_, dim_type * strides_, dim_type number_of_strides_
): Operator{"ConvTranspose"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_W{input_W_}
	, input_W_ndim{input_W_ndim_}
	, input_W_dims{input_W_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, auto_pad{auto_pad_}
	, dilations{dilations_}
	, number_of_dilations{number_of_dilations_}
	, group{group_}
	, kernel_shape{kernel_shape_}
	, number_of_kernel_shape{number_of_kernel_shape_}
	, output_padding{output_padding_}
	, number_of_output_padding{number_of_output_padding_}
	, output_shape{output_shape_}
	, number_of_output_shape{number_of_output_shape_}
	, pads{pads_}
	, number_of_pads{number_of_pads_}
	, strides{strides_}
	, number_of_strides{number_of_strides_}
	{}
void ConvTransposeOp::inference() {
	ONNC_RUNTIME_convtranspose_float(nullptr, input_X, input_X_ndim, input_X_dims, input_W, input_W_ndim, input_W_dims, input_B, input_B_ndim, input_B_dims, output_Y, output_Y_ndim, output_Y_dims, auto_pad, dilations, number_of_dilations, group, kernel_shape, number_of_kernel_shape, output_padding, number_of_output_padding, output_shape, number_of_output_shape, pads, number_of_pads, strides, number_of_strides);
}

CosOp::CosOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Cos"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void CosOp::inference() {
	ONNC_RUNTIME_cos_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

CropOp::CropOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type * border_, dim_type number_of_border_, dim_type * scale_, dim_type number_of_scale_
): Operator{"Crop"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, border{border_}
	, number_of_border{number_of_border_}
	, scale{scale_}
	, number_of_scale{number_of_scale_}
	{}
void CropOp::inference() {
	ONNC_RUNTIME_crop_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, border, number_of_border, scale, number_of_scale);
}

DepthToSpaceOp::DepthToSpaceOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type blocksize_
): Operator{"DepthToSpace"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, blocksize{blocksize_}
	{}
void DepthToSpaceOp::inference() {
	ONNC_RUNTIME_depthtospace_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, blocksize);
}

DivOp::DivOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Div"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void DivOp::inference() {
	ONNC_RUNTIME_div_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

DropoutOp::DropoutOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type * output_mask_, dim_type output_mask_ndim_, const dim_type * output_mask_dims_, element_type ratio_
): Operator{"Dropout"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, output_mask{output_mask_}
	, output_mask_ndim{output_mask_ndim_}
	, output_mask_dims{output_mask_dims_}
	, ratio{ratio_}
	{}
void DropoutOp::inference() {
	ONNC_RUNTIME_dropout_float(nullptr, input_data, input_data_ndim, input_data_dims, output_output, output_output_ndim, output_output_dims, output_mask, output_mask_ndim, output_mask_dims, ratio);
}

EluOp::EluOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_
): Operator{"Elu"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	{}
void EluOp::inference() {
	ONNC_RUNTIME_elu_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, alpha);
}

EqualOp::EqualOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Equal"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void EqualOp::inference() {
	ONNC_RUNTIME_equal_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

ExpandOp::ExpandOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, const element_type * input_shape_, dim_type input_shape_ndim_, const dim_type * input_shape_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Expand"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, input_shape{input_shape_}
	, input_shape_ndim{input_shape_ndim_}
	, input_shape_dims{input_shape_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void ExpandOp::inference() {
	ONNC_RUNTIME_expand_float(nullptr, input_input, input_input_ndim, input_input_dims, input_shape, input_shape_ndim, input_shape_dims, output_output, output_output_ndim, output_output_dims);
}

ExpOp::ExpOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Exp"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void ExpOp::inference() {
	ONNC_RUNTIME_exp_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

FlattenOp::FlattenOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
): Operator{"Flatten"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, axis{axis_}
	{}
void FlattenOp::inference() {
	ONNC_RUNTIME_flatten_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, axis);
}

FloorOp::FloorOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Floor"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void FloorOp::inference() {
	ONNC_RUNTIME_floor_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

GatherOp::GatherOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, const element_type * input_indices_, dim_type input_indices_ndim_, const dim_type * input_indices_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
): Operator{"Gather"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, input_indices{input_indices_}
	, input_indices_ndim{input_indices_ndim_}
	, input_indices_dims{input_indices_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, axis{axis_}
	{}
void GatherOp::inference() {
	ONNC_RUNTIME_gather_float(nullptr, input_data, input_data_ndim, input_data_dims, input_indices, input_indices_ndim, input_indices_dims, output_output, output_output_ndim, output_output_dims, axis);
}

GemmOp::GemmOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_C_, dim_type input_C_ndim_, const dim_type * input_C_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_, dim_type transA_, dim_type transB_
): Operator{"Gemm"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, input_C{input_C_}
	, input_C_ndim{input_C_ndim_}
	, input_C_dims{input_C_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	, beta{beta_}
	, transA{transA_}
	, transB{transB_}
	{}
void GemmOp::inference() {
	ONNC_RUNTIME_gemm_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, input_C, input_C_ndim, input_C_dims, output_Y, output_Y_ndim, output_Y_dims, alpha, beta, transA, transB);
}

GivenTensorFillOp::GivenTensorFillOp(
	const element_type * input_shape_, dim_type input_shape_ndim_, const dim_type * input_shape_dims_, element_type * output_X_, dim_type output_X_ndim_, const dim_type * output_X_dims_, dim_type * extra_shape_, dim_type number_of_extra_shape_, dim_type input_as_shape_, dim_type * shape_, dim_type number_of_shape_, element_type * values_, dim_type number_of_values_
): Operator{"GivenTensorFill"}
	, input_shape{input_shape_}
	, input_shape_ndim{input_shape_ndim_}
	, input_shape_dims{input_shape_dims_}
	, output_X{output_X_}
	, output_X_ndim{output_X_ndim_}
	, output_X_dims{output_X_dims_}
	, extra_shape{extra_shape_}
	, number_of_extra_shape{number_of_extra_shape_}
	, input_as_shape{input_as_shape_}
	, shape{shape_}
	, number_of_shape{number_of_shape_}
	, values{values_}
	, number_of_values{number_of_values_}
	{}
void GivenTensorFillOp::inference() {
	ONNC_RUNTIME_giventensorfill_float(nullptr, input_shape, input_shape_ndim, input_shape_dims, output_X, output_X_ndim, output_X_dims, extra_shape, number_of_extra_shape, input_as_shape, shape, number_of_shape, values, number_of_values);
}

GlobalAveragePoolOp::GlobalAveragePoolOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"GlobalAveragePool"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void GlobalAveragePoolOp::inference() {
	ONNC_RUNTIME_globalaveragepool_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

GlobalLpPoolOp::GlobalLpPoolOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, dim_type p_
): Operator{"GlobalLpPool"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, p{p_}
	{}
void GlobalLpPoolOp::inference() {
	ONNC_RUNTIME_globallppool_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, p);
}

GlobalMaxPoolOp::GlobalMaxPoolOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"GlobalMaxPool"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void GlobalMaxPoolOp::inference() {
	ONNC_RUNTIME_globalmaxpool_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

GreaterOp::GreaterOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Greater"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void GreaterOp::inference() {
	ONNC_RUNTIME_greater_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

GRUOp::GRUOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_R_, dim_type input_R_ndim_, const dim_type * input_R_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_sequence_lens_, dim_type input_sequence_lens_ndim_, const dim_type * input_sequence_lens_dims_, const element_type * input_initial_h_, dim_type input_initial_h_ndim_, const dim_type * input_initial_h_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_Y_h_, dim_type output_Y_h_ndim_, const dim_type * output_Y_h_dims_, element_type * activation_alpha_, dim_type number_of_activation_alpha_, element_type * activation_beta_, dim_type number_of_activation_beta_, const char ** activations_, dim_type number_of_activations_, element_type clip_, const char * direction_, dim_type hidden_size_, dim_type linear_before_reset_
): Operator{"GRU"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_W{input_W_}
	, input_W_ndim{input_W_ndim_}
	, input_W_dims{input_W_dims_}
	, input_R{input_R_}
	, input_R_ndim{input_R_ndim_}
	, input_R_dims{input_R_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, input_sequence_lens{input_sequence_lens_}
	, input_sequence_lens_ndim{input_sequence_lens_ndim_}
	, input_sequence_lens_dims{input_sequence_lens_dims_}
	, input_initial_h{input_initial_h_}
	, input_initial_h_ndim{input_initial_h_ndim_}
	, input_initial_h_dims{input_initial_h_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, output_Y_h{output_Y_h_}
	, output_Y_h_ndim{output_Y_h_ndim_}
	, output_Y_h_dims{output_Y_h_dims_}
	, activation_alpha{activation_alpha_}
	, number_of_activation_alpha{number_of_activation_alpha_}
	, activation_beta{activation_beta_}
	, number_of_activation_beta{number_of_activation_beta_}
	, activations{activations_}
	, number_of_activations{number_of_activations_}
	, clip{clip_}
	, direction{direction_}
	, hidden_size{hidden_size_}
	, linear_before_reset{linear_before_reset_}
	{}
void GRUOp::inference() {
	ONNC_RUNTIME_gru_float(nullptr, input_X, input_X_ndim, input_X_dims, input_W, input_W_ndim, input_W_dims, input_R, input_R_ndim, input_R_dims, input_B, input_B_ndim, input_B_dims, input_sequence_lens, input_sequence_lens_ndim, input_sequence_lens_dims, input_initial_h, input_initial_h_ndim, input_initial_h_dims, output_Y, output_Y_ndim, output_Y_dims, output_Y_h, output_Y_h_ndim, output_Y_h_dims, activation_alpha, number_of_activation_alpha, activation_beta, number_of_activation_beta, activations, number_of_activations, clip, direction, hidden_size, linear_before_reset);
}

GRUUnitOp::GRUUnitOp(
	const element_type * input_hidden_prev_, dim_type input_hidden_prev_ndim_, const dim_type * input_hidden_prev_dims_, const element_type * input_gates_, dim_type input_gates_ndim_, const dim_type * input_gates_dims_, const element_type * input_seq_lengths_, dim_type input_seq_lengths_ndim_, const dim_type * input_seq_lengths_dims_, const element_type * input_t_, dim_type input_t_ndim_, const dim_type * input_t_dims_, element_type * output_hidden_, dim_type output_hidden_ndim_, const dim_type * output_hidden_dims_, dim_type drop_states_
): Operator{"GRUUnitOp"}
	, input_hidden_prev{input_hidden_prev_}
	, input_hidden_prev_ndim{input_hidden_prev_ndim_}
	, input_hidden_prev_dims{input_hidden_prev_dims_}
	, input_gates{input_gates_}
	, input_gates_ndim{input_gates_ndim_}
	, input_gates_dims{input_gates_dims_}
	, input_seq_lengths{input_seq_lengths_}
	, input_seq_lengths_ndim{input_seq_lengths_ndim_}
	, input_seq_lengths_dims{input_seq_lengths_dims_}
	, input_t{input_t_}
	, input_t_ndim{input_t_ndim_}
	, input_t_dims{input_t_dims_}
	, output_hidden{output_hidden_}
	, output_hidden_ndim{output_hidden_ndim_}
	, output_hidden_dims{output_hidden_dims_}
	, drop_states{drop_states_}
	{}
void GRUUnitOp::inference() {
	ONNC_RUNTIME_gruunit_float(nullptr, input_hidden_prev, input_hidden_prev_ndim, input_hidden_prev_dims, input_gates, input_gates_ndim, input_gates_dims, input_seq_lengths, input_seq_lengths_ndim, input_seq_lengths_dims, input_t, input_t_ndim, input_t_dims, output_hidden, output_hidden_ndim, output_hidden_dims, drop_states);
}

HardmaxOp::HardmaxOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
): Operator{"Hardmax"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, axis{axis_}
	{}
void HardmaxOp::inference() {
	ONNC_RUNTIME_hardmax_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, axis);
}

HardSigmoidOp::HardSigmoidOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_
): Operator{"HardSigmoid"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	, beta{beta_}
	{}
void HardSigmoidOp::inference() {
	ONNC_RUNTIME_hardsigmoid_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, alpha, beta);
}

IdentityOp::IdentityOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Identity"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void IdentityOp::inference() {
	ONNC_RUNTIME_identity_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

IfOp::IfOp(
	const element_type * input_cond_, dim_type input_cond_ndim_, const dim_type * input_cond_dims_, element_type * const * output_outputs_, dim_type output_outputs_ntensor_, const dim_type * output_outputs_ndim_, const dim_type * const * output_outputs_dims_, const void * else_branch_, const void * then_branch_
): Operator{"If"}
	, input_cond{input_cond_}
	, input_cond_ndim{input_cond_ndim_}
	, input_cond_dims{input_cond_dims_}
	, output_outputs{output_outputs_}
	, output_outputs_ntensor{output_outputs_ntensor_}
	, output_outputs_ndim{output_outputs_ndim_}
	, output_outputs_dims{output_outputs_dims_}
	, else_branch{else_branch_}
	, then_branch{then_branch_}
	{}
void IfOp::inference() {
	ONNC_RUNTIME_if_float(nullptr, input_cond, input_cond_ndim, input_cond_dims, output_outputs, output_outputs_ntensor, output_outputs_ndim, output_outputs_dims, else_branch, then_branch);
}

ImageScalerOp::ImageScalerOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type * bias_, dim_type number_of_bias_, element_type scale_
): Operator{"ImageScaler"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, bias{bias_}
	, number_of_bias{number_of_bias_}
	, scale{scale_}
	{}
void ImageScalerOp::inference() {
	ONNC_RUNTIME_imagescaler_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, bias, number_of_bias, scale);
}

InstanceNormalizationOp::InstanceNormalizationOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, const element_type * input_scale_, dim_type input_scale_ndim_, const dim_type * input_scale_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type epsilon_
): Operator{"InstanceNormalization"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, input_scale{input_scale_}
	, input_scale_ndim{input_scale_ndim_}
	, input_scale_dims{input_scale_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, epsilon{epsilon_}
	{}
void InstanceNormalizationOp::inference() {
	ONNC_RUNTIME_instancenormalization_float(nullptr, input_input, input_input_ndim, input_input_dims, input_scale, input_scale_ndim, input_scale_dims, input_B, input_B_ndim, input_B_dims, output_output, output_output_ndim, output_output_dims, epsilon);
}

LeakyReluOp::LeakyReluOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_
): Operator{"LeakyRelu"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	{}
void LeakyReluOp::inference() {
	ONNC_RUNTIME_leakyrelu_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, alpha);
}

LessOp::LessOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Less"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void LessOp::inference() {
	ONNC_RUNTIME_less_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

LogOp::LogOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Log"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void LogOp::inference() {
	ONNC_RUNTIME_log_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

LogSoftmaxOp::LogSoftmaxOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
): Operator{"LogSoftmax"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, axis{axis_}
	{}
void LogSoftmaxOp::inference() {
	ONNC_RUNTIME_logsoftmax_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, axis);
}

LoopOp::LoopOp(
	const element_type * input_M_, dim_type input_M_ndim_, const dim_type * input_M_dims_, const element_type * input_cond_, dim_type input_cond_ndim_, const dim_type * input_cond_dims_, const element_type * const * input_v_initial_, dim_type input_v_initial_ntensor_, const dim_type * input_v_initial_ndim_, const dim_type * const * input_v_initial_dims_, element_type * const * output_v_final_and_scan_outputs_, dim_type output_v_final_and_scan_outputs_ntensor_, const dim_type * output_v_final_and_scan_outputs_ndim_, const dim_type * const * output_v_final_and_scan_outputs_dims_, const void * body_
): Operator{"Loop"}
	, input_M{input_M_}
	, input_M_ndim{input_M_ndim_}
	, input_M_dims{input_M_dims_}
	, input_cond{input_cond_}
	, input_cond_ndim{input_cond_ndim_}
	, input_cond_dims{input_cond_dims_}
	, input_v_initial{input_v_initial_}
	, input_v_initial_ntensor{input_v_initial_ntensor_}
	, input_v_initial_ndim{input_v_initial_ndim_}
	, input_v_initial_dims{input_v_initial_dims_}
	, output_v_final_and_scan_outputs{output_v_final_and_scan_outputs_}
	, output_v_final_and_scan_outputs_ntensor{output_v_final_and_scan_outputs_ntensor_}
	, output_v_final_and_scan_outputs_ndim{output_v_final_and_scan_outputs_ndim_}
	, output_v_final_and_scan_outputs_dims{output_v_final_and_scan_outputs_dims_}
	, body{body_}
	{}
void LoopOp::inference() {
	ONNC_RUNTIME_loop_float(nullptr, input_M, input_M_ndim, input_M_dims, input_cond, input_cond_ndim, input_cond_dims, input_v_initial, input_v_initial_ntensor, input_v_initial_ndim, input_v_initial_dims, output_v_final_and_scan_outputs, output_v_final_and_scan_outputs_ntensor, output_v_final_and_scan_outputs_ndim, output_v_final_and_scan_outputs_dims, body);
}

LpNormalizationOp::LpNormalizationOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_, dim_type p_
): Operator{"LpNormalization"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, axis{axis_}
	, p{p_}
	{}
void LpNormalizationOp::inference() {
	ONNC_RUNTIME_lpnormalization_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, axis, p);
}

LpPoolOp::LpPoolOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * auto_pad_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type p_, dim_type * pads_, dim_type number_of_pads_, dim_type * strides_, dim_type number_of_strides_
): Operator{"LpPool"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, auto_pad{auto_pad_}
	, kernel_shape{kernel_shape_}
	, number_of_kernel_shape{number_of_kernel_shape_}
	, p{p_}
	, pads{pads_}
	, number_of_pads{number_of_pads_}
	, strides{strides_}
	, number_of_strides{number_of_strides_}
	{}
void LpPoolOp::inference() {
	ONNC_RUNTIME_lppool_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, auto_pad, kernel_shape, number_of_kernel_shape, p, pads, number_of_pads, strides, number_of_strides);
}

LRNOp::LRNOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_, element_type bias_, dim_type size_
): Operator{"LRN"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	, beta{beta_}
	, bias{bias_}
	, size{size_}
	{}
void LRNOp::inference() {
	ONNC_RUNTIME_lrn_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, alpha, beta, bias, size);
}

LSTMOp::LSTMOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_R_, dim_type input_R_ndim_, const dim_type * input_R_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_sequence_lens_, dim_type input_sequence_lens_ndim_, const dim_type * input_sequence_lens_dims_, const element_type * input_initial_h_, dim_type input_initial_h_ndim_, const dim_type * input_initial_h_dims_, const element_type * input_initial_c_, dim_type input_initial_c_ndim_, const dim_type * input_initial_c_dims_, const element_type * input_P_, dim_type input_P_ndim_, const dim_type * input_P_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_Y_h_, dim_type output_Y_h_ndim_, const dim_type * output_Y_h_dims_, element_type * output_Y_c_, dim_type output_Y_c_ndim_, const dim_type * output_Y_c_dims_, element_type * activation_alpha_, dim_type number_of_activation_alpha_, element_type * activation_beta_, dim_type number_of_activation_beta_, const char ** activations_, dim_type number_of_activations_, element_type clip_, const char * direction_, dim_type hidden_size_, dim_type input_forget_
): Operator{"LSTM"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_W{input_W_}
	, input_W_ndim{input_W_ndim_}
	, input_W_dims{input_W_dims_}
	, input_R{input_R_}
	, input_R_ndim{input_R_ndim_}
	, input_R_dims{input_R_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, input_sequence_lens{input_sequence_lens_}
	, input_sequence_lens_ndim{input_sequence_lens_ndim_}
	, input_sequence_lens_dims{input_sequence_lens_dims_}
	, input_initial_h{input_initial_h_}
	, input_initial_h_ndim{input_initial_h_ndim_}
	, input_initial_h_dims{input_initial_h_dims_}
	, input_initial_c{input_initial_c_}
	, input_initial_c_ndim{input_initial_c_ndim_}
	, input_initial_c_dims{input_initial_c_dims_}
	, input_P{input_P_}
	, input_P_ndim{input_P_ndim_}
	, input_P_dims{input_P_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, output_Y_h{output_Y_h_}
	, output_Y_h_ndim{output_Y_h_ndim_}
	, output_Y_h_dims{output_Y_h_dims_}
	, output_Y_c{output_Y_c_}
	, output_Y_c_ndim{output_Y_c_ndim_}
	, output_Y_c_dims{output_Y_c_dims_}
	, activation_alpha{activation_alpha_}
	, number_of_activation_alpha{number_of_activation_alpha_}
	, activation_beta{activation_beta_}
	, number_of_activation_beta{number_of_activation_beta_}
	, activations{activations_}
	, number_of_activations{number_of_activations_}
	, clip{clip_}
	, direction{direction_}
	, hidden_size{hidden_size_}
	, input_forget{input_forget_}
	{}
void LSTMOp::inference() {
	ONNC_RUNTIME_lstm_float(nullptr, input_X, input_X_ndim, input_X_dims, input_W, input_W_ndim, input_W_dims, input_R, input_R_ndim, input_R_dims, input_B, input_B_ndim, input_B_dims, input_sequence_lens, input_sequence_lens_ndim, input_sequence_lens_dims, input_initial_h, input_initial_h_ndim, input_initial_h_dims, input_initial_c, input_initial_c_ndim, input_initial_c_dims, input_P, input_P_ndim, input_P_dims, output_Y, output_Y_ndim, output_Y_dims, output_Y_h, output_Y_h_ndim, output_Y_h_dims, output_Y_c, output_Y_c_ndim, output_Y_c_dims, activation_alpha, number_of_activation_alpha, activation_beta, number_of_activation_beta, activations, number_of_activations, clip, direction, hidden_size, input_forget);
}

MatMulOp::MatMulOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"MatMul"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void MatMulOp::inference() {
	ONNC_RUNTIME_matmul_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_Y, output_Y_ndim, output_Y_dims);
}

MaxOp::MaxOp(
	const element_type * const * input_data_0_, dim_type input_data_0_ntensor_, const dim_type * input_data_0_ndim_, const dim_type * const * input_data_0_dims_, element_type * output_max_, dim_type output_max_ndim_, const dim_type * output_max_dims_
): Operator{"Max"}
	, input_data_0{input_data_0_}
	, input_data_0_ntensor{input_data_0_ntensor_}
	, input_data_0_ndim{input_data_0_ndim_}
	, input_data_0_dims{input_data_0_dims_}
	, output_max{output_max_}
	, output_max_ndim{output_max_ndim_}
	, output_max_dims{output_max_dims_}
	{}
void MaxOp::inference() {
	ONNC_RUNTIME_max_float(nullptr, input_data_0, input_data_0_ntensor, input_data_0_ndim, input_data_0_dims, output_max, output_max_ndim, output_max_dims);
}

MaxPoolOp::MaxPoolOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_Indices_, dim_type output_Indices_ndim_, const dim_type * output_Indices_dims_, const char * auto_pad_, dim_type * kernel_shape_, dim_type number_of_kernel_shape_, dim_type * pads_, dim_type number_of_pads_, dim_type storage_order_, dim_type * strides_, dim_type number_of_strides_
): Operator{"MaxPool"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, output_Indices{output_Indices_}
	, output_Indices_ndim{output_Indices_ndim_}
	, output_Indices_dims{output_Indices_dims_}
	, auto_pad{auto_pad_}
	, kernel_shape{kernel_shape_}
	, number_of_kernel_shape{number_of_kernel_shape_}
	, pads{pads_}
	, number_of_pads{number_of_pads_}
	, storage_order{storage_order_}
	, strides{strides_}
	, number_of_strides{number_of_strides_}
	{}
void MaxPoolOp::inference() {
	ONNC_RUNTIME_maxpool_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, output_Indices, output_Indices_ndim, output_Indices_dims, auto_pad, kernel_shape, number_of_kernel_shape, pads, number_of_pads, storage_order, strides, number_of_strides);
}

MaxRoiPoolOp::MaxRoiPoolOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_rois_, dim_type input_rois_ndim_, const dim_type * input_rois_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, dim_type * pooled_shape_, dim_type number_of_pooled_shape_, element_type spatial_scale_
): Operator{"MaxRoiPool"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_rois{input_rois_}
	, input_rois_ndim{input_rois_ndim_}
	, input_rois_dims{input_rois_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, pooled_shape{pooled_shape_}
	, number_of_pooled_shape{number_of_pooled_shape_}
	, spatial_scale{spatial_scale_}
	{}
void MaxRoiPoolOp::inference() {
	ONNC_RUNTIME_maxroipool_float(nullptr, input_X, input_X_ndim, input_X_dims, input_rois, input_rois_ndim, input_rois_dims, output_Y, output_Y_ndim, output_Y_dims, pooled_shape, number_of_pooled_shape, spatial_scale);
}

MeanOp::MeanOp(
	const element_type * const * input_data_0_, dim_type input_data_0_ntensor_, const dim_type * input_data_0_ndim_, const dim_type * const * input_data_0_dims_, element_type * output_mean_, dim_type output_mean_ndim_, const dim_type * output_mean_dims_
): Operator{"Mean"}
	, input_data_0{input_data_0_}
	, input_data_0_ntensor{input_data_0_ntensor_}
	, input_data_0_ndim{input_data_0_ndim_}
	, input_data_0_dims{input_data_0_dims_}
	, output_mean{output_mean_}
	, output_mean_ndim{output_mean_ndim_}
	, output_mean_dims{output_mean_dims_}
	{}
void MeanOp::inference() {
	ONNC_RUNTIME_mean_float(nullptr, input_data_0, input_data_0_ntensor, input_data_0_ndim, input_data_0_dims, output_mean, output_mean_ndim, output_mean_dims);
}

MeanVarianceNormalizationOp::MeanVarianceNormalizationOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type across_channels_, dim_type normalize_variance_
): Operator{"MeanVarianceNormalization"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, across_channels{across_channels_}
	, normalize_variance{normalize_variance_}
	{}
void MeanVarianceNormalizationOp::inference() {
	ONNC_RUNTIME_meanvariancenormalization_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, across_channels, normalize_variance);
}

MinOp::MinOp(
	const element_type * const * input_data_0_, dim_type input_data_0_ntensor_, const dim_type * input_data_0_ndim_, const dim_type * const * input_data_0_dims_, element_type * output_min_, dim_type output_min_ndim_, const dim_type * output_min_dims_
): Operator{"Min"}
	, input_data_0{input_data_0_}
	, input_data_0_ntensor{input_data_0_ntensor_}
	, input_data_0_ndim{input_data_0_ndim_}
	, input_data_0_dims{input_data_0_dims_}
	, output_min{output_min_}
	, output_min_ndim{output_min_ndim_}
	, output_min_dims{output_min_dims_}
	{}
void MinOp::inference() {
	ONNC_RUNTIME_min_float(nullptr, input_data_0, input_data_0_ntensor, input_data_0_ndim, input_data_0_dims, output_min, output_min_ndim, output_min_dims);
}

MulOp::MulOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Mul"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void MulOp::inference() {
	ONNC_RUNTIME_mul_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

MultinomialOp::MultinomialOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, dim_type sample_size_, element_type seed_
): Operator{"Multinomial"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, dtype{dtype_}
	, sample_size{sample_size_}
	, seed{seed_}
	{}
void MultinomialOp::inference() {
	ONNC_RUNTIME_multinomial_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, dtype, sample_size, seed);
}

NegOp::NegOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Neg"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void NegOp::inference() {
	ONNC_RUNTIME_neg_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

NotOp::NotOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Not"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void NotOp::inference() {
	ONNC_RUNTIME_not_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

OrOp::OrOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Or"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void OrOp::inference() {
	ONNC_RUNTIME_or_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

PadOp::PadOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, const char * mode_, dim_type * pads_, dim_type number_of_pads_, element_type value_
): Operator{"Pad"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, mode{mode_}
	, pads{pads_}
	, number_of_pads{number_of_pads_}
	, value{value_}
	{}
void PadOp::inference() {
	ONNC_RUNTIME_pad_float(nullptr, input_data, input_data_ndim, input_data_dims, output_output, output_output_ndim, output_output_dims, mode, pads, number_of_pads, value);
}

ParametricSoftplusOp::ParametricSoftplusOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type beta_
): Operator{"ParametricSoftplus"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	, beta{beta_}
	{}
void ParametricSoftplusOp::inference() {
	ONNC_RUNTIME_parametricsoftplus_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, alpha, beta);
}

PowOp::PowOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_Y_, dim_type input_Y_ndim_, const dim_type * input_Y_dims_, element_type * output_Z_, dim_type output_Z_ndim_, const dim_type * output_Z_dims_
): Operator{"Pow"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_Y{input_Y_}
	, input_Y_ndim{input_Y_ndim_}
	, input_Y_dims{input_Y_dims_}
	, output_Z{output_Z_}
	, output_Z_ndim{output_Z_ndim_}
	, output_Z_dims{output_Z_dims_}
	{}
void PowOp::inference() {
	ONNC_RUNTIME_pow_float(nullptr, input_X, input_X_ndim, input_X_dims, input_Y, input_Y_ndim, input_Y_dims, output_Z, output_Z_ndim, output_Z_dims);
}

PReluOp::PReluOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_slope_, dim_type input_slope_ndim_, const dim_type * input_slope_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"PRelu"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_slope{input_slope_}
	, input_slope_ndim{input_slope_ndim_}
	, input_slope_dims{input_slope_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void PReluOp::inference() {
	ONNC_RUNTIME_prelu_float(nullptr, input_X, input_X_ndim, input_X_dims, input_slope, input_slope_ndim, input_slope_dims, output_Y, output_Y_ndim, output_Y_dims);
}

RandomNormalOp::RandomNormalOp(
	element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, element_type mean_, element_type scale_, element_type seed_, dim_type * shape_, dim_type number_of_shape_
): Operator{"RandomNormal"}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, dtype{dtype_}
	, mean{mean_}
	, scale{scale_}
	, seed{seed_}
	, shape{shape_}
	, number_of_shape{number_of_shape_}
	{}
void RandomNormalOp::inference() {
	ONNC_RUNTIME_randomnormal_float(nullptr, output_output, output_output_ndim, output_output_dims, dtype, mean, scale, seed, shape, number_of_shape);
}

RandomNormalLikeOp::RandomNormalLikeOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, element_type mean_, element_type scale_, element_type seed_
): Operator{"RandomNormalLike"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, dtype{dtype_}
	, mean{mean_}
	, scale{scale_}
	, seed{seed_}
	{}
void RandomNormalLikeOp::inference() {
	ONNC_RUNTIME_randomnormallike_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, dtype, mean, scale, seed);
}

RandomUniformOp::RandomUniformOp(
	element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, element_type high_, element_type low_, element_type seed_, dim_type * shape_, dim_type number_of_shape_
): Operator{"RandomUniform"}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, dtype{dtype_}
	, high{high_}
	, low{low_}
	, seed{seed_}
	, shape{shape_}
	, number_of_shape{number_of_shape_}
	{}
void RandomUniformOp::inference() {
	ONNC_RUNTIME_randomuniform_float(nullptr, output_output, output_output_ndim, output_output_dims, dtype, high, low, seed, shape, number_of_shape);
}

RandomUniformLikeOp::RandomUniformLikeOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type dtype_, element_type high_, element_type low_, element_type seed_
): Operator{"RandomUniformLike"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, dtype{dtype_}
	, high{high_}
	, low{low_}
	, seed{seed_}
	{}
void RandomUniformLikeOp::inference() {
	ONNC_RUNTIME_randomuniformlike_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, dtype, high, low, seed);
}

ReciprocalOp::ReciprocalOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Reciprocal"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void ReciprocalOp::inference() {
	ONNC_RUNTIME_reciprocal_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

ReduceL1Op::ReduceL1Op(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceL1"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceL1Op::inference() {
	ONNC_RUNTIME_reducel1_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceL2Op::ReduceL2Op(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceL2"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceL2Op::inference() {
	ONNC_RUNTIME_reducel2_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceLogSumExpOp::ReduceLogSumExpOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceLogSumExp"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceLogSumExpOp::inference() {
	ONNC_RUNTIME_reducelogsumexp_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceLogSumOp::ReduceLogSumOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceLogSum"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceLogSumOp::inference() {
	ONNC_RUNTIME_reducelogsum_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceMaxOp::ReduceMaxOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceMax"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceMaxOp::inference() {
	ONNC_RUNTIME_reducemax_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceMeanOp::ReduceMeanOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceMean"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceMeanOp::inference() {
	ONNC_RUNTIME_reducemean_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceMinOp::ReduceMinOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceMin"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceMinOp::inference() {
	ONNC_RUNTIME_reducemin_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceProdOp::ReduceProdOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceProd"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceProdOp::inference() {
	ONNC_RUNTIME_reduceprod_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceSumOp::ReduceSumOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceSum"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceSumOp::inference() {
	ONNC_RUNTIME_reducesum_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReduceSumSquareOp::ReduceSumSquareOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_reduced_, dim_type output_reduced_ndim_, const dim_type * output_reduced_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type keepdims_
): Operator{"ReduceSumSquare"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_reduced{output_reduced_}
	, output_reduced_ndim{output_reduced_ndim_}
	, output_reduced_dims{output_reduced_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, keepdims{keepdims_}
	{}
void ReduceSumSquareOp::inference() {
	ONNC_RUNTIME_reducesumsquare_float(nullptr, input_data, input_data_ndim, input_data_dims, output_reduced, output_reduced_ndim, output_reduced_dims, axes, number_of_axes, keepdims);
}

ReluOp::ReluOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Relu"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void ReluOp::inference() {
	ONNC_RUNTIME_relu_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

ReshapeOp::ReshapeOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, const element_type * input_shape_, dim_type input_shape_ndim_, const dim_type * input_shape_dims_, element_type * output_reshaped_, dim_type output_reshaped_ndim_, const dim_type * output_reshaped_dims_
): Operator{"Reshape"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, input_shape{input_shape_}
	, input_shape_ndim{input_shape_ndim_}
	, input_shape_dims{input_shape_dims_}
	, output_reshaped{output_reshaped_}
	, output_reshaped_ndim{output_reshaped_ndim_}
	, output_reshaped_dims{output_reshaped_dims_}
	{}
void ReshapeOp::inference() {
	ONNC_RUNTIME_reshape_float(nullptr, input_data, input_data_ndim, input_data_dims, input_shape, input_shape_ndim, input_shape_dims, output_reshaped, output_reshaped_ndim, output_reshaped_dims);
}

RNNOp::RNNOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, const element_type * input_W_, dim_type input_W_ndim_, const dim_type * input_W_dims_, const element_type * input_R_, dim_type input_R_ndim_, const dim_type * input_R_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, const element_type * input_sequence_lens_, dim_type input_sequence_lens_ndim_, const dim_type * input_sequence_lens_dims_, const element_type * input_initial_h_, dim_type input_initial_h_ndim_, const dim_type * input_initial_h_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type * output_Y_h_, dim_type output_Y_h_ndim_, const dim_type * output_Y_h_dims_, element_type * activation_alpha_, dim_type number_of_activation_alpha_, element_type * activation_beta_, dim_type number_of_activation_beta_, const char ** activations_, dim_type number_of_activations_, element_type clip_, const char * direction_, dim_type hidden_size_
): Operator{"RNN"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, input_W{input_W_}
	, input_W_ndim{input_W_ndim_}
	, input_W_dims{input_W_dims_}
	, input_R{input_R_}
	, input_R_ndim{input_R_ndim_}
	, input_R_dims{input_R_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, input_sequence_lens{input_sequence_lens_}
	, input_sequence_lens_ndim{input_sequence_lens_ndim_}
	, input_sequence_lens_dims{input_sequence_lens_dims_}
	, input_initial_h{input_initial_h_}
	, input_initial_h_ndim{input_initial_h_ndim_}
	, input_initial_h_dims{input_initial_h_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, output_Y_h{output_Y_h_}
	, output_Y_h_ndim{output_Y_h_ndim_}
	, output_Y_h_dims{output_Y_h_dims_}
	, activation_alpha{activation_alpha_}
	, number_of_activation_alpha{number_of_activation_alpha_}
	, activation_beta{activation_beta_}
	, number_of_activation_beta{number_of_activation_beta_}
	, activations{activations_}
	, number_of_activations{number_of_activations_}
	, clip{clip_}
	, direction{direction_}
	, hidden_size{hidden_size_}
	{}
void RNNOp::inference() {
	ONNC_RUNTIME_rnn_float(nullptr, input_X, input_X_ndim, input_X_dims, input_W, input_W_ndim, input_W_dims, input_R, input_R_ndim, input_R_dims, input_B, input_B_ndim, input_B_dims, input_sequence_lens, input_sequence_lens_ndim, input_sequence_lens_dims, input_initial_h, input_initial_h_ndim, input_initial_h_dims, output_Y, output_Y_ndim, output_Y_dims, output_Y_h, output_Y_h_ndim, output_Y_h_dims, activation_alpha, number_of_activation_alpha, activation_beta, number_of_activation_beta, activations, number_of_activations, clip, direction, hidden_size);
}

ScaledTanhOp::ScaledTanhOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type alpha_, element_type beta_
): Operator{"ScaledTanh"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, alpha{alpha_}
	, beta{beta_}
	{}
void ScaledTanhOp::inference() {
	ONNC_RUNTIME_scaledtanh_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, alpha, beta);
}

ScaleOp::ScaleOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, element_type scale_
): Operator{"Scale"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, scale{scale_}
	{}
void ScaleOp::inference() {
	ONNC_RUNTIME_scale_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, scale);
}

ScanOp::ScanOp(
	const element_type * input_sequence_lens_, dim_type input_sequence_lens_ndim_, const dim_type * input_sequence_lens_dims_, const element_type * const * input_initial_state_and_scan_inputs_, dim_type input_initial_state_and_scan_inputs_ntensor_, const dim_type * input_initial_state_and_scan_inputs_ndim_, const dim_type * const * input_initial_state_and_scan_inputs_dims_, element_type * const * output_final_state_and_scan_outputs_, dim_type output_final_state_and_scan_outputs_ntensor_, const dim_type * output_final_state_and_scan_outputs_ndim_, const dim_type * const * output_final_state_and_scan_outputs_dims_, const void * body_, dim_type * directions_, dim_type number_of_directions_, dim_type num_scan_inputs_
): Operator{"Scan"}
	, input_sequence_lens{input_sequence_lens_}
	, input_sequence_lens_ndim{input_sequence_lens_ndim_}
	, input_sequence_lens_dims{input_sequence_lens_dims_}
	, input_initial_state_and_scan_inputs{input_initial_state_and_scan_inputs_}
	, input_initial_state_and_scan_inputs_ntensor{input_initial_state_and_scan_inputs_ntensor_}
	, input_initial_state_and_scan_inputs_ndim{input_initial_state_and_scan_inputs_ndim_}
	, input_initial_state_and_scan_inputs_dims{input_initial_state_and_scan_inputs_dims_}
	, output_final_state_and_scan_outputs{output_final_state_and_scan_outputs_}
	, output_final_state_and_scan_outputs_ntensor{output_final_state_and_scan_outputs_ntensor_}
	, output_final_state_and_scan_outputs_ndim{output_final_state_and_scan_outputs_ndim_}
	, output_final_state_and_scan_outputs_dims{output_final_state_and_scan_outputs_dims_}
	, body{body_}
	, directions{directions_}
	, number_of_directions{number_of_directions_}
	, num_scan_inputs{num_scan_inputs_}
	{}
void ScanOp::inference() {
	ONNC_RUNTIME_scan_float(nullptr, input_sequence_lens, input_sequence_lens_ndim, input_sequence_lens_dims, input_initial_state_and_scan_inputs, input_initial_state_and_scan_inputs_ntensor, input_initial_state_and_scan_inputs_ndim, input_initial_state_and_scan_inputs_dims, output_final_state_and_scan_outputs, output_final_state_and_scan_outputs_ntensor, output_final_state_and_scan_outputs_ndim, output_final_state_and_scan_outputs_dims, body, directions, number_of_directions, num_scan_inputs);
}

SeluOp::SeluOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_, element_type gamma_
): Operator{"Selu"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	, gamma{gamma_}
	{}
void SeluOp::inference() {
	ONNC_RUNTIME_selu_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, alpha, gamma);
}

ShapeOp::ShapeOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_shape_, dim_type output_shape_ndim_, const dim_type * output_shape_dims_
): Operator{"Shape"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_shape{output_shape_}
	, output_shape_ndim{output_shape_ndim_}
	, output_shape_dims{output_shape_dims_}
	{}
void ShapeOp::inference() {
	ONNC_RUNTIME_shape_float(nullptr, input_data, input_data_ndim, input_data_dims, output_shape, output_shape_ndim, output_shape_dims);
}

SigmoidOp::SigmoidOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Sigmoid"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void SigmoidOp::inference() {
	ONNC_RUNTIME_sigmoid_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

SinOp::SinOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Sin"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void SinOp::inference() {
	ONNC_RUNTIME_sin_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

SizeOp::SizeOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_size_, dim_type output_size_ndim_, const dim_type * output_size_dims_
): Operator{"Size"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_size{output_size_}
	, output_size_ndim{output_size_ndim_}
	, output_size_dims{output_size_dims_}
	{}
void SizeOp::inference() {
	ONNC_RUNTIME_size_float(nullptr, input_data, input_data_ndim, input_data_dims, output_size, output_size_ndim, output_size_dims);
}

SliceOp::SliceOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type * axes_, dim_type number_of_axes_, dim_type * ends_, dim_type number_of_ends_, dim_type * starts_, dim_type number_of_starts_
): Operator{"Slice"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	, ends{ends_}
	, number_of_ends{number_of_ends_}
	, starts{starts_}
	, number_of_starts{number_of_starts_}
	{}
void SliceOp::inference() {
	ONNC_RUNTIME_slice_float(nullptr, input_data, input_data_ndim, input_data_dims, output_output, output_output_ndim, output_output_dims, axes, number_of_axes, ends, number_of_ends, starts, number_of_starts);
}

SoftmaxOp::SoftmaxOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type axis_
): Operator{"Softmax"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, axis{axis_}
	{}
void SoftmaxOp::inference() {
	ONNC_RUNTIME_softmax_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, axis);
}

SoftplusOp::SoftplusOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Softplus"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void SoftplusOp::inference() {
	ONNC_RUNTIME_softplus_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

SoftsignOp::SoftsignOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Softsign"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void SoftsignOp::inference() {
	ONNC_RUNTIME_softsign_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

SpaceToDepthOp::SpaceToDepthOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_, dim_type blocksize_
): Operator{"SpaceToDepth"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	, blocksize{blocksize_}
	{}
void SpaceToDepthOp::inference() {
	ONNC_RUNTIME_spacetodepth_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims, blocksize);
}

SplitOp::SplitOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * const * output_outputs_, dim_type output_outputs_ntensor_, const dim_type * output_outputs_ndim_, const dim_type * const * output_outputs_dims_, dim_type axis_, dim_type * split_, dim_type number_of_split_
): Operator{"Split"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_outputs{output_outputs_}
	, output_outputs_ntensor{output_outputs_ntensor_}
	, output_outputs_ndim{output_outputs_ndim_}
	, output_outputs_dims{output_outputs_dims_}
	, axis{axis_}
	, split{split_}
	, number_of_split{number_of_split_}
	{}
void SplitOp::inference() {
	ONNC_RUNTIME_split_float(nullptr, input_input, input_input_ndim, input_input_dims, output_outputs, output_outputs_ntensor, output_outputs_ndim, output_outputs_dims, axis, split, number_of_split);
}

SqrtOp::SqrtOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_
): Operator{"Sqrt"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	{}
void SqrtOp::inference() {
	ONNC_RUNTIME_sqrt_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims);
}

SqueezeOp::SqueezeOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_squeezed_, dim_type output_squeezed_ndim_, const dim_type * output_squeezed_dims_, dim_type * axes_, dim_type number_of_axes_
): Operator{"Squeeze"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_squeezed{output_squeezed_}
	, output_squeezed_ndim{output_squeezed_ndim_}
	, output_squeezed_dims{output_squeezed_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	{}
void SqueezeOp::inference() {
	ONNC_RUNTIME_squeeze_float(nullptr, input_data, input_data_ndim, input_data_dims, output_squeezed, output_squeezed_ndim, output_squeezed_dims, axes, number_of_axes);
}

SubOp::SubOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Sub"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void SubOp::inference() {
	ONNC_RUNTIME_sub_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}

SumOp::SumOp(
	const element_type * const * input_data_0_, dim_type input_data_0_ntensor_, const dim_type * input_data_0_ndim_, const dim_type * const * input_data_0_dims_, element_type * output_sum_, dim_type output_sum_ndim_, const dim_type * output_sum_dims_
): Operator{"Sum"}
	, input_data_0{input_data_0_}
	, input_data_0_ntensor{input_data_0_ntensor_}
	, input_data_0_ndim{input_data_0_ndim_}
	, input_data_0_dims{input_data_0_dims_}
	, output_sum{output_sum_}
	, output_sum_ndim{output_sum_ndim_}
	, output_sum_dims{output_sum_dims_}
	{}
void SumOp::inference() {
	ONNC_RUNTIME_sum_float(nullptr, input_data_0, input_data_0_ntensor, input_data_0_ndim, input_data_0_dims, output_sum, output_sum_ndim, output_sum_dims);
}

TanOp::TanOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Tan"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void TanOp::inference() {
	ONNC_RUNTIME_tan_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

TanhOp::TanhOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Tanh"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void TanhOp::inference() {
	ONNC_RUNTIME_tanh_float(nullptr, input_input, input_input_ndim, input_input_dims, output_output, output_output_ndim, output_output_dims);
}

ThresholdedReluOp::ThresholdedReluOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, element_type alpha_
): Operator{"ThresholdedRelu"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, alpha{alpha_}
	{}
void ThresholdedReluOp::inference() {
	ONNC_RUNTIME_thresholdedrelu_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, alpha);
}

TileOp::TileOp(
	const element_type * input_input_, dim_type input_input_ndim_, const dim_type * input_input_dims_, const element_type * input_repeats_, dim_type input_repeats_ndim_, const dim_type * input_repeats_dims_, element_type * output_output_, dim_type output_output_ndim_, const dim_type * output_output_dims_
): Operator{"Tile"}
	, input_input{input_input_}
	, input_input_ndim{input_input_ndim_}
	, input_input_dims{input_input_dims_}
	, input_repeats{input_repeats_}
	, input_repeats_ndim{input_repeats_ndim_}
	, input_repeats_dims{input_repeats_dims_}
	, output_output{output_output_}
	, output_output_ndim{output_output_ndim_}
	, output_output_dims{output_output_dims_}
	{}
void TileOp::inference() {
	ONNC_RUNTIME_tile_float(nullptr, input_input, input_input_ndim, input_input_dims, input_repeats, input_repeats_ndim, input_repeats_dims, output_output, output_output_ndim, output_output_dims);
}

TopKOp::TopKOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Values_, dim_type output_Values_ndim_, const dim_type * output_Values_dims_, element_type * output_Indices_, dim_type output_Indices_ndim_, const dim_type * output_Indices_dims_, dim_type axis_, dim_type k_
): Operator{"TopK"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Values{output_Values_}
	, output_Values_ndim{output_Values_ndim_}
	, output_Values_dims{output_Values_dims_}
	, output_Indices{output_Indices_}
	, output_Indices_ndim{output_Indices_ndim_}
	, output_Indices_dims{output_Indices_dims_}
	, axis{axis_}
	, k{k_}
	{}
void TopKOp::inference() {
	ONNC_RUNTIME_topk_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Values, output_Values_ndim, output_Values_dims, output_Indices, output_Indices_ndim, output_Indices_dims, axis, k);
}

TransposeOp::TransposeOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_transposed_, dim_type output_transposed_ndim_, const dim_type * output_transposed_dims_, dim_type * perm_, dim_type number_of_perm_
): Operator{"Transpose"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_transposed{output_transposed_}
	, output_transposed_ndim{output_transposed_ndim_}
	, output_transposed_dims{output_transposed_dims_}
	, perm{perm_}
	, number_of_perm{number_of_perm_}
	{}
void TransposeOp::inference() {
	ONNC_RUNTIME_transpose_float(nullptr, input_data, input_data_ndim, input_data_dims, output_transposed, output_transposed_ndim, output_transposed_dims, perm, number_of_perm);
}

UnsqueezeOp::UnsqueezeOp(
	const element_type * input_data_, dim_type input_data_ndim_, const dim_type * input_data_dims_, element_type * output_expanded_, dim_type output_expanded_ndim_, const dim_type * output_expanded_dims_, dim_type * axes_, dim_type number_of_axes_
): Operator{"Unsqueeze"}
	, input_data{input_data_}
	, input_data_ndim{input_data_ndim_}
	, input_data_dims{input_data_dims_}
	, output_expanded{output_expanded_}
	, output_expanded_ndim{output_expanded_ndim_}
	, output_expanded_dims{output_expanded_dims_}
	, axes{axes_}
	, number_of_axes{number_of_axes_}
	{}
void UnsqueezeOp::inference() {
	ONNC_RUNTIME_unsqueeze_float(nullptr, input_data, input_data_ndim, input_data_dims, output_expanded, output_expanded_ndim, output_expanded_dims, axes, number_of_axes);
}

UpsampleOp::UpsampleOp(
	const element_type * input_X_, dim_type input_X_ndim_, const dim_type * input_X_dims_, element_type * output_Y_, dim_type output_Y_ndim_, const dim_type * output_Y_dims_, const char * mode_, element_type * scales_, dim_type number_of_scales_
): Operator{"Upsample"}
	, input_X{input_X_}
	, input_X_ndim{input_X_ndim_}
	, input_X_dims{input_X_dims_}
	, output_Y{output_Y_}
	, output_Y_ndim{output_Y_ndim_}
	, output_Y_dims{output_Y_dims_}
	, mode{mode_}
	, scales{scales_}
	, number_of_scales{number_of_scales_}
	{}
void UpsampleOp::inference() {
	ONNC_RUNTIME_upsample_float(nullptr, input_X, input_X_ndim, input_X_dims, output_Y, output_Y_ndim, output_Y_dims, mode, scales, number_of_scales);
}

XorOp::XorOp(
	const element_type * input_A_, dim_type input_A_ndim_, const dim_type * input_A_dims_, const element_type * input_B_, dim_type input_B_ndim_, const dim_type * input_B_dims_, element_type * output_C_, dim_type output_C_ndim_, const dim_type * output_C_dims_
): Operator{"Xor"}
	, input_A{input_A_}
	, input_A_ndim{input_A_ndim_}
	, input_A_dims{input_A_dims_}
	, input_B{input_B_}
	, input_B_ndim{input_B_ndim_}
	, input_B_dims{input_B_dims_}
	, output_C{output_C_}
	, output_C_ndim{output_C_ndim_}
	, output_C_dims{output_C_dims_}
	{}
void XorOp::inference() {
	ONNC_RUNTIME_xor_float(nullptr, input_A, input_A_ndim, input_A_dims, input_B, input_B_ndim, input_B_dims, output_C, output_C_ndim, output_C_dims);
}


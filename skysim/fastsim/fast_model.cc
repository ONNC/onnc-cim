#include "fastsim/fast_model.hh"

typedef int32_t ONNC_INDEX_TYPE;
#ifdef __cplusplus
#define restrict __restrict__
extern "C" {
#endif

#include <onnc-runtime.h>

#ifdef __cplusplus
}
#endif
#undef restrict

const std::string FastModel::dump_extension{".out"};

void FastModel::dump_output_tensor(reg_type start_, reg_type ndim_, reg_type dims_, reg_type tensorname_) {
	address_type start = (address_type)start_;
	size_t ndim = (size_t)ndim_;
	int32_t *dims = (int32_t*)(memory->pointer_at(dims_));
	const char *tensorname = (char*)(memory->pointer_at(tensorname_));

	size_type len=sizeof(float);
	for(unsigned int i=0; i<ndim; i++)
		len *= dims[i];

	std::ofstream output_file(tensorname + dump_extension, std::ios::binary);
	memory->dump(start, len, output_file, true);
	output_file.close();
}

template<typename T>
T** FastModel::get_multiple_tensor_info(address_type *addrs, size_t ntensor) {
	// Caller is responsible for freeing.
	T **tensors = new T*[ntensor];
	for(uint32_t i=0; i<ntensor; i++)
		tensors[i] = static_cast<T*>(memory->pointer_at(static_cast<address_type>(addrs[i])));
	return tensors;
}

void FastModel::on_set_launch_add(reg_type data) {
	ONNC_RUNTIME_add_float(nullptr,
			(float*)(memory->pointer_at(add_input_a)),
			(int32_t)add_input_a_ndim,
			(int32_t*)(memory->pointer_at(add_input_a_dims)),
			(float*)(memory->pointer_at(add_input_b)),
			(int32_t)add_input_b_ndim,
			(int32_t*)(memory->pointer_at(add_input_b_dims)),
			(float*)(memory->pointer_at(add_output_c)),
			(int32_t)add_output_c_ndim,
			(int32_t*)(memory->pointer_at(add_output_c_dims))
			);

	dump_output_tensor(add_output_c, add_output_c_ndim, add_output_c_dims, add_tensor_name);
}

void FastModel::on_set_launch_averagepool(reg_type data) {
	ONNC_RUNTIME_averagepool_float(nullptr,
			(float*)(memory->pointer_at(averagepool_input_x)),
			(int32_t)averagepool_input_x_ndim,
			(int32_t*)(memory->pointer_at(averagepool_input_x_dims)),
			(float*)(memory->pointer_at(averagepool_output_y)),
			(int32_t)averagepool_output_y_ndim,
			(int32_t*)(memory->pointer_at(averagepool_output_y_dims)),
			(char*)(memory->pointer_at(averagepool_auto_pad)),
			(int32_t)averagepool_count_include_pad,
			(int32_t*)(memory->pointer_at(averagepool_kernel_shape)),
			(int32_t)averagepool_number_of_kernel_shape,
			(int32_t*)(memory->pointer_at(averagepool_pads)),
			(int32_t)averagepool_number_of_pads,
			(int32_t*)(memory->pointer_at(averagepool_strides)),
			(int32_t)averagepool_number_of_strides
			);
	dump_output_tensor(averagepool_output_y, averagepool_output_y_ndim, averagepool_output_y_dims, averagepool_tensor_name);
}

void FastModel::on_set_launch_batchnormalization(reg_type data) {
	ONNC_RUNTIME_batchnormalization_float(nullptr,
			(float*)(memory->pointer_at(batchnormalization_input_x)),
			(int32_t)batchnormalization_input_x_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_input_x_dims)),
			(float*)(memory->pointer_at(batchnormalization_input_scale)),
			(int32_t)batchnormalization_input_scale_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_input_scale_dims)),
			(float*)(memory->pointer_at(batchnormalization_input_b)),
			(int32_t)batchnormalization_input_b_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_input_b_dims)),
			(float*)(memory->pointer_at(batchnormalization_input_mean)),
			(int32_t)batchnormalization_input_mean_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_input_mean_dims)),
			(float*)(memory->pointer_at(batchnormalization_input_var)),
			(int32_t)batchnormalization_input_var_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_input_var_dims)),
			(float*)(memory->pointer_at(batchnormalization_output_y)),
			(int32_t)batchnormalization_output_y_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_output_y_dims)),
			(float*)(memory->pointer_at(batchnormalization_output_mean)),
			(int32_t)batchnormalization_output_mean_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_output_mean_dims)),
			(float*)(memory->pointer_at(batchnormalization_output_var)),
			(int32_t)batchnormalization_output_var_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_output_var_dims)),
			(float*)(memory->pointer_at(batchnormalization_output_saved_mean)),
			(int32_t)batchnormalization_output_saved_mean_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_output_saved_mean_dims)),
			(float*)(memory->pointer_at(batchnormalization_output_saved_var)),
			(int32_t)batchnormalization_output_saved_var_ndim,
			(int32_t*)(memory->pointer_at(batchnormalization_output_saved_var_dims)),
			*(float*)&batchnormalization_epsilon,
			*(float*)&batchnormalization_momentum,
			(int32_t)batchnormalization_spatial
				);
	dump_output_tensor(batchnormalization_output_y, batchnormalization_output_y_ndim, batchnormalization_output_y_dims, batchnormalization_tensor_name);
}

void FastModel::on_set_launch_concat(reg_type data) {
	float **inputs = get_multiple_tensor_info<float>(static_cast<address_type*>(memory->pointer_at(concat_input_inputs))
			, static_cast<size_t>(concat_input_inputs_ntensor));
	int32_t **dims = get_multiple_tensor_info<int32_t>(static_cast<address_type*>(memory->pointer_at(concat_input_inputs_dims))
			, static_cast<size_t>(concat_input_inputs_ntensor));
	ONNC_RUNTIME_concat_float(nullptr,
			inputs,
			(int32_t)concat_input_inputs_ntensor,
			(int32_t*)(memory->pointer_at(concat_input_inputs_ndim)),
			dims,
			(float*)(memory->pointer_at(concat_output_concat_result)),
			(int32_t)concat_output_concat_result_ndim,
			(int32_t*)(memory->pointer_at(concat_output_concat_result_dims)),
			(int32_t)concat_axis
			);
	dump_output_tensor(concat_output_concat_result, concat_output_concat_result_ndim, concat_output_concat_result_dims, concat_tensor_name);
	delete []dims;
	delete []inputs;
}

void FastModel::on_set_launch_conv(reg_type data) {
	ONNC_RUNTIME_conv_float(nullptr,
			(float*)(memory->pointer_at(conv_input_x)),
			(int32_t)conv_input_x_ndim,
			(int32_t*)(memory->pointer_at(conv_input_x_dims)),
			(float*)(memory->pointer_at(conv_input_w)),
			(int32_t)conv_input_w_ndim,
			(int32_t*)(memory->pointer_at(conv_input_w_dims)),
			(float*)(memory->pointer_at(conv_input_b)),
			(int32_t)conv_input_b_ndim,
			(int32_t*)(memory->pointer_at(conv_input_b_dims)),
			(float*)(memory->pointer_at(conv_output_y)),
			(int32_t)conv_output_y_ndim,
			(int32_t*)(memory->pointer_at(conv_output_y_dims)),
			(char*)(memory->pointer_at(conv_auto_pad)),
			(int32_t*)(memory->pointer_at(conv_dilations)),
			(int32_t)conv_number_of_dilations,
			(int32_t)conv_group,
			(int32_t*)(memory->pointer_at(conv_kernel_shape)),
			(int32_t)conv_number_of_kernel_shape,
			(int32_t*)(memory->pointer_at(conv_pads)),
			(int32_t)conv_number_of_pads,
			(int32_t*)(memory->pointer_at(conv_strides)),
			(int32_t)conv_number_of_strides
				);
	dump_output_tensor(conv_output_y, conv_output_y_ndim, conv_output_y_dims, conv_tensor_name);
}

void FastModel::on_set_launch_gemm(reg_type data) {
	ONNC_RUNTIME_gemm_float(nullptr,
			(float*)(memory->pointer_at(gemm_input_a)),
			(int32_t)gemm_input_a_ndim,
			(int32_t*)(memory->pointer_at(gemm_input_a_dims)),
			(float*)(memory->pointer_at(gemm_input_b)),
			(int32_t)gemm_input_b_ndim,
			(int32_t*)(memory->pointer_at(gemm_input_b_dims)),
			(float*)(memory->pointer_at(gemm_input_c)),
			(int32_t)gemm_input_c_ndim,
			(int32_t*)(memory->pointer_at(gemm_input_c_dims)),
			(float*)(memory->pointer_at(gemm_output_y)),
			(int32_t)gemm_output_y_ndim,
			(int32_t*)(memory->pointer_at(gemm_output_y_dims)),
			*(float*)&gemm_alpha,
			*(float*)&gemm_beta,
			(int32_t)gemm_transa,
			(int32_t)gemm_transb
			);
	dump_output_tensor(gemm_output_y, gemm_output_y_ndim, gemm_output_y_dims, gemm_tensor_name);
}

void FastModel::on_set_launch_globalaveragepool(reg_type data) {
	ONNC_RUNTIME_globalaveragepool_float(nullptr,
			(float*)(memory->pointer_at(globalaveragepool_input_x)),
			(int32_t)globalaveragepool_input_x_ndim,
			(int32_t*)(memory->pointer_at(globalaveragepool_input_x_dims)),
			(float*)(memory->pointer_at(globalaveragepool_output_y)),
			(int32_t)globalaveragepool_output_y_ndim,
			(int32_t*)(memory->pointer_at(globalaveragepool_output_y_dims))
			);
	dump_output_tensor(globalaveragepool_output_y, globalaveragepool_output_y_ndim, globalaveragepool_output_y_dims, globalaveragepool_tensor_name);
}

void FastModel::on_set_launch_lrn(reg_type data) {
	ONNC_RUNTIME_lrn_float(nullptr,
			(float*)(memory->pointer_at(lrn_input_x)),
			(int32_t)lrn_input_x_ndim,
			(int32_t*)(memory->pointer_at(lrn_input_x_dims)),
			(float*)(memory->pointer_at(lrn_output_y)),
			(int32_t)lrn_output_y_ndim,
			(int32_t*)(memory->pointer_at(lrn_output_y_dims)),
			*(float*)&lrn_alpha,
			*(float*)&lrn_beta,
			*(float*)&lrn_bias,
			(int32_t)lrn_size
			);
	dump_output_tensor(lrn_output_y, lrn_output_y_ndim, lrn_output_y_dims, lrn_tensor_name);
}

void FastModel::on_set_launch_maxpool(reg_type data) {
	ONNC_RUNTIME_maxpool_float(nullptr,
			(float*)(memory->pointer_at(maxpool_input_x)),
			(int32_t)maxpool_input_x_ndim,
			(int32_t*)(memory->pointer_at(maxpool_input_x_dims)),
			(float*)(memory->pointer_at(maxpool_output_y)),
			(int32_t)maxpool_output_y_ndim,
			(int32_t*)(memory->pointer_at(maxpool_output_y_dims)),
			(float*)(memory->pointer_at(maxpool_output_indices)),
			(int32_t)maxpool_output_indices_ndim,
			(int32_t*)(memory->pointer_at(maxpool_output_indices_dims)),
			(char*)(memory->pointer_at(maxpool_auto_pad)),
			(int32_t*)(memory->pointer_at(maxpool_kernel_shape)),
			(int32_t)maxpool_number_of_kernel_shape,
			(int32_t*)(memory->pointer_at(maxpool_pads)),
			(int32_t)maxpool_number_of_pads,
			(int32_t)maxpool_storage_order,
			(int32_t*)(memory->pointer_at(maxpool_strides)),
			(int32_t)maxpool_number_of_strides
			);
	dump_output_tensor(maxpool_output_y, maxpool_output_y_ndim, maxpool_output_y_dims, maxpool_tensor_name);
}

void FastModel::on_set_launch_mul(reg_type data) {
	ONNC_RUNTIME_mul_float(nullptr,
			(float*)(memory->pointer_at(mul_input_a)),
			(int32_t)mul_input_a_ndim,
			(int32_t*)(memory->pointer_at(mul_input_a_dims)),
			(float*)(memory->pointer_at(mul_input_b)),
			(int32_t)mul_input_b_ndim,
			(int32_t*)(memory->pointer_at(mul_input_b_dims)),
			(float*)(memory->pointer_at(mul_output_c)),
			(int32_t)mul_output_c_ndim,
			(int32_t*)(memory->pointer_at(mul_output_c_dims))
			);
	dump_output_tensor(mul_output_c, mul_output_c_ndim, mul_output_c_dims, mul_tensor_name);
}

void FastModel::on_set_launch_relu(reg_type data) {
	ONNC_RUNTIME_relu_float(nullptr,
			(float*)(memory->pointer_at(relu_input_x)),
			(int32_t)relu_input_x_ndim,
			(int32_t*)(memory->pointer_at(relu_input_x_dims)),
			(float*)(memory->pointer_at(relu_output_y)),
			(int32_t)relu_output_y_ndim,
			(int32_t*)(memory->pointer_at(relu_output_y_dims))
			);
	dump_output_tensor(relu_output_y, relu_output_y_ndim, relu_output_y_dims, relu_tensor_name);
}

void FastModel::on_set_launch_reshape(reg_type data) {
	ONNC_RUNTIME_reshape_float(nullptr,
			(float*)(memory->pointer_at(reshape_input_data)),
			(int32_t)reshape_input_data_ndim,
			(int32_t*)(memory->pointer_at(reshape_input_data_dims)),
			(float*)(memory->pointer_at(reshape_input_shape)),
			(int32_t)reshape_input_shape_ndim,
			(int32_t*)(memory->pointer_at(reshape_input_shape_dims)),
			(float*)(memory->pointer_at(reshape_output_reshaped)),
			(int32_t)reshape_output_reshaped_ndim,
			(int32_t*)(memory->pointer_at(reshape_output_reshaped_dims))
			);
	dump_output_tensor(reshape_output_reshaped, reshape_output_reshaped_ndim, reshape_output_reshaped_dims, reshape_tensor_name);
}

void FastModel::on_set_launch_softmax(reg_type data) {
	ONNC_RUNTIME_softmax_float(nullptr,
			(float*)(memory->pointer_at(softmax_input_input)),
			(int32_t)softmax_input_input_ndim,
			(int32_t*)(memory->pointer_at(softmax_input_input_dims)),
			(float*)(memory->pointer_at(softmax_output_output)),
			(int32_t)softmax_output_output_ndim,
			(int32_t*)(memory->pointer_at(softmax_output_output_dims)),
			(int32_t)softmax_axis
			);
	dump_output_tensor(softmax_output_output, softmax_output_output_ndim, softmax_output_output_dims, softmax_tensor_name);
}

void FastModel::on_set_launch_sum(reg_type data) {
	float **inputs = get_multiple_tensor_info<float>(static_cast<address_type*>(memory->pointer_at(sum_input_data_0))
			, static_cast<size_t>(sum_input_data_0_ntensor));
	int32_t **dims = get_multiple_tensor_info<int32_t>(static_cast<address_type*>(memory->pointer_at(sum_input_data_0_dims))
			, static_cast<size_t>(sum_input_data_0_ntensor));
	ONNC_RUNTIME_sum_float(nullptr,
			inputs,
			(int32_t)sum_input_data_0_ntensor,
			(int32_t*)(memory->pointer_at(sum_input_data_0_ndim)),
			dims,
			(float*)(memory->pointer_at(sum_output_sum)),
			(int32_t)sum_output_sum_ndim,
			(int32_t*)(memory->pointer_at(sum_output_sum_dims))
			);
	dump_output_tensor(sum_output_sum, sum_output_sum_ndim, sum_output_sum_dims, sum_tensor_name);
	delete []dims;
	delete []inputs;
}

void FastModel::on_set_launch_transpose(reg_type data) {
	ONNC_RUNTIME_transpose_float(nullptr,
			(float*)(memory->pointer_at(transpose_input_data)),
			(int32_t)transpose_input_data_ndim,
			(int32_t*)(memory->pointer_at(transpose_input_data_dims)),
			(float*)(memory->pointer_at(transpose_output_transposed)),
			(int32_t)transpose_output_transposed_ndim,
			(int32_t*)(memory->pointer_at(transpose_output_transposed_dims)),
			(int32_t*)(memory->pointer_at(transpose_perm)),
			(int32_t)transpose_number_of_perm
			);
	dump_output_tensor(transpose_output_transposed, transpose_output_transposed_ndim, transpose_output_transposed_dims, transpose_tensor_name);
}

void FastModel::on_set_launch_unsqueeze(reg_type data) {
	ONNC_RUNTIME_unsqueeze_float(nullptr,
			(float*)(memory->pointer_at(unsqueeze_input_data)),
			(int32_t)unsqueeze_input_data_ndim,
			(int32_t*)(memory->pointer_at(unsqueeze_input_data_dims)),
			(float*)(memory->pointer_at(unsqueeze_output_expanded)),
			(int32_t)unsqueeze_output_expanded_ndim,
			(int32_t*)(memory->pointer_at(unsqueeze_output_expanded_dims)),
			(int32_t*)(memory->pointer_at(unsqueeze_axes)),
			(int32_t)unsqueeze_number_of_axes
			);
	dump_output_tensor(unsqueeze_output_expanded, unsqueeze_output_expanded_ndim, unsqueeze_output_expanded_dims, unsqueeze_tensor_name);
}

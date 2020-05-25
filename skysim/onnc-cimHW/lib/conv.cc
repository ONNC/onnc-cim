//===- conv.cc ------------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "conv.hh"
#include "diagnostic/msgHandling.hh"
#include <Eigen/Dense>

namespace cimHW {

enum class AutoPadType {
  NOTSET = 0,
  VALID = 1,
  SAME_UPPER = 2,
  SAME_LOWER = 3,
};

inline AutoPadType StringToAutoPadType(const std::string& str) {
  if (str == "NOTSET") {  // in onnx spec, default value is "NOTSET"
    return AutoPadType::NOTSET;
  }
  if (str == "VALID") {
    return AutoPadType::VALID;
  }
  if (str == "SAME_UPPER") {
    return AutoPadType::SAME_UPPER;
  }
  if (str == "SAME_LOWER") {
    return AutoPadType::SAME_LOWER;
  }
  // default, use NOTSET
  return AutoPadType::NOTSET;
}

dim_type computePadAndOutputShape(
    const int in_dim,
    const int kernel,
    const int stride,
    const int dilation,
    AutoPadType pad_type,
    int* pad_head,
    int* pad_tail)
{
  const int dkernel = dilation * (kernel - 1) + 1;
  int out_dim = 0;
  if (pad_type == AutoPadType::NOTSET)
  {
    out_dim = static_cast<int>(static_cast<float>(in_dim + *pad_head + *pad_tail - dkernel) / stride + 1);
  }
  else
  {
    switch (pad_type) {
      // VALID is nopad
      case AutoPadType::VALID:
        *pad_head = 0;
        *pad_tail = 0;
        out_dim = (in_dim - dkernel) / stride + 1;
        break;
      case AutoPadType::SAME_UPPER:
      case AutoPadType::SAME_LOWER:
      {
        assert(dilation == 1 && "Dilation not supported for AutoPadType::SAME_UPPER or AutoPadType::SAME_LOWER.");
        int legacy_target_size = (in_dim + stride - 1) / stride;
        int pad_needed = (legacy_target_size - 1) * stride + kernel - in_dim;
        out_dim = (in_dim + pad_needed - dkernel) / stride + 1;

        // pad the extra to the end if SAME_UPPER, or to the begining if SAME_LOWER
        *pad_head = (pad_type == AutoPadType::SAME_LOWER)? (pad_needed + 1) / 2 : pad_needed / 2;
        *pad_tail = pad_needed - *pad_head;
      }
      break;
      default:
        assert(false && "pad type not supported.");
    }
  }
  return out_dim;
}

// fetch all posible data cubes (along with kernel height and width) used to do matmul with kernel matrix
void im2col(const float *data_im, const int channels, const int height, const int width,
            const int kernel_h, const int kernel_w,
            const int pad_t, const int pad_b,
            const int pad_l, const int pad_r,
            const int stride_h, const int stride_w,
            const int dilation_h, const int dilation_w,
            float *data_col)
{
  auto is_a_ge_zero_and_a_lt_b = [](int a, int b) { return static_cast<unsigned>(a) < static_cast<unsigned>(b); };
  auto get_conv_output_size = [](const int intput_size,
                                 const int kernel_size,
                                 const int pad_begin,
                                 const int pad_end,
                                 const int stride_step,
                                 const int dilation_rate)
  {
    return (intput_size + pad_begin + pad_end - (dilation_rate * (kernel_size - 1) + 1)) / stride_step + 1;
  };

  const int output_h = get_conv_output_size(height, kernel_h, pad_t, pad_b, stride_h, dilation_h);
  const int output_w = get_conv_output_size(width, kernel_w, pad_l, pad_r, stride_w, dilation_w);
  const int channel_size = height * width;

  for (int channel = channels; channel--; data_im += channel_size)
  {
    for (int kernel_row = 0; kernel_row < kernel_h; kernel_row++)
    {
      for (int kernel_col = 0; kernel_col < kernel_w; kernel_col++)
      {
        int input_row = -pad_t + kernel_row * dilation_h;
        for (int output_rows = output_h; output_rows; output_rows--)
        {
          if (!is_a_ge_zero_and_a_lt_b(input_row, height))
          {
            for (int output_cols = output_w; output_cols; output_cols--)
            {
              *(data_col++) = 0;
            }
          }
          else
          {
            int input_col = -pad_l + kernel_col * dilation_w;
            for (int output_col = output_w; output_col; output_col--)
            {
              if (is_a_ge_zero_and_a_lt_b(input_col, width))
              {
                *(data_col++) = data_im[input_row * width + input_col];
              }
              else
              {
                *(data_col++) = 0;
              }
              input_col += stride_w;
            } // output_col loop
          }
          input_row += stride_h;
        } // output_rows loop
      } // kernel_col loop
    } // kernel_row loop
  } // channel loop
}

// fetch all posible data cubes (along with kernel D1, D2, D3....Dd) used to do matmul with kernel matrix
void im2colNd(const float* data_img, const int* im_shape, const int* col_shape,
              const int* m_kernel_shape, const int N,
              const int* pad,
              const int* stride,
              const int* dilation,
              float* data_col,
              const int padding_value = 0)
{
  int kernel_size = 1;
  for (int i = 0; i < N; ++i) {
    kernel_size *= m_kernel_shape[i];
  }
  int channels_col = col_shape[0];
  std::vector<int> d_offset(N, 0);
  std::vector<int> d_iter(N, 0);
  for (int c_col = 0; c_col < channels_col; ++c_col) {
    // Loop over spatial axes in reverse order to compute a per-axis offset.
    int offset = c_col;
    for (int d_i = N - 1; d_i >= 0; --d_i) {
      if (d_i < N - 1) {
        offset /= m_kernel_shape[d_i + 1];
      }
      d_offset[d_i] = offset % m_kernel_shape[d_i];
    }
    for (bool incremented = true; incremented;) {
      // Loop over spatial axes in forward order to compute the indices in the
      // image and column, and whether the index lies in the padding.
      int index_col = c_col;
      int index_im = c_col / kernel_size;
      bool is_padding = false;
      for (int d_i = 0; d_i < N; ++d_i) {
        int d = d_iter[d_i];
        int d_im = d * stride[d_i] - pad[d_i] + d_offset[d_i] * dilation[d_i];
        is_padding |= d_im < 0 || d_im >= im_shape[d_i + 1];
        index_col *= col_shape[d_i + 1];
        index_col += d;
        index_im *= im_shape[d_i + 1];
        index_im += d_im;
      }
      if (is_padding) {
        data_col[index_col] = padding_value;
      } else {
        data_col[index_col] = data_img[index_im];
      }
      // Loop over spatial axes in reverse order to choose an index,
      // like counting.
      incremented = false;
      for (int d_i = N - 1; d_i >= 0; --d_i) {
        int d_max = col_shape[d_i + 1];
        if (d_iter[d_i] == d_max - 1) {
          d_iter[d_i] = 0;
        } else {  // d_iter[d_i] < d_max - 1
          ++d_iter[d_i];
          incremented = true;
          break;
        }
      }
    }  // while(incremented) {
  }    // for (int c = 0; c < channels_col; ++c) {
}

cimHWConvOp::cimHWConvOp(
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
  const_dim_type* strides_, const_dim_type number_of_strides_)
  : cimHWOp("Conv")
  , m_cimCU(configFilePath)
  , m_input_X(input_X_)
  , m_input_W(input_W_)
  , m_input_B(input_B_)
  , m_output_Y(output_Y_)
{
  verbose1(opName());

  // input validation
  if(input_X_ndim_ <= 2)
    error("Minimum dimension of X is 3");
  if(input_W_ndim_ <= 2)
    error("Minimum dimension of W is 3");

  m_NInputs = input_X_dims_[0];
  if(m_NInputs != 1)
    error("Only support 1 batch now");

  // basic property of conv
  m_Channel       = input_X_dims_[1];
  m_OutputChannel = input_W_dims_[0];
  m_input_X_shape = std::vector<dim_type>(input_X_dims_, input_X_dims_ + input_X_ndim_);
  m_input_W_shape = std::vector<dim_type>(input_W_dims_, input_W_dims_ + input_W_ndim_);
  if(m_Channel != input_W_dims_[1])
    error("Channel of X and W is not consistent");

  // check kernel related properties
  // find out kernel shape, which is the shape excludes M and C from weights
  m_kernel_shape  = std::vector<dim_type>(input_W_dims_ + 2, input_W_dims_ + input_W_ndim_);
  m_input_B_shape = std::vector<dim_type>(input_B_dims_, input_B_dims_ + input_B_ndim_);
  // check dilation
  m_dilations = std::vector<dim_type>(dilations_, dilations_ + number_of_dilations_);
  if (m_dilations.empty()) {
    m_dilations.resize(m_kernel_shape.size(), 1);
  }
  // check group
  m_group = group_;
  // check pads
  m_pads = std::vector<dim_type>(pads_, pads_ + number_of_pads_);
  if (m_pads.empty()) {
    m_pads.resize(m_kernel_shape.size() * 2, 0);
  }
  // check strides
  m_strides = std::vector<dim_type>(strides_, strides_ + number_of_strides_);
  if (m_strides.empty()) {
    m_strides.resize(m_kernel_shape.size(), 1);
  }

  // infer the shape of output and output_Y from input
  m_image_shape = std::vector<dim_type>(input_X_dims_ + 2, input_X_dims_ + input_X_ndim_);
  m_output_Y_shape = std::vector<dim_type> ({m_NInputs, m_OutputChannel});
  for(int i=0; i< m_image_shape.size(); i++) {
    m_output_Y_shape.push_back(computePadAndOutputShape(m_image_shape[i], m_kernel_shape[i], m_strides[i], m_dilations[i],
                                                        StringToAutoPadType(std::string(auto_pad_)),
                                                        &m_pads[i], &m_pads[ m_image_shape.size()+i]));
  }
  for(int i=2; i<m_output_Y_shape.size(); i++)
    m_output_shape.push_back(m_output_Y_shape[i]);
}

void cimHWConvOp::simulate()
{
  // calculate the size of each tensor
  dim_type m_input_size  = std::accumulate( m_image_shape.cbegin()  ,  m_image_shape.cend()  , 1, std::multiplies<dim_type>());
  dim_type m_weight_size = std::accumulate(m_input_W_shape.cbegin() , m_input_W_shape.cend() , 1, std::multiplies<dim_type>());
  dim_type m_kernel_size = std::accumulate(m_kernel_shape.cbegin()  , m_kernel_shape.cend()  , 1, std::multiplies<dim_type>());
  dim_type m_output_size = std::accumulate(m_output_shape.cbegin()  , m_output_shape.cend()  , 1, std::multiplies<dim_type>());

  // calculate the extended number for easy use
  const dim_type X_offset      = m_Channel / m_group * m_input_size;
  const dim_type W_offset      = m_weight_size / m_group;
  const dim_type kernel_offset = m_kernel_size * m_Channel / m_group;
  const dim_type kernel_dim    = m_Channel / m_group * m_kernel_size;
  const dim_type kernel_rank   = m_kernel_shape.size();

  std::vector<dim_type> col_buffer_shape;
  // Pointwise convolutions can use the original input tensor in place,
  // otherwise a temporary buffer is required for the im2col transform.
  // Todo: pointwise conv can do inplace gemm without dataCube and col_buffer
  //if (kernel_size != 1/* || !HasStridesOneAndNoPadding()*/) {
  if (kernel_rank != 2) {
    // only used in in2colNd
    col_buffer_shape.reserve(1 + m_output_shape.size());
    col_buffer_shape.push_back(kernel_dim);
    col_buffer_shape.insert(col_buffer_shape.end(), m_output_shape.begin(), m_output_shape.end());
  }
  //}

  // Object is to get matrix product N*M(output_channels) x dataCubes(output_image_size) = kernel * dataCubes
  MatrixXfRowMajor result = MatrixXfRowMajor::Zero(m_OutputChannel, m_output_size);
  // prepare dataCubes = dataCubes(output_image_size) x (kernel_size), column-major
  MatrixXfRowMajor dataCubes = MatrixXfRowMajor::Zero(kernel_dim, m_output_size);
  for (int group_id = 0; group_id < m_group; ++group_id)
  {
    // apply im2col for conv2d
    if (kernel_rank == 2) {

      im2col(m_input_X + group_id * X_offset, m_Channel / m_group,  m_image_shape[0],  m_image_shape[1],
               m_kernel_shape[0], m_kernel_shape[1],
               m_pads[0], m_pads[2],
               m_pads[1], m_pads[3],
               m_strides[0], m_strides[1],
               m_dilations[0], m_dilations[1],
               dataCubes.data());
    }
    else
    // otherwise, apply im2colNd, including conv1d and more than conv3d
    {
      im2colNd(m_input_X + group_id * X_offset, m_input_X_shape.data() + 1, col_buffer_shape.data(),
              m_kernel_shape.data(), kernel_rank,
              m_pads.data(),
              m_strides.data(),
              m_dilations.data(),
              dataCubes.data());
    }

    // prepare kernel =  M(output_channels)/group x (kernel_size)
    Eigen::Map<const MatrixXfRowMajor> kernel(m_input_W + group_id * W_offset + group_id * kernel_offset, m_OutputChannel / m_group, kernel_dim);
    // send datacube and each kernel by row to ComputeUnit
    for(int i=0; i<kernel.rows(); i++)
      result.block(group_id * m_OutputChannel / m_group, 0, m_OutputChannel / m_group, m_output_size).row(i) = 
                   m_cimCU.compute(dataCubes, kernel.row(i).transpose());
  }

  // finally, plus bias to every kernel
  if(m_input_B != nullptr)
  {
    MatrixXfRowMajor bias_mat(m_OutputChannel, m_output_size);
    bias_mat.colwise() = Eigen::Map<const Eigen::VectorXf>(m_input_B, m_input_B_shape[0]);
    result += bias_mat;
  }

  // copy back to output
  memcpy(m_output_Y, result.data(), sizeof(numType) * m_OutputChannel * m_output_size);
  verbose1("\n");
}

}  // namespace cimHW
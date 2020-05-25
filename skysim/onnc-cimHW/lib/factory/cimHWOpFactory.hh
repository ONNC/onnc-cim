//===- cimHWOpFactory.hh --------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#pragma once
#include <abstractOpFactory.hh>

namespace cimHW {

class cimHWOpFactory
  : public AbstractOpFactory {
public:
  cimHWOpFactory();
  virtual ~cimHWOpFactory();

  virtual std::unique_ptr<cimHWOp> createConvOp(
    void* context
    ,const_element_type* input_X, const_dim_type input_X_ndim, const_dim_type* input_X_dims
    ,const_element_type* input_W, const_dim_type input_W_ndim, const_dim_type* input_W_dims
    ,const_element_type* input_B, const_dim_type input_B_ndim, const_dim_type* input_B_dims
    ,element_type* output_Y, const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
    ,const char* auto_pad
    ,dim_type* dilations
    ,dim_type number_of_dilations
    ,dim_type group
    ,dim_type* kernel_shape
    ,dim_type number_of_kernel_shape
    ,dim_type* pads
    ,dim_type number_of_pads
    ,dim_type* strides
    ,dim_type number_of_strides
  ) override;

  virtual std::unique_ptr<cimHWOp> createGemmOp(
    void* context
    ,const_element_type* input_A, const_dim_type input_A_ndim, const_dim_type* input_A_dims
    ,const_element_type* input_B, const_dim_type input_B_ndim, const_dim_type* input_B_dims
    ,const_element_type* input_C, const_dim_type input_C_ndim, const_dim_type* input_C_dims
    ,element_type* output_Y, const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
    ,const_element_type alpha
    ,const_element_type beta
    ,const_dim_type transA
    ,const_dim_type transB
  ) override;

  // virtual std::unique_ptr<cimHWOp> create${OperatorName}Op(
  //   void* context
  //   ${argument_list}
  // ) override;
};

} // namespace cimHW
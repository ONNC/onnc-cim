//===- abstractOpFactory.cc -----------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include "cimHWOpFactory.hh"
#include "../conv.hh"
#include "../gemm.hh"

namespace cimHW {

cimHWOpFactory::cimHWOpFactory() {}
cimHWOpFactory::~cimHWOpFactory() {}

std::unique_ptr<cimHWOp> cimHWOpFactory::createConvOp(
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
)
{
  const std::string* cimConfig = reinterpret_cast<const std::string*>(context);
  return std::make_unique<cimHWConvOp>(
    *cimConfig
    ,input_X, input_X_ndim, input_X_dims
    ,input_W, input_W_ndim, input_W_dims
    ,input_B, input_B_ndim, input_B_dims
    ,output_Y, output_Y_ndim, output_Y_dims
    ,auto_pad
    ,dilations
    ,number_of_dilations
    ,group
    ,kernel_shape
    ,number_of_kernel_shape
    ,pads
    ,number_of_pads
    ,strides
    ,number_of_strides
  );
}

std::unique_ptr<cimHWOp> cimHWOpFactory::createGemmOp(
  void* context
  ,const_element_type* input_A, const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B, const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,const_element_type* input_C, const_dim_type input_C_ndim, const_dim_type* input_C_dims
  ,element_type* output_Y, const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  ,const_element_type alpha
  ,const_element_type beta
  ,const_dim_type transA
  ,const_dim_type transB)
{
  const std::string* cimConfig = reinterpret_cast<const std::string*>(context);
  return std::make_unique<cimHWGemmOp>(
    *cimConfig
		, input_A, input_A_ndim, input_A_dims
		, input_B, input_B_ndim, input_B_dims
		, input_C, input_C_ndim, input_C_dims
		, output_Y, output_Y_ndim, output_Y_dims
		, alpha, beta
    , transA, transB
  );
}

// std::unique_ptr<cimHWOp> cimHWOpFactory::create${OperatorName}Op(
//   void* context
//   ${argument_list}
// )
// {
//   const std::string* cimConfig = reinterpret_cast<const std::string*>(context);
//   return std::make_unique<cimHW${OperatorName}Op>(
//     *cimConfig
//     ${argument_list}
//   );
// }

} // namespace cimHW
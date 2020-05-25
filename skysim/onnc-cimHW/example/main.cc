//===- main.cc ------------------------------------------------------------===//
//
//                       The CIM Hardware Simulator Project
//
// See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#include <cimHWOp.hh>
#include <cimHWSimulator.hh>
#include <iostream>
#include <vector>
using namespace cimHW;


// This program illustrates how to hand make a model and including tensors
// And we will use the model as a case to use cimHWSim to simulate the hardware behavior
int main(int argc, char *argv[])
{
  // cinfiguration file must be provided
  if(argc != 2)
  {
    std::cout << "Usage: ./main <cimConfigFile>" << std::endl;
    exit(1);
  }
  std::string configFile(argv[1]);

  // tensor shape definition (Batch, Channel, Height, Width)
  // define a model with 3 operators
  // input(1x1x5x5)     = 1x1x5x5
  // conv1(1x3x5x5)     = Conv(input, kernel=3x1x3x3, bias=1x3, pads=[1,1,1,1], strides=[1,1])
  // reshape1(1x75)     = Reshape(conv1, shape=[1,75])
  // output(1x5)        = Gemm(reshape1, gemmB=5x75, transA=0, transB=1)

  // initialize simulator
  cimHWSimulator ops;

  // allocate input, output and internal tensors
  // input(1x1x5x5)
  const std::vector<dim_type> input_shape {1, 1, 5, 5};
  element_type input[] = {
    1.5, 1.0, 0.5, 1.5, 1.0,
    1.5, 1.0, 0.5, 1.5, 1.0,
    1.5, 1.0, 0.5, 1.5, 1.0,
    1.5, 1.0, 0.5, 1.5, 1.0,
    1.5, 1.0, 0.5, 1.5, 1.0
  };

  // layer 1:
  // conv1(1x3x5x5)     = Conv(input, weight=3x1x3x3, bias=1x3, pads=[1,1,1,1], strides=[1,1])
  // allocate constant resource for layer 1
  // kernel(1x3)
  const std::vector<dim_type> weight_shape {3, 1, 3, 3};
  const_element_type weight[] = {
    1.5, 1.0, 0.5,
    1.5, 1.0, 0.5,
    1.5, 1.0, 0.5,

    1.5, 1.0, 0.5,
    1.5, 1.0, 0.5,
    1.5, 1.0, 0.5,

    1.5, 1.0, 0.5,
    1.5, 1.0, 0.5,
    1.5, 1.0, 0.5
  };
  // bias(1x3)
  const std::vector<dim_type> bias_shape {3};
  const_element_type bias[] = {
    1.5, 1.0, 0.5
  };
  // conv1(1x3x5x5)
  const std::vector<dim_type> conv1_shape {1, 3, 5, 5};
  element_type conv1[75];
  // dilation(1x2)
  std::vector<dim_type> dilations {1, 1};
  // group(1)
  const_dim_type group = 1;
  // kernel(1x2)
  std::vector<dim_type> kernel {3, 3};
  // pads(1x4)
  std::vector<dim_type> pads {1, 1, 1, 1};
  // strides(1x2)
  std::vector<dim_type> strides {1, 1};
  ops.cimHW_Conv_float(
    reinterpret_cast<void*>(&configFile),
		input, input_shape.size()  , input_shape.data(),
		weight, weight_shape.size() , weight_shape.data(),
		bias  , bias_shape.size()   , bias_shape.data(),
		conv1 , conv1_shape.size()  ,   conv1_shape.data(),
    "",
    dilations.data(), dilations.size(),
    group,
    kernel.data(), kernel.size(),
    pads.data(), pads.size(),
    strides.data(), strides.size()
  );


  // layer 2:
  // reshape1(1x75)     = Reshape(conv1, shape=1x2)
  // allocate constant resource for layer 2
  // shape(1x2)
  const std::vector<dim_type> shape_shape {1, 2};
  const_element_type shape[] = {1, 75};
  // reshape(1x2)
  const std::vector<dim_type> reshape_shape {1, 75};
  element_type reshape[75];
  ops.cimHW_Reshape_float(
    reinterpret_cast<void*>(&configFile),
		conv1   , conv1_shape.size()    ,   conv1_shape.data(),
		shape   , shape_shape.size()    ,   shape_shape.data(),
		reshape , reshape_shape.size()  ,   reshape_shape.data()
  );

  // layer 3:
  // output(1x5)        = Gemm(reshape1, gemmB=5x75, transA=0, transB=1)
  // allocate constant resource for layer 3
  // gemmB(5x75)
  const std::vector<dim_type> gemmB_shape {5, 75};
  const_element_type gemmB[] = {
    1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 0.5, 1.5, 1.0, 0.5, 1.5,
    1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 0.5, 1.5, 1.0, 0.5, 1.5,
    1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 0.5, 1.5, 1.0, 0.5, 1.5,
    1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 0.5, 1.5, 1.0, 0.5, 1.5,
    1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 1.0, 0.5, 1.5, 0.5, 1.5, 1.0, 0.5, 1.5
  };
  // output(1x5)
  const std::vector<dim_type> output_shape {1, 5};
  element_type output[5];
  // alpha(1)
  element_type alpha = 1.0;
  // beta(1)
  element_type beta  = 1.0;
  // transA(1)
  dim_type transA = 0;
  // transB(1)
  dim_type transB = 1;
  ops.cimHW_Gemm_float(
    reinterpret_cast<void*>(&configFile),
		reshape , reshape_shape.size()  , reshape_shape.data()  ,
    gemmB   , gemmB_shape.size()    , gemmB_shape.data()    ,
    nullptr , 0                     , nullptr               ,
    output  , output_shape.size()   , shape_shape.data()    ,
    alpha,  beta,
    transA, transB
  );


  // cout the compute result
  std::cout << "Result: " << std::endl;
  dim_type size = 1;
  for(dim_type i=0; i<output_shape.size(); i++)
    size *= output_shape[i];
  for(dim_type i=0; i<size; i++)
    std::cout << output[i] << ", ";
  std::cout << std::endl;

  return 0;
}
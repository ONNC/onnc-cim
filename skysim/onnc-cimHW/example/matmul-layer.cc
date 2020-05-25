//===- matmul-layer.cc -----------------------------------------------------===//
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


// This program illustrates how to simulate single layer matmul
int main(int argc, char *argv[])
{
  // cinfiguration file must be provided
  if(argc != 2)
  {
    std::cout << "Usage: ./main <cimConfigFile>" << std::endl;
    exit(1);
  }
  std::string configFile(argv[1]);

  // matrixA(2x3)       = 2x3
  // matrixB(3x5)       = 3x5
  // result(2x5)        = Matmul(matrixA, matrixB)

  // initialize simulator
  cimHWSimulator ops;

  // allocate matrixA, matrixB
  // matrixA(2x3)
  const std::vector<dim_type> matrixA_shape {2, 3};
  element_type matrixA[] = {
    1.5, 1.0, 0.5,
    1.5, 1.0, 0.5
  };

  // matrixB(3x5)
  const std::vector<dim_type> matrixB_shape {3, 5};
  element_type matrixB[] = {
    1.5, 1.0, 0.5, 1.5, 1.0,
    1.5, 1.0, 0.5, 1.5, 1.0, 
    1.5, 1.0, 0.5, 1.5, 1.0
  };

  // result(2x5)
  const std::vector<dim_type> output_shape {2, 5};
  element_type output[10];

  ops.cimHW_MatMul_float(
    reinterpret_cast<void*>(&configFile),
		matrixA,  matrixA_shape.size()  , matrixA_shape.data(),
		matrixB,  matrixB_shape.size()  , matrixB_shape.data(),
		output,   output_shape.size()   , output_shape.data()
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
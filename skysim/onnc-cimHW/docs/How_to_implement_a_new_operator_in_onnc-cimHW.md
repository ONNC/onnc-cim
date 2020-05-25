How to implement a new operator in onnc-cimHW
==

[[_TOC_]]

## Preface
onnc-cimHW now has implmented two operators using CIM hardware. For those operators haven't implemented, onnc-cimHW provides default behavior from fastsim. Excitingly, onnc-cimHW has been designed to be extended easily, providing a easy way to implement a new simulation for an operator. Furthermore, it is possible to select partial of operators from both cim-implemented or fastsim, not have to be all cim-implemented. In this tutorial, we will focus on how to implement a new operator using cim hardware.

## Development Process
onnc-cimHW has designed to be as easy as possible to create a new operator. Following is the summary to create a cim-feature operator.

1. Create a new header and implementation file from template
1. Register to desired factory class
1. Register to building system
3. Rebuild

## Implementation
### Create a new header and implementation file
We will use `MatMul` as example to go through how to implement a cim-feature operator.

First of all, copy `op.template.cc` and `op.template.hh` in skysim/onnc-cimHW/lib to same directory and give it a new name. We use `matmul.cc` and `matmul.hh` here.

#### matmul.hh
The template has included basic component to implement a operator. The first thing is to replace `${OperatorName}` by desired name. This will be used in whole C++ program, not to be the same to file name.
```cpp
class cimHW${OperatorName}Op : public cimHWOp {
public:
  cimHW${OperatorName}Op(
    const std::string &configFile
    ${argument_list}
  );

  virtual void simulate() final;

private:

  // Use a compute unit
  ComputeUnit               m_cimCU;
};
```

For `${argument_list}`, check out `skysim/onnc-cimHW/include/abstractOpFactory.hh`, there is a function named `create${OperatorName}Op`. Copy the second parameter to the last to `${argument_list}`. This is to create the interface of the constructor, which needs to be identical to factery argument list.
```
virtual std::unique_ptr<cimHWOp> createMatMulOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims
  
);
```

After replacement, the final class declaration will look like this. Here we also create a member to store the pointer to output, tow eigen matrix for computation. We will use these members in implementation later. **Note: A CIM ComputeUnite is used in this case.**
```cpp
class cimHWMatMulOp : public cimHWOp {
public:
  cimHWMatMulOp(
  const std::string &configFile
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims);

  virtual void simulate() final;

private:
  element_type*             m_output_Y;

  MatrixXfRowMajor          m_matrix_A;
  MatrixXfRowMajor          m_matrix_B;

  // Use a compute unit
  ComputeUnit               m_cimCU;
};
```

#### matmul.cc
Apply similar process to implementation file `matmul.cc`. For constructor, we often perform data check and some trasformation, this is all for preparing simulation later. In this case, we map `input_A` and `input_B` to Eigen matrix, this has nearly no cost. We use a lot Eigen matrix as basic datatype to transfer between instances. We also initialize base class `cimHWOp` by  operator's name and cim compute unit which needs the path to configuration file.
```cpp
cimHWMatMulOp::cimHWMatMulOp(
  const std::string &configFile
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims)
	: cimHWOp("MatMul")
  , m_cimCU(configFile)
{
  verbose1(opName());
  
  // map to proper view of matrix according to transision
  m_matrix_A = Eigen::Map<const MatrixXfRowMajor>(input_A, input_A_dims[0], input_A_dims[1]);
  m_matrix_B = Eigen::Map<const MatrixXfRowMajor>(input_B, input_B_dims[0], input_B_dims[1]);

  // keep output pointer
  m_output_Y = output_Y;
}
```

For member function `simulate`, this will be called for actuall simulation. To ensure this is the new cim-feature implementation, not fastsim, we add a line in begining to notice. As widely known, a matrix product of MxK to KxN produces MxN, here we create a matrix `result` to store the multiplication.

Then `m_cimCU.compute` is the main part of using CIM hardware. A compute unit can perform the inner product for a bunch of input (said matrix) and a vector. To fully take benefit from CIM hardware feature, setting kernel one time and used as many times as possible, we take `m_matrix_A` as weight matrix and set rows iteratively to cross bar cell. Thus we can take matrix `m_matrix_B` as data columns to multiply with given row in `m_matrix_A`. Each time, we will obtain a row vector, representing the inner product of all the data and the first row (kernel) of weights. After iterating all the rows, the whole matrix multiplication completes.

Lastly, copy back the `result` to pointer `m_ouput_Y`. Remeber to set proper number of elements to be copied, avoiding invalid memory access. This is the main part of implementation of a new operator.
```cpp
void cimHWMatMulOp::simulate() 
{
  std::cout << "This is a cim-implemented operator" << std::endl;
  
  // take matrixA as kernel and matrixB as data to use ComputeUnit
  MatrixXfRowMajor result = MatrixXfRowMajor::Zero(m_matrix_A.rows(), m_matrix_B.cols());
  for(int i=0; i<m_matrix_A.rows(); i++)
    result.row(i) = m_cimCU.compute(m_matrix_B, m_matrix_A.row(i).transpose());

  // copy back to output
  memcpy(m_output_Y, result.data(), sizeof(numType) * m_matrix_A.rows() * m_matrix_B.cols());
}
```

### Register to desired factory class
After implementation, we now have to register the cim-feature operator to factor hierarchy. Check out the code in `skysim/onnc-cimHW/lib/factory/cimHWOpFactory.hh` and `skysim/onnc-cimHW/lib/factory/cimHWOpFactory.cc`, we need to add the just implemented operator to the list.

First thing is to put header just created to source file `cimHWOpFactory.cc`.
```cpp
#include ......
#include ......
#include "../matmul.hh"
```

For `skysim/onnc-cimHW/lib/factory/cimHWOpFactory.hh`, there is a comment declaration template after the last declaration. Copy to create a new snippet and replace `${argument_list}` by same approach introduced above. In MatMul case, this will produce following:
```cpp
  virtual std::unique_ptr<cimHWOp> createMatMulOp(
    void* context
    ,const_element_type* input_A
    ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
    ,const_element_type* input_B
    ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
    ,element_type* output_Y
    ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims    
  ) override;
```

For `skysim/onnc-cimHW/lib/factory/cimHWOpFactory.cc`, there is also a commented definition template after the last member function. Copy to create a new snippet as well and replace `${argument_list}`. This will look like this in MatMul case. Note that Remember to take away data type specifier from `make_unique` statement, this is to pass paramenter.
```cpp
std::unique_ptr<cimHWOp> cimHWOpFactory::createMatMulOp(
  void* context
  ,const_element_type* input_A
  ,const_dim_type input_A_ndim, const_dim_type* input_A_dims
  ,const_element_type* input_B
  ,const_dim_type input_B_ndim, const_dim_type* input_B_dims
  ,element_type* output_Y
  ,const_dim_type output_Y_ndim, const_dim_type* output_Y_dims    
)
{
  const std::string* cimConfig = reinterpret_cast<const std::string*>(context);
  return std::make_unique<cimHWMatMulOp>(
    *cimConfig
    ,input_A
    ,input_A_ndim, input_A_dims
    ,input_B
    ,input_B_ndim, input_B_dims
    ,output_Y
    ,output_Y_ndim, output_Y_dims    
  );
}
```

### Register to building system
Add the `matmul.cc` to `skysim/onnc-cimHW/lib/CMakeLists.txt`.
```cmake
########################################
# cimHWSim library
add_library(cimHWSim SHARED
...
...
matmul.cc
)
```

### Rebuild
Back to container, rebuild the project.
```bash
/onnc/onnc-cimHW.build$ make; sudo make install
```

Run example `matmul-layer` to see the result.
```bash
./example/matmul-layer share/cimConfig.json
```

You should see the result using cim-feature operaotr now.
```bash
This is a cim-implemented operator
Result: 
4.5, 3, 1.5, 4.5, 3, 4.5, 3, 1.5, 4.5, 3, 
```
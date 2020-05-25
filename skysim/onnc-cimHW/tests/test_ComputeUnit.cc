#include "configFile.hh"
#include <hardware/ComputeUnit.hh>
#include <gtest/gtest.h>

using namespace cimHW;

TEST(ComputeUnit, End2EndTest_SingleKernel) {

  // data   1.5, -0.5, 1.5, -0.5 1.5, -0.5, 1.5, -0.5
  //        1.5, -0.5, 1.5, -0.5 1.5, -0.5, 1.5, -0.5
  // kernel 1.5, 3.25, 1.5, 3.25 1.5, 3.25, 1.5, 3.25
  // dot =  2.5 2.5

  // data quantization 2+2
  // bit1~bit4, 8 cycles
  // 0   1   1   0
  // 1   1   1   0
  // 0   1   1   0
  //   1   1   1   0

  // kernel quantization 3+2
  // bit1~bit5
  // 0 0 1 1 0
  // 0 1 1 0 1
  // 0 0 1 1 0
  // 0 1 1 0 1

  MatrixXfRowMajor input(8, 2);
  input << 1.5,  1.5,
          -0.5, -0.5,
           1.5,  1.5,
          -0.5, -0.5,
           1.5,  1.5,
          -0.5, -0.5,
           1.5,  1.5,
             0, -0.5;
  VectorXnum kernel(8);
  kernel << 1.5f,
            3.25f,
            1.5f,
            3.25f,
            1.5f,
            3.25f,
            1.5f,
            3.25f;
  RowVectorXf expected(2);
  expected << 4.125, 2.5;

  ComputeUnit cu(configFilePath);
  auto result = cu.compute(input, kernel);
  EXPECT_EQ(result, expected);
}

TEST(ComputeUnit, End2EndTest_MultipleKernel) {

  // data   1.5, -0.5, 1.5, -0.5 1.5, -0.5, 1.5, -0.5
  //        1.5, -0.5, 1.5, -0.5 1.5, -0.5, 1.5, -0.5
  // kernel 1.5, 3.25, 1.5, 3.25 1.5, 3.25, 1.5, 3.25
  // dot =  2.5 2.5

  // data quantization 2+2
  // bit1~bit4, 8 cycles
  // 0   1   1   0
  // 1   1   1   0
  // 0   1   1   0
  //   1   1   1   0

  // kernel quantization 3+2
  // bit1~bit5
  // 0 0 1 1 0
  // 0 1 1 0 1
  // 0 0 1 1 0
  // 0 1 1 0 1

  MatrixXfRowMajor input(8, 2);
  input << 1.5,  1.5,
          -0.5, -0.5,
           1.5,  1.5,
          -0.5, -0.5,
           1.5,  1.5,
          -0.5, -0.5,
           1.5,  1.5,
             0, -0.5;
  MatrixXfRowMajor kernel(8, 2);
  kernel <<  1.5f,  1.5f,
            3.25f, 3.25f,
             1.5f,  1.5f,
            3.25f, 3.25f,
             1.5f,  1.5f,
            3.25f, 3.25f,
             1.5f,  0.0f,
            3.25f, 3.25f;
  MatrixXfRowMajor expected(2, 2);
  expected << 4.125,  2.5,
              1.875, 0.25;

  ComputeUnit cu(configFilePath);

  MatrixXfRowMajor result = MatrixXfRowMajor::Zero(2, 2);
  for(int i=0; i<kernel.cols(); i++)
    result.row(i) = cu.compute(input, kernel.col(i));
  EXPECT_EQ(result, expected);
}
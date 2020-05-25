#include <hardware/CrossBarUnit.hh>
#include <gtest/gtest.h>

using namespace cimHW;

TEST(CrossBarUnit, End2EndTest) {

  // data   1.5, -0.5, 1.5, -0.5
  //        1.5, -0.5, 1.5, -0.5
  // kernel 1.5, 3.25, 1.5, 3.25
  // dot =  1.25

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

  // after xbar, bitlines=5
  // c1 0 1 1 0 1
  // c2 0 1 1 0 1
  // c3 0 1 3 2 1
  // c4 0 1 1 0 1
  // c5 0 1 3 2 1
  // c6 0 1 1 0 1
  // c7 0 0 0 0 0
  // c8 0 0 0 0 0

  MatrixXfRowMajor input(4, 2);
  input << 1.5,  1.5,
          -0.5, -0.5,
           1.5,  1.5,
          -0.5, -0.5;

  VectorXnum kernel(4);
  kernel << 1.5f,
            3.25f,
            1.5f,
            3.25f;

  RowVectorXf expected(2);
  expected << 1.25, 1.25;

  CrossBarUnit xbar(4, nullptr,
                2, 2,
                3, 2);
  const unsigned OUSize = 3;
  xbar.setCell(kernel);
  auto result = xbar.compute(input, OUSize);
  EXPECT_EQ(result, expected);
}
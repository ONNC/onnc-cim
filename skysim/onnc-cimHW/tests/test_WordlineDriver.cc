#include <hardware/WordLineDriver.hh>
#include <gtest/gtest.h>
#include <vector>

using namespace cimHW;

TEST(WordLineDriver, OneOperationUnit) {

  WordLineDriver WLD(4, 4, 4);

  // 0 1 2 3 4 5 6 7 index
  // 0 0 0 1 1 0 0 0
  // 0 0 1 1 0 1 0 0
  // 0 0 1 1 0 1 0 0
  // 0 0 0 1 1 0 0 0
  VectorXnum input(4);
  input << 1.5f, 3.25f, 3.25f, 1.5f;

  MatrixXuiRowMajor expected(4, 8);
  expected << 0, 0, 0, 1, 1, 0, 0, 0,
              0, 0, 1, 1, 0, 1, 0, 0,
              0, 0, 1, 1, 0, 1, 0, 0,
              0, 0, 0, 1, 1, 0, 0, 0;

  WLD.setInput(input, 4);
  auto wl = WLD.getNextWordLine();
  for(int i=0; wl.vector.size() !=0;i++)
  {
    EXPECT_EQ(wl.vector, expected.col(i));
    wl = WLD.getNextWordLine();
  }
}

TEST(WordLineDriver, MutipleOperationUnit) {

  WordLineDriver WLD(4, 4, 4);

  // 0 1 2 3 4 5 6 7 index
  // 0 0 0 1 1 0 0 0
  // 0 0 1 1 0 1 0 0
  // 0 0 1 1 0 1 0 0
  // 0 0 0 1 1 0 0 0
  VectorXnum input(4);
  input << 1.5f, 3.25f, 3.25f, 1.5f;

  MatrixXuiRowMajor expected(2, 16);
  expected << 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0,
              0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0;

  WLD.setInput(input, 2);
  auto wl = WLD.getNextWordLine();
  for(int i=0; wl.vector.size() !=0;i++)
  {
    EXPECT_EQ(wl.vector, expected.col(i));
    wl = WLD.getNextWordLine();
  }
}

TEST(WordLineDriver, LastOperationUnitIsNotFull) {

  WordLineDriver WLD(4, 4, 4);

  // 0 1 2 3 4 5 6 7 index
  // 0 0 0 1 1 0 0 0
  // 0 0 1 1 0 1 0 0
  // 0 0 1 1 0 1 0 0
  // 0 0 0 1 1 0 0 0
  VectorXnum input(4);
  input << 1.5f, 3.25f, 3.25f, 1.5f;

  std::vector<VectorXui> expected = {
    VectorXui(3), VectorXui(1),
    VectorXui(3), VectorXui(1),
    VectorXui(3), VectorXui(1),
    VectorXui(3), VectorXui(1),
    VectorXui(3), VectorXui(1),
    VectorXui(3), VectorXui(1),
    VectorXui(3), VectorXui(1),
    VectorXui(3), VectorXui(1)
  };
  expected[0] << 0, 0, 0;
  expected[1] << 0;
  expected[2] << 0, 0, 0;
  expected[3] << 0;
  expected[4] << 0, 1, 1;
  expected[5] << 0;
  expected[6] << 1, 1, 1;
  expected[7] << 1;
  expected[8] << 1, 0, 0;
  expected[9] << 1;
  expected[10] << 0, 1, 1;
  expected[11] << 0;
  expected[12] << 0, 0, 0;
  expected[13] << 0;
  expected[14] << 0, 0, 0;
  expected[15] << 0;

  WLD.setInput(input, 3);
  auto wl = WLD.getNextWordLine();
  for(int i=0; wl.vector.size() !=0;i++)
  {
    EXPECT_EQ(wl.vector, expected[i]);
    wl = WLD.getNextWordLine();
  }
}

TEST(WordLineDriver, ConvertTwosComplement) {
  
  // 2+4 bit: -2 ~ 1.9375
  // Max: 01.1111 =  1.9375 => shifted: 011111 =  31
  // Min: 10.0000 = -2      => shifted: 100000 = -32
  // reserve 4 bit precision for mantissa
  const unsigned int IL = 2;
  const unsigned int FL = 4;

  // ex: -1.7539 * 2^4 = -28.0624
  std::vector<numType> X = {
    1.5, -1.75, -8.2, 1.1234, 0.0321, -1.7539, -0.0001
  };
  MatrixXuiRowMajor expected_vals(X.size(), IL+FL);
  expected_vals <<
    0, 1, 1, 0, 0, 0,
    1, 0, 0, 1, 0, 0,
    1, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0,
    1, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 0, 0;

  WordLineDriver wld(2, IL, FL);
  MatrixXuiRowMajor result(X.size(), IL+FL);
  for(int i=0; i<X.size(); i++)
    result.row(i) = wld.quantize2TwoComplement(X[i]);
  EXPECT_EQ(result, expected_vals);
}

// TEST(quantize, InputInRange) {
  
//   const unsigned int IL = 8;
//   const unsigned int FL = 0;

//   vector<float> X = {
//     1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0
//   };
//   vector<unsigned int> output(X.size(), 0);
//   vector<unsigned int> expected_vals = {
//     1, 2, 3, 4, 5, 6, 7
//   };

//   for(int i=0;i<X.size();i++)
//     output[i] = quantize(X[i], IL, FL);

//   EXPECT_EQ(output, expected_vals);
// }

// TEST(quantize, InputOutRange) {
  
//   // 3 bit: -4 ~ 3
//   const unsigned int IL = 3;
//   const unsigned int FL = 0;

//   vector<float> X = {
//     1.0, -4.0, -8.0, 4.0, 8.0, 0.0, -5.0
//   };
//   vector<int> output(X.size(), 0);
//   vector<int> expected_vals = {
//     1, -4, -4, 3, 3, 0, -4
//   };

//   for(int i=0;i<X.size();i++)
//     output[i] = quantize(X[i], IL, FL);

//   EXPECT_EQ(output, expected_vals);
// }

// TEST(quantize, HasFraction) {
  
//   // 2+4 bit: -2 ~ 1.9375
//   // Max: 01.1111 =  1.9375 => shifted: 011111 =  31
//   // Min: 10.0000 = -2      => shifted: 100000 = -32
//   // reserve 4 bit precision for mantissa
//   const unsigned int IL = 2;
//   const unsigned int FL = 4;

//   // ex: -1.7539 * 2^4 = -28.0624
//   vector<float> X = {
//     1.5, -1.75, -8.2, 1.1234, 0.0321, -1.7539, -0.0001
//   };
//   vector<int> output(X.size(), 0);
//   vector<int> expected_vals = {
//     24, -28, -32, 17, 0, -28, 0
//   };

//   for(int i=0;i<X.size();i++)
//     output[i] = quantize(X[i], IL, FL);

//   EXPECT_EQ(output, expected_vals);
// }
#include <hardware/BitlineReceiver.hh>
#include <gtest/gtest.h>

using namespace cimHW;

TEST(BitlineReceiver, SingleOperationUnit) {

  // data   1.5, -0.5, 1.5, -0.5
  // kernel 1.5, 3.25, 1.5, 3.25
  // dot =  1.25

  // data quantization 3+2
  // bit1~bit5
  // 0 0 1 1 0
  // 1 1 1 1 0
  // 0 0 1 1 0
  // 1 1 1 1 0

  // kernel quantization 3+2
  // bit1~bit5
  // 0 0 1 1 0
  // 0 1 1 0 1
  // 0 0 1 1 0
  // 0 1 1 0 1

  // after xbar, bitlines=5
  // c1 0 2 2 0 2
  // c2 0 2 2 0 2
  // c3 0 2 4 2 2
  // c4 0 2 4 2 2
  // c5 0 0 0 0 0
  BitlineReceiver receiver(3, 2, 3, 2);
  receiver.setOUNums(4, 4);

  std::vector<RowVectorXui> input = {
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5)
  };
  input[0] << 0, 2, 2, 0, 2;
  input[1] << 0, 2, 2, 0, 2;
  input[2] << 0, 2, 4, 2, 2;
  input[3] << 0, 2, 4, 2, 2;
  input[4] << 0, 0, 0, 0, 0;

  numType expected = 1.25;
  for(int i=0; i<input.size();i++)
    receiver.addVector(input[i]);
  EXPECT_EQ(receiver.fetchResult(), expected);
}

TEST(BitlineReceiver, MultipleOperationUnit) {

  // data   1.5, -0.5, 1.5, -0.5
  // kernel 1.5, 3.25, 1.5, 3.25
  // dot =  1.25

  // data quantization 2+2
  // bit1~bit4, 8 cycles
  // 0   1   1   0
  // 1   1   1   0
  //   0   1   1   0
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
  // c3 0 1 2 1 1
  // c4 0 1 2 1 1
  // c5 0 1 2 1 1
  // c6 0 1 2 1 1
  // c7 0 0 0 0 0
  // c8 0 0 0 0 0
  BitlineReceiver receiver(2, 2, 3, 2);
  receiver.setOUNums(4, 2);

  std::vector<RowVectorXui> input = {
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5)
  };
  input[0] << 0, 1, 1, 0, 1;
  input[1] << 0, 1, 1, 0, 1;
  input[2] << 0, 1, 2, 1, 1;
  input[3] << 0, 1, 2, 1, 1;
  input[4] << 0, 1, 2, 1, 1;
  input[5] << 0, 1, 2, 1, 1;
  input[6] << 0, 0, 0, 0, 0;
  input[7] << 0, 0, 0, 0, 0;

  numType expected = 1.25;
  for(int i=0; i<input.size();i++)
    receiver.addVector(input[i]);
  EXPECT_EQ(receiver.fetchResult(), expected);
}

TEST(BitlineReceiver, MultipleOperationUnit_NotEqualUnit) {

  // data   1.5, -0.5, 1.5, -0.5
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
  BitlineReceiver receiver(2, 2, 3, 2);
  receiver.setOUNums(4, 3);

  std::vector<RowVectorXui> input = {
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5),
    RowVectorXui(5)
  };
  input[0] << 0, 1, 1, 0, 1;
  input[1] << 0, 1, 1, 0, 1;
  input[2] << 0, 1, 3, 2, 1;
  input[3] << 0, 1, 1, 0, 1;
  input[4] << 0, 1, 3, 2, 1;
  input[5] << 0, 1, 1, 0, 1;
  input[6] << 0, 0, 0, 0, 0;
  input[7] << 0, 0, 0, 0, 0;

  numType expected = 1.25;
  for(int i=0; i<input.size();i++)
    receiver.addVector(input[i]);
  EXPECT_EQ(receiver.fetchResult(), expected);
}
#include <hardware/CrossBarArray.hh>
#include <gtest/gtest.h>

using namespace cimHW;

TEST(CrossBarArray, FullCrossBar) {

  CrossBarArray xbar(2, 4, 4, nullptr);

  // 0 0 0 1 1 0 0 0
  // 0 0 1 1 0 1 0 0
  VectorXnum kernel(2);
  kernel << 1.5f, 3.25f;

  CrossBarArray::WordLineVector wl;
  wl.startLine = 0;
  wl.vector = VectorXui(2);
  wl.vector << 1, 1;

  RowVectorXui expected(8);
  expected << 0, 0, 1, 2, 1, 1, 0, 0;

  xbar.setCell(kernel);
  auto result = xbar.compute(wl);

  EXPECT_EQ(result, expected);
}

TEST(CrossBarArray, PartialCrossBar) {

  CrossBarArray xbar(2, 4, 4, nullptr);

  // 0 0 0 1 1 0 0 0
  // 0 0 1 1 0 1 0 0
  VectorXnum kernel(2);
  kernel << 1.5f, 3.25f;

  CrossBarArray::WordLineVector wl;
  wl.startLine = 1;
  wl.vector = VectorXui(1);
  wl.vector << 1;

  RowVectorXui expected(8);
  expected << 0, 0, 1, 1, 0, 1, 0, 0;

  xbar.setCell(kernel);
  auto result = xbar.compute(wl);

  EXPECT_EQ(result, expected);
}
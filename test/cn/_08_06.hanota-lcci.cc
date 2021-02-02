//
// Created by timking.nf@foxmail.com on 2021/2/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_08_06.hanota-lcci.h"

namespace LeetCode_08_06 {

typedef tuple<vector<int>, vector<int>, vector<int>> ArgumentType;
// typedef int ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_08_06Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_08_06Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_08_06::Solution();
  ArgumentType arguments = GetParam();

  vector<int> A, B, C, asserted;
  tie(A, B, C) = arguments;
  asserted = A;
  ASSERT_TRUE(B.empty());
  ASSERT_TRUE(C.empty());

  solution->hanota(A, B, C);
  // vector_print(A);
  // vector_print(B);
  // vector_print(C);
  ASSERT_TRUE(A.empty());
  ASSERT_TRUE(B.empty());
  ASSERT_EQ(asserted, C);
}

auto values = ::testing::Values(
  ArgumentType({2,1,0}, {}, {}),
  ArgumentType({1,0}, {}, {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_08_06ParamTest, LeetCode_08_06Test, values);

}
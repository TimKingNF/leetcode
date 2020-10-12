//
// Created by timking.nf@foxmail.com on 2020/9/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "29.divide-two-integers.h"

namespace LeetCode29 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode29Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode29Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode29::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int dividend, divisor;
  tie(dividend, divisor) = arguments;

  ASSERT_EQ(solution->divide(dividend, divisor), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(10, 3), 3),
  ParamType(ArgumentType(7, -3), -2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode29ParamTest, LeetCode29Test, values);

}
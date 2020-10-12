//
// Created by timking.nf@foxmail.com on 2020/9/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "166.fraction-to-recurring-decimal.h"

namespace LeetCode166 {

typedef tuple<int, int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode166Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode166Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode166::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int numerator, denominator;
  tie(numerator, denominator) = arguments;

  ASSERT_EQ(solution->fractionToDecimal(numerator, denominator), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(1, 2), "0.5"),
  ParamType(ArgumentType(2, 1), "2"),
  ParamType(ArgumentType(2, 3), "0.(6)"),
  ParamType(ArgumentType(-3, -1), "3"),
  ParamType(ArgumentType(4, 333), "0.(012)"),
  ParamType(ArgumentType(1, 6), "0.1(6)")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode166ParamTest, LeetCode166Test, values);

}
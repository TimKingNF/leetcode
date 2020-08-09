//
// Created by timking.nf@foxmail.com on 2020/8/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "224.basic-calculator.h"

namespace LeetCode224 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode224Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode224Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode224::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->calculate(argument), ret);
}

auto values = ::testing::Values(
  ParamType("1 + 1", 2),
  ParamType(" 2-1 + 2 ", 3),
  ParamType("13+ 2 ", 15),
  ParamType("(1+(4+5+2)-3)+(6+8)", 23),
  ParamType("(1-(4+5+2)-3)+(6+8)", 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode224ParamTest, LeetCode224Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/9/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "227.basic-calculator-ii.h"

namespace LeetCode227 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode227Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode227Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode227::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->calculate(argument), ret);
}

auto values = ::testing::Values(
  ParamType("1-1+1", 1),
  ParamType("3+2*2", 7),
  ParamType(" 3/2 ", 1),
  ParamType(" 3+5 / 2 ", 5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode227ParamTest, LeetCode227Test, values);

}
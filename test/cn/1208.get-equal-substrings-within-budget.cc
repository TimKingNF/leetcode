//
// Created by timking.nf@foxmail.com on 2021/2/5.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1208.get-equal-substrings-within-budget.h"

namespace LeetCode1208 {

typedef tuple<string, string, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1208Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1208Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1208::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s, t;
  int maxCost;
  tie(s, t, maxCost) = arguments;

  ASSERT_EQ(solution->equalSubstring(s, t, maxCost), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("abcd", "bcdf", 3), 3),
  ParamType(ArgumentType("abcd", "cdef", 3), 1),
  ParamType(ArgumentType("abcd", "acde", 0), 1)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1208ParamTest, LeetCode1208Test, values);

}
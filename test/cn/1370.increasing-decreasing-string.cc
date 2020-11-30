//
// Created by timking.nf@foxmail.com on 2020/11/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1370.increasing-decreasing-string.h"

namespace LeetCode1370 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1370Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1370Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1370::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->sortString(argument), ret);
}

auto values = ::testing::Values(
  ParamType("aaaabbbbcccc", "abccbaabccba"),
  ParamType("rat", "art"),
  ParamType("leetcode", "cdelotee"),
  ParamType("ggggggg", "ggggggg"),
  ParamType("spo", "ops")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1370ParamTest, LeetCode1370Test, values);

}
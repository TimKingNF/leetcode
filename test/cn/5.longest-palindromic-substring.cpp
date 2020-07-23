//
// Created by timking.nf@foxmail.com on 2020/7/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "5.longest-palindromic-substring.h"

namespace LeetCode5 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode5Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode5Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode5::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->longestPalindrome(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("babad", "bab"),
  ParamType("cbbd", "bb"),
  ParamType("a", "a"),
  ParamType("", ""),
  ParamType("aaaa", "aaaa"),
  ParamType("bb", "bb"),
  ParamType("bbb", "bbb"),
  ParamType("abcba", "abcba"),
  ParamType("dabcbaf", "abcba"),
  ParamType("abacab", "bacab"),
  ParamType("abcda", "a")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode5ParamTest, LeetCode5Test, values);

}
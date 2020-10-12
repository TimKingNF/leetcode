//
// Created by timking.nf@foxmail.com on 2020/8/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "516.longest-palindromic-subsequence.h"

namespace LeetCode516 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode516Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode516Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode516::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->longestPalindromeSubseq(argument), ret);
}

auto values = ::testing::Values(
  ParamType("bbbab", 4),
  ParamType("cbbd", 2)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode516ParamTest, LeetCode516Test, values);

}
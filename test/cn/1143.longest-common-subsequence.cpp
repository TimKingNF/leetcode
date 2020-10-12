//
// Created by timking.nf@foxmail.com on 2020/8/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1143.longest-common-subsequence.h"

namespace LeetCode1143 {

typedef tuple<string, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1143Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1143Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1143::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string text1, text2;
  tie(text1, text2) = arguments;

  ASSERT_EQ(solution->longestCommonSubsequence(text1, text2), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("abcde", "ace"), 3),
  ParamType(ArgumentType("abcde", "akcfe"), 3),
  ParamType(ArgumentType("abc", "abc"), 3),
  ParamType(ArgumentType("abc", "def"), 0),
  ParamType(ArgumentType("", "abc"), 0),
  ParamType(ArgumentType("aaade", "ea"), 1),
  ParamType(ArgumentType("aaade", "de"), 2),
  ParamType(ArgumentType("e", "aaade"), 1),
  ParamType(ArgumentType("bsbininm", "jmjkbkjkv"), 1)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1143ParamTest, LeetCode1143Test, values);

}
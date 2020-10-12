//
// Created by timking.nf@foxmail.com on 2020/8/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "10.regular-expression-matching.h"

namespace LeetCode10 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode10Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode10Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode10::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s, p;
  tie(s, p) = arguments;
  ASSERT_EQ(solution->isMatch(s, p), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("a", "a*a"), true),
  ParamType(ArgumentType("aa", "a"), false),
  ParamType(ArgumentType("aaa", "a*a"), true),
  ParamType(ArgumentType("aa", "a*"), true),
  ParamType(ArgumentType("abc", ".*"), true),
  ParamType(ArgumentType("aab", "c*a*b"), true),
  ParamType(ArgumentType("mississippi", "mis*is*p*."), false),
  ParamType(ArgumentType("aaa", "ab*a*c*a"), true),
  ParamType(ArgumentType("aaba", "ab*a*c*a"), false),
  ParamType(ArgumentType("bbbba", ".*a*a"), true)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode10ParamTest, LeetCode10Test, values);

}
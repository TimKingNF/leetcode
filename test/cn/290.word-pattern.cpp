//
// Created by timking.nf@foxmail.com on 2020/9/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "290.word-pattern.h"

namespace LeetCode290 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode290Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode290Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode290::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string pattern, s;
  tie(pattern, s) = arguments;
  ASSERT_EQ(solution->wordPattern(pattern, s), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("abba", "dog cat cat dog"), true),
  ParamType(ArgumentType("abba", "dog cat cat fish"), false),
  ParamType(ArgumentType("aaaa", "dog cat cat dog"), false),
  ParamType(ArgumentType("abba", "dog dog dog dog"), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode290ParamTest, LeetCode290Test, values);

}
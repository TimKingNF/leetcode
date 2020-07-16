//
// Created by timking.nf@foxmail.com on 2020/7/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "28.implement-strstr.h"

namespace LeetCode28 {

typedef tuple<string, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode28Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode28Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode28::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string haystack, needle;
  tie(haystack, needle) = arguments;

  ASSERT_EQ(solution->strStr(haystack, needle), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("hello", "ll"), 2),
  ParamType(ArgumentType("aaaaa", "bba"), -1),
  ParamType(ArgumentType("aaaaa", ""), 0),
  ParamType(ArgumentType("mississippi", "issip"), 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode28ParamTest, LeetCode28Test, values);

}
//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "424.longest-repeating-character-replacement.h"

namespace LeetCode424 {

typedef tuple<string, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode424Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode424Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode424::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s;
  int k;
  tie(s, k) = arguments;

  ASSERT_EQ(solution->characterReplacement(s, k), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("ABAB", 2), 4),
  ParamType(ArgumentType("AABABBA", 1), 4),
  ParamType(ArgumentType("AABDABBBAA", 2), 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode424ParamTest, LeetCode424Test, values);

}
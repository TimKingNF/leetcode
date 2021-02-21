//
// Created by timking.nf@foxmail.com on 2021/2/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "567.permutation-in-string.h"

namespace LeetCode567 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode567Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode567Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode567::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s1, s2;
  tie(s1, s2) = arguments;

  ASSERT_EQ(solution->checkInclusion(s1, s2), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("ab", "eidbaooo"), true),
  ParamType(ArgumentType("ab", "eidboaoo"), false),
  ParamType(ArgumentType("adc", "dcda"), true),
  ParamType(ArgumentType("hello", "ooolleoooleh"), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode567ParamTest, LeetCode567Test, values);

}
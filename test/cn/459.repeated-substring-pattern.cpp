//
// Created by timking.nf@foxmail.com on 2020/8/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "459.repeated-substring-pattern.h"

namespace LeetCode459 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode459Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode459Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode459::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->repeatedSubstringPattern(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("abab", true),
  ParamType("aba", false),
  ParamType("abcabcabcabc", true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode459ParamTest, LeetCode459Test, values);

}
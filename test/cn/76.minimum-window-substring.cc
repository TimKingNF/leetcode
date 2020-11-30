//
// Created by timking.nf@foxmail.com on 2020/11/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "76.minimum-window-substring.h"

namespace LeetCode76 {

typedef tuple<string, string> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode76Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode76Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode76::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s, t;
  tie(s, t) = arguments;

  ASSERT_EQ(solution->minWindow(s, t), ret);  // 可以有多个结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("ADOBECODEBANC", "ABC"), "BANC"),
  ParamType(ArgumentType("a", "a"), "a"),
  ParamType(ArgumentType("a", "aa"), "")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode76ParamTest, LeetCode76Test, values);

}
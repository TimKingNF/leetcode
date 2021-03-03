//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "796.rotate-string.h"

namespace LeetCode796 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode796Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode796Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode796::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string A, B;
  tie(A, B) = arguments;

  ASSERT_EQ(solution->rotateString(A, B), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("abcde", "cdeab"), true),
  ParamType(ArgumentType("abcde", "abced"), false),
  ParamType(ArgumentType("cdab", "abcd"), true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode796ParamTest, LeetCode796Test, values);

}
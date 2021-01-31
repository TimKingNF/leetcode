//
// Created by timking.nf@foxmail.com on 2020/12/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1081.smallest-subsequence-of-distinct-characters.h"

namespace LeetCode1081 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1081Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1081Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1081::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->smallestSubsequence(argument), ret);
}

auto values = ::testing::Values(
  ParamType("bcabc", "abc"),
  ParamType("cbacdcbc", "acdb"),
  ParamType("abcd", "abcd"),
  ParamType("ecbacba", "eacb")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1081ParamTest, LeetCode1081Test, values);

}
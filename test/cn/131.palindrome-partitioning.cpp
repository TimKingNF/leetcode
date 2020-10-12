//
// Created by timking.nf@foxmail.com on 2020/9/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "131.palindrome-partitioning.h"

namespace LeetCode131 {

typedef string ArgumentType;
typedef vector<vector<string>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode131Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode131Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode131::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType asserted = solution->partition(argument);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType("aab", {{"aa", "b"}, {"a", "a", "b"}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode131ParamTest, LeetCode131Test, values);

}
//
// Created by timking.nf@foxmail.com on 2021/3/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "132.palindrome-partitioning-ii.h"

namespace LeetCode132 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode132Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode132Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode132::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->minCut(argument), ret);
}

auto values = ::testing::Values(
  ParamType("aab", 1),
  ParamType("a", 0),
  ParamType("ab", 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode132ParamTest, LeetCode132Test, values);

}
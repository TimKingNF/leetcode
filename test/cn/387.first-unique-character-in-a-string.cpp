//
// Created by timking.nf@foxmail.com on 2020/7/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "387.first-unique-character-in-a-string.h"

namespace LeetCode387 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode387Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode387Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode387::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->firstUniqChar(argument), ret);
}

auto values = ::testing::Values(
  ParamType("leetcode", 0),
  ParamType("loveleetcode", 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode387ParamTest, LeetCode387Test, values);

}
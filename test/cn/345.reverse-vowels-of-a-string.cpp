//
// Created by timking.nf@foxmail.com on 2020/8/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "345.reverse-vowels-of-a-string.h"

namespace LeetCode345 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode345Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode345Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode345::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reverseVowels(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("hello", "holle"),
  ParamType("leetcode", "leotcede"),
  ParamType(" allyI", " Illya")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode345ParamTest, LeetCode345Test, values);

}
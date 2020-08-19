//
// Created by timking.nf@foxmail.com on 2020/8/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "647.palindromic-substrings.h"

namespace LeetCode647 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode647Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode647Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode647::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->countSubstrings(argument), ret);
}

auto values = ::testing::Values(
  ParamType("abc", 3),
  ParamType("aaa", 6),
  ParamType("aabb", 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode647ParamTest, LeetCode647Test, values);

}
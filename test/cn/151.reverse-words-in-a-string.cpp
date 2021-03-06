//
// Created by timking.nf@foxmail.com on 2020/6/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "151.reverse-words-in-a-string.h"

namespace LeetCode151 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode151Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode151Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode151::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reverseWords(argument), ret);
}

ArgumentType p1 = "the sky is blue";
ResultType r1 = "blue is sky the";

ArgumentType p2 = "  hello world!  ";
ResultType r2 = "world! hello";

ArgumentType p3 = "a good   example";
ResultType r3 = "example good a";

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3),
  ParamType(" ", ""),
  ParamType("", "")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode151ParamTest, LeetCode151Test, values);

}
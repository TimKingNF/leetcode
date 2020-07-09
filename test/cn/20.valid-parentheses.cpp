//
// Created by timking.nf@foxmail.com on 2020/6/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "20.valid-parentheses.h"

namespace LeetCode20 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode20Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode20Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode20::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isValid(argument), ret);  // 断言结果
}

ArgumentType p1 = "()";
ArgumentType p2 = "()[]{}";
ArgumentType p3 = "(]";
ArgumentType p4 = "([)]";
ArgumentType p5 = "{[]}";
ArgumentType p6 = "{";

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, true),
  ParamType(p3, false),
  ParamType(p4, false),
  ParamType(p5, true),
  ParamType(p6, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode20ParamTest, LeetCode20Test, values);

}
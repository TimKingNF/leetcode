//
// Created by timking.nf@foxmail.com on 2020/7/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1021.remove-outermost-parentheses.h"

namespace LeetCode1021 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1021Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1021Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1021::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->removeOuterParentheses(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("(()())(())", "()()()"),
  ParamType("(()())(())(()(()))", "()()()()(())"),
  ParamType("()()", "")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1021ParamTest, LeetCode1021Test, values);

}
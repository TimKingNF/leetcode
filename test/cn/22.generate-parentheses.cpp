//
// Created by timking.nf@foxmail.com on 2020/8/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "22.generate-parentheses.h"

namespace LeetCode22 {

typedef int ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode22Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode22Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode22::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType assertResult = solution->generateParenthesis(argument);
  ASSERT_TRUE(vector_unordered_cmp(assertResult, ret));
}

auto values = ::testing::Values(
  ParamType(0, {""}),
  ParamType(3, {"((()))",
                "(()())",
                "(())()",
                "()(())",
                "()()()"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode22ParamTest, LeetCode22Test, values);

}
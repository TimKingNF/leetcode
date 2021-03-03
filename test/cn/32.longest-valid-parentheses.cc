//
// Created by timking.nf@foxmail.com on 2021/3/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "32.longest-valid-parentheses.h"

namespace LeetCode32 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode32Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode32Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode32::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->longestValidParentheses(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("(()", 2),
  ParamType(")()())", 4),
  ParamType("", 0),
  ParamType("(()())", 6),
  ParamType("()(()()(", 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode32ParamTest, LeetCode32Test, values);

}
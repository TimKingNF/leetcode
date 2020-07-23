//
// Created by timking.nf@foxmail.com on 2020/7/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "150.evaluate-reverse-polish-notation.h"

namespace LeetCode150 {

typedef vector<string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode150Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode150Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode150::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->evalRPN(argument), ret);
}

auto values = ::testing::Values(
  ParamType({"2", "1", "+", "3", "*"}, 9),
  ParamType({"4", "13", "5", "/", "+"}, 6),
  ParamType({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"}, 22),
  ParamType({}, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode150ParamTest, LeetCode150Test, values);

}
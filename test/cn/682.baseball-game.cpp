//
// Created by timking.nf@foxmail.com on 2020/6/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "682.baseball-game.h"

namespace LeetCode682 {

typedef vector<string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode682Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode682Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode682::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->calPoints(argument), ret);  // 断言结果
}

ArgumentType p1{"5","2","C","D","+"};
ResultType r1 = 30;

ArgumentType p2{"5","-2","4","C","D","9","+","+"};
ResultType r2 = 27;

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode682ParamTest, LeetCode682Test, values);

}
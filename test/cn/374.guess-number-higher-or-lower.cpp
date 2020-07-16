//
// Created by timking.nf@foxmail.com on 2020/7/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "374.guess-number-higher-or-lower.h"

namespace LeetCode374 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode374Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode374Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode374::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->guessNumber(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(10, 6),
  ParamType(100, 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode374ParamTest, LeetCode374Test, values);

}
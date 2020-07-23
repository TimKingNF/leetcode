//
// Created by timking.nf@foxmail.com on 2020/7/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "279.perfect-squares.h"

namespace LeetCode279 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode279Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode279Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode279::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->numSquares(argument), ret);
}

auto values = ::testing::Values(
  ParamType(12, 3),
  ParamType(13, 2),
  ParamType(4, 1)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode279ParamTest, LeetCode279Test, values);

}
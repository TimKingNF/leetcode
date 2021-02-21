//
// Created by timking.nf@foxmail.com on 2021/2/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_16_01.swap-numbers-lcci.h"

namespace LeetCode_16_01 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_16_01Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_16_01Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_16_01::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->swapNumbers(argument), ret);
}

auto values = ::testing::Values(
  ParamType({1,2}, {2,1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_16_01ParamTest, LeetCode_16_01Test, values);

}
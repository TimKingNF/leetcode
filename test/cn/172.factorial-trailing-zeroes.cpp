//
// Created by timking.nf@foxmail.com on 2020/8/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "172.factorial-trailing-zeroes.h"

namespace LeetCode172 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode172Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode172Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode172::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->trailingZeroes(argument), ret);
}

auto values = ::testing::Values(
  ParamType(3, 0),
  ParamType(5, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode172ParamTest, LeetCode172Test, values);

}
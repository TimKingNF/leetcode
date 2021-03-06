//
// Created by timking.nf@foxmail.com on 2020/7/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "231.power-of-two.h"

namespace LeetCode231 {

typedef int ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode231Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode231Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode231::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isPowerOfTwo(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(1, true),
  ParamType(16, true),
  ParamType(218, false),
  ParamType(0, false),
  ParamType(-2147483648, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode231ParamTest, LeetCode231Test, values);

}

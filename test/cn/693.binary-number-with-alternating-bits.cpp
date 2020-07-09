//
// Created by timking.nf@foxmail.com on 2020/7/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "693.binary-number-with-alternating-bits.h"

namespace LeetCode693 {

typedef int ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode693Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode693Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode693::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->hasAlternatingBits(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(5, true),
  ParamType(7, false),
  ParamType(11, false),
  ParamType(10, true),
  ParamType(6, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode693ParamTest, LeetCode693Test, values);

}
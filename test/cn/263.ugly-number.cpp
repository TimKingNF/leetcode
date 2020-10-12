//
// Created by timking.nf@foxmail.com on 2020/9/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "263.ugly-number.h"

namespace LeetCode263 {

typedef int ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode263Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode263Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode263::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isUgly(argument), ret);
}

auto values = ::testing::Values(
  ParamType(6, true),
  ParamType(8, true),
  ParamType(14, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode263ParamTest, LeetCode263Test, values);

}
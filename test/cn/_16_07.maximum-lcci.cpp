//
// Created by timking.nf@foxmail.com on 2020/7/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_16_07.maximum-lcci.h"

namespace LeetCode_16_07 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_16_07Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_16_07Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_16_07::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int a, b;
  tie(a, b) = arguments;

  ASSERT_EQ(solution->maximum(a, b), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType(1, 2), 2),
  ParamType(ArgumentType(-1, 0), 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_16_07ParamTest, LeetCode_16_07Test, values);

}
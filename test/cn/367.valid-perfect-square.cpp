//
// Created by timking.nf@foxmail.com on 2020/7/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "367.valid-perfect-square.h"

namespace LeetCode367 {

typedef int ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode367Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode367Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode367::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isPerfectSquare(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(16, true),
  ParamType(14, false),
  ParamType(18, false),
  ParamType(5, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode367ParamTest, LeetCode367Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/7/7.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1342.number-of-steps-to-reduce-a-number-to-zero.h"

namespace LeetCode1342 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1342Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1342Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1342::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->numberOfSteps(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(14, 6),
  ParamType(8, 4),
  ParamType(123, 12)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1342ParamTest, LeetCode1342Test, values);

}
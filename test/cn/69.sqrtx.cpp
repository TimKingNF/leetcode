//
// Created by timking.nf@foxmail.com on 2020/7/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "69.sqrtx.h"

namespace LeetCode69 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode69Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode69Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode69::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->mySqrt(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(4, 2),
  ParamType(6, 2),
  ParamType(8, 2),
  ParamType(25, 5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode69ParamTest, LeetCode69Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/5/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "746.min-cost-climbing-stairs.h"

namespace LeetCode746 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode746Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode746Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode746::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->minCostClimbingStairs(argument), ret);  // 断言结果
}

ArgumentType p1{10, 15, 20};
ArgumentType p2{1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

auto values = ::testing::Values(
  ParamType(p1, 15),
  ParamType(p2, 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode746ParamTest, LeetCode746Test, values);

}

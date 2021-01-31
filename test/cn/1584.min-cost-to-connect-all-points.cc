//
// Created by timking.nf@foxmail.com on 2021/1/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1584.min-cost-to-connect-all-points.h"

namespace LeetCode1584 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1584Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1584Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1584::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->minCostConnectPoints(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{0,0},{2,2},{3,10},{5,2},{7,0}}, 20),
  ParamType({{3,12},{-2,5},{-4,1}}, 18),
  ParamType({{0,0},{1,1},{1,0},{-1,1}}, 4),
  ParamType({{-1000000,-1000000},{1000000,1000000}}, 4000000),
  ParamType({{0,0}}, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1584ParamTest, LeetCode1584Test, values);

}
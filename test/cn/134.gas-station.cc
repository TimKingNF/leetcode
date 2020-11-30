//
// Created by timking.nf@foxmail.com on 2020/11/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "134.gas-station.h"

namespace LeetCode134 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode134Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode134Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode134::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> gas, cost;
  tie(gas, cost) = arguments;

  ASSERT_EQ(solution->canCompleteCircuit(gas, cost), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,3,4,5}, {3,4,5,1,2}), 3),
  ParamType(ArgumentType({2,3,4}, {3,4,3}), -1),
  ParamType(ArgumentType({5,1,2,3,4}, {4,4,1,5,1}), 4),
  ParamType(ArgumentType({5,8,2,8}, {6,5,6,6}), 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode134ParamTest, LeetCode134Test, values);

}
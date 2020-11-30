//
// Created by timking.nf@foxmail.com on 2020/11/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "452.minimum-number-of-arrows-to-burst-balloons.h"

namespace LeetCode452 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode452Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode452Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode452::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findMinArrowShots(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{10,16}, {2,8}, {1,6}, {7,12}}, 2),
  ParamType({{1,2}, {3,4}, {5,6}, {7,8}}, 4),
  ParamType({{1,2}, {2,3}, {3,4}, {4,5}}, 2),
  ParamType({{1,2}}, 1),
  ParamType({{2,3}, {2,3}}, 1),
  ParamType({{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}}, 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode452ParamTest, LeetCode452Test, values);

}
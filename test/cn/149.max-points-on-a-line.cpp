//
// Created by timking.nf@foxmail.com on 2020/8/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "149.max-points-on-a-line.h"

namespace LeetCode149 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode149Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode149Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode149::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->maxPoints(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{0,0}}, 1),
  ParamType({{1,1}, {2,2}, {3,3}}, 3),
  ParamType({{3,10},{0,2},{0,2},{3,10}}, 4),
  ParamType({{1,1}, {3,2}, {5,3}, {4,1}, {2,3}, {1,4}}, 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode149ParamTest, LeetCode149Test, values);

}
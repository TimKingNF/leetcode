//
// Created by timking.nf@foxmail.com on 2020/10/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "463.island-perimeter.h"

namespace LeetCode463 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode463Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode463Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode463::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->islandPerimeter(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{0,1,0,0}, {1,1,1,0}, {0,1,0,0}, {1,1,0,0}}, 16)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode463ParamTest, LeetCode463Test, values);

}
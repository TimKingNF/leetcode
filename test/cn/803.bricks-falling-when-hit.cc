//
// Created by timking.nf@foxmail.com on 2021/1/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "803.bricks-falling-when-hit.h"

namespace LeetCode803 {

typedef tuple<vector<vector<int>>, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode803Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode803Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode803::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<vector<int>> grid, hits;
  tie(grid, hits) = arguments;

  ASSERT_EQ(solution->hitBricks(grid, hits), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({{1,0,0,0},{1,1,1,0}}, {{1,0}}), {2}),
  ParamType(ArgumentType({{1,0,0,0},{1,1,0,0}}, {{1,1},{1,0}}), {0,0})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode803ParamTest, LeetCode803Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/10/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "834.sum-of-distances-in-tree.h"

namespace LeetCode834 {

typedef tuple<int, vector<vector<int>>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode834Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode834Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode834::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int N;
  vector<vector<int>> edges;
  tie(N, edges) = arguments;

  ASSERT_EQ(solution->sumOfDistancesInTree(N, edges), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType(6, {{0,1}, {0,2}, {2,3}, {2,4}, {2,5}}),
            {8,12,6,10,10,10})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode834ParamTest, LeetCode834Test, values);

}
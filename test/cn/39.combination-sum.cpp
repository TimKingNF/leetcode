//
// Created by timking.nf@foxmail.com on 2020/9/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "39.combination-sum.h"

namespace LeetCode39 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode39Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode39Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode39::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> candidates;
  int target;
  tie(candidates, target) = arguments;

  ResultType asserted = solution->combinationSum(candidates, target);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(double_vector_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({2,3,6,7}, 7), {{7}, {2,2,3}}),
  ParamType(ArgumentType({2,3,5}, 8), {{2,2,2,2}, {2,3,3}, {3,5}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode39ParamTest, LeetCode39Test, values);

}
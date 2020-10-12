//
// Created by timking.nf@foxmail.com on 2020/9/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "40.combination-sum-ii.h"

namespace LeetCode40 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode40Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode40Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode40::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> candidates;
  int target;
  tie(candidates, target) = arguments;

  ResultType asserted = solution->combinationSum2(candidates, target);
  ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(double_vector_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType(ArgumentType({10,1,2,7,6,1,5}, 8),
            {{1,7}, {1,2,5}, {2,6}, {1,1,6}}),
  ParamType(ArgumentType({2,5,2,1,2}, 5), {{1,2,2}, {5}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode40ParamTest, LeetCode40Test, values);

}
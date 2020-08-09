//
// Created by timking.nf@foxmail.com on 2020/8/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "46.permutations.h"

namespace LeetCode46 {

typedef vector<int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode46Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode46Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode46::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType assertResult = solution->permute(argument);
  ASSERT_TRUE(vector_unordered_cmp(assertResult, ret));
}

auto values = ::testing::Values(
  ParamType({1,2,3}, {{1,2,3},
                      {1,3,2},
                      {2,1,3},
                      {2,3,1},
                      {3,1,2},
                      {3,2,1}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode46ParamTest, LeetCode46Test, values);

}
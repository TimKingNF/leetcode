//
// Created by timking.nf@foxmail.com on 2020/8/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "491.increasing-subsequences.h"

namespace LeetCode491 {

typedef vector<int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode491Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode491Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode491::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<vector<int>> asserted = solution->findSubsequences(argument);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType({4,6,7,7}, {{4, 6},
                                {4, 7},
                                {4, 6, 7},
                                {4, 6, 7, 7},
                                {6, 7},
                                {6, 7, 7},
                                {7,7},
                                {4,7,7}}),
  ParamType({4,7,6,7}, {{4,7},{4,7,7},{4,6},{4,6,7},{7,7},{6,7}})
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode491ParamTest, LeetCode491Test, values);

}
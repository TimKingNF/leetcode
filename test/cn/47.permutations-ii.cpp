//
// Created by timking.nf@foxmail.com on 2020/8/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "47.permutations-ii.h"

namespace LeetCode47 {

typedef vector<int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode47Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode47Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode47::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType assertResult = solution->permuteUnique(argument);
  ASSERT_TRUE(vector_unordered_cmp(assertResult, ret));
}

auto values = ::testing::Values(
  ParamType({1,1,2}, {{1,1,2},
                      {1,2,1},
                      {2,1,1}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode47ParamTest, LeetCode47Test, values);

}
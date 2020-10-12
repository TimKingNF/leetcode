//
// Created by timking.nf@foxmail.com on 2020/9/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "216.combination-sum-iii.h"

namespace LeetCode216 {

typedef tuple<int, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode216Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode216Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode216::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int k, n;
  tie(k, n) = arguments;

  ResultType asserted = solution->combinationSum3(k, n);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(double_vector_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType(ArgumentType(3, 7), {{1,2,4}}),
  ParamType(ArgumentType(3, 9), {{1,2,6}, {1,3,5}, {2,3,4}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode216ParamTest, LeetCode216Test, values);

}
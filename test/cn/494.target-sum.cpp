//
// Created by timking.nf@foxmail.com on 2020/7/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "494.target-sum.h"

namespace LeetCode494 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode494Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode494Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode494::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int S;
  tie(nums, S) = arguments;

  ASSERT_EQ(solution->findTargetSumWays(nums, S), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,1,1,1,1}, 3), 5),
  ParamType(ArgumentType({1,1,1}, 3), 1)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode494ParamTest, LeetCode494Test, values);

}
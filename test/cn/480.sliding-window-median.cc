//
// Created by timking.nf@foxmail.com on 2021/2/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "480.sliding-window-median.h"

namespace LeetCode480 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<double> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode480Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode480Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode480::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int k;
  tie(nums, k) = arguments;

  ResultType asserted = solution->medianSlidingWindow(nums, k);
  for (int i = 0; i < ret.size(); ++i) {
    ASSERT_DOUBLE_EQ(asserted[i], ret[i]);
  }
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,3,-1,-3,5,3,6,7}, 3), {1,-1,-1,3,5,6})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode480ParamTest, LeetCode480Test, values);

}
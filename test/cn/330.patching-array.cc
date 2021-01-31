//
// Created by timking.nf@foxmail.com on 2020/12/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "330.patching-array.h"

namespace LeetCode330 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode330Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode330Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode330::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<int> nums;
  int n;
  tie(nums, n) = argument;

  ASSERT_EQ(solution->minPatches(nums, n), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,3}, 6), 1),
  ParamType(ArgumentType({1,5,10}, 20), 2),
  ParamType(ArgumentType({1,2,2}, 5), 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode330ParamTest, LeetCode330Test, values);

}
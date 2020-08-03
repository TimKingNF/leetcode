//
// Created by timking.nf@foxmail.com on 2020/6/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "34.find-first-and-last-position-of-element-in-sorted-array.h"

namespace LeetCode34 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode34Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode34Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode34::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  vector<int> nums;
  int target;
  tie(nums, target) = arguments;

  ASSERT_EQ(solution->searchRange(nums, target), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({5,7,7,8,8,10}, 8), {3,4}),
  ParamType(ArgumentType({5,7,7,8,8,10}, 6), {-1,-1}),
  ParamType(ArgumentType({2,2}, 3), {-1,-1}),
  ParamType(ArgumentType({1,1,2}, 1), {0,1}),
  ParamType(ArgumentType({1}, 1), {0,0})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode34ParamTest, LeetCode34Test, values);

}

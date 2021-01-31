//
// Created by timking.nf@foxmail.com on 2020/12/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "321.create-maximum-number.h"

namespace LeetCode321 {

typedef tuple<vector<int>, vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode321Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode321Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode321::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums1, nums2;
  int k;
  tie(nums1, nums2, k) = arguments;

  ASSERT_EQ(solution->maxNumber(nums1, nums2, k), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({}, {9,1,9,5,8,3}, 3), {9,9,8}),
  ParamType(ArgumentType({3,4,6,5}, {9,1,2,5,8,3}, 5), {9,8,6,5,3}),
  ParamType(ArgumentType({6,7}, {6,0,4}, 5), {6,7,6,0,4}),
  ParamType(ArgumentType({3,9}, {8,9}, 3), {9,8,9})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode321ParamTest, LeetCode321Test, values);

}
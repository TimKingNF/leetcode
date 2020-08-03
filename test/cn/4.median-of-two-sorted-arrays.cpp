//
// Created by timking.nf@foxmail.com on 2020/8/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "4.median-of-two-sorted-arrays.h"

namespace LeetCode4 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef double ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode4Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode4Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode4::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums1, nums2;
  tie(nums1, nums2) = arguments;
  ASSERT_DOUBLE_EQ(solution->findMedianSortedArrays(nums1, nums2), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,3}, {2}), 2.0),
  ParamType(ArgumentType({1,2}, {3,4}), 2.5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode4ParamTest, LeetCode4Test, values);

}
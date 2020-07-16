//
// Created by timking.nf@foxmail.com on 2020/7/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "349.intersection-of-two-arrays.h"

namespace LeetCode349 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode349Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode349Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode349::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums1, nums2;
  tie(nums1, nums2) = arguments;

  vector<int> asserted = solution->intersection(nums1, nums2);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,2,1}, {2,2}), {2}),
  ParamType(ArgumentType({4,9,5}, {9,4,9,8,4}), {9,4})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode349ParamTest, LeetCode349Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/7/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "347.top-k-frequent-elements.h"

namespace LeetCode347 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode347Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode347Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode347::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int k;
  tie(nums, k) = arguments;

  ResultType asserted = solution->topKFrequent(nums, k);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
  // ASSERT_EQ(asserted, ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,1,1,2,2,3}, 2), {1,2}),
  ParamType(ArgumentType({1}, 1), {1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode347ParamTest, LeetCode347Test, values);

}
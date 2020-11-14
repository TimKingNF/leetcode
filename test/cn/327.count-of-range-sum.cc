//
// Created by timking.nf@foxmail.com on 2020/11/7.
//

#include "gtest/gtest.h"
#include "header.h"
#include "327.count-of-range-sum.h"

namespace LeetCode327 {

typedef tuple<vector<int>, int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode327Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode327Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode327::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int lower, upper;
  tie(nums, lower, upper) = arguments;

  ASSERT_EQ(solution->countRangeSum(nums, lower, upper), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({-2,5,-1}, -2, 2), 3),
  ParamType(ArgumentType({0,-3,-3,1,1,2}, 3, 5), 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode327ParamTest, LeetCode327Test, values);

}
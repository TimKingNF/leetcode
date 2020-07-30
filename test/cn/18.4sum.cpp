//
// Created by timking.nf@foxmail.com on 2020/7/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "18.4sum.h"

namespace LeetCode18 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode18Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode18Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode18::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> nums;
  int target;
  tie(nums, target) = arguments;

  ResultType asserted = solution->fourSum(nums, target);
  ASSERT_TRUE(double_vector_cmp<int>(asserted, ret));
  // ASSERT_EQ(asserted, ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1, 0, -1, 0, -2, 2}, 0), {{-1,  0, 0, 1},
                                                    {-2, -1, 1, 2},
                                                    {-2,  0, 0, 2}}),
  ParamType(ArgumentType({0,0,0,0,0}, 0), {{0,0,0,0}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode18ParamTest, LeetCode18Test, values);

}
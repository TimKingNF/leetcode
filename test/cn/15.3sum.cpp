//
// Created by timking.nf@foxmail.com on 2020/7/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "15.3sum.h"

namespace LeetCode15 {

typedef vector<int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode15Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode15Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode15::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType asserted = solution->threeSum(argument);
  ASSERT_EQ(asserted, ret);
  // ASSERT_TRUE(double_vector_cmp<int>(asserted, ret));
}

auto values = ::testing::Values(
  ParamType({-1, 0, 1, 2, -1, -4}, {{-1, -1, 2},
                                    {-1, 0, 1}}),
  ParamType({0,0,0,0}, {{0,0,0}}),
  ParamType({0,0}, {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode15ParamTest, LeetCode15Test, values);

}
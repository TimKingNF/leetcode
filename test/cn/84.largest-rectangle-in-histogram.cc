//
// Created by timking.nf@foxmail.com on 2020/12/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "84.largest-rectangle-in-histogram.h"

namespace LeetCode84 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode84Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode84Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode84::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  return;

  ASSERT_EQ(solution->largestRectangleArea(argument), ret);
}

auto values = ::testing::Values(
  ParamType({2,1,5,6,2,3}, 10)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode84ParamTest, LeetCode84Test, values);

}
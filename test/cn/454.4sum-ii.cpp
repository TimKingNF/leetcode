//
// Created by timking.nf@foxmail.com on 2020/7/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "454.4sum-ii.h"

namespace LeetCode454 {

typedef tuple<vector<int>, vector<int>, vector<int>, vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode454Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode454Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode454::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> A,B,C,D;
  tie(A,B,C,D) = arguments;
  ASSERT_EQ(solution->fourSumCount(A,B,C,D), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2}, {-2,-1}, {-1,2}, {0,2}), 2),
  ParamType(ArgumentType({0,0}, {0,0}, {0,0}, {0,0}), 16)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode454ParamTest, LeetCode454Test, values);

}
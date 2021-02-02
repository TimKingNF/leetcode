//
// Created by timking.nf@foxmail.com on 2021/2/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "888.fair-candy-swap.h"

namespace LeetCode888 {

typedef tuple<vector<int>, vector<int>> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode888Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode888Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode888::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> A, B;
  tie(A, B) = arguments;

  ASSERT_EQ(solution->fairCandySwap(A, B), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,1}, {2,2}), {1,2}),
  ParamType(ArgumentType({1,2}, {2,3}), {1,2}),
  ParamType(ArgumentType({2}, {1,3}), {2,3}),
  ParamType(ArgumentType({1,2,5}, {2,4}), {5,4})
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode888ParamTest, LeetCode888Test, values);

}
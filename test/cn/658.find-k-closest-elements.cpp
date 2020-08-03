//
// Created by timking.nf@foxmail.com on 2020/7/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "658.find-k-closest-elements.h"

namespace LeetCode658 {

typedef tuple<vector<int>, int, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode658Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode658Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode658::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> arr;
  int k, x;
  tie(arr, k, x) = arguments;

  ASSERT_EQ(solution->findClosestElements(arr, k, x), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({0,2,3,4,5}, 4, 3), {2,3,4,5}),
  ParamType(ArgumentType({1,2,3,4,5}, 4, 3), {1,2,3,4}),
  ParamType(ArgumentType({1,2,3,4,5}, 4, -1), {1,2,3,4}),
  ParamType(ArgumentType({1,2,3,4,5}, 4, 6), {2,3,4,5}),
  ParamType(ArgumentType({1,3}, 1, 2), {1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode658ParamTest, LeetCode658Test, values);

}
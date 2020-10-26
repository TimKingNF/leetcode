//
// Created by timking.nf@foxmail.com on 2020/10/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "977.squares-of-a-sorted-array.h"

namespace LeetCode977 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode977Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode977Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode977::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->sortedSquares(argument), ret);
}

auto values = ::testing::Values(
  ParamType({-4, -1, 0, 3, 10}, {0, 1, 9, 16, 100}),
  ParamType({-7, -3, 2, 3, 11}, {4, 9, 9, 49, 121})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode977ParamTest, LeetCode977Test, values);

}
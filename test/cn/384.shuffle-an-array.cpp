//
// Created by timking.nf@foxmail.com on 2020/7/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "384.shuffle-an-array.h"

namespace LeetCode384 {

typedef vector<int> ArgumentType;
// typedef vector<int> ResultType;
// typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode384Test : public ::testing::TestWithParam<ArgumentType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode384Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  ArgumentType argument;
  argument = GetParam();

  Solution* solution = new Solution(argument);
  ASSERT_EQ(solution->reset(), argument);
  vector<int> shuffle = solution->shuffle();
  ASSERT_TRUE(vector_unordered_cmp(shuffle, argument));
  ASSERT_EQ(solution->reset(), argument);
}

ArgumentType p1 = {1, 2, 3};

auto values = ::testing::Values(
  p1
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode384ParamTest, LeetCode384Test, values);

}
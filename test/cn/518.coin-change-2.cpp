//
// Created by timking.nf@foxmail.com on 2020/8/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "518.coin-change-2.h"

namespace LeetCode518 {

typedef tuple<int, vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode518Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode518Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode518::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int amount;
  vector<int> coins;
  tie(amount, coins) = arguments;

  ASSERT_EQ(solution->change(amount, coins), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(5, {1,2,5}), 4),
  ParamType(ArgumentType(3, {2}), 0),
  ParamType(ArgumentType(10, {10}), 1)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode518ParamTest, LeetCode518Test, values);

}
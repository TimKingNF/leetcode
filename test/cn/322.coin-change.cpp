//
// Created by timking.nf@foxmail.com on 2020/8/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "322.coin-change.h"

namespace LeetCode322 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode322Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode322Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode322::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> coins;
  int amount;
  tie(coins, amount) = arguments;

  ASSERT_EQ(solution->coinChange(coins, amount), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,5}, 11), 3),
  ParamType(ArgumentType({2}, 3), -1)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode322ParamTest, LeetCode322Test, values);

}
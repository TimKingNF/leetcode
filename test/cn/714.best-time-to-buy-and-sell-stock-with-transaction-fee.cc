//
// Created by timking.nf@foxmail.com on 2020/12/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "714.best-time-to-buy-and-sell-stock-with-transaction-fee.h"

namespace LeetCode714 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode714Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode714Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode714::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> prices;
  int fee;
  tie(prices, fee) = arguments;

  ASSERT_EQ(solution->maxProfit(prices, fee), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1, 3, 2, 8, 4, 9}, 2), 8),
  ParamType(ArgumentType({1}, 0), 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode714ParamTest, LeetCode714Test, values);

}
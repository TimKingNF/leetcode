//
// Created by timking.nf@foxmail.com on 2020/7/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "739.daily-temperatures.h"

namespace LeetCode739 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode739Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode739Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode739::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->dailyTemperatures(argument), ret);
}

auto values = ::testing::Values(
  ParamType({73, 74, 75, 71, 69, 72, 76, 73}, {1, 1, 4, 2, 1, 1, 0, 0}),
  ParamType({}, {}),
  ParamType({67, 1, 1}, {0, 0, 0}),
  ParamType({1, 2, 3, 4}, {1, 1, 1, 0})
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode739ParamTest, LeetCode739Test, values);

}
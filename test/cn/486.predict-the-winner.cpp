//
// Created by timking.nf@foxmail.com on 2020/9/01.
//

#include "gtest/gtest.h"
#include "header.h"
#include "486.predict-the-winner.h"

namespace LeetCode486 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode486Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode486Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode486::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->PredictTheWinner(argument), ret);
}

auto values = ::testing::Values(
  ParamType({1,5,2}, false),
  ParamType({1,5,233,7}, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode486ParamTest, LeetCode486Test, values);

}
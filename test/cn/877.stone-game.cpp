//
// Created by timking.nf@foxmail.com on 2020/8/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "877.stone-game.h"

namespace LeetCode877 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode877Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode877Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode877::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->stoneGame(argument), ret);
}

auto values = ::testing::Values(
  ParamType({5,3,4,5}, true),
  ParamType({5,3,4,5,2}, true),
  ParamType({2,5,3,4,5,2}, true)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode877ParamTest, LeetCode877Test, values);

}
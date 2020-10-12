//
// Created by timking.nf@foxmail.com on 2020/8/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "679.24-game.h"

namespace LeetCode679 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode679Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode679Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode679::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->judgePoint24(argument), ret);
}

auto values = ::testing::Values(
  ParamType({4,1,8,7}, true),
  ParamType({1,2,1,2}, false)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode679ParamTest, LeetCode679Test, values);

}
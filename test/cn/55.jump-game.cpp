//
// Created by timking.nf@foxmail.com on 2020/8/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "55.jump-game.h"

namespace LeetCode55 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode55Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode55Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode55::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->canJump(argument), ret);
}

auto values = ::testing::Values(
  ParamType({0}, true),
  ParamType({2,3,1,1,4}, true),
  ParamType({3,2,1,0,4}, false)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode55ParamTest, LeetCode55Test, values);

}
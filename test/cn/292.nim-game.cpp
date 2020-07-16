//
// Created by timking.nf@foxmail.com on 2020/7/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "292.nim-game.h"

namespace LeetCode292 {

typedef int ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode292Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode292Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode292::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->canWinNim(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(4, false),
  ParamType(5, true),
  ParamType(8, false),
  ParamType(12, false),
  ParamType(999, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode292ParamTest, LeetCode292Test, values);

}
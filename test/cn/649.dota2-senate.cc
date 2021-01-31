//
// Created by timking.nf@foxmail.com on 2020/12/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "649.dota2-senate.h"

namespace LeetCode649 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode649Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode649Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode649::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->predictPartyVictory(argument), ret);
}

auto values = ::testing::Values(
  ParamType("RD", "Radiant"),
  ParamType("RDD", "Dire")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode649ParamTest, LeetCode649Test, values);

}
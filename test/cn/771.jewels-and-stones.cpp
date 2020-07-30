//
// Created by timking.nf@foxmail.com on 2020/7/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "771.jewels-and-stones.h"

namespace LeetCode771 {

typedef tuple<string, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode771Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode771Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode771::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string J, S;
  tie(J, S) = arguments;
  ASSERT_EQ(solution->numJewelsInStones(J, S), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("aA", "aAAbbbb"), 3),
  ParamType(ArgumentType("z", "ZZ"), 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode771ParamTest, LeetCode771Test, values);

}
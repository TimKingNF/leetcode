//
// Created by timking.nf@foxmail.com on 2021/1/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1018.binary-prefix-divisible-by-5.h"

namespace LeetCode1018 {

typedef vector<int> ArgumentType;
typedef vector<bool> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1018Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1018Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1018::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->prefixesDivBy5(argument), ret);
}

auto values = ::testing::Values(
  ParamType({0,1,1}, {true, false, false}),
  ParamType({1,1,1}, {false, false, false}),
  ParamType({0,1,1,1,1,1}, {true, false, false, false, true, false}),
  ParamType({1,1,1,0,1}, {false, false, false, false, false})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1018ParamTest, LeetCode1018Test, values);

}
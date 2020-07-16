//
// Created by timking.nf@foxmail.com on 2020/7/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "137.single-number-ii.h"

namespace LeetCode137 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode137Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode137Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode137::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->singleNumber(argument), ret);
}

auto values = ::testing::Values(
  ParamType({3,4,3,3}, 4),
  ParamType({2,2,3,2}, 3),
  ParamType({0,1,0,1,0,1,99}, 99)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode137ParamTest, LeetCode137Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/8/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_08_01.three-steps-problem-lcci.h"

namespace LeetCode_08_01 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_08_01Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_08_01Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_08_01::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->waysToStep(argument), ret);

  // 变种题
  // int diffStepWays = solution->waysToDiffStep(argument);
  //
  // auto steps = solution->printWaysToDiffStep(argument);
  // ASSERT_EQ(diffStepWays, steps.size());
  // for (auto v : steps) {
  //   vector_print(v);
  // }
}

auto values = ::testing::Values(
  ParamType(3, 4),
  ParamType(5, 13),
  ParamType(15, 5768)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_08_01ParamTest, LeetCode_08_01Test, values);

}
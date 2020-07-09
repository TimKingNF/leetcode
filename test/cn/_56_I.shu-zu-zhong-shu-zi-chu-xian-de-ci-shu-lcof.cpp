//
// Created by timking.nf@foxmail.com on 2020/6/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_56_I.shu-zu-zhong-shu-zi-chu-xian-de-ci-shu-lcof.h"

namespace LeetCode_56_I {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_56_ITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_56_ITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_56_I::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType asserted = solution->singleNumbers(argument);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

ArgumentType p1{4,1,4,6};
ArgumentType p2{1,2,10,4,1,4,3,3};

ResultType r1{1,6};
ResultType r2{2,10};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_56_IParamTest, LeetCode_56_ITest, values);

}
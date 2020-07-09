//
// Created by timking.nf@foxmail.com on 2020/6/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_60.nge-tou-zi-de-dian-shu-lcof.h"

namespace LeetCode_60 {

typedef int ArgumentType;
typedef vector<double> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_60Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_60Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_60::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  auto asserts = solution->twoSum(argument);
  // vector_print(asserts);
  // ASSERT_EQ(asserts, ret);
  
}

auto values = ::testing::Values(
  ParamType(1, {}),
  ParamType(2, {}),
  ParamType(3, {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_60ParamTest, LeetCode_60Test, values);

}

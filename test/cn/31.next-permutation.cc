//
// Created by timking.nf@foxmail.com on 2020/11/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "31.next-permutation.h"

namespace LeetCode31 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode31Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode31Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode31::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  solution->nextPermutation(argument);
  ASSERT_EQ(argument, ret);
}

auto values = ::testing::Values(
  ParamType({1,2,3}, {1,3,2}),
  ParamType({3,2,1}, {1,2,3}),
  ParamType({1,1,5}, {1,5,1})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode31ParamTest, LeetCode31Test, values);

}
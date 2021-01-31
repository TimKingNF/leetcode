//
// Created by timking.nf@foxmail.com on 2021/1/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "989.add-to-array-form-of-integer.h"

namespace LeetCode989 {

typedef tuple<vector<int>, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode989Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode989Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode989::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> A;
  int K;
  tie(A, K) = arguments;

  ASSERT_EQ(solution->addToArrayForm(A, K), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({1,2,0,0}, 34), {1,2,3,4}),
  ParamType(ArgumentType({2,7,4}, 181), {4,5,5}),
  ParamType(ArgumentType({2,1,5}, 806), {1,0,2,1}),
  ParamType(ArgumentType({0}, 23), {2,3}),
  ParamType(ArgumentType({9,9,9,9,9,9,9,9,9,9}, 1), {1,0,0,0,0,0,0,0,0,0,0})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode989ParamTest, LeetCode989Test, values);

}
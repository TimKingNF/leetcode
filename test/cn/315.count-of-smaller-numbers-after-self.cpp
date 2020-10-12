//
// Created by timking.nf@foxmail.com on 2020/8/19.
//

#include "gtest/gtest.h"
#include "header.h"
#include "315.count-of-smaller-numbers-after-self.h"

namespace LeetCode315 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode315Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode315Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode315::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->countSmaller(argument), ret);
}

auto values = ::testing::Values(
  ParamType({5,2,6,1}, {2,1,1,0}),
  ParamType({}, {}),
  ParamType({1}, {0}),
  ParamType({5,2,6,1,0}, {3,2,2,1,0})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode315ParamTest, LeetCode315Test, values);

}
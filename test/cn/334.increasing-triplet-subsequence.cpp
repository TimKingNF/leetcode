//
// Created by timking.nf@foxmail.com on 2020/8/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "334.increasing-triplet-subsequence.h"

namespace LeetCode334 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode334Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode334Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode334::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->increasingTriplet(argument), ret);
}

auto values = ::testing::Values(
  ParamType({1,2,3,4,5}, true),
  ParamType({5,4,3,2,1}, false)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode334ParamTest, LeetCode334Test, values);

}
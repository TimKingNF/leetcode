//
// Created by timking.nf@foxmail.com on 2020/8/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "493.reverse-pairs.h"

namespace LeetCode493 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode493Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode493Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode493::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reversePairs(argument), ret);
}

auto values = ::testing::Values(
  ParamType({1,3,2,3,1}, 2),
  ParamType({2,4,3,5,1}, 3),
  ParamType({5,4,3,2,1}, 4)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode493ParamTest, LeetCode493Test, values);

}
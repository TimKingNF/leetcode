//
// Created by timking.nf@foxmail.com on 2020/10/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1207.unique-number-of-occurrences.h"

namespace LeetCode1207 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1207Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1207Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1207::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->uniqueOccurrences(argument), ret);
}

auto values = ::testing::Values(
  ParamType({1,2,2,1,1,3}, true),
  ParamType({1,2}, false),
  ParamType({-3,0,1,-3,1,1,1,-3,10,0}, true)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1207ParamTest, LeetCode1207Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/8/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "78.subsets.h"

namespace LeetCode78 {

typedef vector<int> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode78Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode78Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode78::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ResultType asserted = solution->subsets(argument);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType({1,2,3}, {{3}, {1}, {2}, {1,2,3},
                              {1,3}, {2,3}, {1,2}, {}})
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode78ParamTest, LeetCode78Test, values);

}
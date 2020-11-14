//
// Created by timking.nf@foxmail.com on 2020/11/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "922.sort-array-by-parity-ii.h"

namespace LeetCode922 {

typedef vector<int> ArgumentType;
typedef set<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode922Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode922Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode922::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<int> asserted = solution->sortArrayByParityII(argument);
  // vector_print(asserted);
  ASSERT_TRUE(ret.count(asserted));
}

auto values = ::testing::Values(
  ParamType({4,2,5,7}, {{4,5,2,7}, {4,7,2,5}, {2,5,4,7}, {2,7,4,5}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode922ParamTest, LeetCode922Test, values);

}
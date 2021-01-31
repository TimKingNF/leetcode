//
// Created by timking.nf@foxmail.com on 2020/12/31.
//

#include "gtest/gtest.h"
#include "header.h"
#include "435.non-overlapping-intervals.h"

namespace LeetCode435 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode435Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode435Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode435::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->eraseOverlapIntervals(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{1,2}, {2,3}, {3,4}, {1,3}}, 1),
  ParamType({{1,2}, {1,2}, {1,2}}, 2),
  ParamType({{1,2}, {2,3}}, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode435ParamTest, LeetCode435Test, values);

}
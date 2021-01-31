//
// Created by timking.nf@foxmail.com on 2021/1/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "228.summary-ranges.h"

namespace LeetCode228 {

typedef vector<int> ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode228Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode228Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode228::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->summaryRanges(argument), ret);
}

auto values = ::testing::Values(
  ParamType({0,1,2,4,5,7}, {"0->2","4->5","7"}),
  ParamType({0,2,3,4,6,8,9}, {"0","2->4","6","8->9"}),
  ParamType({}, {}),
  ParamType({-1}, {"-1"}),
  ParamType({0}, {"0"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode228ParamTest, LeetCode228Test, values);

}
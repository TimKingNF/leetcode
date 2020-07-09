//
// Created by timking.nf@foxmail.com on 2020/6/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_57_II.he-wei-sde-lian-xu-zheng-shu-xu-lie-lcof.h"

namespace LeetCode_57_II {

typedef int ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_57_IITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_57_IITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_57_II::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findContinuousSequence(argument), ret);
}

ArgumentType p1 = 9;
ResultType r1{{2,3,4}, {4,5}};

ArgumentType p2 = 15;
ResultType r2{{1,2,3,4,5}, {4,5,6}, {7,8}};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_57_IIParamTest, LeetCode_57_IITest, values);

}
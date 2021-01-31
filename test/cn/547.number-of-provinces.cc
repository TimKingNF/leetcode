//
// Created by timking.nf@foxmail.com on 2021/1/7.
//

#include "gtest/gtest.h"
#include "header.h"
#include "547.number-of-provinces.h"

namespace LeetCode547 {

typedef vector<vector<int>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode547Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode547Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode547::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findCircleNum(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{1,1,0},{1,1,0},{0,0,1}}, 2),
  ParamType({{1,0,0},{0,1,0},{0,0,1}}, 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode547ParamTest, LeetCode547Test, values);

}
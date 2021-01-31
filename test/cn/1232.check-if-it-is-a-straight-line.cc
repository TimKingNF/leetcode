//
// Created by timking.nf@foxmail.com on 2021/1/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1232.check-if-it-is-a-straight-line.h"

namespace LeetCode1232 {

typedef vector<vector<int>> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1232Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1232Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1232::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->checkStraightLine(argument), ret);
}

auto values = ::testing::Values(
  ParamType({{1,2},{2,3},{3,4},{4,5},{5,6},{6,7}}, true),
  ParamType({{1,1},{2,2},{3,4},{4,5},{5,6},{7,7}}, false),
  ParamType({{-3,-14},{-4,-21},{2,21},{7,56},{3,28}}, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1232ParamTest, LeetCode1232Test, values);

}
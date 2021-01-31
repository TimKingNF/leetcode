//
// Created by timking.nf@foxmail.com on 2020/12/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "85.maximal-rectangle.h"

namespace LeetCode85 {

typedef vector<vector<char>> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode85Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode85Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode85::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->maximalRectangle(argument), ret);
}

auto values = ::testing::Values(
  ParamType({}, 0),
  ParamType({{'0'}}, 0),
  ParamType({{'1'}}, 1),
  ParamType({{'0', '0'}}, 0),
  ParamType({
    {'1','0','1','0','0'},
    {'1','0','1','1','1'},
    {'1','1','1','1','1'},
    {'1','0','0','1','0'}}, 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode85ParamTest, LeetCode85Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/7/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_01_07.rotate-matrix-lcci.h"

namespace LeetCode_01_07 {

typedef vector<vector<int>> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_01_07Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_01_07Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_01_07::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  solution->rotate(argument);
  ASSERT_EQ(argument, ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({{1,2,3},
             {4,5,6},
             {7,8,9}},
            {{7,4,1},
             {8,5,2},
             {9,6,3}}),
  ParamType({ { 5, 1, 9,11},
              { 2, 4, 8,10},
              {13, 3, 6, 7},
              {15,14,12,16}},
            { {15,13, 2, 5},
              {14, 3, 4, 1},
              {12, 6, 8, 9},
              {16, 7,10,11}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_01_07ParamTest, LeetCode_01_07Test, values);

}
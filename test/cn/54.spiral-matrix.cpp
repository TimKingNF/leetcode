//
// Created by timking.nf@foxmail.com on 2020/5/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "54.spiral-matrix.h"

namespace LeetCode54 {

typedef vector<vector<int>> MatrixType;
typedef MatrixType ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode54Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode54Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode54::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->spiralOrder(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            {1,2,3,6,9,8,7,4,5}),
  ParamType({{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}},
            {1,2,3,4,8,12,11,10,9,5,6,7}),
  ParamType({{7}, {8}, {9}}, {7, 8, 9})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode54ParamTest, LeetCode54Test, values);

}
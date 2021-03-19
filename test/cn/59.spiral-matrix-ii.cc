//
// Created by timking.nf@foxmail.com on 2021/3/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "59.spiral-matrix-ii.h"

namespace LeetCode59 {

typedef vector<vector<int>> MatrixType;
typedef int ArgumentType;
typedef MatrixType ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode59Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode59Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode59::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->generateMatrix(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(3, {{1, 2, 3}, {8, 9, 4}, {7, 6, 5}} ),
  ParamType(1, {{1}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode59ParamTest, LeetCode59Test, values);

}
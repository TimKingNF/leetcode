//
// Created by timking.nf@foxmail.com on 2020/5/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "766.toeplitz-matrix.h"

namespace LeetCode766 {

typedef vector<vector<int>> MatrixType;
typedef MatrixType ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode766Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode766Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode766::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isToeplitzMatrix(argument), ret);  // 断言结果
}

ArgumentType p1{{1, 2, 3, 4}, {5,1,2,3}, {9,5,1,2}};

ArgumentType p2{{1, 2}, {2, 2}};

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode766ParamTest, LeetCode766Test, values);

}
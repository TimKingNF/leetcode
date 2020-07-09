//
// Created by timking.nf@foxmail.com on 2020/5/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_04.er-wei-shu-zu-zhong-de-cha-zhao-lcof.h"

namespace LeetCode_04 {

typedef vector<vector<int>> MatrixType;
typedef tuple<MatrixType, int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_04Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_04Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_04::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  MatrixType matrix;
  int target;
  tie(matrix, target) = arguments;

  ASSERT_EQ(solution->findNumberIn2DArray(matrix, target), ret);  // 断言结果
}

MatrixType p1_0{{1,   4,  7, 11, 15},
                {2,   5,  8, 12, 19},
                {3,   6,  9, 16, 22},
                {10, 13, 14, 17, 24},
                {18, 21, 23, 26, 30}};
ArgumentType p1(p1_0, 5);
ArgumentType p2(p1_0, 20);

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_04ParamTest, LeetCode_04Test, values);

}
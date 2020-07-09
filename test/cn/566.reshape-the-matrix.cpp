//
// Created by timking.nf@foxmail.com on 2020/5/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "566.reshape-the-matrix.h"

namespace LeetCode566 {

typedef vector<vector<int>> MatrixType;
typedef tuple<MatrixType, int, int> ArgumentType;
typedef MatrixType ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode566Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode566Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode566::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  MatrixType nums;
  int r, c;
  tie(nums, r, c) = arguments;

  ASSERT_EQ(solution->matrixReshape(nums, r, c), ret);  // 断言结果
}

MatrixType p1_0{{1, 2}, {3, 4}};
ArgumentType p1(p1_0, 1, 4);

ArgumentType p2(p1_0, 2, 4);

ResultType r1{{1, 2, 3, 4}};
ResultType r2{{1, 2}, {3, 4}};

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode566ParamTest, LeetCode566Test, values);

}

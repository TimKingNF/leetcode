//
// Created by timking.nf@foxmail.com on 2020/7/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "542.01-matrix.h"

namespace LeetCode542 {

typedef vector<vector<int>> MatrixType;
typedef MatrixType ArgumentType;
typedef MatrixType ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode542Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode542Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode542::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->updateMatrix(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({{0,0,0},
             {0,1,0},
             {0,0,0}},
            {{0,0,0},
             {0,1,0},
             {0,0,0}}),
  ParamType({{0,0,0},
             {0,1,0},
             {1,1,1}},
            {{0,0,0},
             {0,1,0},
             {1,2,1}}),
  ParamType({{0},
             {1}},
            {{0},
             {1}}),
  ParamType({{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0}},
            {{0,1,0},{0,1,0},{0,1,0},{0,1,0},{0,1,0}}),
  ParamType({{0,0,1,0,1,1,1,0,1,1},
             {1,1,1,1,0,1,1,1,1,1},
             {1,1,1,1,1,0,0,0,1,1},
             {1,0,1,0,1,1,1,0,1,1},
             {0,0,1,1,1,0,1,1,1,1},
             {1,0,1,1,1,1,1,1,1,1},
             {1,1,1,1,0,1,0,1,0,1},
             {0,1,0,0,0,1,0,0,1,1},
             {1,1,1,0,1,1,0,1,0,1},
             {1,0,1,1,1,0,1,1,1,0}},
            {{0,0,1,0,1,2,1,0,1,2},
             {1,1,2,1,0,1,1,1,2,3},
             {2,1,2,1,1,0,0,0,1,2},
             {1,0,1,0,1,1,1,0,1,2},
             {0,0,1,1,1,0,1,1,2,3},
             {1,0,1,2,1,1,1,2,1,2},
             {1,1,1,1,0,1,0,1,0,1},
             {0,1,0,0,0,1,0,0,1,2},
             {1,1,1,0,1,1,0,1,0,1},
             {1,0,1,1,1,0,1,2,1,0}}
            )
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode542ParamTest, LeetCode542Test, values);

}
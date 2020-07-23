//
// Created by timking.nf@foxmail.com on 2020/7/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_01_08.zero-matrix-lcci.h"

namespace LeetCode_01_08 {

typedef vector<vector<int>> ArgumentType;
typedef vector<vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_01_08Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_01_08Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_01_08::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  solution->setZeroes(argument);
  ASSERT_EQ(argument, ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({{1,1,1},
             {1,0,1},
             {1,1,1}},
            {{1,0,1},
             {0,0,0},
             {1,0,1}}),
  ParamType({{0,1,2,0},
             {3,4,5,2},
             {1,3,1,5}},
            {{0,0,0,0},
             {0,4,5,0},
             {0,3,1,0}})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_01_08ParamTest, LeetCode_01_08Test, values);

}
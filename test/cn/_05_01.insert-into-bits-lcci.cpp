//
// Created by timking.nf@foxmail.com on 2020/7/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_05_01.insert-into-bits-lcci.h"

namespace LeetCode_05_01 {

typedef tuple<int, int, int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_05_01Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_05_01Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_05_01::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  int N, M, i, j;
  tie(N, M, i, j) = arguments;

  ASSERT_EQ(solution->insertBits(N, M, i, j), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType(0b10000000000, 0b10011, 2, 6), 0b10001001100),
  ParamType(ArgumentType(0, 0b11111, 0, 4), 0b11111),
  ParamType(ArgumentType(1143207437, 1017033, 11, 31), 2082885133),
  ParamType(ArgumentType(2032243561, 10, 24, 29), 1243714409)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_05_01ParamTest, LeetCode_05_01Test, values);

}
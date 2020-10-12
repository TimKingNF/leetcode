//
// Created by timking.nf@foxmail.com on 2020/8/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "201.bitwise-and-of-numbers-range.h"

namespace LeetCode201 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode201Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode201Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode201::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int m, n;
  tie(m, n) = arguments;

  ASSERT_EQ(solution->rangeBitwiseAnd(m, n), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(5, 7), 4),
  ParamType(ArgumentType(0, 1), 0)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode201ParamTest, LeetCode201Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/8/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "62.unique-paths.h"

namespace LeetCode62 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode62Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode62Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode62::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int m, n;
  tie(m, n) = arguments;

  ASSERT_EQ(solution->uniquePaths(m, n), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(3,2), 3),
  ParamType(ArgumentType(7,3), 28)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode62ParamTest, LeetCode62Test, values);

}
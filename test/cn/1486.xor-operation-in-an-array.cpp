//
// Created by timking.nf@foxmail.com on 2020/7/7.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1486.xor-operation-in-an-array.h"

namespace LeetCode1486 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1486Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1486Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1486::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  int n, start;
  tie(n, start) = arguments;

  ASSERT_EQ(solution->xorOperation(n, start), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType(5, 0), 8),
  ParamType(ArgumentType(4, 3), 8),
  ParamType(ArgumentType(1, 7), 7),
  ParamType(ArgumentType(10, 5), 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1486ParamTest, LeetCode1486Test, values);

}
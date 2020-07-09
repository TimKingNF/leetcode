//
// Created by timking.nf@foxmail.com on 2020/7/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "371.sum-of-two-integers.h"

namespace LeetCode371 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode371Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode371Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode371::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int a, b;
  tie(a, b) = arguments;

  ASSERT_EQ(solution->getSum(a, b), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(tuple<int, int>(1, 2), 3),
  ParamType(tuple<int, int>(-3, 2), -1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode371ParamTest, LeetCode371Test, values);

}

//
// Created by timking.nf@foxmail.com on 2020/5/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "50.powx-n.h"

namespace LeetCode50 {

typedef tuple<double, int> ArgumentType;
typedef double ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode50Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode50Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode50::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  double x;
  int n;
  tie(x, n) = arguments;

  ASSERT_DOUBLE_EQ(solution->myPow(x, n), ret);  // 断言结果
}

ArgumentType p1(2.0, 10);
ArgumentType p2(2.1, 3);
ArgumentType p3(2.0, -2);
ArgumentType p4(8.84372, -5);
ArgumentType p5(1, -2147483648);

auto values = ::testing::Values(
  ParamType(p1, 1024.0),
  ParamType(p2, 9.261),
  ParamType(p3, 0.25),
  ParamType(p4, 1.848523942883906e-05),
  ParamType(p5, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode50ParamTest, LeetCode50Test, values);

}

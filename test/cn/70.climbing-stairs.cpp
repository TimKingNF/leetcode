//
// Created by timking.nf@foxmail.com on 2020/5/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "70.climbing-stairs.h"

namespace LeetCode70 {

typedef int ArgumentType;
typedef tuple<ArgumentType, int> ParamType;

class LeetCode70Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode70Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode70::Solution();
  ArgumentType argument;
  int ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->climbStairs(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(2, 2),
  ParamType(3, 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode70ParamTest, LeetCode70Test, values);

}
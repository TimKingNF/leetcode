//
// Created by timking.nf@foxmail.com on 2020/10/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "LCP19.UlBDOe.h"

namespace LeetCodeLCP19 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCodeLCP19Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCodeLCP19Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCodeLCP19::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->minimumOperations(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("ryr", 0),
  ParamType("rrryyyrryyyrr", 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCodeLCP19ParamTest, LeetCodeLCP19Test, values);

}
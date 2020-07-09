//
// Created by timking.nf@foxmail.com on 2020/5/27.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_20.biao-shi-shu-zhi-de-zi-fu-chuan-lcof.h"

namespace LeetCode_20 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_20Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_20Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_20::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isNumber(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("+100", true),
  ParamType("5e2", true),
  ParamType("-123", true),
  ParamType("3.1416", true),
  ParamType("-1E-16", true),
  ParamType("12e", false),
  ParamType("1a3.14", false),
  ParamType("1.2.3", false),
  ParamType("+-5", false),
  ParamType("12e+5.4", false),
  ParamType("e9", false),
  ParamType("1 ", true),
  ParamType(" ", false),
  ParamType("3.", true),
  ParamType(".", false),
  ParamType(" 0 ", true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_20ParamTest, LeetCode_20Test, values);

}

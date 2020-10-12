//
// Created by timking.nf@foxmail.com on 2020/6/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "8.string-to-integer-atoi.h"

namespace LeetCode8 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode8Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode8Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode8::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->myAtoi(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("45", 45),
  ParamType("    -45", -45),
  ParamType("4093 ", 4093),
  ParamType("words and 987", 0),
  ParamType("-91283472332", INT32_MIN),
  ParamType("    -", 0),
  ParamType("    -a12", 0),
  ParamType("3.14159", 3),
  ParamType("3.14.15", 3),
  ParamType("+-2", 0),
  ParamType("-2147483648", INT32_MIN)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode8ParamTest, LeetCode8Test, values);

}
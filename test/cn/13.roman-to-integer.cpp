//
// Created by timking.nf@foxmail.com on 2020/7/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "13.roman-to-integer.h"

namespace LeetCode13 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode13Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode13Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode13::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->romanToInt(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("III", 3),
  ParamType("IV", 4),
  ParamType("IX", 9),
  ParamType("LVIII", 58),
  ParamType("MCMXCIV", 1994)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode13ParamTest, LeetCode13Test, values);

}
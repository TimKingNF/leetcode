//
// Created by timking.nf@foxmail.com on 2020/12/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "12.integer-to-roman.h"

namespace LeetCode12 {

typedef int ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode12Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode12Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode12::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->intToRoman(argument), ret);
}

auto values = ::testing::Values(
  ParamType(3, "III"),
  ParamType(4, "IV"),
  ParamType(9, "IX"),
  ParamType(58, "LVIII"),
  ParamType(1994, "MCMXCIV")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode12ParamTest, LeetCode12Test, values);

}
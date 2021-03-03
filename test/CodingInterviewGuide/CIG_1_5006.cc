//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_5006.hpp"

namespace CIG_1_5006 {

typedef tuple<string, string, string> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_5006_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_5006_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_5006::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string str, from, to;
  tie(str, from, to) = arguments;

  ASSERT_EQ(solution->replace(str, from, to), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("123abc", "abc", "4567"), "1234567"),
  ParamType(ArgumentType("123", "abc", "456"), "123"),
  ParamType(ArgumentType("abc", "abc", "456"), "456"),
  ParamType(ArgumentType("123abcabc", "abc", "X"), "123X"),
  ParamType(ArgumentType("123abcabc123abc", "abc", "X"), "123X123X"),
  ParamType(ArgumentType("abcabcabd123abc", "abc", "X"), "Xabd123X")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_5006_ParamTest, CIG_1_5006_Test, values);

}
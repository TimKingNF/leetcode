//
// Created by timking.nf@foxmail.com on 2020/7/5.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1071.greatest-common-divisor-of-strings.h"

namespace LeetCode1071 {

typedef tuple<string, string> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1071Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1071Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1071::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  string x, y;
  tie(x, y) = arguments;

  ASSERT_EQ(solution->gcdOfStrings(x, y), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("ABCABC", "ABC"), "ABC"),
  ParamType(ArgumentType("ABABAB", "ABAB"), "AB"),
  ParamType(ArgumentType("LEET", "CODE"), ""),
  ParamType(ArgumentType("AB", "A"), ""),
  ParamType(ArgumentType("AB", "AB"), "AB"),
  ParamType(ArgumentType("ABC", "A"), ""),
  ParamType(ArgumentType("TAUXXTAUXXTAUXXTAUXXTAUXX",
                         "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX"), "TAUXX")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1071ParamTest, LeetCode1071Test, values);

}
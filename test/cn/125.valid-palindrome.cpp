//
// Created by timking.nf@foxmail.com on 2020/7/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "125.valid-palindrome.h"

namespace LeetCode125 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode125Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode125Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode125::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isPalindrome(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("A man, a plan, a canal: Panama", true),
  ParamType("race a car", false),
  ParamType(" ", true),
  ParamType(".,", true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode125ParamTest, LeetCode125Test, values);

}
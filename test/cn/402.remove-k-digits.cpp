//
// Created by timking.nf@foxmail.com on 2020/8/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "402.remove-k-digits.h"

namespace LeetCode402 {

typedef tuple<string, int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode402Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode402Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode402::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string num;
  int k;
  tie(num, k) = arguments;
  ASSERT_EQ(solution->removeKdigits(num, k), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("1432219", 3), "1219"),
  ParamType(ArgumentType("10200", 1), "200"),
  ParamType(ArgumentType("10", 2), "0")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode402ParamTest, LeetCode402Test, values);

}
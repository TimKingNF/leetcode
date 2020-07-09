//
// Created by timking.nf@foxmail.com on 2020/7/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "405.convert-a-number-to-hexadecimal.h"

namespace LeetCode405 {

typedef int ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode405Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode405Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode405::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->toHex(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(26, "1a"),
  ParamType(-1, "ffffffff")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode405ParamTest, LeetCode405Test, values);

}
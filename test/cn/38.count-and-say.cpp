//
// Created by timking.nf@foxmail.com on 2020/7/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "38.count-and-say.h"

namespace LeetCode38 {

typedef int ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode38Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode38Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode38::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->countAndSay(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(1, "1"),
  ParamType(4, "1211")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode38ParamTest, LeetCode38Test, values);

}
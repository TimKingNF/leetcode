//
// Created by timking.nf@foxmail.com on 2020/7/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_05_03.reverse-bits-lcci.h"

namespace LeetCode_05_03 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_05_03Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_05_03Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_05_03::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reverseBits(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(1775, 8),
  ParamType(7, 4)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_05_03ParamTest, LeetCode_05_03Test, values);

}
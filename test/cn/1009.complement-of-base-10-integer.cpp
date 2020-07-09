//
// Created by timking.nf@foxmail.com on 2020/7/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1009.complement-of-base-10-integer.h"

namespace LeetCode1009 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1009Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1009Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1009::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->bitwiseComplement(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(5, 2),
  ParamType(1, 0),
  ParamType(7, 0),
  ParamType(10, 5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1009ParamTest, LeetCode1009Test, values);

}
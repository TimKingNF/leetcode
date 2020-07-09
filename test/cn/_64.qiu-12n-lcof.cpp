//
// Created by timking.nf@foxmail.com on 2020/6/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_64.qiu-12n-lcof.h"

namespace LeetCode_64 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_64Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_64Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_64::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->sumNums(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(3, 6),
  ParamType(9, 45)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_64ParamTest, LeetCode_64Test, values);

}
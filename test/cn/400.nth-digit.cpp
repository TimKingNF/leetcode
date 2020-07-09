//
// Created by timking.nf@foxmail.com on 2020/6/5.
//

#include "gtest/gtest.h"
#include "header.h"
#include "400.nth-digit.h"

namespace LeetCode400 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode400Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode400Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode400::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->findNthDigit(arguments), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(3, 3),
  ParamType(11, 0),
  ParamType(10, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode400ParamTest, LeetCode400Test, values);

}
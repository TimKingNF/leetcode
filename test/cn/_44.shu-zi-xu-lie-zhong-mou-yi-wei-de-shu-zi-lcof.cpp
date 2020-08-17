//
// Created by timking.nf@foxmail.com on 2020/6/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_44.shu-zi-xu-lie-zhong-mou-yi-wei-de-shu-zi-lcof.h"

namespace LeetCode_44 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_44Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_44Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_44::Solution();
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
INSTANTIATE_TEST_SUITE_P(LeetCode_44ParamTest, LeetCode_44Test, values);

}
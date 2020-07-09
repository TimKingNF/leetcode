//
// Created by timking.nf@foxmail.com on 2020/7/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "476.number-complement.h"

namespace LeetCode476 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode476Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode476Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode476::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findComplement(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(5, 2),
  ParamType(1, 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode476ParamTest, LeetCode476Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/5/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "191.number-of-1-bits.h"

namespace LeetCode191 {

typedef uint32_t ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode191Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode191Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode191::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->hammingWeight(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(9, 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode191ParamTest, LeetCode191Test, values);

}


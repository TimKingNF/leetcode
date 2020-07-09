//
// Created by timking.nf@foxmail.com on 2020/7/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "190.reverse-bits.h"

namespace LeetCode190 {

typedef uint32_t ArgumentType;
typedef uint32_t ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode190Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode190Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode190::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reverseBits(argument), ret);  // 断言结果
}

ArgumentType p1 = 43261596;
ResultType r1 = 964176192;

ArgumentType p2 = 4294967293;
ResultType r2 = 3221225471;

ArgumentType p3 = 1;
ResultType r3 = 2147483648;

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode190ParamTest, LeetCode190Test, values);

}

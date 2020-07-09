//
// Created by timking.nf@foxmail.com on 2020/7/6.
//

#include "gtest/gtest.h"
#include "header.h"
#include "762.prime-number-of-set-bits-in-binary-representation.h"

namespace LeetCode762 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode762Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode762Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode762::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();
  int L, R;
  tie(L, R) = arguments;

  ASSERT_EQ(solution->countPrimeSetBits(L, R), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType(6, 10), 4),
  ParamType(ArgumentType(10, 15), 5),
  ParamType(ArgumentType(977581, 983119), 2036)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode762ParamTest, LeetCode762Test, values);

}

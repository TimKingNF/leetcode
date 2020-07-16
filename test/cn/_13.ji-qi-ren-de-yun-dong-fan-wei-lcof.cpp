//
// Created by timking.nf@foxmail.com on 2020/7/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_13.ji-qi-ren-de-yun-dong-fan-wei-lcof.h"

namespace LeetCode_13 {

typedef tuple<int, int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_13Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_13Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_13::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int m, n, k;
  tie(m, n, k) = arguments;

  ASSERT_EQ(solution->movingCount(m, n, k), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType(2, 3, 1), 3),
  ParamType(ArgumentType(3, 1, 0), 1),
  ParamType(ArgumentType(3, 2, 17), 6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_13ParamTest, LeetCode_13Test, values);

}
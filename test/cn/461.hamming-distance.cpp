//
// Created by timking.nf@foxmail.com on 2020/7/5.
//

#include "gtest/gtest.h"
#include "header.h"
#include "461.hamming-distance.h"

namespace LeetCode461 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode461Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode461Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode461::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int x, y;
  tie(x, y) = arguments;

  ASSERT_EQ(solution->hammingDistance(x, y), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(tuple<int, int>(1, 4), 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode461ParamTest, LeetCode461Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/5/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "747.largest-number-at-least-twice-of-others.h"

namespace LeetCode747 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode747Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode747Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode747::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->dominantIndex(argument), ret);  // 断言结果
}

ArgumentType p1{3, 6, 1, 0};
ArgumentType p2{1, 2, 3, 4};

auto values = ::testing::Values(
  ParamType(p1, 1),
  ParamType(p2, -1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode747ParamTest, LeetCode747Test, values);

}

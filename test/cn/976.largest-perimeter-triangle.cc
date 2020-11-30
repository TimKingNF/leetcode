//
// Created by timking.nf@foxmail.com on 2020/11/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "976.largest-perimeter-triangle.h"

namespace LeetCode976 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode976Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode976Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode976::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->largestPerimeter(argument), ret);  // 可以有多个结果
}

auto values = ::testing::Values(
  ParamType({2,1,2}, 5),
  ParamType({1,2,1}, 0),
  ParamType({3,2,3,4}, 10),
  ParamType({3,6,2,3}, 8)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode976ParamTest, LeetCode976Test, values);

}
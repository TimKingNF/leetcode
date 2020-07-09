//
// Created by timking.nf@foxmail.com on 2020/5/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "628.maximum-product-of-three-numbers.h"

namespace LeetCode628 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode628Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode628Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode628::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->maximumProduct(argument), ret);  // 断言结果
}

ArgumentType p1{1,2,3};
ArgumentType p2{1,2,3,4};
ArgumentType p3{-1,-2,-3};

auto values = ::testing::Values(
  ParamType(p1, 6),
  ParamType(p2, 24),
  ParamType(p3, -6)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode628ParamTest, LeetCode628Test, values);

}

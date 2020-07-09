//
// Created by timking.nf@foxmail.com on 2020/5/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "152.maximum-product-subarray.h"

namespace LeetCode152 {

typedef vector<int> ArgumentType;
typedef tuple<ArgumentType, int> ParamType;

class LeetCode152Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode152Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode152::Solution();
  ArgumentType arguments;
  int ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->maxProduct(arguments), ret);  // 断言结果
}

ArgumentType p1{2,3,-2,4};
ArgumentType p2{-2,0,-1};
ArgumentType p3{-2};

auto values = ::testing::Values(
  ParamType(p1, 6),
  ParamType(p2, 0),
  ParamType(p3, -2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode152ParamTest, LeetCode152Test, values);

}
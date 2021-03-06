//
// Created by timking.nf@foxmail.com on 2020/9/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "238.product-of-array-except-self.h"

namespace LeetCode238 {

typedef vector<int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode238Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode238Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode238::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->productExceptSelf(argument), ret);
}

auto values = ::testing::Values(
  ParamType({1,2,3,4}, {24,12,8,6})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode238ParamTest, LeetCode238Test, values);

}
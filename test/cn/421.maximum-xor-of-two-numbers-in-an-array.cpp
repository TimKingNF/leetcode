//
// Created by timking.nf@foxmail.com on 2020/8/18.
//

#include "gtest/gtest.h"
#include "header.h"
#include "421.maximum-xor-of-two-numbers-in-an-array.h"

namespace LeetCode421 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode421Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode421Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode421::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findMaximumXOR(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({3,10,5,25,2,8}, 28),
  ParamType({2147483647,2147483646}, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode421ParamTest, LeetCode421Test, values);

}

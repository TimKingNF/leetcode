//
// Created by timking.nf@foxmail.com on 2021/3/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "338.counting-bits.h"

namespace LeetCode338 {

typedef int ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode338Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode338Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode338::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->countBits(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(2, {0,1,1}),
  ParamType(5, {0,1,1,2,1,2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode338ParamTest, LeetCode338Test, values);

}
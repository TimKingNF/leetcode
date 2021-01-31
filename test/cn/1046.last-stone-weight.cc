//
// Created by timking.nf@foxmail.com on 2020/12/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1046.last-stone-weight.h"

namespace LeetCode1046 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1046Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1046Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1046::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->lastStoneWeight(argument), ret);
}

auto values = ::testing::Values(
  ParamType({2,7,4,1,8,1}, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1046ParamTest, LeetCode1046Test, values);

}
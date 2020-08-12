//
// Created by timking.nf@foxmail.com on 2020/8/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "11.container-with-most-water.h"

namespace LeetCode11 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode11Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode11Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode11::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->maxArea(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({1,8,6,2,5,4,8,3,7}, 49)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode11ParamTest, LeetCode11Test, values);

}
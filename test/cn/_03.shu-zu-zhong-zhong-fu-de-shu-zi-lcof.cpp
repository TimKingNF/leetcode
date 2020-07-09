//
// Created by timking.nf@foxmail.com on 2020/5/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_03.shu-zu-zhong-zhong-fu-de-shu-zi-lcof.h"

namespace LeetCode_03 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_03Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_03Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_03::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->findRepeatNumber(argument), ret);  // 断言结果
}

ArgumentType p1{2, 3, 1, 0, 2, 5, 3};

auto values = ::testing::Values(
  ParamType(p1, 2)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_03ParamTest, LeetCode_03Test, values);

}
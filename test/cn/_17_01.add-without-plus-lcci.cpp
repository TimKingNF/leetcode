//
// Created by timking.nf@foxmail.com on 2020/7/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_17_01.add-without-plus-lcci.h"

namespace LeetCode_17_01 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_17_01Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_17_01Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_17_01::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int a, b;
  tie(a, b) = arguments;

  ASSERT_EQ(solution->add(a, b), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(tuple<int, int>(1, 2), 3),
  ParamType(tuple<int, int>(-3, 2), -1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_17_01ParamTest, LeetCode_17_01Test, values);

}

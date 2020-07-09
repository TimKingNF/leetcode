//
// Created by timking.nf@foxmail.com on 2020/6/23.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_65.bu-yong-jia-jian-cheng-chu-zuo-jia-fa-lcof.h"

namespace LeetCode_65 {

typedef tuple<int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_65Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_65Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_65::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int a, b;
  tie(a, b) = arguments;

  ASSERT_EQ(solution->add(a, b), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType (1, 1), 2),
  ParamType(ArgumentType (-10, 5), -5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_65ParamTest, LeetCode_65Test, values);

}
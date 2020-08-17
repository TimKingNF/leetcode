//
// Created by timking.nf@foxmail.com on 2020/7/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "389.find-the-difference.h"

namespace LeetCode389 {

typedef tuple<string, string> ArgumentType;
typedef char ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode389Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode389Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode389::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string a, b;
  tie(a, b) = arguments;

  ASSERT_EQ(solution->findTheDifference(a, b), ret);  // 断言结果
}

ArgumentType p1("abcd", "abcde");
ResultType r1 = 'e';

auto values = ::testing::Values(
  ParamType(p1, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode389ParamTest, LeetCode389Test, values);

}
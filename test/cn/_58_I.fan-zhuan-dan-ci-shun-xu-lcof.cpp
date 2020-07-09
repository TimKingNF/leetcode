//
// Created by timking.nf@foxmail.com on 2020/6/16.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_58_I.fan-zhuan-dan-ci-shun-xu-lcof.h"

namespace LeetCode_58_I {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_58_ITest : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_58_ITest, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_58_I::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reverseWords(argument), ret);
}

ArgumentType p1 = "the sky is blue";
ResultType r1 = "blue is sky the";

ArgumentType p2 = "  hello world!  ";
ResultType r2 = "world! hello";

ArgumentType p3 = "a good   example";
ResultType r3 = "example good a";

auto values = ::testing::Values(
  ParamType(p1, r1),
  ParamType(p2, r2),
  ParamType(p3, r3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_58_IParamTest, LeetCode_58_ITest, values);

}
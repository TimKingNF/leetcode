//
// Created by timking.nf@foxmail.com on 2020/6/4.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_43.1nzheng-shu-zhong-1chu-xian-de-ci-shu-lcof.h"

namespace LeetCode_43 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_43Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_43Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_43::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->countDigitOne(arguments), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(12, 5),
  ParamType(13, 6),
  ParamType(1410065408, 1737167499),
  ParamType(99, 20)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_43ParamTest, LeetCode_43Test, values);

}
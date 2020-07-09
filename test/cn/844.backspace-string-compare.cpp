//
// Created by timking.nf@foxmail.com on 2020/7/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "844.backspace-string-compare.h"

namespace LeetCode844 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode844Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode844Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode844::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string S, T;
  tie(S, T) = arguments;

  ASSERT_EQ(solution->backspaceCompare(S, T), ret);  // 断言结果
}

ArgumentType p1("ab#c", "ad#c");
ArgumentType p2("ab##", "c#d#");
ArgumentType p3("a##c", "#a#c");
ArgumentType p4("a#c", "b");

auto values = ::testing::Values(
  ParamType(p1, true),
  ParamType(p2, true),
  ParamType(p3, true),
  ParamType(p4, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode844ParamTest, LeetCode844Test, values);

}
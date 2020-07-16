//
// Created by timking.nf@foxmail.com on 2020/7/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "392.is-subsequence.h"

namespace LeetCode392 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode392Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode392Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode392::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s, t;
  tie(s, t) = arguments;

  ASSERT_EQ(solution->isSubsequence(s, t), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("abc", "ahbgdc"), true),
  ParamType(ArgumentType("axc", "ahbgdca"), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode392ParamTest, LeetCode392Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/11/30.
//

#include "gtest/gtest.h"
#include "header.h"
#include "767.reorganize-string.h"

namespace LeetCode767 {

typedef string ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode767Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode767Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode767::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  string asserted = solution->reorganizeString(argument);
  // cout << asserted << endl;
  ASSERT_TRUE(ret.count(asserted));
}

auto values = ::testing::Values(
  ParamType("aab", {"aba"}),
  ParamType("aaab", {""})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode767ParamTest, LeetCode767Test, values);

}
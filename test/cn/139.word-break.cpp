//
// Created by timking.nf@foxmail.com on 2020/9/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "139.word-break.h"

namespace LeetCode139 {

typedef tuple<string, vector<string>> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode139Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode139Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode139::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s;
  vector<string> wordDict;
  tie(s, wordDict) = arguments;

  ASSERT_EQ(solution->wordBreak(s, wordDict), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("leetcode", {"leet", "code"}), true),
  ParamType(ArgumentType("applepenapple", {"apple", "pen"}), true),
  ParamType(ArgumentType("catsandog", {"cats", "dog", "sand", "and", "cat"}), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode139ParamTest, LeetCode139Test, values);

}
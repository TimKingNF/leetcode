//
// Created by timking.nf@foxmail.com on 2020/9/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "140.word-break-ii.h"

namespace LeetCode140 {

typedef tuple<string, vector<string>> ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode140Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode140Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode140::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s;
  vector<string> wordDict;
  tie(s, wordDict) = arguments;

  ResultType asserted = solution->wordBreak(s, wordDict);
  // ASSERT_EQ(asserted, ret);
  ASSERT_TRUE(vector_unordered_cmp(asserted, ret));
}

auto values = ::testing::Values(
  ParamType(ArgumentType("catsandog", {"cats", "dog", "sand", "and", "cat"}),
            {}),
  ParamType(ArgumentType("pineapplepenapple", {"apple", "pen", "applepen", "pine", "pineapple"}),
            {"pine apple pen apple", "pineapple pen apple", "pine applepen apple" }),
  ParamType(ArgumentType("catsanddog", {"cats", "dog", "sand", "and", "cat"}),
            {"cats and dog", "cat sand dog"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode140ParamTest, LeetCode140Test, values);

}
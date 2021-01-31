//
// Created by timking.nf@foxmail.com on 2021/1/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1202.smallest-string-with-swaps.h"

namespace LeetCode1202 {

typedef tuple<string, vector<vector<int>>> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1202Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1202Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1202::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s;
  vector<vector<int>> pairs;
  tie(s, pairs) = arguments;

  ASSERT_EQ(solution->smallestStringWithSwaps(s, pairs), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("dcab", {{0,3}, {1,2}}), "bacd"),
  ParamType(ArgumentType("dcab", {{0,3}, {1,2}, {0,2}}), "abcd"),
  ParamType(ArgumentType("cba", {{0,1}, {1,2}}), "abc")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1202ParamTest, LeetCode1202Test, values);

}
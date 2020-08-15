//
// Created by timking.nf@foxmail.com on 2020/8/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "451.sort-characters-by-frequency.h"

namespace LeetCode451 {

typedef string ArgumentType;
typedef set<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode451Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode451Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode451::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_TRUE(ret.count(solution->frequencySort(argument)));  // 断言结果
}

auto values = ::testing::Values(
  ParamType("tree", {"eert", "eetr"}),
  ParamType("cccaaa", {"cccaaa", "aaaccc"}),
  ParamType("Abab", {"bbAa", "bbaA"}),
  ParamType("eeeee", {"eeeee"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode451ParamTest, LeetCode451Test, values);

}
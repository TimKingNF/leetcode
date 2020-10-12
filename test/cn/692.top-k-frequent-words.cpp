//
// Created by timking.nf@foxmail.com on 2020/9/24.
//

#include "gtest/gtest.h"
#include "header.h"
#include "692.top-k-frequent-words.h"

namespace LeetCode692 {

typedef tuple<vector<string>, int> ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode692Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode692Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode692::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<string> words;
  int k;
  tie(words, k) = arguments;

  ASSERT_EQ(solution->topKFrequent(words, k), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType({"i", "love", "leetcode", "i", "love", "coding"}, 2),
            {"i", "love"}),
  ParamType(ArgumentType({"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"}, 4),
            {"the", "is", "sunny", "day"})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode692ParamTest, LeetCode692Test, values);

}
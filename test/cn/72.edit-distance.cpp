//
// Created by timking.nf@foxmail.com on 2020/8/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "72.edit-distance.h"

namespace LeetCode72 {

typedef tuple<string, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode72Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode72Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode72::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string word1, word2;
  tie(word1, word2) = arguments;

  ASSERT_EQ(solution->minDistance(word1, word2), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("horse", "ros"), 3),
  ParamType(ArgumentType("intention", "execution"), 5)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode72ParamTest, LeetCode72Test, values);

}
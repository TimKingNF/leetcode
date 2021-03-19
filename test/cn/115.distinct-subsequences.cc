//
// Created by timking.nf@foxmail.com on 2021/3/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "115.distinct-subsequences.h"

namespace LeetCode115 {

typedef tuple<string, string> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode115Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode115Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode115::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s, t;
  tie(s, t) = arguments;

  ASSERT_EQ(solution->numDistinct(s, t), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("rabbbit", "rabbit"), 3),
  ParamType(ArgumentType("babgbag", "bag"), 5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode115ParamTest, LeetCode115Test, values);

}
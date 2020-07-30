//
// Created by timking.nf@foxmail.com on 2020/7/29.
//

#include "gtest/gtest.h"
#include "header.h"
#include "205.isomorphic-strings.h"

namespace LeetCode205 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode205Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode205Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode205::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s, t;
  tie(s, t) = arguments;

  ASSERT_EQ(solution->isIsomorphic(s, t), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("egg", "add"), true),
  ParamType(ArgumentType("foo", "bar"), false),
  ParamType(ArgumentType("paper", "title"), true),
  ParamType(ArgumentType("ab", "aa"), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode205ParamTest, LeetCode205Test, values);

}
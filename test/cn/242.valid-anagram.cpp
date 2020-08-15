//
// Created by timking.nf@foxmail.com on 2020/8/13.
//

#include "gtest/gtest.h"
#include "header.h"
#include "242.valid-anagram.h"

namespace LeetCode242 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode242Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode242Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode242::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s, t;
  tie(s, t) = arguments;

  ASSERT_EQ(solution->isAnagram(s, t), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("anagram", "nagaram"), true),
  ParamType(ArgumentType("rat", "car"), false),
  ParamType(ArgumentType("", "a"), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode242ParamTest, LeetCode242Test, values);

}
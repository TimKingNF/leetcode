//
// Created by timking.nf@foxmail.com on 2020/6/11.
//

#include "gtest/gtest.h"
#include "header.h"
#include "3.longest-substring-without-repeating-characters.h"

namespace LeetCode3 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode3Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode3Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode3::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  ASSERT_EQ(solution->lengthOfLongestSubstring(arguments), ret);  // 断言结果
}

ArgumentType p1 = "abcabcbb";
ArgumentType p2 = "bbbbb";
ArgumentType p3 = "pwwkew";

auto values = ::testing::Values(
  ParamType(p1, 3),
  ParamType(p2, 1),
  ParamType(p3, 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode3ParamTest, LeetCode3Test, values);

}
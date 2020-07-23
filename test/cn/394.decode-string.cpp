//
// Created by timking.nf@foxmail.com on 2020/7/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "394.decode-string.h"

namespace LeetCode394 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode394Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode394Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode394::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->decodeString(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("", ""),
  ParamType("3[a]2[bc]", "aaabcbc"),
  ParamType("3[a2[c]]", "accaccacc"),
  ParamType("2[abc]3[cd]ef", "abcabccdcdcdef"),
  ParamType("abc3[cd]xyz", "abccdcdcdxyz"),
  ParamType("10[a]", "aaaaaaaaaa")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode394ParamTest, LeetCode394Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/12/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "316.remove-duplicate-letters.h"

namespace LeetCode316 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode316Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode316Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode316::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->removeDuplicateLetters(argument), ret);
}

auto values = ::testing::Values(
  ParamType("bcabc", "abc"),
  ParamType("cbacdcbc", "acdb")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode316ParamTest, LeetCode316Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/7/21.
//

#include "gtest/gtest.h"
#include "header.h"
#include "557.reverse-words-in-a-string-iii.h"

namespace LeetCode557 {

typedef string ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode557Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode557Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode557::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->reverseWords(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType("Let's take LeetCode contest", "s'teL ekat edoCteeL tsetnoc")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode557ParamTest, LeetCode557Test, values);

}

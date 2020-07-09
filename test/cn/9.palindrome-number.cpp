//
// Created by timking.nf@foxmail.com on 2020/5/22.
//

#include "gtest/gtest.h"
#include "header.h"
#include "9.palindrome-number.h"

namespace LeetCode9 {

typedef int ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode9Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode9Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode9::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isPalindrome(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  // ParamType(121, true),
  // ParamType(-121, false),
  // ParamType(10, false),
  ParamType(1001, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode9ParamTest, LeetCode9Test, values);

}

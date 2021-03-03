//
// Created by timking.nf@foxmail.com on 2021/3/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "1312.minimum-insertion-steps-to-make-a-string-palindrome.h"

namespace LeetCode1312 {

typedef string ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode1312Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode1312Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode1312::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->minInsertions(argument), ret);  // 断言结果
  // cout << solution->getPalindrome(argument) << endl;
}

auto values = ::testing::Values(
  ParamType("zzazz", 0),
  ParamType("mbadm", 2),
  ParamType("leetcode", 5),
  ParamType("g", 0),
  ParamType("no", 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode1312ParamTest, LeetCode1312Test, values);

}
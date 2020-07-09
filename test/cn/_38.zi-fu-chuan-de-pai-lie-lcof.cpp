//
// Created by timking.nf@foxmail.com on 2020/6/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_38.zi-fu-chuan-de-pai-lie-lcof.h"

namespace LeetCode_38 {

typedef string ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_38Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_38Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_38::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  vector<string> ans = solution->permutation(argument);
  ASSERT_TRUE(vector_unordered_cmp(ans, ret));
}

ArgumentType p1 = "ab";
ResultType r1{"ab","ba"};

ArgumentType p2 = "abc";
ResultType r2{"abc","acb","bac","bca","cab","cba"};

ArgumentType p3 = "aab";
ResultType r3{"aba", "aab", "baa"};

auto values = ::testing::Values(
  // ParamType(p1, r1),
  ParamType(p2, r2)
  // ParamType(p3, r3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_38ParamTest, LeetCode_38Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/7/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "14.longest-common-prefix.h"

namespace LeetCode14 {

typedef vector<string> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode14Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode14Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode14::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->longestCommonPrefix(argument), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType({"flower","flow","flight"}, "fl"),
  ParamType({"dog","racecar","car"}, ""),
  ParamType({""}, ""),
  ParamType(ArgumentType(), ""),
  ParamType({"car"}, "car"),
  ParamType({"aa", "aa"}, "aa")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode14ParamTest, LeetCode14Test, values);

}
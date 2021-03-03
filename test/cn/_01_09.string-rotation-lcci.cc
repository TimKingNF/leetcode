//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_01_09.string-rotation-lcci.h"

namespace LeetCode_01_09 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_01_09Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_01_09Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_01_09::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s1, s2;
  tie(s1, s2) = arguments;

  ASSERT_EQ(solution->isFlipedString(s1, s2), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("waterbottle", "erbottlewat"), true),
  ParamType(ArgumentType("aa", "aba"), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_01_09ParamTest, LeetCode_01_09Test, values);

}
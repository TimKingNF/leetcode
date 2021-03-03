//
// Created by timking.nf@foxmail.com on 2021/2/28.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_01_02.check-permutation-lcci.h"

namespace LeetCode_01_02 {

typedef tuple<string, string> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode_01_02Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_01_02Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_01_02::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s1, s2;
  tie(s1, s2) = arguments;

  ASSERT_EQ(solution->CheckPermutation(s1, s2), ret);  // 断言结果
}

auto values = ::testing::Values(
  ParamType(ArgumentType("abc", "bca"), true),
  ParamType(ArgumentType("abc", "bad"), false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_01_02ParamTest, LeetCode_01_02Test, values);

}
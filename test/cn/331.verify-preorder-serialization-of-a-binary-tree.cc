//
// Created by timking.nf@foxmail.com on 2021/3/12.
//

#include "gtest/gtest.h"
#include "header.h"
#include "331.verify-preorder-serialization-of-a-binary-tree.h"

namespace LeetCode331 {

typedef string ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode331Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode331Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode331::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->isValidSerialization(argument), ret);
}

auto values = ::testing::Values(
  ParamType("9,3,4,#,#,1,#,#,2,#,6,#,#", true),
  ParamType("1,#", false),
  ParamType("1,#,#,#,#", false),
  ParamType("9,#,#,1", false),
  ParamType("#", true),
  ParamType("#,#,#", false)
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode331ParamTest, LeetCode331Test, values);

}
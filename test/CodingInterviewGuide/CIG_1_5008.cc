//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_5008.hpp"

namespace CIG_1_5008 {

typedef tuple<string, int> ArgumentType;
typedef char ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_5008_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_5008_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_5008::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string str;
  int index;
  tie(str, index) = arguments;

  ASSERT_EQ(solution->getCharAt(str, index), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("a_1_b_100", 0), 'a'),
  ParamType(ArgumentType("a_1_b_100", 1), 'b'),
  ParamType(ArgumentType("a_1_b_100", 101), '\0'),
  ParamType(ArgumentType("a_1_b_100", 100), 'b')
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_5008_ParamTest, CIG_1_5008_Test, values);

}
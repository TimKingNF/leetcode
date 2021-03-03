//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_5003.hpp"

namespace CIG_1_5003 {

typedef tuple<string, int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_5003_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_5003_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_5003::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string s;
  int k;
  tie(s, k) = arguments;

  ASSERT_EQ(solution->removeKZeros(s, k), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("A00B", 2), "AB"),
  ParamType(ArgumentType("A0000B000", 3), "A0000B"),
  ParamType(ArgumentType("0A0B0C00D0", 1), "ABC00D"),
  ParamType(ArgumentType("00A00B0C00D0", 2), "AB0CD0"),
  ParamType(ArgumentType("000A00B000C0D00", 3), "A00BC0D00"),
  ParamType(ArgumentType("000000", 2), "000000")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_5003_ParamTest, CIG_1_5003_Test, values);

}
//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_7003.hpp"

namespace CIG_1_7003 {

typedef tuple<int, int> ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_7003_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_7003_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_7003::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  int a, b;
  tie(a, b) = arguments;
  ASSERT_EQ(ret.size(), 4);
  ASSERT_EQ(solution->add(a, b), ret[0]);
  ASSERT_EQ(solution->minus(a, b), ret[1]);
  ASSERT_EQ(solution->multi(a, b), ret[2]);
  ASSERT_EQ(solution->divide(a, b), ret[3]);
}

auto values = ::testing::Values(
  ParamType(ArgumentType(10, 5), {15, 5, 50, 2})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_7003_ParamTest, CIG_1_7003_Test, values);

}
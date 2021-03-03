//
// Created by timking.nf@foxmail.com on 2021/2/2.
//

#include "gtest/gtest.h"
#include "header.h"
#include "CIG_1_4004.hpp"

namespace CIG_1_4004 {

typedef tuple<vector<int>, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class CIG_1_4004_Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(CIG_1_4004_Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new CIG_1_4004::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  vector<int> arr;
  int aim;
  tie(arr, aim) = arguments;

  ASSERT_EQ(solution->minCoins(arr, aim), ret);
}

auto values = ::testing::Values(
  ParamType(ArgumentType({5,2,3}, 20), -1),
  ParamType(ArgumentType({5,2,5,3}, 10), 2),
  ParamType(ArgumentType({5,2,5,3}, 15), 4),
  ParamType(ArgumentType({5,2,5,3}, 0), 0)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(CIG_1_4004_ParamTest, CIG_1_4004_Test, values);

}
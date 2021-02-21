//
// Created by timking.nf@foxmail.com on 2021/2/8.
//

#include "gtest/gtest.h"
#include "header.h"
#include "978.longest-turbulent-subarray.h"

namespace LeetCode978 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode978Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode978Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode978::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->maxTurbulenceSize(argument), ret);
}

auto values = ::testing::Values(
  ParamType({9,4,2,10,7,8,8,1,9}, 5),
  ParamType({4,8,12,16}, 2),
  ParamType({100}, 1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode978ParamTest, LeetCode978Test, values);

}
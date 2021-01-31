//
// Created by timking.nf@foxmail.com on 2020/12/15.
//

#include "gtest/gtest.h"
#include "header.h"
#include "738.monotone-increasing-digits.h"

namespace LeetCode738 {

typedef int ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode738Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode738Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode738::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->monotoneIncreasingDigits(argument), ret);
}

auto values = ::testing::Values(
  ParamType(10, 9),
  ParamType(1234, 1234),
  ParamType(332, 299),
  ParamType(123456789, 123456789),
  ParamType(6544, 5999)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode738ParamTest, LeetCode738Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/7/20.
//

#include "gtest/gtest.h"
#include "header.h"
#include "344.reverse-string.h"

namespace LeetCode344 {

typedef vector<char> ArgumentType;
typedef vector<char> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode344Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode344Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode344::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  solution->reverseString(argument);
  ASSERT_EQ(argument, ret);
}

auto values = ::testing::Values(
  ParamType({'h', 'e', 'l', 'l', 'o'}, {'o', 'l', 'l', 'e', 'h'}),
  ParamType({'H', 'a', 'n', 'n', 'a', 'h'}, {'h', 'a', 'n', 'n', 'a', 'H'})
);

//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode344ParamTest, LeetCode344Test, values);

}
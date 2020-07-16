//
// Created by timking.nf@foxmail.com on 2020/7/14.
//

#include "gtest/gtest.h"
#include "header.h"
#include "412.fizz-buzz.h"

namespace LeetCode412 {

typedef int ArgumentType;
typedef vector<string> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode412Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode412Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode412::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->fizzBuzz(argument), ret);
}

ResultType r1 = {
   "1",
   "2",
   "Fizz",
   "4",
   "Buzz",
   "Fizz",
   "7",
   "8",
   "Fizz",
   "Buzz",
   "11",
   "Fizz",
   "13",
   "14",
   "FizzBuzz"
};

auto values = ::testing::Values(
  ParamType(15, r1)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode412ParamTest, LeetCode412Test, values);

}
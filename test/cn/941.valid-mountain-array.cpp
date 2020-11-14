//
// Created by timking.nf@foxmail.com on 2020/11/3.
//

#include "gtest/gtest.h"
#include "header.h"
#include "941.valid-mountain-array.h"

namespace LeetCode941 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode941Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode941Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode941::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->validMountainArray(argument), ret);
}

auto values = ::testing::Values(
  ParamType({2,1}, false),
  ParamType({3,5,5}, false),
  ParamType({0,3,2,1}, true),
  ParamType({0,1,2,3}, false)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode941ParamTest, LeetCode941Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/10/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "845.longest-mountain-in-array.h"

namespace LeetCode845 {

typedef vector<int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode845Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode845Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode845::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->longestMountain(argument), ret);
}

auto values = ::testing::Values(
  ParamType({2,1,4,7,3,2,5}, 5),
  ParamType({2,2,2}, 0),
  ParamType({5,4,3,2,1,2,1}, 3)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode845ParamTest, LeetCode845Test, values);

}
//
// Created by timking.nf@foxmail.com on 2020/8/10.
//

#include "gtest/gtest.h"
#include "header.h"
#include "80.remove-duplicates-from-sorted-array-ii.h"

namespace LeetCode80 {

typedef vector<int> ArgumentType;
typedef tuple<int, vector<int>> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode80Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode80Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode80::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  int len;
  vector<int> asserts;
  tie(len, asserts) = ret;

  ASSERT_EQ(solution->removeDuplicates(argument), len);

  vector<int> slice(argument.begin(), argument.begin() + len);
  ASSERT_EQ(slice, asserts);
}

auto values = ::testing::Values(
  ParamType({1,1,1,2,2,3}, ResultType(5, {1,1,2,2,3})),
  ParamType({0, 0, 1, 1, 1, 1, 2, 3, 3}, ResultType(7, {0,0,1,1,2,3,3})),
  ParamType({}, ResultType(0, {})),
  ParamType({1}, ResultType{1, {1}}),
  ParamType({0,1,2,2,2,3,4,5,5,6}, ResultType(9, {0,1,2,2,3,4,5,5,6})),
  ParamType({1,1,1,1,2,2,3}, ResultType(5, {1,1,2,2,3}))
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode80ParamTest, LeetCode80Test, values);

}
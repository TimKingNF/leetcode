//
// Created by timking.nf@foxmail.com on 2021/2/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "255.verify-preorder-sequence-in-binary-search-tree.h"

namespace LeetCode255 {

typedef vector<int> ArgumentType;
typedef bool ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode255Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode255Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode255::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  ASSERT_EQ(solution->verifyPreorder(argument), ret);
}

auto values = ::testing::Values(
  ParamType({5,2,6,1,3}, false),
  ParamType({5,2,1,3,6}, true)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode255ParamTest, LeetCode255Test, values);

}
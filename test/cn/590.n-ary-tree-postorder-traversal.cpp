//
// Created by timking.nf@foxmail.com on 2020/8/17.
//

#include "gtest/gtest.h"
#include "header.h"
#include "590.n-ary-tree-postorder-traversal.h"

namespace LeetCode590 {

typedef string ArgumentType;
typedef vector<int> ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode590Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode590Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode590::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  Node* root = buildNTreeBySerialize<Node>(argument);
  ASSERT_EQ(solution->postorder(root), ret);
}

auto values = ::testing::Values(
  ParamType("[1 [3 [5 6 ] 2 4 ] ]", {5,6,3,2,4,1}),
  ParamType("[4]", {4}),
  ParamType("", {})
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode590ParamTest, LeetCode590Test, values);

}
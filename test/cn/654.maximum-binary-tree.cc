//
// Created by timking.nf@foxmail.com on 2021/2/1.
//

#include "gtest/gtest.h"
#include "header.h"
#include "654.maximum-binary-tree.h"

namespace LeetCode654 {

typedef vector<int> ArgumentType;
typedef string ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

class LeetCode654Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode654Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode654::Solution();
  ArgumentType argument;
  ResultType ret;
  tie(argument, ret) = GetParam();

  TreeNode* root = solution->constructMaximumBinaryTree(argument);
  string asserted = treeSerialize(root);
  ASSERT_EQ(asserted, ret);
}

auto values = ::testing::Values(
  ParamType({3,2,1,6,0,5}, "6,3,5,null,2,0,null,null,1"),
  ParamType({3,2,1}, "3,null,2,null,1")
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode654ParamTest, LeetCode654Test, values);

}
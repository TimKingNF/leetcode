//
// Created by timking.nf@foxmail.com on 2021/2/26.
//

#include "gtest/gtest.h"
#include "header.h"
#include "_04_08.first-common-ancestor-lcci.h"

namespace LeetCode_04_08 {

typedef tuple<string, int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

TreeNode* find_node(TreeNode* root, int val) {
  if (!root) return nullptr;
  if (root->val == val) return root;
  TreeNode* left_find = find_node(root->left, val);
  if (left_find) return left_find;
  return find_node(root->right, val);
}

class LeetCode_04_08Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode_04_08Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode_04_08::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string tree_str;
  int p, q;
  tie(tree_str, p, q) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode>(tree_str);
  TreeNode* p_node = find_node(root, p);
  TreeNode* q_node = find_node(root, q);
  TreeNode* ret_node = find_node(root, ret);

  ASSERT_EQ(solution->lowestCommonAncestor(root, p_node, q_node), ret_node);
}

auto values = ::testing::Values(
  ParamType(ArgumentType("3,5,1,6,2,0,8,null,null,7,4", 5, 1), 3),
  ParamType(ArgumentType("3,5,1,6,2,0,8,null,null,7,4", 5, 4), 5)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode_04_08ParamTest, LeetCode_04_08Test, values);

}
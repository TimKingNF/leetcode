//
// Created by timking.nf@foxmail.com on 2020/7/9.
//

#include "gtest/gtest.h"
#include "header.h"
#include "236.lowest-common-ancestor-of-a-binary-tree.h"

namespace LeetCode236 {

typedef tuple<string, int, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;

struct convert {
  int operator() (string v) {
    return stoi(v);
  }
};

TreeNode* find_node(TreeNode* root, int val) {
  if (!root) return nullptr;
  if (root->val == val) return root;
  TreeNode* left_find = find_node(root->left, val);
  if (left_find) return left_find;
  return find_node(root->right, val);
}

class LeetCode236Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode236Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode236::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string tree_str;
  int p, q;
  tie(tree_str, p, q) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode, convert>(tree_str);
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
INSTANTIATE_TEST_SUITE_P(LeetCode236ParamTest, LeetCode236Test, values);

}
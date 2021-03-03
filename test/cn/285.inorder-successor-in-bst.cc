//
// Created by timking.nf@foxmail.com on 2021/2/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "285.inorder-successor-in-bst.h"

namespace LeetCode285 {

typedef tuple<string, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
#define INVALID_NUM INT32_MIN

// 在 BST 树中找 值等于 n 的节点, 如果不存在等于 n 的节点，抛出异常
TreeNode* getTreeNode(TreeNode* root, int n) {
  if (n == INVALID_NUM) return nullptr;
  if (root->val == n) return root;
  if (root->val > n && root->left) {
    return getTreeNode(root->left, n);
  }
  if (root->val < n && root->right) {
    return getTreeNode(root->right, n);
  }
  cerr << "BST tree not contain the given value!" << endl;
  return nullptr;
}

class LeetCode285Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode285Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode285::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string args;
  int i;
  tie(args, i) = arguments;

  TreeNode* root = buildTreeBySerialize<TreeNode>(args);
  TreeNode* p = getTreeNode(root, i);
  TreeNode* assertNext = getTreeNode(root, ret);

  ASSERT_EQ(solution->inorderSuccessor(root, p), assertNext);  // 断言指针
}

auto values = ::testing::Values(
  ParamType(ArgumentType("2,1,3", 1), 2),
  ParamType(ArgumentType("5,3,6,2,4,null,null,1", 6), INVALID_NUM),
  ParamType(ArgumentType("5,3,6,2,4,null,null,1", 1), 2),
  ParamType(ArgumentType("15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9", 15), 17),
  ParamType(ArgumentType("15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9", 13), 15)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode285ParamTest, LeetCode285Test, values);

}
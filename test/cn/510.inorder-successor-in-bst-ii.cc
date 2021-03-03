//
// Created by timking.nf@foxmail.com on 2021/2/25.
//

#include "gtest/gtest.h"
#include "header.h"
#include "510.inorder-successor-in-bst-ii.h"

namespace LeetCode510 {

typedef tuple<string, int> ArgumentType;
typedef int ResultType;
typedef tuple<ArgumentType, ResultType> ParamType;
#define INVALID_NUM INT32_MIN

void connectParent(Node* node) {
  if (!node) return;
  // 层序遍历
  deque<Node*> q;
  q.push_back(node);

  while (!q.empty()) {
    node = q.front();
    q.pop_front();
    if (node->left) {
      node->left->parent = node;
      q.push_back(node->left);
    }
    if (node->right) {
      node->right->parent = node;
      q.push_back(node->right);
    }
  }
}

// 在 BST 树中找 值等于 n 的节点, 如果不存在等于 n 的节点，抛出异常
Node* getNode(Node* root, int n) {
  if (n == INVALID_NUM) return nullptr;
  if (root->val == n) return root;
  if (root->val > n && root->left) {
    return getNode(root->left, n);
  }
  if (root->val < n && root->right) {
    return getNode(root->right, n);
  }
  cerr << "BST tree not contain the given value!" << endl;
  return nullptr;
}

class LeetCode510Test : public ::testing::TestWithParam<ParamType> {
  // You can implement all the usual fixture class members here.
  // To access the test parameter, call GetParam() from class
  // TestWithParam<T>.
};

TEST_P(LeetCode510Test, main) {
  // Inside a test, access the test parameter with the GetParam() method
  // of the TestWithParam<T> class:

  auto solution = new LeetCode510::Solution();
  ArgumentType arguments;
  ResultType ret;
  tie(arguments, ret) = GetParam();

  string args;
  int i;
  tie(args, i) = arguments;

  Node* root = buildTreeBySerialize<Node>(args);
  connectParent(root);
  Node* node = getNode(root, i);
  Node* assertNext = getNode(root, ret);

  ASSERT_EQ(solution->inorderSuccessor(node), assertNext);  // 断言指针
}

auto values = ::testing::Values(
  ParamType(ArgumentType("2,1,3", 1), 2),
  ParamType(ArgumentType("5,3,6,2,4,null,null,1", 6), INVALID_NUM),
  ParamType(ArgumentType("15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9", 15), 17),
  ParamType(ArgumentType("15,6,18,3,7,17,20,2,4,null,13,null,null,null,null,null,null,null,null,9", 13), 15)
);
//第一个参数是前缀；第二个是类名；第三个是参数生成器
INSTANTIATE_TEST_SUITE_P(LeetCode510ParamTest, LeetCode510Test, values);

}
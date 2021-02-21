//
// Created by timking.nf@foxmail.com on 2021/2/7.
//

#ifndef LEETCODE_CIG_1_2018_HPP
#define LEETCODE_CIG_1_2018_HPP

#include "header.h"

namespace CIG_1_2018 {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* convert(TreeNode* root) {
    return solution2(root);
  }

  // 利用队列, 先中序遍历一遍
  // O( N ), O( N )
  TreeNode* solution1(TreeNode* root) {
    if (!root) return nullptr;
    queue<TreeNode*> q;
    stack<TreeNode*> stk;
    // 中序遍历
    while (root || !stk.empty()) {
      while (root) {
        stk.push(root);
        root = root->left;
      }
      if (!stk.empty()) {
        root = stk.top();
        q.push(root);
        stk.pop();
        root = root->right;
      }
    }
    // 遍历完成之后
    TreeNode *dummy = new TreeNode(0), *pre = dummy;
    while (!q.empty()) {
      pre->right = q.front();
      q.front()->left = pre;
      q.pop();
      pre = pre->right;
    }
    dummy->right->left = nullptr;  // 去掉头节点的 prev
    return dummy->right;
  }

  // 利用递归
  // O( N ), O( h ) 考虑栈的展开，最大展开数为树的高度
  TreeNode* solution2(TreeNode* root) {
    if (!root) return nullptr;
    TreeNode *last = solution2core(root);
    root = last->right;
    last->right = nullptr;
    return root;
  }

  // 将树转化为链表，并返回链表的尾节点，该尾节点的 right 指针指向 head 节点
  TreeNode* solution2core(TreeNode* root) {
    if (!root) return nullptr;
    auto left = solution2core(root->left);  // 处理左子树
    auto right = solution2core(root->right);  // 处理右子树
    auto leftS = left ? left->right : nullptr;  // 左边链表的开始节点
    auto rightS = right ? right->right : nullptr;  // 右边链表的开始节点
    if (left && right) {
      left->right = root;
      root->left = left;
      root->right = rightS;
      rightS->left = root;
      right->right = leftS;  // 将右边链表的最后一个节点的 right 指向开头
      return right;
    } else if (left) {
      left->right = root;
      root->left = left;
      root->right = leftS;
      return root;
    } else if (right) {
      root->right = rightS;
      rightS->left = root;
      right->right = root;
      return right;
    } else {
      root->right = root;
      return root;
    }
  }
};

}

#endif  // LEETCODE_CIG_1_2018_HPP

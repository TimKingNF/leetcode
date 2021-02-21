//
// Created by timking.nf@foxmail.com on 2021/2/19.
//

#ifndef LEETCODE_CIG_1_3008_HPP
#define LEETCODE_CIG_1_3008_HPP

#include "header.h"

namespace CIG_1_3008 {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Morris 遍历法
// 让子节点中的 null 节点用于指向上层的某个节点，用于代替栈的作用
class Solution {
 public:
  vector<int> preorder(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;

    // leftRight 记录当前节点的左子树的最右节点
    TreeNode *cur = root, *leftRight;
    while (cur) {
      leftRight = cur->left;
      if (leftRight) {  // 存在左子树
        // leftRight 需要取到当前左子树的最右节点
        while (leftRight->right && leftRight->right != cur) {
          leftRight = leftRight->right;
        }
        if (!leftRight->right) {  // 该节点的 right 此时还并没有指向 cur
          leftRight->right = cur;
          ans.push_back(cur->val);  // 在第一次遍历到上级节点的时候打印
          cur = cur->left;  // 下移一层
          continue;
        } else {  // 此时说明cur节点的左子树已经遍历完毕
          leftRight->right = nullptr;
        }
      } else {  // cur 不存在左子树，直接打印当前节点
        ans.push_back(cur->val);
      }
      // 这里返回有两种情况
      // 1. 在 leftRight 为 nullptr 的情况下，会由此返回上一级节点
      // 2. 在 cur 返回到上一级节点之后，前面重置了 leftRight->right 为空，并移动到上一级节点的右子树
      cur = cur->right;
    }
    return ans;
  }

  vector<int> inorder(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;

    // leftRight 记录当前节点的左子树的最右节点
    TreeNode *cur = root, *leftRight;
    while (cur) {
      leftRight = cur->left;
      if (leftRight) {  // 存在左子树
        // leftRight 需要取到当前左子树的最右节点
        while (leftRight->right && leftRight->right != cur) {
          leftRight = leftRight->right;
        }
        if (!leftRight->right) {  // 该节点的 right 此时还并没有指向 cur
          leftRight->right = cur;
          cur = cur->left;  // 下移一层
          continue;
        } else {  // 此时说明cur节点的左子树已经遍历完毕
          leftRight->right = nullptr;
        }
      }
      ans.push_back(cur->val);
      // 这里返回有两种情况
      // 1. 在 leftRight 为 nullptr 的情况下，会由此返回上一级节点
      // 2. 在 cur 返回到上一级节点之后，前面重置了 leftRight->right 为空，并移动到上一级节点的右子树
      cur = cur->right;
    }
    return ans;
  }

  vector<int> postorder(TreeNode* root) {
    if (!root) return {};
    vector<int> ans;

    // 翻转节点的右子树
    auto reverseEdge = [&](TreeNode* node) {
      TreeNode *pre = nullptr, *next;
      while (node) {
        next = node->right;
        node->right = pre;  // 指向当前节点的上一个节点
        pre = node;
        node = next;
      }
      return pre;
    };

    auto printEdge = [&](TreeNode* node) {
      TreeNode *tail = reverseEdge(node);  // 翻转此节点的右子树
      TreeNode *cur = tail;
      while (cur) {
        ans.push_back(cur->val);
        cur = cur->right;
      }
      reverseEdge(tail);  // 将右子树节点再次翻转回来
    };

    // leftRight 记录当前节点的左子树的最右节点
    TreeNode *cur = root, *leftRight;
    while (cur) {
      leftRight = cur->left;
      if (leftRight) {
        while (leftRight->right && leftRight->right != cur) {
          leftRight = leftRight->right;
        }
        if (!leftRight->right) {
          leftRight->right = cur;
          cur = cur->left;
          continue;
        } else {
          leftRight->right = nullptr;
          // 此时说明左子树已经遍历完毕，需要按照后续遍历的方式，逆序打印右子树
          printEdge(cur->left);
        }
      }
      cur = cur->right;
    }
    printEdge(root);  // 处理 root 节点尚未处理的节点
    return ans;
  }
};

}

#endif  // LEETCODE_CIG_1_3008_HPP

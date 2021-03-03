//
// Created by timking.nf@foxmail.com on 2021/2/26.
//

#ifndef LEETCODE_CIG_1_3025_HPP
#define LEETCODE_CIG_1_3025_HPP

#include "header.h"

namespace CIG_1_3025 {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int maxDistance(TreeNode* root) {
    if (!root) return 0;
    int depth = 0;
    return postOrder(root, &depth);
  }

 private:
  // depth 记录树的最大深度
  int postOrder(TreeNode* node, int* depth) {
    if (!node) {
      *depth = 0;
      return 0;
    }
    int maxFromLeft = 0, maxFromRight = 0;
    int leftMax = postOrder(node->left, &maxFromLeft);
    int rightMax = postOrder(node->right, &maxFromRight);
    *depth = max(maxFromLeft, maxFromRight) + 1;  // 更新深度
    return max(max(leftMax, rightMax), maxFromLeft + maxFromRight + 1);
  }
};

}

#endif  // LEETCODE_CIG_1_3025_HPP

//给定一个二叉树，判断它是否是高度平衡的二叉树。 
//
// 本题中，一棵高度平衡二叉树定义为： 
//
// 
// 一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过1。 
// 
//
// 示例 1: 
//
// 给定二叉树 [3,9,20,null,null,15,7] 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回 true 。 
// 
//示例 2: 
//
// 给定二叉树 [1,2,2,3,3,null,null,4,4] 
//
//        1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
// 
//
// 返回 false 。 
//
// 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode110 {

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
      return solution2(root);
    }

    bool solution1(TreeNode* root) {
      if (!root) return true;
      return solution1core(root) != -1;
    }

    int solution1core(TreeNode* root) {
      if (!root) return 0;
      int leftDepth = solution1core(root->left);
      if (leftDepth == -1) return -1;

      int rightDepth = solution1core(root->right);
      if (rightDepth == -1) return -1;

      if (abs(leftDepth - rightDepth) > 1) return -1;  // 不平衡
      return max(leftDepth, rightDepth) + 1;
    }

    bool solution2(TreeNode* root) {
      if (!root) return true;
      int leftHight;
      int rightHight;
      return solution2core(root->left, &leftHight) &&
             solution2core(root->right, &rightHight) &&
             abs(leftHight - rightHight) <= 1;
    }

    bool solution2core(TreeNode* node, int* hight) {
      if (!node) {
        *hight = 0;
        return true;
      }
      int leftHight;
      int rightHight;
      if (solution2core(node->left, &leftHight) &&
          solution2core(node->right, &rightHight) &&
          abs(leftHight - rightHight) <= 1) {
        *hight = max(leftHight, rightHight) + 1;
        return true;
      }
      return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个二叉树，找出其最小深度。 
//
// 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//
// 给定二叉树 [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最小深度 2. 
// Related Topics 树 深度优先搜索 广度优先搜索

#include "header.h"

namespace LeetCode111 {

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
    int minDepth(TreeNode* root) {
      return solution1(root);
    }

    int solution1(TreeNode* root) {
      if (!root) return 0;
      if (!root->left && !root->right) return 1;
      int left = solution1(root->left);
      int right = solution1(root->right);
      // 有一个节点为空，则 left 和 right 有一个必为0，可以返回之和
      if (!root->left || !root->right) return left + right + 1;
      return min(left, right) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
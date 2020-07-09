//给定一个二叉树，找出其最大深度。 
//
// 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例： 
//给定二叉树 [3,9,20,null,null,15,7]， 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最大深度 3 。 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode104 {

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
    // BFS
    int maxDepth(TreeNode* root) {
      if (!root) return 0;
      deque<TreeNode*> q;
      q.push_back(root);
      int ans = 0, size;
      TreeNode* node;

      while (!q.empty()) {
        size = q.size();
        for (int i = 0; i < size; ++i) {
          node = q.front();
          q.pop_front();
          if (node->left) q.push_back(node->left);
          if (node->right) q.push_back(node->right);
        }
        ans++;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//计算给定二叉树的所有左叶子之和。 
//
// 示例： 
//
// 
//    3
//   / \
//  9  20
//    /  \
//   15   7
//
//在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24 
//
// 
// Related Topics 树

#include "header.h"

namespace LeetCode404 {

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
    int sumOfLeftLeaves(TreeNode* root) {
      return solution1(root);
    }

    int solution1(TreeNode* root) {
      if (!root) return 0;
      int ans = 0;
      deque<pair<TreeNode*, int>> q;
      q.push_back({root, 1}); // 0 左子树，1 右子树
      TreeNode* cur;
      int child;
      while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
          tie(cur, child) = q.front();
          q.pop_front();
          if (!child && !cur->left && !cur->right) ans += cur->val;  // 是左子树且叶子节点
          if (cur->left) q.push_back({cur->left, 0});
          if (cur->right) q.push_back({cur->right, 1});
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
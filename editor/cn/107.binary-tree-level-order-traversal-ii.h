//给定一个二叉树，返回其节点值自底向上的层次遍历。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历） 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其自底向上的层次遍历为： 
//
// [
//  [15,7],
//  [9,20],
//  [3]
//]
// 
// Related Topics 树 广度优先搜索

#include "header.h"

namespace LeetCode107 {

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
      return solution1(root);
    }

    vector<vector<int>> solution1(TreeNode* root) {
      if (!root) return {};
      vector<vector<int>> ans;
      vector<int> line;
      deque<TreeNode*> q;
      q.push_back(root);

      while (!q.empty()) {
        int size = q.size();
        line.clear();
        for (int i = 0; i < size; ++i) {
          TreeNode* cur = q.front();
          q.pop_front();
          line.push_back(cur->val);
          if (cur->left) q.push_back(cur->left);
          if (cur->right) q.push_back(cur->right);
        }
        ans.push_back(line);
      }
      reverse(ans.begin(), ans.end());
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
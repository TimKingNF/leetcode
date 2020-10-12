//给定一个二叉树，返回所有从根节点到叶子节点的路径。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//
// 输入:
//
//   1
// /   \
//2     3
// \
//  5
//
//输出: ["1->2->5", "1->3"]
//
//解释: 所有根节点到叶子节点的路径为: 1->2->5, 1->3 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode257 {


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
    vector<string> binaryTreePaths(TreeNode* root) {
      return solution2(root);
    }

    vector<string> solution1(TreeNode* root) {
      if (!root) return {};
      if (!root->left && !root->right) return {to_string(root->val)};
      string path = to_string(root->val);
      vector<string> ans;
      helper(root->left, path, ans);
      helper(root->right, path, ans);
      return ans;
    }

    void helper(TreeNode* node, string path, vector<string>& ans) {
      if (!node) return;
      path += "->" + to_string(node->val);
      if (!node->left && !node->right) {  // 叶子节点
        ans.push_back(path);
        return;
      }
      helper(node->left, path, ans);
      helper(node->right, path, ans);
    }

    // 更简易的方法
    vector<string> solution2(TreeNode* root) {
      vector<string> ans;
      if (!root) return ans;
      if (!root->left && !root->right) return {to_string(root->val)};
      auto resL = solution2(root->left);
      for (int i = 0; i < resL.size(); ++i) {
        ans.push_back(to_string(root->val) + "->" + resL[i]);
      }
      auto resR = solution2(root->right);
      for (int i = 0; i < resR.size(); ++i) {
        ans.push_back(to_string(root->val) + "->" + resR[i]);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
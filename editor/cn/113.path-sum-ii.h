//给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。 
//
// 说明: 叶子节点是指没有子节点的节点。 
//
// 示例: 
//给定如下二叉树，以及目标和 sum = 22， 
//
//               5
//             / \
//            4   8
//           /   / \
//          11  13  4
//         /  \    / \
//        7    2  5   1
// 
//
// 返回: 
//
// [
//   [5,4,11,2],
//   [5,8,4,5]
//]
// 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode113 {

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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
      return solution1(root, sum);
    }

    vector<vector<int>> solution1(TreeNode* root, int sum) {
      if (!root) return {};
      vector<vector<int>> ans;
      vector<int> path;
      solution1core(root, ans, path, sum);
      return ans;
    }

    void solution1core(TreeNode* root, vector<vector<int>>& ans, vector<int>& path, int want) {
      if (!root) return;
      path.push_back(root->val);

      if (!root->left && !root->right && want == root->val) {
        ans.push_back(path);
      }
      solution1core(root->left, ans, path, want - root->val);
      solution1core(root->right, ans, path, want - root->val);
      path.pop_back();
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
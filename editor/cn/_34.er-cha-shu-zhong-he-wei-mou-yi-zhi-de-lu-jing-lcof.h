//输入一棵二叉树和一个整数，打印出二叉树中节点值的和为输入整数的所有路径。从树的根节点开始往下一直到叶节点所经过的节点形成一条路径。 
//
// 
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
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 10000 
// 
//
// 注意：本题与主站 113 题相同：https://leetcode-cn.com/problems/path-sum-ii/ 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode_34 {

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
    // TODO
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
      // 如果当前为叶子节点, 判断是否等于 want
      if (!root->left && !root->right && want == root->val) {
        ans.push_back(path);
      }
      solution1core(root->left, ans, path, want - root->val);
      solution1core(root->right, ans, path, want - root->val);
      path.pop_back();  // 左子树和右子树遍历完毕，删除该节点
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
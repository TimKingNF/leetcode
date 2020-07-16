//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。 
//
// 
//
// 示例： 
//二叉树：[3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回其层次遍历结果： 
//
// [
//  [3],
//  [9,20],
//  [15,7]
//]
// 
// Related Topics 树 广度优先搜索

#include "header.h"

namespace LeetCode102 {

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
    vector<vector<int>> levelOrder(TreeNode* root) {
      return solution1(root);
    }

    vector<vector<int>> solution1(TreeNode* root) {
      if (root == nullptr) return {};
      deque<TreeNode*> q;
      q.push_back(root);
      TreeNode* cur;
      vector<vector<int>> ans;
      vector<int> line;
      int toBe = 1, nextLevel = 0;

      while (!q.empty()) {
        cur = q.front();
        q.pop_front();
        line.push_back(cur->val);

        if (cur->left) {
          ++nextLevel;
          q.push_back(cur->left);
        }

        if (cur->right) {
          ++nextLevel;
          q.push_back(cur->right);
        }

        if (--toBe == 0) {
          ans.push_back(line);
          line.clear();
          toBe = nextLevel;
          nextLevel = 0;
        }
      }
      return ans;
    }

    // 更易理解一点
    vector<vector<int>> solution2(TreeNode* root) {
      if (!root) return {};
      deque<TreeNode*> p, q;
      p.push_back(root);
      vector<vector<int>> ans;
      vector<int> line;
      TreeNode* cur;
      while (!p.empty()) {
        cur = p.front();
        p.pop_front();
        line.push_back(cur->val);
        if (cur->left) q.push_back(cur->left);
        if (cur->right) q.push_back(cur->right);
        if (p.empty()) {
          swap(p, q);
          ans.push_back(line);
          line.clear();
        }
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
//从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。 
//
// 
//
// 例如: 
//给定二叉树: [3,9,20,null,null,15,7], 
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
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 1000 
// 
//
// 注意：本题与主站 102 题相同：https://leetcode-cn.com/problems/binary-tree-level-order-tra
//versal/ 
// Related Topics 树 广度优先搜索

#include "header.h"

namespace LeetCode_32_II {

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
      return solution2(root);
    }

    vector<vector<int>> solution1(TreeNode* root) {
      if (root == nullptr) return {};
      vector<vector<int>> ans{{root->val}};
      vector<int> line;
      vector<TreeNode*> q{root->left, root->right};
      vector<TreeNode*> tmp;
      TreeNode* cur;
      int step = 0;
      while (!q.empty()) {
        cur = *(q.begin() + step);
        if (cur) {
          line.push_back(cur->val);
          tmp.push_back(cur->left);
          tmp.push_back(cur->right);
        }
        if (++step == q.size()) {
          if (!line.empty()) {
            ans.push_back(line);
            line.clear();
          }
          q = tmp;
          tmp.clear();
          step = 0;
        }
      }
      return ans;
    }

    vector<vector<int>> solution2(TreeNode* root) {
      if (root == nullptr) return {};
      int toBe = 1, nextLevel = 0;
      deque<TreeNode*> q;
      q.push_back(root);
      TreeNode* cur;
      vector<vector<int>> ans;
      vector<int> line;

      while (!q.empty()) {
        cur = q.front();
        q.pop_front();
        line.push_back(cur->val);
        --toBe;

        if (cur->left) {
          q.push_back(cur->left);
          ++nextLevel;
        }
        if (cur->right) {
          q.push_back(cur->right);
          ++nextLevel;
        }

        if (toBe == 0) {
          ans.push_back(line);
          line.clear();
          toBe = nextLevel;
          nextLevel = 0;
        }
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
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
// 返回锯齿形层次遍历如下： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics 栈 树 广度优先搜索

#include "header.h"

namespace LeetCode103 {

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      return solution1(root);
    }

    // bfs
    vector<vector<int>> solution1(TreeNode* root) {
      if (!root) return {};
      vector<vector<int>> ans;
      vector<int> line;
      deque<TreeNode*> q;
      q.push_back(root);
      int flag = 1;  // 1 从左到右

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
        if (!flag) {  // 做一次翻转
          reverse(line.begin(), line.end());
        }
        ans.push_back(line);
        flag = 1-flag;
      }

      return ans;
    }

};
//leetcode submit region end(Prohibit modification and deletion)

}
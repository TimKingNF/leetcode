//给定一个非空二叉树, 返回一个由每层节点平均值组成的数组。 
//
// 
//
// 示例 1： 
//
// 输入：
//    3
//   / \
//  9  20
//    /  \
//   15   7
//输出：[3, 14.5, 11]
//解释：
//第 0 层的平均值是 3 ,  第1层是 14.5 , 第2层是 11 。因此返回 [3, 14.5, 11] 。
// 
//
// 
//
// 提示： 
//
// 
// 节点值的范围在32位有符号整数范围内。 
// 
// Related Topics 树

#include "header.h"

namespace LeetCode637 {

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
    vector<double> averageOfLevels(TreeNode* root) {
      return solution1(root);
    }

    // bfs
    vector<double> solution1(TreeNode* root) {
      if (!root) return {};
      deque<TreeNode*> q;
      vector<double> ans;
      q.push_back(root);
      while (!q.empty()) {
        int size = q.size();
        double sum = 0;
        for (int i = 0; i < size; ++i) {
          TreeNode* cur = q.front();
          q.pop_front();
          sum += cur->val;
          if (cur->left) q.push_back(cur->left);
          if (cur->right) q.push_back(cur->right);
        }
        ans.push_back(sum / size);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
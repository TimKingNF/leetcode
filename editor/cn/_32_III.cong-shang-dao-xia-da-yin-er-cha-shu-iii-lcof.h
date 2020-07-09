//请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。 
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
//  [20,9],
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
// Related Topics 树 广度优先搜索

#include "header.h"

namespace LeetCode_32_III {

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
      vector<vector<int>> ans;
      vector<int> line;
      TreeNode* cur;
      vector<TreeNode*> q{root}, tmp;
      int lineNum = 1, step = 0;

      while (!q.empty()) {
        cur = *(q.begin() + step);
        if (cur) {
          line.push_back(cur->val);
          tmp.push_back(cur->left);
          tmp.push_back(cur->right);
        }
        if (++step == q.size()) {
          if (!line.empty()) {
            if ((lineNum & 1) == 0)
              reverse(line.begin(), line.end());  // 增加了一步翻转
            ans.push_back(line);
            line.clear();
          }
          q = tmp;
          tmp.clear();
          step = 0;
          ++lineNum;  // 行号增加
        }
      }
      return ans;
    }

    vector<vector<int>> solution2(TreeNode* root) {
      if (root == nullptr) return {};
      vector<vector<int>> ans;
      vector<int> line;
      stack<TreeNode*> levels[2];
      int current = 0, next = 1;
      levels[current].push(root);
      TreeNode* pNode;

      while (!levels[0].empty() || !levels[1].empty()) {
        pNode = levels[current].top();
        levels[current].pop();
        line.push_back(pNode->val);

        if (current == 0) {  // 当前为奇数行时，下一层偶数行先左后右
          if (pNode->left)
            levels[next].push(pNode->left);
          if (pNode->right)
            levels[next].push(pNode->right);
        } else {  // 当前为偶数行时，下一城奇数行先右后左
          if (pNode->right)
            levels[next].push(pNode->right);
          if (pNode->left)
            levels[next].push(pNode->left);
        }

        if (levels[current].empty()) {
          ans.push_back(line);
          line.clear();
          current = 1 - current;
          next = 1 - next;
        }
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
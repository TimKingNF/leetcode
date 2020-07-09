//从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。 
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
// 返回： 
//
// [3,9,20,15,7]
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

namespace LeetCode_32_I {

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
    vector<int> levelOrder(TreeNode* root) {
      return solution1(root);
    }

    vector<int> solution1(TreeNode* root) {
      if (root == nullptr) return {};
      vector<int> ans{root->val};
      vector<TreeNode*> q{root->left, root->right};
      vector<TreeNode*> tmp;
      int step = 0;
      TreeNode* cur;
      while (!q.empty()) {
        cur = *(q.begin() + step);
        if (cur) {
          ans.push_back(cur->val);
          tmp.push_back(cur->left);
          tmp.push_back(cur->right);
        }
        if (++step == q.size()) {
          q = tmp;
          tmp.clear();
          step = 0;
        }
      }
      return ans;
    }

    vector<int> solution2(TreeNode* root) {
      if (root == nullptr) return {};
      deque<TreeNode*> q;
      q.push_back(root);
      TreeNode* cur;
      vector<int> ans;

      while (!q.empty()) {
        cur = q.front();
        ans.push_back(cur->val);
        if (cur->left)
          q.push_back(cur->left);
        if (cur->right)
          q.push_back(cur->right);
        q.pop_front();
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
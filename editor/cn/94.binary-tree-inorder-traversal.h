//给定一个二叉树，返回它的中序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]
//   1
//    \
//     2
//    /
//   3
//
//输出: [1,3,2] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树 哈希表

#include "header.h"

namespace LeetCode94 {

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
    vector<int> inorderTraversal(TreeNode* root) {
      return solution2(root);
    }

    // 递归
    vector<int> solution1(TreeNode* root) {
      if (!root) return {};
      vector<int> ans;
      inorder(root, &ans);
      return ans;
    }

    void inorder(TreeNode* root, vector<int>* ans) {
      if (!root) return;
      inorder(root->left, ans);
      (*ans).push_back(root->val);
      inorder(root->right, ans);
    }

    // 循环
    vector<int> solution2(TreeNode* root) {
      if (!root) return {};
      stack<TreeNode*> stk;
      vector<int> ans;
      TreeNode* cur;
      while (!stk.empty() || root) {
        while (root) {
          stk.push(root);
          root = root->left;
        }
        cur = stk.top();
        stk.pop();
        ans.push_back(cur->val);
        root = cur->right;
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
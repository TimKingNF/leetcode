//给定一个二叉树，返回它的 前序 遍历。 
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
//输出: [1,2,3]
// 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树

#include "header.h"

namespace LeetCode144 {

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
    vector<int> preorderTraversal(TreeNode* root) {
      return solution3(root);
    }

    // 递归
    vector<int> solution1(TreeNode* root) {
      vector<int> ans;

      function<void(TreeNode*)> solution1core = [&](TreeNode* root) {
        if (!root) return;
        ans.push_back(root->val);
        solution1core(root->left);
        solution1core(root->right);
      };

      solution1core(root);
      return ans;
    }

    // 迭代
    vector<int> solution2(TreeNode* root) {
      if (!root) return {};
      vector<int> ans;
      stack<TreeNode*> stk;
      TreeNode* cur;
      while (!stk.empty() || root) {
        while (root) {
          ans.push_back(root->val);
          stk.push(root);
          root = root->left;
        }
        cur = stk.top();
        stk.pop();
        root = cur->right;
      }
      return ans;
    }

    // 迭代的另一种实现方式
    vector<int> solution3(TreeNode* root) {
      if (!root) return {};
      vector<int> ans;
      stack<TreeNode*> stk;
      stk.push(root);

      while (!stk.empty()) {
        TreeNode* cur = stk.top();
        stk.pop();
        ans.push_back(cur->val);
        if (cur->right) stk.push(cur->right);
        if (cur->left) stk.push(cur->left);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
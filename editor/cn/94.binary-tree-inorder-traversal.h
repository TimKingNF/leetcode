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

      function<void(TreeNode*)> inorder = [&](TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
      };

      inorder(root);
      return ans;
    }

    // 循环
    vector<int> solution2(TreeNode* root) {
      vector<int> ans;
      if (!root) return ans;

      stack<TreeNode*> stk;
      while (!stk.empty() || root) {
        while (root) {
          stk.push(root);
          root = root->left;
        }
        root = stk.top();
        stk.pop();
        ans.push_back(root->val);
        root = root->right;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
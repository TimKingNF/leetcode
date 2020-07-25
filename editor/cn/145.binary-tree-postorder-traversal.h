//给定一个二叉树，返回它的 后序 遍历。 
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
//输出: [3,2,1] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树

#include "header.h"

namespace LeetCode145 {

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
    vector<int> postorderTraversal(TreeNode* root) {
      return solution1(root);
    }

    // 递归
    vector<int> solution1(TreeNode* root) {
      vector<int> ans;
      solution1core(root, ans);
      return ans;
    }

    void solution1core(TreeNode* root, vector<int>& ans) {
      if (!root) return;
      solution1core(root->left, ans);
      solution1core(root->right, ans);
      ans.push_back(root->val);
    }

    // TODO: 迭代
    vector<int> solution2(TreeNode* root) {
      if (!root) return {};
      stack<TreeNode*> stk;
      TreeNode *cur, *last_visited;
      vector<int> ans;
      while (!stk.empty() || root) {
        if (root) {
          stk.push(root);
          root = root->left;
        } else {
          cur = stk.top();
          if (cur->right && cur->right != last_visited) {  // 存在右子树且未被访问
            root = cur->right;
          } else {
            // cur 的左右子树都被访问过
            ans.push_back(cur->val);
            last_visited = cur;
            stk.pop();
            root = nullptr;  // 置空root
          }
        }
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个二叉树，判断其是否是一个有效的二叉搜索树。 
//
// 假设一个二叉搜索树具有如下特征： 
//
// 
// 节点的左子树只包含小于当前节点的数。 
// 节点的右子树只包含大于当前节点的数。 
// 所有左子树和右子树自身必须也是二叉搜索树。 
// 
//
// 示例 1: 
//
// 输入:
//    2
//   / \
//  1   3
//输出: true
// 
//
// 示例 2: 
//
// 输入:
//    5
//   / \
//  1   4
//     / \
//    3   6
//输出: false
//解释: 输入为: [5,1,4,null,null,3,6]。
//     根节点的值为 5 ，但是其右子节点值为 4 。
// 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode98 {

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
    bool isValidBST(TreeNode* root) {
      return solution2(root);
    }

    bool solution1(TreeNode* root) {
      return solution1core(root, nullptr, nullptr);
    }

    bool solution1core(TreeNode* root, TreeNode* min, TreeNode* max) {
      if (!root) return true;
      if (min && root->val <= min->val) return false;
      if (max && root->val >= max->val) return false;
      return solution1core(root->left, min, root) && solution1core(root->right, root, max);
    }

    // 中序遍历。 遍历形成一个递增数组
    bool solution2(TreeNode* root) {
      if (!root) return true;
      stack<TreeNode*> stk;
      long pre = (long) INT32_MIN - 1;

      while (!stk.empty() || root != nullptr) {
        while (root != nullptr) {
          stk.push(root);
          root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (root->val <= pre) return false;  // 中序遍历的值不符合递增数组
        pre = root->val;
        root = root->right;
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
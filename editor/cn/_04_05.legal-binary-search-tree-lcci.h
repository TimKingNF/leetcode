// 实现一个函数，检查一棵二叉树是否为二叉搜索树。
//
// 示例 1:
// 输入:
//     2
//    / \
//   1   3
// 输出: true
//
// 示例 2:
// 输入:
//     5
//    / \
//   1   4
//      / \
//     3   6
// 输出: false
// 解释: 输入为: [5,1,4,null,null,3,6]。
//      根节点的值为 5 ，但是其右子节点值为 4 。
//
//  Related Topics 树 深度优先搜索
// 👍 41 👎 0

#include "header.h"

namespace LeetCode_04_05 {

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
      if (!root) return true;
      return checkSubTree(root, nullptr, nullptr);
    }

    bool checkSubTree(TreeNode* node, TreeNode* min, TreeNode* max) {
      if (!node) return true;
      if (min && min->val >= node->val) return false;
      if (max && max->val <= node->val) return false;
      return checkSubTree(node->left, min, node) && checkSubTree(node->right, node, max);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
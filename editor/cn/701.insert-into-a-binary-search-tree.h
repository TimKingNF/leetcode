//给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 保证原始二叉搜索树中不存在新值。 
//
// 注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。 
//
// 例如, 
//
// 
//给定二叉搜索树:
//
//        4
//       / \
//      2   7
//     / \
//    1   3
//
//和 插入的值: 5
// 
//
// 你可以返回这个二叉搜索树: 
//
// 
//         4
//       /   \
//      2     7
//     / \   /
//    1   3 5
// 
//
// 或者这个树也是有效的: 
//
// 
//         5
//       /   \
//      2     7
//     / \
//    1   3
//         \
//          4
// 
// Related Topics 树

#include "header.h"

namespace LeetCode701 {

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//leetcode submit region begin(Prohibit modification and deletion)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
      return solution1(root, val);
    }

    // 插入到某叶节点作为左子树或者右子树
    TreeNode* solution1(TreeNode* root, int val) {
      if (!root) return new TreeNode(val);  // 空数也是二叉搜索树
      solution1core(root, val);
      return root;
    }

    void solution1core(TreeNode* node, int val) {
      if (!node) return;
      // 插入左叶子节点
      if (!node->left && val < node->val) {
        node->left = new TreeNode(val);
        return;
      }
      // 插入到右叶子节点
      if (!node->right && val > node->val) {
        node->right = new TreeNode(val);
        return;
      }
      // 往左子树找
      if (node->left && val < node->val) solution1core(node->left, val);
      // 往右子树找
      if (node->right && val > node->val) solution1core(node->right, val);
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
// 实现一个函数，检查二叉树是否平衡。在这个问题中，平衡树的定义如下：任意一个节点，其两棵子树的高度差不超过 1。
//
// 示例 1:
// 给定二叉树 [3,9,20,null,null,15,7]
//     3
//    / \
//   9  20
//     /  \
//    15   7
// 返回 true 。
//
// 示例 2:
// 给定二叉树 [1,2,2,3,3,null,null,4,4]
//       1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
// 返回 false 。
//
// Related Topics 树 深度优先搜索
// 👍 39 👎 0

#include "header.h"

namespace LeetCode_04_04 {

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
    bool isBalanced(TreeNode* root) {
      return solution1(root);
    }

    bool solution1(TreeNode* root) {
      if (!root) return true;
      return solution1core(root) != -1;
    }

    int solution1core(TreeNode* root) {
      if (!root) return 0;
      int leftHeight = solution1core(root->left);
      if (leftHeight == -1) return -1;
      int rightHeight = solution1core(root->right);
      if (rightHeight == -1) return -1;

      if (abs(leftHeight - rightHeight) > 1) return -1;
      return max(leftHeight, rightHeight) + 1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
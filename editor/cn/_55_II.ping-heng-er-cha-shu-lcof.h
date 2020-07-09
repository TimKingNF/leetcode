//输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。 
//
// 
//
// 示例 1: 
//
// 给定二叉树 [3,9,20,null,null,15,7]
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回 true 。 
// 
//示例 2: 
//
// 给定二叉树 [1,2,2,3,3,null,null,4,4] 
//
//        1
//      / \
//     2   2
//    / \
//   3   3
//  / \
// 4   4
// 
//
// 返回 false 。 
//
// 
//
// 限制： 
//
// 
// 1 <= 树的结点个数 <= 10000 
// 
//
// 注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/ 
//
// 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode_55_II {

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
      int leftDepth = solution1core(root->left);
      if (leftDepth == -1) return -1;  // 只要有一个子树是不平衡的，整个树都是不平衡的

      int rightDepth = solution1core(root->right);
      if (rightDepth == -1) return -1;

      if (abs(leftDepth - rightDepth) > 1)
        return -1;  // 表示不平衡
      return max(leftDepth, rightDepth) + 1;  // 递归获取最大深度值
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
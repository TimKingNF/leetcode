//请完成一个函数，输入一个二叉树，该函数输出它的镜像。 
//
// 例如输入： 
//
// 4 
// / \
// 2 7 
// / \ / \
//1 3 6 9 
//镜像输出： 
//
// 4 
// / \
// 7 2 
// / \ / \
//9 6 3 1 
//
// 
//
// 示例 1： 
//
// 输入：root = [4,2,7,1,3,6,9]
//输出：[4,7,2,9,6,3,1]
// 
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 1000 
//
// 注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/ 
// Related Topics 树

#include "header.h"

namespace LeetCode_27 {

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
    TreeNode* mirrorTree(TreeNode* root) {
      if (root == nullptr) return root;

      if (!root->left && !root->right) {  // 只有子节点为空的叶子节点才不用翻
        return root;
      }

      // 交换 left 和 right
      TreeNode* tmp = root->left;
      root->left = root->right;
      root->right = tmp;

      if (root->left)
        root->left = mirrorTree(root->left);
      if (root->right)
        root->right = mirrorTree(root->right);
      return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
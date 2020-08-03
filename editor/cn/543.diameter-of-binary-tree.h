//给定一棵二叉树，你需要计算它的直径长度。一棵二叉树的直径长度是任意两个结点路径长度中的最大值。这条路径可能穿过也可能不穿过根结点。 
//
// 
//
// 示例 : 
//给定二叉树 
//
//           1
//         / \
//        2   3
//       / \
//      4   5    
// 
//
// 返回 3, 它的长度是路径 [4,2,1,3] 或者 [5,2,1,3]。 
//
// 
//
// 注意：两结点之间的路径长度是以它们之间边的数目表示。 
// Related Topics 树

#include "header.h"

namespace LeetCode543 {

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
 private:
  int maxD;
public:
    int diameterOfBinaryTree(TreeNode* root) {
      return solution1(root);
    }

    // 直径为 左子树的高度 + 右子树的高度
    int solution1(TreeNode* root) {
      maxD = 0;
      solution1core(root);
      return maxD;
    }

    // 需要遍历每一个节点
    int solution1core(TreeNode* root) {
      if (!root) return 0;
      int leftDepth = solution1core(root->left);
      int rightDepth = solution1core(root->right);
      maxD = max(maxD, leftDepth + rightDepth);
      return max(leftDepth, rightDepth) + 1;
    }


};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个二叉树，检查它是否是镜像对称的。 
//
// 
//
// 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。 
//
//     1
//   / \
//  2   2
// / \ / \
//3  4 4  3
// 
//
// 
//
// 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的: 
//
//     1
//   / \
//  2   2
//   \   \
//   3    3
// 
//
// 
//
// 进阶： 
//
// 你可以运用递归和迭代两种方法解决这个问题吗？ 
// Related Topics 树 深度优先搜索 广度优先搜索

#include "header.h"

namespace LeetCode101 {

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
    bool isSymmetric(TreeNode* root) {
      return solution2(root);
    }

    bool solution1(TreeNode* root) {
      return solution1(root, root);
    }

    bool solution1(TreeNode* first, TreeNode* second) {
      if (!first && !second) return true;
      if (!first || !second) return false;
      if (first->val != second->val) return false;
      return solution1(first->left, second->right) && solution1(first->right, second->left);
    }

    bool solution2(TreeNode* root) {
      if (!root) return true;
      deque<TreeNode*> q;
      q.push_back(root->left);
      q.push_back(root->right);

      TreeNode *node1, *node2;
      while (!q.empty()) {
        node1 = q.back();
        q.pop_back();
        node2 = q.back();
        q.pop_back();

        if (!node1 && !node2) continue;
        if (!node1 || !node2) return false;
        if (node1->val != node2->val) return false;
        // 下两个比较的节点, 为 node1的左节点 和 node2 的右节点
        q.push_back(node1->left);
        q.push_back(node2->right);
        // 下两个比较的节点, 为 node1的右节点 和 node2 的左节点
        q.push_back(node1->right);
        q.push_back(node2->left);
      }
      return true;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
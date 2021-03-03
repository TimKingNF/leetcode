//给定一个二叉树，确定它是否是一个完全二叉树。 
//
// 百度百科中对完全二叉树的定义如下： 
//
// 若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：
//第 h 层可能包含 1~ 2h 个节点。） 
//
// 
//
// 示例 1： 
//
// 
//
// 输入：[1,2,3,4,5,6]
//输出：true
//解释：最后一层前的每一层都是满的（即，结点值为 {1} 和 {2,3} 的两层），且最后一层中的所有结点（{4,5,6}）都尽可能地向左。
// 
//
// 示例 2： 
//
// 
//
// 输入：[1,2,3,4,5,null,7]
//输出：false
//解释：值为 7 的结点没有尽可能靠向左侧。
// 
//
// 
//
// 提示： 
//
// 
// 树中将会有 1 到 100 个结点。 
// 
// Related Topics 树 
// 👍 107 👎 0

#include "header.h"

namespace LeetCode958 {

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
    bool isCompleteTree(TreeNode* root) {
      return solution1(root);
    }

    // 层序遍历，遵循以下规则
    // 1. 如果有右孩子没有左孩子，那么一定不是
    // 2. 如果一个节点不是左右孩子都有，那么之后遍历的节点，一定都是叶子节点
    bool solution1(TreeNode* root) {
      if (!root) return true;
      deque<TreeNode*> q;
      q.push_back(root);
      bool leaf = false;

      while (!q.empty()) {
        root = q.front();
        q.pop_front();
        if (root->right && !root->left) return false;
        if (leaf && (root->left || root->right)) return false;

        if (root->left) {
          q.push_back(root->left);
        }
        if (root->right) {
          q.push_back(root->right);
        } else {
          leaf = true;  // 第一个出现没有右孩子的，那么接下来的节点，都必须要是叶子节点
        }
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
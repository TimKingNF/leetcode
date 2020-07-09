//输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。 
//
// 例如： 
//
// 给定二叉树 [3,9,20,null,null,15,7]， 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
//
// 返回它的最大深度 3 。 
//
// 
//
// 提示： 
//
// 
// 节点总数 <= 10000 
// 
//
// 注意：本题与主站 104 题相同：https://leetcode-cn.com/problems/maximum-depth-of-binary-tre
//e/ 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode_55_I {

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
    int maxDepth(TreeNode* root) {
      return solution2(root);
    }

    // 递归解法, DFS
    int solution1(TreeNode* root) {
      if (!root) return 0;
      return max(solution1(root->left) + 1, solution1(root->right) + 1);
    }

    // BFS 广度优先遍历
    int solution2(TreeNode* root) {
      if (!root) return 0;
      deque<TreeNode*> q;
      q.push_back(root);
      int ans = 0, size;
      TreeNode* node;
      while (!q.empty()) {
        size = q.size();
        for (int i = 0; i < size; ++i) {
          node = q.front();
          q.pop_front();
          if (node->left) q.push_back(node->left);
          if (node->right) q.push_back(node->right);
        }
        ans++;
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
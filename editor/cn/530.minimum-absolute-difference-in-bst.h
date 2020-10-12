//给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。 
//
// 
//
// 示例： 
//
// 输入：
//
//   1
//    \
//     3
//    /
//   2
//
//输出：
//1
//
//解释：
//最小绝对差为 1，其中 2 和 1 的差的绝对值为 1（或者 2 和 3）。
// 
//
// 
//
// 提示： 
//
// 
// 树中至少有 2 个节点。 
// 本题与 783 https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes/ 
//相同 
// 
// Related Topics 树 
// 👍 151 👎 0

#include "header.h"

namespace LeetCode530 {

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
    int getMinimumDifference(TreeNode* root) {
      return solution1(root);
    }

    // 中序遍历，并求相邻两个节点的差的最小值
    int solution1(TreeNode* root) {
      // 非空树
      int ans = INT32_MAX, pre_val;
      bool isFirst = true;
      stack<TreeNode*> stk;
      while (!stk.empty() || root) {
        while (root) {
          stk.push(root);
          root = root->left;
        }
        root = stk.top();
        if (isFirst) isFirst = false;
        else ans = min(ans, root->val - pre_val);
        pre_val = root->val;
        stk.pop();
        root = root->right;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
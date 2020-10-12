//给定一个二叉搜索树的根节点 root，返回树中任意两节点的差的最小值。 
//
// 
//
// 示例： 
//
// 输入: root = [4,2,6,1,3,null,null]
//输出: 1
//解释:
//注意，root是树节点对象(TreeNode object)，而不是数组。
//
//给定的树 [4,2,6,1,3,null,null] 可表示为下图:
//
//          4
//        /   \
//      2      6
//     / \
//    1   3  
//
//最小的差值是 1, 它是节点1和节点2的差值, 也是节点3和节点2的差值。 
//
// 
//
// 注意： 
//
// 
// 二叉树的大小范围在 2 到 100。 
// 二叉树总是有效的，每个节点的值都是整数，且不重复。 
// 本题与 530：https://leetcode-cn.com/problems/minimum-absolute-difference-in-bst/ 
//相同 
// 
// Related Topics 树 递归 
// 👍 87 👎 0

#include "header.h"

namespace LeetCode783 {

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
    int minDiffInBST(TreeNode* root) {
      return solution1(root);
    }

    // 递归法
    int solution1(TreeNode* root) {
      int ans = INT32_MAX;
      // 注意此处 pre 要传递引用，以便在递归的时候修改 pre 为中序遍历中正确的前一个节点
      TreeNode *pre = nullptr;
      dfs(root, pre, ans);
      return ans;
    }

    void dfs(TreeNode *cur, TreeNode *&pre, int &ans) {
      if (!cur) return;
      dfs(cur->left, pre, ans);
      if (pre) {
        ans = min(ans, cur->val - pre->val);
      }
      pre = cur;
      dfs(cur->right, pre, ans);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
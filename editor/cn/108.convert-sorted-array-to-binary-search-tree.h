//将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。 
//
// 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。 
//
// 示例: 
//
// 给定有序数组: [-10,-3,0,5,9],
//
//一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：
//
//      0
//     / \
//   -3   9
//   /   /
// -10  5
// 
// Related Topics 树 深度优先搜索

#include "header.h"

namespace LeetCode108 {

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return solution2(nums);
    }

    TreeNode* solution1(vector<int>& nums) {
      if (nums.empty()) return nullptr;
      int left = 0, right = nums.size() - 1, middle;
      middle = left + (right - left) / 2;
      vector<int> leftNums = vector<int>(nums.begin(), nums.begin()+middle),
        rightNums = vector<int>(nums.begin()+middle+1, nums.end());
      TreeNode *root = new TreeNode(nums[middle]);
      root->left = solution1(leftNums);
      root->right = solution1(rightNums);
      return root;
    }

    TreeNode* solution2(vector<int>& nums) {
      if (nums.empty()) return nullptr;
      return solution2core(nums, 0, nums.size() - 1);
    }

    TreeNode* solution2core(vector<int>& nums, int left, int right) {
      if (left > right) return nullptr;
      int middle = left + (right - left) / 2;
      TreeNode *root = new TreeNode(nums[middle]);
      root->left = solution2core(nums, left, middle-1);
      root->right = solution2core(nums, middle+1, right);
      return root;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
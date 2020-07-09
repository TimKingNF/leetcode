//给定一棵二叉搜索树，请找出其中第k大的节点。 
//
// 
//
// 示例 1: 
//
// 输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 4 
//
// 示例 2: 
//
// 输入: root = [5,3,6,2,4,null,null,1], k = 3
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /
// 1
//输出: 4 
//
// 
//
// 限制： 
//
// 1 ≤ k ≤ 二叉搜索树元素个数 
// Related Topics 树

#include "header.h"

namespace LeetCode_54 {

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
    int kthLargest(TreeNode* root, int k) {
      return solution2(root, k);
    }

    // 使用中序遍历排成一个递增数组即可
    int solution1(TreeNode* root, int k) {
      vector<int> nums;
      solution1core(root, nums);
      return nums[nums.size()-k];
    }

    void solution1core(TreeNode* root, vector<int>& nums) {
      if (!root) return;
      solution1core(root->left, nums);
      nums.push_back(root->val);
      solution1core(root->right, nums);
    }

    // 不使用递归进行中序遍历
    int solution2(TreeNode* root, int k) {
      vector<int> nums;
      stack<TreeNode*> stk;
      TreeNode* p = root;
      while (p != nullptr || !stk.empty()) {
        while (p != nullptr) {  // 一直遍历到左子树的最左节点
          stk.push(p);
          p = p->left;
        }
        if (!stk.empty()) {
          p = stk.top();
          stk.pop();
          nums.push_back(p->val);
          p = p->right;
        }
      }
      return nums[nums.size() - k];
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
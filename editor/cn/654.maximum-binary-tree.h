//给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下： 
//
// 
// 二叉树的根是数组 nums 中的最大元素。 
// 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。 
// 右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。 
// 
//
// 返回有给定数组 nums 构建的 最大二叉树 。 
//
// 
//
// 示例 1： 
//
// 
//输入：nums = [3,2,1,6,0,5]
//输出：[6,3,5,null,2,0,null,null,1]
//解释：递归调用如下所示：
//- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
//    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
//        - 空数组，无子节点。
//        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
//            - 空数组，无子节点。
//            - 只有一个元素，所以子节点是一个值为 1 的节点。
//    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
//        - 只有一个元素，所以子节点是一个值为 0 的节点。
//        - 空数组，无子节点。
// 
//
// 示例 2： 
//
// 
//输入：nums = [3,2,1]
//输出：[3,null,2,null,1]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= nums.length <= 1000 
// 0 <= nums[i] <= 1000 
// nums 中的所有整数 互不相同 
// 
// Related Topics 树 
// 👍 237 👎 0

#include "header.h"

namespace LeetCode654 {

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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      return solution1(nums);
    }

    // O( N*h ) h 为 树高
    TreeNode* solution1(vector<int>& nums) {
      // 求数组中最大值，作为根节点
      return getRoot(nums, 0, nums.size());
    }

    TreeNode* getRoot(vector<int>& nums, int start, int end) {
      if (start >= end) return nullptr;
      auto max_element = std::max_element(nums.begin() + start, nums.begin() + end);
      TreeNode* root = new TreeNode(*max_element);
      root->left = getRoot(nums, start, max_element - nums.begin());
      root->right = getRoot(nums, max_element - nums.begin() + 1, end);
      return root;
    }

    // 拓展:
    // 经证明可知，在数组中，求得当前数 从左数第一个大于的节点，和从右数第一个大于的节点，二者中较小值为其父节点
    // 但这种写法并不符合定义： 左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树
    // O( N ), O( N )
    TreeNode* solution2(vector<int>& nums) {
      int n = nums.size();
      vector<TreeNode*> ptrs(n);
      for (int i = 0; i < n; ++i) ptrs[i] = new TreeNode(nums[i]);

      // 构建两个字典，用于记录节点从左数和从右数的第一个大于的节点
      stack<TreeNode*> stk;  // 帮助辅助计算
      auto popStack = [&](unordered_map<TreeNode*, TreeNode*>& dict) {
        auto node = stk.top();
        stk.pop();
        if (stk.empty()) dict[node] = nullptr;  // 说明 node 节点从某个方向数没有比它大的节点
        else dict[node] = stk.top();
      };
      unordered_map<TreeNode*, TreeNode*> leftDict, rightDict;

      // 计算每个元素从左数第一个大于的节点，放在 leftDict 中
      for (int i = 0; i < n; ++i) {
        auto node = ptrs[i];
        while (!stk.empty() && stk.top()->val < node->val) {
          popStack(leftDict);  // 栈顶的值弹出，并记录左数第一个大于的节点是栈的下一个值
        }
        stk.push(node);
      }
      // 处理剩余的元素
      while (!stk.empty()) popStack(leftDict);

      // 同上，处理 rightDict
      for (int i = n-1; i >= 0; --i) {
        auto node = ptrs[i];
        while (!stk.empty() && stk.top()->val < node->val) {
          popStack(rightDict);
        }
        stk.push(node);
      }
      while (!stk.empty()) popStack(rightDict);

      // 根据 leftDict 和 rightDict 即可连接起所有的节点
      TreeNode* root;
      for (int i = 0; i < n; ++i) {
        auto node = ptrs[i];
        auto left = leftDict[node];
        auto right = rightDict[node];
        if (!left && !right) root = node;  // 两边都没有比它更大的值，说明它就是根节点
        else if (!left) {  // 说明 node 的父节点是 right
          // 考虑 node 是左孩子还是右孩子, 在此处，丢失了定义关系
          if (!right->left) right->left = node;
          else right->right = node;
        } else if (!right) {  // 同上
          if (!left->left) left->left = node;
          else left->right = node;
        } else {
          auto parent = left->val < right->val ? left : right;
          if (!parent->left) parent->left = node;
          else parent->right = node;
        }
      }
      return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//根据一棵树的前序遍历与中序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 前序遍历 preorder = [3,9,20,15,7]
//中序遍历 inorder = [9,3,15,20,7] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7 
// Related Topics 树 深度优先搜索 数组

#include "header.h"

namespace LeetCode105 {

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
    // TODO: 有多种解法
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      // return __buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
      return solution1(preorder, inorder);
    }

    TreeNode* __buildTree(vector<int>::iterator pre_begin,
                          vector<int>::iterator pre_end,
                          vector<int>::iterator in_begin,
                          vector<int>::iterator in_end) {
      if (pre_begin == pre_end || in_begin == in_end) return nullptr;
      TreeNode* root = new TreeNode(*pre_begin);
      auto findRoot = find(in_begin, in_end, *pre_begin);  // 找到根节点在中序遍历中的下标
      int step = findRoot - in_begin;
      root->left = __buildTree(pre_begin+1, pre_begin+step+1, in_begin, in_begin+step);
      root->right = __buildTree(pre_begin+step+1, pre_end, in_begin+step+1, in_end);
      return root;
    }

    // 通过迭代
    TreeNode* solution1(vector<int>& preorder, vector<int>& inorder) {
      if (!preorder.size()) {
        return nullptr;
      }
      TreeNode* root = new TreeNode(preorder[0]);
      stack<TreeNode*> stk;
      stk.push(root);
      int inorderIndex = 0;
      for (int i = 1; i < preorder.size(); ++i) {
        int preorderVal = preorder[i];
        TreeNode* node = stk.top();
        if (node->val != inorder[inorderIndex]) {
          node->left = new TreeNode(preorderVal);
          stk.push(node->left);
        }
        else {
          while (!stk.empty() && stk.top()->val == inorder[inorderIndex]) {
            node = stk.top();
            stk.pop();
            ++inorderIndex;
          }

          node->right = new TreeNode(preorderVal);
          stk.push(node->right);
        }
      }
      return root;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
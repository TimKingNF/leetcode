//根据一棵树的中序遍历与后序遍历构造二叉树。 
//
// 注意: 
//你可以假设树中没有重复的元素。 
//
// 例如，给出 
//
// 中序遍历 inorder = [9,3,15,20,7]
//后序遍历 postorder = [9,15,7,20,3] 
//
// 返回如下的二叉树： 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
// Related Topics 树 深度优先搜索 数组

#include "header.h"

namespace LeetCode106 {

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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      return __buildTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }

    TreeNode* __buildTree(vector<int>::iterator in_begin,
                          vector<int>::iterator in_end,
                          vector<int>::iterator post_begin,
                          vector<int>::iterator post_end) {
      if (in_begin == in_end || post_begin == post_end) return nullptr;
      TreeNode* root = new TreeNode(*(post_end-1));
      auto findRoot = find(in_begin, in_end, root->val);
      int step = findRoot - in_begin;
      root->left = __buildTree(in_begin, in_begin + step, post_begin, post_begin + step);
      root->right = __buildTree(in_begin + step + 1, in_end, post_begin + step, post_end - 1);
      return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
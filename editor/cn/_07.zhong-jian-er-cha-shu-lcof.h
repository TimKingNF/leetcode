//输入某二叉树的前序遍历和中序遍历的结果，请重建该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。 
//
// 
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
//
// 
//
// 限制： 
//
// 0 <= 节点个数 <= 5000 
//
// 
//
// 注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-
//preorder-and-inorder-traversal/ 
// Related Topics 树 递归

#include "header.h"

namespace LeetCode_07 {

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      // return solution1(preorder, inorder);
      return __buildTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }

    // 需要多次拷贝
    TreeNode* solution1(vector<int>& preorder, vector<int>& inorder) {
      if (preorder.empty() || inorder.empty()) return nullptr;

      // 前序遍历的第一个数字就是根节点
      TreeNode* root = new TreeNode(preorder[0]);

      // 在中序遍历序列中找到根节点的值
      int i;
      for (i = 0; i < inorder.size(); ++i) {
        if (inorder[i] == preorder[0])
          break;
      }

      // 已知在中序遍历中根节点左边的值为 左子树的内容, 后边的值为 右子树的内容
      vector<int> preorder_left(i);
      copy(preorder.begin()+1, preorder.begin()+i+1, preorder_left.begin());
      vector<int> inorder_left(i);
      copy(inorder.begin(), inorder.begin()+i, inorder_left.begin());

      root->left = buildTree(preorder_left, inorder_left);

      vector<int> preorder_right(preorder.size() - 1 - i);
      copy(preorder.begin()+i+1, preorder.end(), preorder_right.begin());
      vector<int> inorder_right(inorder.size()-i-1);
      copy(inorder.begin()+i+1, inorder.end(), inorder_right.begin());
      root->right = buildTree(preorder_right, inorder_right);

      return root;
    }

    TreeNode* __buildTree(vector<int>::iterator pre_begin,
                          vector<int>::iterator pre_end,
                          vector<int>::iterator in_begin,
                          vector<int>::iterator in_end) {
      if (pre_begin == pre_end || in_begin == in_end) return nullptr;

      TreeNode* root = new TreeNode(*pre_begin);
      auto findRoot = find(in_begin, in_end, *pre_begin);  // 找到在中序遍历中根节点的 iterator
      int step = findRoot - in_begin;
      root->left = __buildTree(pre_begin+1, pre_begin+step+1, in_begin, in_begin+step);
      root->right = __buildTree(pre_begin+step+1, pre_end, in_begin+step+1, in_end);
      return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
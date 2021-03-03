//给你一个二叉搜索树和其中的某一个结点，请你找出该结点在树中顺序后继的节点。 
//
// 结点 p 的后继是值比 p.val 大的结点中键值最小的结点。 
//
// 
//
// 示例 1: 
//
// 
//
// 输入: root = [2,1,3], p = 1
//输出: 2
//解析: 这里 1 的顺序后继是 2。请注意 p 和返回值都应是 TreeNode 类型。
// 
//
// 示例 2: 
//
// 
//
// 输入: root = [5,3,6,2,4,null,null,1], p = 6
//输出: null
//解析: 因为给出的结点没有顺序后继，所以答案就返回 null 了。
// 
//
// 
//
// 注意: 
//
// 
// 假如给出的结点在该树中没有顺序后继的话，请返回 null 
// 我们保证树中每个结点的值是唯一的 
// 
// Related Topics 树 
// 👍 88 👎 0

#include "header.h"

namespace LeetCode285 {

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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
      return solution2(root, p);
    }

    // 中序遍历，取下一个节点
    TreeNode* solution1(TreeNode* root, TreeNode* p) {
      if (!root || !p) return nullptr;

      TreeNode *leftRight, *pre = nullptr;
      while (root) {
        leftRight = root->left;
        if (leftRight) {
          while (leftRight->right && leftRight->right != root) {
            leftRight = leftRight->right;
          }
          if (!leftRight->right) {
            leftRight->right = root;
            root = root->left;
            continue;
          } else {
            leftRight->right = nullptr;
          }
        }
        if (pre == p) return root;  // 如果中序遍历的前一个元素是 p 则返回下一个元素
        pre = root;
        root = root->right;
      }
      return nullptr;  // 说明 p 就是最后一个
    }

    // 或者更简单点
    TreeNode* solution2(TreeNode* root, TreeNode* p) {
      TreeNode *tp, *ans = nullptr;

      if(p->right) {  // p 有右子树，直接查右子树的最左节点
        tp = p->right;
        while(tp->left) {
          tp = tp->left;
        }
        ans = tp;
      } else {  // 从 root 的路径往下找，直到查找路径上，离 p 最近且大于 p 的节点
        tp = root;
        while(true) {
          if (p->val < tp->val) {
            ans = tp;
            tp = tp->left;
          } else if (p->val > tp->val)  {
            tp = tp->right;
          } else {
            break;
          }
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。 
//
// 百度百科中最近公共祖先的定义为：“对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（
//一个节点也可以是它自己的祖先）。” 
//
// 例如，给定如下二叉树: root = [3,5,1,6,2,0,8,null,null,7,4] 
//
// 
//
// 
//
// 示例 1: 
//
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
//输出: 3
//解释: 节点 5 和节点 1 的最近公共祖先是节点 3。
// 
//
// 示例 2: 
//
// 输入: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
//输出: 5
//解释: 节点 5 和节点 4 的最近公共祖先是节点 5。因为根据定义最近公共祖先节点可以为节点本身。
// 
//
// 
//
// 说明: 
//
// 
// 所有节点的值都是唯一的。 
// p、q 为不同节点且均存在于给定的二叉树中。 
// 
//
// 注意：本题与主站 236 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a
//-binary-tree/ 
// Related Topics 树

#include "header.h"

namespace LeetCode_68_II {

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
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    return solution2(root, p, q);
  }

  TreeNode* solution1(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || !p || !q) return nullptr;
    deque<TreeNode*> p_deque = solution1core(root, p);
    deque<TreeNode*> q_deque = solution1core(root, q);
    TreeNode* ans = nullptr;
    while (!p_deque.empty() && !q_deque.empty() && p_deque.front() == q_deque.front()) {
      ans = p_deque.front();
      p_deque.pop_front();
      q_deque.pop_front();
    }
    return ans;
  }

  // 遍历找到该节点并返回寻找路径
  deque<TreeNode*> solution1core(TreeNode* root, TreeNode* p) {
    deque<TreeNode*> ans;
    solution1helper(root, p, ans);
    return ans;
  }

  // 前序遍历得到路径
  bool solution1helper(TreeNode* root, TreeNode* p, deque<TreeNode*> &ans) {
    if (root == nullptr) return false;
    ans.push_back(root);
    if (root == p) return true;
    bool found = solution1helper(root->left, p, ans) || solution1helper(root->right, p, ans);
    if (!found) ans.pop_back();  // 左右子树都没找到，则弹出root
    return found;
  }

  // TODO
  TreeNode* solution2(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = solution2(root->left, p, q);
    TreeNode* right = solution2(root->right, p, q);
    // if (!left && !right) return nullptr;
    if (!left) return right;
    if (!right) return left;
    return root;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}
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
// Related Topics 树

#include "header.h"

namespace LeetCode236 {

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

    // 后序遍历
    TreeNode* solution1(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root || root == p || root == q) return root;
      // 先处理左右子树
      TreeNode* left = lowestCommonAncestor(root->left, p, q);
      TreeNode* right = lowestCommonAncestor(root->right, p, q);

      // left right 都为空，说明 p q 不在 root 的子树上，应返回 nullptr
      // 和 left 为空时 返回 right, 两个情况整合
      if (!left) return right;

      // 当 right 为空时，返回 left
      if (!right) return left;

      // 两个都不为空，说明首次在 root 点相遇
      return root;
    }

    // 支持多次查询
    // O( N+h ), O( N )
    // N 是构造字典的时间，h 是查询的时间
    TreeNode* solution2(TreeNode* root, TreeNode* p, TreeNode* q) {
      // 构造字典记录每个节点对应的父节点
      unordered_map<TreeNode*, TreeNode*> dict{{root, nullptr}};
      function<void(TreeNode*)> setDict = [&](TreeNode* node) {
        if (!node) return;
        if (node->left) dict.insert({node->left, node});
        if (node->right) dict.insert({node->right, node});
        setDict(node->left);
        setDict(node->right);
      };
      setDict(root);

      // 查询时，先将 p 的父节点记录到一个集合中，然后一次判断 q 的父节点
      unordered_set<TreeNode*> parents;
      while (dict.count(p)) {
        parents.insert(p);
        p = dict[p];
      }
      while (!parents.count(q)) {
        q = dict[q];
      }
      return q;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个二叉搜索树（Binary Search Tree），把它转换成为累加树（Greater Tree)，使得每个节点的值是原来的节点值加上所有大于它的节
//点值之和。 
//
// 
//
// 例如： 
//
// 输入: 原始二叉搜索树:
//              5
//            /   \
//           2     13
//
//输出: 转换为累加树:
//             18
//            /   \
//          20     13
// 
//
// 
//
// 注意：本题和 1038: https://leetcode-cn.com/problems/binary-search-tree-to-greater-s
//um-tree/ 相同 
// Related Topics 树

#include "header.h"

namespace LeetCode538 {

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
    TreeNode* convertBST(TreeNode* root) {
      return solution3(root);
    }

    // 中序遍历
    // O( N! )
    TreeNode* solution1(TreeNode* root) {
      if (!root) return root;
      vector<TreeNode*> q;
      stack<TreeNode*> stk;
      TreeNode* cur = root;
      while (!stk.empty() || cur) {
        while (cur) {
          stk.push(cur);
          cur = cur->left;
        }
        cur = stk.top();
        stk.pop();
        for (auto v : q) {
          v->val += cur->val;
        }
        q.push_back(cur);
        cur = cur->right;
      }
      return root;
    }

    // 反向的中序遍历
    // O( N ), O( N )
    TreeNode* solution2(TreeNode* root) {
      int sum = 0;
      function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return;
        dfs(node->right);
        sum += node->val;
        node->val = sum;
        dfs(node->left);
      };
      dfs(root);
      return root;
    }

    // Morris 遍历
    // 在线性时间内，只占用常数空间来实现中序遍历
    // O( N ), O( 1 )
    TreeNode* solution3(TreeNode* root) {
      int sum = 0;
      TreeNode* node = root;

      while (node != nullptr) {
        if (node->right == nullptr) {
          // 如果当前节点的右子节点为空，处理当前节点，并遍历当前节点的左子节点
          sum += node->val;
          node->val = sum;
          node = node->left;
        } else {
          // 如果当前节点的右子节点不为空，找到当前节点右子树的最左节点（该节点为当前节点中序遍历的前驱节点
          TreeNode* succ = getSuccessor(node);
          if (succ->left == nullptr) {
            // 如果最左节点的左指针为空，将最左节点的左指针指向当前节点，遍历当前节点的右子节点
            succ->left = node;
            node = node->right;
          } else {
            // 如果最左节点的左指针不为空，将最左节点的左指针重新置为空（恢复树的原状）
            // 处理当前节点，并将当前节点置为其左节点
            succ->left = nullptr;
            sum += node->val;
            node->val = sum;
            node = node->left;
          }
        }
      }

      return root;
    }

    TreeNode* getSuccessor(TreeNode* node) {
      TreeNode* succ = node->right;
      while (succ->left != nullptr && succ->left != node) {
        succ = succ->left;
      }
      return succ;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
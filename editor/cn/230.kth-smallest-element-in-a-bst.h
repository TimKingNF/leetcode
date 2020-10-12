//给定一个二叉搜索树，编写一个函数 kthSmallest 来查找其中第 k 个最小的元素。 
//
// 说明： 
//你可以假设 k 总是有效的，1 ≤ k ≤ 二叉搜索树元素个数。 
//
// 示例 1: 
//
// 输入: root = [3,1,4,null,2], k = 1
//   3
//  / \
// 1   4
//  \
//   2
//输出: 1 
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
//输出: 3 
//
// 进阶： 
//如果二叉搜索树经常被修改（插入/删除操作）并且你需要频繁地查找第 k 小的值，你将如何优化 kthSmallest 函数？ 
// Related Topics 树 二分查找

#include "header.h"

namespace LeetCode230 {

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
    int kthSmallest(TreeNode* root, int k) {
      return solution3(root, k);
    }

    // 中序遍历拿到第 k 小的值
    int solution1(TreeNode* root, int k) {
      stack<TreeNode*> stk;
      while (!stk.empty() || root) {
        while (root) {
          stk.push(root);
          root = root->left;
        }
        root = stk.top();
        stk.pop();
        if (--k == 0) return root->val;
        root = root->right;
      }
      return -1;  // k 总是有效的，所以不会走到这里
    }

    // 二分加递归
    int solution2(TreeNode* root, int k) {
      int cnt = numOfRoot(root->left);
      if (k <= cnt) return solution2(root->left, k);
      else if (k > cnt + 1) return solution2(root->right, k-cnt-1);
      return root->val;  // k 正好比左子树节点数大一，那么结果就是 root 本身
    }

    int numOfRoot(TreeNode* root) {
      if (!root) return 0;
      return 1 + numOfRoot(root->left) + numOfRoot(root->right);
    }

    // 进阶：构建一个k大小的大顶堆
    int solution3(TreeNode* root, int k) {
      struct cmp {
        bool operator() (TreeNode* first, TreeNode* second) {
          return first->val < second->val;  // 从大到小
        }
      };

      priority_queue<TreeNode*, vector<TreeNode*>, cmp> pq;

      function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (!node) return;
        if (pq.size() < k) {
          pq.push(node);
        } else if (node->val < pq.top()->val) {  // 当前元素小于大顶堆的最大值
          pq.pop();
          pq.push(node);
        }
        dfs(node->left);
        dfs(node->right);
      };
      // 遍历二叉树，构建堆
      dfs(root);
      return pq.top()->val;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
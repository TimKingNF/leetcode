//给定一个整数 n，生成所有由 1 ... n 为节点所组成的 二叉搜索树 。 
//
// 
//
// 示例： 
//
// 输入：3
//输出：
//[
//  [1,null,3,2],
//  [3,2,null,1],
//  [3,1,null,null,2],
//  [2,1,3],
//  [1,null,2,null,3]
//]
//解释：
//以上的输出对应以下 5 种不同结构的二叉搜索树：
//
//   1         3     3      2      1
//    \       /     /      / \      \
//     3     2     1      1   3      2
//    /     /       \                 \
//   2     1         2                 3
// 
//
// 
//
// 提示： 
//
// 
// 0 <= n <= 8 
// 
// Related Topics 树 动态规划

#include "header.h"

namespace LeetCode95 {

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
    // TODO
    vector<TreeNode*> generateTrees(int n) {
      return solution4(n);
    }

    // 递归
    vector<TreeNode*> solution1(int n) {
      if (n == 0) return {};
      return solution1core(1, n);
    }

    vector<TreeNode*> solution1core(int start, int end) {
      if (start > end) return {nullptr};
      if (start == end) return {new TreeNode(start)};

      vector<TreeNode*> ans;
      // 尝试以每个数字作为根节点
      for (int i = start; i <= end; ++i) {
        vector<TreeNode*> leftTreeList = solution1core(start, i-1);
        vector<TreeNode*> rightTreeList = solution1core(i+1, end);
        for (auto leftTree : leftTreeList) {
          for (auto rightTree : rightTreeList) {
            auto* root = new TreeNode(i, leftTree, rightTree);
            ans.push_back(root);
          }
        }
      }
      return ans;
    }

    // 在 solution1 的基础上缓存一下结果，避免重复计算
 private:
  vector<vector<vector<TreeNode*>>> memo;

 public:
    vector<TreeNode*> solution2(int n) {
      if (n == 0) return {};
      memo.resize(n+1, vector<vector<TreeNode*>>(n+1));
      return solution2core(1, n);
    }

    vector<TreeNode*> solution2core(int start, int end) {
      if (start > end) return {nullptr};
      if (!memo[start][end].empty()) return memo[start][end];  // 返回缓存的结果
      vector<TreeNode*> ans;
      for (int i = start; i <= end; ++i) {
        for (auto l : solution2core(start, i-1)) {
          for (auto r : solution2core(i+1, end)) {
            auto* root = new TreeNode(i, l, r);
            ans.push_back(root);
          }
        }
      }
      return memo[start][end] = ans;
    }

    // 动态规划思路1:
    // 已知在已有的vector<TreeNode*>中添加一个比所有节点值都大的节点，则该节点只有以下3种可能可以插入
    // 1. 根节点
    // 2. 根节点的右子树，并把原来的右子树移动作为新加入节点的左子树
    // 3. 右子树的右子树 ...
    // 故据此可以递推
    vector<TreeNode*> solution3(int n) {
      if (n == 0) return {};
      vector<TreeNode*> pre = {new TreeNode(1)}, cur;
      for (int i = 2; i <= n; ++i) {
        cur.clear();
        for (auto root : pre) {
          // 第一种，新加入的节点插入到根节点
          auto insert = new TreeNode(i);
          insert->left = root;
          cur.push_back(insert);
          // 遍历第二和第三种可能
          for (int j = 0; j < i - 1; ++j) {  // 最多有 i - 1 种可能
            auto root_copy = treeCopy(root);  // 复制当前的树
            auto right = root_copy;  // 要插入右子树的位置
            int k = 0;
            for (; k < j; k++) {
              if (!right) break;
              right = right->right;
            }
            if (!right) break;
            // 保存当前右子树，作为新插入的节点的左子树
            auto rightTree = right->right;
            insert = new TreeNode(i);
            right->right = insert;
            insert->left = rightTree;
            cur.push_back(root_copy);
          }
        }
        pre = cur;
      }
      return pre;
    }

    TreeNode* treeCopy(TreeNode* root) {
      if (!root) return root;
      return new TreeNode(root->val,treeCopy(root->left), treeCopy(root->right));;
    }

    // 动态规划思路2
    vector<TreeNode*> solution4(int n) {
      if (n == 0) return {};
      vector<vector<TreeNode*>> dp(n+1, vector<TreeNode*>(0));
      dp[0] = {nullptr};

      for (int i = 1; i <= n; ++i) { // 最外循环执行递推
        for (int root = 1; root <= i; ++root) {
          int left = root - 1;  // root 为根节点, left 是 root 左边的节点数
          int right = i - root;  // right 是 root 右边的节点数
          /*
            假设n为5，root是3，那么左边有2个节点，所以去dp[2]里面找，右边也有两个节点4,5。所以还去dp[2]里面找。
            因为只有dp[2]里面都是2个节点的数。他们的树的结构是一直的。但是dp[2]中的数值只有1和2，我们要的是4,5。
            我们不妨将1,2加上root，正好发现是4,5。
            所以得到结论，左子树的值直接找前面节点数一样的dp索引，右子树的值也找前面一样的dp索引,
            但是你需要加上root才能保证val是你需要的，所以右子树要重新创建，不然会破坏前面的树。
          */
          for (auto leftTree : dp[left]) {
            for (auto rightTree : dp[right]) {
              auto newRoot = new TreeNode(root);
              newRoot->left = leftTree;
              newRoot->right = clone(rightTree, root);  // 右子树创建一个新的树。
              dp[i].push_back(newRoot);  // 添加一种可能
            }
          }
        }
      }
      return dp[n];
    }

    TreeNode* clone(TreeNode* node, int offset) {
      if (!node) return nullptr;
      auto newNode = new TreeNode(node->val + offset);
      newNode->left = clone(node->left, offset);
      newNode->right = clone(node->right, offset);
      return newNode;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
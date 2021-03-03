//给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。 
//
// 例如： 
//给定二叉树 [3,9,20,null,null,15,7], 
//
//     3
//   / \
//  9  20
//    /  \
//   15   7
// 
//
// 返回锯齿形层次遍历如下： 
//
// [
//  [3],
//  [20,9],
//  [15,7]
//]
// 
// Related Topics 栈 树 广度优先搜索

#include "header.h"

namespace LeetCode103 {

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
      return solution2(root);
    }

    // bfs
    vector<vector<int>> solution1(TreeNode* root) {
      if (!root) return {};
      vector<vector<int>> ans;
      vector<int> line;
      deque<TreeNode*> q;
      q.push_back(root);
      int flag = 1;  // 1 从左到右

      while (!q.empty()) {
        int size = q.size();
        line.clear();
        for (int i = 0; i < size; ++i) {
          TreeNode* cur = q.front();
          q.pop_front();
          line.push_back(cur->val);
          if (cur->left) q.push_back(cur->left);
          if (cur->right) q.push_back(cur->right);
        }
        if (!flag) {  // 做一次翻转, 此处会有 n 次翻转的消耗
          reverse(line.begin(), line.end());
        }
        ans.push_back(line);
        flag = 1-flag;
      }

      return ans;
    }

    // 不做翻转的方法
    vector<vector<int>> solution2(TreeNode* root) {
      vector<vector<int>> ans;
      if (!root) return ans;

      int align = 1;  // 1 正序，0 逆序
      TreeNode *last = root, *nLast = nullptr;
      vector<int> line;
      deque<TreeNode*> q;
      q.push_back(root);

      while (!q.empty()) {
        if (align) {
          root = q.front();  // 正序的时候，从队列的头取
          q.pop_front();
          if (root->left) {
            // 正序的下一级是逆序，所以这里保证 nLast 是第一个 root->left 即可
            nLast = !nLast ? root->left : nLast;
            q.push_back(root->left);
          }
          if (root->right) {
            nLast = !nLast ? root->right : nLast;
            q.push_back(root->right);
          }
        } else {
          root = q.back();  // 逆序的时候，从队列的尾部取元素, 插入的时候，要插入到头
          q.pop_back();
          if (root->right) {  // 先计算 right
            nLast = !nLast ? root->right : nLast;
            q.push_front(root->right);
          }
          if (root->left) {
            nLast = !nLast ? root->left : nLast;
            q.push_front(root->left);
          }
        }
        line.push_back(root->val);
        // 如果到了最后一个元素
        if (root == last) {
          align = 1-align;
          last = nLast;
          nLast = nullptr;
          ans.push_back(line);
          line.clear();
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
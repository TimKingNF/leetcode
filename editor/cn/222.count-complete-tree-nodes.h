//给出一个完全二叉树，求出该树的节点个数。 
//
// 说明： 
//
// 完全二叉树的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为
//第 h 层，则该层包含 1~ 2h 个节点。 
//
// 示例: 
//
// 输入: 
//    1
//   / \
//  2   3
// / \  /
//4  5 6
//
//输出: 6 
// Related Topics 树 二分查找 
// 👍 311 👎 0

#include "header.h"

namespace LeetCode222 {

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
    int countNodes(TreeNode* root) {
      return solution3(root);
    }

    // bfs, O( N ), O( N )
    int solution1(TreeNode* root) {
      if (!root) return 0;
      queue<TreeNode*> q;
      q.push(root);

      int ans = 0;
      while (!q.empty()) {
        int size = q.size();
        ans += size;
        for (int i = 0; i < size; ++i) {
          TreeNode* cur = q.front();
          q.pop();
          if (cur->left) q.push(cur->left);
          if (cur->right) q.push(cur->right);
        }
      }
      return ans;
    }

    // 通过二分来确定最后一层的大小
    int solution2(TreeNode* root) {
      if (!root) return 0;
      int level = 0;
      TreeNode* node = root;
      while (node->left != nullptr) {
        level++;
        node= node->left;
      }
      // 如果最后一层有一个节点，或者有 2^level 个节点, 总节点范围在 [2^level, 2^(level+1)-1]
      // 在此范围内二分，判断节点是否存在
      int l = 1 << level, r = (1 << (level+1)) - 1;
      while (l < r) {
        int mid = l + (r - l + 1) / 2;
        if (exists(root, level, mid)) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      return l;
    }

    // 如何判断第 k 个节点是否存在呢？如果第 k 个节点位于第 h 层，则 k 的二进制表示包含 h+1 位，
    // 其中最高位是 11，其余各位从高到低表示从根节点到第 k 个节点的路径，0 表示移动到左子节点，
    // 1 表示移动到右子节点。通过位运算得到第 k 个节点对应的路径，判断该路径对应的节点是否存在，
    // 即可判断第 k 个节点是否存在。
    bool exists(TreeNode* root, int level, int k) {
      int bits = 1 << (level - 1);  // 用于计算每个边是左还是右
      TreeNode* node = root;
      while (node != nullptr && bits > 0) {
        if (!(bits & k)) {
          node = node->left;
        } else {
          node = node->right;
        }
        bits >>= 1;
      }
      return node != nullptr;
    }

    // O( h^2 )
    int solution3(TreeNode* root) {
      if (!root) return 0;
      return bs(root, 1, mostLeftLevel(root, 0));
    }

    // l 是当前深度，h 是总深度
    int bs(TreeNode* node, int l, int h) {
      if (l == h) return 1;  // 当前深度已经到最大深度，说明自己是叶子节点，返回自己即可
      // node 的右子树的最左节点深度达到了最大深度，说明整个左子树都是满二叉树
      if (mostLeftLevel(node->right, l) == h) {
        return (1 << (h-l)) + bs(node->right, l+1, h);
      } else {
        // 右子树是高度为 h-l-1 的满二叉树
        return (1 << (h-l-1)) + bs(node->left, l+1, h);
      }
    }

    // 求树的最左节点的深度
    int mostLeftLevel(TreeNode* node, int level) {
      while (node) {
        ++level;
        node = node->left;
      }
      return level;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
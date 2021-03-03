//检查子树。你有两棵非常大的二叉树：T1，有几万个节点；T2，有几万个节点。设计一个算法，判断 T2 是否为 T1 的子树。 
//
// 如果 T1 有这么一个节点 n，其子树与 T2 一模一样，则 T2 为 T1 的子树，也就是说，从节点 n 处把树砍断，得到的树与 T2 完全相同。 
//
// 示例1: 
//
//  输入：t1 = [1, 2, 3], t2 = [2]
// 输出：true
// 
//
// 示例2: 
//
//  输入：t1 = [1, null, 2, 4], t2 = [3, 2]
// 输出：false
// 
//
// 提示： 
//
// 
// 树的节点数目范围为[0, 20000]。 
// 
// Related Topics 树 
// 👍 28 👎 0

#include "header.h"

namespace LeetCode_04_10 {

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
    bool checkSubTree(TreeNode* t1, TreeNode* t2) {
      return solution1(t1, t2);
    }

    // 普通方法, 通过dfs判断 t2 是否是 t1 的子树，每个节点都要一次遍历比较
    // 复杂度 O( N*M )，对该题来说比较高
    bool solution1(TreeNode* t1, TreeNode* t2) {
      if (!t2) return true;
      if (!t1) return false;
      return isSameTree(t1, t2) || solution1(t1->left, t2) || solution1(t1->right, t2);
    }

   private:
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
      if (!t1 && !t2) return true;  // 两个都需要没节点才能匹配。不能是一个有一个没有
      if (!t1 || !t2 || t1->val != t2->val) return false;  // 两个都有的情况下不相同也不匹配
      return isSameTree(t1->left, t2->left) && isSameTree(t1->right, t2->right);
    }

   public:
    // 先将树前序遍历之后，判断 t2 的子串是否是 t1 的子串，如果是说明是子树
    // 使用 KMP 算法可以达到 O( N+M ) 的复杂度
    bool solution2(TreeNode* t1, TreeNode* t2) {
      auto t1_str = serialByPre(t1);
      auto t2_str = serialByPre(t2);
      return getIndexOf(t1_str, t2_str) != -1;
    }

   private:
    // 空节点需要用 # 来填充
    string serialByPre(TreeNode* node) {
      if (!node) return "#,";
      ostringstream oss;
      oss << node->val << ",";
      oss << serialByPre(node->left);
      oss << serialByPre(node->right);
      return oss.str();
    }

    // 使用 KMP 寻找 m 是否是 s 的子串
    int getIndexOf(string s, string m) {
      if (s.empty() || m.empty() || s.size() < m.size()) return -1;
      // 生成 next 数组
      vector<int> next(m.size());
      if (m.size() == 1) next[0] = 1;
      else {
        next[0] = -1;
        next[1] = 0;
        int pos = 2, cn = 0;
        while (pos < m.size()) {
          if (m[pos-1] == m[cn]) {
            next[pos++] = ++cn;
          } else if (cn > 0) {
            cn = next[cn];
          } else {
            next[pos++] = 0;
          }
        }
      }

      int si = 0, mi = 0;
      while (si < s.size() && mi < m.size()) {
        if (s[si] == m[mi]) {
          ++si;
          ++mi;
        } else if (next[mi] == -1) {
          ++si;
        } else {
          mi = next[mi];
        }
      }
      return mi == m.size() ? si - mi : -1;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
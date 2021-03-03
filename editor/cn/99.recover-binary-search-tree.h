//给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。 
//
// 进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗？ 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,3,null,null,2]
//输出：[3,1,null,null,2]
//解释：3 不能是 1 左孩子，因为 3 > 1 。交换 1 和 3 使二叉搜索树有效。
// 
//
// 示例 2： 
//
// 
//输入：root = [3,1,4,null,null,2]
//输出：[2,1,4,null,null,3]
//解释：2 不能在 3 的右子树中，因为 2 < 3 。交换 2 和 3 使二叉搜索树有效。 
//
// 
//
// 提示： 
//
// 
// 树上节点的数目在范围 [2, 1000] 内 
// -231 <= Node.val <= 231 - 1 
// 
// Related Topics 树 深度优先搜索 
// 👍 421 👎 0

#include "header.h"

namespace LeetCode99 {

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
    void recoverTree(TreeNode* root) {
      return solution2(root);
    }

    // 普通解法 O( N ), O( N )
    // 中序遍历的时候找到出现降序的两个节点即可
    void solution1(TreeNode* root) {
      if (!root) return;

      TreeNode *errOne = nullptr, *errTwo, *pre = nullptr;
      stack<TreeNode*> stk;

      while (!stk.empty() || root) {
        while (root) {
          stk.push(root);
          root = root->left;
        }
        root = stk.top();
        stk.pop();
        // 中序遍历，这里进行判断
        if (pre && pre->val > root->val) {  // 说明出现了降序
          errOne = !errOne ? pre : errOne;
          errTwo = root;  // 保留记录最后一次降序中较小的值
        }
        pre = root;
        root = root->right;
      }
      swap(errOne->val, errTwo->val);
    }

    // 进阶：使用常数空间, 时间上会多点开销
    // 需要用到 Mirror 遍历
    void solution2(TreeNode* root) {
      if (!root) return;

      TreeNode *errOne = nullptr, *errTwo;
      TreeNode *leftRight, *pre = nullptr;
      while (root) {
        leftRight = root->left;
        if (leftRight) {
          // 取左子树的最右节点
          while (leftRight->right && leftRight->right != root) {
            leftRight = leftRight->right;
          }
          if (!leftRight->right) {  // 最右节点的右指针还没有指向 root
            leftRight->right = root;
            root = root->left;  // 移动到下一层
            continue;
          } else {
            leftRight->right = nullptr;
          }
        }
        if (pre && pre->val > root->val) {
          errOne = !errOne ? pre : errOne;
          errTwo = root;
        }
        pre = root;
        root = root->right;
      }
      swap(errOne->val, errTwo->val);
    }

    // TODO：进阶，要在结构上交换两个节点，不能只是单纯交换值 (CIG 上的问题)
};
//leetcode submit region end(Prohibit modification and deletion)

}
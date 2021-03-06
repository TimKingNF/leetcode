//给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。 
//
// 假定 BST 有如下定义： 
//
// 
// 结点左子树中所含结点的值小于等于当前结点的值 
// 结点右子树中所含结点的值大于等于当前结点的值 
// 左子树和右子树都是二叉搜索树 
// 
//
// 例如： 
//给定 BST [1,null,2,2], 
//
//    1
//    \
//     2
//    /
//   2
// 
//
// 返回[2]. 
//
// 提示：如果众数超过1个，不需考虑输出顺序 
//
// 进阶：你可以不使用额外的空间吗？（假设由递归产生的隐式调用栈的开销不被计算在内） 
// Related Topics 树

#include "header.h"

namespace LeetCode501 {

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
    vector<int> findMode(TreeNode* root) {
      return solution1(root);
    }

    int base, count, maxCount;
    vector<int> ans;

    // 中序遍历的时候因为是连续的，所以可以采取这种方式
    void update(int x) {
      if (x == base) ++count;
      else {
        count = 1;
        base = x;
      }
      if (count == maxCount) {
        ans.push_back(base);
      } else if (count > maxCount) {
        ans = vector<int>{base};
        maxCount = count;
      }
    }

    // mirror 遍历, 没有栈的开销
    vector<int> solution1(TreeNode* root) {
      if (!root) return {};
      TreeNode* cur = root, *pre = nullptr;
      while (cur) {
        if (!cur->left) {  // 如果左子树为空，取右子树
          update(cur->val);
          cur = cur->right;
          continue;
        }
        pre = cur->left;
        while (pre->right && pre->right != cur) {  // 取左子树的最右节点
          pre = pre->right;
        }
        if (!pre->right) {  // 最右节点的右子树指回到 cur 节点, 继续往左子树遍历
          pre->right = cur;
          cur = cur->left;
        } else {  // 进行回撤
          pre->right = nullptr;
          update(cur->val);
          cur = cur->right;
        }
      }
      return ans;
    }

    // 使用递归遍历，中序遍历也是一样的
};
//leetcode submit region end(Prohibit modification and deletion)

}
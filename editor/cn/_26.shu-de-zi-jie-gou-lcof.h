//输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构) 
//
// B是A的子结构， 即 A中有出现和B相同的结构和节点值。 
//
// 例如: 
//给定的树 A: 
//
// 3 
// / \
// 4 5 
// / \
// 1 2 
//给定的树 B： 
//
// 4 
// / 
// 1 
//返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。 
//
// 示例 1： 
//
// 输入：A = [1,2,3], B = [3,1]
//输出：false
// 
//
// 示例 2： 
//
// 输入：A = [3,4,5,1,2], B = [4,1]
//输出：true 
//
// 限制： 
//
// 0 <= 节点个数 <= 10000 
// Related Topics 树

#include "header.h"

namespace LeetCode_26 {

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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
      if (A == nullptr || B == nullptr) return false;

      bool ans = false;
      if (A->val == B->val) {
        ans = isSubStructureCore(A, B);
      }
      if (!ans) {  // 尝试从左子树开始找
        ans = isSubStructure(A->left, B);
      }
      if (!ans) {  // 尝试从右子树开始找
        ans = isSubStructure(A->right, B);
      }
      return ans;
    }

    bool isSubStructureCore(TreeNode* A, TreeNode* B) {
      // 判断是否是子结构
      if (B == nullptr) return true;  // 找到B的节点为 nullptr 时说明已经匹配完毕
      if (A == nullptr) return false;

      if (A->val == B->val) {
        return isSubStructureCore(A->left, B->left) && isSubStructureCore(A->right, B->right);
      }
      return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
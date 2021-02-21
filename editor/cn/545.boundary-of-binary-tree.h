//二叉树的边界是按顺序包括 左边界 、叶节点 和 右边界 而 不包括重复的节点 。 
//
// 左边界 的定义是从根到 最左侧 节点的路径。右边界 的定义是从根到 最右侧 节点的路径。 
//
// 最左侧 节点的定义是：在左子树存在时总是优先访问，如果不存在左子树则访问右子树。重复以上操作，首先抵达的节点就是 最左侧 节点。 
//
// 最右侧 节点的定义方式相同，只是将左替换成右。 
//
// 注意，根节点可能是 最左侧 和/或 最右侧 的节点。 
//
// 给定一棵二叉树的根节点 root ，以 逆时针 顺序从根开始返回其 边界 。 
//
// 
//
// 示例 1： 
//
// 
//输入：root = [1,null,2,3,4]
//输出：[1,3,4,2]
//解释：
//左边界是 [1,2,3]
//右边界是 [1,2,4]
//叶节点是 [3,4]
//合并在一起得到 [1,2,3,4]，按逆时针排序得 [1,3,4,2]
// 
//
// 示例 2： 
//
// 
//输入：root = [1,2,3,4,5,6,null,null,null,7,8,9,10]
//输出：[1,2,4,7,8,9,10,6,3]
//解释：
//左边界是 [1,2,4]（根据定义，4 是最左侧结点）
//右边界是 [1,3,6,10]
//叶节点是 [4,7,8,9,10]
//合并在一起得到 [1,2,3,4,6,7,8,9,10]，按逆时针排序得 [1,2,4,7,8,9,10,6,3]
// 
//
// 
//
// 提示： 
//
// 
// 树中节点的数目在范围 [1, 104] 内 
// -1000 <= Node.val <= 1000 
// 
// Related Topics 树 
// 👍 61 👎 0

#include "header.h"

namespace LeetCode545 {

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
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
      return solution1(root);
    }

    vector<int> solution1(TreeNode* root) {
      vector<int> ans;
      dfs(root, true, true, &ans);
      return ans;
    }

    void dfs(TreeNode* node, bool leftBound, bool rightBound, vector<int>* ans) {
      if (!node) return;
      if (leftBound) {
        ans->push_back(node->val);
      } else if (!node->left && !node->right) {  // 叶子节点
        ans->push_back(node->val);
        return;
      }
      // 当前node 不是叶子节点
      // 先处理左子树
      // 在处理左子树时，右子树的判断条件变多了，起到剪枝的作用。处理右子树时反过来，原理和目的一致。
      dfs(node->left, leftBound, !leftBound && rightBound && !node->right, ans);
      dfs(node->right, !rightBound && leftBound && !node->left, rightBound, ans);

      // 加入右边界上的节点
      if (!leftBound && rightBound) ans->push_back(node->val);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
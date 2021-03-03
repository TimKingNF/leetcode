//给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该子树的大小。其中，最大指的是子树节点数最多的。 
//
// 二叉搜索树（BST）中的所有节点都具备以下属性： 
//
// 
// 
// 左子树的值小于其父（根）节点的值。 
// 
// 
// 右子树的值大于其父（根）节点的值。 
// 
// 
//
// 注意: 
//
// 
// 子树必须包含其所有后代。 
// 
//
// 进阶: 
//
// 
// 你能想出 O(n) 时间复杂度的解法吗？ 
// 
//
// 
//
// 示例 1： 
//
// 
//
// 
//输入：root = [10,5,15,1,8,null,7]
//输出：3
//解释：本例中最大的 BST 子树是高亮显示的子树。返回值是子树的大小，即 3 。 
//
// 示例 2： 
//
// 
//输入：root = [4,2,7,2,3,5,null,2,null,null,null,null,null,1]
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 树上节点数目的范围是 [0, 104] 
// -104 <= Node.val <= 104 
// 
// Related Topics 树 
// 👍 81 👎 0

#include "header.h"

namespace LeetCode333 {

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
    int largestBSTSubtree(TreeNode* root) {
      return solution1(root);
    }

    // 返回最大BST子树的根节点
    TreeNode* getLargestBSTSubtree(TreeNode* root) {
      vector<int> record;
      return postOrder(root, record);
    }

    int solution1(TreeNode* root) {
       vector<int> record(3);
       postOrder(root, record);
       return record[0];
    }

   private:
    TreeNode* postOrder(TreeNode* node, vector<int>& record) {
      if (!node) {
        record[0] = 0;  // 记录节点数
        record[1] = INT32_MAX;  // 记录 BST 树的最小值
        record[2] = INT32_MIN;  // 记录 BST 树的最大值
        return nullptr;
      }

      auto lBST = postOrder(node->left, record);
      int lSize = record[0], lMin = record[1], lMax = record[2];
      auto rBST = postOrder(node->right, record);
      int rSize = record[0], rMin = record[1], rMax = record[2];
      // 计算如果以此为节点的 子树是 BST 树
      if (node->left == lBST && node->right == rBST && lMax < node->val && rMin > node->val) {
        record[0] = lSize + rSize + 1;  // 左右子树都是 BST，且满足整个树也是 BST
        record[1] = min(lMin, node->val);
        record[2] = max(rMax, node->val);
        return node;
      }
      record[0] = max(lSize, rSize);
      // 说明出现了断层，也就无需再维护 record[1] record[2] 了
      // record[1] = lSize > rSize ? lMin : rMin;
      // record[2] = lSize > rSize ? lMax : rMax;
      return lSize > rSize ? lBST : rBST;  // 返回较大的 BST
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
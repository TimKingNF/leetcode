//返回与给定的前序和后序遍历匹配的任何二叉树。 
//
// pre 和 post 遍历中的值是不同的正整数。 
//
// 
//
// 示例： 
//
// 输入：pre = [1,2,4,5,3,6,7], post = [4,5,2,6,7,3,1]
//输出：[1,2,3,4,5,6,7]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= pre.length == post.length <= 30 
// pre[] 和 post[] 都是 1, 2, ..., pre.length 的排列 
// 每个输入保证至少有一个答案。如果有多个答案，可以返回其中一个。 
// 
// Related Topics 树 
// 👍 141 👎 0

#include "header.h"

namespace LeetCode889 {

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
      return solution1(pre, post);
    }

    // 想要通过前序和后续构造出二叉树，需要注意有如下性质
    // 每个节点除了叶子节点以外，都有左右孩子节点，这样的树才可以被重构出来
    TreeNode* solution1(vector<int>& pre, vector<int>& post) {
      if (pre.empty() || post.empty()) return nullptr;
      unordered_map<int, int> dict;
      for (int i = 0; i < post.size(); ++i) {
        dict.insert({post[i], i});
      }
      return prePost(pre, 0, pre.size()-1, post, 0, post.size()-1, dict);
    }

   private:
    TreeNode* prePost(vector<int>& pre, int preStart, int preEnd,
                      vector<int>& post, int postStart, int postEnd,
                      unordered_map<int, int>& dict) {
      if (preStart > preEnd || postStart > postEnd) return nullptr;

      TreeNode* root = new TreeNode(pre[preStart]);
      if (preStart == preEnd) return root;  // 说明就一个节点

      // 找左子树的头节点在 post 中的位置
      int leftCount = dict[pre[++preStart]];  // 这里 preStart 前移，指向 左子树的头结点
      // 关键在于计算正确的位置
      root->left = prePost(pre, preStart, preStart+leftCount-postStart,
                           post, postStart, leftCount, dict);
      root->right = prePost(pre, preStart+leftCount-postStart+1, preEnd,
                            post, leftCount+1, postEnd-1, dict);
      return root;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
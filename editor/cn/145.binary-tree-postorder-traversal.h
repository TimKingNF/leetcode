//给定一个二叉树，返回它的 后序 遍历。 
//
// 示例: 
//
// 输入: [1,null,2,3]  
//   1
//    \
//     2
//    /
//   3 
//
//输出: [3,2,1] 
//
// 进阶: 递归算法很简单，你可以通过迭代算法完成吗？ 
// Related Topics 栈 树

#include "header.h"

namespace LeetCode145 {

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
    vector<int> postorderTraversal(TreeNode* root) {
      return solution4(root);
    }

    // 递归
    vector<int> solution1(TreeNode* root) {
      vector<int> ans;

      function<void(TreeNode*)> postorder = [&](TreeNode* root) {
        if (!root) return;
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->val);
      };

      postorder(root);
      return ans;
    }

    // TODO: 迭代
    vector<int> solution2(TreeNode* root) {
      if (!root) return {};
      stack<TreeNode*> stk;
      TreeNode *cur, *last_visited;
      vector<int> ans;
      while (!stk.empty() || root) {
        if (root) {
          stk.push(root);
          root = root->left;
        } else {
          cur = stk.top();
          // root 节点的前驱节点就是其右子树节点, 所以判断不为 last_visited
          if (cur->right && cur->right != last_visited) {  // 存在右子树且未被访问
            root = cur->right;
          } else {
            // cur 的左右子树都被访问过
            ans.push_back(cur->val);
            last_visited = cur;
            stk.pop();
            root = nullptr;  // 置空root
          }
        }
      }
      return ans;
    }

    // 使用两个栈实现迭代
    vector<int> solution3(TreeNode* root) {
      vector<int> ans;
      if (!root) return ans;

      stack<TreeNode*> s1, s2;
      s1.push(root);
      while (!s1.empty()) {
        root = s1.top();
        s1.pop();
        s2.push(root);
        // 因为写入到 s2 的顺序，左子树在最上面，所以先写入 左子树到 s1
        if (root->left) s1.push(root->left);
        if (root->right) s1.push(root->right);
      }
      while (!s2.empty()) {
        ans.push_back(s2.top()->val);
        s2.pop();
      }
      return ans;
    }

    // 相对于 solution2 更简洁的写法
    vector<int> solution4(TreeNode* root) {
      vector<int> ans;
      if (!root) return ans;

      stack<TreeNode*> stk;
      stk.push(root);
      TreeNode *cur;  // 记录当前的节点
      while (!stk.empty()) {
        cur = stk.top();

        if (cur->left && cur->left != root && cur->right != root) {
          // 左右left right 都不是最后一个处理的节点，说明左子树尚未处理过
          stk.push(cur->left);
        } else if (cur->right && cur->right != root) {
          // 说明左子树被处理过了，cur->left == root
          // 处理右子树
          stk.push(cur->right);
        } else {
          // 左右子树都处理完毕，可以输出根节点
          ans.push_back(cur->val);
          stk.pop();
          root = cur;  // 记录最后一个处理的节点
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
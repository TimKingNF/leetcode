//给定一个 N 叉树，返回其节点值的前序遍历。 
//
// 例如，给定一个 3叉树 : 
//
// 
//
// 
//
// 
//
// 返回其前序遍历: [1,3,5,6,2,4]。 
//
// 
//
// 说明: 递归法很简单，你可以使用迭代法完成此题吗? Related Topics 树

#include "header.h"

namespace LeetCode589 {

class Node {
 public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) {
    val = _val;
  }

  Node(int _val, vector<Node*> _children) {
    val = _val;
    children = _children;
  }
};

//leetcode submit region begin(Prohibit modification and deletion)
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
      return solution2(root);
    }

    // dfs
    vector<int> solution1(Node* root) {
      vector<int> ans;
      function<void(Node*)> dfs = [&](Node* node) {
        if (!node) return;
        ans.push_back(node->val);
        for (auto v : node->children) dfs(v);
      };
      dfs(root);
      return ans;
    }

    // 迭代
    vector<int> solution2(Node* root) {
      if (!root) return {};
      vector<int> ans;
      stack<Node*> stk;
      stk.push(root);

      while (!stk.empty()) {
        Node* cur = stk.top();
        stk.pop();
        ans.push_back(cur->val);
        // 将childred 按逆序入栈, 则最后栈顶就是第一个元素
        for (int i = (int) cur->children.size() - 1; i >= 0; --i) {
          stk.push(cur->children[i]);
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
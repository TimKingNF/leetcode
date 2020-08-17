//给定一个 N 叉树，返回其节点值的后序遍历。 
//
// 例如，给定一个 3叉树 : 
//
// 
//
// 
//
// 
//
// 返回其后序遍历: [5,6,3,2,4,1]. 
//
// 
//
// 说明: 递归法很简单，你可以使用迭代法完成此题吗? Related Topics 树

#include "header.h"

namespace LeetCode590 {

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
    vector<int> postorder(Node* root) {
      return solution2(root);
    }

    vector<int> solution1(Node* root) {
      vector<int> ans;
      function<void(Node*)> dfs = [&](Node* node) {
        if (!node) return;
        for (auto v : node->children) dfs(v);
        ans.push_back(node->val);
      };
      dfs(root);
      return ans;
    }

    vector<int> solution2(Node* root) {
      if (!root) return {};
      vector<int> ans;
      stack<Node*> stk;
      stk.push(root);

      while (!stk.empty()) {
        Node* cur = stk.top();
        ans.push_back(cur->val);
        stk.pop();
        for (auto v : cur->children) stk.push(v);
      }
      reverse(ans.begin(), ans.end());  // 最后将遍历结果翻转
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
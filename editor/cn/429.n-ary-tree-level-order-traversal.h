//给定一个 N 叉树，返回其节点值的层序遍历。 (即从左到右，逐层遍历)。 
//
// 例如，给定一个 3叉树 : 
//
// 
//
// 
//
// 
//
// 返回其层序遍历: 
//
// [
//     [1],
//     [3,2,4],
//     [5,6]
//]
// 
//
// 
//
// 说明: 
//
// 
// 树的深度不会超过 1000。 
// 树的节点总数不会超过 5000。 
// Related Topics 树 广度优先搜索

#include "header.h"

namespace LeetCode429 {

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
    vector<vector<int>> levelOrder(Node* root) {
      return solution2(root);
    }

    // bfs
    vector<vector<int>> solution1(Node* root) {
      if (!root) return {};
      deque<Node*> q;
      q.push_back(root);

      vector<vector<int>> ans;
      vector<int> line;
      while (!q.empty()) {
        int size = q.size();
        line.clear();
        for (int i = 0; i < size; ++i) {
          Node* cur = q.front();
          q.pop_front();
          line.push_back(cur->val);
          for (auto v : cur->children) q.push_back(v);
        }
        ans.push_back(line);
      }
      return ans;
    }

    // dfs
    vector<vector<int>> solution2(Node* root) {
      if (!root) return {};
      vector<vector<int>> ans;
      function<void(Node*, int)> traverse_node = [&](Node* node, int level) {
        if (ans.size() == level) ans.emplace_back();  // 说明需要添加新的 level
        ans[level].push_back(node->val);
        for (auto v : node->children) traverse_node(v, level + 1);
      };
      traverse_node(root, 0);
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个 N 叉树，找到其最大深度。 
//
// 最大深度是指从根节点到最远叶子节点的最长路径上的节点总数。 
//
// 例如，给定一个 3叉树 : 
//
// 
//
// 
//
// 
//
// 我们应返回其最大深度，3。 
//
// 说明: 
//
// 
// 树的深度不会超过 1000。 
// 树的节点总不会超过 5000。 
// Related Topics 树 深度优先搜索 广度优先搜索

#include "header.h"

namespace LeetCode559 {

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
    int maxDepth(Node* root) {
      return solution2(root);
    }

    // 深度搜索
    int solution1(Node* root) {
      function<int(Node*)> dfs = [&](Node* node) {
        if (!node) return 0;
        int max_level = 0;
        for (auto v : node->children)
          max_level = max(max_level, dfs(v));
        return max_level + 1;
      };
      return dfs(root);
    }

    // 广度搜索
    int solution2(Node* root) {
      if (!root) return 0;
      deque<Node*> q;
      q.push_back(root);
      int ans = 0;

      while (!q.empty()) {
        int size = q.size();
        ans += 1;
        for (int i = 0; i < size; ++i) {
          Node* cur = q.front();
          q.pop_front();
          for (auto v : cur->children) q.push_back(v);
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
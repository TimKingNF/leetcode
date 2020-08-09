//数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。 
//
// 
//
// 示例： 
//
// 输入：n = 3
//输出：[
//       "((()))",
//       "(()())",
//       "(())()",
//       "()(())",
//       "()()()"
//     ]
// 
// Related Topics 字符串 回溯算法

#include "header.h"

namespace LeetCode22 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> generateParenthesis(int n) {
      return solution2(n);
    }

    // dfs
    vector<string> solution1(int n) {
      vector<string> ans;
      solution1core(n, n, "", ans);
      return ans;
    }

    void solution1core(int left, int right, string path, vector<string>& ans) {
      if (left == 0 && right == 0) ans.push_back(path);
      if (left > 0) solution1core(left - 1, right, path + '(', ans);
      if (right > left) solution1core(left, right - 1, path + ')', ans);
    }

    // bfs
    vector<string> solution2(int n) {
      struct item {
        int left;
        int right;
        string val;
      };
      vector<string> ans;
      deque<item> q;
      q.push_back({n, n, ""});
      while (!q.empty()) {
        item v = q.front();
        q.pop_front();
        if (v.left == 0 && v.right == 0) {
          ans.push_back(v.val);
          continue;
        }
        if (v.left > 0) q.push_back({v.left-1, v.right, v.val + '('});
        if (v.right > v.left) q.push_back({v.left, v.right-1, v.val + ')'});
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
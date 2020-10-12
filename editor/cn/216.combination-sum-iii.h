//找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。 
//
// 说明： 
//
// 
// 所有数字都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1: 
//
// 输入: k = 3, n = 7
//输出: [[1,2,4]]
// 
//
// 示例 2: 
//
// 输入: k = 3, n = 9
//输出: [[1,2,6], [1,3,5], [2,3,4]]
// 
// Related Topics 数组 回溯算法

#include "header.h"

namespace LeetCode216 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
      return solution1(k, n);
    }

    vector<vector<int>> solution1(int k, int n) {
      if (n <= 0) return {};
      vector<vector<int>> ans;
      vector<int> line;
      solution1core(n, k, 9, line, ans);
      return ans;
    }

    void solution1core(int n, int k, int idx, vector<int>& line, vector<vector<int>>& ans) {
      if (n == 0 && k == 0) {
        ans.push_back(line);
        return;
      }
      if (idx == 0 || k < 0) return;  // 到底了
      if (idx <= n) {
        line.push_back(idx);
        solution1core(n - idx, k-1, idx-1, line, ans);
        line.pop_back();
      }
      solution1core(n, k, idx-1, line, ans);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
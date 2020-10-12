//给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。 
//
// 示例: 
//
// 输入: n = 4, k = 2
//输出:
//[
//  [2,4],
//  [3,4],
//  [2,3],
//  [1,2],
//  [1,3],
//  [1,4],
//] 
// Related Topics 回溯算法

#include "header.h"

namespace LeetCode77 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      return solution2(n, k);
    }

    vector<vector<int>> solution1(int n, int k) {
      if (n <= 0) return {};
      vector<int> nums(n, 0);
      iota(nums.begin(), nums.end(), 1);  // 累加
      vector<vector<int>> ans;
      vector<int> path;
      for (int i = 0; i < n; ++i) {
        path.push_back(nums[i]);
        helper(nums, i, k-1, path, ans);
        path.pop_back();
      }
      return ans;
    }

    void helper(vector<int>& nums, int next, int k, vector<int>& path, vector<vector<int>>& ans) {
      if (k == 0) {
        ans.push_back(path);
        return;
      }
      for (int i = next + 1; i < nums.size(); ++i) {
        path.push_back(nums[i]);
        helper(nums, i, k-1, path, ans);
        path.pop_back();
      }
    }

    vector<vector<int>> solution2(int n, int k) {
      vector<vector<int>> ans;
      vector<int> path;
      solution2core(1, n, k, path, ans);
      return ans;
    }

    void solution2core(int cur, int n, int k, vector<int>& path, vector<vector<int>>& ans) {
      if (path.size() + (n - cur + 1) < k) return;  // 剩下的元素肯定无法满足 k 个元素
      if (path.size() == k) {
        ans.push_back(path);
        return;
      }
      // 考虑选择当前位置
      path.push_back(cur);
      solution2core(cur + 1, n, k, path, ans);
      path.pop_back();
      // 不选择当前位置
      solution2core(cur + 1, n , k, path, ans);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
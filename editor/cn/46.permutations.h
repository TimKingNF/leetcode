//给定一个 没有重复 数字的序列，返回其所有可能的全排列。 
//
// 示例: 
//
// 输入: [1,2,3]
//输出:
//[
//  [1,2,3],
//  [1,3,2],
//  [2,1,3],
//  [2,3,1],
//  [3,1,2],
//  [3,2,1]
//] 
// Related Topics 回溯算法

#include "header.h"

namespace LeetCode46 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      return solution2(nums);
    }

    // dfs
    vector<vector<int>> solution1(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<bool> used(nums.size(), false);
      vector<int> cur;
      solution1core(nums, cur, used, ans);
      return ans;
    }

    void solution1core(vector<int>& nums, vector<int>& cur,
                       vector<bool>& used, vector<vector<int>>& ans) {
      if (cur.size() == nums.size()) {
        ans.push_back(cur);
        return;
      }
      for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
          cur.push_back(nums[i]);
          used[i] = true;
          solution1core(nums, cur, used, ans);
          // 恢复状态
          used[i] = false;
          cur.pop_back();
        }
      }
    }

    // 交换法
    vector<vector<int>> solution2(vector<int>& nums) {
      vector<vector<int>> ans;
      solution2core(0, nums.size()-1, nums, ans);
      return ans;
    }

    void solution2core(int begin, int end, vector<int>& nums, vector<vector<int>>& ans) {
      if (begin == end) ans.push_back(nums);
      for (int i = begin; i <= end; ++i) {
        swap(nums[i], nums[begin]);
        solution2core(begin + 1, end, nums, ans);
        swap(nums[i], nums[begin]);
      }
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个可包含重复数字的序列，返回所有不重复的全排列。 
//
// 示例: 
//
// 输入: [1,1,2]
//输出:
//[
//  [1,1,2],
//  [1,2,1],
//  [2,1,1]
//] 
// Related Topics 回溯算法

#include "header.h"

namespace LeetCode47 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      return solution2(nums);
    }

    vector<vector<int>> solution1(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> cur;
      vector<bool> used(nums.size(), false);
      sort(nums.begin(), nums.end());
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
          if (i > 0 && nums[i] == nums[i-1] && used[i-1]) continue;
          cur.push_back(nums[i]);
          used[i] = true;
          solution1core(nums, cur, used, ans);
          used[i] = false;
          cur.pop_back();
        }
      }
    }

    vector<vector<int>> solution2(vector<int>& nums) {
      sort(nums.begin(), nums.end());
      int current_len = 0;
      vector<vector<int>> ans;
      function<void(void)> backtrack = [&]() {
        if (current_len == nums.size()) {
          ans.push_back(nums);
          return;
        }
        ++current_len;
        backtrack();
        --current_len;
        for (int i = 0; i < current_len; ++i) {
          if (nums[i] == nums[current_len]) break;
          swap(nums[i], nums[current_len]);
          ++current_len;
          backtrack();
          --current_len;
          swap(nums[i], nums[current_len]);
        }
      };
      backtrack();
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
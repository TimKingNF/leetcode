//给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。 
//
// 说明：解集不能包含重复的子集。 
//
// 示例: 
//
// 输入: nums = [1,2,3]
//输出:
//[
//  [3],
//  [1],
//  [2],
//  [1,2,3],
//  [1,3],
//  [2,3],
//  [1,2],
//  []
//] 
// Related Topics 位运算 数组 回溯算法

#include "header.h"

namespace LeetCode78 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      return solution2(nums);
    }

    // 回溯
    vector<vector<int>> solution1(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> cur;
      solution1core(nums, 0, cur, ans);
      return ans;
    }

    void solution1core(vector<int>& nums, int first, vector<int>& cur, vector<vector<int>>& ans) {
      ans.push_back(cur);
      for (int i = first; i < nums.size(); ++i) {
        cur.push_back(nums[i]);
        solution1core(nums, i+1, cur, ans);
        cur.pop_back();
      }
    }

    // 另一种回溯方式
    vector<vector<int>> solution2(vector<int>& nums) {
      vector<vector<int>> ans;
      vector<int> cur;
      solution2core(nums, 0, cur, ans);
      return ans;
    }

    void solution2core(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& ans) {
      if (i == nums.size()) {
        ans.push_back(cur);
        return;
      }
      // 分为取和不取两种情况
      solution2core(nums, i+1, cur, ans);  // 不取

      cur.push_back(nums[i]);
      solution2core(nums, i+1, cur, ans);
      cur.pop_back();  // 取
    }

    // 二进制，每个元素都可以选或不选，遍历二进制和所有可能即可
    vector<vector<int>> solution3(vector<int>& nums) {
      int n = nums.size();
      vector<vector<int>> ans;
      vector<int> line;
      for (int i = 0; i < (1 << n); ++i) {
        line.clear();
        for (int j = 0; j < n; ++j) {
          if ((i >> j) & 1) line.push_back(nums[j]);  // 对应选取的位的下标
        }
        ans.push_back(line);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
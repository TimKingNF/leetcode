//给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。 
//
// candidates 中的数字可以无限制重复被选取。 
//
// 说明： 
//
// 
// 所有数字（包括 target）都是正整数。 
// 解集不能包含重复的组合。 
// 
//
// 示例 1： 
//
// 输入：candidates = [2,3,6,7], target = 7,
//所求解集为：
//[
//  [7],
//  [2,2,3]
//]
// 
//
// 示例 2： 
//
// 输入：candidates = [2,3,5], target = 8,
//所求解集为：
//[
//  [2,2,2,2],
//  [2,3,3],
//  [3,5]
//] 
//
// 
//
// 提示： 
//
// 
// 1 <= candidates.length <= 30 
// 1 <= candidates[i] <= 200 
// candidate 中的每个元素都是独一无二的。 
// 1 <= target <= 500 
// 
// Related Topics 数组 回溯算法

#include "header.h"

namespace LeetCode39 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
      return solution1(candidates, target);
    }

    // 贪心法 + 回溯
    vector<vector<int>> solution1(vector<int>& candidates, int target) {
      sort(candidates.begin(), candidates.end());
      vector<vector<int>> ans;
      vector<int> line;
      solution1core(candidates, candidates.size()-1, target, line, ans);
      return ans;
    }

    void solution1core(vector<int>& candidates, int last, int target,
                       vector<int>& line, vector<vector<int>>& ans) {
      if (target == 0) {
        ans.push_back(line);
        return;
      }
      if (last == -1) return;  // 终止

      if (candidates[last] <= target) {
        line.push_back(candidates[last]);
        solution1core(candidates, last, target - candidates[last], line, ans);
        line.pop_back();
      }

      // 继续从前一个数开始考虑
      solution1core(candidates, last - 1, target, line, ans);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个整型数组, 你的任务是找到所有该数组的递增子序列，递增子序列的长度至少是2。 
//
// 示例: 
//
// 
//输入: [4, 6, 7, 7]
//输出: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7
//]] 
//
// 说明: 
//
// 
// 给定数组的长度不会超过15。 
// 数组中的整数范围是 [-100,100]。 
// 给定数组中可能包含重复数字，相等的数字应该被视为递增的一种情况。 
// 
// Related Topics 深度优先搜索

#include "header.h"

namespace LeetCode491 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  vector<vector<int>> findSubsequences(vector<int>& nums) {
    return solution2(nums);
  }

  // 普通 dfs 思路
  vector<vector<int>> solution1(vector<int>& nums) {
    if (nums.empty()) return {};
    vector<int> path;
    set<vector<int>> ans;
    dfs(nums, 0, path, ans);
    return vector<vector<int>>(ans.begin(), ans.end());
  }

  void dfs(vector<int>& nums, int idx, vector<int> path, set<vector<int>>& ans) {
    if (idx == nums.size()) {
      if (path.size() > 1) ans.insert(path);
      return;
    }

    // 加入数组和不加入数组两种情况
    dfs(nums, idx + 1, path, ans);  // 不加入数组

    if (path.empty() || path.back() <= nums[idx]) {
      path.push_back(nums[idx]);
      dfs(nums, idx + 1, path, ans);  // 加入数组
    }
  }

  // 借助 stack 和 预处理数组优化
  vector<vector<int>> solution2(vector<int>& nums){
    // 预处理数组，用于记录每个下标对应的元素，在其之前是否有相同的元素，如果有则记最大下标
    // 也就是 pre[i] 即 nums[i] 上一次出现的位置
    int pre[15];  // 数组长度不超过15
    for (int i = 0; i < nums.size(); ++i) {
      pre[i] = -1;
      for (int j = i-1; j >= 0; --j) {
        if (nums[j] == nums[i]) { pre[i] = j; break; }
      }
    }
    vector<vector<int>> ans;
    vector<int> stack;
    solution2core(nums, pre, -1, 0, stack, ans);
    return ans;
  }

  bool is_first(const vector<int>& nums, int* pre, int last, int pos) {
    return !(last < pre[pos] && pre[pos] < pos);  // pre[pos] 在 [last+1, pos) 之间
  }

  // last 用于记录 stack 中最后一个元素值的下标
  void solution2core(const vector<int>& nums, int* pre, int last, int pos,
                     vector<int>& stack, vector<vector<int>>& ans) {
    if (nums.size() == pos) return;  // 到达末尾
    // 检查 nums[pos] 是否符合要求
    if ((stack.empty() || nums[pos] >= stack.back()) && is_first(nums, pre, last, pos)) {
      stack.push_back(nums[pos]);
      if (stack.size() >= 2) { ans.push_back(stack); };
      solution2core(nums, pre, pos, pos+1, stack, ans);  // 继续处理下一个
      stack.pop_back();  // 将当前放入的吐出来，撤销状态
    }
    solution2core(nums, pre, last, pos+1, stack, ans);
  }

};
//leetcode submit region end(Prohibit modification and deletion)

}
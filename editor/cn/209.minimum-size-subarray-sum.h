//给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回
// 0。 
//
// 
//
// 示例： 
//
// 输入：s = 7, nums = [2,3,1,2,4,3]
//输出：2
//解释：子数组 [4,3] 是该条件下的长度最小的子数组。
// 
//
// 
//
// 进阶： 
//
// 
// 如果你已经完成了 O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。 
// 
// Related Topics 数组 双指针 二分查找

#include "header.h"

namespace LeetCode209 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
      return solution2(s, nums);
    }

    // O(n2)
    int solution1(int s, vector<int>& nums) {
      if (nums.empty()) return 0;
      int ans = INT_MAX, n = nums.size();
      int dp[n];  // 记录从j到当前下标的和
      for (int i = 0; i < n; ++i) dp[i] = 0;

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          dp[j] += nums[i];
          if (dp[j] >= s) ans = min(ans, i - j + 1);
        }
      }
      return ans == INT_MAX ? 0 : ans;
    }

    // TODO：滑动窗口
    int solution2(int s, vector<int>& nums) {
      if (nums.empty()) return 0;
      int n = nums.size();
      int ans = INT_MAX;
      int start = 0, end = 0, sum = 0;
      while (end < n) {
        sum += nums[end];
        while (sum >= s) {
          ans = min(ans, end - start + 1);
          sum -= nums[start];
          ++start;
        }
        ++end;
      }
      return ans == INT_MAX ? 0 : ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
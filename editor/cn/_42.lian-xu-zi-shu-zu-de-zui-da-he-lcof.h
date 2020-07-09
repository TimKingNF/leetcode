//输入一个整型数组，数组里有正数也有负数。数组中的一个或连续多个整数组成一个子数组。求所有子数组的和的最大值。 
//
// 要求时间复杂度为O(n)。 
//
// 
//
// 示例1: 
//
// 输入: nums = [-2,1,-3,4,-1,2,1,-5,4]
//输出: 6
//解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。 
//
// 
//
// 提示： 
//
// 
// 1 <= arr.length <= 10^5 
// -100 <= arr[i] <= 100 
// 
//
// 注意：本题与主站 53 题相同：https://leetcode-cn.com/problems/maximum-subarray/ 
//
// 
// Related Topics 分治算法 动态规划

#include "header.h"

namespace LeetCode_42 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      return solution1(nums);
    }

    // dp O(N)
    int solution1(vector<int>& nums) {
      int dp[2];
      dp[0] = nums[0];

      int x, y, ans = dp[0];
      // 定义dp的递推方程为，包括本数在内的最大连续子数组之和
      for (int i = 1; i < nums.size(); ++i) {
        x = i % 2;
        y = (i-1) % 2;
        dp[x] = max(nums[i], dp[y] + nums[i]);  // 要么就自己一个元素，要么就由前一个加本元素
        ans = max(ans, dp[x]);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
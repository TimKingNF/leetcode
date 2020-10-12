//给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。 
//
// 
//
// 示例 1: 
//
// 输入: [2,3,-2,4]
//输出: 6
//解释: 子数组 [2,3] 有最大乘积 6。
// 
//
// 示例 2: 
//
// 输入: [-2,0,-1]
//输出: 0
//解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。 
// Related Topics 数组 动态规划

#include "header.h"

namespace LeetCode152 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
      return solution2(nums);
    }

    // O(n^2)
    int solution1(vector<int>& nums) {
      int res = INT32_MIN;
      for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
          res = max(accumulate(nums.begin() + i, nums.begin() + j + 1,
            1,  // 累加器的初值
            multiplies<>()), res);
        }
      }
      return res;
    }

    // O(n)
    int solution2(vector<int>& nums) {
      if (nums.empty()) return 0;
      int max_i = 0, minus_max_i = 1;
      // 构建dp数组，一维表示第n, n-1项
      // 二维 0: max 1: minus_max
      int dp[2][2];
      int res = nums[0];
      dp[0][max_i] = nums[0];
      dp[0][minus_max_i] = nums[0];

      int x, y;  // x 表示第n项， y 表示第n-1项
      vector<int> arr;
      for (int i = 1; i < nums.size(); ++i) {
        x = i % 2;
        y = (i-1) % 2;
        arr = {
          dp[y][max_i] * nums[i],
          dp[y][minus_max_i] * nums[i],
          nums[i]};
        dp[x][max_i] = *max_element(arr.begin(), arr.end());
        dp[x][minus_max_i] = *min_element(arr.begin(), arr.end());
        res = max(dp[x][max_i], res);
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。 
//
// 注意: 
//
// 
// 每个数组中的元素不会超过 100 
// 数组的大小不会超过 200 
// 
//
// 示例 1: 
//
// 输入: [1, 5, 11, 5]
//
//输出: true
//
//解释: 数组可以分割成 [1, 5, 5] 和 [11].
// 
//
// 
//
// 示例 2: 
//
// 输入: [1, 2, 3, 5]
//
//输出: false
//
//解释: 数组不能分割成两个元素和相等的子集.
// 
//
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode416 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
      return solution1(nums);
    }

    // dp
    // O( N*C ) C 为元素和的一半，即target
    bool solution1(vector<int>& nums) {
      // 设 x, y 为其中两个子集，则有 x = y, x + y = sum
      // 推导可得 x = sum / 2
      int sum = 0;
      for (int num : nums) sum += num;
      if (sum & 1) return false;  // 如果和为奇数，说明 sum/2 为含小数的数，即不存在 和为target 的集合
      int target = sum / 2;

      // 问题转为，从 vector 中取一部分元素和为 target
      bool dp[target+1];
      fill(dp, dp+target+1, false);
      dp[0] = true;

      for (int i = 0; i < nums.size(); ++i) {
        for (int j = target; j >= 0; --j) {
          if (j - nums[i] >=0) {  // 可以装入该物品
            dp[j] = dp[j] || dp[j-nums[i]];
          }
        }
      }
      return dp[target];
    }

    // 也可以用回溯法来解本题
};
//leetcode submit region end(Prohibit modification and deletion)

}
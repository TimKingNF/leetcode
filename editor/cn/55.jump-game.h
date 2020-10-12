//给定一个非负整数数组，你最初位于数组的第一个位置。 
//
// 数组中的每个元素代表你在该位置可以跳跃的最大长度。 
//
// 判断你是否能够到达最后一个位置。 
//
// 示例 1: 
//
// 输入: [2,3,1,1,4]
//输出: true
//解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
// 
//
// 示例 2: 
//
// 输入: [3,2,1,0,4]
//输出: false
//解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置。
// 
// Related Topics 贪心算法 数组

#include "header.h"

namespace LeetCode55 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canJump(vector<int>& nums) {
      return solution2(nums);
    }

    // dp
    bool solution1(vector<int>& nums) {
      int n = nums.size();
      int dp[n];
      fill(dp, dp+n, false);
      dp[0] = true;

      for (int i = 0; i < n; ++i) {
        if (!dp[i]) continue;  // 该位置不可达，跳过
        for (int step = 0; step <= nums[i]; ++step) {
          if (i + step < n) dp[i+step] = true;  // 可以跳到 i + step 阶
        }
      }
      return dp[n-1];
    }

    // 贪心
    // 核心思路是，如果第一位置可达，那么说明其左侧的所有位置都可达
    bool solution2(vector<int>& nums) {
      int n = nums.size(), k = 0;
      for (int i = 0; i <= k; ++i) {
        k = max(k, i + nums[i]);  // 尝试不断更新能到达的最远距离
        if (k >= n-1) return true;  // 如果 k 超过 n-1, 则说明可到达最后一个位置
      }
      return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个非负整数数组，a1, a2, ..., an, 和一个目标数，S。现在你有两个符号 + 和 -。对于数组中的任意一个整数，你都可以从 + 或 -中选
//择一个符号添加在前面。 
//
// 返回可以使最终数组和为目标数 S 的所有添加符号的方法数。 
//
// 
//
// 示例： 
//
// 输入：nums: [1, 1, 1, 1, 1], S: 3
//输出：5
//解释：
//
//-1+1+1+1+1 = 3
//+1-1+1+1+1 = 3
//+1+1-1+1+1 = 3
//+1+1+1-1+1 = 3
//+1+1+1+1-1 = 3
//
//一共有5种方法让最终目标和为3。
// 
//
// 
//
// 提示： 
//
// 
// 数组非空，且长度不会超过 20 。 
// 初始的数组的和不会超过 1000 。 
// 保证返回的最终结果能被 32 位整数存下。 
// 
// Related Topics 深度优先搜索 动态规划

#include "header.h"

namespace LeetCode494 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
      return solution2(nums, S);
    }

    // dfs
    int solution1(vector<int>& nums, int S) {
      int ans = 0;
      dfs(nums, S, 0, 0, ans);
      return ans;
    }

    void dfs(vector<int>& nums, int S, int sum, int i, int& count) {
      if (i == nums.size()) {
        if (sum == S) ++count;
        return;
      }
      dfs(nums, S, sum + nums[i], i + 1, count);
      dfs(nums, S, sum - nums[i], i + 1, count);
    }

    // 动态规划 + 空间优化
    // O(N * nums.length) O(nums.length)
    int solution2(vector<int>& nums, int S) {
      vector<int> dp(2001, 0);  // 元素和最多不超过1000
      dp[nums[0] + 1000] = 1;
      dp[-nums[0] + 1000] += 1;  // 防止 nums[0] 为 0
      for (int i = 1; i < nums.size(); ++i) {
        vector<int> next(2001, 0);
        for (int sum = -1000; sum <= 1000; ++sum) {  // 遍历所有不为0的可能性，计算下一步的次数
          if (dp[sum + 1000] > 0) {
            next[sum + nums[i] + 1000] += dp[sum + 1000];
            next[sum - nums[i] + 1000] += dp[sum + 1000];
          }
        }
        dp = next;
      }
      return S > 1000 ? 0 : dp[S+1000];
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
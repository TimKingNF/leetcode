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
      return solution3(nums, S);
    }

    // dfs
    // O( 2^N )
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
      // dp 表示 当前和 +1000 ，共有多少种方法数
      vector<int> dp(2001, 0);  // 元素和最多不超过1000，所以 S 只能在 -1000 到 1000 之间
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

    // 转化为 01 背包问题
    // 设 x 为所有取 + 的 数的和, y 为所有取 - 的数的和（注意是正数之和）
    // z 为 nums 所有数之和
    // 则有 x - y = S, x = S + y, 推导可得 2x = S + y + x  = S + z
    // x = (S+z)/2
    int solution3(vector<int>& nums, int S) {
      int z = 0;
      for (int n : nums) z += n;  // 求得 z

      if ((z + S) & 1) return 0;  // x=(S+z)/2，x必为整数，所以 S+z 是奇数的话无解
      if (S > z) return 0;  // S 不可能大于 z，所以也是无解

      // 已知有若干个正数之和为 x，转化为背包问题
      // 给定一个数组和一个容量为x的背包，求有多少种方式让背包装满。
      int x = (z + S) / 2;
      vector<int> dp(x+1, 0);
      dp[0] = 1;  // 只有一种就是什么都不装
      for (int n : nums) {
        // 遍历从 x 到 n 的各种情况，累加所有可能的方式
        // 因为要借用上一轮 dp 的结果，所以从后往前遍历
        for (int i = x; i >= n; --i) {
          dp[i] += dp[i - n];
        }
      }
      return dp[x];
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
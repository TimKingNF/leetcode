//给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回
// -1。 
//
// 
//
// 示例 1: 
//
// 输入: coins = [1, 2, 5], amount = 11
//输出: 3 
//解释: 11 = 5 + 5 + 1 
//
// 示例 2: 
//
// 输入: coins = [2], amount = 3
//输出: -1 
//
// 
//
// 说明: 
//你可以认为每种硬币的数量是无限的。 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode322 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      return solution2(coins, amount);
    }

    // DP, amount 可能会占据较大空间, 用数组长度可能溢出
    int solution1(vector<int>& coins, int amount) {
      if (coins.empty()) return 0;
      // 最多 amount 个 1元，所以 amount+1 就类似于无限大
      int MAX = amount+1;
      unordered_map<int, int> dp;
      dp[0] = 0;
      for (int i = 1; i <= amount; ++i) {
        int min_cnt = MAX;
        for (int coin : coins) {
          if (i < coin) continue;
          min_cnt = min(min_cnt, dp[i-coin] + 1);
        }
        dp[i] = min_cnt;
      }
      return dp[amount] == MAX ? -1 : dp[amount];
    }

    // dfs + 剪枝
    int solution2(vector<int>& coins, int amount) {
      if (amount == 0 || coins.empty()) return 0;
      sort(coins.rbegin(), coins.rend());  // 从大到小排序
      int ans = amount + 1;
      solution2core(coins, amount, 0, 0, ans);
      return ans == amount + 1 ? -1 : ans;
    }

    // idx 记录当前使用的面值
    // count 记录当前累计的硬币数量
    // amount 剩余金额
    void solution2core(vector<int>& coins, int amount, int idx, int count, int& ans) {
      // 剩余金额为 0，比较硬币数
      if (amount == 0) {
        ans = min(ans, count);
        return;
      }
      if (idx == coins.size()) return;  // 没有可用面值了

      // idx 使用当前最大面值，然后遍历从 k 0->amount/coins[idx] 的各种情况
      for (int k = amount / coins[idx]; k >= 0 && k + count < ans; --k)
        solution2core(coins, amount-coins[idx]*k, idx+1, count+k, ans);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
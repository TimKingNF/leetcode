//给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。 
//
// 你可以无限次地完成交易，但是你每笔交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。 
//
// 返回获得利润的最大值。 
//
// 注意：这里的一笔交易指买入持有并卖出股票的整个过程，每笔交易你只需要为支付一次手续费。 
//
// 示例 1: 
//
// 输入: prices = [1, 3, 2, 8, 4, 9], fee = 2
//输出: 8
//解释: 能够达到的最大利润:  
//在此处买入 prices[0] = 1
//在此处卖出 prices[3] = 8
//在此处买入 prices[4] = 4
//在此处卖出 prices[5] = 9
//总利润: ((8 - 1) - 2) + ((9 - 4) - 2) = 8.
//
// 注意: 
//
// 
// 0 < prices.length <= 50000. 
// 0 < prices[i] < 50000. 
// 0 <= fee < 50000. 
// 
// Related Topics 贪心算法 数组 动态规划 
// 👍 372 👎 0

#include "header.h"

namespace LeetCode714 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
      return solution1(prices, fee);
    }

    // DP
    int solution1(vector<int>& prices, int fee) {
      int dp[2][2];
      memset(dp, 0, sizeof(int) * 4);
      dp[0][1] = -prices[0];  // 买入
      dp[0][0] = 0;

      int x, y, ans = 0;
      for (int i = 1; i < prices.size(); ++i) {
        x = i % 2;
        y = (i-1) % 2;

        // 持有的情况下卖出 / 保持没有买入
        dp[x][0] = max(dp[y][0], dp[y][1] + prices[i] - fee);
        // 没有持有的情况下买入 / 保持没有卖出
        dp[x][1] = max(dp[y][1], dp[y][0] - prices[i]);
        ans = max(max(dp[x][0], dp[x][1]), ans);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
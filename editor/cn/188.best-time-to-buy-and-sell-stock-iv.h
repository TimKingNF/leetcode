//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。 
//
// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 示例 1: 
//
// 输入: [2,4,1], k = 2
//输出: 2
//解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
// 
//
// 示例 2: 
//
// 输入: [3,2,6,5,0,3], k = 2
//输出: 7
//解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6) 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。
//     随后，在第 5 天 (股票价格 = 0) 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 = 3 
//。
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode188 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
      if (prices.empty() || k == 0) return 0;
      int len = prices.size();
      int res = 0;

      if (k > len) {  // 等同与无限次交易，退化为线性计算
        for (int i = 0; i < len - 1; ++i) {
          if (prices[i] < prices[i+1]) {
            res += prices[i+1] - prices[i];
          }
        }
        return res;
      }

      // 有限次交易，use dp, O(kn)
      int x, y;
      int have_not = 0, has = 1;  // 是否持有股票
      int max_profit[2][k+1][2];  // 第一项表示天，第二项表示第几次卖出，第三项表示是否持有股票

      // 构造初值
      for (int j = 0; j <= k; ++j) {
        max_profit[0][j][has] = -prices[0];  // 第一天购入股票
        max_profit[0][j][have_not] = 0;
      }

      vector<int> arr;
      for (int i = 1; i < prices.size(); ++i) {
        x = i % 2;
        y = (i-1) % 2;
        for (int j = 0; j <= k; ++j) {
          max_profit[x][j][have_not] = max(max_profit[y][j][have_not],
                                           j == 0 ? INT32_MIN : max_profit[y][j-1][has] + prices[i]);  // 处理一下边界值
          max_profit[x][j][has] = max(max_profit[y][j][has], max_profit[y][j][have_not] - prices[i]);
          arr = {max_profit[x][j][have_not], max_profit[x][j][has], res};
          res = *max_element(arr.begin(), arr.end());
        }
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
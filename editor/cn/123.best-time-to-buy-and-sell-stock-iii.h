//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。 
//
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。 
//
// 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。 
//
// 示例 1: 
//
// 输入: [3,3,5,0,0,3,1,4]
//输出: 6
//解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
//     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。 
//
// 示例 2: 
//
// 输入: [1,2,3,4,5]
//输出: 4
//解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
//     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
//     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。
// 
//
// 示例 3: 
//
// 输入: [7,6,4,3,1] 
//输出: 0 
//解释: 在这个情况下, 没有交易完成, 所以最大利润为 0。 
// Related Topics 数组 动态规划

#include "header.h"

namespace LeetCode123 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      return solution1(prices);
    }

    // O(kn) = O(n) use dp
    int solution1(vector<int>& prices) {
      if (prices.empty()) return 0;

      int x, y, res = 0, k = 2;
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
            j == 0 ? INT_MIN : max_profit[y][j-1][has] + prices[i]);  // 处理一下边界值
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
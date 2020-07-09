//假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？ 
//
// 
//
// 示例 1: 
//
// 输入: [7,1,5,3,6,4]
//输出: 5
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
// 
//
// 示例 2: 
//
// 输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。 
//
// 
//
// 限制： 
//
// 0 <= 数组长度 <= 10^5 
//
// 
//
// 注意：本题与主站 121 题相同：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-s
//tock/ 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode_63 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      return solution3(prices);
    }

    // 只能买卖一次
    int solution1(vector<int>& prices) {
      if (prices.empty()) return 0;
      int dp[2][2][2];  // 第一维表示天，第二维表示是否持有, 第三维表示买卖了多少次, 买入就算一次
      int x, y, has = 1, none = 0, max_profit = 0, buy = 1;
      dp[0][has][buy] = -prices[0];
      dp[0][none][none] = 0;
      dp[0][none][buy] = 0;  // 占位

      for (int i = 1; i < prices.size(); ++i) {
        x = i % 1;
        y = (i-1) % 1;
        dp[x][has][buy] = max(dp[y][has][buy], dp[y][none][none] - prices[i]);  // 昨天持有，或者买
        dp[x][none][buy] = max(dp[y][none][buy], dp[y][has][buy] + prices[i]);  // 昨天不持有,但已经卖出， 或者卖
        dp[x][none][none] = dp[y][none][none];  // 昨天没买，今天也没买
        max_profit = max(max_profit, max(dp[x][has][buy], dp[x][none][buy]));
      }
      return max_profit;
    }

    int solution2(vector<int>& prices) {
      if (prices.empty()) return 0;
      vector<int> tmp;
      tmp.push_back(prices[0]);

      int max_profit = 0;
      for (int i = 1; i < prices.size(); ++i) {
        while (!tmp.empty() && tmp.back() > prices[i])
          tmp.pop_back();
        tmp.push_back(prices[i]);
        max_profit = max(max_profit, tmp.back() - tmp.front());
      }
      return max_profit;
    }

    int solution3(vector<int>& prices) {
      if (prices.size() < 2) return 0;
      int min_price = prices[0];
      int max_diff = prices[1] - min_price;
      for (int i = 2; i < prices.size(); ++i) {
        if (prices[i - 1] < min_price)
          min_price = prices[i - 1];  // 记录一个最低价格
        max_diff = max(max_diff, prices[i] - min_price);
      }
      return max_diff < 0 ? 0 : max_diff;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
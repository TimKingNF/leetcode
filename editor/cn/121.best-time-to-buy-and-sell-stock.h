//给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。 
//
// 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。 
//
// 注意：你不能在买入股票前卖出股票。 
//
// 
//
// 示例 1: 
//
// 输入: [7,1,5,3,6,4]
//输出: 5
//解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
//     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
// 
//
// 示例 2: 
//
// 输入: [7,6,4,3,1]
//输出: 0
//解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
// 
// Related Topics 数组 动态规划

#include "header.h"

namespace LeetCode121 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
      return solution3(prices);
    }

    // O(n)
    int solution1(vector<int>& prices) {
      if (prices.empty()) return 0;
      int min_price = prices[0], max_profit = 0;
      for (int i = 1; i < prices.size(); ++i) {
        min_price = min(min_price, prices[i]);
        max_profit = max(prices[i] - min_price, max_profit);
      }
      return max_profit;
    }

    // O(n) use dp
    int solution2(vector<int>& prices) {
      if (prices.empty()) return 0;

      int len = prices.size();
      int x, y, res = 0, has = 1, have_not = 0;
      int max_profit[2][2][2];  // 第一维表示天，第二维表示手上是否持有股票, 第三维表示第n次交易(只要买入，就算一次交易)
      max_profit[0][have_not][0] = 0;  // 第一天，手上不持有股票，初值为0, 且没有操作，故操作次数算0
      max_profit[0][has][1] = -prices[0];  // 第一天，手上持有股票，故利润为负值
      max_profit[0][have_not][1] = 0;  // 这种情况实际不可能出现

      vector<int> arr;
      for (int i = 1; i < len; ++i) {
        x = i % 2;
        y = (i-1) % 2;
        max_profit[x][have_not][0] = max_profit[y][have_not][0];
        max_profit[x][has][1] = max(max_profit[y][has][1], max_profit[y][have_not][0] - prices[i]);
        max_profit[x][have_not][1] = max(max_profit[y][have_not][1], max_profit[y][has][1] + prices[i]);
        arr = {max_profit[x][have_not][0], max_profit[x][has][1], max_profit[x][have_not][1], res};
        res = *max_element(arr.begin(), arr.end());
      }
      return res;
    }

    // O(n)
    int solution3(vector<int>& prices) {
      if (prices.empty()) return 0;

      int res = 0;
      vector<int> v;
      v.emplace_back(prices[0]);
      for (int i = 1; i < prices.size(); ++i) {
        while (!v.empty() && v.back() > prices[i]) {
          v.pop_back();
        }
        v.emplace_back(prices[i]);
        res = max(res, v.back() - v.front());
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
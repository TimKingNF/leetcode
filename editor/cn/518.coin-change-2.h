//给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。 
//
// 
//
// 
// 
//
// 示例 1: 
//
// 输入: amount = 5, coins = [1, 2, 5]
//输出: 4
//解释: 有四种方式可以凑成总金额:
//5=5
//5=2+2+1
//5=2+1+1+1
//5=1+1+1+1+1
// 
//
// 示例 2: 
//
// 输入: amount = 3, coins = [2]
//输出: 0
//解释: 只用面额2的硬币不能凑成总金额3。
// 
//
// 示例 3: 
//
// 输入: amount = 10, coins = [10] 
//输出: 1
// 
//
// 
//
// 注意: 
//
// 你可以假设： 
//
// 
// 0 <= amount (总金额) <= 5000 
// 1 <= coin (硬币面额) <= 5000 
// 硬币种类不超过 500 种 
// 结果符合 32 位符号整数 
// 
//

#include "header.h"

namespace LeetCode518 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int change(int amount, vector<int>& coins) {
      return solution1(amount, coins);
    }

    int solution1(int amount, vector<int>& coins) {
      int dp[amount+1];
      fill(dp, dp+amount+1, 0);
      dp[0] = 1;
      for (int coin : coins) {
        for (int i = 1; i <= amount; ++i) {
          if (i - coin >= 0 ) dp[i] += dp[i-coin];
        }
      }
      return dp[amount];
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
//编写一个程序，找出第 n 个丑数。 
//
// 丑数就是质因数只包含 2, 3, 5 的正整数。 
//
// 示例: 
//
// 输入: n = 10
//输出: 12
//解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。 
//
// 说明: 
//
// 
// 1 是丑数。 
// n 不超过1690。 
// 
// Related Topics 堆 数学 动态规划

#include "header.h"

namespace LeetCode264 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
      return solution1(n);
    }

    int solution1(int n) {
      int dp[n];
      dp[0] = 1;
      int a = 0, b = 0, c = 0;
      for (int i = 1; i < n; ++i) {
        dp[i] = min(min(dp[a] * 2, dp[b] * 3), dp[c] * 5);
        if (dp[i] == dp[a] * 2) ++a;
        if (dp[i] == dp[b] * 3) ++b;
        if (dp[i] == dp[c] * 5) ++c;
      }
      return dp[n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
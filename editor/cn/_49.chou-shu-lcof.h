//我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。 
//
// 
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
//
// 注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/ 
// Related Topics 数学

#include "header.h"

namespace LeetCode_49 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int nthUglyNumber(int n) {
      return solution1(n);
    }

    // 使用 DP, 下一个丑数必为 小于 i-1 的数 *2, *3, *5 之间的最小值
    // 使用三个指针分别记录 需要*2, *3, *5 的数， 当符合丑数数，指针向前移动
    int solution1(int n) {
      int dp[n];
      dp[0] = 1;

      int a = 0, b = 0, c = 0;  // a, b, c 分别指向对应 2, 3, 5 的数的指针
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
//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m-1] 。
//请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18
//。 
//
// 示例 1： 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36 
//
// 提示： 
//
// 
// 2 <= n <= 58 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
// Related Topics 数学 动态规划

#include "header.h"

namespace LeetCode_14_I {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cuttingRope(int n) {
      return solution2(n);
    }

    // DP: O(N), 空间 O(N+1)
    int solution1(int n) {
      if (n < 2) return 0;  // 不满足n>1的条件
      if (n == 2) return 1;
      if (n == 3) return 2;

      int dp[n+1];  // 存储最优解, 包括n
      // 构造初值，初值用于参与计算
      dp[0] = 0;
      dp[1] = 1;
      dp[2] = 2;
      dp[3] = 3;
      int max_val;

      for (int i = 4; i <= n; ++i) {
        max_val = 0;
        // 因为不确定m的次数，所以需要从 1 -> i/2
        for (int j = 1; j <= i / 2; ++j) {  // j 为切割点
          max_val = max(max_val, dp[j] * dp[i-j]);
        }
        dp[i] = max_val;
      }
      return dp[n];
    }

    // 贪婪: O(1), 空间 O(1)
    int solution2(int n) {
      if (n < 2) return 0;  // 不满足n>1的条件
      if (n == 2) return 1;
      if (n == 3) return 2;

      // 通过数学归纳可知
      // 在切一刀，切割点为3的情况下，其长度乘积为 3(n-3)
      // 在切一刀，切割点为2的情况下，其长度乘积为 2(n-2)
      // 当 n>=5 时 3(n-3) >= 2(n-2), 故当长度 n >= 5 时，优先尽可能多的切长度为3的绳子

      int times_of_3 = n / 3;
      // 如果最后剩下的长度是4，则采用 2 * 2 的切法
      if (n - times_of_3 * 3 == 1)
        times_of_3 -= 1;

      int times_of_2 = (n - times_of_3 * 3) / 2;
      return int(pow(3, times_of_3)) * int(pow(2, times_of_2));
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
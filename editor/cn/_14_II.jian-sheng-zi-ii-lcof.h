//给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），每段绳子的长度记为 k[0],k[1]...k[m] 。请问
// k[0]*k[1]*...*k[m] 可能的最大乘积是多少？例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。 
//
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。 
//
// 
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
// 
//
// 提示： 
//
// 
// 2 <= n <= 1000 
// 
//
// 注意：本题与主站 343 题相同：https://leetcode-cn.com/problems/integer-break/ 
// Related Topics 数学 动态规划

#include "header.h"

namespace LeetCode_14_II {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int cuttingRope(int n) {
      return solution1(n);
    }

    int solution1(int n) {
      if (n < 2) return 0;
      if (n == 2) return 1;
      if (n == 3) return 2;

      int times_of_3 = n / 3;
      if (n % 3 == 1)
        times_of_3 -= 1;
      int times_of_2 = (n - times_of_3 * 3) / 2;

      long p = 1e9+7;
      long res = 1;
      while (times_of_3) {
        res = (res * 3) % p;
        --times_of_3;
      }
      return (res * int(pow(2, times_of_2))) % p;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
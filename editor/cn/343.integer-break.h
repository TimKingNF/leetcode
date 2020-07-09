//给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。 
//
// 示例 1: 
//
// 输入: 2
//输出: 1
//解释: 2 = 1 + 1, 1 × 1 = 1。 
//
// 示例 2: 
//
// 输入: 10
//输出: 36
//解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。 
//
// 说明: 你可以假设 n 不小于 2 且不大于 58。 
// Related Topics 数学 动态规划

#include "header.h"

namespace LeetCode343 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int integerBreak(int n) {
      if (n < 2) return 0;
      if (n == 2) return 1;
      if (n == 3) return 2;

      int times_of_3 = n / 3;
      // 如果最后一个数是4，则不能使用 1 3 的方式，应采用 2 2
      if (n % 3 == 1)
        times_of_3 -= 1;
      int times_of_2 = (n - times_of_3 * 3) / 2;
      return int(pow(3, times_of_3)) * int(pow(2, times_of_2));
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
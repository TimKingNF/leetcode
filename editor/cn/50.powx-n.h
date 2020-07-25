//实现 pow(x, n) ，即计算 x 的 n 次幂函数。 
//
// 示例 1: 
//
// 输入: 2.00000, 10
//输出: 1024.00000
// 
//
// 示例 2: 
//
// 输入: 2.10000, 3
//输出: 9.26100
// 
//
// 示例 3: 
//
// 输入: 2.00000, -2
//输出: 0.25000
//解释: 2-2 = 1/22 = 1/4 = 0.25 
//
// 说明: 
//
// 
// -100.0 < x < 100.0 
// n 是 32 位有符号整数，其数值范围是 [−231, 231 − 1] 。 
// 
// Related Topics 数学 二分查找

#include "header.h"

namespace LeetCode50 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    double myPow(double x, int n) {
      return solution1(x, n);
    }

    double solution1(double x, int n) {
      double ans = 1;
      for (int i = n; i != 0; i /= 2) {
        if (i & 1) ans *= x;  // 如果i为奇数，则需要补乘一个x
        x *= x;
      }
      return n < 0 ? 1 / ans : ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
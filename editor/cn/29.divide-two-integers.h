//给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。 
//
// 返回被除数 dividend 除以除数 divisor 得到的商。 
//
// 整数除法的结果应当截去（truncate）其小数部分，例如：truncate(8.345) = 8 以及 truncate(-2.7335) = -2 
//
// 
//
// 示例 1: 
//
// 输入: dividend = 10, divisor = 3
//输出: 3
//解释: 10/3 = truncate(3.33333..) = truncate(3) = 3 
//
// 示例 2: 
//
// 输入: dividend = 7, divisor = -3
//输出: -2
//解释: 7/-3 = truncate(-2.33333..) = -2 
//
// 
//
// 提示： 
//
// 
// 被除数和除数均为 32 位有符号整数。 
// 除数不为 0。 
// 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−231, 231 − 1]。本题中，如果除法结果溢出，则返回 231 − 1。 
// 
// Related Topics 数学 二分查找

#include "header.h"

namespace LeetCode29 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int divide(int dividend, int divisor) {
      return solution1(dividend, divisor);
    }

    int solution1(int dividend, int divisor) {
      if (dividend == 0) return 0;
      if (divisor == 1) return dividend;
      if (divisor == -1) {
        if (dividend > INT32_MIN) return -dividend;
        return INT32_MAX;  // 如果是最小数，则返回最大值
      }
      int sign = 1;
      if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) sign = -1;  // 返回负数
      // 都转为负数避免溢出
      dividend = -abs(dividend);
      divisor = -abs(divisor);
      return sign > 0 ? div(dividend, divisor) : -div(dividend, divisor);
    }

    // 负数的除法
    int div(int a, int b) {
      if (a > b) return 0;  // 因为都转为了负数，所以这里反过来
      int cnt = 1;
      int tb = b;
      // 满足 tb+tb 之后还要 >= a， 且没有溢出
      // 如果溢出则不再小于 0
      while (tb >= a - tb && tb + tb < 0) {
        tb += tb;
        cnt += cnt;
      }
      return cnt + div(a-tb, b);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
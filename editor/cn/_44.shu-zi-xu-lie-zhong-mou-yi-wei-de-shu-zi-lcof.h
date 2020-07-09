//数字以0123456789101112131415…的格式序列化到一个字符序列中。在这个序列中，第5位（从下标0开始计数）是5，第13位是1，第19位是4，
//等等。 
//
// 请写一个函数，求任意第n位对应的数字。 
//
// 
//
// 示例 1： 
//
// 输入：n = 3
//输出：3
// 
//
// 示例 2： 
//
// 输入：n = 11
//输出：0 
//
// 
//
// 限制： 
//
// 
// 0 <= n < 2^31 
// 
//
// 注意：本题与主站 400 题相同：https://leetcode-cn.com/problems/nth-digit/ 
// Related Topics 数学

#include "header.h"

namespace LeetCode_44 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNthDigit(int n) {
      return solution1(n);
    }

    // 核心思路就是用 n 不断判断和减去每一组字符的总个数。然后再除以当前字符位数
    // 从基数开始加，计算出 n 所在位置的数，再取模计算 n 所在位置的字符
    int solution1(int n) {
      if (n < 0) return -1;

      int digit = 1;  // 字符位数
      long numbers = countOfDigit(digit);  // 获取该字符位数一共有多少个数字
      long offset = numbers * digit;  // 一共有多少位数
      while (n >= offset) {
        n -= offset;
        numbers = countOfDigit(++digit);  // 求下一字符位数的 数字数量
        offset = numbers * digit;
      }
      int base = baseOfDigit(digit) + n / digit;  // 该数是n所在位置的数
      for (int i = 1; i < digit - n % digit; ++i)
        base /= 10;
      return base % 10;
    }

    long countOfDigit(int digit) {
      if (digit == 1) return 10;
      return 9 * (int) pow(10, digit - 1);
    }

    int baseOfDigit(int digit) {
      if (digit == 1) return 0;
      return (int) pow(10, digit-1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
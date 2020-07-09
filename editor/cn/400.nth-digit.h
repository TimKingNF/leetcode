//在无限的整数序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...中找到第 n 个数字。 
//
// 注意: 
//n 是正数且在32位整数范围内 ( n < 231)。 
//
// 示例 1: 
//
// 输入:
//3
//
//输出:
//3
// 
//
// 示例 2: 
//
// 输入:
//11
//
//输出:
//0
//
//说明:
//第11个数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是0，它是10的一部分。
// 
// Related Topics 数学

#include "header.h"

namespace LeetCode400 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findNthDigit(int n) {
      return solution1(n);
    }

    int solution1(int n) {
      if (n < 0) return -1;

      int digit = 1;  // 字符位数
      long numbers = countOfDigit(digit);  // 计算字符位数有多少个数字
      long offset = numbers * digit;
      while (n >= offset) {
        n -= offset;
        numbers = countOfDigit(++digit);
        offset = numbers * digit;
      }
      int base = baseOfDigit(digit) + n / digit;
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
      return (int) pow(10, digit - 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
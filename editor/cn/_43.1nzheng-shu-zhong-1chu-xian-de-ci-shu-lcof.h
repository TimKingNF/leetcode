//输入一个整数 n ，求1～n这n个整数的十进制表示中1出现的次数。 
//
// 例如，输入12，1～12这些整数中包含1 的数字有1、10、11和12，1一共出现了5次。 
//
// 
//
// 示例 1： 
//
// 输入：n = 12
//输出：5
// 
//
// 示例 2： 
//
// 输入：n = 13
//输出：6 
//
// 
//
// 限制： 
//
// 
// 1 <= n < 2^31 
// 
//
// 注意：本题与主站 233 题相同：https://leetcode-cn.com/problems/number-of-digit-one/ 
// Related Topics 数学

#include "header.h"

namespace LeetCode_43 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO
    int countDigitOne(int n) {
      return solution2(n);
    }

    int solution1(int n) {
      if (n <= 0) return 0;
      char strN[11];  // 最多10位数
      sprintf(strN, "%d", n);
      return solution1core(strN);
    }

    int solution1core(const char* strN) {
      if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
        return 0;
      int first = *strN - '0';  // 得到最高位的数字
      int length = strlen(strN);  // 获取数字的长度
      if (length == 1 && first == 0) return 0;  // 返回个位数的情况
      if (length == 1 && first > 0) return 1;

      // 第一步求出在最高位，出现的所有的1的次数
      int numFirstDigit = 0;
      if (first > 1)
        numFirstDigit = pow(10, length-1);
      else if (first == 1)
        numFirstDigit = atoi(strN + 1) + 1;  // 对于最高位为1，则取按剩下长度+1 的次数

      // 求的除去最高位，剩下的数字中出现1的次数，它的次数由
      // 最高位的次数 * 排列组合 (剩余长度中，任选一个为1，剩余数字在0～9之间的所有情况)
      int numOtherDigits = first * (length - 1) * pow(10, length-2);
      int numRecursive = solution1core(strN + 1);  // 递归求得剩余长度的次数
      return numFirstDigit + numOtherDigits + numRecursive;
    }

    // 循环求每个位为1的可能次数
    // 将数字拆成 高位，当前位，低位，如假设 2301，当前位为0，则高位为 23， 低位为1
    // 当前位为 0 时，该位为 1 取决于高位的总数，在本例中，0 为十位，digit 为 10，则出现 1 的次数为 高位 23 * 10 = 230
    // 当前位为 1 时，该位为 1 取决于高位的总数和低位之和，公式为 high * digit + low + 1
    // 当前为 >1 时，该位为 (high + 1) * digit
    int solution2(int n) {
      int high = n / 10, cur = n % 10, low = 0;
      long digit = 1;
      int ans = 0;
      while (high != 0 || cur != 0) {  // 高位和cur同时为0，说明已经越过最高位
        if (cur == 0)
          ans += high * digit;
        else if (cur == 1)
          ans += high * digit + low + 1;
        else
          ans += (high + 1) * digit;
        low += cur * digit;  // cur 加入到low 中，组成下一轮的low
        cur = high % 10;
        high /= 10;
        digit *= 10;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
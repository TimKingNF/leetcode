//编写一个方法，找出两个数字a和b中最大的那一个。不得使用if-else或其他比较运算符。 
// 示例： 
// 输入： a = 1, b = 2
//输出： 2
// 
// Related Topics 位运算 数学

#include "header.h"

namespace LeetCode_16_07 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximum(int a, int b) {
      return solution2(a, b);
    }

    // long 的长度 > int 长度的计算机上有效
    // 主要如果 sizeof(long) = sizeof(int) 情况下, a-b 溢出, 结果会不对
    int solution1(int a, int b) {
      long k = (((long)a - (long)b) >> 63) & 1;  // a-b 求符号位
      return b * k + a * (1 - k);
    }

    int solution2(int a, int b) {
      // 取反
      auto flip = [](int n) {
        return n ^ 1;
      };
      // 取符号位, 正数或 0 返回 1
      auto sign = [&](int n) {
        return flip((n >> 31) & 1);
      };
      unsigned int c = (uint ) a - b;
      int sa = sign(a), sb = sign(b), sc = sign(c);
      int difSab = sa ^ sb;  // ab符号位相同返回 0，不同为 1
      int sameSab = flip(difSab);  // 符号位相同时，该值为 1
      // 综合情况, 列得式子
      // 1）当a和b符号不同时，difSab = 1, sameSab = 0
      //    a 符号位为 0，那么 b 为负数，sa = 1, sb = 0, 应返回 a
      //    a 符号位为 1，那么 b 是正数，sa = 0, sb = 1, 应返回 b
      // 2) 当a和b符号相同时，difSab = 0, sameSab = 1, 此时 a-b 不会溢出
      //    a-b 为正数，即 sc = 1 时，返回 a
      //    a-b 为负数, 即 sc = 0 时，返回 b
      int returnA = difSab * sa + sameSab * sc;
      int returnB = flip(returnA);
      return a * returnA + b * returnB;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
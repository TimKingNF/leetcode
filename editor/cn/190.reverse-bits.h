//颠倒给定的 32 位无符号整数的二进制位。 
//
// 
//
// 示例 1： 
//
// 输入: 00000010100101000001111010011100
//输出: 00111001011110000010100101000000
//解释: 输入的二进制串 00000010100101000001111010011100 表示无符号整数 43261596，
//     因此返回 964176192，其二进制表示形式为 00111001011110000010100101000000。 
//
// 示例 2： 
//
// 输入：11111111111111111111111111111101
//输出：10111111111111111111111111111111
//解释：输入的二进制串 11111111111111111111111111111101 表示无符号整数 4294967293，
//     因此返回 3221225471 其二进制表示形式为 10111111111111111111111111111111 。 
//
// 
//
// 提示： 
//
// 
// 请注意，在某些语言（如 Java）中，没有无符号整数类型。在这种情况下，输入和输出都将被指定为有符号整数类型，并且不应影响您的实现，因为无论整数是有符号的
//还是无符号的，其内部的二进制表示形式都是相同的。 
// 在 Java 中，编译器使用二进制补码记法来表示有符号整数。因此，在上面的 示例 2 中，输入表示有符号整数 -3，输出表示有符号整数 -10737418
//25。 
// 
//
// 
//
// 进阶: 
//如果多次调用这个函数，你将如何优化你的算法？ 
// Related Topics 位运算

#include "header.h"

namespace LeetCode190 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
      return solution3(n);
    }

    uint32_t solution1(uint32_t n) {
      int left = 31, right = 0;
      int left_bit, right_bit;
      while (left > right) {
        left_bit = n & (1 << left);  // left指示的位
        right_bit = n & (1 << right);
        n = left_bit ? (n | (1 << right)) : (n & ~(1 << right));  // 设置具体的位值
        n = right_bit ? (n | (1 << left)) : (n & ~(1 << left));
        --left;
        ++right;
      }
      return n;
    }

    // 用一个新的数存储
    uint32_t solution2(uint32_t n) {
      uint32_t ret = 0;
      for(int i = 31; i >= 0; i--) {
        ret = ret | (((n>>(31-i)) & 1) << i);
      }
      return ret;
    }

    // 第一步: 左右两位高低交换  (使用奇偶交换的方法)
    // 第二步：2位 2位的高低位交换
    // 第三步：4位 4位的高低位交换
    // 第四步：8位 8位的高低位交换
    // 第五步：16位 16位的高低位交换
    uint32_t solution3(uint32_t n) {
      // 取偶数位和奇数位的数，各向左和右移动一位，再或，得2位高低交换之后的数
      n = ((n & 0xAAAAAAAA) >> 1) | ((n & 0x55555555) << 1);
      n = ((n & 0xCCCCCCCC) >> 2) | ((n & 0x33333333) << 2);
      n = ((n & 0xF0F0F0F0) >> 4) | ((n & 0x0F0F0F0F) << 4);
      n = ((n & 0xFF00FF00) >> 8) | ((n & 0x00FF00FF) << 8);
      n = (n >> 16) | (n << 16);
      return n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
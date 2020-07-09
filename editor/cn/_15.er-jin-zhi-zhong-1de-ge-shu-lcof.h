//请实现一个函数，输入一个整数，输出该数二进制表示中 1 的个数。例如，把 9 表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 
//2。 
//
// 示例 1： 
//
// 输入：00000000000000000000000000001011
//输出：3
//解释：输入的二进制串 00000000000000000000000000001011 中，共有三位为 '1'。
// 
//
// 示例 2： 
//
// 输入：00000000000000000000000010000000
//输出：1
//解释：输入的二进制串 00000000000000000000000010000000 中，共有一位为 '1'。
// 
//
// 示例 3： 
//
// 输入：11111111111111111111111111111101
//输出：31
//解释：输入的二进制串 11111111111111111111111111111101 中，共有 31 位为 '1'。 
//
// 
//
// 注意：本题与主站 191 题相同：https://leetcode-cn.com/problems/number-of-1-bits/ 
// Related Topics 位运算

#include "header.h"

namespace LeetCode_15 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int hammingWeight(uint32_t n) {
      return solution3(n);
    }

    int solution1(uint32_t n) {
      // 题目中为无符号数，如果是负数，则无法采用移位方式
      int res = 0;
      while (n >= 1) {
        res += n & 1;
        n = n >> 1;
      }
      return res;
    }

    int solution2(uint32_t n) {
      // 兼容负数版本, 改为由1进行右移的版本
      int count = 0;
      int flag = 1;
      while (flag) {
        if (n & flag) ++count;
        flag = flag << 1;
      }
      return count;
    }

    int solution3(uint32_t n) {
      // 利用 n & (n-1) 的可以将最右位的1置0的性质
      int res = 0;
      while (n) {
        n = n & (n-1);
        ++res;
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
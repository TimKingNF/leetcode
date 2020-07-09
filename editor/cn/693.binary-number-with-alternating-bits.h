//给定一个正整数，检查他是否为交替位二进制数：换句话说，就是他的二进制数相邻的两个位数永不相等。 
//
// 示例 1: 
//
// 
//输入: 5
//输出: True
//解释:
//5的二进制数是: 101
// 
//
// 示例 2: 
//
// 
//输入: 7
//输出: False
//解释:
//7的二进制数是: 111
// 
//
// 示例 3: 
//
// 
//输入: 11
//输出: False
//解释:
//11的二进制数是: 1011
// 
//
// 示例 4: 
//
// 
//输入: 10
//输出: True
//解释:
//10的二进制数是: 1010
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode693 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool hasAlternatingBits(int n) {
      return solution2(n);
    }

    bool solution1(int num) {
      unsigned int n = num;
      int v;
      while (n != 0) {
        v = n & 0x3;
        if (v == 0 || v == 3) return false;
        n >>= 1;
      }
      return true;
    }

    bool solution2(int n) {
      n = n ^ (n >> 1);
      return (n & ((long) n + 1)) == 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
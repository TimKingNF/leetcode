//给定两个整数 L 和 R ，找到闭区间 [L, R] 范围内，计算置位位数为质数的整数个数。 
//
// （注意，计算置位代表二进制表示中1的个数。例如 21 的二进制表示 10101 有 3 个计算置位。还有，1 不是质数。） 
//
// 示例 1: 
//
// 
//输入: L = 6, R = 10
//输出: 4
//解释:
//6 -> 110 (2 个计算置位，2 是质数)
//7 -> 111 (3 个计算置位，3 是质数)
//9 -> 1001 (2 个计算置位，2 是质数)
//10-> 1010 (2 个计算置位，2 是质数)
// 
//
// 示例 2: 
//
// 
//输入: L = 10, R = 15
//输出: 5
//解释:
//10 -> 1010 (2 个计算置位, 2 是质数)
//11 -> 1011 (3 个计算置位, 3 是质数)
//12 -> 1100 (2 个计算置位, 2 是质数)
//13 -> 1101 (3 个计算置位, 3 是质数)
//14 -> 1110 (3 个计算置位, 3 是质数)
//15 -> 1111 (4 个计算置位, 4 不是质数)
// 
//
// 注意: 
//
// 
// L, R 是 L <= R 且在 [1, 10^6] 中的整数。 
// R - L 的最大值为 10000。 
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode762 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countPrimeSetBits(int L, int R) {
      return solution1(L, R);
    }

    // 暴力解法, 10^6 次方 一共有20位的二进制
    int solution1(int L, int R) {
      int ans = 0, count;
      for (int i = L; i <= R; ++i) {
        count = countOfDigit(i);
        if (count == 2 || count == 3 || count == 5 || count == 7 ||
            count == 11 || count == 13 || count == 17 || count == 19)
          ++ans;
      }
      return ans;
    }

    int countOfDigit(int v) {
      int ans = 0;
      while (v != 0) {
        v = v & (v - 1);
        ++ans;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
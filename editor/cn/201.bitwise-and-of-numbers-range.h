//给定范围 [m, n]，其中 0 <= m <= n <= 2147483647，返回此范围内所有数字的按位与（包含 m, n 两端点）。 
//
// 示例 1: 
//
// 输入: [5,7]
//输出: 4 
//
// 示例 2: 
//
// 输入: [0,1]
//输出: 0 
// Related Topics 位运算

#include "header.h"

namespace LeetCode201 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
      return solution1(m, n);
    }

    int solution1(int m, int n) {
      // n 大于 m，所以两者最高相同1的位之前都不用考虑了
      // 只需考虑 最高相同1之后的低位，同理，有第一个高位相同之后，考虑第二个高位相同
      // 即需要有相同的前缀1, 所以只要一直 n 大于 m，就可以一直消去低位的 1，直到 n < m
      while (n > m) {
        n &= n-1;
      }
      return n;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
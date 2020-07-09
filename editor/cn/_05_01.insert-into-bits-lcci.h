//插入。给定两个32位的整数N与M，以及表示比特位置的i与j。编写一种方法，将M插入N，使得M从N的第j位开始，到第i位结束。假定从j位到i位足以容纳M，也即
//若M = 10 011，那么j和i之间至少可容纳5个位。例如，不可能出现j = 3和i = 2的情况，因为第3位和第2位之间放不下M。 
//
// 示例1: 
//
// 
// 输入：N = 10000000000, M = 10011, i = 2, j = 6
// 输出：N = 10001001100
// 
//
// 示例2: 
//
// 
// 输入： N = 0, M = 11111, i = 0, j = 4
// 输出：N = 11111
// 
// Related Topics 位运算

#include "header.h"

namespace LeetCode_05_01 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int insertBits(int N, int M, int i, int j) {
      return solution1(N, M, i, j);
    }

    int solution1(int N, int M, int i, int j) {
      int mask = ((1 << (j - i + 1)) - 1) << i;
      return (N & ~mask) | (M << i);  // 将 i - j 的位置置0
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
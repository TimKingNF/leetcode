//给定一个整数 n，返回 n! 结果尾数中零的数量。 
//
// 示例 1: 
//
// 输入: 3
//输出: 0
//解释: 3! = 6, 尾数中没有零。 
//
// 示例 2: 
//
// 输入: 5
//输出: 1
//解释: 5! = 120, 尾数中有 1 个零. 
//
// 说明: 你算法的时间复杂度应为 O(log n) 。 
// Related Topics 数学

#include "header.h"

namespace LeetCode172 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int trailingZeroes(int n) {
      return solution2(n);
    }

    // O( N ), 会超时
    // 要乘得0，必须含有一对 2 和 5 因子
    // 已知包含 2 的因子和 5 的因子会在 10 出重叠，在 5 处只有 2 可以对应
    // 故我们只需考虑以 5 为倍数的因子即可
    int solution1(int n) {
      int zero_cnt = 0;
      for (int i = 5; i <= n; i+=5) {
        int cur = i;
        while (cur % 5 == 0) {
          zero_cnt += 1;
          cur /= 5;
        }
      }
      return zero_cnt;
    }

    // 直接计算有多少个 5 的因子
    int solution2(int n) {
      int zero_cnt = 0;
      while (n > 0) {
        n /= 5;
        zero_cnt += n;
      }
      return zero_cnt;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
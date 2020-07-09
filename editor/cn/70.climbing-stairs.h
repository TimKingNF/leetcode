//假设你正在爬楼梯。需要 n 阶你才能到达楼顶。 
//
// 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？ 
//
// 注意：给定 n 是一个正整数。 
//
// 示例 1： 
//
// 输入： 2
//输出： 2
//解释： 有两种方法可以爬到楼顶。
//1.  1 阶 + 1 阶
//2.  2 阶 
//
// 示例 2： 
//
// 输入： 3
//输出： 3
//解释： 有三种方法可以爬到楼顶。
//1.  1 阶 + 1 阶 + 1 阶
//2.  1 阶 + 2 阶
//3.  2 阶 + 1 阶
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode70 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int climbStairs(int n) {
      if (n <= 2) return n;
      int one_step_ways = 2;  // f(n-1)  只需走一步
      int two_step_ways = 1;  // f(n-2)  需要走两步
      int all_ways = 0;

      for (int i = 2; i < n; ++i) {
        all_ways = one_step_ways + two_step_ways;  // 下一步的总走法为 f(n-1) + f(n-2)
        two_step_ways = one_step_ways;  // 对下一步来说，原来需要一步的变为需要走两步
        one_step_ways = all_ways;  // 只需走一步， 所以是本次台阶的总走法
      }
      return all_ways;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//你和你的朋友，两个人一起玩 Nim 游戏：桌子上有一堆石头，每次你们轮流拿掉 1 - 3 块石头。 拿掉最后一块石头的人就是获胜者。你作为先手。 
//
// 你们是聪明人，每一步都是最优解。 编写一个函数，来判断你是否可以在给定石头数量的情况下赢得游戏。 
//
// 示例: 
//
// 输入: 4
//输出: false 
//解释: 如果堆中有 4 块石头，那么你永远不会赢得比赛；
//     因为无论你拿走 1 块、2 块 还是 3 块石头，最后一块石头总是会被你的朋友拿走。
// 
// Related Topics 脑筋急转弯 极小化极大

#include "header.h"

namespace LeetCode292 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool canWinNim(int n) {
      return solution1(n);
    }

    // 当石子数为 4 的倍数时先手必输
    bool solution1(int n) {
      return n & 3;
    }

    // 动态规划法, 作为一种补充思路
    // 当 n-1 n-2 n-3 都为true时，n必输
    // f(n) = !(f(n-1) && f(n-2) && f(n-3))
    bool solution2(int n) {
      bool dp[4];
      dp[0] = false;
      dp[1] = true;
      dp[2] = true;
      dp[3] = true;
      for (int i = 4; i <= n; ++i) {
        dp[i % 4] = !(dp[(i-1) % 4] && dp[(i-2) % 4] && dp[(i-3) % 4]);
      }
      return dp[n % 4];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
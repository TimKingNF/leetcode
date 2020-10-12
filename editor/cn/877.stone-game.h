//亚历克斯和李用几堆石子在做游戏。偶数堆石子排成一行，每堆都有正整数颗石子 piles[i] 。 
//
// 游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。 
//
// 亚历克斯和李轮流进行，亚历克斯先开始。 每回合，玩家从行的开始或结束处取走整堆石头。 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
// 
//
// 假设亚历克斯和李都发挥出最佳水平，当亚历克斯赢得比赛时返回 true ，当李赢得比赛时返回 false 。 
//
// 
//
// 示例： 
//
// 输入：[5,3,4,5]
//输出：true
//解释：
//亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
//假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
//如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
//如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
//这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以我们返回 true 。
// 
//
// 
//
// 提示： 
//
// 
// 2 <= piles.length <= 500 
// piles.length 是偶数。 
// 1 <= piles[i] <= 500 
// sum(piles) 是奇数。 
// 
// Related Topics 极小化极大 数学 动态规划

#include "header.h"

namespace LeetCode877 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
      return solution2(piles);
    }

    // dp
    bool solution1(vector<int>& piles) {
      int n = piles.size();
      // 记录从 i->j 的石头，第三维 0 表示先手，1 表示后手
      vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 0)));
      // base case
      for (int i = 0; i < n; ++i) {
        dp[i][i][0] = piles[i];  // 只有一堆石头时，先手拿着所有石头
        dp[i][i][1] = 0;  // 后手没有石头
      }

      // 填表的时候，从下往上填
      for (int l = n-1; l >= 0; --l) {
        for (int r = l+1; r < n; ++r) {
          // 先手选择最左边或者最右边
          int left = piles[l] + dp[l+1][r][1];  // 选择左边，然后面对 [l+1,r] 的石头，先手变为后手
          int right = piles[r] + dp[l][r-1][1];  // 同上

          if (left > right) {  // 先手选择左边
            dp[l][r][0] = left;
            dp[l][r][1] = dp[l+1][r][0];  // 原来的后手变为先手
          } else {
            dp[l][r][0] = right;
            dp[l][r][1] = dp[l][r-1][0];  // 同上
          }
        }
      }
      return dp[0][n-1][0] > dp[0][n-1][1];
    }

    // dp: 可以更简化一点
    bool solution2(vector<int>& piles) {
      int length = piles.size();
      auto dp = vector<int>(length);
      for (int i = 0; i < length; i++) {
        dp[i] = piles[i];
      }
      for (int i = length - 2; i >= 0; i--) {
        for (int j = i + 1; j < length; j++) {
          dp[j] = max(piles[i] - dp[j], piles[j] - dp[j - 1]);
        }
      }
      return dp[length - 1] > 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
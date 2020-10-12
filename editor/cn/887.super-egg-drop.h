//你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N 共有 N 层楼的建筑。 
//
// 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。 
//
// 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于 F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。 
//
// 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1 <= X <= N）。 
//
// 你的目标是确切地知道 F 的值是多少。 
//
// 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？ 
//
// 
//
// 
// 
//
// 示例 1： 
//
// 输入：K = 1, N = 2
//输出：2
//解释：
//鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
//否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
//如果它没碎，那么我们肯定知道 F = 2 。
//因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
// 
//
// 示例 2： 
//
// 输入：K = 2, N = 6
//输出：3
// 
//
// 示例 3： 
//
// 输入：K = 3, N = 14
//输出：4
// 
//
// 
//
// 提示： 
//
// 
// 1 <= K <= 100 
// 1 <= N <= 10000 
// 
// Related Topics 数学 二分查找 动态规划

#include "header.h"

namespace LeetCode887 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int superEggDrop(int K, int N) {
      return solution1(K, N);
    }

    // dp
    // https://www.bilibili.com/video/BV1KE41137PK?from=search&seid=17973611971894816621
    int solution1(int K, int N) {
      vector<vector<int>> dp(N+1, vector<int>(K+1, INT32_MAX));
      // 构建初值
      for (int i = 1; i <= K; ++i) {
        dp[0][i] = 0;  // 0 层楼
        dp[1][i] = 1;  // 只有一层楼的情况下，只需要扔一次
      }
      for (int i = 1; i <= N; ++i) {
        dp[i][0] = 0;  // 0个蛋
        dp[i][1] = i;  // 只有一个蛋，只能一层一层扔，最坏情况就是和楼层数一样
      }

      // // 正常填表，最后时间复杂度是 O( N^2 * K )
      // for (int i = 2; i <= N; i++) {
      //   for (int j = 2; j <= K; j++) {
      //     for (int k = 1; k <= i; k++) {
      //       // 碎了，就需要往低层继续扔：层数少 1 ，鸡蛋也少 1
      //       // 不碎，就需要往高层继续扔：层数是当前层到最高层的距离差，鸡蛋数量不少
      //       // 两种情况都做了一次尝试，所以加 1
      //       dp[i][j] = min(dp[i][j], max(dp[k - 1][j - 1], dp[i - k][j]) + 1);
      //     }
      //   }
      // }

      // 利用二分法，加快 k 的查找
      for (int i = 2; i <= N; ++i) {
        for (int j = 2; j <= K; ++j) {
          // 在区间 [1, i] 里确定一个最优值
          // 该最优值使得 dp[i][j] 最小, 所以在 单调递增 和 单调递减 的交汇点取得最小
          int left = 1, right = i;
          while (left < right) {
            int mid = left + (right - left + 1) / 2;
            int breakCount = dp[mid-1][j-1];  // 单调递增
            int notBreakCount = dp[i-mid][j];  // 单调递减
            if (breakCount > notBreakCount) {
              right = mid - 1;
            } else {
              left = mid;
            }
          }
          dp[i][j] = max(dp[left-1][j-1], dp[i-left][j]) + 1;
        }
      }
      return dp[N][K];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
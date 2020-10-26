//你将会获得一系列视频片段，这些片段来自于一项持续时长为 T 秒的体育赛事。这些片段可能有所重叠，也可能长度不一。 
//
// 视频片段 clips[i] 都用区间进行表示：开始于 clips[i][0] 并于 clips[i][1] 结束。我们甚至可以对这些片段自由地再剪辑，例如
//片段 [0, 7] 可以剪切成 [0, 1] + [1, 3] + [3, 7] 三部分。 
//
// 我们需要将这些片段进行再剪辑，并将剪辑后的内容拼接成覆盖整个运动过程的片段（[0, T]）。返回所需片段的最小数目，如果无法完成该任务，则返回 -1 。 
//
//
// 
//
// 示例 1： 
//
// 
//输入：clips = [[0,2],[4,6],[8,10],[1,9],[1,5],[5,9]], T = 10
//输出：3
//解释：
//我们选中 [0,2], [8,10], [1,9] 这三个片段。
//然后，按下面的方案重制比赛片段：
//将 [1,9] 再剪辑为 [1,2] + [2,8] + [8,9] 。
//现在我们手上有 [0,2] + [2,8] + [8,10]，而这些涵盖了整场比赛 [0, 10]。
// 
//
// 示例 2： 
//
// 
//输入：clips = [[0,1],[1,2]], T = 5
//输出：-1
//解释：
//我们无法只用 [0,1] 和 [1,2] 覆盖 [0,5] 的整个过程。
// 
//
// 示例 3： 
//
// 
//输入：clips = [[0,1],[6,8],[0,2],[5,6],[0,4],[0,3],[6,7],[1,3],[4,7],[1,4],[2,5],
//[2,6],[3,4],[4,5],[5,7],[6,9]], T = 9
//输出：3
//解释： 
//我们选取片段 [0,4], [4,7] 和 [6,9] 。
// 
//
// 示例 4： 
//
// 
//输入：clips = [[0,4],[2,8]], T = 5
//输出：2
//解释：
//注意，你可能录制超过比赛结束时间的视频。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= clips.length <= 100 
// 0 <= clips[i][0] <= clips[i][1] <= 100 
// 0 <= T <= 100 
// 
// Related Topics 动态规划 
// 👍 138 👎 0

#include "header.h"

namespace LeetCode1024 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int videoStitching(vector<vector<int>>& clips, int T) {
    return solution2(clips, T);
  }

  // DP
  // O( T * N ), O( N )
  int solution1(vector<vector<int>>& clips, int T) {
    int dp[T+1];
    fill(dp, dp+T+1, 101);
    dp[0] = 0;

    for (int i = 1; i <= T; ++i) {
      for (auto& it : clips) {
        if (it[0] < i && i <= it[1]) {
          dp[i] = min(dp[i], dp[it[0]] + 1);
        }
      }
    }
    return dp[T] == 101 ? -1 : dp[T];
  }

  // 贪心法
  // O( T + N ), O( N )
  int solution2(vector<vector<int>>& clips, int T) {
    vector<int> maxn(T, 0);
    int last = 0, ret = 0, pre = 0;
    for (auto& it : clips) {
      if (it[0] < T) {
        maxn[it[0]] = max(maxn[it[0]], it[1]);  // 该起点能到的最大秒数
      }
    }
    for (int i = 0; i < T; ++i) {
      last = max(last, maxn[i]);
      if (i == last) return -1;  // 此时说明 last 位置无法到达
      if (i == pre) {  // 越过上一个片段，需要取新的片段
        ret++;  // 记录片段 + 1
        pre = last;  // 新片段的结束点
      }
    }
    return ret;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个表示分数的非负整数数组。 玩家 1 从数组任意一端拿取一个分数，随后玩家 2 继续从剩余数组任意一端拿取分数，然后玩家 1 拿，…… 。每次一个玩家
//只能拿取一个分数，分数被拿取之后不再可取。直到没有剩余分数可取时游戏结束。最终获得分数总和最多的玩家获胜。 
//
// 给定一个表示分数的数组，预测玩家1是否会成为赢家。你可以假设每个玩家的玩法都会使他的分数最大化。 
//
// 
//
// 示例 1： 
//
// 输入：[1, 5, 2]
//输出：False
//解释：一开始，玩家1可以从1和2中进行选择。
//如果他选择 2（或者 1 ），那么玩家 2 可以从 1（或者 2 ）和 5 中进行选择。如果玩家 2 选择了 5 ，那么玩家 1 则只剩下 1（或者 2 ）
//可选。
//所以，玩家 1 的最终分数为 1 + 2 = 3，而玩家 2 为 5 。
//因此，玩家 1 永远不会成为赢家，返回 False 。
// 
//
// 示例 2： 
//
// 输入：[1, 5, 233, 7]
//输出：True
//解释：玩家 1 一开始选择 1 。然后玩家 2 必须从 5 和 7 中进行选择。无论玩家 2 选择了哪个，玩家 1 都可以选择 233 。
//     最终，玩家 1（234 分）比玩家 2（12 分）获得更多的分数，所以返回 True，表示玩家 1 可以成为赢家。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= 给定的数组长度 <= 20. 
// 数组里所有分数都为非负数且不会大于 10000000 。 
// 如果最终两个玩家的分数相等，那么玩家 1 仍为赢家。 
// 
// Related Topics 极小化极大 动态规划

#include "header.h"

namespace LeetCode486 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
      return solution2(nums);
    }

    // dp
    bool solution1(vector<int>& nums) {
      int length = nums.size();
      auto dp = vector<vector<int>> (length, vector<int>(length));
      for (int i = 0; i < length; i++) {
        dp[i][i] = nums[i];
      }
      for (int i = length - 2; i >= 0; i--) {
        for (int j = i + 1; j < length; j++) {
          dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);  // 记录先后手的分数之差
        }
      }
      return dp[0][length - 1] >= 0;  // 最后如果先手-后手分数>=0,则先手必胜
    }

    // dp，优化到一维空间
    bool solution2(vector<int>& nums) {
      int length = nums.size();
      auto dp = vector<int>(length);
      for (int i = 0; i < length; i++) {
        dp[i] = nums[i];
      }
      for (int i = length - 2; i >= 0; i--) {
        for (int j = i + 1; j < length; j++) {
          dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
        }
      }
      return dp[length - 1] >= 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
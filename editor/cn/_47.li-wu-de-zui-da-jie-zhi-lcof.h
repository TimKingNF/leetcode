//在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直
//到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？ 
//
// 
//
// 示例 1: 
//
// 输入: 
//[
//  [1,3,1],
//  [1,5,1],
//  [4,2,1]
//]
//输出: 12
//解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物 
//
// 
//
// 提示： 
//
// 
// 0 < grid.length <= 200 
// 0 < grid[0].length <= 200 
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode_47 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
      return solution2(grid);
    }

    int solution1(vector<vector<int>>& grid) {
      int r = grid.size(), c = grid[0].size();  // 获取高和长
      int dp[r][c];
      dp[0][0] = grid[0][0];
      // 初始化第一排第一列
      for (int i = 1; i < c; ++i)
        dp[0][i] = dp[0][i-1] + grid[0][i];
      for (int i = 1; i < r; ++i)
        dp[i][0] = dp[i-1][0] + grid[i][0];

      // 递推
      for (int i = 1; i < r; ++i) {
        for (int j = 1; j < c; ++j) {
          dp[i][j] = max(dp[i][j-1], dp[i-1][j]) + grid[i][j];
        }
      }
      return dp[r-1][c-1];
    }

    // 由于最大值只取决于 上和左，故可以优化到只需要 int[cols] 空间
    int solution2(vector<vector<int>>& grid) {
      int r = grid.size(), c = grid[0].size();
      int dp[c];  // 0 表示 up，1 表示 left
      int up, left;
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          up = left = 0;
          if (i > 0) up = dp[j];
          if (j > 0) left = dp[j-1];
          dp[j] = max(up, left) + grid[i][j];
        }
      }
      return dp[c-1];
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
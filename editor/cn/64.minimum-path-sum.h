//给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。 
//
// 说明：每次只能向下或者向右移动一步。 
//
// 
//
// 示例 1： 
//
// 
//输入：grid = [[1,3,1],[1,5,1],[4,2,1]]
//输出：7
//解释：因为路径 1→3→1→1→1 的总和最小。
// 
//
// 示例 2： 
//
// 
//输入：grid = [[1,2,3],[4,5,6]]
//输出：12
// 
//
// 
//
// 提示： 
//
// 
// m == grid.length 
// n == grid[i].length 
// 1 <= m, n <= 200 
// 0 <= grid[i][j] <= 100 
// 
// Related Topics 数组 动态规划 
// 👍 795 👎 0

#include "header.h"

namespace LeetCode64 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
      return solution2(grid);
    }

    // dfs，记录所有路径并判断

    // dp
    // O( M*N ), O( M*N )
    int solution1(vector<vector<int>>& grid) {
      if (grid.empty() || grid[0].empty()) return 0;
      int rows = grid.size(), cols = grid[0].size();
      vector<vector<int>> dp(rows, vector<int>(cols, 0));

      // base
      dp[0][0] = grid[0][0];
      for (int i = 1; i < rows; ++i) dp[i][0] = dp[i-1][0] + grid[i][0];
      for (int i = 1; i < cols; ++i) dp[0][i] = dp[0][i-1] + grid[0][i];

      for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
      }
      return dp[rows-1][cols-1];
    }

    // dp 空间压缩
    // O( M*N ), O( min(M,N) )
    int solution2(vector<vector<int>>& grid) {
      if (grid.empty() || grid[0].empty()) return 0;
      // 行数与列数中较大的为more，较小的为 less
      int more = max(grid.size(), grid[0].size());
      int less = min(grid.size(), grid[0].size());
      bool rowMore = more == grid.size();
      int dp[less];  // 以最小值计
      dp[0] = grid[0][0];

      // rowMore 则从上往下，colMore 则从左往右
      for (int i = 1; i < less; ++i) {
        dp[i] = dp[i-1] + (rowMore ? grid[0][i] : grid[i][0]);
      }
      for (int i = 1; i < more; ++i) {
        dp[0] += rowMore ? grid[i][0] : grid[0][i];
        for (int j = 1; j < less; ++j) {
          dp[j] = min(dp[j-1], dp[j]) + (rowMore ? grid[i][j] : grid[j][i]);
        }
      }
      return dp[less-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个包含 0 和 1 的二维网格地图，其中 1 表示陆地 0 表示水域。 
//
// 网格中的格子水平和垂直方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。 
//
// 岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿
//的周长。 
//
// 
//
// 示例 : 
//
// 输入:
//[[0,1,0,0],
// [1,1,1,0],
// [0,1,0,0],
// [1,1,0,0]]
//
//输出: 16
//
//解释: 它的周长是下面图片中的 16 个黄色的边：
//
//
// 
// Related Topics 哈希表 
// 👍 321 👎 0

#include "header.h"

namespace LeetCode463 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
      return solution2(grid);
    }

    // dfs
    int solution1(vector<vector<int>>& grid) {
      int n = grid.size(), m = grid[0].size();
      int ans = 0;

      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (grid[i][j] == 1) ans += dfs(grid, i, j);
        }
      }
      return ans;
    }

    int dfs(vector<vector<int>>& grid, int r, int c) {
      int n = grid.size(), m = grid[0].size();
      // 越界或者是水，则返回边 1
      if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0) return 1;

      if (grid[r][c] == 2) return 0;  // 已经遍历过, 返回 0
      grid[r][c] = 2;

      int res = 0;
      res += dfs(grid, r-1, c);
      res += dfs(grid, r+1, c);
      res += dfs(grid, r, c-1);
      res += dfs(grid, r, c+1);
      return res;
    }

    // 遍历的同时，只考虑右和下的方格，如果是岛屿，则 少2边 (左右岛屿都少一边)
    int solution2(vector<vector<int>>& grid) {
      int n = grid.size(), m = grid[0].size();
      int island = 0, border = 0;

      for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
          if (grid[r][c] == 1) {
            ++island;

            if (c + 1 < m && grid[r][c+1] == 1) ++border;
            if (r + 1 < n && grid[r+1][c] == 1) ++border;
          }
        }
      }
      return 4 * island - 2 * border;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。 
//
// 岛屿总是被水包围，并且每座岛屿只能由水平方向或竖直方向上相邻的陆地连接形成。 
//
// 此外，你可以假设该网格的四条边均被水包围。 
//
// 
//
// 示例 1: 
//
// 输入:
//[
//['1','1','1','1','0'],
//['1','1','0','1','0'],
//['1','1','0','0','0'],
//['0','0','0','0','0']
//]
//输出: 1
// 
//
// 示例 2: 
//
// 输入:
//[
//['1','1','0','0','0'],
//['1','1','0','0','0'],
//['0','0','1','0','0'],
//['0','0','0','1','1']
//]
//输出: 3
//解释: 每座岛屿只能由水平和/或竖直方向上相邻的陆地连接而成。
// 
// Related Topics 深度优先搜索 广度优先搜索 并查集

#include "header.h"

namespace LeetCode200 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
      return solution2(grid);
    }

    // bfs
    // 在原矩阵中进行遍历，遇到一个新的 1 ，就进行广度搜索，将访问过的元素置 0
    // 最后记录新的1的个数即可
    int solution1(vector<vector<char>>& grid) {
      if (grid.empty()) return 0;

      int ans = 0, rows = grid.size(), cols = grid[0].size();
      auto bfs = [&](int r, int c) {
        deque<pair<int, int>> q;
        q.push_back({r, c});
        pair<int, int> cur;
        while (!q.empty()) {
          cur = q.front();
          r = cur.first;
          c = cur.second;
          q.pop_front();
          if (r < 0 || r == rows || c < 0 || c == cols || grid[r][c] == '0') continue;
          grid[r][c] = '0';
          q.push_back({r-1, c});  // 上
          q.push_back({r+1, c});  // 下
          q.push_back({r, c-1});  // 左
          q.push_back({r, c+1});  // 右
        }
      };

      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          if (grid[r][c] == '1') {
            bfs(r, c);
            ++ans;
          }
        }
      }
      return ans;
    }

    // dfs
    int solution2(vector<vector<char>>& grid) {
      if (grid.empty()) return 0;
      int rows = grid.size(), cols = grid[0].size(), ans = 0;
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          if (grid[r][c] == '1') {
            dfs(grid, r, c);
            ++ans;
          }
        }
      }
      return ans;
    }

    void dfs(vector<vector<char>>& grid, int r, int c) {
      int rows = grid.size(), cols = grid[0].size();
      if (r < 0 || r == rows || c < 0 || c == cols || grid[r][c] == '0') return;
      grid[r][c] = '0';
      dfs(grid, r-1, c);
      dfs(grid, r+1, c);
      dfs(grid, r, c-1);
      dfs(grid, r, c+1);
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
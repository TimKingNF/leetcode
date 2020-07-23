//给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。 
//
// 两个相邻元素间的距离为 1 。 
//
// 示例 1: 
//输入: 
//
// 
//0 0 0
//0 1 0
//0 0 0
// 
//
// 输出: 
//
// 
//0 0 0
//0 1 0
//0 0 0
// 
//
// 示例 2: 
//输入: 
//
// 
//0 0 0
//0 1 0
//1 1 1
// 
//
// 输出: 
//
// 
//0 0 0
//0 1 0
//1 2 1
// 
//
// 注意: 
//
// 
// 给定矩阵的元素个数不超过 10000。 
// 给定矩阵中至少有一个元素是 0。 
// 矩阵中的元素只在四个方向上相邻: 上、下、左、右。 
// 
// Related Topics 深度优先搜索 广度优先搜索

#include "header.h"

namespace LeetCode542 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
      return solution2(matrix);
    }

    // bfs
    vector<vector<int>> solution1(vector<vector<int>>& matrix) {
      if (matrix.empty()) return matrix;
      int rows = matrix.size(), cols = matrix[0].size();
      // 修改为1的值
      auto bfs = [&](int r, int c) {
        deque<pair<int, int>> q;
        pair<int, int> cur;
        q.emplace_back(r, c);
        int distance = 0, size, nr, nc;
        while (!q.empty()) {
          size = q.size();
          for (int i = 0; i < size; ++i) {
            cur = q.front();
            q.pop_front();
            nr = cur.first;
            nc = cur.second;
            if (nr < 0 || nr == rows || nc < 0 || nc == cols) continue;
            if (matrix[nr][nc] == 0) {
              matrix[r][c] = distance;
              return;
            }
            q.emplace_back(nr-1, nc);
            q.emplace_back(nr+1, nc);
            q.emplace_back(nr, nc-1);
            q.emplace_back(nr, nc+1);
          }
          ++distance;
        }
      };

      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          if (matrix[r][c] == 1) bfs(r, c);
        }
      }
      return matrix;
    }

    // dfs 无法求最值问题

    // 动态规划
    // index = r * cols + c;
    // dp[index] = {1 + min(dp[(r-1)*cols+c], dp[(r+1)*cols+c], dp[r*cols+c-1], dp[r*cols+c+1])   if matrix[i][j] == 1
    //             {0    if matrix[i][j] == 0
    vector<vector<int>> solution2(vector<vector<int>>& matrix) {
      if (matrix.empty()) return matrix;
      int rows = matrix.size(), cols = matrix[0].size();
      vector<vector<int>> dp(rows, vector<int>(cols, 0));
      for (int r = 0; r < rows; ++r)
        for (int c = 0; c < cols; ++c)
          if (matrix[r][c] == 1) dp[r][c] = 10000;

      // 从左上角开始
      for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
          if (r - 1 >= 0) dp[r][c] = min(dp[r][c], dp[r-1][c] + 1);
          if (c - 1 >= 0) dp[r][c] = min(dp[r][c], dp[r][c-1] + 1);
        }
      }
      // 从右下角开始
      for (int r = rows - 1; r >= 0; --r) {
        for (int c = cols - 1; c >= 0; --c) {
          if (r + 1 < rows) dp[r][c] = min(dp[r][c], dp[r+1][c] + 1);
          if (c + 1 < cols) dp[r][c] = min(dp[r][c], dp[r][c+1] +1);
        }
      }
      return dp;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
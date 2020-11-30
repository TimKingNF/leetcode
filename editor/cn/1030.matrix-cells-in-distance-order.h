//给出 R 行 C 列的矩阵，其中的单元格的整数坐标为 (r, c)，满足 0 <= r < R 且 0 <= c < C。 
//
// 另外，我们在该矩阵中给出了一个坐标为 (r0, c0) 的单元格。 
//
// 返回矩阵中的所有单元格的坐标，并按到 (r0, c0) 的距离从最小到最大的顺序排，其中，两单元格(r1, c1) 和 (r2, c2) 之间的距离是曼哈
//顿距离，|r1 - r2| + |c1 - c2|。（你可以按任何满足此条件的顺序返回答案。） 
//
// 
//
// 示例 1： 
//
// 输入：R = 1, C = 2, r0 = 0, c0 = 0
//输出：[[0,0],[0,1]]
//解释：从 (r0, c0) 到其他单元格的距离为：[0,1]
// 
//
// 示例 2： 
//
// 输入：R = 2, C = 2, r0 = 0, c0 = 1
//输出：[[0,1],[0,0],[1,1],[1,0]]
//解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2]
//[[0,1],[1,1],[0,0],[1,0]] 也会被视作正确答案。
// 
//
// 示例 3： 
//
// 输入：R = 2, C = 3, r0 = 1, c0 = 2
//输出：[[1,2],[0,2],[1,1],[0,1],[1,0],[0,0]]
//解释：从 (r0, c0) 到其他单元格的距离为：[0,1,1,2,2,3]
//其他满足题目要求的答案也会被视为正确，例如 [[1,2],[1,1],[0,2],[1,0],[0,1],[0,0]]。
// 
//
// 
//
// 提示： 
//
// 
// 1 <= R <= 100 
// 1 <= C <= 100 
// 0 <= r0 < R 
// 0 <= c0 < C 
// 
// Related Topics 排序 
// 👍 56 👎 0

#include "header.h"

namespace LeetCode1030 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
      return solution1(R, C, r0, c0);
    }

private:
    int r_dis[4] = {1, 0, 0, -1};
    int c_dis[4] = {0, 1, -1, 0};

    // bfs, 优化掉队列
    vector<vector<int>> solution1(int R, int C, int r0, int c0) {
      vector<vector<int>> ans;
      vector<bool> visited(R*C, false);

      ans.push_back({r0, c0});
      visited[r0 * C + c0] = true;

      int k = 0;
      while (ans.size() < visited.size()) {
        int r = ans[k][0], c = ans[k][1];

        for (int i = 0; i < 4; ++i) {
          int n_r = r + r_dis[i];
          int n_c = c + c_dis[i];
          int idx = n_r * C + n_c;
          if (n_r < 0 || n_r >= R || n_c < 0 || n_c >= C) continue;
          if (!visited[idx]) {
            visited[idx] = true;
            ans.push_back({n_r, n_c});
          }
        }
        ++k;  // 从下一个元素开始
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个仅包含 0 和 1 、大小为 rows x cols 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。 
//
// 
//
// 示例 1： 
//
// 
//输入：matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"]
//,["1","0","0","1","0"]]
//输出：6
//解释：最大矩形如上图所示。
// 
//
// 示例 2： 
//
// 
//输入：matrix = []
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：matrix = [["0"]]
//输出：0
// 
//
// 示例 4： 
//
// 
//输入：matrix = [["1"]]
//输出：1
// 
//
// 示例 5： 
//
// 
//输入：matrix = [["0","0"]]
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// rows == matrix.length 
// cols == matrix[0].length 
// 0 <= row, cols <= 200 
// matrix[i][j] 为 '0' 或 '1' 
// 
// Related Topics 栈 数组 哈希表 动态规划 
// 👍 719 👎 0

#include "header.h"

namespace LeetCode85 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
      return solution1(matrix);
    }

    // 采取不断考虑已有矩形的方式
    // O( m^2 * n ), O( mn )
    int solution1(vector<vector<char>>& matrix) {
      if (matrix.empty()) return 0;

      int rows = matrix.size(), cols = matrix[0].size();
      int ans = 0;
      vector<vector<int>> dp(rows, vector<int>(cols));

      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          if (matrix[i][j] == '1') {
            // 当前是第一个元素，则需要单独处理
            if (j == 0) dp[i][j] = 1;
            // 能够构成的矩形 + 1
            else dp[i][j] = dp[i][j-1] + 1;
          } else {  // 中间隔断，无法构成连续矩形
            dp[i][j] = 0;
          }

          if (dp[i][j] == 0) continue;  // 当前无法构成矩形

          int min_width = dp[i][j];  // 当前一行能够成的矩形宽度
          for (int r = i; r >= 0; --r) {
            if (dp[r][j] == 0) break;  // 从当前行往上数，如果为 0 则无需再考虑上面的行
            int height = i - r + 1;
            min_width = min(min_width, dp[r][j]);  // 判断高度最小的矩形
            ans = max(ans, height * min_width);
          }
        }
      }
      return ans;
    }

    // 采取单调栈的做法
    // O( mn ), O( mn )
    int solution2(vector<vector<char>>& matrix) {
      if (matrix.empty()) return 0;
      int rows = matrix.size(), cols = matrix[0].size();
      vector<vector<int>> left(rows, vector<int>(cols, 0));

      // 构建初值, 基于每一行来考虑
      for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
          if (matrix[i][j] == '1')
            left[i][j] = (j == 0 ? 0 : left[i][j-1]) + 1;
        }
      }

      int ans = 0;
      for (int j = 0; j < cols; ++j) {  // 从每一列开始考虑
        vector<int> up(rows), down(rows);
        stack<int> stk;

        // 构建 up 数组
        for (int i = 0; i < rows; ++i) {  // 对于每一行
          while (!stk.empty() && left[stk.top()][j] >= left[i][j]) stk.pop();
          up[i] = stk.empty() ? -1 : stk.top();
          stk.push(i);
        }
        stk = stack<int>();

        // 构建down数组
        for (int i = rows - 1; i >= 0; --i) {
          while (!stk.empty() && left[stk.top()][j] >= left[i][j]) stk.pop();
          down[i] = stk.empty() ? rows : stk.top();
          stk.push(i);
        }

        for (int i = 0; i < rows; ++i) {
          int height = down[i] - up[i] - 1;
          ans = max(ans, height * left[i][j]);
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
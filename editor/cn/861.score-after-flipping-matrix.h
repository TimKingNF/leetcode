//有一个二维矩阵 A 其中每个元素的值为 0 或 1 。 
//
// 移动是指选择任一行或列，并转换该行或列中的每一个值：将所有 0 都更改为 1，将所有 1 都更改为 0。 
//
// 在做出任意次数的移动后，将该矩阵的每一行都按照二进制数来解释，矩阵的得分就是这些数字的总和。 
//
// 返回尽可能高的分数。 
//
// 
//
// 
// 
//
// 示例： 
//
// 输入：[[0,0,1,1],[1,0,1,0],[1,1,0,0]]
//输出：39
//解释：
//转换为 [[1,1,1,1],[1,0,0,1],[1,1,1,1]]
//0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 20 
// 1 <= A[0].length <= 20 
// A[i][j] 是 0 或 1 
// 
// Related Topics 贪心算法 
// 👍 135 👎 0

#include "header.h"

namespace LeetCode861 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
      return solution1(A);
    }

    // 一列一列的比较，取贪心
    int solution1(vector<vector<int>>& A) {
      int rows = A.size(), cols = A[0].size();

      auto changeRows = [&](int r) {
        for (int i = 0; i < cols; ++i) A[r][i] = 1 - A[r][i];
      };

      auto changeCols = [&](int c) {
        for (int i = 0; i < rows; ++i) A[i][c] = 1 - A[i][c];
      };

      // 把第一列不为0，都横向变化
      for (int i = 0; i < rows; ++i) {
        if (A[i][0] == 0) changeRows(i);
      }

      for (int i = 1; i < cols; ++i) {
        int cnt = 0;
        // 遍历这一列，1 多还是 0 多
        for (int j = 0; j < rows; ++j) {
          if (A[j][i] == 1) ++cnt;
        }
        // 如果 0 多，则改变这一列
        if (cnt <= rows/2) changeCols(i);
      }

      int ans = 0;
      for (int i = 0; i < rows; ++i) {
        int number = 0;
        for (int j = 0; j < cols; ++j) {
          number <<= 1;
          number += A[i][j];
        }
        ans += number;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
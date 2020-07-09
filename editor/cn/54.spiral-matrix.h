//给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。 
//
// 示例 1: 
//
// 输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//输出: [1,2,3,6,9,8,7,4,5]
// 
//
// 示例 2: 
//
// 输入:
//[
//  [1, 2, 3, 4],
//  [5, 6, 7, 8],
//  [9,10,11,12]
//]
//输出: [1,2,3,4,8,12,11,10,9,5,6,7]
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode54 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      return solution1(matrix);
    }

    vector<int> solution1(vector<vector<int>>& matrix) {
      if (matrix.empty()) return {};
      int r = matrix.size(), c = matrix[0].size();
      return solution1(matrix, 0, r-1, 0, c-1);
    }

    vector<int> solution1(vector<vector<int>>& matrix, int row_start, int row_end, int col_start, int col_end) {
      if (row_start > row_end || col_start > col_end) return {};
      vector<int> ans;
      // 从左到右
      for (int i = col_start; i <= col_end; ++i) {
        ans.push_back(matrix[row_start][i]);
      }

      if (row_start != row_end) {
        // 从上到下
        for (int i = row_start + 1; i <= row_end; ++i) {
          ans.push_back(matrix[i][col_end]);
        }

        if (col_start != col_end) {
          // 从右到左
          for (int i = col_end - 1; i >= col_start; --i) {
            ans.push_back(matrix[row_end][i]);
          }

          // 从下到上
          for (int i = row_end - 1; i >= row_start +1; --i) {
            ans.push_back(matrix[i][col_start]);
          }
        }
      }
      // 继续内圈
      for (auto v : solution1(matrix, row_start+1, row_end-1, col_start+1, col_end-1)) {
        ans.push_back(v);
      }
      return ans;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
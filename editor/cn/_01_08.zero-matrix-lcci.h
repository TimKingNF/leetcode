//编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。 
//
// 
//
// 示例 1： 
//
// 输入：
//[
//  [1,1,1],
//  [1,0,1],
//  [1,1,1]
//]
//输出：
//[
//  [1,0,1],
//  [0,0,0],
//  [1,0,1]
//]
// 
//
// 示例 2： 
//
// 输入：
//[
//  [0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]
//]
//输出：
//[
//  [0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]
//]
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode_01_08 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      return solution2(matrix);
    }

    // O(M*N) O(M+N)
    void solution1(vector<vector<int>>& matrix) {
      if (matrix.empty()) return;
      int rows = matrix.size(), cols = matrix[0].size();
      vector<int> zero_rows, zero_cols;
      for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
          if (matrix[i][j] == 0) {
            zero_rows.push_back(i);
            zero_cols.push_back(j);
          }
      // 将行置0
      for (int row : zero_rows) for (int j = 0; j < cols; ++j) matrix[row][j] = 0;
      // 将列置0
      for (int col : zero_cols) for (int i = 0; i < rows; ++i) matrix[i][col] = 0;
    }

    // 直接使用原数组的第一行第一列来记录是否对对应的行列需要置0
    // // O(M*N) O(1)
    void solution2(vector<vector<int>>& matrix) {
      if (matrix.empty()) return;
      int rows = matrix.size(), cols = matrix[0].size();
      bool first_zero_col = false;

      for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) first_zero_col = true;  // 第一列需要置0
        for (int j = 1; j < cols; ++j)
          if (matrix[i][j] == 0) {
            matrix[0][j] = 0;  // 在第一行记录 j 列需要置0
            matrix[i][0] = 0;  // 在第一列记录 i 行需要置0
          }
      }
      // 将对应的位置置0
      for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
          if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        }
      }
      // 将第一行置0
      if (matrix[0][0] == 0) for (int j = 0; j < cols; ++j) matrix[0][j] = 0;
      // 将第一列置0
      if (first_zero_col) for (int i = 0; i < rows; ++i) matrix[i][0] = 0;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。 
//
// 示例 1: 
//
// 输入: 
//[
//  [1,1,1],
//  [1,0,1],
//  [1,1,1]
//]
//输出: 
//[
//  [1,0,1],
//  [0,0,0],
//  [1,0,1]
//]
// 
//
// 示例 2: 
//
// 输入: 
//[
//  [0,1,2,0],
//  [3,4,5,2],
//  [1,3,1,5]
//]
//输出: 
//[
//  [0,0,0,0],
//  [0,4,5,0],
//  [0,3,1,0]
//] 
//
// 进阶: 
//
// 
// 一个直接的解决方案是使用 O(mn) 的额外空间，但这并不是一个好的解决方案。 
// 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。 
// 你能想出一个常数空间的解决方案吗？ 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode73 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      solution1(matrix);
    }

    // 借用第一行和第一列来帮助是否需要置0
    void solution1(vector<vector<int>>& matrix) {
      if (matrix.empty()) return;
      int rows = matrix.size(), cols = matrix[0].size();

      bool first_col_zero = false;

      // 只关心从 [1,1] 开始的矩阵
      for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) first_col_zero = true;  // 第一列需要置0
        for (int j = 1; j < cols; ++j) {
          if (matrix[i][j] == 0) {
            matrix[0][j] = 0;  // 在第一行记录对应列需要置0
            matrix[i][0] = 0;  // 在第一列记录对应行需要置0
          }
        }
      }

      for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
          if (matrix[0][j] == 0 || matrix[i][0] == 0) matrix[i][j] = 0;
        }
      }
      // 将第一行置0
      if (matrix[0][0] == 0) for (int j = 0; j < cols; ++j) matrix[0][j] = 0;
      // 将第一列置0
      if (first_col_zero) for (int i = 0; i < rows; ++i) matrix[i][0] = 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
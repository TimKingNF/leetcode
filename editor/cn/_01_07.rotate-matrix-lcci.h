//给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。 
//
// 不占用额外内存空间能否做到？ 
//
// 
//
// 示例 1: 
//
// 给定 matrix = 
//[
//  [1,2,3],
//  [4,5,6],
//  [7,8,9]
//],
//
//原地旋转输入矩阵，使其变为:
//[
//  [7,4,1],
//  [8,5,2],
//  [9,6,3]
//]
// 
//
// 示例 2: 
//
// 给定 matrix =
//[
//  [ 5, 1, 9,11],
//  [ 2, 4, 8,10],
//  [13, 3, 6, 7],
//  [15,14,12,16]
//], 
//
//原地旋转输入矩阵，使其变为:
//[
//  [15,13, 2, 5],
//  [14, 3, 4, 1],
//  [12, 6, 8, 9],
//  [16, 7,10,11]
//]
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode_01_07 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    // TODO
    void rotate(vector<vector<int>>& matrix) {
      return solution2(matrix);
    }

    // 旋转90度之后，矩阵中第 i 行的第 j 个元素，它会出现在倒数第 i 列的第 j 个位置。
    void solution1(vector<vector<int>>& matrix) {
       if (matrix.empty()) return;
       int n = matrix.size(), temp;
       // 需要旋转的为左上角 高为 n / 2, 宽为 n + 1 / 2 的子矩阵
       for (int i = 0; i < n / 2; ++i) {
         for (int j = 0; j < (n + 1) / 2; ++j) {
           temp = matrix[i][j];
           matrix[i][j] = matrix[n - j - 1][i];
           matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
           matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
           matrix[j][n - i - 1] = temp;
         }
       }
    }

    // 沿着水平中间轴交换元素，再沿斜对角线交换，即为旋转90度
    void solution2(vector<vector<int>>& matrix) {
      if (matrix.empty()) return;
      int n = matrix.size();
      // 沿着水平中间轴交换元素
      for (int i = 0; i < n / 2; ++i) {
        for (int j = 0; j < n; ++j) {
          swap(matrix[i][j], matrix[n-i-1][j]);
        }
      }
      // 沿着对角线交换
      for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
          swap(matrix[i][j], matrix[j][i]);
        }
      }
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
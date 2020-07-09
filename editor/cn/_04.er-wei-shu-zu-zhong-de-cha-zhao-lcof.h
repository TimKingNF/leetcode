//在一个 n * m 的二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
//判断数组中是否含有该整数。 
//
// 
//
// 示例: 
//
// 现有矩阵 matrix 如下： 
//
// [
//  [1,   4,  7, 11, 15],
//  [2,   5,  8, 12, 19],
//  [3,   6,  9, 16, 22],
//  [10, 13, 14, 17, 24],
//  [18, 21, 23, 26, 30]
//]
// 
//
// 给定 target = 5，返回 true。 
//
// 给定 target = 20，返回 false。 
//
// 
//
// 限制： 
//
// 0 <= n <= 1000 
//
// 0 <= m <= 1000 
//
// 
//
// 注意：本题与主站 240 题相同：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/ 
// Related Topics 数组 双指针

#include "header.h"

namespace LeetCode_04 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
      return solution1(matrix, target);
    }

    // 利用本身就有序的功能，从右上角开始定位，逐渐缩小范围
    bool solution1(vector<vector<int>>& matrix, int target) {
      if (matrix.size() == 0 || matrix[0].size() == 0)
        return false;

      int r = matrix.size(), c = matrix[0].size();
      int i = 0, j = c - 1;
      while (i < r && j >= 0) {
        if (matrix[i][j] == target) return true;
        else if (matrix[i][j] > target) --j;
        else ++i;
      }
      return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
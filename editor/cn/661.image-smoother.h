//包含整数的二维矩阵 M 表示一个图片的灰度。你需要设计一个平滑器来让每一个单元的灰度成为平均灰度 (向下舍入) ，平均灰度的计算是周围的8个单元和它本身的值
//求平均，如果周围的单元格不足八个，则尽可能多的利用它们。 
//
// 示例 1: 
//
// 
//输入:
//[[1,1,1],
// [1,0,1],
// [1,1,1]]
//输出:
//[[0, 0, 0],
// [0, 0, 0],
// [0, 0, 0]]
//解释:
//对于点 (0,0), (0,2), (2,0), (2,2): 平均(3/4) = 平均(0.75) = 0
//对于点 (0,1), (1,0), (1,2), (2,1): 平均(5/6) = 平均(0.83333333) = 0
//对于点 (1,1): 平均(8/9) = 平均(0.88888889) = 0
// 
//
// 注意: 
//
// 
// 给定矩阵中的整数范围为 [0, 255]。 
// 矩阵的长和宽的范围均为 [1, 150]。 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode661 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
      return solution1(M);
    }

    vector<vector<int>> solution1(vector<vector<int>>& M) {
      int r = M.size(), c = M[0].size();  // 取出矩阵的大小
      vector<vector<int>> res(r, vector<int>(c));  // 初始化结果矩阵
      int sum, count;
      int left_top_r, left_top_c;  // 遍历点的左上角点
      for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
          sum = 0, count = 0;  // 重置值和计数器
          // 遍历矩阵元素周围的格子
          for (int k = 0; k < 9; ++k) {
            left_top_r = i - 1 + k / 3;
            left_top_c = j - 1 + k % 3;
            if (left_top_r >= 0 && left_top_r < r && left_top_c >= 0 && left_top_c < c) {
              sum += M[left_top_r][left_top_c];
              ++count;
            }
          }
          res[i][j] = sum / count;
        }
      }
      return res;
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
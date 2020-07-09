//在MATLAB中，有一个非常有用的函数 reshape，它可以将一个矩阵重塑为另一个大小不同的新矩阵，但保留其原始数据。 
//
// 给出一个由二维数组表示的矩阵，以及两个正整数r和c，分别表示想要的重构的矩阵的行数和列数。 
//
// 重构后的矩阵需要将原始矩阵的所有元素以相同的行遍历顺序填充。 
//
// 如果具有给定参数的reshape操作是可行且合理的，则输出新的重塑矩阵；否则，输出原始矩阵。 
//
// 示例 1: 
//
// 
//输入: 
//nums = 
//[[1,2],
// [3,4]]
//r = 1, c = 4
//输出: 
//[[1,2,3,4]]
//解释:
//行遍历nums的结果是 [1,2,3,4]。新的矩阵是 1 * 4 矩阵, 用之前的元素值一行一行填充新矩阵。
// 
//
// 示例 2: 
//
// 
//输入: 
//nums = 
//[[1,2],
// [3,4]]
//r = 2, c = 4
//输出: 
//[[1,2],
// [3,4]]
//解释:
//没有办法将 2 * 2 矩阵转化为 2 * 4 矩阵。 所以输出原矩阵。
// 
//
// 注意： 
//
// 
// 给定矩阵的宽和高范围在 [1, 100]。 
// 给定的 r 和 c 都是正数。 
// 
// Related Topics 数组

#include "header.h"

namespace LeetCode566 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
      return solution2(nums, r, c);
    }

    vector<vector<int>> solution1(vector<vector<int>>& nums, int r, int c) {
      // 原矩阵大小
      int origR = nums.size(), origC = nums[0].size();
      // 判断是否可以转化为新矩阵
      if (origR * origC != r * c) return nums;

      vector<vector<int>> res;
      vector<int> row;
      for (int i = 0; i < origR; ++i) {
        for (int j = 0; j < origC; ++j) {
          row.push_back(nums[i][j]);
          if (row.size() == c) {
            res.push_back(vector<int>(row.begin(), row.end()));
            row.clear();
          }
        }
      }
      return res;
    }

    vector<vector<int>> solution2(vector<vector<int>>& nums, int r, int c) {
      // 原矩阵大小
      int origR = nums.size(), origC = nums[0].size();
      // 判断是否可以转化为新矩阵
      if (origR * origC != r * c) return nums;

      vector<vector<int>> res(r, vector<int>(c));  // 预先初始化完毕
      int count = 0, newR, newC;
      for (int i = 0; i < origR; ++i) {
        for (int j = 0; j < origC; ++j) {
          newR = int(count / c);
          newC = count % c;
          res[newR][newC] = nums[i][j];
          ++count;
        }
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
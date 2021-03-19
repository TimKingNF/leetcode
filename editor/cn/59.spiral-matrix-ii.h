//给你一个正整数 n ，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。 
//
// 
//
// 示例 1： 
//
// 
//输入：n = 3
//输出：[[1,2,3],[8,9,4],[7,6,5]]
// 
//
// 示例 2： 
//
// 
//输入：n = 1
//输出：[[1]]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 20 
// 
// Related Topics 数组 
// 👍 337 👎 0

#include "header.h"

namespace LeetCode59 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      return solution1(n);
    }

    vector<vector<int>> solution1(int n) {
      vector<vector<int>> ans(n, vector<int>(n, -1));  // n * n
      int left_hand = 0, right_hand = n-1, top_hand = 0, bottom_hand = n-1;

      int k = 1;
      while (left_hand <= right_hand && top_hand <= bottom_hand) {
        // 从左到右
        for (int i = left_hand; i <= right_hand; ++i) {
          ans[top_hand][i] = k++;
        }
        // 从上到下
        if (top_hand != bottom_hand) {
          for (int i = top_hand+1; i <= bottom_hand; ++i) {
            ans[i][right_hand] = k++;
          }

          if (left_hand != right_hand) {
            // 从右到左
            for (int i = right_hand-1; i >= left_hand; --i) {
              ans[bottom_hand][i] = k++;
            }
            // 从下到上
            for (int i = bottom_hand-1; i > top_hand; --i) {
              ans[i][left_hand] = k++;
            }
          }
        }
        left_hand++;
        right_hand--;
        top_hand++;
        bottom_hand--;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
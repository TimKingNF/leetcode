//给定一个 n x n 矩阵，其中每行和每列元素均按升序排序，找到矩阵中第 k 小的元素。 
//请注意，它是排序后的第 k 小元素，而不是第 k 个不同的元素。 
//
// 
//
// 示例： 
//
// matrix = [
//   [ 1,  5,  9],
//   [10, 11, 13],
//   [12, 13, 15]
//],
//k = 8,
//
//返回 13。
// 
//
// 
//
// 提示： 
//你可以假设 k 的值永远是有效的，1 ≤ k ≤ n2 。 
// Related Topics 堆 二分查找

#include "header.h"

namespace LeetCode378 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
      return solution2(matrix, k);
    }

    // 堆
    // O( N * logN )
    int solution1(vector<vector<int>>& matrix, int k) {
      int rows = matrix.size(), cols = matrix[0].size();
      k = rows * cols - k + 1;  // 第k小，反过来就是第 n - k + 1 大
      priority_queue<int, vector<int>, greater<>> pq;  // 最小堆
      for (int r = 0; r < matrix.size(); ++r) {
        for (int c = 0; c < matrix[0].size(); ++c) {
          if (pq.size() < k) {
            pq.push(matrix[r][c]);
          } else {
            if (matrix[r][c] > pq.top()) {
              pq.push(matrix[r][c]);
              pq.pop();
            }
          }
        }
      }
      return pq.top();
    }

    // 二分解法
    int solution2(vector<vector<int>>& matrix, int k) {
      int n = matrix.size();
      int left = matrix[0][0], right = matrix[n-1][n-1];
      while (left < right) {
        int mid = left + (right - left) / 2;
        if (check(matrix, mid, k, n)) {
          // 返回 true 说明左板块数量大于 k, 因为是第k小，所以该元素在左板块
          right = mid;
        } else {
          left = mid + 1;
        }
      }
      return left;
    }

    bool check(vector<vector<int>>& matrix, int mid, int k, int n) {
      int i = n - 1, j = 0, count = 0;
      // 从左下角点出发, 往上计算左板块的数量
      while (i >= 0 && j < n) {
        if (matrix[i][j] <= mid) {  // 说明以 i,j 为右下角点的区域都小于 mid
          count += i + 1;  // 加上本列的数量
          j++;  // 计算下一列
        } else {
          i--;
        }
      }
      return count >= k;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
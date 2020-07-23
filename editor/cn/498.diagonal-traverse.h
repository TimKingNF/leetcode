//给定一个含有 M x N 个元素的矩阵（M 行，N 列），请以对角线遍历的顺序返回这个矩阵中的所有元素，对角线遍历如下图所示。 
//
// 
//
// 示例: 
//
// 输入:
//[
// [ 1, 2, 3 ],
// [ 4, 5, 6 ],
// [ 7, 8, 9 ]
//]
//
//输出:  [1,2,4,7,5,3,6,8,9]
//
//解释:
//
// 
//
// 
//
// 说明: 
//
// 
// 给定矩阵中的元素总数不会超过 100000 。 
// 
//

#include "header.h"

namespace LeetCode498 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
      return solution3(matrix);
    }

    vector<int> solution1(vector<vector<int>>& matrix) {
      if (matrix.empty()) return {};
      int order = 0;  // 表示正序还是逆序, 0 表示从下到上的逆序
      int rows = matrix.size(), cols = matrix[0].size();
      vector<int> ans, tmp;
      // 遍历从 (0,0) - (0,cols-1)
      for (int c = 0; c < cols; ++c) {
        tmp.clear();
        for (int r = 0, cc = c; r < rows && cc >= 0; ++r, --cc) {
          tmp.push_back(matrix[r][cc]);
        }
        if (order == 1) ans.insert(ans.end(), tmp.begin(), tmp.end());
        else ans.insert(ans.end(), tmp.rbegin(), tmp.rend());
        order = 1 - order;
      }
      // 遍历从 (1,cols-1) - (rows-1,cols-1)
      for (int r = 1; r < rows; ++r) {
        tmp.clear();
        for (int rr = r, cc = cols-1; rr < rows && cc >= 0; ++rr, --cc) {
          tmp.push_back(matrix[rr][cc]);
        }
        if (order == 1) ans.insert(ans.end(), tmp.begin(), tmp.end());
        else ans.insert(ans.end(), tmp.rbegin(), tmp.rend());
        order = 1 - order;
      }
      return ans;
    }

    // 由方法一简化而来，将第一行和第一列视为同一行，确定起始元素即可
    vector<int> solution2(vector<vector<int>>& matrix) {
      if (matrix.empty()) return {};
      int rows = matrix.size(), cols = matrix[0].size(), order = 0;
      vector<int> ans, tmp;
      for (int i = 0, r, c; i < rows + cols - 1; ++i) {
        tmp.clear();
        r = i < cols ? 0 : i - cols + 1;
        c = i < cols ? i : cols - 1;
        for (; r < rows && c >= 0; ++r, --c) tmp.push_back(matrix[r][c]);
        if (order == 1) ans.insert(ans.end(), tmp.begin(), tmp.end());
        else ans.insert(ans.end(), tmp.rbegin(), tmp.rend());
        order = 1 - order;
      }
      return ans;
    }

    vector<int> solution3(vector<vector<int>>& matrix) {
      if (matrix.empty()) return {};
      int rows = matrix.size(), cols = matrix[0].size(), i = 0, r, c;
      vector<int> ans(rows*cols);
      int x = 0;  // x = r + c
      while (x < rows + cols - 1) {
        r = x < rows ? x : rows - 1;  // 逆序的时候，r 取较大值
        c = x - r;
        while (r >= 0 && c < cols) ans[i++] = matrix[r--][c++];

        if (++x >= rows + cols) break;

        c = x < cols ? x : cols - 1;  // 正序的时候，c 取较大值
        r = x - c;
        while (r < rows && c >= 0) ans[i++] = matrix[r++][c--];
        ++x;
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
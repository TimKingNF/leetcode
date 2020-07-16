//给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 5
//输出:
//[
//     [1],
//    [1,1],
//   [1,2,1],
//  [1,3,3,1],
// [1,4,6,4,1]
//] 
// Related Topics 数组

#include "header.h"

namespace LeetCode118 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      return solution2(numRows);
    }

    // O(n^2)
    vector<vector<int>> solution1(int numRows) {
      vector<vector<int>> res;
      vector<int> tmp(numRows, 1);
      int n = 1;
      while (n <= numRows) {
        for (int i = 1; i < n-1; ++i) {
          tmp[i] = res[n-2][i-1] + res[n-2][i];
        }
        res.push_back(vector<int>(tmp.begin(), tmp.begin()+n));
        ++n;
      }
      return res;
    }

    vector<vector<int>> solution2(int numRows) {
      vector<vector<int>> ans;
      vector<int> line;
      long x;
      for (int n = 0; n < numRows; ++n) {
        x = 1;
        line.push_back(x);
        for (int i = 1; i <= n; ++i) {  // 一共有n+1个元素, 所以是 i <= n
          x = x * (n - i + 1) / i;   // 由杨辉三角的同项公式得 每一项是前一项的 (n-i)/(i+1) 倍 (这里的i是前一项)
          line.push_back(x);
        }
        ans.push_back(line);
        line.clear();
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
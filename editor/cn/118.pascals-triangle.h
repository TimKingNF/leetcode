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
};
//leetcode submit region end(Prohibit modification and deletion)

}
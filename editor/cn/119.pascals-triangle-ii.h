//给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。 
//
// 
//
// 在杨辉三角中，每个数是它左上方和右上方的数的和。 
//
// 示例: 
//
// 输入: 3
//输出: [1,3,3,1]
// 
//
// 进阶： 
//
// 你可以优化你的算法到 O(k) 空间复杂度吗？ 
// Related Topics 数组

#include "header.h"

namespace LeetCode119 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
      return solution2(rowIndex);
    }

    // O(n^2)
    vector<int> solution1(int rowIndex) {
      vector<int> tmp(rowIndex+1);
      tmp[rowIndex] = 1;

      for (int i = 0; i <= rowIndex; ++i) {  // 从第一行开始
        // j 指针从倒数第二项开始算起，一直到大于 i - 1
        for (int j = rowIndex - 1; j > i - 1; --j) {
          tmp[j] = tmp[j] + tmp[j+1];
        }
      }
      return tmp;
    }

    // O(n)
    // 可以通过公式，推导出每一项是前一项的 (n-i) / (i+1) 倍
    vector<int> solution2(int rowIndex) {
      vector<int> res(rowIndex+1);
      long v;
      res[0] = 1;
      for (int i = 1; i <= rowIndex; ++i) {
        // 因为是前一项，故此时公式中取 i-1
        v = long(res[i-1]) * (rowIndex - i + 1) / i;  // 避免int溢出
        res[i] = v;
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
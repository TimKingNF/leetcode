//给定一个整数数组 A，如果它是有效的山脉数组就返回 true，否则返回 false。 
//
// 让我们回顾一下，如果 A 满足下述条件，那么它是一个山脉数组： 
//
// 
// A.length >= 3 
// 在 0 < i < A.length - 1 条件下，存在 i 使得：
// 
// A[0] < A[1] < ... A[i-1] < A[i] 
// A[i] > A[i+1] > ... > A[A.length - 1] 
// 
// 
// 
//
// 
//
// 
//
// 
//
// 示例 1： 
//
// 输入：[2,1]
//输出：false
// 
//
// 示例 2： 
//
// 输入：[3,5,5]
//输出：false
// 
//
// 示例 3： 
//
// 输入：[0,3,2,1]
//输出：true 
//
// 
//
// 提示： 
//
// 
// 0 <= A.length <= 10000 
// 0 <= A[i] <= 10000 
// 
//
// 
//
// 
// Related Topics 数组 
// 👍 94 👎 0

#include "header.h"

namespace LeetCode941 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool validMountainArray(vector<int>& A) {
      return solution1(A);
    }

    // 有且只存在一个最高点
    bool solution1(vector<int>& A) {
      if (A.size() < 3) return false;
      int i = 0, n = A.size();
      bool inc = false, dec = false;
      // 先连续递增
      while (i + 1 < n && A[i] < A[i+1]) {
        inc = true;
        ++i;
      }
      // 或者在这里先判断 最高点不能是数组的第一个位置或最后一个位置
      // 再连续递减
      while (i + 1 < n && A[i] > A[i+1]) {
        dec = true;
        ++i;
      }
      return inc && dec && i == n - 1;  // 遍历到最后，i 是最后一个元素
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
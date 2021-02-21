//当 A 的子数组 A[i], A[i+1], ..., A[j] 满足下列条件时，我们称其为湍流子数组： 
//
// 
// 若 i <= k < j，当 k 为奇数时， A[k] > A[k+1]，且当 k 为偶数时，A[k] < A[k+1]； 
// 或 若 i <= k < j，当 k 为偶数时，A[k] > A[k+1] ，且当 k 为奇数时， A[k] < A[k+1]。 
// 
//
// 也就是说，如果比较符号在子数组中的每个相邻元素对之间翻转，则该子数组是湍流子数组。 
//
// 返回 A 的最大湍流子数组的长度。 
//
// 
//
// 示例 1： 
//
// 输入：[9,4,2,10,7,8,8,1,9]
//输出：5
//解释：(A[1] > A[2] < A[3] > A[4] < A[5])
// 
//
// 示例 2： 
//
// 输入：[4,8,12,16]
//输出：2
// 
//
// 示例 3： 
//
// 输入：[100]
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 40000 
// 0 <= A[i] <= 10^9 
// 
// Related Topics 数组 动态规划 Sliding Window 
// 👍 142 👎 0

#include "header.h"

namespace LeetCode978 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
      return solution1(arr);
    }

    int solution1(vector<int>& arr) {
      int n = arr.size();

      auto solution1core = [&](int greater) {
        int maxLen = 0;
        for (int i = 0, j = 0; j < n; ++j) {
          // 满足条件的两种情况
          // greater && arr[j] > arr[j+1]
          // !greater && arr[j] < arr[j+1]
          if (j == n-1
              || (greater && arr[j] <= arr[j+1])
              || (!greater && arr[j] >= arr[j+1])) {  // 不满足条件
            maxLen = max(maxLen, j - i + 1);
            i = j + 1;  // 取当前 j 的下一个，因为当前 j 无法满足, 所以 i 取新的起点
          }
          greater = 1-greater;
        }
        return maxLen;
      };

      // 考虑两种插入的方式
      int lessMaxLen = solution1core(0);
      int greaterMaxLen = solution1core(1);
      return max(lessMaxLen, greaterMaxLen);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
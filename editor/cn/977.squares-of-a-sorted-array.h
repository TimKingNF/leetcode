//给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。 
//
// 
//
// 示例 1： 
//
// 输入：[-4,-1,0,3,10]
//输出：[0,1,9,16,100]
// 
//
// 示例 2： 
//
// 输入：[-7,-3,2,3,11]
//输出：[4,9,9,49,121]
// 
//
// 
//
// 提示： 
//
// 
// 1 <= A.length <= 10000 
// -10000 <= A[i] <= 10000 
// A 已按非递减顺序排序。 
// 
// Related Topics 数组 双指针 
// 👍 153 👎 0

#include "header.h"

namespace LeetCode977 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
      return solution2(A);
    }

    vector<int> solution1(vector<int>& A) {
      int n = A.size();
      vector<int> ans(n);

      int l = 0, r = n -1;
      for (int i = n-1; i >= 0; --i) {
        int l_square = A[l] * A[l];
        int r_square = A[r] * A[r];
        if (l_square > r_square) {
          ans[i] = l_square;
          l++;
        } else {
          ans[i] = r_square;
          r--;
        }
      }
      return ans;
    }

    // 减少乘法的次数
    vector<int> solution2(vector<int>& A) {
      int n = A.size();
      vector<int> ans(n);

      int l = 0, r = n -1;
      int pre = 0;
      int pre_square = A[l] * A[l], next_square;

      for (int i = n-1; i >= 0; --i) {
        // 根据上一个标志位, 决定下一个标志位是取左还是右
        next_square = pre ? A[l] * A[l] : A[r] * A[r];
        if (pre_square > next_square) {
          ans[i] = pre_square;
          pre_square = next_square;
          if (pre) {
            r--;  // 上次是右，本次取右
            pre = 0;  // 记录上一个未比较的数是左边的
          }
          else {
            l++;  // 上次是左，本次取左
            pre = 1;
          }
        } else {
          ans[i] = next_square;
          if (pre) l++;
          else r--;

          // pre_square 还是取原来方向上的元素，所以不用动 pre
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
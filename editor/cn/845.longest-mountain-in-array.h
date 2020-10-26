//我们把数组 A 中符合下列属性的任意连续子数组 B 称为 “山脉”： 
//
// 
// B.length >= 3 
// 存在 0 < i < B.length - 1 使得 B[0] < B[1] < ... B[i-1] < B[i] > B[i+1] > ... > B
//[B.length - 1] 
// 
//
// （注意：B 可以是 A 的任意子数组，包括整个数组 A。） 
//
// 给出一个整数数组 A，返回最长 “山脉” 的长度。 
//
// 如果不含有 “山脉” 则返回 0。 
//
// 
//
// 示例 1： 
//
// 输入：[2,1,4,7,3,2,5]
//输出：5
//解释：最长的 “山脉” 是 [1,4,7,3,2]，长度为 5。
// 
//
// 示例 2： 
//
// 输入：[2,2,2]
//输出：0
//解释：不含 “山脉”。
// 
//
// 
//
// 提示： 
//
// 
// 0 <= A.length <= 10000 
// 0 <= A[i] <= 10000 
// 
// Related Topics 双指针 
// 👍 85 👎 0

#include "header.h"

namespace LeetCode845 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
 public:
  int longestMountain(vector<int>& A) {
    return solution2(A);
  }

  // 双指针
  // 数组中要先满足连续递增，再满足连续递减
  // O( N ), O( 1 )
  int solution1(vector<int>& A) {
    int start = 0, n = A.size();
    int i = 0;
    int ans = 0;

    while (i < n) {
      bool inc = false, dec = false;
      // 先连续递增
      while (i+1 < n && A[i] < A[i+1]) {
        inc = true;
        ++i;
      }
      // 再连续递减
      while (i+1 < n && A[i] > A[i+1]) {
        dec = true;
        ++i;
      }
      if (inc && dec) {
        ans = max(i - start + 1, ans);  // 求得最大长度
      } else if (!inc && !dec) {
        ++i;  // 说明前后两个数相同，则直接 ++i
      }
      start = i;
    }
    return ans;
  }

  // 利用递增和递减的特性，简化一下
  // O( 3N ), O( 2N )
  int solution2(vector<int>& A) {
    int n = A.size();
    if (n < 3) return 0;  // 必不可能有山脉

    int inc[n], dec[n];
    fill(inc, inc+n, 1);
    fill(dec, dec+n, 1);

    // 从左到右记录以这个数为结尾的最长连续递增序列长度
    for (int i = 1; i < n; ++i) {
      if (A[i] > A[i-1]) inc[i] = inc[i-1] + 1;
    }

    // 从右到左记录以这个数为结尾的最长连续递增序列长度
    // 相当于记录从左到右，以 i 为起点的最长连续递减序列长度
    for (int i = n-2; i >= 0; --i) {
      if (A[i] > A[i+1]) dec[i] = dec[i+1] +1;
    }

    int ans = 0;
    for (int i = 1; i < n-1; ++i) {
      if (inc[i] > 1 && dec[i] > 1) ans = max(ans, inc[i] + dec[i] - 1);  // 计算最大长度
    }
    return ans;
  }
};
//leetcode submit region end(Prohibit modification and deletion)

}
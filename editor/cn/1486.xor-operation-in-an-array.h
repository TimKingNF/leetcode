//给你两个整数，n 和 start 。 
//
// 数组 nums 定义为：nums[i] = start + 2*i（下标从 0 开始）且 n == nums.length 。 
//
// 请返回 nums 中所有元素按位异或（XOR）后得到的结果。 
//
// 
//
// 示例 1： 
//
// 输入：n = 5, start = 0
//输出：8
//解释：数组 nums 为 [0, 2, 4, 6, 8]，其中 (0 ^ 2 ^ 4 ^ 6 ^ 8) = 8 。
//     "^" 为按位异或 XOR 运算符。
// 
//
// 示例 2： 
//
// 输入：n = 4, start = 3
//输出：8
//解释：数组 nums 为 [3, 5, 7, 9]，其中 (3 ^ 5 ^ 7 ^ 9) = 8. 
//
// 示例 3： 
//
// 输入：n = 1, start = 7
//输出：7
// 
//
// 示例 4： 
//
// 输入：n = 10, start = 5
//输出：2
// 
//
// 
//
// 提示： 
//
// 
// 1 <= n <= 1000 
// 0 <= start <= 1000 
// n == nums.length 
// 
// Related Topics 位运算 数组

#include "header.h"

namespace LeetCode1486 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int xorOperation(int n, int start) {
      return solution2(n, start);
    }

    // 暴力法
    int solution1(int n, int start) {
      int ans = start;
      while (--n > 0) {
        start += 2;
        ans ^= start;
      }
      return ans;
    }

    // O(1)
    // 有 2x ^ 2x+1 = 1
    // 则对于 X ^ (X + 2) ^ (X + 4) ^ ... ^ (X + 2(n-1)), X = start
    // 可得 Y = [ X/2 ^ (X/2 + 1) ^ (X/2 +2) ^ ... ^ (X/2 + n-1) ], 记为 fn(n, start)
    // 说明对于 n 和 start, 可以计算出 结果右移一位的值, 即 ans / 2, 该值取决于 n 的 奇偶 和 start 的奇偶
    // 若 start/2 为 偶数
    // 如果 n 为偶数，则 Y 等于 n/2 个 1 异或, 即 Y/2 = n/2 & 1
    // 如果 n 为奇数，则 Y 等于 n/2 个 1 异或 再异或 (X/2 + n-1) 即 Y = (n/2 & 1) ^ (X/2 + n-1)
    // 若 start/2 为 奇数
    // 则可以在 Y 上再添加一个数 （X/2-1) 得到 Y', 则 Y' = fn(n+1, start-1), 再 ^(X/2 - 1) 即可消去刚刚添加的值得 Y
    //
    // 而对于 Y 以外的最后一位 Z ，则取决于 n 和 start 的奇偶
    // 如果 start 为 偶数，则 Z 必为 0
    // 如果 start 为奇数，n 为 偶数，则 Z 也为 0， 其余情况则 Z 为 1
    int solution2(int n, int start) {
      int ans;
      if ((start/2) & 1)
        ans = (start/2 - 1) ^ solution2core(n+1, start/2 - 1);
      else
        ans = solution2core(n, start / 2);
      ans <<= 1;
      return (n & start & 1) ? ans + 1 : ans;
    }

    int solution2core(int n, int start) {
      return (n & 1) ? (n/2 & 1) ^ (start + n - 1) : (n/2 & 1);
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个非负整数 num。对于 0 ≤ i ≤ num 范围中的每个数字 i ，计算其二进制数中的 1 的数目并将它们作为数组返回。 
//
// 示例 1: 
//
// 输入: 2
//输出: [0,1,1] 
//
// 示例 2: 
//
// 输入: 5
//输出: [0,1,1,2,1,2] 
//
// 进阶: 
//
// 
// 给出时间复杂度为O(n*sizeof(integer))的解答非常容易。但你可以在线性时间O(n)内用一趟扫描做到吗？ 
// 要求算法的空间复杂度为O(n)。 
// 你能进一步完善解法吗？要求在C++或任何其他语言中不使用任何内置函数（如 C++ 中的 __builtin_popcount）来执行此操作。 
// 
// Related Topics 位运算 动态规划 
// 👍 576 👎 0

#include "header.h"

namespace LeetCode338 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<int> countBits(int num) {
      return solution1(num);
    }

    vector<int> solution1(int num) {
      vector<int> dp(num+1, 0);

      // base
      for (int i = 1; i <= num; i <<= 1) {
        dp[i] = 1;
      }

      // 向下取2进制整
      auto getCeil = [](int n) {
        int cnt = 0;
        while (n != 1) {
          n >>= 1;
          ++cnt;
        }
        while (cnt-- > 0) {
          n <<= 1;
        }
        return n;
      };

      for (int i = 3; i <= num; ++i) {
        // 每个数都可以拆解为，最高位的 1 和 余下的数字
        if (dp[i] == 0) dp[i] = 1 + dp[i - getCeil(i)];
      }
      return dp;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
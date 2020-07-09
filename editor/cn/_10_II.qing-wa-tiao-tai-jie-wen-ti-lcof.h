//一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。 
//
// 答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。 
//
// 示例 1： 
//
// 输入：n = 2
//输出：2
// 
//
// 示例 2： 
//
// 输入：n = 7
//输出：21
// 
//
// 提示： 
//
// 
// 0 <= n <= 100 
// 
//
// 注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/ 
//
// 
// Related Topics 递归

#include "header.h"

namespace LeetCode_10_II {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numWays(int n) {
      if (n == 0) return 1;
      if (n <= 2) return n;

      // f(n) = f(n-1) + f(n-2)
      int dp[2];
      dp[0] = 2;  // 第二级
      dp[1] = 1;  // 第一级

      int x, y;
      for (int i = 3; i <= n; ++i) {
        x = i % 2;
        y = (i-1) % 2;
        dp[x] = (dp[y] + dp[x]) % 1000000007;
      }
      return n % 2 == 0 ? dp[0] : dp[1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
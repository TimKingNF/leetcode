//给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。 
//
// 
//
// 示例 1: 
//输入: 
//
// "bbbab"
// 
//
// 输出: 
//
// 4
// 
//
// 一个可能的最长回文子序列为 "bbbb"。 
//
// 示例 2: 
//输入: 
//
// "cbbd"
// 
//
// 输出: 
//
// 2
// 
//
// 一个可能的最长回文子序列为 "bb"。 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 1000 
// s 只包含小写英文字母 
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode516 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
      return solution2(s);
    }

    int solution1(string s) {
      int n = s.size();
      // 维度 i,j 表示从 i 到 j 的最长回文子串长度
      vector<vector<int>> dp(n, vector<int>(n, 0));
      // base case, 对角线必为回文串，长度为1
      for (int i = 0; i < n; ++i) dp[i][i] = 1;

      // 中心扩散的递推
      // 已知 dp[i+1][j-1], 如果 s[i] == s[j] 那么 dp[i][j] = dp[i+1][j-1] + 2
      // 否则 dp[i][j] 就在 s[i,j-1] 和 s[i+1,j] 两段中取最大值

      // 需要反向遍历
      for (int i = n - 2; i >= 0; --i) {  // 因为 dp[n-1][n-1] 已知
        for (int j = i + 1; j < n; j++) {  // 只计算对角线右侧即可
          if (s[i] == s[j]) dp[i][j] = dp[i+1][j-1] + 2;
          else dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
        }
      }
      return dp[0][n-1];
    }

    // 在 solution1 的基础上做空间优化
    int solution2(string s) {
      int n = s.size();
      vector<int> dp(n, 1);
      for (int i = n - 2; i >= 0; --i) {
        int last = 0;  // 初值为 0
        for (int j = i + 1; j < n; ++j) {
          int tmp = dp[j];
          if (s[i] == s[j]) dp[j] = last + 2;
          else dp[j] = max(dp[j], dp[j-1]);
          last = tmp;  // 作为下次循环的 上一行 j-1 出现
        }
      }
      return dp[n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
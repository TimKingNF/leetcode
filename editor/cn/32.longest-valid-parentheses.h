//给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。 
//
// 
//
// 
// 
// 示例 1： 
//
// 
//输入：s = "(()"
//输出：2
//解释：最长有效括号子串是 "()"
// 
//
// 示例 2： 
//
// 
//输入：s = ")()())"
//输出：4
//解释：最长有效括号子串是 "()()"
// 
//
// 示例 3： 
//
// 
//输入：s = ""
//输出：0
// 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length <= 3 * 104 
// s[i] 为 '(' 或 ')' 
// 
// 
// 
// Related Topics 字符串 动态规划 
// 👍 1181 👎 0

#include "header.h"

namespace LeetCode32 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestValidParentheses(string s) {
      return solution1(s);
    }

    // DP
    int solution1(string s) {
      int n = s.size();
      if (n < 2) return 0;

      int ans = INT32_MIN, pre = 0;
      int dp[n];
      fill(dp, dp+n, 0);

      for (int i = 1; i < n; ++i) {
        // s[i] == '(' 自然不用考虑
        if (s[i] == ')') {
          pre = i - dp[i-1] - 1;
          // 这里是考虑到，如果 dp[i-1] 能构成括号，且 pre 为 (, 则可以与 i 凑成一对，长度为 dp[i-1]+2
          // 在考虑 pre 之前的情况，合并起来
          if (pre >= 0 && s[pre] == '(') {
            dp[i] = dp[i-1] + 2 + (pre > 0 ? dp[pre-1] : 0);
          }
        }
        ans = max(ans, dp[i]);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
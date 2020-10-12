//给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。 
//
// '.' 匹配任意单个字符
//'*' 匹配零个或多个前面的那一个元素
// 
//
// 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。 
//
// 说明: 
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。 
// 
//
// 示例 1: 
//
// 输入:
//s = "aa"
//p = "a"
//输出: false
//解释: "a" 无法匹配 "aa" 整个字符串。
// 
//
// 示例 2: 
//
// 输入:
//s = "aa"
//p = "a*"
//输出: true
//解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
// 
//
// 示例 3: 
//
// 输入:
//s = "ab"
//p = ".*"
//输出: true
//解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
// 
//
// 示例 4: 
//
// 输入:
//s = "aab"
//p = "c*a*b"
//输出: true
//解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
// 
//
// 示例 5: 
//
// 输入:
//s = "mississippi"
//p = "mis*is*p*."
//输出: false 
// Related Topics 字符串 动态规划 回溯算法

#include "header.h"

namespace LeetCode10 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
      return solution1(s, p);
    }

    // dp
    bool solution1(string s, string p) {
      int slen = s.size(), plen = p.size();
      // 填入的是 在对应下标之前的字符串是否能够匹配
      vector<vector<bool>> dp(slen+1, vector<bool>(plen+1, false));

      for (int si = 0; si <= slen; ++si) {
        for (int pi = 0; pi <= plen; ++pi) {
          if (pi == 0) {
            dp[si][pi] = si == 0;  // 赋初值
          } else {
            // 判断前一个字符是否是 *
            if (p[pi-1] == '*') {
              // 考虑 字符* 为 0 的结果，即不看 字符*
              if (pi >= 2) {
                dp[si][pi] = dp[si][pi] || dp[si][pi-2];  // 如果已经可以匹配，就无需考虑 pi-2
              }
              // s[si-1] 和 p[pi-2] 即说明当 字符串前一个字符与 * 前一个字符是否可以匹配
              // 一次只考虑一个
              if (si > 0 && pi >= 2 && (s[si-1] == p[pi-2] || p[pi-2] == '.')) {
                dp[si][pi] = dp[si][pi] || dp[si-1][pi];
              }
            } else {
              // 判断前一个字符是否相同，或是可以任意匹配
              // 如果相同，则 dp[si-1][pi-1] 可以匹配，那么 dp[si][pi] 也一定可以匹配
              if (si > 0 && (s[si-1] == p[pi-1] || p[pi-1] == '.')) {
                dp[si][pi] = dp[si-1][pi-1];
              }
            }
          }
        }
      }
      return dp[slen][plen];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
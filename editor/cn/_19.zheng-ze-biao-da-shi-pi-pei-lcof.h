//请实现一个函数用来匹配包含'. '和'*'的正则表达式。模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题中，匹配
//是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。 
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
//
// 
// s 可能为空，且只包含从 a-z 的小写字母。 
// p 可能为空，且只包含从 a-z 的小写字母以及字符 . 和 *，无连续的 '*'。 
// 
//
// 注意：本题与主站 10 题相同：https://leetcode-cn.com/problems/regular-expression-matching/
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode_19 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isMatch(string s, string p) {
      return solution2(s, p);
    }

    // 递归
    bool solution1(string s, string p) {
      return solution1core(s, 0, p, 0);
    }

    bool solution1core(const string& s, int si, const string& p, int pi) {
      int plen = p.size(), slen = s.size();
      if (si == slen) {  // 如果字符串已经遍历完，则需要检查一下模式串
        // 此处模式串必须要符合 a*b* 的情况才能匹配，其他如 ".", "ab*" 都是无法匹配的
        if ((plen - pi) & 1) return false;  // 模式串剩余长度为奇数，必定不匹配
        // 判断是否为 a*b* 模式
        int i = 1;
        while (pi + i < plen) {
          if (p[pi+i] != '*') return false;
          i += 2;
        }
        return true;
      }
      if (pi == plen) return false;  // 字符串尚未遍历完，模式串已经遍历完

      // 按模式串的后一个是否 '*' 情况来区分讨论
      if (pi+1 < plen && p[pi+1] == '*') {
        // 如果模式串中 pi 和字符串一样，或者为 . , 则需要区分讨论
        // 1. si 移动，pi 不动，表示继续匹配如 aa 和 a* 的情况，一次一步匹配
        // 2. si 不同，跳过 .*
        if (s[si] == p[pi] || p[pi] == '.')
          return solution1core(s, si+1, p, pi) || solution1core(s, si, p, pi+2);
        else  // 不同则说明 p[pi]* 无效
          return solution1core(s, si, p, pi+2);
      } else {
        // 如果模式串中 pi 和字符串一样，或者为 . , 则可以往后走
        if (s[si] == p[pi] || p[pi] == '.')
          return solution1core(s, si+1, p, pi+1);
        else
          return false;  // 否则不匹配
      }
    }

    // DP
    bool solution2(string s, string p) {
      int slen = s.size(), plen = p.size();
      // 维度一表示 匹配到字符串的第几位，维度二表示 匹配到模式串的第几位
      vector<vector<bool>> dp(slen + 1, vector<bool>(plen + 1, false));

      for (int si = 0; si <= slen; ++si) {
        for (int pi = 0; pi <= plen; ++pi) {
          if (pi == 0) {  // 正则为空
            dp[si][pi] = si == 0;  // 如果字符串也为空就返回 true
          } else {
            if (p[pi-1] != '*') {
              // 前一个字符相同，或是 . ，说明可以递推
              if (si > 0 && (s[si-1] == p[pi-1] || p[pi-1] == '.')) {
                dp[si][pi] = dp[si-1][pi-1];
              }
            } else {
              // 遇到 * 了，分为看和不看两种情况
              if (pi >= 2) {  // 不看
                dp[si][pi] = dp[si][pi] || dp[si][pi-2];
              }
              // 看, 模式串不动，字符串向前移动一个
              if (si >= 1 && pi >= 2 && (s[si-1] == p[pi-2] || p[pi-2] == '.')) {
                dp[si][pi] = dp[si][pi] || dp[si-1][pi];
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
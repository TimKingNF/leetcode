//给定一个非空的字符串，判断它是否可以由它的一个子串重复多次构成。给定的字符串只含有小写英文字母，并且长度不超过10000。 
//
// 示例 1: 
//
// 
//输入: "abab"
//
//输出: True
//
//解释: 可由子字符串 "ab" 重复两次构成。
// 
//
// 示例 2: 
//
// 
//输入: "aba"
//
//输出: False
// 
//
// 示例 3: 
//
// 
//输入: "abcabcabcabc"
//
//输出: True
//
//解释: 可由子字符串 "abc" 重复四次构成。 (或者子字符串 "abcabc" 重复两次构成。)
// 
// Related Topics 字符串

#include "header.h"

namespace LeetCode459 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
      return solution4(s);
    }

    bool solution1(string s) {
      return (s+s).find(s, 1) != s.size();  // 如果当前有循环串，则必然满足有解要小于 s.size()
    }

    // O( N^2 )
    bool solution2(string s) {
      int n = s.size();
      // 如果满足条件，则最少有2个子串构成 s
      // 所以只需考虑 i * 2 <= n
      for (int i = 1; i * 2 <= n; ++i) {
        if (n % i == 0) {  // i 是子串的长度，n 一定是 i 的倍数
          bool match = true;
          for (int j = i; j < n; ++j) {
            if (s[j] != s[j-i]) {
              match = false;
              break;
            }
          }
          if (match) return true;
        }
      }
      return false;
    }

    // 在方法一的基础上，将字符串查询函数替换为 kmp
    bool solution3(string s) {
      int n = s.size();
      // 在去掉头尾字符之后，仍能够匹配到，说明是正确的
      return kmp((s+s).substr(1, n*2-2), s) != -1;
    }

    int kmp(string text, string p) {
      // 构建模式串的 next 数组
      int m = p.size();
      int next[m], k = -1;
      next[0] = -1;
      for (int i = 1; i < m; ++i) {
        while (k != -1 && p[k+1] != p[i]) {
          k = next[k];
        }
        if (p[k+1] == p[i]) ++k;
        next[i] = k;
      }

      // 模式匹配
      int j = 0, n = text.size();  // j 是模式串的下标
      for (int i = 0; i < n; ++i) {
        while (j > 0 && text[i] != p[j]) {  // 说明遇到坏字符
          j = next[j-1] + 1;  // next[j-1] 是此刻好前缀的最长可匹配前缀子串的下标, 直到 -1+1 =0, j 重置
        }
        if (text[i] == p[j]) ++j;
        if (j == m) return i - m + 1;  // 起始位置
      }
      return -1;
    }

    // 在kmp的基础上再优化
    int solution4(string s) {
      int m = s.size();
      int next[m], k = -1;
      next[0] = -1;
      for (int i = 1; i < m; ++i) {
        while (k != -1 && s[k+1] != s[i]) {
          k = next[k];
        }
        if (s[k+1] == s[i]) ++k;
        next[i] = k;
      }
      return next[m-1] != -1 && m % (m - next[m-1]-1) == 0;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。 
//
// 示例 1： 
//
// 输入: "babad"
//输出: "bab"
//注意: "aba" 也是一个有效答案。
// 
//
// 示例 2： 
//
// 输入: "cbbd"
//输出: "bb"
// 
// Related Topics 字符串 动态规划

#include "header.h"

namespace LeetCode5 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string longestPalindrome(string s) {
      return solution4(s);
    }

    // 暴力枚举所有长度>=2的子串. O(n^3) O(1)
    string solution1(string s) {
      int len = s.size();
      if (len <= 1) return s;
      int maxLen = 1, begin = 0;
      for (int i = 0; i < len - 1; ++i) {
        for (int j = i + 1; j < len; ++j) {
          if (j - i + 1 > maxLen && validPalindrome(s, i ,j)) {
            maxLen = j - i + 1;
            begin = i;
          }
        }
      }
      return s.substr(begin, maxLen);
    }

    bool validPalindrome(string s, int left, int right) {
      while (left < right) if (s[left++] != s[right--]) return false;
      return true;
    }

    // 中心扩散法，枚举单个字符或者两个相邻相同的字符
    // O(n^2), O(1)
    string solution2(string s) {
      int len = s.size();
      if (len < 2) return s;
      int maxLen = 1, begin = 0;
      int oddLen, evenLen, curMaxLen;
      for (int i = 0; i < len - 1; ++i) {
        oddLen = expandAroundCenter(s, i, i);   // 获取奇数长度的回文子串的长度
        evenLen = expandAroundCenter(s, i, i+1);  // 获取偶数长度的回文子串的长度
        curMaxLen = max(oddLen, evenLen);
        if (curMaxLen > maxLen) {
          maxLen = curMaxLen;
          begin = i - (maxLen - 1) / 2;
        }
      }
      return s.substr(begin, maxLen);
    }

    int expandAroundCenter(string s, int left, int right) {
      int len = s.size();
      while (left >= 0 && right < len && s[left] == s[right]) {
        --left;
        ++right;
      }
      return right - left - 1;
    }

    // 动态规划
    // O(n^2), O(n^2)
    string solution3(string s) {
      int n = s.size(), maxLen = 1, begin = 0;
      bool dp[n][n];  // 第一维表示子串的起点，第二维表示子串的终点, 记录从i到j是否是回文
      // 初始化dp矩阵
      for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) dp[i][j] = false;
      for (int i = 0; i < n; ++i) dp[i][i] = true;  // 单个元素是回文

      // 递推，记录时要先以j为计算，因为递推方程 dp[i][j] == s[i] == s[j] && dp[i+1][j-1]
      for (int j = 1; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
          if (s[i] != s[j]) dp[i][j] = false;
          else {
            if (j - i < 3) dp[i][j] = true;  // 长度<=2 且 s[i] == s[j]
            else dp[i][j] = dp[i+1][j-1];
          }

          if (j - i + 1 > maxLen && dp[i][j]) {
            maxLen = j - i + 1;
            begin = i;
          }
        }
      }
      return s.substr(begin, maxLen);
    }

    // Manacher 算法
    // O( N )
    string solution4(string s) {
      string T = preprocess(s);
      int n = T.size(), P[n];
      fill(P, P+n, 0);
      int C = 0, R = 0;
      for (int i = 1; i < n - 1; ++i) {
        int i_mirror = 2 * C - i;  // 求得 i 关于 C 的对称位置
        if (R > i) {
          P[i] = min(R - i, P[i_mirror]);  // 防止超出 R
        } else {
          P[i] = 0;  // 等于 R 的情况
        }

        // 利用中心扩散法计算 P[i]
        while (T[i+1+P[i]] == T[i-1-P[i]]) {
          P[i]++;
        }

        // 判断是否需要更新 R
        if (i + P[i] > R) {
          C = i;
          R = i + P[i];
        }
      }

      // 找出 P[i] 最大值
      int maxLen = 0;
      int centerIndex = 0;
      for (int i = 1; i < n - 1; ++i) {
        if (P[i] > maxLen) {
          maxLen = P[i];
          centerIndex = i;
        }
      }
      int start = (centerIndex - maxLen) / 2;  // 求得在原始字符串中的下标
      return s.substr(start, maxLen);
    }

    // 预处理字符串，在每个字符间都添加 #，头尾添加分界符
    string preprocess(string s) {
      int n = s.size();
      if (n == 0) return "^$";
      ostringstream os;
      os << '^';
      for (auto c : s) os << '#' << c;
      os << "#$";
      return os.str();
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
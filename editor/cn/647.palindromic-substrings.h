//给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。 
//
// 具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。 
//
// 
//
// 示例 1： 
//
// 输入："abc"
//输出：3
//解释：三个回文子串: "a", "b", "c"
// 
//
// 示例 2： 
//
// 输入："aaa"
//输出：6
//解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa" 
//
// 
//
// 提示： 
//
// 
// 输入的字符串长度不会超过 1000 。 
// 
// Related Topics 字符串 动态规划

#include "header.h"

namespace LeetCode647 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int countSubstrings(string s) {
      return solution2(s);
    }

    // 中心扩散法
    // O( N^2 ), O( N^2 )
    int solution1(string s) {
      int ans = 0, n = s.size();
      vector<vector<bool>> dp(n, vector<bool>(n, false));

      for (int i = 0; i < n; ++i) {
        dp[i][i] = true;  // 相同字符
        ans += 1;

        // 以i为中点往两边扩散
        int l = i-1, r = i+1;
        while (l >= 0 && r < n && s[l] == s[r]) {
          if (!dp[l][r]) {
            dp[l][r] = true;
            ans += 1;
          }
          --l;
          ++r;
        }

        // 以 i,i+1 往两边扩散
        l = i, r = i+1;
        while (l >= 0 && r < n && s[l] == s[r]) {
          if (!dp[l][r]) {
            dp[l][r] = true;
            ans += 1;
          }
          --l;
          ++r;
        }
      }
      return ans;
    }

    // 中心扩散法 简洁形式
    // 通过归纳可知，长度为 n 的字符串会生成 2n-1 组回文中心
    // 其中 l = i / 2, r = l + (i % 2)
    // O( N^2 ), O( 1 )
    int solution2(string s) {
      int n = s.size(), ans = 0;
      for (int i = 0; i < 2 * n - 1; ++i) {
        int l = i / 2, r = l + i % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
          ++ans;
          --l;
          ++r;
        }
      }
      return ans;
    }

    // DP
    // O( N^2 ), O( N^2 )
    int solution3(string s) {
      int ans = 0, n = s.size();
      vector<vector<int>> dp(n, vector<int>(n, false));
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
          if (i == j) dp[j][i] = true;
          else if (s[i] == s[j]) dp[j][i] = i - j == 1 || dp[j + 1][i - 1];

          if (dp[j][i]) ans++;
        }
      }
      return ans;
    }

    // TODO：待验证 Manacher
    // O( N ), O( 1 )
    int solution4(string s) {
      ostringstream os;
      os << "$#";
      for (auto c : s) os << c << '#';
      os << '!';
      string t = os.str();
      int n = t.size() - 1;  // 排除掉末尾的 !

      auto f = vector<int>(n);
      int iMax = 0, rMax = 0, ans = 0;
      for (int i = 1; i < n; ++i) {
        f[i] = (i <= rMax) ? min(rMax - i + 1, f[2 * iMax - 1]) : 1;
        while (t[i + f[i]] == t[i - f[i]]) ++f[i];
        if (i + f[i] - 1 > rMax) {
          iMax = i;
          rMax = i + f[i] - 1;
        }
        ans += (f[i] / 2);
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
//给你一个字符串 s ，每一次操作你都可以在字符串的任意位置插入任意字符。 
//
// 请你返回让 s 成为回文串的 最少操作次数 。 
//
// 「回文串」是正读和反读都相同的字符串。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "zzazz"
//输出：0
//解释：字符串 "zzazz" 已经是回文串了，所以不需要做任何插入操作。
// 
//
// 示例 2： 
//
// 
//输入：s = "mbadm"
//输出：2
//解释：字符串可变为 "mbdadbm" 或者 "mdbabdm" 。
// 
//
// 示例 3： 
//
// 
//输入：s = "leetcode"
//输出：5
//解释：插入 5 个字符后字符串变为 "leetcodocteel" 。
// 
//
// 示例 4： 
//
// 
//输入：s = "g"
//输出：0
// 
//
// 示例 5： 
//
// 
//输入：s = "no"
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 500 
// s 中所有字符都是小写字母。 
// 
// Related Topics 动态规划 
// 👍 82 👎 0

#include "header.h"

namespace LeetCode1312 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minInsertions(string s) {
      return solution1(s);
    }

    // DP, O( N^2 ), O( N^2 )
    int solution1(string s) {
      int n = s.size();
      // dp[i][j] 表示, 字符串 i-j 需要添加多少个字符才能构成回文串
      vector<vector<int>> dp(n, vector<int>(n, 0));

      for (int j = 1; j < n; ++j) {
        dp[j-1][j] = s[j] == s[j-1] ? 0 : 1;  // 判断开头
        // 要 i 要倒着推，因为要先计算出 i+1
        for (int i = j - 2; i >= 0; --i) {
          if (s[i] == s[j]) {
            dp[i][j] = dp[i+1][j-1];
          } else {
            dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
          }
        }
      }
      return dp[0][n-1];
    }

    // TODO：可以对空间进行优化

    // 进阶，输出添加字符之后的回文串
    string getPalindrome(string s) {
      int n = s.size();
      if (n < 2) return s;
      // 构建 DP
      vector<vector<int>> dp(n, vector<int>(n, 0));

      for (int j = 1; j < n; ++j) {
        dp[j-1][j] = s[j] == s[j-1] ? 0 : 1;  // 判断开头
        // 要 i 要倒着推，因为要先计算出 i+1
        for (int i = j - 2; i >= 0; --i) {
          if (s[i] == s[j]) {
            dp[i][j] = dp[i+1][j-1];
          } else {
            dp[i][j] = min(dp[i+1][j], dp[i][j-1]) + 1;
          }
        }
      }
      // 已知最少要添加几个字符
      string ans(n + dp[0][n-1], ' ');

      int i = 0, j = n-1;
      int left = 0, right = ans.size()-1;
      while (i <= j) {
        if (s[i] == s[j]) {
          ans[left++] = s[i++];
          ans[right--] = s[j--];
        } else if (dp[i][j-1] < dp[i+1][j]) {
          // 说明取 [i,j-1] 这一段，在 left 处补上和 j 一样的字符
          ans[left++] = ans[right--] = s[j--];
        } else {
          // 说明取 [i+1, j] 这一段，可以选择在 right 处补上和 j 一样的字符
          ans[left++] = ans[right--] = s[i++];
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
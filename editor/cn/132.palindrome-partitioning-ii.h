//给你一个字符串 s，请你将 s 分割成一些子串，使每个子串都是回文。 
//
// 返回符合要求的 最少分割次数 。 
//
// 
// 
// 
//
// 示例 1： 
//
// 
//输入：s = "aab"
//输出：1
//解释：只需一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
// 
//
// 示例 2： 
//
// 
//输入：s = "a"
//输出：0
// 
//
// 示例 3： 
//
// 
//输入：s = "ab"
//输出：1
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length <= 2000 
// s 仅由小写英文字母组成 
// 
// 
// 
// Related Topics 动态规划 
// 👍 283 👎 0

#include "header.h"

namespace LeetCode132 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minCut(string s) {
      return solution2(s);
    }

    // 会超时
    int solution1(string s) {
      int ans = INT32_MAX, cur = 0;
      dfs(s, 0, ans, cur);
      return ans;
    }

    void dfs(string s, int idx, int& ans, int cur) {
      int n = s.size();
      if (idx == n) {
        ans = min(ans, cur-1);  // cur 会多计算一次
        return;
      }

      bool isPalindrome;
      int size;

      // 分割
      for (int i = n-1; i >= idx; --i) {  // 从最贪心的方案开始分割, 进行剪枝
        // tmp = s.substr(idx, i-idx+1);
        isPalindrome = true;
        size = i-idx+1;

        // 验证是回文
        for (int j = idx; j < idx+(size / 2); ++j) {
          if (s[j] != s[idx+size-j-1]) {
            isPalindrome = false;
            break;
          }
        }
        if (!isPalindrome) continue;
        dfs(s, i+1, ans, cur+1);
      }
    }

    // 动态规划
    // O( n^2 ), O( n^2 )
    int solution2(string s) {
      int n = s.size();

      vector<vector<bool>> dp(n, vector<bool>(n, true));
      // base, 构造所有长度范围的字符串是否为回文串
      for (int i = n-1; i >= 0; --i) {
        for (int j = i+1; j < n; ++j) {
          dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1];
        }
      }

      vector<int> f(n, INT32_MAX);
      for (int i = 0; i < n; ++i) {
        if (dp[0][i]) {  // 0,i 是回文，无需分割
          f[i] = 0;
        } else {
          for (int j = 0; j < i; ++j) {
            if (dp[j+1][i]) {
              f[i] = min(f[i], f[j]+1);  // 到 j 为止，尝试一种分割策略
            }
          }
        }
      }
      return f[n-1];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
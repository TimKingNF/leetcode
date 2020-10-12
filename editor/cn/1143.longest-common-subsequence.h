//给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。 
//
// 一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。 
//例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」是这两个字符串所共同拥有的子序列。
// 
//
// 若这两个字符串没有公共子序列，则返回 0。 
//
// 
//
// 示例 1: 
//
// 输入：text1 = "abcde", text2 = "ace" 
//输出：3  
//解释：最长公共子序列是 "ace"，它的长度为 3。
// 
//
// 示例 2: 
//
// 输入：text1 = "abc", text2 = "abc"
//输出：3
//解释：最长公共子序列是 "abc"，它的长度为 3。
// 
//
// 示例 3: 
//
// 输入：text1 = "abc", text2 = "def"
//输出：0
//解释：两个字符串没有公共子序列，返回 0。
// 
//
// 
//
// 提示: 
//
// 
// 1 <= text1.length <= 1000 
// 1 <= text2.length <= 1000 
// 输入的字符串只含有小写英文字符。 
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode1143 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      return solution1(text1, text2);
    }

    // DP
    // O( n*m )
    int solution1(string text1, string text2) {
      // 交换，使得申请较小的空间
      if (text1.size() < text2.size()) swap(text1, text2);
      int n = text1.size(), m = text2.size();
      int dp[m+1];
      fill(dp, dp+m+1, 0);  // 全都填充0

      for (int i = 1; i <= n; ++i) {
        int last = 0;  // 对应初值 (i, 0) = 0
        for (int j = 1; j <= m; ++j) {
          int tmp = dp[j];  // 对应 (i-1, j), 缓存下来给 last 保存
          if (text1[i-1] == text2[j-1]) {  // 下标对应的元素相同
            dp[j] = last + 1;  // 这里的 last 应该是上一行的 j-1, 所以应该有一个临时变量缓存
          } else {
            dp[j] = max(dp[j], dp[j-1]);  // dp[j] 表示上一行的 dp[j], dp[j-1] 表示当前行的前一个
          }
          last = tmp;
        }
      }
      return dp[m];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
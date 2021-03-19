//给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。 
//
// 字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列
//，而 "AEC" 不是） 
//
// 题目数据保证答案符合 32 位带符号整数范围。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "rabbbit", t = "rabbit"
//输出：3
//解释：
//如下图所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
//(上箭头符号 ^ 表示选取的字母)
//rabbbit
//^^^^ ^^
//rabbbit
//^^ ^^^^
//rabbbit
//^^^ ^^^
// 
//
// 示例 2： 
//
// 
//输入：s = "babgbag", t = "bag"
//输出：5
//解释：
//如下图所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
//(上箭头符号 ^ 表示选取的字母)
//babgbag
//^^ ^
//babgbag
//^^    ^
//babgbag
//^    ^^
//babgbag
//  ^  ^^
//babgbag
//    ^^^ 
//
// 
//
// 提示： 
//
// 
// 0 <= s.length, t.length <= 1000 
// s 和 t 由英文字母组成 
// 
// Related Topics 字符串 动态规划 
// 👍 348 👎 0

#include "header.h"

namespace LeetCode115 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int numDistinct(string s, string t) {
      return solution1(s, t);
    }

    // dfs 应该也是可以解的

    int solution1(string s, string t) {
      int m = s.size(), n = t.size();
      if (m < n) return 0;

      // 第一维表示 s[i:] 第二维表示 t[j:]
      long dp[m+1][n+1];
      memset(dp, 0, sizeof(long) * (m+1) * (n+1));

      // base case
      // 当 j == n 时，t 为空串，对任意 s 的子串，都可以取到匹配( 1种 )
      for (int i = 0; i <= m; ++i) dp[i][n] = 1;

      // 从后往前推
      for (int i = m-1; i >= 0; --i) {
        for (int j = n-1; j >= 0; --j) {
          if (s[i] == t[j]) {  // 两字符相同
            // 可以匹配掉 j，也可以不匹配，所以是两种方式加起来
            dp[i][j] = dp[i+1][j+1] + dp[i+1][j];
          } else {
            dp[i][j] = dp[i+1][j];  // 无法匹配，只能 i 继续前移
          }
        }
      }
      return dp[0][0];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
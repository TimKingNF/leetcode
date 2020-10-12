//给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。 
//
// 你可以对一个单词进行如下三种操作： 
//
// 
// 插入一个字符 
// 删除一个字符 
// 替换一个字符 
// 
//
// 
//
// 示例 1： 
//
// 输入：word1 = "horse", word2 = "ros"
//输出：3
//解释：
//horse -> rorse (将 'h' 替换为 'r')
//rorse -> rose (删除 'r')
//rose -> ros (删除 'e')
// 
//
// 示例 2： 
//
// 输入：word1 = "intention", word2 = "execution"
//输出：5
//解释：
//intention -> inention (删除 't')
//inention -> enention (将 'i' 替换为 'e')
//enention -> exention (将 'n' 替换为 'x')
//exention -> exection (将 'n' 替换为 'c')
//exection -> execution (插入 'u')
// 
// Related Topics 字符串 动态规划

#include "header.h"

namespace LeetCode72 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int minDistance(string word1, string word2) {
      return solution1(word1, word2);
    }

    int solution1(string word1, string word2) {
      int n = word1.size(), m = word2.size();
      vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

      for (int i = 1; i <= n; ++i) dp[i][0] = i;
      for (int j = 1; j <= m; ++j) dp[0][j] = j;
      for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
          if (word1[i-1] == word2[j-1]) {
            dp[i][j] = dp[i-1][j-1];  // 字符相同，无需操作
          } else {
            int x = dp[i-1][j-1] + 1;  // 做一步替换
            // 在 word2[0, j-1] 处任意插入一个字符, 或者 word1[0,i]处删除一个字符
            // 两种操作都可以构成相同字符串
            int y = dp[i][j-1] + 1;
            int z = dp[i-1][j] + 1;  // 同上
            dp[i][j] = min(min(x, y), z);
          }
        }
      }
      return dp[n][m];
    }

    // 可以做进一步的空间优化
};
//leetcode submit region end(Prohibit modification and deletion)

}
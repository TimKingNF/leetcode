//在计算机界中，我们总是追求用有限的资源获取最大的收益。 
//
// 现在，假设你分别支配着 m 个 0 和 n 个 1。另外，还有一个仅包含 0 和 1 字符串的数组。 
//
// 你的任务是使用给定的 m 个 0 和 n 个 1 ，找到能拼出存在于数组中的字符串的最大数量。每个 0 和 1 至多被使用一次。 
//
// 注意: 
//
// 
// 给定 0 和 1 的数量都不会超过 100。 
// 给定字符串数组的长度不会超过 600。 
// 
//
// 示例 1: 
//
// 
//输入: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
//输出: 4
//
//解释: 总共 4 个字符串可以通过 5 个 0 和 3 个 1 拼出，即 "10","0001","1","0" 。
// 
//
// 示例 2: 
//
// 
//输入: Array = {"10", "0", "1"}, m = 1, n = 1
//输出: 2
//
//解释: 你可以拼出 "10"，但之后就没有剩余数字了。更好的选择是拼出 "0" 和 "1" 。
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode474 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
      return solution1(strs, m, n);
    }

    int solution1(vector<string>& strs, int m, int n) {
      vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
      int cnt[2] = {0, 0};

      for (const string& str : strs) {
        cnt[0] = cnt[1] = 0;
        // 计数
        for (char v : str) cnt[v - '0']++;

        // 遍历从 m -> cnt[0], n -> cnt[1] 的各种组合情况
        for (int zeroes = m; zeroes >= cnt[0]; --zeroes) {
          for (int ones = n; ones >= cnt[1]; --ones) {
            dp[zeroes][ones] = max(1 + dp[zeroes - cnt[0]][ones - cnt[1]], dp[zeroes][ones]);
          }
        }
      }
      return dp[m][n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
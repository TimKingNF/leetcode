//给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。 
//
// 说明： 
//
// 
// 拆分时可以重复使用字典中的单词。 
// 你可以假设字典中没有重复的单词。 
// 
//
// 示例 1： 
//
// 输入: s = "leetcode", wordDict = ["leet", "code"]
//输出: true
//解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
// 
//
// 示例 2： 
//
// 输入: s = "applepenapple", wordDict = ["apple", "pen"]
//输出: true
//解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
//     注意你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出: false
// 
// Related Topics 动态规划

#include "header.h"

namespace LeetCode139 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      return solution1(s, wordDict);
    }

    // DP
    // O( N^2 ), O( N )
    bool solution1(string s, vector<string>& wordDict) {
      if (s.empty() || wordDict.empty()) return false;
      int n = s.size();
      bool dp[n+1];
      fill(dp, dp+n+1, false);
      unordered_set<string> dict{wordDict.begin(), wordDict.end()};

      // base case
      dp[0] = true;

      for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
          if (dp[j] && dict.count(s.substr(j, i - j))) {
            dp[i] = true;
            break;
          }
        }
      }
      return dp[n];
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
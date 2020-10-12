//给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的
//句子。 
//
// 说明： 
//
// 
// 分隔时可以重复使用字典中的单词。 
// 你可以假设字典中没有重复的单词。 
// 
//
// 示例 1： 
//
// 输入:
//s = "catsanddog"
//wordDict = ["cat", "cats", "and", "sand", "dog"]
//输出:
//[
//  "cats and dog",
//  "cat sand dog"
//]
// 
//
// 示例 2： 
//
// 输入:
//s = "pineapplepenapple"
//wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
//输出:
//[
//  "pine apple pen apple",
//  "pineapple pen apple",
//  "pine applepen apple"
//]
//解释: 注意你可以重复使用字典中的单词。
// 
//
// 示例 3： 
//
// 输入:
//s = "catsandog"
//wordDict = ["cats", "dog", "sand", "and", "cat"]
//输出:
//[]
// 
// Related Topics 动态规划 回溯算法

#include "header.h"

namespace LeetCode140 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
      return solution3(s, wordDict);
    }

    // 递归回溯
    // 最坏情况下 "aaaaaa" 达到 O( N^N )
    vector<string> solution1(string s, vector<string>& wordDict) {
      if (s.empty() || wordDict.empty()) return {};
      vector<string> ans;
      vector<string> cur;
      unordered_set<string> dict{wordDict.begin(), wordDict.end()};
      solution1core(s, dict, 0, cur, ans);
      return ans;
    }

    void solution1core(string s, unordered_set<string>& dict,
                       int l, vector<string>& cur, vector<string>& ans) {
      int n = s.size();
      if (l >= n) {
        ans.push_back(join(cur, ' '));
        return;
      }

      string tmp;
      for (int i = l; i < n; ++i) {
        tmp = s.substr(l, i-l+1);
        if (dict.count(tmp)) {
          cur.push_back(tmp);
          solution1core(s, dict, i+1, cur, ans);
          cur.pop_back();
        }
      }
    }

    string join(vector<string>& f, char sp) {
      ostringstream os;
      os << f[0];
      for (int i = 1; i < f.size(); ++i) {
        os << sp << f[i];
      }
      return os.str();
    }

    // 记忆化回溯
    // O( N^3 ), O( N )
    vector<string> solution2(string s, vector<string>& wordDict) {
      if (s.empty() || wordDict.empty()) return {};
      unordered_set<string> dict{wordDict.begin(), wordDict.end()};
      unordered_map<int, vector<string>> map;
      return solution2core(s, dict, map, 0);
    }

    vector<string> solution2core(string s, unordered_set<string>& dict,
                                 unordered_map<int, vector<string>>& map, int l) {
      if (map.count(l)) {
        return map[l];
      }
      vector<string> ans;
      int n = s.size();
      if (l == n) {
        ans.push_back("");  // 表示到达了结尾
        return ans;
      }
      string tmp;
      for (int i = l; i < n; ++i) {
        tmp = s.substr(l, i-l+1);
        if (dict.count(tmp)) {
          vector<string> list = solution2core(s, dict, map, i+1);
          for (auto v : list) {
            ans.push_back(tmp + (v == "" ? "" : " ") + v);
          }
        }
      }
      map.insert({l, ans});
      return ans;
    }

    // DP
    vector<string> solution3(string s, vector<string>& wordDict) {
      // 先沿用 139 的解法，判断是否可以完全切分
      if (!wordBreak_139(s, wordDict)) return {};

      size_t validEnd = 0;
      // dp[i] 表示第 i 个字符前，所有的拆分情况
      vector<vector<string>> dp(s.size() + 1, vector<string>());

      for (size_t i = 0; i < s.size(); i++) {
        if (i == validEnd + 1) return {};
        if (i != 0 && dp[i].empty()) continue;
        // 假设 i 满足切分
        for (auto& word : wordDict) {
          size_t newEnd = i + word.size();  // 从i之后取新字符串的长度
          if (newEnd > s.size()) continue;
          if (memcmp(&s[i], &word[0], word.size()) != 0) continue;  // 比较s之后 word长度的内容是否是 word
          validEnd = max(validEnd, newEnd);
          if (i == 0) {  // 针对首个字符特殊处理
            dp[newEnd].push_back(word);
            continue;
          }
          for (auto& d : dp[i]) {
            dp[newEnd].push_back(d + " " + word);
          }
        }
      }

      return dp.back();
    }

    bool wordBreak_139(string s, vector<string>& wordDict) {
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
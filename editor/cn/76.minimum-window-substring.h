//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。 
//
// 注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。 
//
// 
//
// 示例 1： 
//
// 
//输入：s = "ADOBECODEBANC", t = "ABC"
//输出："BANC"
// 
//
// 示例 2： 
//
// 
//输入：s = "a", t = "a"
//输出："a"
// 
//
// 
//
// 提示： 
//
// 
// 1 <= s.length, t.length <= 105 
// s 和 t 由英文字母组成 
// 
//
// 
//进阶：你能设计一个在 o(n) 时间内解决此问题的算法吗？ Related Topics 哈希表 双指针 字符串 Sliding Window 
// 👍 842 👎 0

#include "header.h"

namespace LeetCode76 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string minWindow(string s, string t) {
      return solution2(s, t);
    }

    // 滑动窗口
    string solution1(string s, string t) {
      int n = s.size(), m = t.size();
      if (n < m) return "";  // s 不可能包含 t 的所有字符

      unordered_map<char, int> dict, cnt;
      for (auto c : t) dict[c]++;
      bool has_answer = false;

      auto check = [&]() {
        for (const auto& v : dict) {
          if (cnt[v.first] < v.second) return false;
        }
        return true;
      };

      // 第一个匹配的点
      int best_len = n+1, best_start = -1;
      for (int i = 0; i < n; ++i) {
        if (dict.count(s[i])) {
          best_start = i;
          break;
        }
      }

      int left = best_start, right = best_start;
      while (right < n) {
        if (dict.count(s[right])) {
          ++cnt[s[right]];
        }
        // 比较 cnt 里的数是否满足 dict
        while (check() && left <= right) {
          has_answer = true;
          if (right - left + 1 < best_len) {
            best_len = right - left + 1;
            best_start = left;
          }
          // 移动left, 到下一个可以判断的点
          --cnt[s[left]];
          while (left <= right && !dict.count(s[++left])) {}
        }
        ++right;
      }
      return has_answer ? s.substr(best_start, best_len) : "";
    }

    // XXX: 感觉不是很对的样子
    string solution2(string s, string t) {
      if (s.empty() || t.empty()) return "";
      int mp[128] = {0};
      int n = s.size(), m = t.size(), cnt = 0, left = 0;
      string ans;
      for (auto i : t) mp[i]++;

      for (int i = 0; i < n; ++i) {
        --mp[s[i]];  // s只包含字母，所以可以直接--
        if (mp[s[i]] >= 0) cnt++;  // --之后 >= 0，说明 s[i] 在 t 中

        while (left < i && mp[s[left]] < 0) {
          // 此时 s[left] == s[i], 移动 left 到下一个起点
          ++mp[s[left]];
          ++left;
        }
        if (cnt == m) {  // 因为有唯一解，所以当 cnt == m 之后，后续考虑所有 left 位置的情况即可
          if (ans.empty() || ans.length() > i - left + 1) {
            ans = s.substr(left, i- left +1);
          }
        }
      }
      return ans;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
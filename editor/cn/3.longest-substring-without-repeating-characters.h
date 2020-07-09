//给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。 
//
// 示例 1: 
//
// 输入: "abcabcbb"
//输出: 3 
//解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
// 
//
// 示例 2: 
//
// 输入: "bbbbb"
//输出: 1
//解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
// 
//
// 示例 3: 
//
// 输入: "pwwkew"
//输出: 3
//解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
//     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
// 
// Related Topics 哈希表 双指针 字符串 Sliding Window

#include "header.h"

namespace LeetCode3 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      return solution1(s);
    }

    int solution1(string s) {
      vector<int> m(128, -1);
      int res = 0, left = -1;
      for (int i = 0; i < s.size(); ++i) {
        left = max(left, m[s[i]]);
        m[s[i]] = i;
        res = max(res, i - left);
      }
      return res;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
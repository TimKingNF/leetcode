//给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。 
//
// 换句话说，第一个字符串的排列之一是第二个字符串的子串。 
//
// 示例1: 
//
// 
//输入: s1 = "ab" s2 = "eidbaooo"
//输出: True
//解释: s2 包含 s1 的排列之一 ("ba").
// 
//
// 
//
// 示例2: 
//
// 
//输入: s1= "ab" s2 = "eidboaoo"
//输出: False
// 
//
// 
//
// 注意： 
//
// 
// 输入的字符串只包含小写字母 
// 两个字符串的长度都在 [1, 10,000] 之间 
// 
// Related Topics 双指针 Sliding Window 
// 👍 264 👎 0

#include "header.h"

namespace LeetCode567 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
      return solution1(s1, s2);
    }

    bool solution1(string s1, string s2) {
      if (s1.size() > s2.size()) return false;
      // 计算 s1 各个字符的频率
      unordered_map<char, int> freq;
      int cnt = 0;  // 记录 freq 中的累计和
      for (auto c : s1) {
        freq[c]++;
        ++cnt;
      }
      unordered_map<char, int> freq_bak = freq;
      int cnt_bak = cnt;

      int k = s1.size();  // 在 s2 中找符合 k 长度的窗口
      int left = 0, right = 0;
      while (right < s2.size()) {
        if (!freq.count(s2[right])) {  // 说明该字符在 s1 中未出现
          left = right + 1;
          freq = freq_bak;
          cnt = cnt_bak;
          ++right;
          continue;  // 这一步保证 left 到 right 所有字符都在 s1 中出现过
        }
        if (--freq[s2[right]] >= 0) --cnt;  // --有效
        if (right - left + 1 > k) {  // 需要调整 left 位置
          if (++freq[s2[left]] > 0) ++cnt;  // ++有效
          ++left;
        }
        if (cnt == 0) return true;  // 满足排列
        ++right;
      }
      return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
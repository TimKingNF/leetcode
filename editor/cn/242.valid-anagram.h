//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。 
//
// 示例 1: 
//
// 输入: s = "anagram", t = "nagaram"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s = "rat", t = "car"
//输出: false 
//
// 说明: 
//你可以假设字符串只包含小写字母。 
//
// 进阶: 
//如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？ 
// Related Topics 排序 哈希表

#include "header.h"

namespace LeetCode242 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isAnagram(string s, string t) {
      return solution1(s, t);
    }

    bool solution1(string s, string t) {
      if (s.size() < t.size()) swap(s, t);  // 使用字符串长的构建字典
      int dict[26] = {0};
      for (auto c : s) ++dict[c];
      for (auto c : t) dict[c] > 0 && --dict[c];  // 出现过的才 --
      int sum = 0;
      for (int i = 0; i < 26; ++i) sum += dict[i];
      return sum == 0;
    }

    // 效率更高
    bool solution2(string s, string t) {
      if (s.size() != t.size()) return false;  // 长度不一致一定不是
      int dict[26] = {0};
      for (int i = 0; i < s.size(); ++i) {
        dict[s[i] - 'a']++;
        dict[t[i] - 'a']--;
      }

      for (int i = 0; i < 26; ++i) {
        if (dict[i] != 0) return false;
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
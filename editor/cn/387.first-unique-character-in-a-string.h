//给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。 
//
// 
//
// 示例： 
//
// s = "leetcode"
//返回 0
//
//s = "loveleetcode"
//返回 2
// 
//
// 
//
// 提示：你可以假定该字符串只包含小写字母。 
// Related Topics 哈希表 字符串

#include "header.h"

namespace LeetCode387 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    int firstUniqChar(string s) {
      return solution1(s);
    }

    int solution1(string s) {
      int dict[27] = {0};
      for (char c : s) dict[c - 'a'] += 1;
      for (int i = 0; i < s.size(); ++i) {
        if (dict[s[i] - 'a'] == 1) return i;
      }
      return -1;
    }

    // 相对 solution1 来说速度更快
    int solution2(string s) {
      int position[26];
      fill(position, position+26, -2);
      int n = s.size();
      for (int i = 0; i < n; ++i) {
        int idx = s[i]-'a';
        if (position[idx] == -1) continue;  // 已经是多次出现
        if (position[idx] >= 0) position[idx] = -1;  // 多次出现
        else position[idx] = i;
      }
      int first = n;
      for (int i = 0; i < 26; ++i) {
        int pos = position[i];
        if (pos >= 0 && pos < first) {
          first = pos;
        }
      }
      if (first == n) return -1;
      return first;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
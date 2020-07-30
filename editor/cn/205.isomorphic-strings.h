//给定两个字符串 s 和 t，判断它们是否是同构的。 
//
// 如果 s 中的字符可以被替换得到 t ，那么这两个字符串是同构的。 
//
// 所有出现的字符都必须用另一个字符替换，同时保留字符的顺序。两个字符不能映射到同一个字符上，但字符可以映射自己本身。 
//
// 示例 1: 
//
// 输入: s = "egg", t = "add"
//输出: true
// 
//
// 示例 2: 
//
// 输入: s = "foo", t = "bar"
//输出: false 
//
// 示例 3: 
//
// 输入: s = "paper", t = "title"
//输出: true 
//
// 说明: 
//你可以假设 s 和 t 具有相同的长度。 
// Related Topics 哈希表

#include "header.h"

namespace LeetCode205 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    bool isIsomorphic(string s, string t) {
      return solution1(s, t);
    }

    bool solution1(string s, string t) {
      // 每个字符的首次出现位置
      int sdict[256] = {0}, tdict[256] = {0};
      for (int i = 0; i < s.size(); ++i) {
        if (sdict[s[i]] == 0) sdict[s[i]] = i + 1;  // 首次出现，记录下标加1
        if (tdict[t[i]] == 0) tdict[t[i]] = i + 1;
        if (sdict[s[i]] != tdict[t[i]]) return false;  // 字符的首次出现位置不同, 说明异构
      }
      return true;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}
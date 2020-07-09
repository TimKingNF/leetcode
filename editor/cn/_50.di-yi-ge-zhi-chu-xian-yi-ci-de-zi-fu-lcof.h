//在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。 
//
// 示例: 
//
// s = "abaccdeff"
//返回 "b"
//
//s = "" 
//返回 " "
// 
//
// 
//
// 限制： 
//
// 0 <= s 的长度 <= 50000 
// Related Topics 哈希表

#include "header.h"

namespace LeetCode_50 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    char firstUniqChar(string s) {
      return solution1(s);
    }

    char solution1(string s) {
      // 只包含小写字母
      int tmp[26] = {0};  // 初始化26个字符空间
      for (auto c : s) {  // 统计所有字符出现次数
        tmp[c - 97] += 1;
      }
      for (auto c : s) {
        if (tmp[c-97] == 1) return c;
      }
      return ' ';
    }
  };
//leetcode submit region end(Prohibit modification and deletion)

}
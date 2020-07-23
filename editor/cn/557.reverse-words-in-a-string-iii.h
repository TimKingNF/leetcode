//给定一个字符串，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。 
//
// 示例 1: 
//
// 
//输入: "Let's take LeetCode contest"
//输出: "s'teL ekat edoCteeL tsetnoc" 
// 
//
// 注意：在字符串中，每个单词由单个空格分隔，并且字符串中不会有任何额外的空格。 
// Related Topics 字符串

#include "header.h"

namespace LeetCode557 {

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
    string reverseWords(string s) {
      return solution1(s);
    }

    string solution1(string s) {
      if (s.empty()) return s;
      int start = -1, i = 0;
      while (i < s.size()) {
        if (s[i] == ' ') {
          reverse(s.begin()+start, s.begin()+i);
          start = -1;
        } else if (start == -1) start = i;
        ++i;
      }
      // 翻转最后一个单词
      reverse(s.begin()+start, s.end());
      return s;
    }
};
//leetcode submit region end(Prohibit modification and deletion)

}